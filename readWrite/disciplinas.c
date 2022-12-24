#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

disciplinasStruct* ReadTxtDisciplinas(int *n_disciplinas)
{
    disciplinasStruct* disciplinas = malloc(sizeof(disciplinasStruct));
    int i;
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
        fscanf(disciplinasTxt, "%s", disciplinas[i].name);
        *n_disciplinas = *n_disciplinas + 1;
    }
    fclose(disciplinasTxt);


    for(int j=0;j<n_disciplinas;j++)
    {
        printf("%d", disciplinas[j].id);
        printf("%s", disciplinas[j].name);
    }
    return disciplinas;
}

void SavetxtDisciplinas(disciplinasStruct *disciplinas, int n_disciplinas)
{
    FILE *disciplinasTxt = fopen("data/txt/disciplinas.txt","w");
    if (!disciplinasTxt) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]disciplinas.txt[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_disciplinas; i++)
    {
        if(feof(disciplinasTxt))
            break;
        fprintf(disciplinasTxt, "%d %s", disciplinas[i].id, disciplinas[i].name);
    }
}
void SaveBinDisciplinas(disciplinasStruct *disciplinas, int n_disciplinas)
{
    FILE *disciplinasBin = fopen("data/bin/disciplinas.bin","ab");
    if (!disciplinasBin) {
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

void ListarDisciplinas(disciplinasStruct *disciplinas, int n_disciplinas)
{
    printf("Disciplinas --> ");
    for(int i=0;i<n_disciplinas;i++)
    {
       printc("\n\t[green]%d[/green] - %s", disciplinas[i].id, disciplinas[i].name);
        if(i==5 || i==10 || i==15 || i==20 || i==25 || i==30)
            printf("\n");
    }
    printf("\n\n");
}

void MenuEditarAdicionarRemoverDisciplinas(disciplinasStruct *disciplinas, int *n_disciplinas)
{
    int opcao;
    do
    {
    printc("\n\n\t[green]1[/green] - Adicionar Disciplina");
    printc("\n\t[green]2[/green] - Remover Disciplina");
    printc("\n\t[green]3[/green] - Editar Disciplina");
    printc("\n\t[green]4[/green] - Voltar");
    printc("\n\n\tOpcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        criarDisciplina(disciplinas, n_disciplinas);
        break;
    case 2:
        RemoverDisciplina(disciplinas, n_disciplinas);
        break;
    case 3:
        EditarDisciplina(disciplinas, n_disciplinas);
        break;
    case 4:
        break;
    default:
        printc("\n\n\tOpcao Invalida");
        break;
    }
    } while (opcao != 4);
}

void criarDisciplina(disciplinasStruct *disciplinas, int *n_disciplinas)
{
    int id;
    char name[50];
    printc("\n\n\tID: ");
    scanf("%d", &id);
    printc("\n\tNome: ");
    scanf("%s", name);
    disciplinas[*n_disciplinas].id = id;
    strcpy(disciplinas[*n_disciplinas].name, name);
    *n_disciplinas = *n_disciplinas + 1;
    SavetxtDisciplinas(disciplinas, *n_disciplinas);
    SaveBinDisciplinas(disciplinas, *n_disciplinas);
}

void Removerdisciplina(disciplinasStruct *disciplinas, int *n_disciplinas)
{
    int id;
    void ListarDisciplinas(disciplinas, n_disciplinas);
    printc("\n\n\tInsira o ID da disciplina que quer apagar: ");
    scanf("%d", &id);
    for (int i = 0; i < *n_disciplinas; i++)
    {
        if (disciplinas[i].id == id)
        {
            for (int j = i; j < *n_disciplinas; j++)
            {
                disciplinas[j] = disciplinas[j + 1];
            }
            *n_disciplinas = *n_disciplinas - 1;
            break;
        }
    }
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (*n_disciplinas));   
    SavetxtDisciplinas(disciplinas, *n_disciplinas);
    SaveBinDisciplinas(disciplinas, *n_disciplinas);
}

void EditarDisciplina(disciplinasStruct *disciplinas, int *n_disciplinas)
{
    int id;
    void ListarDisciplinas(disciplinas, n_disciplinas);
    printc("\n\n\tInsira o ID da disciplina que quer editar: ");
    scanf("%d", &id);
    for (int i = 0; i < *n_disciplinas; i++)
    {
        if (disciplinas[i].id == id)
        {
            printc("\n\n\tNovo ID: ");
            scanf("%d", &disciplinas[i].id);
            printc("\n\tNovo Nome: ");
            scanf("%s", disciplinas[i].name);
            break;
        }
    }
    SavetxtDisciplinas(disciplinas, *n_disciplinas);
    SaveBinDisciplinas(disciplinas, *n_disciplinas);
}
    