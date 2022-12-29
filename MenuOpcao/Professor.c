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

/* void criarProfessor(){
    professorStruct professortemp;
    professortemp.nomeProfessor = malloc(100);
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    printf("Qual o nome do professor? ");
    scanf(" %[^\n]", professortemp.nomeProfessor);
    FILE *file;
    file = fopen("../data/Exames/Professores.bin", "ab");
    if(file == NULL){
        printc("Erro ao abrir o arquivo [red]Professor.bin[/red]");
        exit(1);
    }
    size_t nomeProfessorsize = strlen(professortemp.nomeProfessor) + 1; // +1 para guardar o \0
    fwrite(&nomeProfessorsize, sizeof(size_t), 1, file);
    fwrite(professortemp.nomeProfessor, nomeProfessorsize, 1, file);
    fclose(file);
    free(professortemp.nomeProfessor);
    readBinProfessores();
}

void readBinProfessores(){
    FILE *file;
    file = fopen("../data/Exames/Professores.bin", "rb");
    if(file == NULL){
        printc("Erro ao abrir o arquivo [red]Professor.bin[/red]");
        exit(1);
    }
    fread(&n_professores, sizeof(int), 1, file);
    professores = malloc(n_professores * sizeof(professorStruct));
    for(int i = 0; i < n_professores; i++){
        size_t nomeProfessorsize;
        fread(&nomeProfessorsize, sizeof(size_t), 1, file);
        professores[i].nomeProfessor = malloc(nomeProfessorsize);
        fread(professores[i].nomeProfessor, nomeProfessorsize, 1, file);
    }
    fclose(file);
}
 */