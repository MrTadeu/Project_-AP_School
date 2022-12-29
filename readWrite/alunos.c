#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern int n_alunos, n_regimes, n_courses;
extern AlunoDataStruct aluno;

void printAlunos(){
    for (int i = 0; i < n_alunos; i++){
        printf("\nI: %d", i);
        printf(" ID: %d", alunos[i].id);
        printf(" Nome: %s", alunos[i].name);
        printf(" Ano: %d", alunos[i].year);
        printf(" ID Regime: %d", alunos[i].id_regime);
        printf(" ID Course: %d", alunos[i].id_course);
        printf(" Email: %s", alunos[i].email);
        printf(" Password: %s", alunos[i].password);
    }
    printc("\n\n[lw]Pressione enter para continuar[/lw]\n");  
    getchar();
    getchar();
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
}

void saveBinAlunos(){
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

        size_t emailLen = strlen(alunos[i].email) + 1;
        fwrite(&emailLen, sizeof(size_t), 1, file);
        fwrite(alunos[i].email, emailLen, 1, file);

        size_t passLen = strlen(alunos[i].password) + 1;
        fwrite(&passLen, sizeof(size_t), 1, file);
        fwrite(alunos[i].password, passLen, 1, file);
    }
    fclose(file);
}

AlunoStruct *readBinAlunos(){
    AlunoStruct *alunos = malloc(sizeof(AlunoStruct));
    int i;
    FILE *file = fopen("data/bin/alunos.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]alunos.bin[/red]\n\n");
        return NULL;
    }
    else{
        for (i = 0;; i++){
            if(fread(&alunos[i].id, sizeof(int), 1, file) != 1) break;
            fread(&alunos[i].year, sizeof(int), 1, file);
            fread(&alunos[i].id_regime, sizeof(int), 1, file);
            fread(&alunos[i].id_course, sizeof(int), 1, file);
            
            size_t nameLen;
            fread(&nameLen, sizeof(size_t), 1, file);
            alunos[i].name = malloc(nameLen);
            fread(alunos[i].name, nameLen, 1, file);

            size_t emailLen;
            fread(&emailLen, sizeof(size_t), 1, file);
            alunos[i].email = malloc(emailLen);
            fread(alunos[i].email, emailLen, 1, file);

            size_t passLen;
            fread(&passLen, sizeof(size_t), 1, file);
            alunos[i].password = malloc(passLen);
            fread(alunos[i].password, passLen, 1, file);

            alunos = realloc(alunos, sizeof(AlunoStruct) * (i+2));
        }
        n_alunos = i-1;
        fclose(file);
        return alunos;
    }
}



void login(char *email, char *password){
    int i, flag = 0;
    for (i = 0; i < n_alunos; i++){
        if (strcmp(email, alunos[i].email) == 0 && strcmp(password, alunos[i].password) == 0){
            flag = 1;
            printc("\n\n\t[green]Login feito com sucesso[/green]\n\n");
            getchar();
            getchar();
            fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
            getUserDataByID(alunos[i].id);
        }
    }
    if(flag == 0){
        printc("\n\n\t[red]Dados Inválidos.[/red]\n\n");
        getchar();
        getchar();
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    }
}

/* char *name, *email, *password;
    int id, year;
    courseStruct course;
    regimeStruct regime; */


void getUserDataByID(int id){
    int position = 0;
    for (int i = 0; i < n_alunos; i++){
        if (id == alunos[i].id){
            position = i;
            break;
        }
    }
    aluno.id = id;
    aluno.name = malloc(strlen(alunos[position].name)+1);
    aluno.email = malloc(strlen(alunos[position].email)+1);
    aluno.password = malloc(strlen(alunos[position].password)+1);
    strcpy(aluno.name, alunos[position].name);
    strcpy(aluno.email, alunos[position].email);
    strcpy(aluno.password, alunos[position].password);
    aluno.year = alunos[position].year;
    aluno.regime = getRegimeByID(alunos[position].id_regime);
    aluno.course = getCourseByID(alunos[position].id_course);
    printfUserData();
}

void printfUserData(){
    printc("\n\t[green]ID:[/green] %d", aluno.id);
    printc("\n\t[green]Nome:[/green] %s", aluno.name);
    printc("\n\t[green]Email:[/green] %s", aluno.email);
    printc("\n\t[green]Password:[/green] %s", aluno.password);
    printc("\n\t[green]Ano:[/green] %d", aluno.year);
    printc("\n\t[green]Regime ID:[/green] %d", aluno.regime.id);
    printc("\n\t[green]Regime:[/green] %s", aluno.regime.name);
    printc("\n\t[green]Curso ID:[/green] %d", aluno.course.id);
    printc("\n\t[green]Curso:[/green] %s", aluno.course.name);
    getchar();
    getchar();
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