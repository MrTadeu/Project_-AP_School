#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern AlunoStruct *alunos;
extern int n_disciplinas, n_courses, n_alunos;


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

void criarDisciplina()
{   
    int id;
    char *name = malloc(10);
    printc("\n\n\tInsira os dados da disciplina: ");
    printc("\n\n\tID: ");
    scanf("%d", &id);
    printc("\n\tNome: ");
    scanf("%s", name);
    name = realloc(name, strlen(name) + 1);
    uppercase(name);
    n_disciplinas++;
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * n_disciplinas);
    disciplinas[n_disciplinas-1].id = id;
    strcpy(disciplinas[n_disciplinas-1].name, name);
    free(name);
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
                strcpy(disciplinas[j].name , disciplinas[j+1].name);
            }
            n_disciplinas--;
            break;
        }
    }
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (n_disciplinas));   
    SaveBinDisciplinas();
}

void EditarDisciplina()
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
    SaveBinDisciplinas();
}

//________CURSOS_____CURSOS______CURSOS______CURSOS______CURSOS_______CURSOS_______CURSOS_________

void ListarCursos()
{
    for(int i=0; i<n_courses; i++)
    {
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        printftf("ID Diretor de curso: %d\n", courses[i].IdResponsavel);
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
        printf("Diretor: %d\n", courses[i].IdResponsavel);
        printf("\n\n");
    }
}

void CriarCurso()
{
    n_courses++;
    char TmpNameCurso[15], TmpNameDisciplina[15], TmpIdDiretor[15];
    printc("\n\n\t[green]Insira o nome do curso:[/green] ");
    scanf("%s", TmpNameCurso);
    if(CheckIFCursoExisteNome(TmpNameCurso) != -1){
        printc("\n\n\t[red]Este curso ja existe[/red]\n\n");
        do{
            printf("\n\nInsira a sigla do curso: ");
            scanf("%s", TmpNameCurso);
        } while (CheckIFCursoExiste(TmpNameCurso) != -1); 
    }
    courses = (courseStruct*) realloc(courses, (n_courses) * sizeof(courseStruct*));
    courses[n_courses-1].id = n_courses;
    courses[n_courses-1].name = malloc(strlen(TmpNameCurso + 1));
    uppercase(TmpNameCurso);
    strcpy(courses[n_courses-1].name, TmpNameCurso);
    for(int i=0; i<3; i++)
    {   
        printc("\n\n\t[green]Insira o nome da disciplina do %d ano:[/green] ", i+1);
        for(int j=0; j<10; j++)
        {
            printf("Disciplina %d: ", j+1);
            scanf("%s", TmpNameDisciplina);
            courses[n_courses-1].AnoDisciplina[i][j] = malloc(strlen(TmpNameDisciplina + 1));
            uppercase(TmpNameDisciplina);
            strcpy(courses[n_courses-1].AnoDisciplina[i][j], TmpNameDisciplina);
        }
    }
    
    printc("\n\n\t[green]Insira o ID do diretor de curso:[/green] ");
    scanf("%d", &TmpIdDiretor);
    if(CheckIFProfessorExiste(TmpIdDiretor) == -1){
        printc("\n\n\t[red]Esta pessoa nao existe[/red]\n\n");
        do{
            printf("\n\nInsira o novo ID do diretor: ");
            scanf("%d", &TmpIdDiretor);
        } while (CheckIFProfessorExiste(TmpIdDiretor) == -1); 
    }
    courses[n_courses-1].IdResponsavel = TmpIdDiretor;
    SaveBinCursosDisciplina();
    SaveBinCursos();
}

