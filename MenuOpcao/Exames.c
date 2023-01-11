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

    printf("**************************************************\n");
    printc("************        [blue]Criar Exames[/blue]       ************\n");
    printf("**************************************************\n");
    exame[n_exames].SalaNome = malloc(100);
    exame[n_exames].disciplina = malloc(100);
    exame[n_exames].id = n_exames+1;
    exame[n_exames].professor = aluno.id;

    printf("Qual é o número máximo de inscritos? ");
    scanf("%d", &exame[n_exames].max_inscritos);
    exame[n_exames].ids_inscritos = malloc(sizeof(int)*exame[n_exames].max_inscritos);
    for(int i=0;i<exame[n_exames].max_inscritos;i++)
        exame[n_exames].ids_inscritos[i] = 0; 
    
    printf("Qual o regime do exame? (1 - Normal, 2 - Recurso, 3 - Especial): ");
    scanf("%d", &exame[n_exames].regime);
        
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

    do{
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        ListarCursos();
        printf("Para que curso estará disponivel? Insira o ID do curso:");
        scanf("%d", &exame[n_exames].curso);
        if(CheckIFCursoExiste(exame[n_exames].curso) == -1){
            printc("[red]Curso não existe![/red]");
            Sleep(1000);
        }
        if(CheckDiscInCurso(exame[n_exames].curso, n_exames) == -1){
            printc("[red]Disciplina escolhida não existe no curso![/red]");
            Sleep(1000);
        }
    }while(CheckIFCursoExiste(exame[n_exames].curso) == -1 || CheckDiscInCurso(exame[n_exames].curso, n_exames) == -1);

    do{
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        listarSalasLivres();  
        printf("Para que sala pretende criar um exame?\n");
        printf("Insira o nome da sala? ");
        scanf("%s", exame[n_exames].SalaNome);
        exame[n_exames].SalaNome = realloc(exame[n_exames].SalaNome, (strlen(exame[n_exames].SalaNome)+1));
        uppercase(exame[n_exames].SalaNome);
        printf("Insira o número da sala? ");
        scanf("%d", &exame[n_exames].SalaNum);

    if(CheckIFsalaExist(exame[n_exames].SalaNome, exame[n_exames].SalaNum) == 0){
        printc("[red]Sala não existe![/red]");
        Sleep(1000);
    }
    }while(CheckIFsalaExist(exame[n_exames].SalaNome, exame[n_exames].SalaNum) == 0);

    /* mostrarSalasocupada(sala&dia)(); */
    printf("Qual a data do exame (formato DD MM)? ");
    scanf("%d %d", &exame[n_exames].data.dia, &exame[n_exames].data.mes);
    /*Checkifreservaexiste*/

    /* mostrarSalasocupada(sala&dia&horas&minutos)(); */
    printf("Qual a hora do exame (formato HH MM)? ");
    scanf("%d %d", &exame[n_exames].data.hora, &exame[n_exames].data.minuto);

    printf("Qual a duração máxima do exame (em minutos)? ");
    scanf("%d", &exame[n_exames].data.duracao);
    /*funcao*/
    /*Checkifreservaexiste*/

    ReservarSala(n_exames);
    
    n_exames++;
    saveBinExames();
}

int CheckDiscInCurso(int id, int n_Exame)
{
    for(int i = 0; i < n_courses; i++){
        if(courses[i].id == id){
            for(int j = 0; j < 3; j++){
                for (int k = 0; k < courses[i].num_disciplinas[j]; k++){
                    if(strcmp(courses[i].AnoDisciplina[j][k] , exame[n_Exame].disciplina) == 0)
                        return 1;
                }
            }
        }
    }
    return -1;
}

