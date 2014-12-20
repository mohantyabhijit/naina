// This is a basic template of a test file. Modify it according to the need of the function
#include"../../source/symboltable/symboltable.h"

#define MAXCASE 3

int main(int argc, char *argv[])
{
	char *tmpIn=NULL, tmpOut[MAXSIZE], *str=NULL;
	int loop = 0,sval=0;
	size_t length=0;
	FILE *pfin, *pfout, *pftmp;
	pfin = fopen("./search.in", "r");
	pfout = fopen("./search.out", "r");
	pftmp = fopen("./search.tmp", "w+");
	memset(tmpOut, '\0', MAXSIZE);
	for (loop=0;loop<MAXCASE;loop++)
	{
		getline(&tmpIn, &length, pfin);
		sval=search(tmpIn);
		switch (sval)
		{
			case SYMERR:
			{
				strncpy(tmpOut, "SYMERR", 10);
				break;
			}
			case FALSE:
			{
				strncpy(tmpOut, "FALSE", 10);
				break;
			}
			default:
			{
				if (isdigit(sval))
				{
					sprintf(str,"%d",sval);					
					strncpy(tmpOut,"str",5);
					break;
				}
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
