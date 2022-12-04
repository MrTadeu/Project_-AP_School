#include <stdio.h>
#include <time.h>
#include "All_functions\global.h"

typedef struct{
    char admin;
    char studant;
    char teacher;
}permission;

typedef struct{
    int date;
    int room;
}exam;

void main(){
    /* time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date and time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec); */
}