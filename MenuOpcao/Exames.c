#include <stdio.h>
#include <stdlib.h>
#include "../All_functions/global.h"


/* typedef struct{
    int dia, mes, hora, minuto;
}tempoExames;

typedef struct{
    int disciplina, professor, sala, regime;
    tempoExames data;
}Exames; */

Exames* exame;
int n_exames = 0;

void criarExame(){
    exame = malloc(sizeof(Exames));
    printf("Para qual disciplina pretende criar um exame? ");
    scanf("%d", &exame[n_exames].disciplina);
    exame = realloc(exame, sizeof(Exames)*(n_exames+1));

    printf("Pra qual sala pretende criar um exame? ");


    n_exames++;
}