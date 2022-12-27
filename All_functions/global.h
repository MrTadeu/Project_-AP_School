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

//utils.c
char *lowercase(char *str);
char *uppercase(char *str);
int isdigit_cheker(char *str);
void generate_unique_numbers(int *array, int length);
char *capitalize(char *str);

//alunosTxt.c
AlunoFileStruct* getTxt(int *n_alunos);
AlunoStruct *ConvertAluno(AlunoFileStruct *alunosFile, int n_alunos, regimeStruct *regimes, int n_regimes, courseStruct *courses, int n_courses);

//alunos.c
void saveBinAlunos();
void printAlunos();
AlunoStruct *readBinAlunos();

//courses.c
courseStruct *getAllCourses(AlunoFileStruct *alunosFile);
void saveBinCourses();
courseStruct *readBinCourses();
courseStruct findCourseId(int id);

//regimes.c
regimeStruct *getAllRegimes(AlunoFileStruct *alunosFile);
void saveBinRegimes();
regimeStruct *readBinRegimes();

//permissions.c
void saveAndSetPermissionsBinByTxt(regimeStruct *regimes, int n_regimes);
permissionFileStruct* readBinPermissions();

//menus.c
int mainMenu();
int importExportMenu();
void MenuAdminCursos();
void MenuAdminDisciplinas();
void MenuAdminEditarAdicionarRemoverDisciplinas();

//importExport.c
void importExportData();
void importDataTxtBin();

//salas.c
void criarSalas();
void listarSalas();
SalaStruct* readBinSalas();
void editarSala();
void removerSalas();
int ChekeIFsalaExist(char *nomeSala, int nSala);

//disciplinas.c
disciplinasStruct* ReadTxtDisciplinas();
void ReadBinDisciplinas();//Apenas necessario primeira vez(ja vamos ter o ficheiro que podemos binario)
void SaveBinDisciplinas();
void ListarDisciplinas();
void CriarDisciplina();
void RemoverDisciplina();
void EditarDisciplina();

//DiscCursos.c
void InitCursos();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void ReadBinCursosDisciplina();
void SaveBinCursos(); 
void ListarCursosDisciplinas();
void ListarCursos();
void EditarCursos();

//DiscChecker.c
int CheckIFDisciplinaExiste(int id);
int CheckIFDisciplinaExisteNome(char *name);
int CheckIFCursoExiste(int id);
int CheckIFCursoExisteNome(char *name);
int CheckIFPessoaExiste(int id);


