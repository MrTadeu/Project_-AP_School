#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

void printAlunos(AlunoStruct *alunos, int n_alunos){
    for (int i = 0; i < n_alunos; i++){
        printf("ID: %d\n", alunos[i].id);
        printf("Nome: %s\n", alunos[i].name);
        printf("Ano: %d\n", alunos[i].year);
        printf("ID Regime: %d\n", alunos[i].id_regime);
        printf("ID Course: %d\n", alunos[i].id_course);
        printf("\n");
    }
}

void saveBinAlunos(AlunoStruct *alunos, int n_alunos){
    FILE *file = fopen("data/bin/alunos.bin","ab");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]alunos.bin[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_alunos; i++){
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

AlunoStruct *readBinAlunos(int *n_alunos){
    AlunoStruct *alunos = malloc(sizeof(AlunoStruct));
    int i;
    FILE *file = fopen("data/bin/alunos.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]alunos.bin[/red]\n\n");
        exit(1);
    }

    for (i = 0;; i++){
        if(fread(&alunos[i].id, sizeof(int), 1, file) != 1) break;
        fread(&alunos[i].year, sizeof(int), 1, file);
        fread(&alunos[i].id_regime, sizeof(int), 1, file);
        fread(&alunos[i].id_course, sizeof(int), 1, file);
        
        size_t nameLen;
        fread(&nameLen, sizeof(size_t), 1, file);
        alunos[i].name = malloc(nameLen);
        fread(alunos[i].name, nameLen, 1, file);

        alunos = realloc(alunos, sizeof(AlunoStruct) * (i+2));
    }
    *n_alunos = i-1;
    fclose(file);
    return alunos;
}

/* AlunoStruct readBinAluno(int id_aluno){
    AlunoStruct aluno;

    FILE *file_alunos = fopen("data/bin/alunos.bin","rb");
    if (!file_alunos) {
        printf("\n\n\tImpossivel abrir Ficheiro alunos.bin\n\n");
        exit(1);
    }
    FILE *file_regimes = fopen("data/bin/regimes.bin","rb");
    if (!file_regimes) {
        printf("\n\n\tImpossivel abrir Ficheiro regimes.bin\n\n");
        exit(1);
    }
    FILE *file_course = fopen("data/bin/course.bin","rb");
    if (!file_course) {
        printf("\n\n\tImpossivel abrir Ficheiro course.bin\n\n");
        exit(1);
    }


    for (int i = 0;; i++){
        if(fread(&aluno.id, sizeof(int), 1, file_alunos) != 1) break;
        if (aluno.id == id_aluno){

            //GET ALUNO DATA FROM FILE
            fread(&aluno.year, sizeof(int), 1, file_alunos);
            fread(&aluno.id_regime, sizeof(int), 1, file_alunos);
            fread(&aluno.id_course, sizeof(int), 1, file_alunos);

            size_t nameLen;
            fread(&nameLen, sizeof(size_t), 1, file_alunos);
            aluno.name = malloc(nameLen);
            fread(aluno.name, nameLen, 1, file_alunos);


            for (int j = 0;; j++){
                if(fread(&aluno.id_regime, sizeof(int), 1, file_regimes) != 1) break;
                if (aluno.id_regime == aluno.id_regime){
                    size_t regimeLen;
                    fread(&regimeLen, sizeof(size_t), 1, file_regimes);
                    aluno.name = malloc(regimeLen);
                    fread(aluno.name, regimeLen, 1, file_regimes);
                    break;
                }
            }
            



            fclose(file_alunos);
            return aluno;
        }
    }
    fclose(file_alunos);
} */