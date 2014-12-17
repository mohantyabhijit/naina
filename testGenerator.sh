#!/bin/bash

# This is a script to generate test case file for the project NAINA
FILE=$1

f=$(basename $FILE)
fn=$(echo $f | cut -f1 -d'.')
p=$(dirname $FILE)
mod=$(basename $p)
cd $p
if [ ! -f $f ];
then
	touch $f
	printf "// This is a basic template of a test file. Modify it according to the need of the function\n" >> $f
	printf "#include\"test%s.h\"\n\n" "$mod" >> $f
	printf "int main(int argc, char *argv[])\n{\n" >> $f
	printf "\tchar *tmpIn=NULL, tmpOut[MAXSIZE];\n" >> $f
	printf "\tint loop = 0;\n" >> $f
	printf "\tsize_t length=0;\n" >> $f
	printf "\tFILE *pfin, *pfout, *pftmp;\n" >> $f
	printf "\tpfin = fopen(\"./%s.in\", \"r\");\n" "$fn" >> $f
	printf "\tpfout = fopen(\"./%s.out\", \"r\");\n" "$fn" >> $f
	printf "\tpftmp = fopen(\"./%s.tmp\", \"w+\");\n" "$fn" >> $f
	printf "\tmemset(tmpOut, '\\" >> $f
	printf "0', MAXSIZE);\n" >> $f
	printf "\tfor (loop=0;loop<MAXCASE;loop++)\n\t{\n" >> $f
	printf "\t\tgetline(&tmpIn, &length, pfin);\n" >> $f
	printf "\t\t//Invoke the function and store the value returned in the array tmpOut\n" >> $f
	printf "\t\tstrncpy(tmpOut, \"" >> $f
	echo -n "\n" >> $f
	printf "\", 2);\n" >> $f
	printf "\t\tfputs(tmpOut, pftmp);\n\t}\n" >> $f
	printf "\tfclose(pfin);\n" >> $f
	printf "\tfclose(pfout);\n" >> $f
	printf "\tfclose(pftmp);\n" >> $f
	printf "\treturn 0;\n}\n" >> $f
fi
