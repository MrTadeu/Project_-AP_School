#include <stdio.h>

typedef struct{
    char name_user;
    char password;
}user;

typedef struct{
    user admin;
    user student;
    user teacher;
}permission;

void main(){
    int opcao;
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
            register_people(p);
            break;
        default:
            printf("Opção inválida");
            break;
    }
}

void register_people(permission *p){
    printf("---------Register---------\n");
    printf("Username: ");
    scanf("%s", p->admin);
}
/* 
void login(){
    printf("---------Login---------\n");
    printf("Username: ");
    scanf("%s",);
} */