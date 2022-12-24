/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"
//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern int n_disciplinas;

disciplinasStruct* ReadTxtDisciplinas()
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
        n_disciplinas = n_disciplinas + 1;
    }
    fclose(disciplinasTxt);
    return disciplinas;
}

void SavetxtDisciplinas()
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
void SaveBinDisciplinas()
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

void ListarDisciplinas()
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

void MenuEditarAdicionarRemoverDisciplinas()
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
        CriarDisciplina();
        break;
    case 2:
        RemoverDisciplina();
        break;
    case 3:
        EditarDisciplina();
        break;
    case 4:
        break;
    default:
        printc("\n\n\tOpcao Invalida");
        break;
    }
    } while (opcao != 4);
}

void criarDisciplina()
{   
    int id;
    char name[50];
    printc("\n\n\tInsira os dados da disciplina: ");
    printc("\n\n\tID: ");
    scanf("%d", &id);
    printc("\n\tNome: ");
    scanf("%s", name);
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (n_disciplinas + 1));
    disciplinas[n_disciplinas].id = id;
    strcpy(disciplinas[n_disciplinas].name, name);
    n_disciplinas++;
    SavetxtDisciplinas();
    SaveBinDisciplinas();
}

void Removerdisciplina()
{
    int id;
    void ListarDisciplinas();
    printc("\n\n\t[green]Insira o ID da disciplina que quer apagar: [/green]");
    scanf("%d", &id);
    for (int i = 0; i < n_disciplinas; i++)
    {
        if (disciplinas[i].id == id)
        {
            for (int j = i; j < n_disciplinas; j++)
            {
                disciplinas[j] = disciplinas[j+1];
            }
            n_disciplinas--;
            break;
        }
    }
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (n_disciplinas));   
    SavetxtDisciplinas();
    SaveBinDisciplinas();
}

void EditarNomeDisciplina()
{
    int id;
    void ListarDisciplinas();
    printc("\n\n\t[green]Insira o ID da disciplina que quer editar:[/green] ");
    scanf("%d", &id);
    for (int i = 0; i < n_disciplinas; i++)
    {
        if (disciplinas[i].id == id)
        {
            printc("\n\tNovo Nome: ");
            scanf("%s", disciplinas[i].name);
            break;
        }
    }
    SavetxtDisciplinas();
    SaveBinDisciplinas();
}
     */