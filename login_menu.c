#include <stdio.h>

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
void register_people(user_login *storage, int* cont);

void main(){
    int opcao, cont = 0;
    user_login* storage;
    printf("**************************************************\n");
    printf("***************       Menu LOGIN      ************\n");
    printf("**************************************************\n");
    printf("**        0 -> Sair                             **\n");
    printf("**        1 -> Login                            **\n");
    printf("**        2 -> Registrar                        **\n");
    printf("**************************************************\n");
    printf("Qual a opção que pretende?");
    scanf("%d", &opcao);
    switch(opcao){
        case 0:
            printf("Sair");
            break;
        case 1:
            printf("Login");
            break;
        case 2:
            register_people(storage, &cont);
            break;
        default:
            printf("Opção inválida");
            break;
    }
}

void register_people(user_login *storage, int* cont){
    storage = malloc(sizeof(user_login));
    int i = *cont;
    printf("---------Register---------\n");
    printf("Username: ");
    scanf("%s", &storage[i].username_login);
    printf("Password: ");
    scanf("%s", &storage[i].password_login);
    i++;
    *cont = i;

}
/* 
void login(){
    printf("---------Login---------\n");
    printf("Username: ");
    scanf("%s",);
} */