// This is a basic template of a test file. Modify it according to the need of the function
#include"../../source/symboltable/symboltable.h"

#define MAXCASE 10

int main(int argc, char *argv[])
{
	char *tmpIn=NULL, tmpOut[MAXSIZE], *fun=NULL, *psym=NULL, *padd=NULL;
	int loop = 0, stval=0;
	size_t length=0;
	FILE *pfin, *pfout, *pftmp;
	pfin = fopen("./symboltable.in", "r");
	pfout = fopen("./symboltable.out", "r");
	pftmp = fopen("./symboltable.tmp", "w+");
	memset(tmpOut, '\0', MAXSIZE);
	for (loop=0;loop<MAXCASE;loop++)
	{
		getline(&tmpIn, &length, pfin);
		sscanf(tmpIn, "%s\t%s\t%s", fun, psym, padd);
		stval=symboltable(fun,psym,padd);
		switch(stval)
		{
			case TRUENOTEXIST:
			{
				strncpy(tmpOut, "TRUENOTEXIST", 20);
				break;
			}
			case TABLECREATED:
			{
				strncpy(tmpOut, "TABLECREATED", 20);
				break;
			}
			case SYMWRITE:
			{
				strncpy(tmpOut, "SYMWRITE", 20);
				break;
			}
			case SYMERR:
			{
				strncpy(tmpOut,"SYMERR", 10);
				break;
			}
			case NOTFOUND:
			{
				strncpy(tmpOut,"NOTFOUND",10);
				break;
			}
			case FOUND:
			{
				strncpy(tmpOut,"FOUND",10);
				break;
			}
			default:
			{
				strncpy(tmpOut,"FALSE",10);
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
