#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50], role[50], course[50];
    int year, id;
} StudentFile;

void saveBin(StudentFile *studentsFile, int lines){
    FILE *file = fopen("studentsx.bin","ab");
    if (!file) {
        printf("\n\n\tImposible to open file. \n\n");
        exit(1);
    }

    for (int i = 0; i < lines; i++){
        fwrite(&*studentsFile[i].name, sizeof(StudentFile), 1, file);
    }
    fclose(file);
}

void readBin(){
    StudentFile *studentsFile = malloc(sizeof(StudentFile)*5000);
    FILE *file = fopen("studentsx.bin","rb");
    if (!file) {
        printf("\n\n\tImposible to open file. \n\n");
        exit(1);
    }

    int j = 0;

    while (fread(&studentsFile[j], sizeof(StudentFile), 1, file)){
        printf("\nread %d: %s\t%s\t%d\t%d\t%s", j+1, studentsFile[j].name, studentsFile[j].role, studentsFile[j].year, studentsFile[j].id, studentsFile[j].course);
        j++;
    }

    fclose(file);
}

void main(){
    StudentFile *studentsFile = malloc(sizeof(StudentFile)*2);
    int lines = 0;

    strcpy(studentsFile[0].name, "John");
    strcpy(studentsFile[0].role, "Gamer");
    studentsFile[0].year = 1999;
    studentsFile[0].id = 1;
    strcpy(studentsFile[1].course, "IOT");
    strcpy(studentsFile[1].name, "Piter");
    strcpy(studentsFile[1].role, "GamerXL");
    studentsFile[1].year = 1991;
    studentsFile[1].id = 2;
    strcpy(studentsFile[1].course, "IOTXL");

    lines = 2;

    saveBin(studentsFile, lines);
    readBin();
}