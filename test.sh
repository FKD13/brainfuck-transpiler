#!/bin/bash

./bfuck "$1"
g++ out.cpp

rm out.cpp
rm a.out
