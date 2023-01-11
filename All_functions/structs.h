typedef struct{
    int MenuExames, VerDisciplinas, MenuProfessor, MenuAdmin, MenuSalas, CriarExames, InscritosExames, ListarExames, ListarExamesInscritos, EditarExames, ExportarExames, InscreverExames, CriarSalas, ListarSalas, EditarSalas, RemoverSalas, CriarProfessor, ListarProfessor, EditarProfessor, RemoverProfessor, MenuCursos, MenuAlunos, MenuRegimes, CriarCursos, ListarCursos, EditarCursos, RemoverCursos, ListarCursosDisciplinas, MenuDisciplinas;
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
    int IdDiretor;
} courseStruct;

typedef struct {
    char *name, *email, *password;
    int id_regime, year, id, id_course, *exames;
} AlunoStruct;

typedef struct {
    char *name, *regime, *course;
    int year, id;
} AlunoFileStruct;

typedef struct { //struct para guardar os dados de uma reserva
    int dia; 
    int mes;
    int ano;
    int hora;
    int minuto;
    int diaFinal; 
    int mesFinal;
    int anoFinal;
    int horaFinal;
    int minutoFinal;
    int salaReservada;
    int id_exame;
    int id_reserva;
    int vagas;
}Reservas;    

typedef struct { //struct para guardar os dados de uma sala
    char *nomeSala;
    int numeroSala;
    int numeroCadeiras;
    int id;
    Reservas *reservas;
    int n_reservas;
}SalaStruct;

typedef struct { //struct para guardar os dados de um professor
    char *nomeProfessor;
    int id, id_regime;
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

//EXAMES
typedef struct{
    int dia, mes, hora, minuto, ano;
}tempoExames;

typedef struct{
    int hora, minuto;
}duracao;

typedef struct{
    int max_inscritos, *ids_inscritos, professor, SalaNum, regime, id, curso, inscritos;
    char *disciplina, *SalaNome;
    duracao duracao;
    tempoExames data;
}Exames;

//dia, mes, hora, minuto //utils.c

typedef struct{
    int difMes, difDia, difHora, difMinuto;
}TempoAnoAtualDiferenca;

typedef struct{
    int year;
    int month;
    int day;
    int hour;
    int minute;
}Date;