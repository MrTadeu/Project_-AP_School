#include <stdio.h>
#include <stdlib.h>
#include "../All_functions/global.h"
#include <windows.h>


/* typedef struct{
    int dia, mes, hora, minuto;
}tempoExames;

typedef struct{
    int max_inscritos,*ids_inscritos, disciplina, professor, sala, regime, id;
    tempoExames data;
}Exames; */

extern Exames* exame;
extern SalaStruct *salas;
extern AlunoDataStruct aluno;
extern courseStruct *courses;
extern int n_exames, n_salas, n_alunos, n_courses;

//NUMERO MAXIMO DE INSCRITOS?? NUMERO DE INSCRITOS = NUMERO DE VAGAS NECESSARIAS 

void criarExame(){
    exame = realloc(exame, sizeof(Exames)*(n_exames+1));
    zerarExame(n_exames);

    exame[n_exames].disciplina = malloc(100);
    exame[n_exames].id = n_exames+1;
    exame[n_exames].professor = aluno.id;
    printf("Qual é o número máximo de inscritos? ");
    scanf("%d", &exame[n_exames].max_inscritos);
    exame[n_exames].ids_inscritos = malloc(sizeof(int)*exame[n_exames].max_inscritos);
    for(int i=0;i<exame[n_exames].max_inscritos;i++)
        exame[n_exames].ids_inscritos[i] = 0;

    do{
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    ListarDisciplinas();
    printf("Para qual disciplina pretende criar um exame? Insira o nome da disciplina:");
    scanf("%s", exame[n_exames].disciplina);
    exame[n_exames].disciplina = realloc(exame[n_exames].disciplina, (strlen(exame[n_exames].disciplina)+1));
    uppercase(exame[n_exames].disciplina);
    if(CheckIFDisciplinaExisteNome(exame[n_exames].disciplina) == -1){
        printc("[red]Disciplina não existe![/red]");
        Sleep(1000);
    }
    }while(CheckIFDisciplinaExisteNome(exame[n_exames].disciplina) == -1);
    /* void criarExame();
void zerarExame();
void listarExames();
int CheckDiscInCurso(int id);
void SalasOcupada();
void mostrarSalasLivres();
void inscreverExame();
void contarInscrito(int id);
void listarInscritos(int id);
void listarExamesdeumAluno();
void removerIncricao();
void vagaMais(int salaId);
void vagaMenos(int salaId);
void saveBinExames();
void readBinExames(); */


    do{
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        ListarCursos();
        printf("Para que curso estará disponivel? Insira o ID do curso:");
        scanf("%d", &exame[n_exames].curso);
        if(CheckIFCursoExiste(exame[n_exames].curso) == -1){
            printc("[red]Curso não existe![/red]");
            Sleep(1000);
        }
    }while(CheckIFCursoExiste(exame[n_exames].curso) == -1 || CheckDiscInCurso(exame[n_exames].curso) == -1);

    
    SalasOcupada();
    mostrarSalasLivres();
    printf("Para que sala pretende criar um exame? ");
    scanf("%d", &exame[n_exames].sala);
    SalasOcupada();
    
    printf("Qual a data do exame (formato DD MM)? ");
    scanf("%d %d", &exame[n_exames].data.dia, &exame[n_exames].data.mes);

    printf("Qual a hora do exame (formato HH MM)? ");
    scanf("%d %d", &exame[n_exames].data.hora, &exame[n_exames].data.minuto);
    
    n_exames++;
    saveBinExames();
}

int CheckDiscInCurso(int id)
{
    for(int i = 0; i < n_courses; i++){
        if(courses[i].id == id){
            for(int j = 0; j < 3; j++){
                for (int k = 0; k < courses[i].num_disciplinas[j]; k++){
                    if(strcmp(courses[i].AnoDisciplina[j][k] , exame[id].disciplina))
                        return 1;
                }
            }
        }
    }
    return -1;
}

void zerarExame(int i)
{
    exame[i].max_inscritos = 0;
    exame[i].disciplina = 0;
    exame[i].professor = 0;
    exame[i].sala = 0;
    exame[i].regime = 0;
    exame[i].id = 0;
    exame[i].data.dia = 0;
    exame[i].data.mes = 0;
    exame[i].data.hora = 0;
    exame[i].data.minuto = 0;
}

void listarExames(){
    for(int i=0;i<n_exames;i++)
        printf("ID: %d\tDisciplina: %d\tSala: %d\tData: %d\tHora: %d\n",exame[i].id,exame[i].disciplina,exame[i].sala,exame[i].data.dia,exame[i].data.mes,exame[i].data.hora,exame[i].data.minuto);
}

void SalasOcupada()
{
    for(int i=0;i<n_exames;i++){
        for(int j=0;j<n_salas;j++){
        if(exame[i].sala == salas[j].id)
        salas[j].ocupada = 1;
        }
    }
}

void mostrarSalasLivres(){
        for(int i = 0; i< n_salas;i++){
            if(salas[i].ocupada == 0)
            printf("ID: %d\tCapacidade: %d",salas[i].id,salas[i].numeroCadeiras);
        }
}


