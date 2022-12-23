#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

extern AlunoFileStruct *alunosFile;
extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern disciplinasStruct *disciplinas;
extern int n_alunos, n_regimes, n_courses, n_disciplinas;

void InitCurso(int n_disciplinas) {
    for(int i=0; i<n_courses; i++)
    {
        printf("Disciplinas --> ");
        for(i=0;i<n_disciplinas;i++)
        {
            printf(" %s ,", disciplinas[i].name);
            if(i==5 || i==10 || i==15 || i==20 || i==25 || i==30)
                printf("\n");
        }
        printf("\n\n");
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