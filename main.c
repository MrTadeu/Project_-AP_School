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
AlunoDataStruct aluno;
int n_alunos = 0, n_regimes = 0, n_courses = 0, n_disciplinas = 0, n_salas = 0, n_professores = 0;


void readData();


courseStruct *readBinCourses(){
    courseStruct *courses = malloc(sizeof(courseStruct));
    int i;
    FILE *file = fopen("data/bin/courses.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]course.bin[/red]\n\n");
        return NULL;
    }
    else{
        for (i = 0;; i++){
            courses = realloc(courses, (i+1)*sizeof(courseStruct));
            if(fread(&courses[i].id, sizeof(int), 1, file) != 1) break;

            size_t courseLen;
            fread(&courseLen, sizeof(size_t), 1, file);
            courses[i].name = malloc(courseLen);
            fread(courses[i].name, courseLen, 1, file);
        }
        n_courses = i-1;
        fclose(file);
        return courses;
    }
}




/* int firstTime(){
    FILE *fp = fopen("data/bin/firstTime.bin", "rb");
    if (fp == NULL){
        return 1;
    }
    fclose(fp);
    return 0;
} */
void main(){
/*     if (firstTime()){
        printc("[lw]Bem-vindo ao sistema de gestão de exames![/lw]\n");
        printc("[lw]Parece que é a primeira vez que está a usar o programa![/lw]\n");
        printc("[lw]Por favor, importe os dados do ficheiro de texto![/lw]\n");
        importExportData();
    }
    else{
        readData();
    } */

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
    /* ReadBinCursosDisciplina(); */
    readBinCourses();
    readBinSalas();
    readBinProfessores();
}

