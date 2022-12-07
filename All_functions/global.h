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

/* <-------------------------------- /functionsString --------------------------------> */

/* <-------------------------------- readWrite --------------------------------> */
AlunoFile *readFile(char *filename, int *n_linhas_lidas);

void saveBinAlunos(AlunoFile *alunosFile, int n_linhas_lidas);

AlunoFile *readBinAlunos();

void saveBinRoles(role *roles, int n_roles);

role *readBinRoles();

role *getAllRoles(AlunoFile *alunosFile, int n_linhas_lidas, int *n_roles);

/* <-------------------------------- /readWrite --------------------------------> */


