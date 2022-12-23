#include <stdio.h>
#include <stdlib.h>
#include "../All_functions/global.h"

void criarSala(){
    char *nomeSala;
    int numeroSala;
    int numeroCadeiras;
    printf("**************************************************\n");
    printc("************        [blue]Criar Salas[/blue]       ************\n");
    printf("**************************************************\n");
    printf("Qual o nome da sala? ");
    scanf(" %[^\n]", &nomeSala);
    printf("Qual o numero da sala? ");
    scanf("%d", &numeroSala);
    printf("Qual o numero de cadeiras? ");
    scanf("%d", &numeroCadeiras);

    FILE *arquivo;
    arquivo = fopen("Salas.bin", "ab");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fwrite(&nomeSala, sizeof(char), 1, arquivo);
    fwrite(&numeroSala, sizeof(int), 1, arquivo);
    fwrite(&numeroCadeiras, sizeof(int), 1, arquivo);
    fclose(arquivo);
}

void listarSalas(){
    char *nomeSala;
    int numeroSala;
    int numeroCadeiras;
    printf("**************************************************\n");
    printc("************       [blue]Lista de Salas[/blue]      ************\n");
    printf("**************************************************\n");
    FILE *arquivo;
    arquivo = fopen("Salas.bin", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    while(fread(&nomeSala, sizeof(char), 1, arquivo) == 1){
        fread(&numeroSala, sizeof(int), 1, arquivo);
        fread(&numeroCadeiras, sizeof(int), 1, arquivo);
        printf("--------------------------------------------\n");
        printf("Nome da sala: %s", nomeSala);
        printf("Numero da sala: %d", numeroSala);
        printf("Numero de cadeiras: %d", numeroCadeiras);
        printf("--------------------------------------------\n");
    }
    fclose(arquivo);
}