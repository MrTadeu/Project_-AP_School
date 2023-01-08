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

void MenuAdmin(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int op = -1;
    do{
        op = MenuEditarConta();
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

void listarTodosAlunos(){
    printf("Listagem de todos os alunos:\n");
    for (int i = 0; i < n_alunos; i++){
        printf(" ID: %d", alunos[i].id);
        printf(" Nome: %s", alunos[i].name);
        printf(" Ano: %d", alunos[i].year);
        printf(" ID Regime: %d", alunos[i].id_regime);
        printf(" ID Course: %d", alunos[i].id_course);
        printf(" Email: %s\n", alunos[i].email);
    }
    printc("\n\n[lw]Pressione enter para continuar[/lw]\n");  
    getchar();
    getchar();
}

void listarAluno(){
    printf("Por favor insira o ID do aluno que pretende listar:\n");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < n_alunos; i++){
        if (alunos[i].id == id){
            printf(" ID: %d", alunos[i].id);
            printf(" Nome: %s", alunos[i].name);
            printf(" Ano: %d", alunos[i].year);
            printf(" ID Regime: %d", alunos[i].id_regime);
            printf(" ID Course: %d", alunos[i].id_course);
            printf(" Email: %s\n", alunos[i].email);
            break;
        }
    }
}