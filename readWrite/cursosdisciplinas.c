#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern AlunoStruct *alunos;
extern int n_disciplinas, n_courses, n_alunos;


void InitCursos() { //Apenas usado pela primeira vez
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
