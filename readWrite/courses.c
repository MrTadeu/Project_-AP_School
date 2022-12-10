#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h" 

courseStruct *getAllCourses(AlunoFileStruct *alunosFile, int n_linhas_lidas, int *n_courses){
    courseStruct *courses = malloc(sizeof(courseStruct));
    for (int i = 0; i < n_linhas_lidas; i++){
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

void saveBinCourses(courseStruct *courses, int n_courses){
    FILE *file = fopen("data/bin/courses.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0; i < n_courses; i++){
        fwrite(&courses[i].id, sizeof(int), 1, file);

        size_t courseLen = strlen(courses[i].name) + 1;
        fwrite(&courseLen, sizeof(size_t), 1, file);
        fwrite(courses[i].name, courseLen, 1, file);
    }
    fclose(file);
}

courseStruct *readBinCourses(){
    courseStruct *courses = malloc(sizeof(courseStruct));
    FILE *file = fopen("data/bin/courses.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0;; i++){
        courses = realloc(courses, (i+1)*sizeof(courseStruct));
        if(fread(&courses[i].id, sizeof(int), 1, file) != 1) break;

        size_t courseLen;
        fread(&courseLen, sizeof(size_t), 1, file);
        courses[i].name = malloc(courseLen);
        fread(courses[i].name, courseLen, 1, file);
    }
    fclose(file);
    return courses;
}
