// Created by: Benno Verificar se está a funcionar corretamente com o resto do programa (Externos)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

/* typedef struct { //struct para guardar os dados de uma sala
    char *nomeSala;
    int *numeroSala;
    int *numeroCadeiras;
}SalaStruct; */

extern SalaStruct *salas;
extern int n_salas;

int ChekeIFsalaExist(char *nomeSala, int nSala);

extern SalaStruct *salas; //extern para poder usar a variavel global. Verificar se está a funcionar corretamente com o resto do programa
extern int n_salas;

void criarSala(){ // #VALIDAR
    salas = realloc(salas, (n_salas+1)*sizeof(SalaStruct));
    salas[n_salas].nomeSala = malloc(100);
    int id = salas[n_salas - 1].id + 1;
    printf("**************************************************\n");
    printc("************        [blue]Criar Salas[/blue]       ************\n");
    printf("**************************************************\n");
    do{
        printf("Qual o nome da sala? ");
        scanf(" %[^\n]", salas[n_salas].nomeSala);
        uppercase(salas[n_salas].nomeSala);
        salas[n_salas].nomeSala = realloc(salas[n_salas].nomeSala, strlen(salas[n_salas].nomeSala) + 1);
        salas[n_salas].id = id;
        printf("Qual o numero da sala? ");
        scanf("%d", &salas[n_salas].nomeSala);
        if(ChekeIFsalaExist(salas[n_salas].nomeSala, salas[n_salas].numeroSala) == 1){
            printc("[red]Sala já existe[/red]\n");
        }
    }while(ChekeIFsalaExist(salas[n_salas].nomeSala, salas[n_salas].numeroSala) == 1);
    
    printf("Qual o numero de cadeiras? ");
    scanf("%d", &salas[n_salas].numeroCadeiras);

    n_salas++;
    saveBinSalas();
}

void saveBinSalas(){
    FILE *file;
    file = fopen("../data/MenuOpcao/Salas.bin", "wb");
    if(file == NULL){
        printf("Erro ao abrir o file");
        return;
    }
    for(int i = 0; i < n_salas; i++){
        fwrite(&salas[i].id, sizeof(int), 1, file);

        size_t nomeSalasize = strlen(salas[i].nomeSala) + 1;
        fwrite(&nomeSalasize, sizeof(size_t), 1, file);
        fwrite(salas[i].nomeSala, nomeSalasize, 1, file);

        fwrite(&salas[i].numeroSala, sizeof(int), 1, file);

        fwrite(&salas[i].numeroCadeiras, sizeof(int), 1, file);
    }
    fclose(file);
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

void readBinSalas(){
    SalaStruct *sala = malloc(sizeof(SalaStruct));
    FILE *file;
    file = fopen("../data/MenuOpcao/Salas.bin", "rb");
    if(file == NULL){
        printc("\n\n\tErro ao abrir o file [red]Salas.bin[/red]\n\n");
        return;
    }
    size_t nomeSalasize;
    int i = 0;
    while(fread(&nomeSalasize, sizeof(size_t), 1, file)){
        sala[i].nomeSala = malloc(nomeSalasize);
        fread(sala[i].nomeSala, nomeSalasize, 1, file);
        fread(&sala[i].numeroSala, sizeof(int), 1, file);
        fread(&sala[i].numeroCadeiras, sizeof(int), 1, file);
        i++;
        sala = realloc(sala, (i + 1) * sizeof(SalaStruct));
    }
    n_salas = i;
    fclose(file);

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
    FILE *file;
    file = fopen("../data/MenuOpcao/Salas.bin", "wb");
    if(file == NULL){
        printf("Erro ao abrir o file");
        exit(1);
    }
    for(int i = 0; i < n_salas; i++){
        size_t nomeSalasize = strlen(salas[i].nomeSala) + 1;
        fwrite(&nomeSalasize, sizeof(size_t), 1, file);
        fwrite(salas[i].nomeSala, nomeSalasize, 1, file);
        fwrite(&salas[i].numeroSala, sizeof(int), 1, file);
        fwrite(&salas[i].numeroCadeiras, sizeof(int), 1, file);
    }
    free(nomeSala);
    free(salas);
    fclose(file);
    readBinSalas();
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
    FILE *file;
    file = fopen("../data/MenuOpcao/Salas.bin", "wb");
    if(file == NULL){
        printf("Erro ao abrir o file");
        exit(1);
    }
    for(int i = 0; i < n_salas; i++){
        size_t nomeSalasize = strlen(salas[i].nomeSala) + 1;
        fwrite(&nomeSalasize, sizeof(size_t), 1, file);
        fwrite(salas[i].nomeSala, nomeSalasize, 1, file);
        fwrite(&salas[i].numeroSala, sizeof(int), 1, file);
        fwrite(&salas[i].numeroCadeiras, sizeof(int), 1, file);
    }
    free(nomeSala);
    free(salas);
    fclose(file);
    readBinSalas();
}