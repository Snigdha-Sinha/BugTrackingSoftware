#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include"server.h"
void getTime(FILE *fp)   //To display time
{
    
    struct timeval usec_time;
    time_t now = time(0);
    gettimeofday(&usec_time,NULL);
    // format time
    struct tm *current = localtime(&now);
    printf("Time of bug entry: %d:%d:%d\n",current->tm_hour, current->tm_min, current->tm_sec);		//To print time on standard output
    fprintf(fp,"Time of bug entry: %d:%d:%d\n",current->tm_hour, current->tm_min, current->tm_sec);	//To print time in the file
}