void inscreverExame(){
    int id_exame, i, j;
    listarExames(); 
    printf("Qual o ID do exame? ");
    scanf("%d", &id_exame);
    for (i = 0; i < n_exames; i++){
        if (exame[i].id == id_exame){
            for (j = 0; j < exame[i].max_inscritos; j++){
                if (exame[i].ids_inscritos[j] == aluno.id){
                    printf("Já está inscrito neste exame!\n");
                    
                    return;
                }
            }
            for (j = 0; j < exame[i].max_inscritos; j++){
                if (exame[i].ids_inscritos[j] == 0){
                    exame[i].ids_inscritos[j] = aluno.id;
                    printc("[green]Inscrito com sucesso![/green]\n");
                    vagaMenos(exame[i].sala);
                    return;
                }
            }
            printf("Não há vagas disponíveis!\n");
            return;
        }
    }
    printf("Não existe nenhum exame com esse ID!\n");
}

void contarInscrito(int id)
{
    for (int i = 0; i < n_exames; i++)
    {
        for(int j = 0; j < exame[i].max_inscritos; j++)
        {
            if(exame[i].id == id)
                exame[i].inscritos++;
        }
    }
    
}

void listarInscritos(int id){
    for (int i = 0; i < n_exames; i++)
    {
        for(int j = 0; j < exame[i].max_inscritos; j++)
        {
            if(exame[i].id == id)
            {
                for(int k = 0; k < exame[i].inscritos;k++)
                {   
                    printc("\n\n\t[green]ID dos alunos inscritos: [/green]");
                    printf("ID: %d",exame[i].ids_inscritos[k]);
                    for(int l = 0; l<n_alunos;l++)
                    {
                        if(exame[i].ids_inscritos[k] == aluno.id)
                        {
                            printf("\tNome: %s", aluno.name);
                            printf("\tCurso: %s", aluno.course);
                        }
                    }   
                }
            }    
        }
    }
}

void listarExamesdeumAluno(){
    int id_aluno, i, j;
    listarAluno(); 
    printf("Qual o ID do aluno? ");
    scanf("%d", &id_aluno);
    for (i = 0; i < n_exames; i++){
        for (j = 0; j < exame[i].max_inscritos; j++){
            if (exame[i].ids_inscritos[j] == id_aluno){
                printf("ID: %d\tDisciplina: %d\tSala: %d\tData: %d\tHora: %d\n",exame[i].id,exame[i].disciplina,exame[i].sala,exame[i].data.dia,exame[i].data.mes,exame[i].data.hora,exame[i].data.minuto);
            }
        }
    }
}

void removerIncricao(){
    int id_aluno, id_exame, i, j;
    listarExames(); 
    printf("Qual o ID do exame? ");
    scanf("%d", &id_exame);
    for (i = 0; i < n_exames; i++){
        if (exame[i].id == id_exame){
            for (j = 0; j < exame[i].max_inscritos; j++){
                if (exame[i].ids_inscritos[j] == aluno.id){
                    exame[i].ids_inscritos[j] = 0;
                    printc("[green]Removido com sucesso![/green]\n");
                    vagaMais(exame[i].sala);
                    return;
                }
            }
            printf("Não está inscrito neste exame!\n");
            return;
        }
    }
    printf("Não existe nenhum exame com esse ID!\n");
}

void vagaMais(int salaId)
{
    for(int i=0;i<n_salas;i++){
        if(salas[i].id == salaId){
            salas[i].numeroCadeiras++;
        }
    }
}

void vagaMenos(int salaId) 
{
    for(int i=0;i<n_salas;i++){
        if(salas[i].id == salaId){
            salas[i].numeroCadeiras--;
        }
    }
}

void saveBinExames(){
    
    int i;
    FILE *fp;
    fp = fopen("data/bin/exames.bin", "wb");  // ID do exame, ID da disciplina, ID da sala, ID do professor, ID do regime, dia, mes, hora, minuto
    for (i = 0; i < n_exames; i++){
        fwrite(&exame[i].id, sizeof(Exames), 1, fp);
        fwrite(&exame[i].disciplina, sizeof(Exames), 1, fp);
        fwrite(&exame[i].sala, sizeof(Exames), 1, fp);
        fwrite(&exame[i].professor, sizeof(Exames), 1, fp);
        fwrite(&exame[i].regime, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.dia, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.mes, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.hora, sizeof(Exames), 1, fp);
        fwrite(&exame[i].data.minuto, sizeof(Exames), 1, fp);
        fwrite(&exame[i].max_inscritos, sizeof(Exames), 1, fp);
        for(int j=0;j<exame[i].max_inscritos;j++)
        fwrite(&exame[i].ids_inscritos[j], sizeof(Exames), 1, fp);

    }
    fclose(fp);
}

void readBinExames()
{
    exame = malloc(sizeof(Exames));
    int i;
    FILE *fp;
    fp = fopen("data/bin/exames.bin", "rb"); 
    for(i=0;;i++){
        if(fread(&exame[i].id, sizeof(Exames), 1, fp) != 1)break;
        exame = realloc(exame, sizeof(Exames)*(i+1));
        fread(&exame[i].disciplina, sizeof(Exames), 1, fp);
        fread(&exame[i].sala, sizeof(Exames), 1, fp);
        fread(&exame[i].professor, sizeof(Exames), 1, fp);
        fread(&exame[i].regime, sizeof(Exames), 1, fp);
        fread(&exame[i].data.dia, sizeof(Exames), 1, fp);
        fread(&exame[i].data.mes, sizeof(Exames), 1, fp);
        fread(&exame[i].data.hora, sizeof(Exames), 1, fp);
        fread(&exame[i].data.minuto, sizeof(Exames), 1, fp);
        fread(&exame[i].max_inscritos, sizeof(Exames), 1, fp);
        for(int j=0;j<exame[i].max_inscritos;j++)
        fread(&exame[i].ids_inscritos[j], sizeof(Exames), 1, fp);
    }
    n_exames = i;
}
