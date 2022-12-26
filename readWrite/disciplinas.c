#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern AlunoStruct *alunos;
extern int n_disciplinas, n_courses, n_alunos;


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

void ReadBinDisciplinas()
{
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

void SaveBinDisciplinas()
{
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
    SaveBinDisciplinas();
}
//________CURSOS_____CURSOS______CURSOS______CURSOS______CURSOS_______CURSOS_______CURSOS_________

void InitCursos() { //$$$$$$$$$$$$$$$$$$$$$$$so e usado pela primeira vez$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    char TmpNameDisciplina[15], TmpIdDiretor[15];
    for(int i=0; i<n_courses; i++)
    {   ListarDisciplinas();
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        for(int j=0; j<3; j++)
        {
            printf("Insira as siglas das 10 disciplinas do %d ano : ", j+1);
            for(int k=0; k<10; k++)
            {   
                printf("\nDisciplina %d: ", k+1);
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
                strcpy(courses[i].AnoDisciplina[j][k], TmpNameDisciplina);
            }
        }
        printf("\n\n");
        printf("Insira o ID do diretor deste curso: ");
        printf("\nID: ");
        scanf("%d", &TmpIdDiretor);
        if(CheckIFProfessorExiste(TmpIdDiretor) == -1){
            printc("\n\n\t[red]Esta pessoa nao existe[/red]\n\n");
            do{
                printf("\n\nInsira o novo ID do diretor: ");
                scanf("%d", &TmpIdDiretor);
            } while (CheckIFProfessorExiste(TmpIdDiretor) == -1); 
        }
        courses[i].IdResponsavel = TmpIdDiretor;
    }
    SaveBinCursosDisciplina();
}

void SaveBinCursosDisciplina()
{
    FILE *CursoDisciplinaBin = fopen("data/txt/cursosdisciplina.txt","wb");
    if (CursoDisciplinaBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]cursos.txt[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_courses; i++)
    {
        if(feof(CursoDisciplinaBin))
            break;
        fwrite(courses[i].id, sizeof(int), 1, CursoDisciplinaBin);
        size_t CursoLen = strlen(courses[i].name) + 1;
        fwrite(CursoLen, sizeof(size_t), 1, CursoDisciplinaBin);
        fwrite(courses[i].name, CursoLen, 1, CursoDisciplinaBin);
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<10; k++)
            {
                size_t DisciplinaLen = strlen(courses[i].AnoDisciplina[j][k]) + 1;
                fwrite(DisciplinaLen, sizeof(size_t), 1, CursoDisciplinaBin);
                fwrite(courses[i].AnoDisciplina[j][k], DisciplinaLen, 1, CursoDisciplinaBin);
            }
        }
        fwrite(courses[i].IdResponsavel, sizeof(int), 1, CursoDisciplinaBin);
    }
}


void ReadBinCursosDisciplina()
{
    FILE *CursoDisciplinaBin = fopen("data/bin/cursosdisciplina.bin","rb");
    if (CursoDisciplinaBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]cursosdisciplina.txt[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_courses; i++)
    {
        if(feof(CursoDisciplinaBin))
            break;
        fread(&courses[i].id, sizeof(int), 1, CursoDisciplinaBin);
        size_t CursoLen;
        fread(&CursoLen, sizeof(size_t), 1, CursoDisciplinaBin);
        fread(courses[i].name, CursoLen, 1, CursoDisciplinaBin);
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<10; k++)
            {
                size_t DisciplinaName;
                fread(&DisciplinaName, sizeof(size_t), 1, CursoDisciplinaBin);
                fread(courses[i].AnoDisciplina[j][k], DisciplinaName, 1, CursoDisciplinaBin);
            }
        }
        fread(&courses[i].IdResponsavel, sizeof(int), 1, CursoDisciplinaBin);
    }
    fclose(CursoDisciplinaBin);
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
                saveBinCourses(courses , n_courses);
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
                SaveTxtCursosDisciplina();
                SaveBinCursosDisciplina();
            }
        }
    }

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