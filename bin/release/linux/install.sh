#!/bin/bash

cd lib;
sudo cp ./* /usr/lib;
echo "The libs was intalled!";

cd ..;
sudo cp icL /usr/bin;
echo "The icL was intalled!";

cd extra;
mkdir ~/.icL;
cp icL.svg ~/.icL
absdir=`dirname ~/.icL/icL.svg`;

cat icL.desktop > tmp.d;
echo "Icon=$absdir/icL.svg" >> tmp.d;

sudo cp tmp.d /usr/share/applications/icL.desktop;
rm tmp.d;

cd ..;
echo "Now you can run icL! )))";
