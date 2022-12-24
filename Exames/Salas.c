// Created by: Benno Verificar se está a funcionar corretamente com o resto do programa (Externos)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

void listarSalas();
SalaStruct* readBinSalas(int *n_salas);
int ChekeIFsalaExist(char *nomeSala, int nSala);

extern SalaStruct *salas; //extern para poder usar a variavel global. Verificar se está a funcionar corretamente com o resto do programa
extern int n_salas;

void criarSala(){ // #VALIDAR
    SalaStruct salatemp;
    salatemp.nomeSala = malloc(100);
    printf("**************************************************\n");
    printc("************        [blue]Criar Salas[/blue]       ************\n");
    printf("**************************************************\n");
    do{
        printf("Qual o nome da sala? ");
        scanf(" %[^\n]", salatemp.nomeSala);
        uppercase(salatemp.nomeSala);
        salatemp.nomeSala = realloc(salatemp.nomeSala, strlen(salatemp.nomeSala) + 1);
        printf("Qual o numero da sala? ");
        scanf("%d", &salatemp.numeroSala);
        if(ChekeIFsalaExist(salatemp.nomeSala, salatemp.numeroSala) == 1){
            printc("[red]Sala já existe[/red]\n");
        }
    }while(ChekeIFsalaExist(salatemp.nomeSala, salatemp.numeroSala) == 1);
    
    printf("Qual o numero de cadeiras? ");
    scanf("%d", &salatemp.numeroCadeiras);
    FILE *arquivo;
    arquivo = fopen("../data/Exames/Salas.bin", "ab");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    size_t nomeSalasize = strlen(salatemp.nomeSala) + 1;
    printf("%d", nomeSalasize);
    fwrite(&nomeSalasize, sizeof(size_t), 1, arquivo);
    fwrite(salatemp.nomeSala, nomeSalasize, 1, arquivo);
    fwrite(&salatemp.numeroSala, sizeof(int), 1, arquivo);
    fwrite(&salatemp.numeroCadeiras, sizeof(int), 1, arquivo);
    fclose(arquivo);
}

int ChekeIFsalaExist(char *nomeSala, int nSala){
    //SalaStruct *sala;
    //int n_salas = 0;
    //sala = readBinSalas(&n_salas);
    for(int i = 0; i < n_salas; i++){
        if(strcmp(salas[i].nomeSala, nomeSala) == 0 && salas[i].numeroSala == nSala){
            return 1;
        }
    }
    return 0;
}

void listarSalas(){
    //SalaStruct *sala; 
    printf("**************************************************\n");
    printc("************       [blue]Lista de Salas[/blue]      ************\n");
    printf("**************************************************\n");
    size_t nomeSalasize;
    //int n_salas = 0;
    //sala = readBinSalas(&n_salas);
    printf("Numero de salas: %d\n", n_salas);
    for(int i = 0; i < n_salas; i++){
        printf("--------------------------------------------\n");
        printf("Nome da sala: %s\n", salas[i].nomeSala);
        printf("Numero da sala: %d\n", salas[i].numeroSala);
        printf("Numero de cadeiras: %d\n", salas[i].numeroCadeiras);
        printf("--------------------------------------------\n");
    }
}

SalaStruct* readBinSalas(int *n_salas){
    SalaStruct *sala = malloc(sizeof(SalaStruct));
    FILE *arquivo;
    arquivo = fopen("../data/Exames/Salas.bin", "rb");
    if(arquivo == NULL){
        printc("\n\n\tErro ao abrir o arquivo [red]Salas.bin[/red]\n\n");
        return NULL;
    }
    size_t nomeSalasize;
    int i = 0;
    while(fread(&nomeSalasize, sizeof(size_t), 1, arquivo)){
        sala[i].nomeSala = malloc(nomeSalasize);
        fread(sala[i].nomeSala, nomeSalasize, 1, arquivo);
        fread(&sala[i].numeroSala, sizeof(int), 1, arquivo);
        fread(&sala[i].numeroCadeiras, sizeof(int), 1, arquivo);
        i++;
        sala = realloc(sala, (i + 1) * sizeof(SalaStruct));
    }
    *n_salas = i;
    fclose(arquivo);
    return sala;
}

void editarSala(){ // #VALIDAR
    //SalaStruct *sala;
    //int n_salas = 0;
    //sala = readBinSalas(&n_salas);
    int numeroSala;
    char *nomeSala = malloc(100);
    printf("**************************************************\n");
    printc("************       [blue]Editar Salas[/blue]       ************\n");
    printf("**************************************************\n");
    printf("Qual o nome da sala que deseja editar? ");
    scanf("%s", nomeSala);
    uppercase(nomeSala);
    nomeSala = realloc(nomeSala, strlen(nomeSala) + 1);
    printf("Qual o numero da sala que deseja editar? ");
    scanf("%d", &numeroSala);
    for(int i = 0; i < n_salas; i++){
        if((salas[i].numeroSala == numeroSala) && (strcmp(salas[i].nomeSala, nomeSala) == 0)){  
            printf("Qual o novo nome da sala? ");
            scanf("%s", salas[i].nomeSala);
            printf("Qual o novo numero da sala? ");
            scanf("%d", &salas[i].numeroSala);
            printf("Qual o novo numero de cadeiras? ");
            scanf("%d", &salas[i].numeroCadeiras);
        }
    }
    FILE *arquivo;
    arquivo = fopen("../data/Exames/Salas.bin", "wb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    for(int i = 0; i < n_salas; i++){
        size_t nomeSalasize = strlen(salas[i].nomeSala) + 1;
        fwrite(&nomeSalasize, sizeof(size_t), 1, arquivo);
        fwrite(salas[i].nomeSala, nomeSalasize, 1, arquivo);
        fwrite(&salas[i].numeroSala, sizeof(int), 1, arquivo);
        fwrite(&salas[i].numeroCadeiras, sizeof(int), 1, arquivo);
    }
    fclose(arquivo);
}

void removerSalas(){ // #VALIDAR
    //SalaStruct *sala;
    //int n_salas = 0;
    //sala = readBinSalas(&n_salas);
    int numeroSala;
    char *nomeSala = malloc(100);
    printf("**************************************************\n");
    printc("************       [blue]Remover Salas[/blue]      ************\n");
    printf("**************************************************\n");
    printf("Qual o nome da sala que deseja remover? ");
    scanf("%s", nomeSala);
    uppercase(nomeSala);
    nomeSala = realloc(nomeSala, strlen(nomeSala) + 1);
    printf("Qual o numero da sala que deseja remover? ");
    scanf("%d", &numeroSala);
    for(int i = 0; i < n_salas; i++){
        if((salas[i].numeroSala == numeroSala) && (strcmp(salas[i].nomeSala, nomeSala) == 0)){
            for(int j = i; j < n_salas; j++){
                salas[j] = salas[j + 1];
            }
            n_salas--;
        }
    }
    FILE *arquivo;
    arquivo = fopen("../data/Exames/Salas.bin", "wb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    for(int i = 0; i < n_salas; i++){
        size_t nomeSalasize = strlen(salas[i].nomeSala) + 1;
        fwrite(&nomeSalasize, sizeof(size_t), 1, arquivo);
        fwrite(salas[i].nomeSala, nomeSalasize, 1, arquivo);
        fwrite(&salas[i].numeroSala, sizeof(int), 1, arquivo);
        fwrite(&salas[i].numeroCadeiras, sizeof(int), 1, arquivo);
    }
    fclose(arquivo);
}