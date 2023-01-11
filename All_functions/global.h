#include "structs.h"
#include <stdbool.h>

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
int isletter_cheker(char *str);
void timeNow();
void diferencaTempo(int ano, int mes, int dia, int hora, int minuto);

//alunosTxt.c
AlunoFileStruct* getTxt();
void ConvertAluno(AlunoFileStruct *alunosFile);

//alunos.c
void saveBinAlunos();
void printAlunos();
void readBinAlunos();
void login(char *email, char *password);
void getUserDataByID(int id);
void printfUserData();
int checkIfUserExists(int id);
int generateUserID();
void getUserDataByIDProf(int id);

//courses.c
void getAllCourses(AlunoFileStruct *alunosFile);
courseStruct getCourseByID(int id);

//regimes.c
regimeStruct *getAllRegimes(AlunoFileStruct *alunosFile);
void saveBinRegimes();
void readBinRegimes();
regimeStruct getRegimeByID(int id);
void listarRegimes();
void listarRegimesPermissoes();
int checkIfRegimeExists(int id);

//permissions.c
void saveAndSetPermissionsBinByTxt();
void readBinPermissions();
void saveBinPermissions();
PermissionsType getPermissionsByID(int id);

//menus.c
void MenuCursos();
int mainMenu();
void MenuAlunos();
void MenuAdmin();
int MenuEditarConta();
void MenuPrincipal();
int importExportMenu();
void MenuDisciplinas();
void MenuEditarAdicionarRemoverDisciplinas();
void MenuFilesNovos();
int menuEditAluno();
void MenuSalas();
void MenuProfessor();
void MenuExames();
void MenuRegimes();
void editarRegimeMenu();

//importExport.c
void importExportData();
void importDataTxtBin();

//salas.c
void InitSalas();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void criarSalainit();//Apenas necessario primeira vez
void criarSala();
void listarSalas();
void readBinSalas();
void editarSala();
void removerSala();
int CheckIFsalaExist(char *nomeSala, int nSala);
void saveBinSalas();

//disciplinas.c
/* void InitDisciplinas(); *///Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void ReadBinDisciplinas();//Apenas necessario primeira vez(ja vamos ter o ficheiro que podemos binario)
void SaveBinDisciplinas();
void ReadTxtDisciplinas();

//cursosdisciplinas.c
void getAllCourses(AlunoFileStruct *alunosFile);//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
int InitCursos();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void ReadBinCursosDisciplina();
void SaveBinCursosDisciplina();


//UnidadesCurriculares.c
void criardisciplinas();
void ListarDisciplinas();
void ListarPropriasDisciplinas();
void CriarDisciplina();
void RemoverDisciplina();
void EditarDisciplina();
//--------------------------------------------
void ListarCursosDisciplinas();
void RemoverDisciplinaFromCursos(char* name);
void EditarDisciplinaFromCursos(char *NameOriginal,char *nameNovo);
//--------------------------------------------
void ListarCursos();
void CriarCurso();
void EditarCursos();
void RemoverCursos();
void realocarMatriz(int idCurso);
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
void editAccount();
void updateUser();


//ficheiros.c
int fileExistAll();
bool folderExists();

//main.c
void readData();

//admin.c
void listarTodosAlunos();
void listarAluno();
void criarAluno();
void alterarAluno();
void apagarAluno();

//exames.c
void criarExame();
void zerarExame();
void listarExames();
int CheckDiscInCurso(int id, int n_Exame);
void SalasOcupada();
void mostrarSalasLivres();
void inscreverExame();
void contarInscrito(int id);
void listarInscritos(int id);
void listarExamesdeumAluno();
void removerIncricao();
void vagaMais(int salaId, char *SalaNome);
void vagaMenos(int salaId, char *SalaNome);
void saveBinExames();
void readBinExames();

//regime.c on MenuOpcao
void criarRegime();
void editarNomeRegime();
void editarPermissoesRegime();
void removerRegime();