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


void criarRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();
    regimes = realloc(regimes, (n_regimes + 1) * sizeof(regimeStruct));
    perms_file = realloc(perms_file, (n_regimes + 1) * sizeof(permissionFileStruct));
    regimes[n_regimes].id = n_regimes+1;
    regimes[n_regimes].name = malloc(100 * sizeof(char));
    printf("Introduza o nome do regime: ");
    scanf("%s", regimes[n_regimes].name);
    printf("Nome do regime: %s", regimes[n_regimes].name);
    regimes[n_regimes].name = realloc(regimes[n_regimes].name, (strlen(regimes[n_regimes].name) + 1));

    perms_file[n_regimes].id_regime = n_regimes+1;
    printf("\n\nTem permissao para Menu Exames? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuExames);
    printf("Tem permissao para Ver Disciplinas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.VerDisciplinas);
    printf("Tem permissao para Menu Professor? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuProfessor);
    printf("Tem permissao para Menu Admin? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuAdmin);
    printf("Tem permissao para Menu Salas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuSalas);
    printf("Tem permissao para Criar Exames? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.CriarExames);
    printf("Tem permissao para Inscritos Exames? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.InscritosExames);
    printf("Tem permissao para Listar Exames? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.ListarExames);
    printf("Tem permissao para Listar Exames Inscritos? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.ListarExamesInscritos);
    printf("Tem permissao para Editar Exames? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.EditarExames);
    printf("Tem permissao para Exportar Exames? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.ExportarExames);
    printf("Tem permissao para Inscrever Exames? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.InscreverExames);
    printf("Tem permissao para Criar Salas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.CriarSalas);
    printf("Tem permissao para Listar Salas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.ListarSalas);
    printf("Tem permissao para Editar Salas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.EditarSalas);
    printf("Tem permissao para Remover Salas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.RemoverSalas);
    printf("Tem permissao para Criar Professor? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.CriarProfessor);
    printf("Tem permissao para Listar Professor? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.ListarProfessor);
    printf("Tem permissao para Editar Professor? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.EditarProfessor);
    printf("Tem permissao para Remover Professor? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.RemoverProfessor);
    printf("Tem permissao para Menu Cursos? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuCursos);
    printf("Tem permissao para Menu Alunos? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuAlunos);
    printf("Tem permissao para Menu Regimes? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuRegimes);
    printf("Tem permissao para Criar Cursos? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.CriarCursos);
    printf("Tem permissao para Listar Cursos? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.ListarCursos);
    printf("Tem permissao para Editar Cursos? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.EditarCursos);
    printf("Tem permissao para Remover Cursos? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.RemoverCursos);
    printf("Tem permissao para Listar Cursos Disciplinas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.ListarCursosDisciplinas);
    printf("Tem permissao para MenuDisciplinas? (1 - Sim, 0 - Nao): ");
    scanf("%d", &perms_file[n_regimes].perm.MenuDisciplinas);

    n_regimes++;
    saveBinRegimes();
    saveBinPermissions();
}

void editarNomeRegime(){
    listarRegimes();
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfRegimeExists(id) == 0);
    
    printf("\n\nPor favor introduza o novo nome do regime: ");
    scanf("%s", regimes[id].name);
}

void editarPermissoesRegime(){

}

void removerRegime(){
    
}