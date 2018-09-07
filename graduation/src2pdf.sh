#!/bin/bash -e

# Forked form https://github.com/arosspope/src2pdf.git
# Source License: MIT

# MIT License
#
# Copyright (c) 2017 Andrew Pope
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

tex_file="Исходники"

declare -A file_types
file_types[0]="make|-name '*.pro' -o -name *.pri"
file_types[1]="cpp|-name '*.h' -o -name '*.cpp'"
file_types[2]="qml|-name '*.qml'"
file_types[3]="js|-name '*.js'"
file_types[4]="sql|-name '*.sql'"


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
  \usepackage{polyglossia}
  \setmainlanguage{english} 
  \setotherlanguage{russian}
  
  \setmainfont{Liberation Serif}
  \newfontfamily\cyrillicfont{Liberation Serif}
  \setmonofont{Liberation Mono}
  \newfontfamily\cyrillicfonttt{Liberation Serif}


  
  \begin{document}
  \title{Исходник проекта icL}
  \author{Лелицак Василе}

  \maketitle

  \newpage
  \tableofcontents
  \newpage
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
  echo "\section{Исходники на языке $language}" >> $tex_file;
  olddirectory="/"
  for file in "${files_to_process[@]}"; do             ## Loop through each file

    file_title=$file
    directory=$(dirname "${file}")

    if [ -d "./${file}" ]; then
      echo "Skipping ./${file}"
    else
      # echo "\newpage" >> $tex_file                ## start each section on a new page
      input_section $directory $olddirectory
      echo "\subparagraph{\purl{Файл:  /$file}}" >> $tex_file  ## Create a section for each file
      echo "\inputminted[linenos]{$language}{$file}" >> $tex_file
    fi
  done
}

cd ..
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

lualatex -shell-escape $tex_file -output-directory . && lualatex -shell-escape $tex_file -output-directory .
find . -name "$tex_file.*" ! -name "$tex_file.pdf" -type f -exec rm -f {} +
## This needs to be run twice for the TOC to be generated

rm -rf _minted-$tex_file
rm -f $tex_file

mv $tex_file.pdf grandulation
