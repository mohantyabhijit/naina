// This is a basic template of a test file. Modify it according to the need of the function
#include"testsymboltable.h"

int main(int argc, char *argv[])
{
	char *tmpIn=NULL, tmpOut[MAXSIZE];
	int loop = 0;
	size_t length=0;
	FILE *pfin, *pfout, *pftmp;
	pfin = fopen("./check.in", "r");
	pfout = fopen("./check.out", "r");
	pftmp = fopen("./check.tmp", "w+");
	memset(tmpOut, '\0', MAXSIZE);
	for (loop=0;loop<MAXCASE;loop++)
	{
		getline(&tmpIn, &length, pfin);
		//Invoke the function and store the value returned in the array tmpOut
		strncpy(tmpOut, "\n", 2);
		fputs(tmpOut, pftmp);
	}
	fclose(pfin);
	fclose(pfout);
	fclose(pftmp);
	return 0;
}
