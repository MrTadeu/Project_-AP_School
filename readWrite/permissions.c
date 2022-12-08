#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../All_functions/global.h"

void resetarpermissions(permissionindividual *permissions)
{
    for(int i = 0; i < 10 ; i++)
    {
        permissions[i].name = malloc(5);
        strcpy(permissions[i].name, "NULL");
    }
}

void setPermissions_basics(Aluno *alunos, int* n_linhas_lidas) //serve para criar os cargos basicos
{
    for(int i = 0; i < *n_linhas_lidas ; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            alunos[i].id_permission[0] = alunos[i].id_role; //identifica tipo de pessoa(aluno,professor)
            alunos[i].id_permission[1] = alunos[i].ano; //Identifica o ano (1,2,3,4)
            alunos[i].id_permission[2] = alunos[i].id_course;//Identifica o curso (EI,EE,CONT) 
            alunos[i].id_permission[3] = 1; //Necessidade especial
            if(j >= 4)
            alunos[i].id_permission[j] = 0;
        }
    }
}

void listaralunos(Aluno *alunos, int* n_linhas_lidas)
{
    printf("\033[1;33m");
    printf("Listar Alunos:\n");
    printf("\033[0m");
    for(int i = 0; i < *n_linhas_lidas ; i++)
    {
        printf("\nNome: %s\nRole: %d\nAno: %d\t\tID Permissao: ", alunos[i].nome, alunos[i].id_role, alunos[i].ano);
        for(int j = 0; j < 10; j++)
        {
            printf("|%d", alunos[i].id_permission[j]);
        }
        printf("|");
        printf("\nID Aluno: %d\nCurso: %d\n", alunos[i].id, alunos[i].id_course);
    }
}
void ListarCargosExistentes(permissionindividual *permissions)
{
    printf("\033[1;33m");
    printf("Listar Cargos Existentes:\n");
    printf("\033[0m");
    for(int i = 0; i < 10 ; i++)
    {
        if(strcmp(permissions[i].name, "NULL") != 0)
        {
            printf("\nNome do cargo: %s\tID do cargo: %d\tPermissoes: ", permissions[i].name, i+1);
            for(int j = 0; j < 6; j++)
            {
                printf("|%d", permissions[i].id[j]);
            }
            printf("|");
        }
    }
}
int criarcargo(Aluno *alunos, int *n_linhas_lidas, permissionindividual *permission)
{   
printf("\033[1;33m");
printf("Criar Cargo:\n");
printf("\033[0m");
int i, associarcargo, associarcargoGI, id_aluno_basico[4], flag;
for(i = 0; i < 10 ; i++) 
{
    if(strcmp(permission[i].name, "NULL") == 0)
    break;
}
if(i==10)
{
    printf("\nNao e possivel criar mais cargos\n\n");
    return 1;
}
printf("\nDigite o nome do cargo: ");
scanf("%s", permission[i].name);
printf("Escolha as permissoes a adicionar ao cargo:\n\n");
printf("1 - Ler Alunos\n2 - Escrever Alunos\n3 - Listar Alunos\n4 - Deletar Alunos\n5 - Ler Cursos\n6 - Escrever Cursos\n7 - Listar Cursos\n8 - Deletar Cursos\n9 - Ler Roles\n10 - Escrever Roles\n11 - Listar Roles\n12 - Deletar Roles\n");
for(int j = 0; j < 6; j++)
{
    printf("\nDigite a permissao\nPara parar insira -1: ");//cria vetor de permissoes em posicao livre
    scanf("%d", &permission[i].id[j]);
    if(permission[i].id[j] == -1)
    {
        while(j<6)
        {
            permission[i].id[j] = 0;
            j++;
        }
    }
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
printf("\nCargo criado com sucesso!\n");
FILE* fp = fopen("data/bin/permissions.bin", "wb");
for (int j = 0; j < 7; j++)
fwrite(permission, sizeof(permissionindividual), 1, fp);
fclose(fp); 
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
do{
printf("Dejesa associar este cargo?\n1 - Sim\n2 - Nao\n");
scanf("%d", &associarcargo);    
}while(associarcargo != 1 && associarcargo != 2);
if(associarcargo == 1)
{
do{
printf("A um grupo de alunos ou aluno individual?\n1 - Grupo\n2 - Individual\n");
scanf("%d", &associarcargoGI);     
}while(associarcargoGI != 1 && associarcargoGI != 2);
}
else
{
    printf("\n\n");
    return 0;
}
if(associarcargoGI == 1)
{   
//definir grupo de alunos ao qual quer associar o cargo
printf("\nDigite o ID_basico_geral dos alunos (4 primeiros digitos) ao qual quer associar o cargo:");
for(int i = 0; i < 4 ; i++)
{
    scanf("%d", &id_aluno_basico[i]);
}
//verificar se existe algum aluno com o ID basico inserido
for(int i = 0; i < *n_linhas_lidas ; i++)
{   flag = 0;
    for(int j = 0; j < 4; j++)
    {   
        if(alunos[i].id_permission[j] == id_aluno_basico[j]) 
        flag++;
    }
    if(flag == 4)
        i = *n_linhas_lidas;
}
if(flag < 4)
{
    printf("\nNao foi encontrado nenhum aluno com o ID_basico_geral inserido!\n");
}
else
    associarcargoaluno(alunos, n_linhas_lidas, permission, id_aluno_basico, i);
}
if(associarcargoGI == 2)
{  
    int id_aluno_individual;
    printf("\nDigite o ID do aluno (4 digitos) ao qual quer associar o cargo: ");
    scanf("%d", &id_aluno_individual);
    int l;
    for(l = 0; l < *n_linhas_lidas ; l++)
    {
            if(alunos[i].id == id_aluno_individual)
            flag = 1;
            if(flag == 1)
            break;
    }
    if(flag = 0)
    {
        printf("\nNao foi encontrado nenhum aluno com o ID inserido!\n");
    }
    else
    {
    alunos[l].id_permission[4] = permission[i].id[0];
    alunos[l].id_permission[5] = permission[i].id[1];
    alunos[l].id_permission[6] = permission[i].id[2];
    alunos[l].id_permission[7] = permission[i].id[3];
    alunos[l].id_permission[8] = permission[i].id[4];
    alunos[l].id_permission[9] = permission[i].id[5];         
    }

}
printf("\n\n");
}

void associarcargoaluno(Aluno *alunos, int *n_linhas_lidas, permissionindividual *permission, int *id_aluno_basico, int cargocriado)
{
int flag = 0;
for(int l = 0; l<*n_linhas_lidas ;l++)
{   flag = 0;
    for(int k = 0; k<4; k++)
    {
        if(alunos[l].id_permission[k] == id_aluno_basico[k])
        flag++;
    }   
    if(flag == 4)
    {
    alunos[l].id_permission[4] = permission[cargocriado].id[0];
    alunos[l].id_permission[5] = permission[cargocriado].id[1];
    alunos[l].id_permission[6] = permission[cargocriado].id[2];
    alunos[l].id_permission[7] = permission[cargocriado].id[3];
    alunos[l].id_permission[8] = permission[cargocriado].id[4];
    alunos[l].id_permission[9] = permission[cargocriado].id[5];                    
    }
}
printf("Cargo associado com sucesso!\n\n");
}        

void associarcargoexistente(Aluno *alunos, int *n_linhas_lidas, permissionindividual *permission)
{   
int id_cargo , flag = 0 , i, id_aluno_basico[4], associarcargo; 
printf("/033[0;33m");
printf("Associar Cargo Existente: \n");
printf("/033[0m");
printf("/033[0;34m");
printf("\nLista de permicoes: \n");
printf("/033[0m");
printf("/033[0;34m");
printf("1 - Ler Alunos\n2 - Escrever Alunos\n3 - Listar Alunos\n4 - Deletar Alunos\n5 - Ler Cursos\n6 - Escrever Cursos\n7 - Listar Cursos\n8 - Deletar Cursos\n9 - Ler Roles\n10 - Escrever Roles\n11 - Listar Roles\n12 - Deletar Roles\n");
printf("/033[0m");
printf("/033[0;34m");
printf("\nCargos Existentes\n");
printf("/033[0m ");
ListarCargosExistentes(permission);
do{ //Escolher cargo a associar
printf("\nDigite o ID do cargo que deseja associar ao aluno: ");
scanf("%d", &id_cargo);
id_cargo--;        
if(strcmp(permission[id_cargo].name, "NULL") == 0 || id_cargo < 0 || id_cargo >= 10)
{
    printf("\nCargo nao encontrado!\n");
    flag = 1;
}
}while(flag == 1);

printf("\nCargo selecionado: %s\nPretende associa-lo a um grupo de alunos ou a um aluno individual?\n1 - Grupo\n2 - Individual\n", permission[id_cargo].name);
scanf("%d", &associarcargo);
if(associarcargo == 1)
{
printf("\nDigite o ID basico do aluno ao qual quer associar o cargo: ");
for(int i = 0; i < 4 ; i++)
{
    scanf("%d", &id_aluno_basico[i]);
}
for(int i = 0; i < *n_linhas_lidas ; i++)
{   flag = 0;
    for(int j = 0; j < 4; j++)
    {   
        if(alunos[i].id_permission[j] == id_aluno_basico[j])
        flag++;
        if(flag == 4)
        break;
    }
}
if(flag < 4)
{
    printf("\nNao foi encontrado nenhum aluno com o ID inserido!\n");
}
else
{
for(int l = 0; l<*n_linhas_lidas ;l++)
{   flag = 0;
    for( int k = 0; k<4; k++)
    {   
        if(alunos[l].id_permission[k] == id_aluno_basico[k])
        flag++;
    }   
    if(flag == 4)
    {
    alunos[l].id_permission[4] = permission[id_cargo].id[0];
    alunos[l].id_permission[5] = permission[id_cargo].id[1];
    alunos[l].id_permission[6] = permission[id_cargo].id[2];
    alunos[l].id_permission[7] = permission[id_cargo].id[3];
    alunos[l].id_permission[8] = permission[id_cargo].id[4];
    alunos[l].id_permission[9] = permission[id_cargo].id[5];                    
    }
}
}
}
else if(associarcargo == 2)
{

    int id_aluno_individual;
    //definir aluno individual ao qual quer associar o cargo
    printf("\nDigite o ID do aluno (4 digitos) ao qual quer associar o cargo: ");
    scanf("%d", &id_aluno_individual);
    //verificar se existe algum aluno com o ID inserido
    int l;
    for(l = 0; l < *n_linhas_lidas ; l++)
    {
        if(alunos[i].id == id_aluno_individual)
        flag = 1;
        if(flag == 1)
        break;
    }
    if(flag = 0)
    {
        printf("\nNao foi encontrado nenhum aluno com o ID inserido!\n");
    }
    else
    {
    alunos[l].id_permission[4] = permission[id_cargo].id[0];
    alunos[l].id_permission[5] = permission[id_cargo].id[1];
    alunos[l].id_permission[6] = permission[id_cargo].id[2];
    alunos[l].id_permission[7] = permission[id_cargo].id[3];
    alunos[l].id_permission[8] = permission[id_cargo].id[4];
    alunos[l].id_permission[9] = permission[id_cargo].id[5];         
    }
}
}