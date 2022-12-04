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

void register_users();
void register_people(user_login people);
void read_register_people();

void main(){
    int opcao, cont = 0;
    user_login people;
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
            register_users();
            break;
        case 2:
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
    } while (opcao != 0);
}

void register_users(){
    user_login people;
    printc("---------[red]Register[/red]---------\n");
    printc("[blue]Nome[/blue]: ");
    scanf(" %[^\n]", people.username);
    printc("[blue]Regime[/blue]: ");
    scanf("%s", people.regime);
    printc("[blue]Ano[/blue]: ");
    scanf("%d", &people.year);
    printc("[blue]Curso[/blue]: ");
    scanf("%s", people.course);
    spinner_start(0, "Initialize...");
    int i, mul = 10;
    for(i = 0; i < 10 * mul; i++){
        Sleep(3);
        spinner_update("[yellow]A ler[/yellow] [bw][red]%d[/red][/bw]...", i);
    }
    spinner_done("[green]Foi Registado com sucesso![/green]\n");
    register_people(people);   //I don't know why this function is not working
    read_register_people(); 
}

void register_people(user_login people){
    FILE* usersbin = fopen("users.bin", "ab");
    if (usersbin == NULL){
        printf("Erro ao abrir o ficheiro!");
        exit(1);
    }
    fwrite(&people, sizeof(user_login), 1, usersbin);
    fclose(usersbin);
}

void read_register_people(){
    FILE* usersbin = fopen("users.bin", "rb");
    user_login* people = (user_login*) malloc(sizeof(user_login));
    if (usersbin == NULL){
        printf("Erro ao abrir o ficheiro!");
        exit(1);
    }
    while(fread(people, sizeof(user_login),1,usersbin)){
        printf("%s %s %d %s", people->username, people->regime, people->year, people->course);
    }
    fclose(usersbin);
}
/* void login(){
    printf("---------Login---------\n");
    printf("Username: ");
    scanf("%s",);
} */