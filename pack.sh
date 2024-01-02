#! /bin/bash

NAME=211220091-闻嘉迅.zip

rm -f ${NAME}
cd Code
make clean 
cd ../
zip -r ${NAME} ./turing-project/* ./programs/case1.tm ./programs/case2.tm CMakeLists.txt README.md