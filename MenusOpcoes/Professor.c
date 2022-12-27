#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

/* criarProfessor();
listarProfessor(); 
editarProfessor(); 
removerProfessor(); */
extern professorStruct *professores; //extern para poder usar a variavel global.
extern int n_professores; 

void criarProfessoe(){
    professorStruct professortemp;
    professortemp.nomeProfessor = malloc(100);
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    printf("Qual o nome do professor? ");
    scanf(" %[^\n]", professortemp.nomeProfessor);
    
}