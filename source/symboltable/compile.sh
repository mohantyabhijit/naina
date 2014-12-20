#!/bin/bash

###############################################################
# This is a script that compiles the C files in this directory#
###############################################################

declare -a arr=("create" "insert" "symboltable" "search")

for i in "${arr[@]}"
do
	gcc -c -o "$i".o "$i".c
done
