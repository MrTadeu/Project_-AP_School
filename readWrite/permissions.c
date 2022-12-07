#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../All_functions/structs.h"

void setPermissions(Aluno *alunos, int* n_linhas_lidas) //serve para criar os cargos basicos
{
    for(int i = 0; i < *n_linhas_lidas ; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            alunos[i].id_permission[0] = alunos[i].id_role; 
            if(j != 0)
            alunos[i].id_permission[j] = 0;
        }
    }
}

