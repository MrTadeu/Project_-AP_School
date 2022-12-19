#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h" 

/* AlunoStruct *GetAllAlunos(){
    AlunoStruct *alunos = malloc(sizeof(AlunoStruct));
    FILE *file = fopen("data/bin/alunos.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro alunos.bin\n\n");
        exit(1);
    }

    for (int i = 0;; i++){
        if(fread(&alunos[i].id, sizeof(int), 1, file) != 1) break;
        fread(&alunos[i].ano, sizeof(int), 1, file);
        fread(&alunos[i].id_role, sizeof(int), 1, file);
        fread(&alunos[i].id_course, sizeof(int), 1, file);

        size_t nameLen;
        fread(&nameLen, sizeof(size_t), 1, file);
        alunos[i].nome = malloc(nameLen);
        fread(alunos[i].nome, nameLen, 1, file);

        size_t emailLen;
        fread(&emailLen, sizeof(size_t), 1, file);
        alunos[i].email = malloc(emailLen);
        fread(alunos[i].email, emailLen, 1, file);

        size_t passwordLen;
        fread(&passwordLen, sizeof(size_t), 1, file);
        alunos[i].password = malloc(passwordLen);
        fread(alunos[i].password, passwordLen, 1, file);

        alunos = realloc(alunos, sizeof(AlunoStruct) * (i + 2));
    }
    fclose(file);
    return alunos;
} */

AlunoStruct readBinAluno(int id_aluno){
    AlunoStruct aluno;

    FILE *file_alunos = fopen("data/bin/alunos.bin","rb");
    if (!file_alunos) {
        printf("\n\n\tImpossivel abrir Ficheiro alunos.bin\n\n");
        exit(1);
    }
    FILE *file_roles = fopen("data/bin/roles.bin","rb");
    if (!file_roles) {
        printf("\n\n\tImpossivel abrir Ficheiro roles.bin\n\n");
        exit(1);
    }
    FILE *file_course = fopen("data/bin/course.bin","rb");
    if (!file_course) {
        printf("\n\n\tImpossivel abrir Ficheiro course.bin\n\n");
        exit(1);
    }


    for (int i = 0;; i++){
        if(fread(&aluno.id, sizeof(int), 1, file_alunos) != 1) break;
        if (aluno.id == id_aluno){

            //GET ALUNO DATA FROM FILE
            fread(&aluno.year, sizeof(int), 1, file_alunos);
            fread(&aluno.id_role, sizeof(int), 1, file_alunos);
            fread(&aluno.id_course, sizeof(int), 1, file_alunos);

            size_t nameLen;
            fread(&nameLen, sizeof(size_t), 1, file_alunos);
            aluno.name = malloc(nameLen);
            fread(aluno.name, nameLen, 1, file_alunos);


            for (int j = 0;; j++){
                if(fread(&aluno.id_role, sizeof(int), 1, file_roles) != 1) break;
                if (aluno.id_role == aluno.id_role){
                    size_t roleLen;
                    fread(&roleLen, sizeof(size_t), 1, file_roles);
                    aluno.name = malloc(roleLen);
                    fread(aluno.name, roleLen, 1, file_roles);
                    break;
                }
            }
            



            fclose(file_alunos);
            return aluno;
        }
    }
    fclose(file_alunos);
}