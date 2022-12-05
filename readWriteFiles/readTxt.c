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

void orderByName(AlunoFile *alunos, int n_alunos) {
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

            //Name
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

    /* fwrite(&n_linhas_lidas, sizeof(int), 1, file); */
    for (int i = 0; i < n_linhas_lidas; i++){
        fwrite(&alunosFile[i], sizeof(AlunoFile), 1, file);
    }

    fclose(file);
}

void readBin(){
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile));
    FILE *file = fopen("../data/bin/students.bin","rb");
    if (!file) {
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        return -1;
    }

    /* fread(&n_linhas_lidas, sizeof(int), 1, file); */
    /* for (int i = 0; i < n_linhas_lidas; i++){
        fread(&alunosFile[i], sizeof(AlunoFile), 1, file);
    } */
    int i = 0;
    while(fread(alunosFile, sizeof(AlunoFile),1,file)){
        printf("\nLinha read %d: %s\t%s\t%d\t%d\t%s", i+1, alunosFile[i].nome, alunosFile[i].role, alunosFile[i].ano, alunosFile[i].id, alunosFile[i].course);
        i++;
    }

    /* for (int i = 0; i < n_linhas_lidas; i++){
        printf("\nLinha read %d: %s\t%s\t%d\t%d\t%s", i+1, alunosFile[i].nome, alunosFile[i].role, alunosFile[i].ano, alunosFile[i].id, alunosFile[i].course);
    }
 */
    fclose(file);
}

void main(){
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile));
    int n_linhas_lidas = 0;
    alunosFile = getTxt(alunosFile, &n_linhas_lidas);  
    orderByName(alunosFile, n_linhas_lidas);
    saveBin(alunosFile, n_linhas_lidas);
    readBin();
}