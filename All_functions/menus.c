#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "global.h"

//MENU PRINCIPAL: main.c
int mainMenu(){
    int opcao;
    printf("**************************************************\n");
    printf("****************** Menu Principal ****************\n");
    printf("**************************************************\n");
    printf("**        0 -> Sair                             **\n");
    printf("**        1 -> Login                            **\n");
    printf("**        2 -> Exportar / Importar Dados        **\n");
    printf("**************************************************\n");
    printf("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
}

//MENU IMPORTAR / EXPORTAR FILE: importExport.c
int importExportMenu(){
    int opcao;
    printf("**************************************************\n");
    printf("************ Menu Importar / Exportar ************\n");
    printf("**************************************************\n");
    printf("**        0 -> Voltar                           **\n");
    printf("**        1 -> Importar (TXT -> BIN)            **\n");
    printf("**        2 -> Exportar (BIN -> TXT)            **\n");
    printf("**        3 -> Exportar (BIN -> CSV)            **\n");
    printf("**************************************************\n");
    printf("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
}

//MENU LOGIN_Principal: login.c 
void loguinMenu(){
    printc("[lw]Bem-vindo ao sistema de gestão de exames![/lw\n");
    printc("[lw]Por favor, faça o login para continuar![/lw\n");
    printc("[lw]Username:[/lw ");
    printc("[lw]Password:[/lw ");
}

//MENU CONSOANTE O TIPO DE UTILIZADOR: login.c
void MenuMain(){
    int opcao, i = 1, list_alunos = 0, export = 1, edit = 1, j=1;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Principal[/blue] ****************\n");
    printc("**************************************************\n");
    printc("**        0 -> Sair                             **\n");
    if (list_alunos == 1){ 
        printc("**        %d -> Listar Alunos                    **\n", i++);
    }
    if (export == 1){
        printc("**        %d -> Exportar / Importar Dados        **\n", i++);
    }
    if (edit == 1){
        printc("**        %d -> Editar Conta de Utilizador       **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
    if (opcao == 0){
        printc("[lw]A fechar o programa...[/lw]");
    }
    else if (opcao == j && list_alunos == 1){
        /* code */
    }
    
    
}