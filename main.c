#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "All_functions\global.h"


//GLOBAL VARIABLES
AlunoStruct *alunos;
regimeStruct *regimes;
courseStruct *courses;
int n_linhas_lidas = 0, n_regimes = 0, n_courses = 0, n_perms = 0;

void main(){
    int op = -1;
    setlocale(LC_ALL, "Portuguese");
    do{
        op = mainMenu();
        switch (op){
            case 0:
                break;
            case 1:
                /* login(); */
                break;
            case 2:
                importExportData();
                break;
            default: 
                printc("\n[red]Opção inválida![/red]\n\n");
        }
    } while (op != 0);
    printc("[lw]A fechar o programa...[/lw]");
}