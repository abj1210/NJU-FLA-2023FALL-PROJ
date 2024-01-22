#! /bin/bash

NAME=211220091-闻嘉迅

rm -f ${NAME}.zip
zip -r ${NAME} ./turing-project/* ./programs/case1.tm ./programs/case2.tm CMakeLists.txt README.md ${NAME}.pdf 