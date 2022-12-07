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
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile));
    Aluno *alunos;
    role *roles;
    course *courses;
    int n_linhas_lidas = 0, n_roles = 0, n_courses = 0;
    alunosFile = getTxt(alunosFile, &n_linhas_lidas);

    roles = getAllRoles(alunosFile, n_linhas_lidas, &n_roles);
    saveBinRoles(roles, n_roles);
    readBinRoles();

    courses = getAllCourses(alunosFile, n_linhas_lidas, &n_courses);
    saveBinCourses(courses, n_courses);
    readBinCourses();

    alunos = ConvertAluno(alunosFile, n_linhas_lidas, roles, n_roles, courses, n_courses);
    saveBinAlunos(alunos, n_linhas_lidas);
    printAlunos(alunos, n_linhas_lidas);
    for (int i = 0; i < n_courses; i++){
        printf("%d", n_courses);
        printf("\nCURSOS ID: %d NAME: %s", courses[i].id, courses[i].name);
    }

    for (int i = 0; i < n_roles; i++){
        printf("\nREGIMES ID: %d NAME: %s", roles[i].id, roles[i].name);
    }
}