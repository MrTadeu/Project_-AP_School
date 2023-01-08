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

extern Exames* exame;
extern int n_exames;
/* exame = malloc(sizeof(Exames)); */

void criarExame(){
    exame = realloc(exame, sizeof(Exames)*(n_exames+1));

    printf("Para qual disciplina pretende criar um exame? ");
    scanf("%d", &exame[n_exames].disciplina);
    

    printf("Pra qual sala pretende criar um exame? ");
    scanf("%d", &exame[n_exames].sala);
    

    printf("Qual a data do exame (formato DD MM)? ");
    scanf("%d %d", &exame[n_exames].data.dia, &exame[n_exames].data.mes);

    printf("Qual a hora do exame (formato HH MM)? ");
    scanf("%d %d", &exame[n_exames].data.hora, &exame[n_exames].data.minuto);
    
    n_exames++;
}

