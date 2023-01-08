#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern AlunoStruct *alunos;
extern AlunoDataStruct aluno;
extern professorStruct *professores;
extern int n_disciplinas, n_courses, n_alunos, n_professores;


void ListarDisciplinas()
{
    printf("Disciplinas --> ");
    for(int i=0;i<n_disciplinas;i++)
    {
       printc("\t[green]%d[/green] - %s", disciplinas[i].id, disciplinas[i].name);
        if(i==5 || i==10 || i==15 || i==20 || i==25 || i==30)
            printf("\n");
    }
    printf("\n\n");
}

void ListarPropriasDisciplinas()
{
    for(int i = 0; i<3; i++)
    {
        printf("Ano %d: ", i+1);
        for(int j = 0; j<aluno.course.num_disciplinas[i]; j++)
        {
            printf("%s\n", aluno.course.AnoDisciplina[i][j]);
        }
        printf("\n");
    }
}

void CriarDisciplina()
{   
    int id;
    char *nameDisciplina = malloc(10), *nomeCurso = malloc(10), op;
    printc("\n\n\t[green]Insira a sigla da nova disciplina:[/green] ");
    scanf("%s", nameDisciplina);
    nameDisciplina = realloc(nameDisciplina, strlen(nameDisciplina) + 1);
    uppercase(nameDisciplina);
    if(CheckIFDisciplinaExisteNome(nameDisciplina) != -1){
        printc("\n\n\t[red]Disciplina ja existe[/red]\n\n");
        do{
            printf("\n\tSigla: ");
            scanf("%s", nameDisciplina);
            uppercase(nameDisciplina);
        } while(CheckIFDisciplinaExisteNome(nameDisciplina) != -1);
    }
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * n_disciplinas+1);
    disciplinas[n_disciplinas].id = id;
    nameDisciplina = realloc(nameDisciplina, strlen(nameDisciplina)+1);
    disciplinas[n_disciplinas].name = malloc(strlen(nameDisciplina)+1);
    strcpy(disciplinas[n_disciplinas].name, nameDisciplina); 
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
        AdicionarDisciplinaToCursos(nomeCurso, nameDisciplina);
    }
    free(nomeCurso);
    free(nameDisciplina);        
}

void Removerdisciplina()
{
    char nameCurso[10];
    void ListarDisciplinas();
    printc("\n\n\t[green]Insira a sigla da disciplina que quer remover: [/green]");
    scanf("%d", nameCurso);
    if (CheckIFDisciplinaExisteNome(nameCurso) == -1){
        printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
        do{
            printf("\n\n\tInsira a sigla da disciplina que quer remover: ");
            scanf("%d", nameCurso);
        } while (CheckIFDisciplinaExisteNome(nameCurso) == -1);
    }
    for (int i = 0; i < n_disciplinas; i++)
        strcpy(disciplinas[i].name , disciplinas[i+1].name);
    n_disciplinas--;
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (n_disciplinas));   
    SaveBinDisciplinas();
    RemoverDisciplinaFromCursos(nameCurso);
}

