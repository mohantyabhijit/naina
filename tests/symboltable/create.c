// This is a basic template of a test file. Modify it according to the need of the function
#include"../../source/symboltable/symboltable.h"

#define MAXCASE 8


int main(int argc, char *argv[])
{
	char *tmpIn=NULL, tmpOut[MAXSIZE];
	int loop = 0, val =0;
	size_t length=0;
	FILE *pfin, *pfout, *pftmp;
	pfin = fopen("./create.in", "r");
	pfout = fopen("./create.out", "r");
	pftmp = fopen("./create.tmp", "w+");
	memset(tmpOut, '\0', MAXSIZE);
	for (loop=0;loop<MAXCASE;loop++)
	{
		getline(&tmpIn, &length, pfin);
		val = create(tmpIn);
		switch (val)
		{
			case TABLECREATED:
			{
				strncpy(tmpOut, "TABLECREATED", 15);
				break;
			}
			case TABLEERR:
			{
				strncpy(tmpOut, "TABLEERR", 15);
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
