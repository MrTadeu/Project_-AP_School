#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h" 

course *getAllCourses(AlunoFile *alunosFile, int n_linhas_lidas, int *n_courses){
    course *courses = malloc(sizeof(course));
    for (int i = 0; i < n_linhas_lidas; i++){
        int found = 0;
        for (int j = 0; j < *n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            courses = realloc(courses, ((*n_courses)+1)*sizeof(course));
            courses[*n_courses].id = *n_courses+1;
            courses[*n_courses].name = malloc((strlen(alunosFile[i].course)+1));
            strcpy(courses[*n_courses].name, alunosFile[i].course);
            *n_courses=*n_courses+1;
        }
    } 
    return courses;
}

void saveBinCourses(course *courses, int n_courses){
    FILE *file = fopen("../data/bin/courses.bin","ab");
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

course *readBinCourses(){
    course *courses = malloc(sizeof(course));
    FILE *file = fopen("../data/bin/courses.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0;; i++){
        courses = realloc(courses, (i+1)*sizeof(course));
        if(fread(&courses[i].id, sizeof(int), 1, file) != 1) break;

        size_t courseLen;
        fread(&courseLen, sizeof(size_t), 1, file);
        courses[i].name = malloc(courseLen);
        fread(courses[i].name, courseLen, 1, file);
    }
    fclose(file);
    return courses;
}
