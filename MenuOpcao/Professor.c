#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

/* typedef struct { //struct para guardar os dados de um professor
    char *nomeProfessor;
    int id;
    char *emailProfessor;
    char *passwordProfessor;
}professorStruct;*/

extern professorStruct *professores; //extern para poder usar a variavel global.
extern int n_professores; 

void criarProfessor(){
    professores = realloc(professores, (n_professores+1)*sizeof(professorStruct));
    professores[n_professores].nomeProfessor = malloc(100);
    int id = professores[n_professores - 1].id + 1;
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    printf("Qual o nome do professor? ");
    scanf(" %[^\n]", professores[n_professores].nomeProfessor);
    professores[n_professores].nomeProfessor = realloc(professores[n_professores].nomeProfessor, (strlen(professores[n_professores].nomeProfessor)+1));
    professores[n_professores].id = id;

    char *email = malloc(strlen("pv") + 10 + strlen("@estgv.ipv.pt")), *password = malloc(100);
    //email example: pv25207@estgv.ipv.prof.pt
    email[0] = '\0';
    strcat(email, "pv");
    char* id_char = malloc(10);
    itoa(id, id_char, 10);
    strcat(email, id);
    strcat(email, "@estgv.ipv.prof.pt");
    professores[n_professores].emailProfessor = malloc((strlen(email)+1));
    strcpy(professores[n_professores].emailProfessor, email);
    password[0] = '\0';
    strcat(password, "pv");
    strcat(password, id);
    strcat(password, professores[n_professores].passwordProfessor);
    professores[n_professores].passwordProfessor = malloc((strlen(password)+1));
    strcpy(professores[n_professores].passwordProfessor, password);

    saveBinProfessor();
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
        printf("ID: %d Nome: %s\n", professores[i].id, professores[i].nomeProfessor);
    }
}

void editarProfessor(){
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    int id;
    printf("Qual o ID do professor que deseja editar? ");
    scanf("%d", &id);
    for (int i = 0; i < n_professores; i++){
        if (id == professores[i].id){
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
    int id;
    printf("Qual o ID do professor que deseja remover? ");
    scanf("%d", &id);
    for (int i = 0; i < n_professores; i++){
        if (id == professores[i].id){
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
                int id = professores[n_professores].id + 1;
                fwrite(&id, sizeof(int), 1, file);
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
        fwrite(&professores[i].id, sizeof(int), 1, file);
        size_t nomeProfessorsize = strlen(professores[i].nomeProfessor) + 1; // +1 para guardar o \0
        fwrite(&nomeProfessorsize, sizeof(size_t), 1, file);
        fwrite(professores[i].nomeProfessor, nomeProfessorsize, 1, file);
        size_t emailProfessorsize = strlen(professores[i].emailProfessor) + 1; // +1 para guardar o \0
        fwrite(&emailProfessorsize, sizeof(size_t), 1, file);
        size_t passwordProfessorsize = strlen(professores[i].passwordProfessor) + 1; // +1 para guardar o \0
        fwrite(professores[i].passwordProfessor, strlen(professores[i].passwordProfessor) + 1, 1, file);
    }
    fclose(file);
}