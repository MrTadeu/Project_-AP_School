#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "global.h"

extern AlunoDataStruct aluno;

//Menu Folder Novos: Ficheiros.c
void MenuFilesNovos(){
    int opcao;
    do{
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        printf("***************************************************************\n");
        printc("************            [blue]Menu Files[/blue]                 ************\n");
        printf("***************************************************************\n");
        printf("************        0 -> Sair                      ************\n");
        printf("************        1 -> Continuar                 ************\n");
        printf("************        2 -> importar dados alunos txt ************\n");
        printf("***************************************************************\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
    switch (opcao){
      case 0:
        exit(0);
        break;
      case 1:
        printc("Deseja continuar com os dados [red]Corrompidos[/red]? [[red]0[/red]/[green]1[/green]] ");
        scanf("%d", &opcao);
        if (opcao == 1){
          readData();
          opcao = 0;
        }
        else{
          MenuFilesNovos();
        }
        break;
      case 2:
        importDataTxtBin();
        break;
      default:
        printf("Opcao invalida!\n");
        break;
    }
    }while (opcao != 0);
}

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

 
//MENU PRINCIPAL: login.c
void MenuPrincipal(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        i = 0;
        printf("Bem vindo %s!\n", aluno.name);
        printc("**************************************************\n");
        printc("****************** [blue]Menu Principal[/blue] ****************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if (aluno.regime.perm.VerDisciplinas){
            printf("**        %d -> Ver Disciplinas                  **\n", i++);
        }
        if(aluno.regime.perm.MenuExames){
            printf("**        %d -> Menu Exames                      **\n", i++);
        }
        printf("**        %d -> Editar Conta de Utilizador       **\n", i++);
        if(aluno.regime.perm.MenuAdmin){
            printf("**        %d -> Menu admin                       **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        i = 1;

        if (aluno.regime.perm.VerDisciplinas){
            if (opcao == i++){
                printf("Menu Disciplinas");
                //MenuDisciplinas();
            }
        }

        if (aluno.regime.perm.MenuExames){
            if (opcao == i++){
                printf("Menu Exames");
                //MenuExames(); 
            }
        }

        if (opcao == i++){
            editAccount();
        }

        if (aluno.regime.perm.MenuAdmin){
            if (opcao == i++){
                MenuAdmin();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}
/* 
//MENU EXAMES: exames.c
void MenuExames(){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Exames[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (aluno.regime.perm.CriarExames){
        printf("**        %d -> Criar Exames                     **\n", i++); // Não esquecer de verificar se o aluno já está inscrito no exame e se Não se deve permitir marcar exames de um mesmo ano curricular com uma diferença de dias inferior a 3 dias e a data não pode ser num fim de semana ou feriado. FAZER A SELEÇÃO DE SALAS E DATA/HORA QUE OCORRERÁ.
    }
    if (aluno.regime.perm.InscreverExames){
        printf("**        %d -> Inscrever em Exames              **\n", i++); // Não esquecer de verificar se o aluno já está inscrito no exame e se Não se deve permitir marcar exames de um mesmo ano curricular com uma diferença de dias inferior a 3 dias e a data não pode ser num fim de semana ou feriado.
    }
    if (aluno.regime.perm.InscritosExames){
        printf("**        %d -> Inscritos em Exames              **\n", i++);
    }
    if (aluno.regime.perm.ListarExames){
        printf("**        %d -> Listar Exames                    **\n", i++);
    }
    if (aluno.regime.perm.ListarExamesInscritos){
        printf("**        %d -> Listar Exames Inscritos          **\n", i++);
    }
    if (aluno.regime.perm.EditarExames){
        printf("**        %d -> Editar Exames                    **\n", i++);
    }
    if (aluno.regime.perm.ExportarExames){
        printf("**        %d -> Exportar Exames                  **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (aluno.regime.perm.CriarExames){
        if (opcao == i++){
            criarExame();
        }
    }
    if (aluno.regime.perm.InscreverExames){
        if (opcao == i++){
            inscreverExame();
        }
    }
    if (aluno.regime.perm.InscritosExames){
        if (opcao == i++){
            inscritosExame();
        }
    }
    if (aluno.regime.perm.ListarExames){
        if (opcao == i++){
            listarExames();
        }
    }
    if (aluno.regime.perm.ListarExamesInscritos){
        if (opcao == i++){
            listarExamesInscritos();
        }
    }
    if (aluno.regime.perm.EditarExames){
        if (opcao == i++){
            editarExame();
        }
    }
    if (aluno.regime.perm.ExportarExames){
        if (opcao == i++){
            exportarExames();
        }
    }
}
*/
//MENU EDITAR CONTA: currentUser.c
int MenuEditarConta(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao;
    printc("**************************************************\n");
    printc("**************** [blue]Menu Editar Conta[/blue] ***************\n");
    printc("**************************************************\n");
    printf("**            0 -> Sair                         **\n");
    printf("**            1 -> Editar Nome                  **\n");
    printf("**            2 -> Editar Password              **\n");
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
}

//MENU ADMIN: admin.c
void MenuAdmin(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        i = 0;
        printc("**************************************************\n");
        printc("****************** [blue]Menu Administração[/blue] ****************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if(aluno.regime.perm.MenuAlunos){
            printf("**        %d -> Menu Alunos                      **\n", i++);
        }
        if(aluno.regime.perm.MenuProfessor){
            printf("**        %d -> Menu Professor                   **\n", i++);
        }
        if (aluno.regime.perm.MenuCursos){
            printf("**        %d -> Menu Cursos                      **\n", i++);
        }
        if (aluno.regime.perm.MenuRegimes){
            printf("**        %d -> Menu Regimes                     **\n", i++);
        }
        if (aluno.regime.perm.MenuSalas){
            printf("**        %d -> Menu Salas                       **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        int i = 0;

        if (aluno.regime.perm.MenuAlunos){
            if (opcao == i++){
                MenuAlunos();
            }
        }

        if (aluno.regime.perm.MenuProfessor){
            if (opcao == i++){
                //MenuProfessor();
            }
        }

        if (aluno.regime.perm.MenuCursos){
            if (opcao == i++){
                //MenuCursos();
            }
        }
        if (aluno.regime.perm.MenuRegimes){
            if (opcao == i++){
               // MenuRegimes();
            }
        }
        if (aluno.regime.perm.MenuSalas){
            if (opcao == i++){
                //MenuSalas();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

void MenuAlunos(){
    int opcao, i = 0;
    /* printc("**************************************************\n");
    printc("****************** [blue]Menu Alunos[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (aluno.regime.perm.ListarTodosAlunoAdmin){
        printf("**        %d -> Listar Todos os Aluno            **\n", i++);
    }
    if (aluno.regime.perm.ListarAlunoAdmin){
        printf("**        %d -> Listar Aluno (ID)                **\n", i++);
    }
    if (aluno.regime.perm.CriarAlunoAdmin){
        printf("**        %d -> Criar Aluno                      **\n", i++);
    }
    if (aluno.regime.perm.EditarAlunoAdmin){
        printf("**        %d -> Editar Aluno                     **\n", i++);
    }
    if (aluno.regime.perm.RemoverAlunoAdmin){
        printf("**        %d -> Remover Aluno                    **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (aluno.regime.perm.ListarTodosAlunoAdmin){
        if (opcao == i++){
            listarTodosAlunos();
        }
    }
    if (aluno.regime.perm.ListarAlunoAdmin){
        if (opcao == i++){
            listarAlunos();
        }
    }
    if (aluno.regime.perm.CriarAlunoAdmin){
        if (opcao == i++){
            criarAluno();
        }
    }
    if (aluno.regime.perm.EditarAlunoAdmin){
        if (opcao == i++){
            editarAluno();
        }
    }
    if (aluno.regime.perm.RemoverAlunoAdmin){
        if (opcao == i++){
            removerAluno();
        }
    } */
}

/*
//MENU PROFESSOR: professor.c
void MenuProfessor(){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Professor[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (aluno.regime.perm.CriarProfessor){
        printf("**        %d -> Criar Professor                  **\n", i++);
    }
    if (aluno.regime.perm.ListarProfessor){
        printf("**        %d -> Listar Professor                 **\n", i++);
    }
    if (aluno.regime.perm.EditarProfessor){
        printf("**        %d -> Editar Professor                 **\n", i++);
    }
    if (aluno.regime.perm.RemoverProfessor){
        printf("**        %d -> Remover Professor                **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    int i = 0;
    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (aluno.regime.perm.CriarProfessor){
        if (opcao == i++){
            criarProfessor(); 
        }
    }
    if (aluno.regime.perm.ListarProfessor){
        if (opcao == i++){
            listarProfessor(); 
        }
    }
    if (aluno.regime.perm.EditarProfessor){
        if (opcao == i++){
            editarProfessor();
        }
    }
    if (aluno.regime.perm.RemoverProfessor){
        if (opcao == i++){
            removerProfessor();
        }
    }
}

//MENU CURSOS: disciplinas.c && cursosdisciplinas.c && UnidadesCurriculares.c
void MenuCursos(){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Cursos[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (aluno.regime.perm.CriarCursos){
        printf("**        %d -> Criar Cursos                     **\n", i++);
    }
    if (aluno.regime.perm.EditarCursos){
        printf("**        %d -> Editar Cursos                    **\n", i++);
    }
    if (aluno.regime.perm.RemoverCursos){
        printf("**        %d -> Remover Cursos                   **\n", i++);
    }
    if (aluno.regime.perm.ListarCursos){
        printf("**        %d -> Listar Cursos                    **\n", i++);
    }
        if (aluno.regime.perm.ListarCursosDisciplinas){                                        
        printf("**        %d -> Listar Cursos/Disciplinas        **\n", i++);
    }
    if (aluno.regime.perm.MenuDisciplinas){
        printf("**        %d -> Menu Disciplinas                 **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    int i = 0;
    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (aluno.regime.perm.CriarCursos){
        if (opcao == i++){
            CriarCurso();
        }
    }
    if (aluno.regime.perm.ListarCursos){
        if (opcao == i++){
            ListarCursos();
        }
    }
    if (aluno.regime.perm.ListarCursosDisciplinas){                         
        if (opcao == i++){
            ListarCursosDisciplinas();
        }
    }
    if (aluno.regime.perm.EditarCursos){
        if (opcao == i++){
            EditarCursos(); 
        }
    }
    if (aluno.regime.perm.RemoverCursos){
        if (opcao == i++){
            RemoverCursos();
        }
    }
    if (aluno.regime.perm.MenuDisciplinas){
        if (opcao == i++){
            MenuDisciplinas();
        }
    }
}

void MenuDisciplinas()
{
    do
    {
    int opcao;
    printc("\n\n\t  [green]Menu Disciplinas[/green]");
    printc("\n\n\t[green]1[/green] - Listar Disciplinas");
    printc("\n\t[green]2[/green] - Editar/Adicionar/Remover Disciplinas");
    printc("\n\t[green]3[/green] - Voltar");
    printc("\n\n\tOpcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        ListarDisciplinas();
        break;
    case 2:
        MenuEditarAdicionarRemoverDisciplinas();
        break;
    case 3:
        MenuCursos(???????);           
        break;
    default:
        printc("\n\n\t[red]Opcao Invalida[/red]");
        break;
    }
    }while (1);
}

void MenuEditarAdicionarRemoverDisciplinas()
{
    do
    {
    int opcao;
    printc("\n\n\t[green]1[/green] - Adicionar Disciplina");
    printc("\n\t[green]2[/green] - Remover Disciplina");
    printc("\n\t[green]3[/green] - Editar Disciplina");
    printc("\n\t[green]4[/green] - Voltar");
    printc("\n\n\tOpcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        CriarDisciplina();
        break;
    case 2:
        RemoverDisciplina();
        break;
    case 3:
        EditarDisciplina();
        break;
    case 4:
        MenuDisciplinas();
        break;
    default:
        printc("\n\n\t[red]Opcao Invalida[/red]");
        break;
    }
    }while (1);   
} 

//MENU SALAS: salas.c
void MenuSalas(){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("****************** [blue]Menu Salas[/blue] ****************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    if (aluno.regime.perm.CriarSalas){
        printf("**        %d -> Criar Salas                     **\n", i++);
    }
    if (aluno.regime.perm.ListarSalas){
        printf("**        %d -> Listar Salas                    **\n", i++);
    }
    if (aluno.regime.perm.EditarSalas){
        printf("**        %d -> Editar Salas                    **\n", i++);
    }
    if (aluno.regime.perm.RemoverSalas){
        printf("**        %d -> Remover Salas                   **\n", i++);
    }
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);

    if (opcao == 0){
        printf("[lw]A fechar o programa...[/lw]");
    }
    if (aluno.regime.perm.CriarSalas){
        if (opcao == i++){
            criarSala();
        }
    }
    if (aluno.regime.perm.ListarSalas){
        if (opcao == i++){
            listarSalas();
        }
    }
    if (aluno.regime.perm.EditarSalas){
        if (opcao == i++){
            editarSala(); 
        }
    }
    if (aluno.regime.perm.RemoverSalas){
        if (opcao == i++){
            removerSala();
        }
    }
}
 */