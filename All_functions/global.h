#include "structs.h"

/* <-------------------------------- Printcolor --------------------------------> */
#ifndef CJAG_COLORPRINT
#define CJAG_COLORPRINT

#define ERROR_TAG "[r][ERROR][/r] "

void printc(const char *fmt, ...);

void spinner_start(unsigned int type, const char* fmt, ...);
void spinner_update(const char* fmt, ...);
void spinner_done(const char* fmt, ...);

void progress_start(int max, char* fmt);
void progress_update();

#endif

/* <-------------------------------- /Printcolor --------------------------------> */

/* <-------------------------------- functionsString --------------------------------> */
int isdigit_cheker(char *str);
char *lowercase(char *str);
char *uppercase(char *str);

/* <-------------------------------- /functionsString --------------------------------> */

/* <-------------------------------- readWrite --------------------------------> */
AlunoFileStruct* getTxt(AlunoFileStruct *alunosFile, int *n_linhas_lidas);
AlunoStruct *ConvertAluno(AlunoFileStruct *alunosFile, int n_linhas_lidas, regimeStruct *regimes, int n_regimes, courseStruct *courses, int n_courses);
void saveBinAlunos(AlunoStruct *alunos, int n_linhas_lidas);
courseStruct *getAllCourses(AlunoFileStruct *alunosFile, int n_linhas_lidas, int *n_courses);
void saveBinCourses(courseStruct *courses, int n_courses);
courseStruct *readBinCourses();
regimeStruct *getAllRegimes(AlunoFileStruct *alunosFile, int n_linhas_lidas, int *n_regimes);
void saveBinRegimes(regimeStruct *regimes, int n_regimes);
regimeStruct *readBinRegimes();
void printAlunos(AlunoStruct *alunos, int n_linhas_lidas);
void setPermissionsBinByTxt(regimeStruct *regimes, int n_regimes);
permissionFileStruct* readBinPermissions(int *n_perms);
AlunoStruct readBinAluno(int id_aluno);
/* <-------------------------------- /readWrite --------------------------------> */


