#!/bin/bash

hg clone http://bitbucket.org/birkenfeld/pygments-main pygments;
cp lexers/icl.py pygments/pygments/lexers;
cp styles/icl.py pygments/pygments/styles;
cp styles/icldark.py pygments/pygments/styles;

cd pygments;
make mapfiles;
cd ..;
