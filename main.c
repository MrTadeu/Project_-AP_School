#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "All_functions\global.h"

void main(){
    AlunoFileStruct *alunosFile = malloc(sizeof(AlunoFileStruct));
    AlunoStruct *alunos;
    regimeStruct *regimes;
    courseStruct *courses;
    int n_linhas_lidas = 0, n_regimes = 0, n_courses = 0, n_perms = 0;
    alunosFile = getTxt(alunosFile, &n_linhas_lidas);

    regimes = getAllRegimes(alunosFile, n_linhas_lidas, &n_regimes);
    saveBinRegimes(regimes, n_regimes);
    readBinRegimes();

    courses = getAllCourses(alunosFile, n_linhas_lidas, &n_courses);
    saveBinCourses(courses, n_courses);
    readBinCourses();

    

    alunos = ConvertAluno(alunosFile, n_linhas_lidas, regimes, n_regimes, courses, n_courses);
    saveBinAlunos(alunos, n_linhas_lidas);
    printAlunos(alunos, n_linhas_lidas);
    for (int i = 0; i < n_courses; i++){
        printf("%d", n_courses);
        printf("\nCURSOS ID: %d NAME: %s", courses[i].id, courses[i].name);
    }

    for (int i = 0; i < n_regimes; i++){
        printf("\nREGIMES ID: %d NAME: %s", regimes[i].id, regimes[i].name);
    }

    setPermissionsBinByTxt(regimes, n_regimes);
    readBinPermissions(&n_perms);

    /* AlunoStruct test = getAluno(4344);
    printf("\n ID: %d \t Nome: %s \t Ano: %d \t ID Regime: %d \t ID Course: %d \t", test.id, test.name, test.year, test.id_regime, test.id_course); */
}
