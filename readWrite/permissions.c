#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

extern permissionFileStruct *perms_file;
extern regimeStruct *regimes;
extern int n_regimes;

void saveAndSetPermissionsBinByTxt(){
    FILE *file = fopen("data/bin/permission.bin", "ab");
    perms_file = malloc(sizeof(permissionFileStruct));
    if (file == NULL){
        printc("\n\n\tImpossivel abrir Ficheiro [red]permission.bin[/red]\n\n");
        exit(1);
    }
    
    for (int i = 0; i < n_regimes; i++){
        perms_file = realloc(perms_file, sizeof(permissionFileStruct) * (i + 1));
        perms_file[i].id_regime = regimes[i].id;
        printf("\n%dº Regime - %s\n", regimes[i].id, regimes[i].name);
        printf("Tem permissao para Menu Exames? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuExames);
        printf("Tem permissao para Ver Disciplinas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.VerDisciplinas);
        printf("Tem permissao para Menu Professor? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuProfessor);
        printf("Tem permissao para Menu Admin? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuAdmin);
        printf("Tem permissao para Menu Salas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuSalas);
        printf("Tem permissao para Criar Exames? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.CriarExames);
        printf("Tem permissao para Inscritos Exames? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.InscritosExames);
        printf("Tem permissao para Listar Exames? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.ListarExames);
        printf("Tem permissao para Listar Exames Inscritos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.ListarExamesInscritos);
        printf("Tem permissao para Editar Exames? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.EditarExames);
        printf("Tem permissao para Exportar Exames? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.ExportarExames);
        printf("Tem permissao para Inscrever Exames? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.InscreverExames);
        printf("Tem permissao para Criar Salas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.CriarSalas);
        printf("Tem permissao para Listar Salas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.ListarSalas);
        printf("Tem permissao para Editar Salas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.EditarSalas);
        printf("Tem permissao para Remover Salas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.RemoverSalas);
        printf("Tem permissao para Criar Professor? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.CriarProfessor);
        printf("Tem permissao para Listar Professor? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.ListarProfessor);
        printf("Tem permissao para Editar Professor? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.EditarProfessor);
        printf("Tem permissao para Remover Professor? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.RemoverProfessor);
        printf("Tem permissao para Menu Cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuCursos);
        printf("Tem permissao para Menu Alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuAlunos);
        printf("Tem permissao para Menu Regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuRegimes);
        printf("Tem permissao para Criar Cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.CriarCursos);
        printf("Tem permissao para Listar Cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.ListarCursos);
        printf("Tem permissao para Editar Cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.EditarCursos);
        printf("Tem permissao para Remover Cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.RemoverCursos);
        printf("Tem permissao para Listar Cursos Disciplinas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.ListarCursosDisciplinas);
        printf("Tem permissao para MenuDisciplinas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &perms_file[i].perm.MenuDisciplinas);
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