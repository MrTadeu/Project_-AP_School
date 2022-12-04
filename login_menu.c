#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "All_functions\global.h"

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
    char* username_login;
    char* password_login;
}user_login;

void register_users(user_login *people, int* cont);
void register_people(user_login *people, int cont);

void main(){
    int opcao, cont = 0;
    user_login* people;
    do{
        printf("**************************************************\n");
        printf("***************      Menu LOGIN       ************\n");
        printf("**************************************************\n");
        printf("**        0 -> Sair                             **\n");
        printf("**        1 -> Login                            **\n");
        printf("**        2 -> Registrar                        **\n");
        printf("**************************************************\n");
        printf("**************************************************\n");
        printf("Qual a opção que pretende? ");
        scanf("%d", &opcao);
        switch(opcao){
        case 0:
            printf("Saindo do programa...\n");
            break;
        case 1:
            printf("Login");
            break;
        case 2:
            register_users(people, &cont);
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
    } while (opcao != 0);
}

void register_users(user_login *people, int* cont){
    people = malloc(sizeof(user_login));
    int i = *cont;
    printc("---------[red]Register[/red]---------\n");
    printf("Username: ");
    scanf("%s", &people[i].username_login);
    printf("Password: ");
    scanf("%s", &people[i].password_login);
    people = realloc(people, sizeof(user_login)*(i+1));
    i++;
    *cont = i;
    for(int j = 0; j < i; j++){
        printf("Username: %s", people[j].username_login);
        printf("Password: %s", people[j].password_login);
    }
    register_people(people, i);   //I don't know why this function is not working
} 

void register_people(user_login *people, int cont){
    FILE* userstxt = fopen("users.txt", "w");
    if (userstxt == NULL){
        printf("Erro ao abrir o ficheiro!");
        exit(1);
    }
    for (int i = 0; i <= cont; i++){
        fprintf(userstxt, "%s;%s", people[i].username_login, people[i].password_login);
    }
    fclose(userstxt);
}
/* void login(){
    printf("---------Login---------\n");
    printf("Username: ");
    scanf("%s",);
} */
