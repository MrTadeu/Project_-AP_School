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
    printc("************        [blue]Criar Exames[/blue]       ***********\n");
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
    //fazer verificacao
        
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
        listarSalasReservas(); 
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

    tempoExames dateFinal;
    do{
    printf("Qual a data do exame (formato DD MM YY)? ");
    scanf("%d %d %d", &exame[n_exames].data.dia, &exame[n_exames].data.mes, &exame[n_exames].data.ano);
    printf("Qual a hora do exame (formato HH MM)? ");
    scanf("%d %d", &exame[n_exames].data.hora, &exame[n_exames].data.minuto);
    if(exame[n_exames].data.dia > 31 || exame[n_exames].data.mes > 12)
        printc("\n[red]Data inválida![/red]");
    if(exame[n_exames].data.dia < 0 || exame[n_exames].data.mes < 0)
        printc("\n[red]Data inválida![/red]");
    if(exame[n_exames].data.hora > 23 || exame[n_exames].data.minuto > 59)
        printc("\n[red]Hora inválida![/red]");
    if(exame[n_exames].data.hora < 0 || exame[n_exames].data.minuto < 0)
        printc("\n[red]Hora inválida![/red]\n");
    dateFinal = dataFinal(exame[n_exames].data, exame[n_exames].duracao.hora, exame[n_exames].duracao.minuto);
    CheckIfDataExisteExame(exame[n_exames].data, dateFinal);
    }while(exame[n_exames].data.dia > 31 || exame[n_exames].data.mes > 12 || exame[n_exames].data.dia < 0 || exame[n_exames].data.mes < 0 || exame[n_exames].data.hora > 23 || exame[n_exames].data.minuto > 59 || exame[n_exames].data.hora < 0 || exame[n_exames].data.minuto < 0 || CheckIfDataExisteExame(exame[n_exames].data, dateFinal) == 0);

    printf("%d/%d", dateFinal.hora, dateFinal.minuto);
    do{
    printf("Qual a duração máxima do exame (HH MM)? ");
    scanf("%d %d", &exame[n_exames].duracao.hora, &exame[n_exames].duracao.minuto);
    if(exame[n_exames].duracao.hora > 2 && exame[n_exames].duracao.minuto > 59)
        printc("\n[red]Duração máxima de 3 horas![/red]");
    if(exame[n_exames].duracao.hora < 0 || exame[n_exames].duracao.minuto < 0)
        printc("\n[red]Duração não pode ser negativa![/red]\n");
    if(exame[n_exames].duracao.hora == 0 && exame[n_exames].duracao.minuto == 0)
        printc("\n[red]Duração não pode ser 0![/red]\n");
    Sleep(2000);
    }while(exame[n_exames].duracao.hora > 2 || exame[n_exames].duracao.minuto > 59 || exame[n_exames].duracao.hora < 0 || exame[n_exames].duracao.minuto < 0 || exame[n_exames].duracao.hora == 0 && exame[n_exames].duracao.minuto == 0);


    ReservarSala(n_exames, dateFinal);
    
    n_exames++;
    saveBinExames();
}

int CheckIfDataExisteExame(tempoExames dataInicio, tempoExames dataFinal)
{
    for(int i = 0; i < n_salas; i++){
        for(int j = 0;j<salas[i].n_reservas;j++){
            if(checkIfdataExiste(salas[i].reservas[j].data,salas[i].reservas[j].dataFinal,dataInicio) == 1 && checkIfdataExiste(salas[i].reservas[j].data,salas[i].reservas[j].dataFinal,dataFinal) == 1){
                printc("[red]O horário está ocupado pelo seguinte exame:[/red]\n");
                printc("[blue]ID Exame:[/blue] %d   [blue]Data inicial:[/blue] %d/%d/%d   [blue]Hora:[/blue] [%d/%d] - [%d/%d]   [blue]Vagas:[/blue] %d",salas[i].reservas[j].id_exame,salas[i].reservas[j].data.dia,salas[i].reservas[j].data.mes,salas[i].reservas[j].data.ano,salas[i].reservas[j].data.hora,salas[i].reservas[j].data.minuto,salas[i].reservas[j].dataFinal.hora,salas[i].reservas[j].dataFinal.minuto,salas[i].reservas[j].vagas);
                Sleep(2500);
                return 0;
            }
        }
    
    }
    return 1;
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
    printf("**************************************************\n");
    printc("************        [blue]Listar Exames[/blue]       ***********\n");
    printf("**************************************************\n");
    for(int i=0;i<n_exames;i++)
        printc("\n[blue]ID Exame:[/blue] %d   [blue]Disciplina:[/blue] %s   [blue]Sala:[/blue] %s%d   [blue]Data:[/blue] %d/%d/%d   [blue]Hora: [/blue][%d/%d]\n",exame[i].id,exame[i].disciplina,exame[i].SalaNome,exame[i].SalaNum,exame[i].data.dia,exame[i].data.mes,exame[i].data.ano,exame[i].data.hora,exame[i].data.minuto);
}

