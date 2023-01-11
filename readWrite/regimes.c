#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern permissionFileStruct *perms_file;
extern int n_alunos, n_regimes, n_courses;

regimeStruct *getAllRegimes(AlunoFileStruct *alunosFile){
    regimeStruct *regimes = malloc(sizeof(regimeStruct));
    for (int i = 0; i < n_alunos; i++){
        int found = 0;
        for (int j = 0; j < n_regimes; j++){
            if (strcmp(alunosFile[i].regime, regimes[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            regimes = realloc(regimes, (n_regimes+1)*sizeof(regimeStruct));
            regimes[n_regimes].id = n_regimes+1;
            regimes[n_regimes].name = malloc((strlen(alunosFile[i].regime)+1));
            strcpy(regimes[n_regimes].name, alunosFile[i].regime);
            n_regimes = n_regimes+1;
        }
    }
    return regimes;
}

void saveBinRegimes(){
    FILE *file = fopen("data/bin/regimes.bin","wb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]regimes.bin[/red]\n\n");
        exit(1);
    }

    for (int i = 0; i < n_regimes; i++){
        fwrite(&regimes[i].id, sizeof(int), 1, file);
        size_t regimeLen = strlen(regimes[i].name) + 1;
        fwrite(&regimeLen, sizeof(size_t), 1, file);
        fwrite(regimes[i].name, regimeLen, 1, file);
    }
    fclose(file);
}

void readBinRegimes(){
    regimes = malloc(sizeof(regimeStruct));
    int i;
    FILE *file = fopen("data/bin/regimes.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]regimes.bin[/red] \n\n");
    }
    else{
        for (i = 0;; i++){
            regimes = realloc(regimes, (i+1)*sizeof(regimeStruct));
            if(fread(&regimes[i].id, sizeof(int), 1, file) != 1) break;

            size_t regimeLen;
            fread(&regimeLen, sizeof(size_t), 1, file);
            regimes[i].name = malloc(regimeLen);
            fread(regimes[i].name, regimeLen, 1, file);
        }
        n_regimes = i;
    }
    fclose(file);
}

regimeStruct getRegimeByID(int id){
    for (int i = 0; i < n_regimes; i++){
        if (regimes[i].id == id){
            return regimes[i];
        }
    }
    regimeStruct none;
    none.id = -1;
    none.name = malloc(12);
    strcpy(none.name, "Não existe!");
    return none;
}

void listarRegimes(){
    printf("\nListagem de todos os Regimes:\n");
    for (int i = 0; i < n_regimes; i++){
        printf("\nID: %d Regime: %s\n", regimes[i].id, regimes[i].name);
    }
}

void listarRegimesPermissoes(){
    printf("\nListagem de todos os Regimes:\n");
    for (int i = 0; i < n_regimes; i++){
        printf("\nID: %d Regime: %s\n", regimes[i].id, regimes[i].name);
        printf("\nPermissoes:");
        printf("\nTem permissao para Menu Exames - %d", perms_file[i].perm.MenuExames);
        printf("\nTem permissao para Ver Disciplinas %d", perms_file[i].perm.VerDisciplinas);
        printf("\nTem permissao para Menu Professor %d", perms_file[i].perm.MenuProfessor);
        printf("\nTem permissao para Menu Admin %d", perms_file[i].perm.MenuAdmin);
        printf("\nTem permissao para Menu Salas %d", perms_file[i].perm.MenuSalas);
        printf("\nTem permissao para Criar Exames %d", perms_file[i].perm.CriarExames);
        printf("\nTem permissao para Inscritos Exames %d", perms_file[i].perm.InscritosExames);
        printf("\nTem permissao para Listar Exames %d", perms_file[i].perm.ListarExames);
        printf("\nTem permissao para Listar Exames Inscritos %d", perms_file[i].perm.ListarExamesInscritos);
        printf("\nTem permissao para Editar Exames %d", perms_file[i].perm.EditarExames);
        printf("\nTem permissao para Exportar Exames %d", perms_file[i].perm.ExportarExames);
        printf("\nTem permissao para Inscrever Exames %d", perms_file[i].perm.InscreverExames);
        printf("\nTem permissao para Criar Salas %d", perms_file[i].perm.CriarSalas);
        printf("\nTem permissao para Listar Salas %d", perms_file[i].perm.ListarSalas);
        printf("\nTem permissao para Editar Salas %d", perms_file[i].perm.EditarSalas);
        printf("\nTem permissao para Remover Salas %d", perms_file[i].perm.RemoverSalas);
        printf("\nTem permissao para Criar Professor %d", perms_file[i].perm.CriarProfessor);
        printf("\nTem permissao para Listar Professor %d", perms_file[i].perm.ListarProfessor);
        printf("\nTem permissao para Editar Professor %d", perms_file[i].perm.EditarProfessor);
        printf("\nTem permissao para Remover Professor %d", perms_file[i].perm.RemoverProfessor);
        printf("\nTem permissao para Menu Cursos %d", perms_file[i].perm.MenuCursos);
        printf("\nTem permissao para Menu Alunos %d", perms_file[i].perm.MenuAlunos);
        printf("\nTem permissao para Menu Regimes %d", perms_file[i].perm.MenuRegimes);
        printf("\nTem permissao para Criar Cursos %d", perms_file[i].perm.CriarCursos);
        printf("\nTem permissao para Listar Cursos %d", perms_file[i].perm.ListarCursos);
        printf("\nTem permissao para Editar Cursos %d", perms_file[i].perm.EditarCursos);
        printf("\nTem permissao para Remover Cursos %d", perms_file[i].perm.RemoverCursos);
        printf("\nTem permissao para Listar Cursos Disciplinas %d", perms_file[i].perm.ListarCursosDisciplinas);
        printf("\nTem permissao para MenuDisciplinas %d\n", perms_file[i].perm.MenuDisciplinas);
    }
}

int checkIfRegimeExists(int id){
    for (int i = 0; i < n_regimes; i++){
        if (regimes[i].id == id){
            return 1;
        }
    }
    return 0;
}

int checkIfRegimesBeingUsed(int id){
    for (int i = 0; i < n_alunos; i++){
        if (alunos[i].id_regime == id){
            return 1;
        }
    }
    return 0;
}

void masiveRegimeChange(int id, int new_id){
    for (int i = 0; i < n_alunos; i++){
        if (alunos[i].id_regime == id){
            alunos[i].id_regime = new_id;
        }
    }
    saveBinRegimes();
    updateUser();
}