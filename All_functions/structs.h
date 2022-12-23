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
    char *AnoDisciplina[3][10];
} courseStruct;

typedef struct {
    char *name;
    int id_regime, year, id, id_course;
} AlunoStruct;


typedef struct {
    char *name, *regime, *course;
    int year, id;
} AlunoFileStruct;
