// Created by: Benno Verificar se está a funcionar corretamente com o resto do programa (Externos)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

void listarSalas();
SalaStruct* readSalas(int *n_salas);

extern SalaStruct *salas; //extern para poder usar a variavel global. Verificar se está a funcionar corretamente com o resto do programa
extern int n_salas;

void criarSala(){
    SalaStruct sala;
    sala.nomeSala = malloc(100);
    printf("**************************************************\n");
    printf("************        [blue]Criar Salas[/blue]       ************\n");
    printf("**************************************************\n");
    printf("Qual o nome da sala? ");
    scanf("%s", sala.nomeSala); //[^\n]
    sala.nomeSala = realloc(sala.nomeSala, strlen(sala.nomeSala) + 1);
    printf("Qual o numero da sala? ");
    scanf("%d", &sala.numeroSala);
    printf("Qual o numero de cadeiras? ");
    scanf("%d", &sala.numeroCadeiras);
    FILE *arquivo;
    arquivo = fopen("Salas.bin", "ab");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");s
        exit(1);
    }
    size_t nomeSalasize = strlen(sala.nomeSala) + 1;
    printf("%d", nomeSalasize);
    fwrite(&nomeSalasize, sizeof(size_t), 1, arquivo);
    fwrite(sala.nomeSala, nomeSalasize, 1, arquivo);
    fwrite(&sala.numeroSala, sizeof(int), 1, arquivo);
    fwrite(&sala.numeroCadeiras, sizeof(int), 1, arquivo);
    fclose(arquivo);
}

void listarSalas(){
    SalaStruct *sala;
    printf("**************************************************\n");
    printf("************       [blue]Lista de Salas[/blue]      ************\n");
    printf("**************************************************\n");
    size_t nomeSalasize;
    int n_salas = 0;
    //readBinSalas(&n_salas);
    printf("Numero de salas: %d\n", n_salas);
    for(int i = 0; i < n_salas; i++){
        printf("--------------------------------------------\n");
        printf("Nome da sala: %s\n", sala[i].nomeSala);
        printf("Numero da sala: %d\n", sala[i].numeroSala);
        printf("Numero de cadeiras: %d\n", sala[i].numeroCadeiras);
        printf("--------------------------------------------\n");
    }
}

SalaStruct* readBinSalas(int *n_salas){
    SalaStruct *sala = malloc(sizeof(SalaStruct));
    FILE *arquivo;
    arquivo = fopen("Salas.bin", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
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