#!/bin/bash

############################################################################
# This is a script that checks the pass/fail of the functions in test cases#
############################################################################

cd ../../source/symboltable/
./compile.sh
cd ../../tests/symboltable/

gcc -c -o create.o create.c
gcc -c -o insert.o insert.c
gcc -c -o symboltable.o symboltable.c
gcc -c -o search.o search.c

gcc -o create create.o ../../source/symboltable/create.o
gcc -o insert insert.o ../../source/symboltable/insert.o
gcc -o symboltable symboltable.o ../../source/symboltable/symboltable.o
gcc -o search search.o ../../source/symboltable/search.o

declare -a arr=("create" "insert" "symboltable" "search")

for i in "${arr[@]}"
do
	./$i
	if diff "$i".out "$i".tmp > /dev/null;
	then
		rm "$i".tmp
		echo "$i" Passed
	else
		echo "$i" Failed
	fi
done
