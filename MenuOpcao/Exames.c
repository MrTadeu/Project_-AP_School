#include <stdio.h>
#include <stdlib.h>

//void menu()

typedef struct{
    int dia, mes, ano, hora, minuto;
}tempoExames;

typedef struct{
    int disciplina, professor, sala, regime;
    tempoExames data;
}Exames;

