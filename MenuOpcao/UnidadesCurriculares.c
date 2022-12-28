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
    char *name = malloc(10), *nomeCurso = malloc(10), op;
    printc("\n\n\t[green]Insira a sigla da nova disciplina:[/green] ");
    scanf("%s", name);
    name = realloc(name, strlen(name) + 1);
    uppercase(name);
    if(CheckIFDisciplinaExisteNome(name) != -1){
        printc("\n\n\t[red]Disciplina ja existe[/red]\n\n");
        do{
            printf("\n\tSigla: ");
            scanf("%s", name);
            uppercase(name);
        } while(CheckIFDisciplinaExisteNome(name) != -1);
    }
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * n_disciplinas+1);
    disciplinas[n_disciplinas].id = id;
    strcpy(disciplinas[n_disciplinas].name, name); 
    n_disciplinas++;
    
    SaveBinDisciplinas();
    printf("Pretende adicionar a disciplina a algum curso? (s/n)");
    scanf("%c", &op);
    if(op == 'S' || op == 's')
    {
        printf("Qual o nome curso que pretende adicionar a disciplina?");
        scanf("%s", nomeCurso);
        uppercase(nomeCurso);
        if(CheckIFCursoExisteNome(nomeCurso) == -1){
            printc("\n\n\t[red]Curso nao existe[/red]\n\n");
            do{
                printf("\n\tNome do curso: ");
                scanf("%s", nomeCurso);
                uppercase(nomeCurso);
            } while(CheckIFCursoExisteNome(nomeCurso) == -1);
        }   
        nomeCurso = realloc(nomeCurso, strlen(nomeCurso) + 1);
        AdicionarDisciplinaToCursos(nomeCurso, name);
    }
    free(nomeCurso);
    free(name);        
}

void Removerdisciplina()
{
    char name[10];
    void ListarDisciplinas();
    printc("\n\n\t[green]Insira a sigla da disciplina que quer remover: [/green]");
    scanf("%d", name);
    if (CheckIFDisciplinaExisteNome == -1){
        printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
        do{
            printf("\n\n\tInsira a sigla da disciplina que quer remover: ");
            scanf("%d", name);
        } while (CheckIFDisciplinaExisteNome(name) == -1);
    }
    for (int i = 0; i < n_disciplinas; i++){
        strcpy(disciplinas[i].name , disciplinas[i+1].name);
        n_disciplinas--;
        break;
        }
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (n_disciplinas));   
    SaveBinDisciplinas();
    RemoverDisciplinaFromCursos(name);
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
        printf("ID Diretor de curso: %d\n", courses[i].IdResponsavel);
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
    char TmpNameCurso[15], TmpNameDisciplina[15];
    int TmpIdDiretor;
    n_courses++;
    printc("\n\n\t[green]Insira o nome do curso:[/green] ");
    scanf("%s", TmpNameCurso);
    if(CheckIFCursoExisteNome(TmpNameCurso) != -1){
        printc("\n\n\t[red]Este curso ja existe[/red]\n\n");
        do{
            printf("\n\nInsira a sigla do curso: ");
            scanf("%s", TmpNameCurso);
        } while (CheckIFCursoExisteNome(TmpNameCurso) != -1); 
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
    if(CheckIFPessoaExiste(TmpIdDiretor) == -1){
        printc("\n\n\t[red]Esta pessoa nao existe[/red]\n\n");
        do{
            printf("\n\nInsira o novo ID do diretor: ");
            scanf("%d", &TmpIdDiretor);
        } while (CheckIFPessoaExiste(TmpIdDiretor) == -1); 
    }
    courses[n_courses-1].IdResponsavel = TmpIdDiretor;
    SaveBinCursosDisciplina();
    saveBinCourses();
}

void EditarCursos()
{
    int id, TmpIdDiretor;
    char op, TmpNameCurso[15], TmpNameDisciplina[15];

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
            printf("Alterar nome? (S/N");
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

void RemoverDisciplinaFromCursos(char* name)
{
    for(int i=0; i<n_courses; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<courses[i].num_disciplinas[j]; k++){
                if(strcmp(courses[i].AnoDisciplina[j][k], name) == 0){
                    for (int l = k; l < courses[i].num_disciplinas[j]; l++)
                    {
                        strcpy(courses[i].AnoDisciplina[j][l], courses[i].AnoDisciplina[j][l+1]);
                    }
                    courses[i].num_disciplinas[j]--;
                    courses[i].AnoDisciplina[j] = realloc(courses[i].AnoDisciplina[j], courses[i].num_disciplinas[j]);
                }
            }
        }
    }
    SaveBinCursosDisciplina();
}
void AdicionarDisciplinaToCursos(char* nameCurso, char* nomeDisciplina)
{
    int ano;
    for(int i=0; i<n_courses; i++){
        if(strcmp(courses[i].name, nameCurso) == 0){
            printf("A que ano pertence a disciplina? (1, 2 ou 3)");
            scanf("%d", &ano);
            courses[i].num_disciplinas[ano]++;
            courses[i].AnoDisciplina[ano] = realloc(courses[i].AnoDisciplina[ano], courses[i].num_disciplinas[ano]);
            strcpy(courses[i].AnoDisciplina[ano][courses[i].num_disciplinas[ano]-1], nomeDisciplina);
        }
    SaveBinCursosDisciplina();
    }
}

void ListarPropriasDisciplinas()
{
    //  <--This is a problem
}
void RemoverCursos()
{
    //  <--This is a problem    
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