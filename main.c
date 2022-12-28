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
professorStruct *professores;
int n_alunos = 0, n_regimes = 0, n_courses = 0, n_disciplinas = 0, n_salas = 0, n_professores = 0;


void readData();

void main(){
    readData();
    // TESTES
    //disciplinas
    ReadTxtDisciplinas();//Apenas necessario primeira vez(ja vamos ter o ficheiro que podemos binario)
    SaveBinDisciplinas();
    ReadBinDisciplinas();
    ListarDisciplinas();
    //cursosdisciplinas.c
    ListarCursos();
    InitCursos();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
    SaveBinCursosDisciplina();
    ReadBinCursosDisciplina();
    ListarCursosDisciplinas();
    CriarDisciplina();
    ListarCursosDisciplinas();
    RemoverDisciplina();
    ListarCursosDisciplinas();
    EditarDisciplina();
    ListarCursosDisciplinas();
    // /TESTES

    
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
                printAlunos();
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
    alunos = readBinAlunos();
    regimes = readBinRegimes();
    perms_file = readBinPermissions();
    courses = readBinCourses();  
    disciplinas = ReadTxtDisciplinas();
    salas = readBinSalas(); 
}

