#ifndef _ASSIGNMENT2_H
#define _ASSIGNMENT2_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 20
#define BUFFER_SIZE 256

typedef enum {
    FALSE, SUCCESS
}STATUS;

int line_count(void);
STATUS openfile(FILE *fptr);
int length_per_line(void);
STATUS wrap(char *buffer,int length);
int wordlen(char* str);
STATUS buffer_store(FILE* fptr, char *buffer);
STATUS file_present(void);

#endif