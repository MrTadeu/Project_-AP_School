#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

extern disciplinasStruct *disciplinas;
extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern SalaStruct *salas;
extern AlunoFileStruct *alunosFile; 
extern professorStruct *professores;
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
                exportDataBinTxt();
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
        remove("data/bin/alunos.bin");
        remove("data/bin/cursosdisciplinas.bin");
        remove("data/bin/disciplinas.bin");
        remove("data/bin/permission.bin");
        remove("data/bin/professores.bin");
        remove("data/bin/regimes.bin");
        remove("data/bin/salas.bin");

        //LIMPAR n_alunos, n_regimes, n_courses
        n_alunos = 0;
        n_regimes = 0;
        n_courses = 0;
        n_disciplinas = 0;
        n_salas = 0;
        n_professores = 0;
        n_exames = 0;


        //LER TXT ALUNOS
        alunosFile = getTxt();
        if(alunosFile == NULL){
            return;
        }

        //LER ARRAY alunosFile E BUSCAR TODOS OS REGIMES SEM REPETIÇÕES E GUARDAR EM regimes
        getAllRegimes(alunosFile);
        //GUARDAR REGIMES EM BINARIO
        saveBinRegimes();

        //LER ARRAY alunosFile E BUSCAR TODOS OS CURSOS SEM REPETIÇÕES E GUARDAR EM courses

        //LER ARRAY alunosFile, regimes, courses E GUARDAR NO FORMATO DE AlunoStruct
        getAllCourses(alunosFile);
        ConvertAluno(alunosFile);
        //GUARDAR ALUNOS (AlunoStruct) EM BINARIO
        saveBinAlunos();

        criardisciplinas();
        InitCursos();

        criarSala();
        
        //DEFINIR PERMISSÕES DE ACORDO COM OS REGIMES E GUARDAR EM BINARIO
        saveAndSetPermissionsBinByTxt();
    }
}