void ReservarSala(int N_exames, tempoExames dateFinal)
{   
    for(int j=0;j<n_salas;j++){
    if(exame[N_exames].SalaNum == salas[j].numeroSala && strcmp(exame[N_exames].SalaNome , salas[j].nomeSala) == 0){
        if(salas[j].n_reservas == 0)
        {
            salas[j].reservas = malloc(sizeof(Reservas));
        }
        else
        {
            salas[j].reservas = realloc(salas[j].reservas, (salas[j].n_reservas+1)*sizeof(Reservas));
        }

        salas[j].reservas[salas[j].n_reservas].salaReservada = 1;
        salas[j].reservas[salas[j].n_reservas].id_reserva = exame[N_exames].data.hora;
        salas[j].reservas[salas[j].n_reservas].id_exame = exame[N_exames].id;
        salas[j].reservas[salas[j].n_reservas].data.mes = exame[N_exames].data.mes;
        salas[j].reservas[salas[j].n_reservas].data.dia = exame[N_exames].data.dia;
        salas[j].reservas[salas[j].n_reservas].data.ano = exame[N_exames].data.ano;
        salas[j].reservas[salas[j].n_reservas].data.hora = exame[N_exames].data.hora;
        salas[j].reservas[salas[j].n_reservas].data.minuto = exame[N_exames].data.minuto;
        salas[j].reservas[salas[j].n_reservas].dataFinal.ano = dateFinal.ano;
        salas[j].reservas[salas[j].n_reservas].dataFinal.mes = dateFinal.mes; 
        salas[j].reservas[salas[j].n_reservas].dataFinal.dia = dateFinal.dia;
        salas[j].reservas[salas[j].n_reservas].dataFinal.hora = dateFinal.hora;
        salas[j].reservas[salas[j].n_reservas].dataFinal.minuto = dateFinal.minuto; 
        salas[j].reservas[salas[j].n_reservas].vagas = exame[N_exames].max_inscritos;
        salas[j].n_reservas++;
        }
    }
    saveBinSalas();
    printc("\n[green]Sala reservada com sucesso![/green]\n");
}

void removerExame()
{
    int id;
    printf("\n[blue]ID do exame a remover:[/blue] ");
    scanf("%d",&id);
    for(int i=0;i<n_exames;i++){
        if(exame[i].id == id){
            for(int j=i;j<n_exames;j++){
                    if(j == n_exames-1)
                    {
                        exame = realloc(exame,(n_exames-1)*sizeof(Exames));
                        n_exames--;
                        break;
                    }
                exame[j] = exame[j+1];
                }
        saveBinExames();
        RemoverReservaSala(id-1);
        printf("\n[green]Exame removido com sucesso![/green]\n");
        return;
        }
    }
    printf("\n[red]Exame não encontrado![/red]\n");
}

void listarSalasReservas()
{
    printf("**************************************************\n");
    printc("*********        [blue]Salas e Reservas[/blue]       **********\n");
    printf("**************************************************\n");
    for(int i=0;i<n_salas;i++){
        printc("\n[blue]Sala[/blue] %s%d\n",salas[i].nomeSala,salas[i].numeroSala);
        if(salas[i].n_reservas == 0)
            printc("[green]Ainda não há reservas para esta sala[/green]\n\n");
        else
        {
            for(int j=0;j<salas[i].n_reservas;j++){
                printc("\n[red]Reserva:[/red] %d de %d", j+1, salas[i].n_reservas);
                printc("\n[blue]ID Exame:[/blue] %d   [blue]Data:[/blue] %d/%d/%d   [blue]Hora:[/blue] [%d/%d] - [%d/%d]   [blue]Vagas:[/blue] %d\n",salas[i].reservas[j].id_exame,salas[i].reservas[j].data.dia,salas[i].reservas[j].data.mes,salas[i].reservas[j].data.ano,salas[i].reservas[j].data.hora,salas[i].reservas[j].data.minuto,salas[i].reservas[j].dataFinal.hora,salas[i].reservas[j].dataFinal.minuto,salas[i].reservas[j].vagas);
            }
        }
    }
}

