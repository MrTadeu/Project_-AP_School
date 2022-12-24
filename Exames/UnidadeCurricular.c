#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

extern AlunoStruct *alunos;
extern courseStruct *courses;
extern disciplinasStruct *disciplinas;
extern int n_courses, n_disciplinas;

void InitCurso() {
    for(int i=0; i<n_courses; i++)
    {   ListarDisciplinas(disciplinas, n_disciplinas);
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        for(int j=0; j<3/*ano*/; j++)
        {
            printf("Insira as siglas das 10 disciplinas do %d ano : ", j+1);
            for(int k=0; k<10; k++)
            {
                scanf("%s", courses[i].AnoDisciplina[j][k]);
            }
        }
        printf("\n\n");
        printf("Insira os dados do diretor deste curso?: ");
        printf("\nNome: ");
        scanf("%s", courses[i].IdResponsavel);
}
}