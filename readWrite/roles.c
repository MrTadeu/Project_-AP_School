#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h"

regimeStruct *getAllRoles(AlunoFileStruct *alunosFile, int n_linhas_lidas, int *n_roles){
    regimeStruct *roles = malloc(sizeof(regimeStruct));
    for (int i = 0; i < n_linhas_lidas; i++){
        int found = 0;
        for (int j = 0; j < *n_roles; j++){
            if (strcmp(alunosFile[i].role, roles[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            roles = realloc(roles, ((*n_roles)+1)*sizeof(regimeStruct));
            roles[*n_roles].id = *n_roles+1;
            roles[*n_roles].name = malloc((strlen(alunosFile[i].role)+1));
            strcpy(roles[*n_roles].name, alunosFile[i].role);
            *n_roles=*n_roles+1;
        }
    }
    return roles;
}

void saveBinRoles(regimeStruct *roles, int n_roles){
    FILE *file = fopen("data/bin/roles.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0; i < n_roles; i++){
        fwrite(&roles[i].id, sizeof(int), 1, file);
        size_t roleLen = strlen(roles[i].name) + 1;
        fwrite(&roleLen, sizeof(size_t), 1, file);
        fwrite(roles[i].name, roleLen, 1, file);
    }
    fclose(file);
}

regimeStruct *readBinRoles(){
    regimeStruct *roles = malloc(sizeof(regimeStruct));
    FILE *file = fopen("data/bin/roles.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0;; i++){
        roles = realloc(roles, (i+1)*sizeof(regimeStruct));
        if(fread(&roles[i].id, sizeof(int), 1, file) != 1) break;

        size_t roleLen;
        fread(&roleLen, sizeof(size_t), 1, file);
        roles[i].name = malloc(roleLen);
        fread(roles[i].name, roleLen, 1, file);
    }
    fclose(file);
    return roles;
}


