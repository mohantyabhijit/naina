// This is a basic template of a test file. Modify it according to the need of the function
#include"../../source/symboltable/symboltable.h"

#define MAXCASE 6

int main(int argc, char *argv[])
{
	char *tmpIn=NULL, tmpOut[MAXSIZE], *sym=NULL, *addr=NULL;
	int loop = 0,ival=0;
	size_t length=0;
	FILE *pfin, *pfout, *pftmp;
	pfin = fopen("./insert.in", "r");
	pfout = fopen("./insert.out", "r");
	pftmp = fopen("./insert.tmp", "w+");
	memset(tmpOut, '\0', MAXSIZE);
	for (loop=0;loop<MAXCASE;loop++)
	{
		getline(&tmpIn, &length, pfin);
		sscanf(tmpIn, "%s\t%s ", sym, addr);
		ival=insert(sym,addr);
		switch (ival)
		{
			case SYMWRITE:
			{
				strncpy(tmpOut, "SYMWRITE", 15);
				break;
			}
			case SYMERR:
			{
				strncpy(tmpOut, "SYMERR", 10);
				break;
			}
			default: 
			{
				strncpy(tmpOut, "FALSE", 8);
				break;
			}

		}
		strncat(tmpOut, "\n", 2);
		fputs(tmpOut, pftmp);
	}
	fclose(pfin);
	fclose(pfout);
	fclose(pftmp);
	return 0;
}
