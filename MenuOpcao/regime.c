#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern int n_alunos, n_regimes, n_courses;
extern AlunoDataStruct aluno;
extern permissionFileStruct *perms_file;


void criarRegime(){
    regimes = realloc(regimes, (n_regimes + 1) * sizeof(regimeStruct));
}

void editarNomeRegime(){
    
}

void editarPermissoesRegime(){

}

void removerRegime(){
    
}