#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

extern permissionFileStruct *perms_file;
extern regimeStruct *regimes;
extern int n_regimes;

void saveAndSetPermissionsBinByTxt(){
    FILE *file = fopen("data/bin/permission.bin", "ab");
    perms_file = malloc(sizeof(permissionFileStruct)*3);
    if (file == NULL){
        printc("\n\n\tImpossivel abrir Ficheiro [red]permission.bin[/red]\n\n");
        exit(1);
    }

    //ADMIN PERMISSIONS
    perms_file[0].id_regime = regimes[0].id;
     /* EXAMES */
    perms_file[0].perm.CriarExames = 1;
    perms_file[0].perm.InscritosExames = 1;
    perms_file[0].perm.ListarExames = 1;
    perms_file[0].perm.ListarExamesInscritos = 1;
    perms_file[0].perm.EditarExames = 1;
    perms_file[0].perm.ExportarExames = 1;
    perms_file[0].perm.InscreverExames = 1;
     /* SALAS */
    perms_file[0].perm.CriarSalas = 1;
    perms_file[0].perm.ListarSalas = 1;
    perms_file[0].perm.EditarSalas = 1;
    perms_file[0].perm.RemoverSalas = 1;
     /* PROFESSOR */
    perms_file[0].perm.CriarProfessor = 1;
    perms_file[0].perm.ListarProfessor = 1;
    perms_file[0].perm.EditarProfessor = 1;
    perms_file[0].perm.RemoverProfessor = 1;
     /* CURSOS */
    perms_file[0].perm.CriarCursos = 1;
    perms_file[0].perm.ListarCursos = 1;
    perms_file[0].perm.EditarCursos = 1;
    perms_file[0].perm.RemoverCursos = 1;
     /* DISCIPLINAS */
    perms_file[0].perm.ListarCursosDisciplinas = 1;
    perms_file[0].perm.CriarDisciplinas = 1;
    perms_file[0].perm.ListarDisciplinas = 1;
    perms_file[0].perm.EditarDisciplinas = 1;
    perms_file[0].perm.RemoverDisciplinas = 1;
    perms_file[0].perm.VerDisciplinas = 1;
     /* ALUNOS */
    perms_file[0].perm.CriarAluno = 1;
    perms_file[0].perm.ListarAluno = 1;
    perms_file[0].perm.ListarTodosAlunos = 1;
    perms_file[0].perm.EditarAluno = 1;
    perms_file[0].perm.RemoverAluno = 1;
     /* Regimes */
    perms_file[0].perm.CriarRegimes = 1;
    perms_file[0].perm.ListarRegimes = 1;
    perms_file[0].perm.ListarRegimesPermissoes = 1;
    perms_file[0].perm.EditarNomeRegimes = 1;
    perms_file[0].perm.EditarPermissoesRegimes = 1;
    perms_file[0].perm.MoverRegimes = 1;
    perms_file[0].perm.RemoverRegimes = 1;
    fwrite(&perms_file[0], sizeof(permissionFileStruct),1,file);

    //PROFESSOR PERMISSIONS
    perms_file[1].id_regime = regimes[1].id;
     /* EXAMES */
    perms_file[1].perm.CriarExames = 1;
    perms_file[1].perm.InscritosExames = 1;
    perms_file[1].perm.ListarExames = 1;
    perms_file[1].perm.ListarExamesInscritos = 1;
    perms_file[1].perm.EditarExames = 1;
    perms_file[1].perm.ExportarExames = 1;
    perms_file[1].perm.InscreverExames = 1;
     /* SALAS */
    perms_file[1].perm.CriarSalas = 1;
    perms_file[1].perm.ListarSalas = 1;
    perms_file[1].perm.EditarSalas = 1;
    perms_file[1].perm.RemoverSalas = 1;
     /* PROFESSOR */
    perms_file[1].perm.CriarProfessor = 1;
    perms_file[1].perm.ListarProfessor = 1;
    perms_file[1].perm.EditarProfessor = 1;
    perms_file[1].perm.RemoverProfessor = 1;
     /* CURSOS */
    perms_file[1].perm.CriarCursos = 1;
    perms_file[1].perm.ListarCursos = 1;
    perms_file[1].perm.EditarCursos = 1;
    perms_file[1].perm.RemoverCursos = 1;
     /* DISCIPL1NAS */
    perms_file[1].perm.ListarCursosDisciplinas = 1;
    perms_file[1].perm.CriarDisciplinas = 1;
    perms_file[1].perm.ListarDisciplinas = 1;
    perms_file[1].perm.EditarDisciplinas = 1;
    perms_file[1].perm.RemoverDisciplinas = 1;
    perms_file[1].perm.VerDisciplinas = 1;
     /* ALUNOS */
    perms_file[1].perm.CriarAluno = 1;
    perms_file[1].perm.ListarAluno = 1;
    perms_file[1].perm.ListarTodosAlunos = 1;
    perms_file[1].perm.EditarAluno = 1;
    perms_file[1].perm.RemoverAluno = 1;
     /* Regimes*/
    perms_file[1].perm.CriarRegimes = 1;
    perms_file[1].perm.ListarRegimes = 1;
    perms_file[1].perm.ListarRegimesPermissoes = 1;
    perms_file[1].perm.EditarNomeRegimes = 1;
    perms_file[1].perm.EditarPermissoesRegimes = 1;
    perms_file[1].perm.MoverRegimes = 1;
    perms_file[1].perm.RemoverRegimes = 1;
    fwrite(&perms_file[1], sizeof(permissionFileStruct),1,file);

    printf("\n1º Regime - %s\n", regimes[0].name);
    printc("Permissoes predefinidas.\n");

    printf("\n2º Regime - %s\n", regimes[1].name);
    printf("Permissoes predefinidas.\n");

    for (int i = 2; i < n_regimes; i++){
        perms_file = realloc(perms_file, sizeof(permissionFileStruct) * (i + 1));
        perms_file[i].id_regime = regimes[i].id;
        printc("[green]\n%dº Regime - %s\n[/green]", regimes[i].id, regimes[i].name);

        printc("[blue]Permissoes Exames:[/blue]\n");
        printf("Tem permissao para Criar Exames? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.CriarExames = ValidarZeroUm();
        printf("Tem permissao para Ver Inscritos Exames? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.InscritosExames = ValidarZeroUm();
        printf("Tem permissao para Listar Todos Exames? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarExames = ValidarZeroUm();
        printf("Tem permissao para Listar Exames de um aluno? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarExamesInscritos = ValidarZeroUm();
        printf("Tem permissao para Editar Exames? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarExames = ValidarZeroUm();
        printf("Tem permissao para Exportar Exames? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ExportarExames = ValidarZeroUm();
        printf("Tem permissao para Inscrever Exames? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.InscreverExames = ValidarZeroUm();

        printc("\n[blue]Permissoes Salas:[/blue]\n");
        printf("Tem permissao para Criar Salas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.CriarSalas = ValidarZeroUm();
        printf("Tem permissao para Listar Salas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarSalas = ValidarZeroUm();
        printf("Tem permissao para Editar Salas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarSalas = ValidarZeroUm();
        printf("Tem permissao para Remover Salas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.RemoverSalas = ValidarZeroUm();

        printc("\n[blue]Permissoes Professor:[/blue]\n");
        printf("Tem permissao para Criar Professor? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.CriarProfessor = ValidarZeroUm();
        printf("Tem permissao para Listar Professor? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarProfessor = ValidarZeroUm();
        printf("Tem permissao para Editar Professor? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarProfessor = ValidarZeroUm();
        printf("Tem permissao para Remover Professor? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.RemoverProfessor = ValidarZeroUm();

        printc("\n[blue]Permissoes Cursos:[/blue]\n");
        printf("Tem permissao para Criar Cursos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.CriarCursos = ValidarZeroUm();
        printf("Tem permissao para Listar Cursos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarCursos = ValidarZeroUm();
        printf("Tem permissao para Editar Cursos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarCursos = ValidarZeroUm();
        printf("Tem permissao para Remover Cursos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.RemoverCursos = ValidarZeroUm();
        printf("Tem permissao para Listar Cursos e Disciplinas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarCursosDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
        printf("Tem permissao para Criar Disciplinas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.CriarDisciplinas = ValidarZeroUm();
        printf("Tem permissao para Listar Disciplinas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarDisciplinas = ValidarZeroUm();
        printf("Tem permissao para Editar Disciplinas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarDisciplinas = ValidarZeroUm();
        printf("Tem permissao para Remover Disciplinas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.RemoverDisciplinas = ValidarZeroUm();
        printf("Tem permissao para Listar Disciplinas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarDisciplinas = ValidarZeroUm();
        printf("Tem permissao para Ver Proprias Disciplinas Disciplinas? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.VerDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Alunos:[/blue]\n");
        printf("Tem permissao para Criar Alunos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.CriarAluno = ValidarZeroUm();
        printf("Tem permissao para Listar Aluno? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarAluno = ValidarZeroUm();
        printf("Tem permissao para Listar Todos os Alunos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarTodosAlunos = ValidarZeroUm();
        printf("Tem permissao para Editar Alunos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarAluno = ValidarZeroUm();
        printf("Tem permissao para Remover Alunos? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.RemoverAluno = ValidarZeroUm();

        printc("\n[blue]Permissoes Regimes:[/blue]\n");
        printf("Tem permissao para Criar Regimes? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.CriarRegimes = ValidarZeroUm();
        printf("Tem permissao para Listar Regimes? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarRegimes = ValidarZeroUm();
        printf("Tem permissao para Listar Regimes e Permissões? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.ListarRegimesPermissoes = ValidarZeroUm();
        printf("Tem permissao para Editar Nome dos Regimes (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarNomeRegimes = ValidarZeroUm();
        printf("Tem permissao para Editar permissões dos Regimes (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.EditarPermissoesRegimes = ValidarZeroUm();
        printf("Tem permissao para Mover Regimes Regimes (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.MoverRegimes = ValidarZeroUm();
        printf("Tem permissao para Remover Regimes? (1 - Sim, 0 - Nao): ");
        perms_file[i].perm.RemoverRegimes = ValidarZeroUm();
        fwrite(&perms_file[i], sizeof(permissionFileStruct),1,file);
    }
    fclose(file);
}

void saveBinPermissions(){
    FILE *file = fopen("data/bin/permission.bin", "wb");
    if (file == NULL){
        printc("\n\n\tImpossivel abrir Ficheiro [red]permission.bin[/red]\n\n");
    }
    else{
        for (int i = 0; i < n_regimes; i++){
            fwrite(&perms_file[i], sizeof(permissionFileStruct), 1, file);
        }
    }
    fclose(file);
}

void readBinPermissions(){
    FILE *file = fopen("data/bin/permission.bin", "rb");
    perms_file = malloc(sizeof(permissionFileStruct));
    if (file == NULL){
        printc("\n\n\tImpossivel abrir Ficheiro [red]permission.bin[/red]\n\n");
    }
    else{
        int i = 0;
        while (fread(&perms_file[i], sizeof(permissionFileStruct), 1, file)){
            i++;
            perms_file = realloc(perms_file, sizeof(permissionFileStruct)*((i)+1));
        }
        fclose(file);
    }
}

PermissionsType getPermissionsByID(int id){
    int i = 0;
    while (perms_file[i].id_regime != id){
        i++;
    }
    return perms_file[i].perm;
}