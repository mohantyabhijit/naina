#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int symboltable(char *fun, void *psym, void *padd);
int create(char *ds);
int search(char *sym);
int insert(void *sym, void *add);

#ifndef TRUE
#define TRUE 0
#endif

#ifndef FALSE
#define FALSE 1
#endif

#ifndef MAXSIZE
#define MAXSIZE 50
#endif

#define TABLECREATED 11
#define SYMWRITE 12
#define FOUND 13

#define	TABLEERR 101
#define SYMERR 102
#define TRUENOTEXIST 103
#define NOTFOUND 104

#endif
