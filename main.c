#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "All_functions\global.h"


//GLOBAL VARIABLES
AlunoStruct *alunos;
regimeStruct *regimes;
courseStruct *courses;
permissionFileStruct *perms_file;
disciplinasStruct *disciplinas;
SalaStruct *salas;
int n_alunos = 0, n_regimes = 0, n_courses = 0, n_disciplinas = 0, n_salas = 0;


void readData();

void main(){
    readData();
    int op = -1;
    setlocale(LC_ALL, "Portuguese");
    do{
        op = mainMenu();
        switch (op){
            case 0:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printc("[lw]A fechar o programa...[/lw]");
                break;
            case 1:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                /* login(); */
                printAlunos(alunos, n_alunos);
                break;
            case 2:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                importExportData();
                break;
            default:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printc("\n[red]Opção inválida![/red]\n\n");
        }
    } while (op != 0);
}

void readData(){
    alunos = readBinAlunos(&n_alunos);
    regimes = readBinRegimes(&n_regimes);
    perms_file = readBinPermissions();
    courses = readBinCourses(&n_courses);  
    //disciplinas = readBinDisciplinas(&n_disciplinas);
    salas = readBinSalas(&n_salas);
}