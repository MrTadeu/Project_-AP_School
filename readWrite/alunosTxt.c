#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h" 

AlunoFileStruct* getTxt(int *n_linhas_lidas){
    AlunoFileStruct *alunosFile = malloc(sizeof(AlunoFileStruct));
    FILE *file = fopen("data/alunos.txt","r");
    char **filedata = malloc(5*sizeof(char *)), *linhaString = malloc(250);

    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    int linha = 0;
    while (!feof(file)){
        fgets(linhaString,250,file);
        char *pch = strtok (linhaString, "\t\r\n");
        
        int count = 0;

        while (pch != NULL){
            filedata[count] = malloc((strlen(pch)+1));
            strcpy(filedata[count], pch);
            pch = strtok (NULL, "\t\r\n");
            count++;
        }
        alunosFile = realloc(alunosFile, ((*n_linhas_lidas)+1)*sizeof(AlunoFileStruct));

        //nome
        alunosFile[*n_linhas_lidas].name = malloc((strlen(filedata[0])+1));
        strcpy(alunosFile[*n_linhas_lidas].name, filedata[0]);
        //REGIME
        alunosFile[*n_linhas_lidas].regime = malloc((strlen(filedata[1])+1));
        strcpy(alunosFile[*n_linhas_lidas].regime, filedata[1]);
        //Year
        alunosFile[*n_linhas_lidas].year = atoi(filedata[2]);
        //ID / Número
        alunosFile[*n_linhas_lidas].id = atoi(filedata[3]);
        //Course 
        alunosFile[*n_linhas_lidas].course = malloc((strlen(filedata[4])+1));
        strcpy(alunosFile[*n_linhas_lidas].course, filedata[4]);

        *n_linhas_lidas = *n_linhas_lidas + 1;
    }

    fclose(file);
    return alunosFile;
}

AlunoStruct *ConvertAluno(AlunoFileStruct *alunosFile, int n_linhas_lidas, regimeStruct *regimes, int n_regimes, courseStruct *courses, int n_courses){
    AlunoStruct *alunos = malloc(sizeof(AlunoStruct)*n_linhas_lidas);
    for (int i = 0; i < n_linhas_lidas; i++){
        alunos[i].name = malloc((strlen(alunosFile[i].name)+1));
        strcpy(alunos[i].name, alunosFile[i].name);
        alunos[i].year = alunosFile[i].year;
        alunos[i].id = alunosFile[i].id;
        for (int j = 0; j < n_regimes; j++){
            if (strcmp(alunosFile[i].regime, regimes[j].name) == 0){
                alunos[i].id_regime = regimes[j].id;
                break;
            }
        }
        for (int j = 0; j < n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                alunos[i].id_course = courses[j].id;
                break;
            }
        }
    }
    return alunos;
}

void saveBinAlunos(AlunoStruct *alunos, int n_linhas_lidas){
    FILE *file = fopen("data/bin/alunos.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }
    for (int i = 0; i < n_linhas_lidas; i++){
        fwrite(&alunos[i].id, sizeof(int), 1, file);
        fwrite(&alunos[i].year, sizeof(int), 1, file);
        fwrite(&alunos[i].id_regime, sizeof(int), 1, file);
        fwrite(&alunos[i].id_course, sizeof(int), 1, file);

        size_t nomeLen = strlen(alunos[i].name) + 1;
        fwrite(&nomeLen, sizeof(size_t), 1, file);
        fwrite(alunos[i].name, nomeLen, 1, file);
    }
    fclose(file);
}

void printAlunos(AlunoStruct *alunos, int n_linhas_lidas){
    for (int i = 0; i < n_linhas_lidas; i++){
        printf("ID: %d\n", alunos[i].id);
        printf("Nome: %s\n", alunos[i].name);
        printf("Ano: %d\n", alunos[i].year);
        printf("ID Regime: %d\n", alunos[i].id_regime);
        printf("ID Course: %d\n", alunos[i].id_course);
        printf("\n");
    }
}