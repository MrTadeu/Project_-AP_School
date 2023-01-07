#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

/* criarProfessor();
listarProfessor(); 
editarProfessor(); 
removerProfessor(); */
/* typedef struct { //struct para guardar os dados de um professor
    char *nomeProfessor;
    int IDProfessor;
    char *emailProfessor;
    char *passwordProfessor;
}professorStruct; */

extern professorStruct *professores; //extern para poder usar a variavel global.
extern int n_professores; 

void criarProfessor(){
    professorStruct professortemp;
    professortemp.nomeProfessor = malloc(100);
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    printf("Qual o nome do professor? ");
    scanf(" %[^\n]", professortemp.nomeProfessor);
    FILE *file;
    file = fopen("data/bin/Professores.bin", "ab");
    if(!file){
        printc("Erro ao abrir o arquivo [red]Professor.bin[/red]");
        return;
    }
    int idprofessor = professores[n_professores].IDProfessor + 1;
    fwrite(&idprofessor, sizeof(int), 1, file);
    size_t nomeProfessorsize = strlen(professortemp.nomeProfessor) + 1; // +1 para guardar o '\0'
    fwrite(&nomeProfessorsize, sizeof(size_t), 1, file);
    fwrite(professortemp.nomeProfessor, nomeProfessorsize, 1, file);
    fclose(file);
    free(professortemp.nomeProfessor);
    readBinProfessores();
}

void readBinProfessores(){
    professores = malloc(sizeof(professorStruct));
    FILE *file;
    file = fopen("data/bin/Professores.bin", "rb");
    if(file == NULL){
        printc("\n\n\tErro ao abrir o arquivo [red]Professor.bin[/red]\n\n");
        return;
    }
    int i = 0;
    while (fread(&n_professores, sizeof(int), 1, file)){
        size_t nomeProfessorsize;
        fread(&nomeProfessorsize, sizeof(size_t), 1, file);
        professores[i].nomeProfessor = malloc(nomeProfessorsize);
        fread(professores[i].nomeProfessor, nomeProfessorsize, 1, file);
        i++;
        professores = realloc(professores, (i+1) * sizeof(professorStruct));
    }
    n_professores = i;
    fclose(file);
}



void listarProfessor(){
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    for (int i = 0; i < n_professores; i++){
        printf("Nome: %s\n", professores[i].nomeProfessor);
    }
}

void editarProfessor(){
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    int idProfessor;
    printf("Qual o ID do professor que deseja editar? ");
    scanf("%d", &idProfessor);
    for (int i = 0; i < n_professores; i++){
        if (idProfessor == professores[i].IDProfessor){
            printf("Qual o novo nome do professor? ");
            scanf(" %[^\n]", professores[i].nomeProfessor);
            FILE *file;
            file = fopen("data/bin/Professores.bin", "wb");
            if(file == NULL){
                printc("Erro ao abrir o arquivo [red]Professor.bin[/red]");
                return;
            }
            for (int i = 0; i < n_professores; i++){
                fwrite(&n_professores, sizeof(int), 1, file);
                size_t nomeProfessorsize = strlen(professores[i].nomeProfessor) + 1; // +1 para guardar o \0
                fwrite(&nomeProfessorsize, sizeof(size_t), 1, file);
                fwrite(professores[i].nomeProfessor, nomeProfessorsize, 1, file);
            }
            fclose(file);
            readBinProfessores();
        }
    }
}

void removerProfessor(){
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    int idProfessor;
    printf("Qual o ID do professor que deseja remover? ");
    scanf("%d", &idProfessor);
    for (int i = 0; i < n_professores; i++){
        if (idProfessor == professores[i].IDProfessor){
            for (int j = i; j < n_professores; j++){
                professores[j] = professores[j+1];
            }
            n_professores--;
            FILE *file;
            file = fopen("data/bin/Professores.bin", "wb");
            if(file == NULL){
                printc("Erro ao abrir o arquivo [red]Professor.bin[/red]");
                return;
            }
            for (int i = 0; i < n_professores; i++){
                int idprofessor = professores[n_professores].IDProfessor + 1;
                fwrite(&idprofessor, sizeof(int), 1, file);
                size_t nomeProfessorsize = strlen(professores[i].nomeProfessor) + 1; // +1 para guardar o \0
                fwrite(&nomeProfessorsize, sizeof(size_t), 1, file);
                fwrite(professores[i].nomeProfessor, nomeProfessorsize, 1, file);
            }
            fclose(file);
            readBinProfessores();
        }
    }
}

void saveBinProfessor(){
    FILE *file;
    file = fopen("data/bin/Professores.bin", "wb");
    if(file == NULL){
        printc("Erro ao abrir o arquivo [red]Professor.bin[/red]");
        return;
    }
    for (int i = 0; i < n_professores; i++){
        fwrite(&professores[i].IDProfessor, sizeof(int), 1, file);
        size_t nomeProfessorsize = strlen(professores[i].nomeProfessor) + 1; // +1 para guardar o \0
        fwrite(&nomeProfessorsize, sizeof(size_t), 1, file);
        fwrite(professores[i].nomeProfessor, nomeProfessorsize, 1, file);
    }
    fclose(file);
}