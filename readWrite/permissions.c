#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h"

int numero_de_perms = 12;


void setRulesBinByTxt(roleStruct *roles, int n_roles){
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
        scanf("%d", &permFile.enable[0]);
        printf("Tem permissao para escrever alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[1]);
        printf("Tem permissao para listar alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[2]);
        printf("Tem permissao para deletar alunos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[3]);
        printf("Tem permissao para ler cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[4]);
        printf("Tem permissao para escrever cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[5]);
        printf("Tem permissao para listar cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[6]);
        printf("Tem permissao para deletar cursos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[7]);
        printf("Tem permissao para ler regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[8]);
        printf("Tem permissao para escrever regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[9]);
        printf("Tem permissao para listar regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[10]);
        printf("Tem permissao para deletar regimes? (1 - Sim, 0 - Nao): ");
        scanf("%d", &permFile.enable[11]);

        fwrite(&permFile, sizeof(permissionFileStruct),1,file);
    }

    fclose(file);
}

void readBinPermissions(){
    FILE *file = fopen("data/bin/permission.bin", "rb");
    permissionFileStruct permFile;
    if (file == NULL){
        printf("\nErro ao abrir o ficheiro permission.bin");
        exit(1);
    }

    while (fread(&permFile, sizeof(permissionFileStruct), 1, file)){
        printf("\n\nID CARGO: %d", permFile.id_cargo);
        for (int i = 0; i < 12; i++){
            printf("\nPERM ID: %d ENABLED: %d", i+1, permFile.enable[i]);
        }
    }

    fclose(file);
}



