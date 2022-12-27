#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern int n_disciplinas;


disciplinasStruct* ReadTxtDisciplinas()
{
    disciplinasStruct* disciplinas = malloc(sizeof(disciplinasStruct));
    int i, DiscNameLen;
    FILE *disciplinasTxt = fopen("disciplinas.txt", "r");
    if (disciplinasTxt == NULL)
    {
        printc("\n\n\tImpossivel abrir Ficheiro [red]Disciplinas.txt[/red]\n\n");
        exit(1);
    }
    for (i = 0 ;; i++)
    {   if (feof(disciplinasTxt))
            break;
        disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (i + 1));
        fscanf(disciplinasTxt, "%d", &disciplinas[i].id);
        fscanf(disciplinasTxt, "%d",DiscNameLen);
        disciplinas[i].name = malloc(DiscNameLen);
        fscanf(disciplinasTxt, "%s", disciplinas[i].name);
    }
    n_disciplinas = i - 1;
    fclose(disciplinasTxt);
    SaveBinDisciplinas();
    return disciplinas;
}

void ReadBinDisciplinas(){
    disciplinas = malloc(sizeof(disciplinasStruct));
    int i;
    FILE *disciplinasBin = fopen("data/bin/disciplinas.bin","rb");
    if (disciplinasBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]disciplinas.bin[/red]\n\n");
        exit(1);
    }
    else{
        for (i = 0;n_disciplinas; i++){
            if (feof(disciplinasBin))
                break;
            disciplinas = realloc(disciplinas, (i+1)*sizeof(disciplinasStruct));
            fread(&disciplinas[i].id, sizeof(int), 1, disciplinasBin);
            size_t disciplinasLen;
            fread(&disciplinasLen, sizeof(size_t), 1, disciplinasBin);
            disciplinas[i].name = malloc(disciplinasLen);
            fread(disciplinas[i].name, disciplinasLen, 1, disciplinasBin);
            
        }
        n_disciplinas = i-1;
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
        fwrite(disciplinas[i].name, disciplinasLen, 1, disciplinasBin);
    }
    fclose(disciplinasBin);
}