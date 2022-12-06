#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/structs.h" 

AlunoFile* getTxt(AlunoFile *alunosFile, int *n_linhas_lidas){
    FILE *file = fopen("../data/alunos.txt","r");
    char **filedata = malloc(5*sizeof(char *)), *linhaString = malloc(250);

    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    int linha = 0;
    while (!feof(file)){
        fgets(linhaString,250,file);
        char *pch = strtok (linhaString, "\t\r\n");
        
        int count = 0;

        while (pch != NULL){
            filedata[count] = malloc((strlen(pch)+1));
            strcpy(filedata[count], pch);
            pch = strtok (NULL, "\t\r\n");
            count++;
        }
        alunosFile = realloc(alunosFile, ((*n_linhas_lidas)+1)*sizeof(AlunoFile));

        //nome
        alunosFile[*n_linhas_lidas].nome = malloc((strlen(filedata[0])+1));
        strcpy(alunosFile[*n_linhas_lidas].nome, filedata[0]);
        //Role / REGIME
        alunosFile[*n_linhas_lidas].role = malloc((strlen(filedata[1])+1));
        strcpy(alunosFile[*n_linhas_lidas].role, filedata[1]);
        //Year
        alunosFile[*n_linhas_lidas].ano = atoi(filedata[2]);
        //ID / Número
        alunosFile[*n_linhas_lidas].id = atoi(filedata[3]);
        //Course 
        alunosFile[*n_linhas_lidas].course = malloc((strlen(filedata[4])+1));
        strcpy(alunosFile[*n_linhas_lidas].course, filedata[4]);

        *n_linhas_lidas = *n_linhas_lidas + 1;
    }

    for (int i = 0; i < *n_linhas_lidas; i++){
        printf("\nLinha %d: %s\t%s\t%d\t%d\t%s", i+1, alunosFile[i].nome, alunosFile[i].role, alunosFile[i].ano, alunosFile[i].id, alunosFile[i].course);
    }

    fclose(file);
    return alunosFile;
}

Aluno *ConvertAluno(AlunoFile *alunosFile, int n_linhas_lidas, role *roles, int n_roles, course *courses, int n_courses){
    Aluno *alunos = malloc(sizeof(Aluno)*n_linhas_lidas);
    for (int i = 0; i < n_linhas_lidas; i++){
        alunos[i].nome = malloc((strlen(alunosFile[i].nome)+1));
        strcpy(alunos[i].nome, alunosFile[i].nome);
        alunos[i].ano = alunosFile[i].ano;
        alunos[i].id = alunosFile[i].id;
        for (int j = 0; j < n_roles; j++){
            if (strcmp(alunosFile[i].role, roles[j].name) == 0){
                alunos[i].id_role = roles[j].id;
                break;
            }
        }
        for (int j = 0; j < n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                alunos[i].id_course = courses[j].id;
                break;
            }
        }
    }
    return alunos;
}

void saveBinAlunos(Aluno *alunos, int n_linhas_lidas){
    FILE *file = fopen("../data/bin/alunos.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }
    for (int i = 0; i < n_linhas_lidas; i++){
        fwrite(&alunos[i].id, sizeof(int), 1, file);
        fwrite(&alunos[i].ano, sizeof(int), 1, file);
        fwrite(&alunos[i].id_role, sizeof(int), 1, file);
        fwrite(&alunos[i].id_course, sizeof(int), 1, file);

        size_t nomeLen = strlen(alunos[i].nome) + 1;
        fwrite(&nomeLen, sizeof(size_t), 1, file);
        fwrite(alunos[i].nome, nomeLen, 1, file);
    }
    fclose(file);
}

void printAlunos(Aluno *alunos, int n_linhas_lidas){
    for (int i = 0; i < n_linhas_lidas; i++){
        printf("ID: %d\n", alunos[i].id);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Ano: %d\n", alunos[i].ano);
        printf("ID Role: %d\n", alunos[i].id_role);
        printf("ID Course: %d\n", alunos[i].id_course);
        printf("\n");
    }
}

void setPermmissions(role* roles){
    
}

void main(){
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile));
    Aluno *alunos;
    role *roles;
    course *courses;
    int n_linhas_lidas = 0, n_roles = 0, n_courses = 0;
    alunosFile = getTxt(alunosFile, &n_linhas_lidas);

    roles = getAllRoles(alunosFile, n_linhas_lidas, &n_roles);
    saveBinRoles(roles, n_roles);
    readBinRoles();

    courses = getAllCourses(alunosFile, n_linhas_lidas, &n_courses);
    saveBinCourses(courses, n_courses);
    readBinCourses();

    alunos = ConvertAluno(alunosFile, n_linhas_lidas, roles, n_roles, courses, n_courses);
    saveBinAlunos(alunos, n_linhas_lidas);
    printAlunos(alunos, n_linhas_lidas);
    for (int i = 0; i < n_courses; i++){
        printf("%d", n_courses);
        printf("\nCURSOS ID: %d NAME: %s", courses[i].id, courses[i].name);
    }

    for (int i = 0; i < n_roles; i++){
        printf("\nREGIMES ID: %d NAME: %s", roles[i].id, roles[i].name);
    }

}
