#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        return -1;
    }

    /* for (int i = 0; i < n_linhas_lidas; i++){
        fwrite(&alunosFile[i], sizeof(AlunoFile), 1, file);
    } */

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
        return -1;
    }


   /*  fseek(file, 0, SEEK_END);
    int size = ftell(file)/sizeof(AlunoFile);
    printf("size: %d", size);
    rewind(file); */
    

    for (int i = 0; ; i++){
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



    






    /* int i = 0;

    while (fread(&alunosFile[i], sizeof(AlunoFile), 1, file)){
        printf("\nLinha read %d: %s\t%s\t%d\t%d\t%s", i+1, alunosFile[i].nome, alunosFile[i].role, alunosFile[i].ano, alunosFile[i].id, alunosFile[i].course);
        i++;
    }
 */
    /* for (int i = 0; i < j-1; i++){
        printf("\nLinha read %d: %s\t%s\t%d\t%d\t%s", i+1, alunosFile[i].nome, alunosFile[i].role, alunosFile[i].ano, alunosFile[i].id, alunosFile[i].course);
    } */

    fclose(file);
}

void main(){
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile)*2);
    int n_linhas_lidas = 0;
    alunosFile = getTxt(alunosFile, &n_linhas_lidas);  
    //orderBynome(alunosFile, n_linhas_lidas);
    saveBin(alunosFile, n_linhas_lidas);
    readBin();
}