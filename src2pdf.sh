#!/bin/bash -e

# Check everything is installed:
PYTHON_PATH=$(which python)
return_status_1=$(echo $? 2> /dev/null)
PIP_PATH=$(which pip 2> /dev/null)
return_status_2=$(echo $?)
#TEX_PATH=$(which texlive-latex-extra 2> /dev/null)
#return_status_3=$(echo $?)
#sudo apt-get -y -qq install python python-pip texlive-latex-extra
#pip install --user Pygments

tex_file=$1

# EDIT THESE VARIABLES!!!!
doc_title="intra-cloud Lightning"
author="Lelitac Vasile"
abstract=$(cat <<EOM
Source code
EOM
)
introduction=$(cat <<EOM
This document contains the source code of $doc_title (https://gitlab.com/lixcode/ic-lightning)
EOM
)

declare -A file_types
file_types[0]="make|-name '*.pro'"
file_types[1]="cpp|-name '*.h' -o -name '*.cpp'|"
file_types[2]="qml|-name '*.qml'"
file_types[3]="js|-name '*.js'"
file_types[4]="sql|-name '*.sql'"
# DONE EDITING! :)

input_minted_header () {
  tex_file=$1
  cat <<EOF >$tex_file   ## Print the tex file header

  \documentclass[a4paper]{article}
  \usepackage{minted}
  \usepackage{url}
  \urlstyle{same}                       % omit this command if you want monospaced-font look
  \newcommand\purl[1]{\protect\url{#1}} % "protected url"
EOF
}

input_doc_header () {
  tex_file=$1
  cat <<EOF >>$tex_file
  \usepackage[top=2.5cm, bottom=1.5cm, left=2cm, right=1cm]{geometry}
  \usepackage{fancyvrb}
  \fvset{tabsize=2}
  \begin{document}
  \title{$doc_title}
  \author{$author}

  \maketitle

  \newpage
  \begin{abstract}
  $abstract
  \end{abstract}

  \newpage
  \tableofcontents

  \newpage
  \section{Introduction}
  $introduction
EOF
}

input_section () {
  newdirectory=$1
  olddirectory=$2
  if [ "$newdirectory" != "$olddirectory" ]; then
    IFS='/' read -r -a structure <<< "$newdirectory"
    IFS='/' read -r -a oldstructure <<< "$olddirectory"
    for level in "${!structure[@]}"; do
      if [ "${structure[$level]}" != "${oldstructure[$level]}" ]; then
        case $level in
          0) level_command="\subsection"
          ;;
          1) level_command="\subsubsection"
          ;;
          2) level_command="\paragraph"
          ;;
          *) level_command="\subparagraph"
          ;;
        esac
        file_title=${structure[$level]}
        echo "$level_command{\purl{/$file_title}}" >> $tex_file  ## Create a section for each file
      fi
    done
  fi
  olddirectory=$newdirectory
}

input_listings () {
  echo "\section{Source code in language $language}" >> $tex_file;
  olddirectory="/"
  for file in "${files_to_process[@]}"; do             ## Loop through each file

    file_title=$file
    directory=$(dirname "${file}")

    if [ -d "./${file}" ]; then
      echo "Skipping ./${file}"
    else
      # echo "\newpage" >> $tex_file                ## start each section on a new page
      input_section $directory $olddirectory
      echo "\subparagraph{\purl{/$file_title}}" >> $tex_file  ## Create a section for each file
      echo "\inputminted[linenos]{$language}{$file}" >> $tex_file
    fi
  done
}

input_minted_header $tex_file
input_doc_header $tex_file
for i in "${!file_types[@]}"; do
  IFS='|' read -r -a file_type <<< "${file_types[$i]}"
  language=${file_type[0]}
  files_to_include=${file_type[1]}
  files_to_exclude=${file_type[2]}

  # Get the list of files to process
  cmd="find . -type d \( -name storage -o -name vendor \) -prune -o -type f \( $files_to_include \) \
       ! -regex '.*/\..*' ! -name '.*' $files_to_exclude ! -name '*~' ! -name 'src2pdf'  \
       | sed 's/^\..//'"
  files_to_process=( $(eval $cmd) )
  input_listings
done
echo "\end{document}" >> $tex_file

pdflatex -shell-escape $tex_file -output-directory . && pdflatex -shell-escape $tex_file -output-directory .
find . -name "$tex_file.*" ! -name "$tex_file.pdf" -type f -exec rm -f {} +
## This needs to be run twice for the TOC to be generated
