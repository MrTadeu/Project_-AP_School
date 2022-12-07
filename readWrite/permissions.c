
typedef struct{
    int lerAlunos, escreverAlunos, listarAlunos, deletarAlunos, lerCursos, escreverCursos, listarCursos, deletarCursos, lerRoles, escreverRoles, listarRoles, deletarRoles;
}hasPermission;

/* typedef struct{
    rolesID registo, listarAlunos, deletarAlunos;
}prmissionsTipe; */
typedef struct{    
    int id;
    char *name;
    hasPermission permission;
}role;
typedef struct {
    char *nome;
    int id_role, ano, id, id_course;
}Aluno;

void permissions(){
    
}