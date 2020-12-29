#!/bin/bash

./bfuck "$1"
clang++ out.cpp

rm out.cpp
rm a.out
