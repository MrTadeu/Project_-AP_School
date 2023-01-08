#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../All_functions/global.h"

/* typedef struct { //struct para guardar os dados de uma sala
    char *nomeSala;
    int numeroSala;
    int numeroCadeiras;
}SalaStruct; */

extern SalaStruct *salas; //extern para poder usar a variavel global. Verificar se está a funcionar corretamente com o resto do programa
extern int n_salas;

void criarSala(){ // #VALIDAR
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    salas = realloc(salas, (n_salas+1)*sizeof(SalaStruct));
    salas[n_salas].nomeSala = malloc(100);
    int id = salas[n_salas-1].id + 1;
    if (n_salas == 0){
        id = 1;
    }
    salas[n_salas].id = id;

    char numeroCadeirasStringImput[1000];
    char numeroSalaStringImput[1000];

    printf("**************************************************\n");
    printc("************        [blue]Criar Salas[/blue]       ************\n");
    printf("**************************************************\n");
    do{
        do{
            printf("Qual o nome da sala? ");
            scanf(" %[^\n]", salas[n_salas].nomeSala);
            if (isdigit_cheker(salas[n_salas].nomeSala) == 1){
                printc("[red]Somente letras e espaços são permitidos[/red]\n");
            }
            
        } while (isdigit_cheker(salas[n_salas].nomeSala) == 1);
        capitalize(salas[n_salas].nomeSala);
        salas[n_salas].nomeSala = realloc(salas[n_salas].nomeSala, strlen(salas[n_salas].nomeSala) + 1);

        do
        {
            
            printf("Qual o numero da sala? ");
            scanf("%s", numeroSalaStringImput);
            if (isletter_cheker(numeroSalaStringImput) == 1){
                printc("[red]Somente numeros são permitidos[/red]\n");
            }
            
        } while(isletter_cheker(numeroSalaStringImput) == 1);
        salas[n_salas].numeroSala = atoi(numeroSalaStringImput);

        if(ChekeIFsalaExist(salas[n_salas].nomeSala, salas[n_salas].numeroSala) == 1){
            printc("[red]Sala já existe[/red]\n");
        }
    }while(ChekeIFsalaExist(salas[n_salas].nomeSala, salas[n_salas].numeroSala) == 1);

    

    do{
        printf("Qual o numero de cadeiras? ");
        scanf("%s", numeroCadeirasStringImput);
        if (isletter_cheker(numeroCadeirasStringImput) == 1){
            printc("[red]Somente numeros são permitidos[/red]\n");
        }
    } while (isletter_cheker(numeroCadeirasStringImput) == 1);
    salas[n_salas].numeroCadeiras = atoi(numeroCadeirasStringImput);

    printf("Sala criada com sucesso! ID: %d\n", salas[n_salas].id);
    n_salas++;
    saveBinSalas();
}

int ChekeIFsalaExist(char *nomeSala, int nSala){
    for(int i = 0; i < n_salas; i++){
        if(strcmp(salas[i].nomeSala, nomeSala) == 0 && salas[i].numeroSala == nSala){
            return 1;
        }
    }
    return 0;
}

void saveBinSalas(){
    FILE *file;
    file = fopen("data/bin/salas.bin", "wb");
    if(!file){
        printf("Erro ao abrir o file \n");
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



void listarSalas(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    printf("**************************************************\n");
    printc("************       [blue]Lista de Salas[/blue]     ************\n");
    printf("**************************************************\n");
    printf("Numero de salas: %d\n", n_salas);
    
    for(int i = 0; i < n_salas; i++){
        printf("-------------------ID: %d -----------------------\n", salas[i].id);
        printf("Nome da sala: %s\n", salas[i].nomeSala);
        printf("Numero da sala: %d\n", salas[i].numeroSala);
        printf("Numero de cadeiras: %d\n", salas[i].numeroCadeiras);
        printf("--------------------------------------------\n");
    }

    printf("Pressione qualquer tecla para continuar...");
    getchar();
    getchar();
}

void readBinSalas(){
    salas = malloc(sizeof(SalaStruct));
    int i;
    FILE *file;
    file = fopen("data/bin/salas.bin", "rb");
    if(!file){
        printc("\n\n\tImpossivel abrir Ficheiro [red]Salas.bin[/red]\n\n");
        return;
    }
    else{
        for (i = 0; ; i++){
            salas = realloc(salas, (i + 1) * sizeof(SalaStruct));
            if(fread(&salas[i].id, sizeof(int), 1, file) != 1){
                break;
            }
            size_t nomeSalasize;
            fread(&nomeSalasize, sizeof(size_t), 1, file);
            salas[i].nomeSala = malloc(nomeSalasize);
            fread(salas[i].nomeSala, nomeSalasize, 1, file);

            fread(&salas[i].numeroSala, sizeof(int), 1, file);

            fread(&salas[i].numeroCadeiras, sizeof(int), 1, file);
        }
        n_salas = i;
        fclose(file);
    }
}

void editarSala(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    char numeroCadeirasStringImput[1000];
    char numeroSalaStringImput[1000];

    printf("**************************************************\n");
    printc("************       [blue]Editar Salas[/blue]       ************\n");
    printf("**************************************************\n");

    int id;
    printf("Qual ID da sala que deseja editar? ");
    scanf("%d", &id);
    for(int i = 0; i < n_salas; i++){
        if(salas[i].id == id){
            do{
                do{
                    printf("Qual o novo nome da sala? ");
                    scanf("%s", salas[i].nomeSala);
                } while (isdigit_cheker(salas[i].nomeSala) == 1);

                do{
                    printf("Qual o novo numero da sala? ");
                    scanf("%s", numeroSalaStringImput);
                    if (isletter_cheker(numeroSalaStringImput) == 1){
                        printc("[red]Somente numeros são permitidos[/red]\n");
                    }
                } while (isletter_cheker(numeroSalaStringImput) == 1);

                if (ChekeIFsalaExist(salas[i].nomeSala, atoi(numeroSalaStringImput)) == 1){
                    printc("[red]Sala ja existe[/red]\n");
                }

            }while (ChekeIFsalaExist(salas[i].nomeSala, atoi(numeroSalaStringImput)) == 1);
            salas[i].numeroSala = atoi(numeroSalaStringImput);

            do{
                printf("Qual o novo numero de cadeiras? ");
                scanf("%s", numeroCadeirasStringImput);
                if (isletter_cheker(numeroCadeirasStringImput) == 1){
                    printc("[red]Somente numeros são permitidos[/red]\n");
                }
            } while (isletter_cheker(numeroCadeirasStringImput) == 1);
            salas[i].numeroCadeiras = atoi(numeroCadeirasStringImput);

            saveBinSalas();
            readBinSalas();
        }
    }
    
}

void removerSala(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarSalas();
    printf("**************************************************\n");
    printc("************       [blue]Remover Salas[/blue]      ************\n");
    printf("**************************************************\n");

    int id;
    printf("Qual ID da sala que deseja editar? ");
    scanf("%d", &id);
    for(int i = 0; i < n_salas; i++){
        if(salas[i].id == id){
            for(int j = i; j < n_salas; j++){
                salas[j] = salas[j + 1];
            }
            n_salas--;
            salas = realloc(salas, n_salas * sizeof(SalaStruct));
            saveBinSalas();
            readBinSalas();
        }
    }
    
}