#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

//Creating an array of structures
struct Bug{
	char name[20];
	char type[20];
	char status[20];
	char priority[20];
	char desc[100];
	int id;
};
void getTime(FILE *fp);