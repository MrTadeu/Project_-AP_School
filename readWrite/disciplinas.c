#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern int n_disciplinas;

void InitDisciplinas()
{
    char* TmpNameDisciplina = malloc(15); 
    disciplinas = malloc(sizeof(disciplinasStruct));
    int parar;
    for(int i=0; ;i++)
    {
        printf("\nPara parar escreva 0 para cntinuar escreva 1");
        scanf("%d", &parar);
        if(parar == 0)
            break;
        disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (i + 1));    
        printf("\nEscreve o nome da disciplina");
        scanf("%d", TmpNameDisciplina);
        TmpNameDisciplina = realloc(TmpNameDisciplina, strlen(TmpNameDisciplina)+1);
        disciplinas[i].name = malloc(strlen(TmpNameDisciplina)+1);
        strcpy(disciplinas[i].name, TmpNameDisciplina); 
        disciplinas[i].id = i+1;
    }
    SaveBinDisciplinas();
}

void ReadBinDisciplinas(){
    disciplinas = malloc(sizeof(disciplinasStruct));
    int i;
    FILE *disciplinasBin = fopen("data/bin/disciplinas.bin","rb");
    if (disciplinasBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]disciplinas.bin[/red]\n\n");
    }
    else{
        for (i = 0;; i++){
            disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (i + 1));
            if(fread(&disciplinas[i].id, sizeof(int), 1, disciplinasBin) != 1) 
                break;
            size_t disciplinasLen;
            fread(&disciplinasLen, sizeof(size_t), 1, disciplinasBin);
            disciplinas[i].name = malloc(disciplinasLen);
            fread(disciplinas[i].name, disciplinasLen, 1, disciplinasBin);
        }
        n_disciplinas = i;

        fclose(disciplinasBin);
    }
}

void SaveBinDisciplinas(){
    FILE *disciplinasBin = fopen("data/bin/disciplinas.bin","wb");
    if (disciplinasBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]disciplinas.bin[/red]\n\n");
        exit(1);
    }

    for (int i = 0; i < n_disciplinas; i++){
        fwrite(&disciplinas[i].id, sizeof(int), 1, disciplinasBin);
        size_t disciplinasLen = strlen(disciplinas[i].name) + 1;
        fwrite(&disciplinasLen, sizeof(size_t), 1, disciplinasBin);
        uppercase(disciplinas[i].name);
        fwrite(disciplinas[i].name, disciplinasLen, 1, disciplinasBin);
    }
    fclose(disciplinasBin);
}