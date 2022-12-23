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

//MENU PRINCIPAL: login.c
void MenuPrincipal(PermissionsType perm){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Principal[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (perm.VerDisciplinas){
        printf("**        %d -> Ver Disciplinas              **\n", i++);
    }
    if(perm.MenuExames){
        printf("**        %d -> Menu Exames                  **\n", i++);
    }
    printf("**        %d -> Editar Conta de Utilizador       **\n", i++);
    if(perm.MenuAdmin){
        printf("**        %d -> Menu admin                   **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    i = 0;
    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (perm.VerDisciplinas){
        if (opcao == i++){
            MenuDisciplinas(); // <--- This is the problem
        }
    }
    if (perm.MenuExames){
        if (opcao == i++){
            MenuExames();  // <--- This is the problem
        }
    }
    if (opcao == i++){
        EditarConta(); // <--- This is the problem
    }
    if (perm.MenuAdmin){
        if (opcao == i++){
            MenuAdmin(); // <--- This is the problem
        }
    }
    
}

//MENU EXAMES: exames.c
void MenuExames(PermissionsType perm){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Exames[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (perm.CriarExames){
        printf("**        %d -> Criar Exames                     **\n", i++); // Não esquecer de verificar se o aluno já está inscrito no exame e se Não se deve permitir marcar exames de um mesmo ano curricular com uma diferença de dias inferior a 3 dias e a data não pode ser num fim de semana ou feriado. FAZER A SELEÇÃO DE SALAS E DATA/HORA QUE OCORRERÁ.
    }
    if (perm.InscreverExames){
        printf("**        %d -> Inscrever em Exames              **\n", i++); // Não esquecer de verificar se o aluno já está inscrito no exame e se Não se deve permitir marcar exames de um mesmo ano curricular com uma diferença de dias inferior a 3 dias e a data não pode ser num fim de semana ou feriado.
    }
    if (perm.InscritosExames){
        printf("**        %d -> Inscritos em Exames              **\n", i++);
    }
    if (perm.ListarExames){
        printf("**        %d -> Listar Exames                    **\n", i++);
    }
    if (perm.ListarExamesInscritos){
        printf("**        %d -> Listar Exames Inscritos          **\n", i++);
    }
    if (perm.EditarExames){
        printf("**        %d -> Editar Exames                    **\n", i++);
    }
    if (perm.ExportarExames){
        printf("**        %d -> Exportar Exames                  **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (perm.CriarExames){
        if (opcao == i++){
            criarExame(); // <--- This is the problem
        }
    }
    if (perm.InscreverExames){
        if (opcao == i++){
            inscreverExame(); // <--- This is the problem
        }
    }
    if (perm.InscritosExames){
        if (opcao == i++){
            inscritosExame(); // <--- This is the problem
        }
    }
    if (perm.ListarExames){
        if (opcao == i++){
            listarExames(); // <--- This is the problem
        }
    }
    if (perm.ListarExamesInscritos){
        if (opcao == i++){
            listarExamesInscritos(); // <--- This is the problem
        }
    }
    if (perm.EditarExames){
        if (opcao == i++){
            editarExame(); // <--- This is the problem
        }
    }
    if (perm.ExportarExames){
        if (opcao == i++){
            exportarExames(); // <--- This is the problem
        }
    }
}

//MENU EDITAR CONTA: editarconta.c
void MenuEditarConta(PermissionsType perm){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Editar Conta[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                       **\n", i++);
    printf("**        %d -> Editar Nome                **\n", i++);
    printf("**        %d -> Editar Password            **\n", i++);
    printf("**        %d -> Editar Email               **\n", i++);
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    i = 0;
    if (opcao == i++){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (opcao == i++){
        editarNome(); // <--- This is the problem
    }
    if (opcao == i++){
        editarPassword(); // <--- This is the problem
    }
    if (opcao == i++){
        editarEmail(); // <--- This is the problem
    }
}

//MENU ADMIN: admin.c
void MenuAdmin(PermissionsType perm){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Administração[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if(perm.MenuProfessor){
        printf("**        %d -> Menu Professor               **\n", i++);
    }
    if (perm.MenuCursos){
        printf("**        %d -> Menu Cursos                      **\n", i++);
    }
    if (perm.MenuRegimes){
        printf("**        %d -> Menu Regimes                     **\n", i++);
    }
    if (perm.MenuSalas){
        printf("**        %d -> Menu Salas                       **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (perm.MenuProfessor){
        if (opcao == i++){
            MenuProfessor(); // <--- This is the problem
        }
    }
    if (perm.MenuCursos){
        if (opcao == i++){
            MenuCursos(); // <--- This is the problem
        }
    }
    if (perm.MenuAlunos){
        if (opcao == i++){
            MenuAlunos(); // <--- This is the problem
        }
    }
    if (perm.MenuRegimes){
        if (opcao == i++){
            MenuRegimes(); // <--- This is the problem
        }
    }
    if (perm.MenuSalas){
        if (opcao == i++){
            MenuSalas(); // <--- This is the problem
        }
    }
}

//MENU PROFESSOR: professor.c
void MenuProfessor(PermissionsType perm){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Professor[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (perm.CriarProfessor){
        printf("**        %d -> Criar Professor                  **\n", i++);
    }
    if (perm.ListarProfessor){
        printf("**        %d -> Listar Professor                 **\n", i++);
    }
    if (perm.EditarProfessor){
        printf("**        %d -> Editar Professor                 **\n", i++);
    }
    if (perm.RemoverProfessor){
        printf("**        %d -> Remover Professor                **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (perm.CriarProfessor){
        if (opcao == i++){
            criarProfessor(); // <--- This is the problem
        }
    }
    if (perm.ListarProfessor){
        if (opcao == i++){
            listarProfessor(); // <--- This is the problem
        }
    }
    if (perm.EditarProfessor){
        if (opcao == i++){
            editarProfessor(); // <--- This is the problem
        }
    }
    if (perm.RemoverProfessor){
        if (opcao == i++){
            removerProfessor(); // <--- This is the problem
        }
    }
}

//MENU CURSOS: cursos.c // ver melhor
void MenuCursos(PermissionsType perm){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Cursos[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (perm.CriarCursos){
        printf("**        %d -> Criar Cursos                     **\n", i++);
    }
    if (perm.ListarCursos){
        printf("**        %d -> Listar Cursos                    **\n", i++);
    }
    if (perm.EditarCursos){
        printf("**        %d -> Editar Cursos                    **\n", i++);
    }
    if (perm.RemoverCursos){
        printf("**        %d -> Remover Cursos                   **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (perm.CriarCursos){
        if (opcao == i++){
            criarCursos(); // <--- This is the problem
        }
    }
    if (perm.ListarCursos){
        if (opcao == i++){
            listarCursos(); // <--- This is the problem
        }
    }
    if (perm.EditarCursos){
        if (opcao == i++){
            editarCursos(); // <--- This is the problem
        }
    }
    if (perm.RemoverCursos){
        if (opcao == i++){
            removerCursos(); // <--- This is the problem
        }
    }
}

//MENU SALAS: salas.c
void MenuSalas(PermissionsType perm){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Salas[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (perm.CriarSalas){
        printf("**        %d -> Criar Salas                     **\n", i++);
    }
    if (perm.ListarSalas){
        printf("**        %d -> Listar Salas                    **\n", i++);
    }
    if (perm.EditarSalas){
        printf("**        %d -> Editar Salas                    **\n", i++);
    }
    if (perm.RemoverSalas){
        printf("**        %d -> Remover Salas                   **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (perm.CriarSalas){
        if (opcao == i++){
            criarSala(); // <--- This is the problem
        }
    }
    if (perm.ListarSalas){
        if (opcao == i++){
            listarSalas(); // <--- This is the problem
        }
    }
    if (perm.EditarSalas){
        if (opcao == i++){
            editarSala(); // <--- This is the problem
        }
    }
    if (perm.RemoverSalas){
        if (opcao == i++){
            removerSalas(); // <--- This is the problem
        }
    }
}
