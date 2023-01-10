#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern AlunoFileStruct *alunosFile; 
extern int n_alunos, n_regimes, n_courses, n_disciplinas, n_salas, n_professores, n_exames;


void importExportData(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int op = -1;
    do{
        op = importExportMenu();
        switch (op){
            case 0:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                break;
            case 1:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                importDataTxtBin();
                break;
            case 2:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                /* exportDataBinTxt(); */
                break;
            case 3:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                /* exportDataBinCsv(); */
                break;
            default: 
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printc("\n[red]Opção inválida![/red]\n\n");
        }
    } while (op != 0);
}

void importDataTxtBin(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    AlunoFileStruct *alunosFile;
    int op = -1;
    printc("********************************************* [blue]Aviso![/blue] **********************************************\n");
    printf("****         Tem a certeza que pretende importar todos os dados do ficheiro \"alunos.txt\".      ****\n");
    printc("****         Todos os dados anteriores guardados iram ser [red]apagados[/red].                            ****\n");
    printf("****                                                                                           ****\n");
    printc("****               [red]1 - SIM[/red]                                           [green]0 - NÃO[/green]                   ****\n");
    printf("***************************************************************************************************\n");
    scanf("%d", &op);
    //#VALIDACAO SE É UM OU ZERO
    if(op == 1){
        //LIMPAR BINARIOS
        remove("data/bin/regimes.bin");
        remove("data/bin/courses.bin");
        remove("data/bin/alunos.bin");
        remove("data/bin/permission.bin");
        remove("data/bin/disciplinas.bin");
        remove("data/bin/cursosdisciplinas.bin");

        //LIMPAR n_alunos, n_regimes, n_courses
        n_alunos = 0;
        n_regimes = 0;
        n_courses = 0;
        n_disciplinas = 0;
        n_salas = 0;
        n_professores = 0;
        n_exames = 0;


        //LER TXT ALUNOS
        alunosFile = getTxt(&n_alunos);
        if(alunosFile == NULL){
            return;
        }

        //LER ARRAY alunosFile E BUSCAR TODOS OS REGIMES SEM REPETIÇÕES E GUARDAR EM regimes
        regimes = getAllRegimes(alunosFile);
        //GUARDAR REGIMES EM BINARIO
        saveBinRegimes();

        //LER ARRAY alunosFile E BUSCAR TODOS OS CURSOS SEM REPETIÇÕES E GUARDAR EM courses

        //LER ARRAY alunosFile, regimes, courses E GUARDAR NO FORMATO DE AlunoStruct
        getAllCourses(alunosFile);
        alunos = ConvertAluno(alunosFile, n_alunos, regimes, n_regimes, courses, n_courses);
        //GUARDAR ALUNOS (AlunoStruct) EM BINARIO
        saveBinAlunosFix();

        criardisciplinas();
        InitCursos();

        InitSalas();
        InitExame();

        //DEFINIR PERMISSÕES DE ACORDO COM OS REGIMES E GUARDAR EM BINARIO
        saveAndSetPermissionsBinByTxt(regimes, n_regimes);
    }
}