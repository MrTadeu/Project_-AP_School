#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern AlunoStruct *alunos;
extern int n_disciplinas, n_courses, n_alunos;

void getAllCourses(AlunoFileStruct *alunosFile){
    courseStruct *courses = malloc(sizeof(courseStruct));
    for (int i = 0; i < n_alunos; i++){
        int found = 0;
        for (int j = 0; j < n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            courses = realloc(courses, ((n_courses)+1)*sizeof(courseStruct));
            courses[n_courses].id = n_courses+1;
            courses[n_courses].name = malloc((strlen(alunosFile[i].course)+1));
            strcpy(courses[n_courses].name, alunosFile[i].course);
            n_courses++;
        }
    } 
    SaveBinCursosDisciplina();
}

int InitCursos() { //Apenas usado pela primeira vez

    for (int i=0;i<n_courses;i++)
        courses[i].AnoDisciplina = malloc(3);
    char *TmpNameDisciplina = malloc(15);
    int  TmpIdDiretor, Criardisc;
    for(int i=0; i<n_courses; i++){   
        ListarDisciplinas();
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        for(int j=0; j<3; j++){   
            printf("Insira o numero de disciplinas do %d ano: ", j+1);
            scanf("%d", &courses[i].num_disciplinas[j]);
            courses[i].AnoDisciplina[j] = malloc(courses[i].num_disciplinas[j]);
            printf("Insira as siglas das %d disciplinas do %d ano : ", courses[i].num_disciplinas[j], j+1);
            for(int k=0; k<courses[i].num_disciplinas[j]; k++)
            {   
                printf("\nDisciplina %d: ", k+1);
                scanf("%s", TmpNameDisciplina);
                uppercase(TmpNameDisciplina);
                if(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1){
                    printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
                    do{
                        printf("\n\nInsira a sigla da disciplina: ");
                        scanf("%s", TmpNameDisciplina);
                        uppercase(TmpNameDisciplina);
                    } while (CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1); 
                }
                TmpNameDisciplina = realloc(TmpNameDisciplina, strlen(TmpNameDisciplina)+1);
                courses[i].AnoDisciplina[j][k] = malloc(strlen(TmpNameDisciplina)+1);
                strcpy(courses[i].AnoDisciplina[j][k], TmpNameDisciplina);
            }
        }
        printf("\n\n");
        printf("Insira o ID do diretor deste curso: ");
        printf("\nID: ");
        scanf("%d", &TmpIdDiretor);
        if(CheckIFPessoaExiste(TmpIdDiretor) == -1){
            printc("\n\n\t[red]Esta pessoa nao existe[/red]\n\n");
            do{
                printf("\n\nInsira o ID do diretor: ");
                scanf("%d", &TmpIdDiretor);
            } while (CheckIFPessoaExiste(TmpIdDiretor) == -1); 
        }
        /* if(alunos[CheckIFPessoaExiste(TmpIdDiretor)].id_regime???????????){
            printc("\n\n\t[red]Esta pessoa nao e um professor[/red]\n\n");
            do{
                printf("\n\nInsira o ID do diretor deste curso: ");
                scanf("%d", &TmpIdDiretor);
            } while (alunos[CheckIFPessoaExiste(TmpIdDiretor)].id_regime???????);  
        }
        else
        courses[i].IdResponsavel = TmpIdDiretor;*/  //--> This is a problem
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
        fwrite(&courses[i].id, sizeof(int), 1, CursoDisciplinaBin);
        size_t CursoLen = strlen(courses[i].name) + 1;
        fwrite(&CursoLen, sizeof(size_t), 1, CursoDisciplinaBin);
        fwrite(courses[i].name, CursoLen, 1, CursoDisciplinaBin);
        for(int j=0; j<3; j++)
        {   fwrite(&courses[i].num_disciplinas[j], sizeof(int), 1, CursoDisciplinaBin);
            for(int k=0;k < courses[i].num_disciplinas[j]; k++)
            {
                size_t DisciplinaLen = strlen(courses[i].AnoDisciplina[j][k]) + 1;
                fwrite(&DisciplinaLen, sizeof(size_t), 1, CursoDisciplinaBin);
                fwrite(courses[i].AnoDisciplina[j][k], DisciplinaLen, 1, CursoDisciplinaBin);
            }
        }
        fwrite(&courses[i].IdResponsavel, sizeof(int), 1, CursoDisciplinaBin);
    }
    fclose(CursoDisciplinaBin);
}


void ReadBinCursosDisciplina()
{
    FILE *CursoDisciplinaBin = fopen("data/bin/cursosdisciplina.bin","rb");
    if (CursoDisciplinaBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]cursosdisciplina.txt[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_courses; i++){
        fread(&courses[i].id, sizeof(int), 1, CursoDisciplinaBin);
        size_t CursoLen;
        fread(&CursoLen, sizeof(size_t), 1, CursoDisciplinaBin);
        fread(courses[i].name, CursoLen, 1, CursoDisciplinaBin);
        for(int j=0; j<3; j++)
        {   fread(&courses[i].num_disciplinas[j], sizeof(int), 1, CursoDisciplinaBin);
            for(int k=0; k<courses[i].num_disciplinas[j]; k++)
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


courseStruct getCourseByID(int id){
    for (int i = 0; i < n_courses; i++){
        if (courses[i].id == id){
            return courses[i];
        }
    }
    courseStruct course;
    course.id = -1;
    course.name = malloc(12);
    strcpy(course.name, "Não existe!");
    return course;
}