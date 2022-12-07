/*typedef struct{
    int lerAlunos, escreverAlunos, listarAlunos, deletarAlunos, lerCursos, escreverCursos, listarCursos, deletarCursos, lerRoles, escreverRoles, listarRoles, deletarRoles;
}hasPermission;*/

typedef struct{
    int id[6];
    char *name;
}permissionindividual;

typedef struct{    
permissionindividual permission[10];
}ConjuntoPermissionsStruct;

typedef struct{    
    int id;
    char *name;
    //hasPermission permission;
}role;

typedef struct{
    int id;
    char *name;
}course;

typedef struct {
    char *nome;
    int id_role, ano, id, id_course, id_permission[10];
}Aluno;

typedef struct {
    char *nome, *role, *course;
    int ano, id;
} AlunoFile;

