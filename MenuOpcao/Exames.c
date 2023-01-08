#include <stdio.h>
#include <stdlib.h>
#include "../All_functions/global.h"


/* typedef struct{
    int dia, mes, hora, minuto;
}tempoExames;

typedef struct{
    int disciplina, professor, sala, regime, id;
    tempoExames data;
}Exames; */

extern Exames* exame;
extern int n_exames;
/* exame = malloc(sizeof(Exames)); */

void criarExame(){
    exame = realloc(exame, sizeof(Exames)*(n_exames+1));

    ListarDisciplinas();
    printf("Para qual disciplina pretende criar um exame? ");
    scanf("%d", &exame[n_exames].disciplina);
    
    listarSalas();
    printf("Pra qual sala pretende criar um exame? ");
    scanf("%d", &exame[n_exames].sala);
    

    printf("Qual a data do exame (formato DD MM)? ");
    scanf("%d %d", &exame[n_exames].data.dia, &exame[n_exames].data.mes);

    printf("Qual a hora do exame (formato HH MM)? ");
    scanf("%d %d", &exame[n_exames].data.hora, &exame[n_exames].data.minuto);
    
    n_exames++;
}

void saveBinExames(){
    exame = malloc(sizeof(Exames));
    int i;
    FILE *fp;
    fp = fopen("exames.bin", "wb");  // ID do exame, ID da disciplina, ID da sala, ID do professor, ID do regime, dia, mes, hora, minuto
    for (i = 0; i < n_exames; i++){
        fwrite(&exame[i].id, sizeof(Exames), 1, fp);
        fwrite(&exame[i].disciplina, sizeof(Exames), 1, fp);
        fwrite(&exame[i].sala, sizeof(Exames), 1, fp);
        fwrite(&exame[i].professor, sizeof(Exames), 1, fp);
        fwrite(&exame[i].regime, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.dia, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.mes, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.hora, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.minuto, sizeof(Exames), 1, fp);
    }
    
}
