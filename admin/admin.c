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
        courseStruct courseAluno = getCourseByID(alunos[i].id_course);
        regimeStruct regimeAluno = getRegimeByID(alunos[i].id_regime);        
        printf("ID: %d", alunos[i].id);
        printf("Nome: %s", alunos[i].name);
        printf("Ano: %d", alunos[i].year);
        printf("ID Regime: %d", alunos[i].id_regime);
        printf("Nome Regime: %s", regimeAluno.name);
        printf("ID Course: %d", alunos[i].id_course);
        printf("Nome Curso: %s", courseAluno.name);
        printf("Email: %s\n", alunos[i].email);
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
            courseStruct courseAluno = getCourseByID(alunos[i].id_course);
            regimeStruct regimeAluno = getRegimeByID(alunos[i].id_regime);           
            printf("\nID: %d", alunos[i].id);
            printf("\nNome: %s", alunos[i].name);
            printf("\nEmail: %s", alunos[i].email);
            printf("\nAno: %d", alunos[i].year);
            printf("\nID Regime: %d", alunos[i].id_regime);
            printf("\nNome Regime: %s", regimeAluno.name);
            printf("\nID Curso: %d", alunos[i].id_course);
            printf("\nNome Curso: %s", courseAluno.name);
            break;
        }
    }
    printc("\n\n[lw]Pressione enter para continuar[/lw]\n");  
    getchar();
    getchar();
}

void alterarAluno(){
    listarTodosAlunos();
    int flag = 0, id;
    do{
        if(flag == 1)
            printf("\n[red]Por favor insira um ID válido![/red]\n");

        printf("Por favor Introduza o ID do aluno que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfUserExists(id) == 0);



    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        opcao = menuEditAluno();

        switch (opcao){
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
        
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);



}