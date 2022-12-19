#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h"

int numero_de_perms = 12;


void setRulesBinByTxt(regimeStruct *roles, int n_roles){
    FILE *file = fopen("data/bin/permission.bin", "ab");
    permissionFileStruct permFile;
    if (file == NULL){
        printf("\nErro ao abrir o ficheiro permission.bin");
        exit(1);
    }

    for (int i = 0; i < n_roles; i++){
        permFile.id_cargo = roles[i].id;
        printf("\n%dº Cargo - %s\n", roles[i].id, roles[i].name);
        printf("Tem permissao para ler alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.lerAluno);
        printf("Tem permissao para escrever alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.escreverAluno);
        printf("Tem permissao para listar alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.listarAluno);
        printf("Tem permissao para deletar alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.deletarAluno);
        printf("Tem permissao para ler cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.lerCurso);
        printf("Tem permissao para escrever cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.escreverCurso);
        printf("Tem permissao para listar cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.listarCurso);
        printf("Tem permissao para deletar cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.deletarCurso);
        printf("Tem permissao para ler regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.lerRole);
        printf("Tem permissao para escrever regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.escreverRole);
        printf("Tem permissao para listar regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.listarRole);
        printf("Tem permissao para deletar regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.perm.deletarRole);

        fwrite(&permFile, sizeof(permissionFileStruct),1,file);
    }

    fclose(file);
}

permissionFileStruct *readBinPermissions(int *n_perms){
    FILE *file = fopen("data/bin/permission.bin", "rb");
    permissionFileStruct *permFile = (permissionFileStruct *) malloc(sizeof(permissionFileStruct));
    if (file == NULL){
        printf("\nErro ao abrir o ficheiro permission.bin");
        exit(1);
    }

    while (fread(&permFile, sizeof(permissionFileStruct), 1, file)){
        n_perms++;
        permFile = realloc(permFile, sizeof(permissionFileStruct)*(*n_perms)+1);
    }
  
    fclose(file);
    return permFile;
}