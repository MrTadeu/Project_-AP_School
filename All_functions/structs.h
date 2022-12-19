typedef struct{
    int lerAluno, escreverAluno, listarAluno, deletarAluno, lerCurso, escreverCurso, listarCurso, deletarCurso, lerRole, escreverRole, listarRole, deletarRole;
} PermissionsType;

typedef struct{    
    int id;
    char *name;
    PermissionsType perm;
}regimeStruct;


typedef struct{
    int id_cargo;
    PermissionsType perm;
} permissionFileStruct;


typedef struct{
    int id;
    char *name;
} courseStruct;

typedef struct {
    char *name;
    int id_role, year, id, id_course;
} AlunoStruct;


typedef struct {
    char *name, *role, *course;
    int year, id;
} AlunoFileStruct;
