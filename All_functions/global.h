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
void login(char *email, char *password);
void getUserDataByID(int id);
void printfUserData();

//courses.c
void getAllCourses(AlunoFileStruct *alunosFile);
courseStruct getCourseByID(int id);

//regimes.c
regimeStruct *getAllRegimes(AlunoFileStruct *alunosFile);
void saveBinRegimes();
regimeStruct *readBinRegimes();
regimeStruct getRegimeByID(int id);

//permissions.c
void saveAndSetPermissionsBinByTxt(regimeStruct *regimes, int n_regimes);
permissionFileStruct* readBinPermissions();
PermissionsType getPermissionsByID(int id);

//menus.c
int mainMenu();
void MenuPrincipal();
int importExportMenu();
void MenuDisciplinas();
void MenuEditarAdicionarRemoverDisciplinas();

//importExport.c
void importExportData();
void importDataTxtBin();

//salas.c
void criarSala();
void listarSalas();
void readBinSalas();
void editarSala();
void removerSalas();
int ChekeIFsalaExist(char *nomeSala, int nSala);

//disciplinas.c
void InitDisciplinas();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void ReadBinDisciplinas();//Apenas necessario primeira vez(ja vamos ter o ficheiro que podemos binario)
void SaveBinDisciplinas();

//cursosdisciplinas.c
void getAllCourses(AlunoFileStruct *alunosFile);//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
int InitCursos();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void ReadBinCursosDisciplina();
void SaveBinCursosDisciplina();


//UnidadesCurriculares.c
void ListarDisciplinas();
void ListarPropriasDisciplinas();
void CriarDisciplina();
void RemoverDisciplina();
void EditarDisciplina();
//--------------------------------------------
void ListarCursosDisciplinas();
void RemoverDisciplinaFromCursos(char* name);
void AdicionarDisciplinaToCursos(char* nameCurso, char* nomeDisciplina);
void EditarDisciplinaFromCursos(char *NameOriginal,char *nameNovo);
//--------------------------------------------
void ListarCursos();
void CriarCurso();
void EditarCursos();
void RemoverCursos();
//--------------------------------------------
int CheckIFDisciplinaExiste(int id);
int CheckIFDisciplinaExisteNome(char *name);
int CheckIFCursoExiste(int id);
int CheckIFCursoExisteNome(char *name);
int CheckIFProfessor(int id);

//professores.c
void criarProfessor();
void readBinProfessores();
void listarProfessor();
void editarProfessor();
void removerProfessor();
void saveBinProfessor();

//currentUser.c
void changeName();
void changePassword();