void listarExames(){
    for(int i=0;i<n_exames;i++)
        printf("\n\t[blue]ID:[/blue] %d   [blue]Disciplina:[/blue] %d   [blue]Sala:[/blue] %s%d   [blue]Data:[/blue] %d   [blue]Hora: [/blue]%d\n",exame[i].id,exame[i].disciplina,exame[i].SalaNome,exame[i].SalaNum ,exame[i].data.dia,exame[i].data.mes,exame[i].data.hora,exame[i].data.minuto);
}

void ReservarSala(int N_exames)
{
        for(int j=0;j<n_salas;j++){
        if(exame[N_exames].SalaNum == salas[j].numeroSala && strcmp(exame[N_exames].SalaNome , salas[j].nomeSala) == 0 && exame[N_exames].id != salas[j].reservas[salas[j].n_reservas].id_exame){
            realloc(salas[j].reservas, (salas[j].n_reservas+1)*sizeof(Reservas));
            salas[j].reservas[salas[j].n_reservas].salaReservada = 1;
            salas[j].reservas[salas[j].n_reservas].id_reserva = exame[N_exames].data.hora;
            salas[j].reservas[salas[j].n_reservas].id_exame = exame[N_exames].id;
            salas[j].reservas[salas[j].n_reservas].mes = exame[N_exames].data.mes;
            salas[j].reservas[salas[j].n_reservas].dia = exame[N_exames].data.dia;
            salas[j].reservas[salas[j].n_reservas].hora = exame[N_exames].data.hora;
            salas[j].reservas[salas[j].n_reservas].minuto = exame[N_exames].data.minuto;
            salas[j].reservas[salas[j].n_reservas].mesFinal;  //=funcao final
            salas[j].reservas[salas[j].n_reservas].diaFinal;  //=funcao final
            salas[j].reservas[salas[j].n_reservas].horaFinal; //=funcao final
            salas[j].reservas[salas[j].n_reservas].minutoFinal; //=funcao final
            salas[j].reservas[salas[j].n_reservas].vagas = exame[N_exames].max_inscritos;
            salas[j].n_reservas++;
            }
        }
    saveBinSalas();
    printf("\n[green]Sala reservada com sucesso![/green]\n");
}


void MostrarSalasLivresParaHorarioEscolhido(/*temppppppppppppppppppppppppppooooooooooooooo dia tudo*/){//problem
    printc("[blue]Salas Livres: [/blue]\n");
        for(int i = 0; i< n_salas;i++){
            for (int j = 0; j < salas[i].n_reservas; j++){
                if(salas[i].reservas[j].salaReservada == 0)
                printc("\t[blue]Nome:[/blue] %s\t[blue]Número:[/blue] %d\t[blue]Capacidade:[/blue] %d\n",salas[i].id,salas[i].nomeSala, salas[i].numeroSala, salas[i].numeroCadeiras);
            }
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
                    vagaMenos(exame[i].SalaNum, exame[i].SalaNome);
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
                printf("\n[blue]ID:[/blue] %d   [blue]Disciplina: [/blue]%d   [blue]Sala:[/blue] %s%d   [blue]Data:[/blue] %d   [blue]Hora:[/blue] %d\n",exame[i].id,exame[i].disciplina,exame[i].SalaNome,exame[i].SalaNum,exame[i].data.dia,exame[i].data.mes,exame[i].data.hora,exame[i].data.minuto);
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
                    vagaMais(exame[i].SalaNum, exame[i].SalaNome);
                    return;
                }
            }
            printf("Não está inscrito neste exame!\n");
            return;
        }
    }
    printf("Não existe nenhum exame com esse ID!\n");
}

void vagaMais(int SalaNum, char* SalaNome)
{
    for(int i=0;i<n_salas;i++){
        if(salas[i].numeroSala == SalaNum && strcmp(salas[i].nomeSala, SalaNome) == 0){
            for(int j=0;j<salas[i].n_reservas;j++)
                {
                    salas[i].reservas[j].vagas++;
                    return;
                }
            }
        }
}

