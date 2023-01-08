#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <sys/stat.h>
#include <windows.h>

#include "All_functions\global.h"


//GLOBAL VARIABLES
AlunoStruct *alunos;
regimeStruct *regimes;
courseStruct *courses;
permissionFileStruct *perms_file;
disciplinasStruct *disciplinas;
SalaStruct *salas;
professorStruct *professores;
AlunoDataStruct aluno;

int n_alunos = 0, n_regimes = 0, n_courses = 0, n_disciplinas = 0, n_salas = 0, n_professores = 0;


void readData();


void main(){
    if (folderExists("data/bin")) { //Pasta bin existe!

        if (fileExistAll() == 0){ // --------------------->SE PARAR DE EXECUTAR A MEIO LIMPAR TERMINAL <-----------------------
            
            printc("[red]Error[/red] Ficheiros não existem.\n\n");
            int i, mul = 10;
            for(i = 0; i < 100; i++) {
                Sleep(10);
                spinner_update("[white]A entrar em modo Setup[/white] [bw][red]%d[/red][/bw]...", i);
            }
            spinner_done("Done!\n");
            printc("[lg][bg][+][/bg][/lg] Task was successful!\n");
            printf("Enter para continuar...\n");
            MenuFilesNovos();
        }
    }else { //Pasta bin existe!
        mkdir("data/bin"); //Não funciona no linux (algumas dunções do folderExists())
        printc("[red]Error[/red] Pastas não existem.\n\n");
        printc("[red]Error[/red] Ficheiros não existem.\n\n");
        int i, mul = 10;
        for(i = 0; i < 100; i++) { // --------------------->SE PARAR DE EXECUTAR A MEIO LIMPAR TERMINAL <-----------------------
            Sleep(10);
            spinner_update("[white]A entrar em modo Setup[/white] [bw][red]%d[/red][/bw]...", i);
        }
        spinner_done("Done!\n");
        printc("[lg][bg][+][/bg][/lg] Task was successful!\n");
        printf("Enter para continuar...\n");
        MenuFilesNovos();
    }
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
                char *username = malloc(120), *password = malloc(50);
                printc("[lw]Bem-vindo ao sistema de gestão de exames![/lw]\n");
                printc("[lw]Por favor, faça o login para continuar![/lw]\n");
                printc("[lw]Email:[/lw] ");
                scanf("%s", username);
                printc("[lw]Password:[/lw] ");
                scanf("%s", password);
                login(username, password);
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
    ReadBinDisciplinas();   
    ReadBinCursosDisciplina(); 
    readBinSalas();
    readBinProfessores();
    printf("olaaaaaaaaaaaaaaaaa");
    /* CriarDisciplina(); */
    RemoverDisciplina();
    EditarDisciplina();
    CriarCurso();
}