void EditarDisciplina()
{
    int id;
    char TmpDiscName[10];
    void ListarDisciplinas();
    printc("\n\n\t[green]Insira o ID da disciplina que quer editar:[/green] ");
    scanf("%d", &id);
    for (int i = 0; i < n_disciplinas; i++)
    {
        if (disciplinas[i].id == id)
        {
            printf("\n\tNova sigla: ");
            scanf("%s", TmpDiscName);
            uppercase(TmpDiscName);
            if(CheckIFDisciplinaExisteNome(TmpDiscName) != -1){
                printc("\n\n\t[red]Disciplina ja existe[/red]\n\n");
                do{
                    printf("\n\tNova Sigla: ");
                    scanf("%s", TmpDiscName);
                    uppercase(TmpDiscName);
                } while(CheckIFDisciplinaExisteNome(TmpDiscName) != -1);
            }
            EditarDisciplinaFromCursos(disciplinas[i].name,TmpDiscName);
            disciplinas[i].name = realloc(disciplinas[i].name, strlen(TmpDiscName) + 1);
            strcpy(disciplinas[i].name, TmpDiscName);
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
        printf("ID Diretor de curso: %d\n", courses[i].IdDiretor);
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
        printf("Diretor: %d\n", courses[i].IdDiretor);
        printf("\n\n");
    }
}

void CriarCurso()
{   
    char *TmpNameCurso = malloc(15), *TmpNameDisciplina = malloc(15);
    int TmpIdDiretor;
    n_courses++;
    printc("\n\n\t[green]Insira o nome do curso:[/green] ");
    scanf("%s", TmpNameCurso);
    uppercase(TmpNameCurso);
    if(CheckIFCursoExisteNome(TmpNameCurso) != -1){
        printc("\n\n\t[red]Este curso ja existe[/red]\n\n");
        do{
            printf("\n\nInsira a sigla do curso: ");
            scanf("%s", TmpNameCurso);
            uppercase(TmpNameCurso);
        } while (CheckIFCursoExisteNome(TmpNameCurso) != -1); 
    }
    TmpNameCurso = malloc(strlen(TmpNameCurso)+1);
    courses = (courseStruct*) realloc(courses, (n_courses) * sizeof(courseStruct*));
    courses[n_courses-1].id = n_courses;
    courses[n_courses-1].name = malloc(strlen(TmpNameCurso + 1));
    strcpy(courses[n_courses-1].name, TmpNameCurso);
    courses[n_courses-1].AnoDisciplina = malloc(3);
    for(int i=0; i<3; i++)   
    { 
        printc("\n\n\tQuantas disciplinas tem %d  o curso?",i+1);
        scanf("%d", &courses[n_courses-1].num_disciplinas[i]);
        if(courses[n_courses-1].num_disciplinas[i] >= n_disciplinas){
                printc("\n\n\t[red]Numero de disciplinas invalido[/red]\n\n");
                do{
                    printf("\n\nInsira o numero de disciplinas do %d ano: ", i+1);
                    scanf("%d", &courses[n_courses-1].num_disciplinas[i]);
                }while(courses[n_courses-1].num_disciplinas[i] >= n_disciplinas);
            }
        courses[n_courses-1].AnoDisciplina[i] = malloc(courses[n_courses-1].num_disciplinas[i]);
        printf("Insira as %d disciplinas do %d ano: ", courses[n_courses-1].num_disciplinas[i], i+1);
        printc("\n\n\t[green]Insira o nome da disciplina do %d ano:[/green] ", i+1);
        for(int j=0; j<courses[n_courses-1].num_disciplinas[i]; j++)
        {
            printf("Disciplina %d: ", j+1);
            scanf("%s", TmpNameDisciplina);
            uppercase(TmpNameDisciplina);
            if(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1){
                printc("\n\n\t[red]Esta disciplina nao existe[/red]\n\n");
                do{
                    printf("\n\nInsira a sigla da disciplina: ");
                    scanf("%s", TmpNameDisciplina);
                    uppercase(TmpNameDisciplina);
                } while (CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1); 
            }
            TmpNameDisciplina = realloc(TmpNameDisciplina, strlen(TmpNameDisciplina) + 1);
            courses[n_courses-1].AnoDisciplina[i][j] = malloc(strlen(TmpNameDisciplina) + 1);
            strcpy(courses[n_courses-1].AnoDisciplina[i][j], TmpNameDisciplina);
        }
    }
    
    printc("\n\n\t[green]Insira o ID do diretor deste curso:[/green] ");
    scanf("%d", &TmpIdDiretor);
    if(CheckIFProfessor(TmpIdDiretor) == -1){
        printc("\n\n\t[red]Esta pessoa não é professor[/red]\n\n");
        do{
            printf("\n\nInsira o ID do um professor para ser o diretor deste curso: ");
            scanf("%d", &TmpIdDiretor);
        } while (CheckIFProfessor(TmpIdDiretor) == -1); 
    }
    courses[n_courses-1].IdDiretor = TmpIdDiretor;
    SaveBinCursosDisciplina();
}

void EditarCursos(){
    int id, TmpIdDiretor;
    char op, TmpNameCurso[15], *TmpNameDisciplina = malloc(15);

    printc("[green]Cursos existentes:[/green]");
    ListarCursos();
    printc("\n\n\t[green]Insira o ID do curso que quer editar:[/green] ");
    scanf("%d", &id);
    if (CheckIFCursoExiste(id) == -1){
        do
        {
            printc("\n\n\t[red]Curso nao existe[/red]\n\n");
            printc("\n\n\tInsira o ID do curso que quer editar: ");
            scanf("%d", &id);
        } while (CheckIFCursoExiste(id) == -1);
    }
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
        courses[CheckIFCursoExiste(id)].name = malloc(strlen(TmpNameCurso) + 1);
        strcpy(courses[CheckIFCursoExiste(id)].name, TmpNameCurso);
    }
    printf("\n\nAlterar disciplinas? (S/N");
    scanf("%c", &op);
    if(op == 'S' || op == 's')
    {
        printc("[green]Disciplinas existentes:[/green]\n");
        ListarDisciplinas();
        for(int j=0; j<3; j++)
        {
            printc("\n\n\tQuantas disciplinas tem %d  ano do curso?",j+1);
            scanf("%d", &courses[CheckIFCursoExiste(id)].num_disciplinas[j]);
                    if(courses[CheckIFCursoExiste(id)].num_disciplinas[j] >= n_disciplinas){
                printc("\n\n\t[red]Numero de disciplinas invalido[/red]\n\n");
                do{
                    printf("\n\nInsira o numero de disciplinas do %d ano: ", j+1);
                    scanf("%d", &courses[CheckIFCursoExiste(id)].num_disciplinas[j]);
                }while(courses[CheckIFCursoExiste(id)].num_disciplinas[j] >= n_disciplinas);
            }
            courses[CheckIFCursoExiste(id)].AnoDisciplina[j] = realloc(courses[CheckIFCursoExiste(id)].AnoDisciplina[j], courses[CheckIFCursoExiste(id)].num_disciplinas[j]);
            printf("Insira as siglas das %d disciplinas do %d ano : ", courses[CheckIFCursoExiste(id)].num_disciplinas[j], j+1);
            for(int k=0; k<courses[CheckIFCursoExiste(id)].num_disciplinas[j]; k++)
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
                courses[CheckIFCursoExiste(id)].AnoDisciplina[j][k] = malloc(strlen(TmpNameDisciplina)+1);
                strcpy(courses[CheckIFCursoExiste(id)].AnoDisciplina[j][k], TmpNameDisciplina);
            }
        }
    }
    printf("\n\nAlterar diretor? (S/N");
    scanf("%c", &op);
    if(op == 'S' || op == 's')
    {
        printc("\n\n\t[green]Insira o ID do novo diretor deste curso:[/green] ");
        scanf("%d", &TmpIdDiretor);
        if(CheckIFProfessor(TmpIdDiretor) == -1){
            printc("\n\n\t[red]Esta pessoa não é profesor[/red]\n\n");
            do{
                printf("\n\nInsira o ID do um professor para ser o novo diretor deste curso: ");
                scanf("%d", &TmpIdDiretor);
            }while (CheckIFProfessor(TmpIdDiretor) == -1); 
        }
    courses[CheckIFCursoExiste(id)].IdDiretor = TmpIdDiretor;
    }
    printc("\n\n\t[green]Curso editado com sucesso[/green]\n\n");
    SaveBinCursosDisciplina();
    if(aluno.course.id == courses[CheckIFCursoExiste(id)].id)
        aluno.course = courses[CheckIFCursoExiste(id)];   
}

