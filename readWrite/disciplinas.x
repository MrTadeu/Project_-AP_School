/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern int n_disciplinas, n_courses;

/* void MenuAdminDisciplinas()
{
    int opcao;
    printc("\n\n\t  [green]Menu Disciplinas[/green]");
    printc("\n\n\t[green]1[/green] - Listar Disciplinas");
    printc("\n\t[green]2[/green] - Editar/Adicionar/Remover Disciplinas");
    printc("\n\t[green]3[/green] - Voltar");
    printc("\n\n\tOpcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        ListarDisciplinas();
        break;
    case 2:
        MenuAdminEditarAdicionarRemoverDisciplinas();
        break;
    case 3:
        // <--- This is the problem (por funcao do menu anterior)
        break;
    default:
        printc("\n\n\tOpcao Invalida");
        break;
    }
} */

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
        fprintf(&disciplinas[i].id, sizeof(int), 1, disciplinasTxt);
        size_t disciplinasLen = strlen(disciplinas[i].name) + 1;
        fprintf(&disciplinasLen, sizeof(size_t), 1, disciplinasTxt);
        fprintf(disciplinas[i].name, disciplinasLen, 1, disciplinasTxt);
    }
}
void SaveBinDisciplinas()
{
    FILE *disciplinasBin = fopen("data/bin/disciplinas.bin","wb");
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

/* void MenuAdminEditarAdicionarRemoverDisciplinas()
{
    int opcao;
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
        MenuDisciplinas();
        break;
    default:
        printc("\n\n\tOpcao Invalida");
        break;
    }
} */

void criarDisciplina()
{   
    int id;
    char name[50];
    printc("\n\n\tInsira os dados da disciplina: ");
    printc("\n\n\tID: ");
    scanf("%d", &id);
    printc("\n\tNome: ");
    scanf("%s", name);
    n_disciplinas++;
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * n_disciplinas);
    disciplinas[n_disciplinas-1].id = id;
    strcpy(disciplinas[n_disciplinas-1].name, name);
    
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
//________CURSOS_____CURSOS______CURSOS______CURSOS______CURSOS_______CURSOS_______CURSOS_________

void InitCursos() {
    for(int i=0; i<n_courses; i++)
    {   ListarDisciplinas(disciplinas, n_disciplinas);
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        for(int j=0; j<3; j++)
        {
            printf("Insira as siglas das 10 disciplinas do %d ano : ", j+1);
            for(int k=0; k<10; k++)
            {
                scanf("%s", courses[i].AnoDisciplina[j][k]);
            }
        }
        printf("\n\n");
        printf("Insira o ID do diretor deste curso: ");
        printf("\nID: ");
        scanf("%s", courses[i].IdResponsavel);
    }
    SaveTxtCursosDisciplina();
    SaveBinCursosDisciplina();
}
void SaveTxtCursosDisciplina()
{
    FILE *CursoDisciplinaTxt = fopen("data/txt/cursos.txt","w");
    if (CursoDisciplinaTxt == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]cursos.txt[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_courses; i++)
    {
        if(feof(CursoDisciplinaTxt))
            break;
        fprintf(CursoDisciplinaTxt, "%d", courses[i].id);
        size_t CursoNameLen = strlen(courses[i].name) + 1;
        fprintf(CursoDisciplinaTxt, "%d", CursoNameLen);
        fprintf(CursoDisciplinaTxt, "%s", courses[i].name);
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<10; k++)
            {   fprintf(CursoDisciplinaTxt, "%d", j);   //ano
                size_t DisciplinaNameLen = strlen(courses[i].AnoDisciplina[j][k]) + 1;
                fprintf(CursoDisciplinaTxt, "%d", DisciplinaNameLen);
                fprintf(CursoDisciplinaTxt, "%s", courses[i].AnoDisciplina[j][k]);
            }
        }
    }
}

void SaveBinCursosDisciplina()
{
    FILE *CursoDisciplinaBin = fopen("data/txt/cursos.txt","wb");
    if (CursoDisciplinaBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]cursos.txt[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_courses; i++)
    {
        if(feof(CursoDisciplinaBin))
            break;
        fwrite(courses[i].id, sizeof(int), 1, CursoDisciplinaBin);
        size_t CursoNameLen = strlen(courses[i].name) + 1;
        fwrite(CursoNameLen, sizeof(size_t), 1, CursoDisciplinaBin);
        fwrite(courses[i].name, CursoNameLen, 1, CursoDisciplinaBin);
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<10; k++)
            {
                fwrite(j, sizeof(int), 1, CursoDisciplinaBin);   //ano  
                size_t DisciplinaNameLen = strlen(courses[i].AnoDisciplina[j][k]) + 1;
                fwrite(DisciplinaNameLen, sizeof(size_t), 1, CursoDisciplinaBin);
                fwrite(courses[i].AnoDisciplina[j][k], DisciplinaNameLen, 1, CursoDisciplinaBin);
            }
        }
    }
}

void ListarCursosDisciplinas()
{
    for(int i=0; i<n_courses; i++)
    {
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        for(int j=0; j<3; j++)
        {
            printf("Disciplinas do %d ano : ", j+1);
            for(int k=0; k<10; k++)
            {
                if(k == 5)
                    printf("\n");
                printf("%s\t", courses[i].AnoDisciplina[j][k]);

            }
            printf("\n\n");
        }
        printf("\n\n");
        printf("Diretor: %d\n", courses[i].IdResponsavel);
        printf("\n\n");
    }
}

void ListarCursos()
{
    for(int i=0; i<n_courses; i++)
    {
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        printftf("ID Diretor de curso: %d\n", courses[i].IdResponsavel);
    }
}

void EditarCursos()
{
    int id;
    char op;
    printc("[green]Cursos existentes:[/green]");
    ListarCursos();
    printc("[green]Disciplinas existentes:[/green]");
    ListarDisciplinas();
    printc("\n\n\t[green]Insira o ID do curso que quer editar:[/green] ");
    scanf("%d", &id);
    for (int i = 0; i < n_courses; i++)
    {
        if (courses[i].id == id)
        {
            printc("\n[green]Curso encontrado -->[/green] ");
            printf("Curso %d: %s\n", courses[i].id,  courses[i].name);

            printftf("Alterar nome? (S/N");
            scanf("%c", &op);
            if(op == 'S' || op == 's')
            {
            printf("Insira o novo nome do curso: ");
            scanf("%s", courses[i].name);
            saveBinCourses(courses , n_courses);
            }
            printf("Alterar disciplinas? (S/N");
            scanf("%c", &op);
            if(op == 'S' || op == 's')
            {
            for(int j=0; j<3; j++)
            {
                printf("Insira as siglas das 10 disciplinas do %d ano : ", j+1);
                for(int k=0; k<10; k++)
                {
                    scanf("%s", courses[i].AnoDisciplina[j][k]);
                }
            }
            }
            printf("Alterar diretor? (S/N");
            scanf("%c", &op);
            if(op == 'S' || op == 's')
            {
            printf("Insira o ID do novo diretor deste curso: ");
            printf("\nID: ");
            scanf("%d", courses[i].IdResponsavel);
            }
        }
    }
    SaveTxtCursosDisciplina();
    SaveBinCursosDisciplina();
} */