void vagaMenos(int SalaNum, char* SalaNome) 
{
    for(int i=0;i<n_salas;i++){
        if(salas[i].numeroSala == SalaNum && strcmp(salas[i].nomeSala, SalaNome) == 0){
            for(int j=0;j<salas[i].n_reservas;j++)
            {
                salas[i].reservas[j].vagas--;
                return;
            }
        }
    }
}

void saveBinExames(){
    
    int i;
    FILE *fp;
    fp = fopen("data/bin/exames.bin", "wb");  // ID do exame, ID da disciplina, ID da sala, ID do professor, ID do regime, dia, mes, hora, minuto
            
    fwrite(&n_exames, sizeof(int), 1, fp);

    for (i = 0; i < n_exames; i++){

        fwrite(&exame[i].id, sizeof(int), 1, fp);
        fwrite(&exame[i].max_inscritos, sizeof(int), 1, fp);

        size_t disclen = strlen(exame[i].disciplina)+1;
        fwrite(&disclen, sizeof(size_t), 1, fp);
        fwrite(exame[i].disciplina, disclen ,1, fp);
        fwrite(&exame[i].curso, sizeof(int), 1, fp);

        size_t salanomelen = strlen(exame[i].SalaNome)+1;
        fwrite(&salanomelen, sizeof(size_t), 1, fp);
        fwrite(exame[i].SalaNome, salanomelen  , 1, fp);
        fwrite(&exame[i].SalaNum, sizeof(int), 1, fp);

        fwrite(&exame[i].professor, sizeof(int), 1, fp);
        fwrite(&exame[i].regime, sizeof(int), 1, fp);

        fwrite(&exame[i].data.dia, sizeof(int), 1, fp);
        fwrite(&exame[i].data.mes, sizeof(int), 1, fp);
        fwrite(&exame[i].data.hora, sizeof(int), 1, fp);
        fwrite(&exame[i].data.minuto, sizeof(int), 1, fp);
        for(int j=0;j<exame[i].max_inscritos;j++)
        fwrite(&exame[i].ids_inscritos[j], sizeof(int), 1, fp);

    }
    fclose(fp);
}

void readBinExames()
{
    exame = malloc(sizeof(Exames));
    int i;
    FILE *fp;
    fp = fopen("data/bin/exames.bin", "rb"); 

    fread(&n_exames, sizeof(int), 1, fp);

    for(i=0;i<n_exames;i++){
        exame = realloc(exame, sizeof(Exames)*(i+1));

        fread(&exame[i].id, sizeof(int), 1, fp);
        fread(&exame[i].max_inscritos, sizeof(int), 1, fp);

        size_t disclen;
        fread(&disclen, sizeof(size_t), 1, fp);
        exame[i].disciplina = malloc(disclen);
        fread(exame[i].disciplina, disclen, 1, fp);
        fread(&exame[i].curso, sizeof(int), 1, fp);

        size_t salanomelen;
        fread(&salanomelen, sizeof(size_t), 1, fp);
        exame[i].SalaNome = malloc(salanomelen);
        fread(exame[i].SalaNome, salanomelen, 1, fp);
        fread(&exame[i].SalaNum, sizeof(int), 1, fp);

        fread(&exame[i].professor, sizeof(int), 1, fp);
        fread(&exame[i].regime, sizeof(int), 1, fp);

        fread(&exame[i].data.dia, sizeof(int), 1, fp);
        fread(&exame[i].data.mes, sizeof(int), 1, fp);
        fread(&exame[i].data.hora, sizeof(int), 1, fp);
        fread(&exame[i].data.minuto, sizeof(int), 1, fp);

        exame[i].ids_inscritos = malloc(sizeof(int)*exame[i].max_inscritos);
        for(int j=0;j<exame[i].max_inscritos;j++) 
            fread(&exame[i].ids_inscritos[j], sizeof(int), 1, fp);
    }
    fclose(fp);
}
