#include "structs.h"

//colorprint.c
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

//validators.c
int isdigit_cheker(char *str);
char *lowercase(char *str);
char *uppercase(char *str);

//alunosTxt.c
AlunoFileStruct* getTxt(int *n_alunos);
AlunoStruct *ConvertAluno(AlunoFileStruct *alunosFile, int n_alunos, regimeStruct *regimes, int n_regimes, courseStruct *courses, int n_courses);

//alunos.c
void saveBinAlunos(AlunoStruct *alunos, int n_alunos);
void printAlunos(AlunoStruct *alunos, int n_alunos);
AlunoStruct *readBinAlunos(int *n_alunos);

//courses.c
courseStruct *getAllCourses(AlunoFileStruct *alunosFile, int n_alunos, int *n_courses);
void saveBinCourses(courseStruct *courses, int n_courses);
courseStruct *readBinCourses(int *n_courses);

//regimes.c
regimeStruct *getAllRegimes(AlunoFileStruct *alunosFile, int n_alunos, int *n_regimes);
void saveBinRegimes(regimeStruct *regimes, int n_regimes);
regimeStruct *readBinRegimes(int *n_regimes);

//permissions.c
void saveAndSetPermissionsBinByTxt(regimeStruct *regimes, int n_regimes);
permissionFileStruct* readBinPermissions();

//menus.c
int mainMenu();
int importExportMenu();

//importExport.c
void importExportData();
void importDataTxtBin();

//salas.c
void criarSalas();
void listarSalas();
SalaStruct* readBinSalas(int *n_salas);
void editarSala();
void listarSalas();