typedef struct{
    int lerAluno, escreverAluno, listarAluno, deletarAluno, lerCurso, escreverCurso, listarCurso, deletarCurso, lerRegime, escreverRegime, listarRegime, deletarRegime;
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
} courseStruct;

typedef struct {
    char *name;
    int id_regime, year, id, id_course;
} AlunoStruct;


typedef struct {
    char *name, *regime, *course;
    int year, id;
} AlunoFileStruct;
