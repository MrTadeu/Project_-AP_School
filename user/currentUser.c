#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern int n_alunos, n_regimes, n_courses;
extern AlunoDataStruct aluno;
extern permissionFileStruct *perms_file;

void importExportData(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int op = -1;
    do{
        //op = MenuEditarConta();
        switch (op){
            case 0:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                break;
            case 1:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                changeName();
                break;
            case 2:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                changePassword();
                break;
            default: 
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printc("\n[red]Opção inválida![/red]\n\n");
        }
    } while (op != 0);
}

void changeName(){
    char nome[50];
    printc("********************************************* [blue]Editar nome![/blue] **********************************************\n");
    printf("****         Nome: %s          ****\n", aluno.name);
    printf("****         Novo nome: ");
    scanf("%s", nome);
    strcpy(aluno.name, nome);
    saveBinAlunos();
    printf("****         Nome alterado com sucesso!          ****\n");
    printf("***************************************************************************************************\n");
    getchar();
    getchar();
}

void changePassword(){
    char password[50];
    printc("********************************************* [blue]Editar password![/blue] **********************************************\n");
    printf("****         Password: ********          ****\n");
    printf("****         Nova password: ");
    scanf("%s", password);
    strcpy(aluno.password, password);
    saveBinAlunos();
    printf("****         Password alterada com sucesso!          ****\n");
    printf("***************************************************************************************************\n");
    getchar();
    getchar();
}