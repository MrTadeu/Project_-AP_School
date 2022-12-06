#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    int id_permission, enable;
}hasPermission;

typedef struct{    
    int id;
    char *name;
    hasPermission* permission;
}role;

typedef struct{
    int id;
    char name;
}permission;

typedef struct{
    int id;
    char *name;
} course;

typedef struct {
    char *nome;
    int id_role, ano, id, id_course;
} Aluno;

typedef struct {
    char *nome, *role, *course;
    int ano, id;
} AlunoFile;



void orderBynome(AlunoFile *alunos, int n_alunos) {
    int i, j;
    AlunoFile aux;
    for (i = 0; i < n_alunos; i++) {
        for (j = i + 1; j < n_alunos; j++) {
            if (strcmp(alunos[i].nome, alunos[j].nome) > 0) {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}

AlunoFile* getTxt(AlunoFile *alunosFile, int *n_linhas_lidas){
    FILE *file = fopen("../data/alunos.txt","r");
    char **filedata = malloc(50*sizeof(char *)), *linhaString = malloc(250);

    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        return -1;
    }

    int linha = 0;
    while (!feof(file)){
        if (fgets(linhaString,250,file) != NULL){
            char *pch = strtok (linhaString, "\t\r\n");
            
            int count = 0;

            while (pch != NULL){
                filedata[count] = malloc((strlen(pch)+1));
                strcpy(filedata[count], pch);
                pch = strtok (NULL, "\t \r\n");
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
    }

    for (int i = 0; i < *n_linhas_lidas; i++){
        printf("\nLinha %d: %s\t%s\t%d\t%d\t%s", i+1, alunosFile[i].nome, alunosFile[i].role, alunosFile[i].ano, alunosFile[i].id, alunosFile[i].course);
    }

    fclose(file);
    return alunosFile;
}

void saveBin(AlunoFile *alunosFile, int n_linhas_lidas){
    FILE *file = fopen("../data/bin/students.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0; i < n_linhas_lidas; i++){
        size_t nomeLen = strlen(alunosFile[i].nome) + 1;
        fwrite(&nomeLen, sizeof(size_t), 1, file);
        fwrite(alunosFile[i].nome, nomeLen, 1, file);

        size_t roleLen = strlen(alunosFile[i].role) + 1;
        fwrite(&roleLen, sizeof(size_t), 1, file);
        fwrite(alunosFile[i].role, roleLen, 1, file);

        size_t courseLen = strlen(alunosFile[i].course) + 1;
        fwrite(&courseLen, sizeof(size_t), 1, file);
        fwrite(alunosFile[i].course, courseLen, 1, file);

        fwrite(&alunosFile[i].ano, sizeof(int), 1, file);
        fwrite(&alunosFile[i].id, sizeof(int), 1, file);
    }
    fclose(file);fclose(file);
}



void readBin(){
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile)*5000);
    FILE *file = fopen("../data/bin/students.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0;; i++){
        size_t nameLen;
        if(fread(&nameLen, sizeof(size_t), 1, file) != 1) break;
        char *name = malloc(nameLen);
        fread(name, nameLen, 1, file);
        size_t roleLen;
        fread(&roleLen, sizeof(size_t), 1, file);
        char *role = malloc(roleLen);
        fread(role, roleLen, 1, file);
        size_t courseLen;
        fread(&courseLen, sizeof(size_t), 1, file);
        char *course = malloc(courseLen);
        fread(course, courseLen, 1, file);
        int year;
        fread(&year, sizeof(int), 1, file);
        int id;
        fread(&id, sizeof(int), 1, file);

        printf("\nLine read %d: %s\t%s\t%d\t%d\t%s", i+1, name, role, year, id, course);
    }

    fclose(file);
}

role *getAllRoles(AlunoFile *alunosFile, int n_linhas_lidas, int *n_roles){
    role *roles = malloc(sizeof(role));
    int id_role = 1;
    for (int i = 0; i < n_linhas_lidas; i++){
        int found = 0;
        for (int j = 0; j < *n_roles; j++){
            if (strcmp(alunosFile[i].role, roles[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            roles = realloc(roles, ((*n_roles)+1)*sizeof(role));
            roles[*n_roles].id = id_role++;
            roles[*n_roles].name = malloc((strlen(alunosFile[i].role)+1));
            strcpy(roles[*n_roles].name, alunosFile[i].role);
            *n_roles=*n_roles+1;
        }
    } 
    return roles;
}

void saveBinRoles(role *roles, int n_roles){
    FILE *file = fopen("../data/bin/roles.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0; i < n_roles; i++){
        fwrite(&roles[i].id, sizeof(int), 1, file);

        size_t roleLen = strlen(roles[i].name) + 1;
        fwrite(&roleLen, sizeof(size_t), 1, file);
        fwrite(roles[i].name, roleLen, 1, file);
    }
    fclose(file);
}

role *readBinRoles(){
    role *roles = malloc(sizeof(role));
    FILE *file = fopen("../data/bin/roles.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0;; i++){
        roles = realloc(roles, (i+1)*sizeof(role));
        if(fread(&roles[i].id, sizeof(int), 1, file) != 1) break;

        size_t roleLen;
        fread(&roleLen, sizeof(size_t), 1, file);
        roles[i].name = malloc(roleLen);
        fread(roles[i].name, roleLen, 1, file);
    }
    fclose(file);
    return roles;
}

course *getAllCourses(AlunoFile *alunosFile, int n_linhas_lidas, int *n_courses){
    course *courses = malloc(sizeof(course));
    int id_course = 1;
    for (int i = 0; i < n_linhas_lidas; i++){
        int found = 0;
        for (int j = 0; j < *n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            courses = realloc(courses, ((*n_courses)+1)*sizeof(course));
            courses[*n_courses].id = id_course++;
            courses[*n_courses].name = malloc((strlen(alunosFile[i].course)+1));
            strcpy(courses[*n_courses].name, alunosFile[i].course);
            *n_courses=*n_courses+1;
        }
    } 
    return courses;
}

void saveBinCourses(course *courses, int n_courses){
    FILE *file = fopen("../data/bin/courses.bin","ab");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0; i < n_courses; i++){
        fwrite(&courses[i].id, sizeof(int), 1, file);

        size_t courseLen = strlen(courses[i].name) + 1;
        fwrite(&courseLen, sizeof(size_t), 1, file);
        fwrite(courses[i].name, courseLen, 1, file);
    }
    fclose(file);
}

course *readBinCourses(){
    course *courses = malloc(sizeof(course));
    FILE *file = fopen("../data/bin/courses.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        exit(1);
    }

    for (int i = 0;; i++){
        courses = realloc(courses, (i+1)*sizeof(course));
        if(fread(&courses[i].id, sizeof(int), 1, file) != 1) break;

        size_t courseLen;
        fread(&courseLen, sizeof(size_t), 1, file);
        courses[i].name = malloc(courseLen);
        fread(courses[i].name, courseLen, 1, file);
    }
    fclose(file);
    return courses;
}


void main(){
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile)*2);
    role *roles;
    course *courses;
    int n_linhas_lidas = 0, n_roles = 0, n_courses = 0;
    alunosFile = getTxt(alunosFile, &n_linhas_lidas);
    //orderBynome(alunosFile, n_linhas_lidas);


    roles = getAllRoles(alunosFile, n_linhas_lidas, &n_roles);
    saveBinRoles(roles, n_roles);
    readBinRoles();

    courses = getAllCourses(alunosFile, n_linhas_lidas, &n_courses);
    saveBinCourses(courses, n_courses);
    readBinCourses();

    saveBin(alunosFile, n_linhas_lidas);
    readBin();
}