void exportDataBinTxt(){
    printc("\n[green]Exportar dados para ficheiro de texto[/green]\n\n");

    //EXPORTAR ALUNOS
    FILE *fp_aluno= fopen("ExportAlunos.txt", "w");
    if (fp_aluno == NULL) {
        printc("\n[red]Erro ao abrir ficheiro ExportAlunos.txt[/red]\n\n");
    }
    fprintf(fp_aluno, "NOME\tREGIME\tANO\tNÚMERO\tCURSO\n");
    for (int i = 0; i < n_alunos; i++){
        courseStruct courseAluno = getCourseByID(alunos[i].id_course);
        regimeStruct regimeAluno = getRegimeByID(alunos[i].id_regime); 
        fprintf(fp_aluno, "%s\t%s\t%d\t%d\t%s\n", alunos[i].name, regimeAluno.name, alunos[i].year, alunos[i].id, courseAluno.name);
    }
    fclose(fp_aluno);

    //EXPORTAR REGIMES
    FILE *fp_regimes= fopen("ExportRegimes.txt", "w");
    if (fp_regimes == NULL) {
        printc("\n[red]Erro ao abrir ficheiro ExportRegimes.txt[/red]\n\n");
    }
    fprintf(fp_regimes, "ID\tNOME\n");
    for (int i = 0; i < n_regimes; i++){
        fprintf(fp_regimes, "%d\t%s\n", regimes[i].id, regimes[i].name);
    }
    fclose(fp_regimes);

    //EXPORTAR CURSOS
    FILE *fp_cursos= fopen("ExportCursos.txt", "w");
    if (fp_cursos == NULL) {
        printc("\n[red]Erro ao abrir ficheiro ExportCursos.txt[/red]\n\n");
    }
    fprintf(fp_cursos, "ID\tNOME\tDIRETOR DE CURSO\tEMAIL\n");
    for (int i = 0; i < n_professores; i++){
        int findID;
        for(int j=0; j<n_professores; j++){
            if(courses[i].IdDiretor == professores[j].id){
                findID = j;
                break;
            }
        }
        fprintf(fp_cursos, "%d\t%s\t%s\t%s\t%d\n", courses[i].id, courses[i].name, professores[findID].nomeProfessor, professores[findID].emailProfessor);
    }
    fclose(fp_cursos);

    //EXPORTAR DISCIPLINAS
    FILE *fp_disciplinas= fopen("ExportDisciplinas.txt", "w");
    if (fp_disciplinas == NULL) {
        printc("\n[red]Erro ao abrir ficheiro ExportDisciplinas.txt[/red]\n\n");
    }
    fprintf(fp_disciplinas, "ID\tNOME\n");
    for (int i = 0; i < n_disciplinas; i++){
        fprintf(fp_disciplinas, "%d\t%s\n", disciplinas[i].id, disciplinas[i].name);
    }
    fclose(fp_disciplinas);


    //EXPORTAR CURSOS DISCIPLINAS
    FILE *fp_cursos_disciplinas= fopen("ExportCursosDisciplinas.txt", "w");
    if (fp_cursos_disciplinas == NULL) {
        printc("\n[red]Erro ao abrir ficheiro ExportCursosDisciplinas.txt[/red]\n\n");
    }
    for (int i = 0; i < n_courses; i++){
        fprintf(fp_cursos_disciplinas,"\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        for(int j=0; j<3; j++){
            fprintf(fp_cursos_disciplinas,"Disciplinas do %d ano : ", j+1);
            if(courses[i].num_disciplinas[j] == 0){
                fprintf(fp_cursos_disciplinas,"Inexistente!\t");
            }
            else{
                for(int k=0; k<courses[i].num_disciplinas[j]; k++){
                    if(courses[i].AnoDisciplina[j][k] != NULL)
                        fprintf(fp_cursos_disciplinas,"%s\t", courses[i].AnoDisciplina[j][k]);
                    else
                        fprintf(fp_cursos_disciplinas,"Inexistente!\t");
                    if(k%5 == 0)
                        fprintf(fp_cursos_disciplinas, "\n");
                }
            }
            fprintf(fp_cursos_disciplinas, "\n");
        }
        int findID;
        for(int j=0; j<n_professores; j++){
            if(courses[i].IdDiretor == professores[j].id){
                findID = j;
                break;
            }
        }
        fprintf(fp_cursos_disciplinas, "ID: %d Diretor:  %s \n", courses[i].IdDiretor, professores[findID].nomeProfessor);
        fprintf(fp_cursos_disciplinas, "------------------------------------------------------------\n");
    }
    fclose(fp_cursos_disciplinas);

    //EXPORTAR SALAS
    FILE *fp_salas= fopen("ExportSalas.txt", "w");
    if (fp_salas == NULL) {
        printc("\n[red]Erro ao abrir ficheiro ExportSalas.txt[/red]\n\n");
    }
    fprintf(fp_salas, "ID\tNOME SALA\tNUMERO SALA\tNUMERO CADEIRAS\n");
    for (int i = 0; i < n_salas; i++){
        fprintf(fp_salas, "%d\t%s\t%d\t%d\n", salas[i].id, salas[i].nomeSala, salas[i].numeroSala, salas[i].numeroCadeiras);
    }
    fclose(fp_salas);


    //EXPORTAR PROFESSORES
    FILE *fp_professores= fopen("ExportProfessores.txt", "w");
    if (fp_professores == NULL) {
        printc("\n[red]Erro ao abrir ficheiro ExportProfessores.txt[/red]\n\n");
    }
    fprintf(fp_professores, "ID\tNOME\tEMAIL\n");
    for (int i = 0; i < n_professores; i++){
        fprintf(fp_professores, "%d\t%s\t%s\n", professores[i].id, professores[i].nomeProfessor, professores[i].emailProfessor);
    }
    fclose(fp_professores);
}