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
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();
    regimes = realloc(regimes, (n_regimes + 1) * sizeof(regimeStruct));
    perms_file = realloc(perms_file, (n_regimes + 1) * sizeof(permissionFileStruct));
    regimes[n_regimes].id = regimes[n_regimes-1].id+1;
    regimes[n_regimes].name = malloc(100 * sizeof(char));
    printf("Introduza o nome do regime: ");
    scanf("%s", regimes[n_regimes].name);
    printf("Nome do regime: %s", regimes[n_regimes].name);
    regimes[n_regimes].name = realloc(regimes[n_regimes].name, (strlen(regimes[n_regimes].name) + 1));

    perms_file[n_regimes].id_regime = regimes[n_regimes-1].id+1;
    printc("[blue]Permissoes Exames:[/blue]\n");
    printf("Tem permissao para Criar Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarExames = ValidarZeroUm();
    printf("Tem permissao para Ver Inscritos Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.InscritosExames = ValidarZeroUm();
    printf("Tem permissao para Listar Todos Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarExames = ValidarZeroUm();
    printf("Tem permissao para Listar Exames de um aluno? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarExamesInscritos = ValidarZeroUm();
    printf("Tem permissao para Editar Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarExames = ValidarZeroUm();
    printf("Tem permissao para Exportar Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ExportarExames = ValidarZeroUm();
    printf("Tem permissao para Inscrever Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.InscreverExames = ValidarZeroUm();

    printc("\n[blue]Permissoes Salas:[/blue]\n");
    printf("Tem permissao para Criar Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarSalas = ValidarZeroUm();
    printf("Tem permissao para Listar Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarSalas = ValidarZeroUm();
    printf("Tem permissao para Editar Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarSalas = ValidarZeroUm();
    printf("Tem permissao para Remover Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverSalas = ValidarZeroUm();

    printc("\n[blue]Permissoes Professor:[/blue]\n");
    printf("Tem permissao para Criar Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarProfessor = ValidarZeroUm();
    printf("Tem permissao para Listar Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarProfessor = ValidarZeroUm();
    printf("Tem permissao para Editar Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarProfessor = ValidarZeroUm();
    printf("Tem permissao para Remover Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverProfessor = ValidarZeroUm();

    printc("\n[blue]Permissoes Cursos:[/blue]\n");
    printf("Tem permissao para Criar Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarCursos = ValidarZeroUm();
    printf("Tem permissao para Listar Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarCursos = ValidarZeroUm();
    printf("Tem permissao para Editar Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarCursos = ValidarZeroUm();
    printf("Tem permissao para Remover Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverCursos = ValidarZeroUm();
    printf("Tem permissao para Listar Cursos e Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarCursosDisciplinas = ValidarZeroUm();

    printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
    printf("Tem permissao para Criar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Listar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Editar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Remover Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Listar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Ver Proprias Disciplinas Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.VerDisciplinas = ValidarZeroUm();

    printc("\n[blue]Permissoes Alunos:[/blue]\n");
    printf("Tem permissao para Criar Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarAluno = ValidarZeroUm();
    printf("Tem permissao para Listar Aluno? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarAluno = ValidarZeroUm();
    printf("Tem permissao para Listar Todos os Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarTodosAlunos = ValidarZeroUm();
    printf("Tem permissao para Editar Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarAluno = ValidarZeroUm();
    printf("Tem permissao para Remover Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverAluno = ValidarZeroUm();

    printc("\n[blue]Permissoes Regimes:[/blue]\n");
    printf("Tem permissao para Criar Regimes? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarRegimes = ValidarZeroUm();
    printf("Tem permissao para Listar Regimes? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarRegimes = ValidarZeroUm();
    printf("Tem permissao para Listar Regimes e Permissões? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarRegimesPermissoes = ValidarZeroUm();
    printf("Tem permissao para Editar Nome dos Regimes (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarNomeRegimes = ValidarZeroUm();
    printf("Tem permissao para Editar permissões dos Regimes (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarPermissoesRegimes = ValidarZeroUm();
    printf("Tem permissao para Mover Regimes Regimes (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.MoverRegimes = ValidarZeroUm();
    printf("Tem permissao para Remover Regimes? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverRegimes = ValidarZeroUm();

    n_regimes++;
    saveBinRegimes();
    saveBinPermissions();
}

void editarNomeRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfRegimeExists(id) == 0);

    int position = 0;
    for (int i = 0; i <= n_regimes; i++){
        if (id == regimes[i].id){
            position = i;
            break;
        }
    }
    
    printf("\n\nPor favor introduza o novo nome do regime: ");
    scanf("%s", regimes[position].name);
    saveBinRegimes();
    updateUser();
}

void editarPermissoesRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimesPermissoes();
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfRegimeExists(id) == 0);

    int position = 0;
    for (int i = 0; i <= n_regimes; i++){
        if (id == regimes[i].id){
            position = i;
            break;
        }
    }

    printf("Tem permissao para Criar Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarExames = ValidarZeroUm();
    printf("Tem permissao para Ver Inscritos Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.InscritosExames = ValidarZeroUm();
    printf("Tem permissao para Listar Todos Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarExames = ValidarZeroUm();
    printf("Tem permissao para Listar Exames de um aluno? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarExamesInscritos = ValidarZeroUm();
    printf("Tem permissao para Editar Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarExames = ValidarZeroUm();
    printf("Tem permissao para Exportar Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ExportarExames = ValidarZeroUm();
    printf("Tem permissao para Inscrever Exames? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.InscreverExames = ValidarZeroUm();

    printc("\n[blue]Permissoes Salas:[/blue]\n");
    printf("Tem permissao para Criar Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarSalas = ValidarZeroUm();
    printf("Tem permissao para Listar Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarSalas = ValidarZeroUm();
    printf("Tem permissao para Editar Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarSalas = ValidarZeroUm();
    printf("Tem permissao para Remover Salas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverSalas = ValidarZeroUm();

    printc("\n[blue]Permissoes Professor:[/blue]\n");
    printf("Tem permissao para Criar Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarProfessor = ValidarZeroUm();
    printf("Tem permissao para Listar Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarProfessor = ValidarZeroUm();
    printf("Tem permissao para Editar Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarProfessor = ValidarZeroUm();
    printf("Tem permissao para Remover Professor? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverProfessor = ValidarZeroUm();

    printc("\n[blue]Permissoes Cursos:[/blue]\n");
    printf("Tem permissao para Criar Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarCursos = ValidarZeroUm();
    printf("Tem permissao para Listar Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarCursos = ValidarZeroUm();
    printf("Tem permissao para Editar Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarCursos = ValidarZeroUm();
    printf("Tem permissao para Remover Cursos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverCursos = ValidarZeroUm();
    printf("Tem permissao para Listar Cursos e Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarCursosDisciplinas = ValidarZeroUm();

    printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
    printf("Tem permissao para Criar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Listar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Editar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Remover Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Listar Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarDisciplinas = ValidarZeroUm();
    printf("Tem permissao para Ver Proprias Disciplinas Disciplinas? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.VerDisciplinas = ValidarZeroUm();

    printc("\n[blue]Permissoes Alunos:[/blue]\n");
    printf("Tem permissao para Criar Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarAluno = ValidarZeroUm();
    printf("Tem permissao para Listar Aluno? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarAluno = ValidarZeroUm();
    printf("Tem permissao para Listar Todos os Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarTodosAlunos = ValidarZeroUm();
    printf("Tem permissao para Editar Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarAluno = ValidarZeroUm();
    printf("Tem permissao para Remover Alunos? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverAluno = ValidarZeroUm();

    printc("\n[blue]Permissoes Regimes:[/blue]\n");
    printf("Tem permissao para Criar Regimes? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.CriarRegimes = ValidarZeroUm();
    printf("Tem permissao para Listar Regimes? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarRegimes = ValidarZeroUm();
    printf("Tem permissao para Listar Regimes e Permissões? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.ListarRegimesPermissoes = ValidarZeroUm();
    printf("Tem permissao para Editar Nome dos Regimes (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarNomeRegimes = ValidarZeroUm();
    printf("Tem permissao para Editar permissões dos Regimes (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.EditarPermissoesRegimes = ValidarZeroUm();
    printf("Tem permissao para Mover Regimes Regimes (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.MoverRegimes = ValidarZeroUm();
    printf("Tem permissao para Remover Regimes? (1 - Sim, 0 - Nao): ");
    perms_file[n_regimes].perm.RemoverRegimes = ValidarZeroUm();
    saveBinPermissions();
    updateUser();
}

void moverRegimes(){
    int flag = 0, id, new_id;
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();

    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende mover: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfRegimeExists(id) == 0);

    flag = 0;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPara onde pretende mover (ID): ");
        scanf("%d", &new_id);
        flag = 1;
    }while (checkIfRegimeExists(new_id) == 0 || new_id == id);
    masiveRegimeChange(id, new_id);
}

void removerRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();
    int flag = 0, id, new_id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende remover: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfRegimeExists(id) == 0);

    if(checkIfRegimesBeingUsed(id) == 1){
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        printc("\n[red]Não é possível remover este regime, pois existem utilizadores que o estão a usar![/red]\n");
        printf("\nDeseja mover os utilizadores para outro regime? (1 - Sim, 0 - Nao): ");
        int op;
        scanf("%d", &op);
        if (op == 1){
            flag = 0;
            fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
            listarRegimes();
            do{
                if(flag == 1)
                    printc("\n[red]Por favor insira um ID válido![/red]\n");

                printf("\n\nPor favor Introduza o ID do regime que pretende mover: ");
                scanf("%d", &new_id);
                flag = 1;
            }while (checkIfRegimeExists(new_id) == 0 || new_id == id);
            masiveRegimeChange(id, new_id);
        }
        else{
            return;
        }
    }

    int position = 0;
    for (int i = 0; i <= n_regimes; i++){
        if (id == regimes[i].id){
            position = i;
            break;
        }
    }

    for(int i = position; i < n_regimes; i++){
        regimes[i] = regimes[i+1];
    }
    n_regimes--;
    regimes = realloc(regimes, n_regimes * sizeof(regimeStruct));
    saveBinRegimes();
}