/* void listarReservasIndividuais(char *SalaNome, int SalaNum)
{
    for(int i = 0;i<n_exames;i++){
        for(int j = 0;j<n_salas;j++)
        {
            if(strcmp(exame[i].SalaNome,SalaNome) == 0 && exame[i].SalaNum == SalaNum)
            {   
                printc("\n[blue]Reservas da sala %s%d:[/blue]\n",SalaNome,SalaNum);
                for(int j=0;j<salas[i].n_reservas;j++)
                    printc("\n[blue]ID Exame:[/blue] %d   [blue]Data inicial:[/blue] %d/%d/%d   [blue]Hora inicial:[/blue] [%d/%d]   [blue]Data final:[/blue] %d/%d/%d   [blue]Hora final:[/blue] [%d/%d]   [blue]Vagas:[/blue] %d",salas[i].reservas[j].id_exame,salas[i].reservas[j].dia,salas[i].reservas[j].mes,salas[i].reservas[j].ano,salas[i].reservas[j].hora,salas[i].reservas[j].minuto,salas[i].reservas[j].diaFinal,salas[i].reservas[j].mesFinal,salas[i].reservas[j].anoFinal,salas[i].reservas[j].horaFinal,salas[i].reservas[j].minutoFinal,salas[i].reservas[j].vagas);
            }
            
        }
    }
} */

void RemoverReservaSala(int N_exames)
{
    for(int i=0;i<n_salas;i++){
        for(int j=0;j<salas[i].n_reservas;j++){
            if(salas[i].reservas[j].id_exame == exame[N_exames].id){
                for(int k=j;k<salas[i].n_reservas;k++){
                    if(k == salas[i].n_reservas-1){
                        salas[i].reservas = realloc(salas[i].reservas,(salas[i].n_reservas-1)*sizeof(Reservas));
                        salas[i].n_reservas--;
                        break;
                    }
                    salas[i].reservas[k] = salas[i].reservas[k+1];
                }
            }
        }
    }
    saveBinSalas();
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
                    vagaMenos(exame[i].SalaNum, exame[i].SalaNome, n_exames+1);
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
                    vagaMais(exame[i].SalaNum, exame[i].SalaNome, n_exames+1);
                    return;
                }
            }
            printf("Não está inscrito neste exame!\n");
            return;
        }
    }
    printf("Não existe nenhum exame com esse ID!\n");
    saveBinExames();
}

void vagaMais(int SalaNum, char* SalaNome, int id)
{
    for(int i=0;i<n_salas;i++){
        if(salas[i].numeroSala == SalaNum && strcmp(salas[i].nomeSala, SalaNome) == 0){
            for(int j=0;j<salas[i].n_reservas;j++)
                {
                    if(salas[i].reservas[j].id_exame == id)
                    {
                        salas[i].reservas[j].vagas++;
                        saveBinSalas();
                        return;
                    }
                }
            }
        }
}

void vagaMenos(int SalaNum, char* SalaNome, int id) 
{
    for(int i=0;i<n_salas;i++){
        if(salas[i].numeroSala == SalaNum && strcmp(salas[i].nomeSala, SalaNome) == 0){
            for(int j=0;j<salas[i].n_reservas;j++)
            {
                if(salas[i].reservas[j].id_exame == id)
                {
                    salas[i].reservas[j].vagas--;
                    saveBinSalas();
                    return;
                }
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
        fwrite(&exame[i].data.ano, sizeof(int), 1, fp);
        fwrite(&exame[i].data.hora, sizeof(int), 1, fp);
        fwrite(&exame[i].data.minuto, sizeof(int), 1, fp);
        fwrite(&exame[i].duracao.hora, sizeof(int), 1, fp);
        fwrite(&exame[i].duracao.minuto, sizeof(int), 1, fp);
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
        fread(&exame[i].data.ano, sizeof(int), 1, fp);
        fread(&exame[i].data.hora, sizeof(int), 1, fp);
        fread(&exame[i].data.minuto, sizeof(int), 1, fp);
        fread(&exame[i].duracao.hora, sizeof(int), 1, fp);
        fread(&exame[i].duracao.minuto, sizeof(int), 1, fp);

        exame[i].ids_inscritos = malloc(sizeof(int)*exame[i].max_inscritos);
        for(int j=0;j<exame[i].max_inscritos;j++) 
            fread(&exame[i].ids_inscritos[j], sizeof(int), 1, fp);
    }
    fclose(fp);
}
