#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

courseStruct *readBinCourses(int *n_courses){
    courseStruct *courses = malloc(sizeof(courseStruct));
    int i;
    FILE *file = fopen("data/bin/courses.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]course.bin[/red]\n\n");
        exit(1);
    }

    for (i = 0;; i++){
        courses = realloc(courses, (i+1)*sizeof(courseStruct));
        if(fread(&courses[i].id, sizeof(int), 1, file) != 1) break;

        size_t courseLen;
        fread(&courseLen, sizeof(size_t), 1, file);
        courses[i].name = malloc(courseLen);
        fread(courses[i].name, courseLen, 1, file);
    }
    *n_courses = i-1;
    fclose(file);
    return courses;
}
