#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h" 


AlunoFileStruct* getTxt(int *n_alunos){
    AlunoFileStruct *alunosFile = malloc(sizeof(AlunoFileStruct));
    FILE *file = fopen("data/alunos.txt","r");
    char **filedata = malloc(5*sizeof(char *)), *linhaString = malloc(250);

    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]alunos.txt[/red]\n\n");
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
        alunosFile = realloc(alunosFile, ((*n_alunos)+1)*sizeof(AlunoFileStruct));

        //nome
        alunosFile[*n_alunos].name = malloc((strlen(filedata[0])+1));
        strcpy(alunosFile[*n_alunos].name, filedata[0]);
        //REGIME
        alunosFile[*n_alunos].regime = malloc((strlen(filedata[1])+1));
        strcpy(alunosFile[*n_alunos].regime, filedata[1]);
        //Year
        alunosFile[*n_alunos].year = atoi(filedata[2]);
        //ID / Número
        alunosFile[*n_alunos].id = atoi(filedata[3]);
        //Course 
        alunosFile[*n_alunos].course = malloc((strlen(filedata[4])+1));
        strcpy(alunosFile[*n_alunos].course, filedata[4]);

        *n_alunos = *n_alunos + 1;
    }

    fclose(file);
    return alunosFile;
}

AlunoStruct *ConvertAluno(AlunoFileStruct *alunosFile, int n_alunos, regimeStruct *regimes, int n_regimes, courseStruct *courses, int n_courses){
    AlunoStruct *alunos = malloc(sizeof(AlunoStruct)*n_alunos);
    for (int i = 0; i < n_alunos; i++){
        char *email = malloc(100), *password = malloc(100);
        //email example: pv25207@estgv.ipv.pt
        strcat(email, "pv");
        strcat(email, alunos[i].id);
        strcat(email, "@estgv.ipv.pt");
        //password example: pv25207ee
        strcat(password, "pv");
        strcat(password, alunos[i].id);
        strcat(password, (findCourseId(alunos[i].id_course)).name);


        alunos[i].email = malloc((strlen(email)+1));
        strcpy(alunos[i].email, email);



        alunos[i].name = malloc((strlen(alunosFile[i].name)+1));
        strcpy(alunos[i].name, alunosFile[i].name);
        alunos[i].year = alunosFile[i].year;
        alunos[i].id = alunosFile[i].id;
        for (int j = 0; j < n_regimes; j++){
            if (strcmp(alunosFile[i].regime, regimes[j].name) == 0){
                alunos[i].id_regime = regimes[j].id;
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