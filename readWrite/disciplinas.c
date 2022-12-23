#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

courseStruct *getAllCourses(AlunoFileStruct *alunosFile, int n_alunos, int *n_courses){
    courseStruct *courses = malloc(sizeof(courseStruct));
    for (int i = 0; i < n_alunos; i++){
        int found = 0;
        for (int j = 0; j < *n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            courses = realloc(courses, ((*n_courses)+1)*sizeof(courseStruct));
            courses[*n_courses].id = *n_courses+1;
            courses[*n_courses].name = malloc((strlen(alunosFile[i].course)+1));
            strcpy(courses[*n_courses].name, alunosFile[i].course);
            *n_courses=*n_courses+1;
        }
    } 
    return courses;
}