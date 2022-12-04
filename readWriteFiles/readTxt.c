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

void main(){
    FILE *file = fopen("../data/alunos.txt","r");
    AlunoFile *alunosFile = malloc(sizeof(AlunoFile));
    char **filedata = malloc(50*sizeof(char *)), *linhaString = malloc(250);
    int n_linhas_lidas = 0;

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

            printf("\nA linha %d contem %d campos:\n", n_linhas_lidas, count);
            for (int i = 0; i < count; i++)
                printf("\tcampo %02d = V[%02d] = [%s]\n", i+1, i, filedata[i]);

            alunosFile = realloc(alunosFile, ((n_linhas_lidas)+1)*sizeof(AlunoFile));
            
            //Name
            alunosFile[n_linhas_lidas].nome = malloc((strlen(filedata[0])+1));
            strcpy(alunosFile[n_linhas_lidas].nome, filedata[0]);
            //Role / REGIME
            alunosFile->role = malloc((strlen(filedata[2])+1));
            strcpy(alunosFile->role, filedata[2]);
            //Year
            alunosFile->ano = atoi(filedata[3]);
            //ID / Número
            alunosFile->id = atoi(filedata[4]);
            //Course 
            alunosFile->course = malloc((strlen(filedata[1])+1));
            strcpy(alunosFile->course, filedata[1]);

            n_linhas_lidas++;
        }
        
    }
  
    fclose(file);
}