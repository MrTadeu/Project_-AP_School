#include <stdio.h>
#include <stdlib.h>
#include "color.h" 



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

void register_users(user_login *storage, int* cont);
void register_storage(user_login *storage, int cont);

void main(){
    int opcao, cont = 0;
    user_login* storage;
    do{
        printf("**************************************************\n");
        printf("***************       Menu LOGIN      ************\n");
        printf("**************************************************\n");
        printf("**        0 -> Sair                             **\n");
        printf("**        1 -> Login                            **\n");
        printf("**        2 -> Registrar                        **\n");
        printf("**************************************************\n");
        printf("**************************************************\n");
        printf("Qual a opção que pretende?");
        scanf("%d", &opcao);
        switch(opcao){
        case 0:
            printf(RED"Saindo do programa...\n"RESET);
            break;
        case 1:
            printf("Login");
            break;
        case 2:
            register_users(storage, &cont);
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
    } while (opcao != 0);
}

void register_users(user_login *storage, int* cont){
    storage = malloc(sizeof(user_login));
    int i = *cont;
    printf("---------Register---------\n");
    printf("Username: ");
    scanf("%s", &storage[i].username_login);
    printf("Password: ");
    scanf("%s", &storage[i].password_login);
    storage = realloc(storage, sizeof(user_login)*(i+1));
    i++;
    *cont = i;
    /* register_storage(storage, i);*/   //I don't know why this function is not working
} 

/* void register_storage(user_login *storage, int cont){
    FILE* userstxt = fopen("users.txt", "a");
    if (userstxt == NULL){
        printf("Erro ao abrir o ficheiro!");
        exit(1);
    }
    for (int i = 0; i <= cont; i++){
        fprintf(userstxt, "%s %s", storage[i].username_login, storage[i].password_login);
    }
    fclose(userstxt);
} */
/* void login(){
    printf("---------Login---------\n");
    printf("Username: ");
    scanf("%s",);
} */
