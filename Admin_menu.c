#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "All_functions\global.h"

const char* PERSON_FORMAT_OUT = "%s;%s;%d;%s\n";

typedef struct{
    int id_permission, enable;
}hasPermission;
typedef struct{    
    int id;
    char name;
    hasPermission* permission;
}cargo;
typedef struct{
    int id;
    char name;
}permission;

typedef struct{
    char username[20], regime[20], course[20];
    int  year;
}user_login;

void register_users(user_login *people,  int* cont);
void register_people(user_login *people, int cont);
void read_register_people(user_login *people, int cont);

void main(){
    int opcao, cont = 0;
    user_login* people;
    do{
        printf("**************************************************\n");
        printf("***************      Menu ADMIN       ************\n");
        printf("**************************************************\n");
        printf("**        0 -> Sair                             **\n");
        printf("**        1 -> Registrar                        **\n");
        printf("**        2 -> XXXXXXXXX                        **\n");
        printf("**************************************************\n");
        printf("**************************************************\n");
        printf("Qual a opção que pretende? ");
        scanf("%d", &opcao);
        switch(opcao){
        case 0:
            printf("Saindo do programa...\n");
            break;
        case 1:
            register_users(people, &cont);
            break;
        case 2:
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
    } while (opcao != 0);
}

void register_users(user_login *people, int* cont){
    people = malloc(sizeof(user_login));
    if(people == NULL){
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    printc("---------[red]Register[/red]---------\n");
    printc("[blue]Nome[/blue]: ");
    scanf(" %[^\n]", people[*cont].username);
    printc("[blue]Regime[/blue]: ");
    scanf("%s", people[*cont].regime);
    printc("[blue]Ano[/blue]: ");
    scanf("%d", &people[*cont].year);
    printc("[blue]Curso[/blue]: ");
    scanf("%s", people[*cont].course);
    people = realloc(people, sizeof(user_login)*(*cont+1));
    *cont = *cont + 1;
    spinner_start(0, "Initialize...");
    int i, mul = 10;
    for(i = 0; i < 10 * mul; i++){
        Sleep(3);
        spinner_update("[yellow]A ler[/yellow] [bw][red]%d[/red][/bw]...", i);
    }
    spinner_done("[green]Foi Registado com sucesso![/green]\n");
    register_people(people, *cont);   //I don't know why this function is not working
    read_register_people(people, *cont);
}

void register_people(user_login *people, int cont){
    FILE* usersbin = fopen("users.bin", "ab");
    if (usersbin == NULL){
        printf("Erro ao abrir o ficheiro!");
        exit(1);
    }
    for(int i = 0; i < cont; i++){
        size_t elements_writen = fwrite(&people[i], sizeof(user_login), 1, usersbin);
        if (elements_writen == 0){
            exit(2);
        }
    }
    
    fclose(usersbin);
}

void read_register_people(user_login *people, int cont){
    FILE* usersbin = fopen("users.bin", "rb");
    if (usersbin == NULL){
        printf("Erro ao abrir o ficheiro!");
        exit(1);
    }
    for(int i = 0; i < cont; i++){
        size_t elements_read = fread(&people[i], sizeof(user_login), 1, usersbin);
        if (elements_read == 0){
            exit(2);
        }
        printf("%s %s %d %s", people[i].username, people[i].regime, people[i].year, people[i].course);
    }
    fclose(usersbin);
}
/* void login(){
    printf("---------Login---------\n");
    printf("Username: ");
    scanf("%s",);
} */
