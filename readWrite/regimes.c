#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

regimeStruct *getAllRegimes(AlunoFileStruct *alunosFile, int n_alunos, int *n_regimes){
    regimeStruct *regimes = malloc(sizeof(regimeStruct));
    for (int i = 0; i < n_alunos; i++){
        int found = 0;
        for (int j = 0; j < *n_regimes; j++){
            if (strcmp(alunosFile[i].regime, regimes[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            regimes = realloc(regimes, ((*n_regimes)+1)*sizeof(regimeStruct));
            regimes[*n_regimes].id = *n_regimes+1;
            regimes[*n_regimes].name = malloc((strlen(alunosFile[i].regime)+1));
            strcpy(regimes[*n_regimes].name, alunosFile[i].regime);
            *n_regimes=*n_regimes+1;
        }
    }
    return regimes;
}

void saveBinRegimes(regimeStruct *regimes, int n_regimes){
    FILE *file = fopen("data/bin/regimes.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0; i < n_regimes; i++){
        fwrite(&regimes[i].id, sizeof(int), 1, file);
        size_t regimeLen = strlen(regimes[i].name) + 1;
        fwrite(&regimeLen, sizeof(size_t), 1, file);
        fwrite(regimes[i].name, regimeLen, 1, file);
    }
    fclose(file);
}

regimeStruct *readBinRegimes(int *n_regimes){
    regimeStruct *regimes = malloc(sizeof(regimeStruct));
    int i;
    FILE *file = fopen("data/bin/regimes.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]regimes.bin[/red] \n\n");
        return NULL;
    }
    else{
        for (i = 0;; i++){
            regimes = realloc(regimes, (i+1)*sizeof(regimeStruct));
            if(fread(&regimes[i].id, sizeof(int), 1, file) != 1) break;

            size_t regimeLen;
            fread(&regimeLen, sizeof(size_t), 1, file);
            regimes[i].name = malloc(regimeLen);
            fread(regimes[i].name, regimeLen, 1, file);
        }
        *n_regimes = i-1;
        fclose(file);
        return regimes;
    }   
}


