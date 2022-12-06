typedef struct{
    int id_permission, enable;
}hasPermission;

typedef struct{    
    int id;
    char *name;
    hasPermission* permission;
}role;

typedef struct{
    int id;
    char name;
}permission;

typedef struct{
    int id;
    char *name;
} course;

typedef struct {
    char *nome;
    int id_role, ano, id, id_course;
} Aluno;

typedef struct {
    char *nome, *role, *course;
    int ano, id;
} AlunoFile;
