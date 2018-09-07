#!/bin/bash
pwd0=$PWD;

for i in $pwd0/../icl-*/models/*.plantuml; 
do 
    parent=`dirname "$i"`;
    cd $parent;
    cat $i | java -jar ~/plantuml.jar -tsvg -charset UTF-8 -pipe >> $i.svg;
done

#java -jar ~/plantuml.jar -tpng ../icl-*/models/*.plantuml;

parent=`dirname "$pwd0"`;

for fold in $parent/icl-*/models
do
    cd $fold;
    pwd1=`dirname "$PWD"`;
    current=`basename "$pwd1"`;
    mv $PWD/*.svg "$1/${current:4}";
done 
