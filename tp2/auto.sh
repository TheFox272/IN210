#!/bin/bash

make mrproper
make
./testAll
gcov -b -c ratp.c
gcovr --html-details result.html






