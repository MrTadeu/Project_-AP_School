typedef struct{
    int MenuExames, VerDisciplinas, MenuProfessor, MenuAdmin, MenuSalas, CriarExames, InscritosExames, ListarExames, ListarExamesInscritos, EditarExames, ExportarExames, InscreverExames, CriarSalas, ListarSalas, EditarSalas, RemoverSalas, CriarProfessor, ListarProfessor, EditarProfessor, RemoverProfessor, MenuCursos, MenuAlunos, MenuRegimes, CriarCursos, ListarCursos, EditarCursos, RemoverCursos;
} PermissionsType;

typedef struct{    
    int id;
    char *name;
    PermissionsType perm;
}regimeStruct;


typedef struct{
    int id_regime;
    PermissionsType perm;
} permissionFileStruct;

typedef struct{
    int id;
    char *name;
} disciplinasStruct;

typedef struct{
    int id;
    char *name;
    char ***AnoDisciplina;
    int num_disciplinas[3];
    int IdResponsavel;
} courseStruct;

typedef struct {
    char *name, *email, *password;
    int id_regime, year, id, id_course;
} AlunoStruct;

typedef struct {
    char *name, *regime, *course;
    int year, id;
} AlunoFileStruct;

typedef struct { //struct para guardar os dados de uma sala
    char *nomeSala;
    int numeroSala;
    int numeroCadeiras;
}SalaStruct;

typedef struct { //struct para guardar os dados de um professor
    char *nomeProfessor;
    int IDProfessor;
    char *emailProfessor;
    char *passwordProfessor;
}professorStruct;

//USER DATA 
typedef struct {
    char *name, *email, *password;
    int id, year;
    courseStruct course;
    regimeStruct regime;
} AlunoDataStruct;