void RemoverDisciplinaFromCursos(char* name)
{
    int aux;
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
                    aux = i;
                    k = courses[i].num_disciplinas[j];
                    j = 3;
                    i = n_courses;
                }
            }
        }
    }
    SaveBinCursosDisciplina();
    if(aluno.course.id == courses[aux].id)
        aluno.course = courses[aux];
}
void AdicionarDisciplinaToCursos(char* nameCurso, char* nomeDisciplina)
{
    int ano, i;
    for(int i=0; i<n_courses; i++){
        if(strcmp(courses[i].name, nameCurso) == 0){
            printf("A que ano pertence a disciplina? (1, 2 ou 3)");
            scanf("%d", &ano);
            courses[i].num_disciplinas[ano]++;
            courses[i].AnoDisciplina[ano] = realloc(courses[i].AnoDisciplina[ano], courses[i].num_disciplinas[ano]);
            courses[i].AnoDisciplina[ano][courses[i].num_disciplinas[ano]-1] = malloc(strlen(nomeDisciplina)+1);
            strcpy(courses[i].AnoDisciplina[ano][courses[i].num_disciplinas[ano]-1], nomeDisciplina);
            break;
        }
    }

    SaveBinCursosDisciplina();
    if(aluno.course.id == courses[i].id)
        aluno.course = courses[i];
}

void EditarDisciplinaFromCursos(char *NameOriginal,char *nameNovo)
{
    int aux;
    for (int i = 0; i < n_courses; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < courses[i].num_disciplinas[j]; k++){
                if (strcmp(courses[i].AnoDisciplina[j][k], NameOriginal) == 0){
                    strcpy(courses[i].AnoDisciplina[j][k], nameNovo);
                    aux = i;
                    k=courses[i].num_disciplinas[j];
                    j=3;
                    i=n_courses;
                }
            }
        } 
    }
    SaveBinCursosDisciplina();
    if(aluno.course.id == courses[aux].id)
        aluno.course = courses[aux];   
}

void RemoverCursos()
{
    //  <--This is a problem    
    //atulizar strut alunoData do pedro, e remover o curso do aluno que tiver o curso e elimina exames
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

int CheckIFProfessor(int id)
{
    for(int i=0; i<n_professores; i++){
        if(professores[i].id == id)
            return i;
    }
    return -1;
}