void EditarCursos()
{
    int id;
    char op, TmpNameCurso[15], TmpNameDisciplina[15], TmpIdDiretor[15];
    printc("[green]Cursos existentes:[/green]");
    ListarCursos();
    printc("\n\n\t[green]Insira o ID do curso que quer editar:[/green] ");
    scanf("%d", &id);
    for (int i = 0; i < n_courses; i++)
    {
        if (CheckIFCursoExiste(id) == -1)
            printc("\n\n\t[red]Curso nao existe[/red]\n\n");
        else
        {
            printc("\n[green]Curso encontrado -->[/green] ");
            printf("Curso %d: %s\n", courses[CheckIFCursoExiste(id)].id,  courses[CheckIFCursoExiste(id)].name);
            printftf("Alterar nome? (S/N");
            scanf("%c", &op);
            if(op == 'S' || op == 's')
            {
                printf("\n\nInsira o novo nome do curso: ");
                scanf("%s", TmpNameCurso);
                uppercase(TmpNameCurso);
                if(CheckIFCursoExisteNome(TmpNameCurso) != -1){
                    printc("\n\n\t[red]Curso ja existe[/red]\n\n");
                    do{
                        printf("\n\nInsira o novo nome do curso: ");
                        scanf("%s", TmpNameCurso);
                        uppercase(TmpNameCurso);
                    } while (CheckIFCursoExisteNome(TmpNameCurso) != -1); 
                }
                strcpy(courses[CheckIFCursoExiste(id)].name, TmpNameCurso);
                saveBinCourses();
            }
            printf("\n\nAlterar disciplinas? (S/N");
            scanf("%c", &op);
            if(op == 'S' || op == 's')
            {
                printc("[green]Disciplinas existentes:[/green]\n");
                ListarDisciplinas();
                for(int j=0; j<3; j++)
                {
                    printf("Insira as siglas das 10 disciplinas do %d ano : ", j+1);
                    for(int k=0; k<10; k++)
                    {
                        printf("Insira nome da disciplina %d: ", k+1);
                        scanf("%s", TmpNameDisciplina);
                        uppercase(TmpNameDisciplina);
                        if(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1){
                            printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
                            do{
                                printf("\n\nInsira o novo nome da disciplina: ");
                                scanf("%s", TmpNameDisciplina);
                                uppercase(TmpNameDisciplina);
                            } while (CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1); 
                        }
                        strcpy(courses[CheckIFCursoExiste(id)].AnoDisciplina[j][k], TmpNameDisciplina);
                        SaveTxtCursosDisciplina();
                        SaveBinCursosDisciplina();
                    }
                }
            }
            printf("\n\nAlterar diretor? (S/N");
            scanf("%c", &op);
            if(op == 'S' || op == 's')
            {
                printf("Insira o ID do novo diretor deste curso: ");
                printf("\nID: ");
                scanf("%d", &TmpIdDiretor);
                if(CheckIFPessoaExiste(TmpIdDiretor) == -1){
                    printc("\n\n\t[red]Esta pessoa nao existe[/red]\n\n");
                    do{
                        printf("\n\nInsira o novo ID do diretor: ");
                        scanf("%d", &TmpIdDiretor);
                    } while (CheckIFPessoaExiste(TmpIdDiretor) == -1); 
                }
                courses[CheckIFCursoExiste(id)].IdResponsavel = TmpIdDiretor;
                SaveBinCursosDisciplina();
            }
        }
    }

} 

void RemoverCursos()
{
    
}

int CheckIFDisciplinaExiste(int id)
{
    for(int i=0; i<n_disciplinas; i++){
        if(disciplinas[i].id == id)
            return i;
    }
    return -1;
}

int CheckIFDisciplinaExisteNome(char *name)
{
    for(int i=0; i<n_disciplinas; i++){
        if(strcmp(disciplinas[i].name, name) == 0)
            return i;
    }
    return -1;
}

int CheckIFCursoExiste(int id)
{   int flag = 0;
    for(int i = 0; i<n_courses; i++){
        if(courses[i].id == id)
            return i;
    }
    return -1;
}

int CheckIFCursoExisteNome(char *name)
{
    for(int i = 0; i<n_courses; i++){
        if(strcmp(courses[i].name, name) == 0)
            return i;
    }
    return -1;
}

int CheckIFPessoaExiste(int id)
{
    for(int i=0; i<n_alunos; i++){
        if(alunos[i].id == id)
            return i;
    }
    return -1;
}