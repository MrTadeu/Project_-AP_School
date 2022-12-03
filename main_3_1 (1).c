#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 100
#define MIN 20

typedef struct Menu
{
    char nomemenu[MIN];
    char ham[MIN];
    char beb[MIN];
    char ext[MIN];
    float preco;
} Menu;

typedef struct Encomenda
{
    char nome_3[MIN];
    char nome_4[MIN];
    char ham[MIN];
    char beb[MIN];
    char ext[MIN];
    int NIF2;
    float preco;
} Encomenda;

typedef struct Cliente
{
    char nome_1[MIN];
    char nome_2[MIN];
    int idade;
    int telefone;
    int NIF;
} Cliente;

Cliente clientes[MAX];

typedef struct HArtigo
{
    char nome[MIN];
	float preco;
	int codigo;
} HArtigo;

HArtigo Hartigos[MAX];

typedef struct BArtigo
{
    char nome[MIN];
	float preco;
	int codigo;
} BArtigo;

BArtigo Bartigos[MAX];

typedef struct EArtigo
{
    char nome[MIN];
	float preco;
	int codigo;
} EArtigo;

EArtigo Eartigos[MAX];


// A fun��o lista todos os menus existentes

void listar_menus()
{
    system("cls");
    FILE *fp;
    fp = fopen("MENUS.txt", "rb");
    Menu s[MAX];
    int i;
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    printf ("\n ----Lista de Menus----");
    while(fread(&s[i], sizeof(Menu),1,fp))
    {
        printf ("\n Nome do Menu: %s", s[i].nomemenu);
        printf ("\n Hamb�rger: %s", s[i].ham);
        printf ("\n Bebida: %s", s[i].beb);
        printf ("\n Aperitivo: %s", s[i].ext);
        printf ("\n Pre�o: %.2f", s[i].preco);
    }
    fclose(fp);
    getchar();
    getchar();
    return;
}


// A fun��o cria um novo menu

void novo_menu()
{
    system("cls");
    FILE *fp;
    fp = fopen("MENUS.txt", "ab");
    Menu s[MAX];
    int i, a;
    int total = 0;
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    printf("\n Insira o nome do Menu: ");
    scanf ("%s", s[i].nomemenu);

    do{
        int i;
        int a = 0;
        int j;
        HArtigo s1[MAX];
        FILE *fp1;
        fp1 = fopen ("Hamburgers.txt", "rb");

        if (fp1 == NULL){
            printf ("Erro");
            return;
        }
        printf ("\n ----------Hamburgers----------\n");

        while (fread(&s1[i], sizeof(HArtigo),1,fp1)){
            printf (" C�digo: %d \n Nome: %s \n Pre�o: %.2f \n\n", s1[i].codigo, s1[i].nome, s1[i].preco);
        }
        printf (" Insira o c�digo do produto que deseja adicionar: ");
        scanf ("%d", &j);
        rewind(fp1);
        while(fread(&s1[i], sizeof(HArtigo),1,fp1)){
            if (s1[i].codigo == j){
                total = total + s1[i].preco;
                strcpy (s[i].ham, s1[i].nome);
                a = 1;
            }
        }
        fclose(fp1);
    } while (a = 0);

    do{
        int a;
        a = 0;
        int j;
        BArtigo s2[MAX];
        FILE *fp2;
        fp2 = fopen ("Bebidas.txt", "rb");

        if (fp2 == NULL){
            printf ("Erro");
            return;
        }

        printf ("\n ----------Bebidas----------\n");
        while (fread(&s2[i], sizeof(BArtigo),1,fp2)){
            printf (" C�digo: %d \n Nome: %s \n Pre�o: %.2f \n\n", s2[i].codigo, s2[i].nome, s2[i].preco);
        }
        printf (" Insira o c�digo do produto que deseja adicionar: ");
        scanf ("%d", &j);
        rewind(fp2);
        while(fread(&s2[i], sizeof(BArtigo),1,fp2)){
            if (s2[i].codigo == j){
                total = total + s2[i].preco;
                strcpy (s[i].beb, s2[i].nome);
                a = 1;
            }
        }
        fclose(fp2);
    } while (a = 0);

    do{
        int a = 0;
        int j;
        EArtigo s3[MAX];
        FILE *fp3;
        fp3 = fopen ("Aperitivos.txt", "rb");
        if (fp3 == NULL){
            printf ("Erro");
            return;
        }
        printf ("---------Aperitivos----------\n");
        while (fread(&s3[i], sizeof(EArtigo),1,fp3)){
            printf (" C�digo: %d \n Nome: %s \n Pre�o: %.2f \n\n", s3[i].codigo, s3[i].nome, s3[i].preco);
        }
        printf (" Insira o c�digo do produto que deseja adicionar: ");
        scanf ("%d", &j);
        rewind(fp3);
        while(fread(&s3[i], sizeof(EArtigo),1,fp3)){
            if (s3[i].codigo == j){
                total = total + s3[i].preco;
                strcpy (s[i].ext, s3[i].nome);
                a = 1;
            }
        }
        fclose(fp3);
    } while (a =! 1);
    s[i].preco = total;
    fwrite(&s[i],sizeof(Menu),1,fp);
    fclose(fp);
}


// A fun��o permite remover menus existentes

void remover_menu()
{
    system("cls");
    int i, contar=0, index=-1;
    char nmenu[MIN];
    FILE * fp;
    Menu s[MAX];
    Menu ss[MAX];
    fp = fopen("MENUS.txt", "r");
    if (fp == NULL){
        printf ("Erro!");
        return;
    }
    printf("\n Introduza o nome do menu: ");
    scanf("%s", nmenu);
    while(fread(&s[i], sizeof(Menu),1,fp)){
        ss[contar]=s[i];
        contar++;
    }
    for(int i = 0; i<contar; i++)
    {
        if(ss[i].nomemenu == nmenu){
           index = i;
        }
    }
    if(index >= 0){
        for (int i = index; i < contar; i++) {
            ss[i] = ss[i + 1];
        }
        contar = contar - 1;
        fclose(fp);

        FILE *fpp;
        fpp = fopen("MENUS.txt", "w");
        if (fpp == NULL){
            printf ("Erro!");
            return;
        }
        for(i = 0; i < contar; i++)
            fwrite(&ss[i],sizeof(Menu),1,fp);

        fclose(fpp);
        printf("\n Menu removido com sucesso!");
    }
    else{
        printf("Menu n�o encontrado!");
        fclose(fp);
    }
}


// fun��o que lista todas as encomendas

void listar_encomendas()
{
    system("cls");
    FILE *fp;
    fp = fopen("encomendas.txt", "rb");
    Encomenda s[MAX];
    int i;
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    printf (" ----Lista de Encomendas----");
    while(fread(&s[i], sizeof(Encomenda),1,fp))
    {

        printf ("\n Nome do Cliente: %s %s", s[i].nome_3, s[i].nome_4);
        printf ("\n NIF do cliente: %d", s[i].NIF2);
        printf ("\n Hamb�rger: %s", s[i].ham);
        printf ("\n Bebida: %s", s[i].beb);
        printf ("\n Aperitivo: %s", s[i].ext);
        printf ("\n Pre�o: %f", s[i].preco);
    }
    fclose(fp);
    getchar();
    getchar();
    return;
}


// Fun��o para criar uma nova encomenda

void nova_encomenda()
{
    system("cls");
    Encomenda s[MAX];
    Menu s1[MAX];
    Cliente s3[MAX];
    int i, n;
    int helpNIF;
    char help[20];

    FILE *fp;
    fp = fopen("encomendas.txt", "ab");
    if (fp == NULL){
        printf ("Erro");
        return;
    }

    FILE *fp1;
    fp1 = fopen("MENUS.txt", "rb");
    if (fp == NULL){
        printf ("Erro");
        return;
    }



    FILE *fh;
    fh = fopen ("listadeclientes.txt", "r");
    if (fh == NULL){
        printf ("Erro");
        return;
    }


    printf ("\n ----Lista de Menus----");
    while(fread(&s1[i], sizeof(Menu),1,fp1))
    {
        printf ("\n Nome do Menu: %s", s1[i].nomemenu);
        printf ("\n Hamb�rger: %s", s1[i].ham);
        printf ("\n Bebida: %s", s1[i].beb);
        printf ("\n Aperitivo: %s", s1[i].ext);
        printf ("\n Pre�o: %.2f", s1[i].preco);
    }


    int x=0;
    do{
        printf ("\n Insira o nome do menu: ");
        scanf ("%s", help);
        rewind(fp1);
        while(fread(&s1[i], sizeof(Menu),1,fp1))
        {
            if(strcmp(s1[i].nomemenu, help)==0)
            {
                strcpy (s[i].ham, s1[i].ham);
                strcpy (s[i].beb, s1[i].beb);
                strcpy (s[i].ext, s1[i].ext);
                s[i].preco = s1[i].preco;
                x = 1;
            }
        }
    } while (x==0);

    x=0;
    do{
        printf ("\n Insira o NIF do cliente: ");
        scanf ("%d", &helpNIF);
        rewind(fh);
        while (fread(&s3[i],sizeof(Cliente),1,fh))
        {
            if(s3[i].NIF == helpNIF)
            {
                strcpy(s[i].nome_3, s3[i].nome_1);
                strcpy(s[i].nome_4, s3[i].nome_2);
                s[i].NIF2 = s3[i].NIF;
                x = 1;
                getchar();getchar();
            }
        }
    } while (x==0);


    fwrite(&s[i],sizeof(Encomenda),1,fp);

    fclose(fp1);
    fclose(fh);
    fclose(fp);
    getchar();
    return;
}


//Fun��o que lista todos os clientes

void listar_clientes()
{
    system("cls");
    int i, d;
    FILE *fp;
    Cliente s[MAX];
    fp = fopen("listadeclientes.txt", "r");
    if (fp == NULL){
        printf ("Erro");
        return;
    }

    printf ("\n ----Lista de Clientes----");
    while(fread(&s[i], sizeof(Cliente),1,fp))
        {
            printf ("\n Nome: %s \n", s[i].nome_1);
            printf (" Sobrenome: %s \n", s[i].nome_2);
            printf (" Idade: %d \n", s[i].idade);
            printf (" Telefone: %d \n", s[i].telefone);
            printf (" NIF: %d \n", s[i].NIF);
            printf (" -------------------------\n");
        }
    fclose(fp);
    getchar();
    getchar();
    return;
}


//Fun��o que insere n numeros de clientes

void novocliente()
{
    system("cls");
    int i, n;
    FILE *fp;
    fp = fopen("listadeclientes.txt", "a");
    Cliente s[MAX];
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    do{
        printf ("\n Quantos Clientes deseja inserir? \n");
        printf (" Insira um valor entre 1 e 10.\n");
        printf (" Resposta: ");
        scanf ("%d", &n);
        system("cls");
    } while(n<0 || n>10 || n==0);

    for(i = 0; i < n; i++)
    {
        printf ("Insira o nome: ");
        scanf("%s%*c", s[i].nome_1);
        printf ("Inseira o sobrenome: ");
        scanf("%s%*c", s[i].nome_2);
        printf ("Insira a idade do cliente: ");
        scanf ("%d%*c", &s[i].idade);
        printf ("Insira o numero de telefone: ");
        scanf ("%d%*c", &s[i].telefone);
        if (s[i].telefone<900000000 || s[i].telefone>999999999){
            printf ("Insira um numero de telefone v�lido!");
            getchar();
            return;
        }
        printf ("Insira o NIF: ");
        scanf ("%d%*c", &s[i].NIF);
        if (s[i].NIF<100000000 || s[i].NIF>999999999){
            printf ("Insira um valor de NIF v�lido!");
            getchar();
            return;
        }

        fwrite(&s[i],sizeof(Cliente),1,fp);
    }
    fclose(fp);
    return;
}


//Fun��o para procurar os dados dos clientes pelo NIF

void procurar_cliente()
{
    system("cls");
    int i, nif;
    Cliente n[MAX];
    FILE * fp;
    fp = fopen("listadeclientes.txt", "r");
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    printf ("Introduza o NIF para procurar: ");
    scanf ("%d", &nif);

    while (fread(&n, sizeof(Cliente),1,fp))
        {
            if(n[i].NIF == nif){
                printf (" Nome: %s \n", n[i].nome_1);
                printf (" Sobrenome: %s \n", n[i].nome_2);
                printf (" Idade: %d \n", n[i].idade);
                printf (" Telefone: %d \n", n[i].telefone);
                printf (" NIF: %d \n", n[i].NIF);
                printf (" -------------------------\n");
            }
            else{
                system("cls");
                printf("\n N�o Existe um cliente com esse NIF.");
            }
        }
    fclose(fp);
    getchar();
    getchar();
    return;
}


//Fun��o para alterar dados do cliente

void update_cliente()
{
    system("cls");
    int i, nif, contar=0, index=-1;
    FILE * fp;
    Cliente s[MAX];
    Cliente ss[MAX];
    fp = fopen("listadeclientes.txt", "r");
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    printf("\nIntroduza o nif:");
    scanf("%d", &nif);
    while(fread(&s[i], sizeof(Cliente),1,fp)){
        ss[contar]=s[i];
        contar++;
    }
    for(int i = 0; i<contar; i++){
        if(ss[i].NIF == nif){
            index = i;
        }
    }
    printf ("Insira o novo nome: ");
    scanf("%s", ss[index].nome_1);
    printf ("Inseira o novo sobrenome: ");
    scanf("%s", ss[index].nome_2);
    printf ("Insira a nova idade do cliente: ");
    scanf ("%d", &ss[index].idade);
    printf ("Insira o novo numero de telefone: ");
    scanf ("%d", &ss[index].telefone);

    if(index >= 0){
        fclose(fp);

        FILE *fpp;
        fpp = fopen("listadeclientes.txt", "w");
        if (fpp == NULL){
            printf ("Erro");
            return;
        }
        for(i = 0; i < contar; i++)
            fwrite(&ss[i],sizeof(Cliente),1,fp);

        fclose(fpp);
        printf("\nArtigo removido com sucesso!");
    }
    else{
        printf("Nif n�o encontrado!");
        fclose(fp);
    }
}


//A fun��o permite remover um cliente

void remover_clientes()
{
    system("cls");
    int i, nif, contar=0, index=-1;
    FILE * fp;
    Cliente s[MAX];
    Cliente ss[MAX];
    fp = fopen("listadeclientes.txt", "r");
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    printf("\n Introduza o nif: ");
    scanf("%d", &nif);
    while(fread(&s[i], sizeof(Cliente),1,fp)){
        ss[contar]=s[i];
        contar++;
    }
    for(int i = 0; i<contar; i++)
    {
        if(ss[i].NIF == nif){
           index = i;
        }
    }
    if(index >= 0){
        for (int i = index; i < contar; i++) {
            ss[i] = ss[i + 1];
        }
        contar = contar - 1;
        fclose(fp);

        FILE *fpp;
        fpp = fopen("listadeclientes.txt", "w");
        if (fpp == NULL){
            printf ("Erro");
            return;
        }
        for(i = 0; i < contar; i++)
            fwrite(&ss[i],sizeof(Cliente),1,fp);
        fclose(fpp);
        printf("\nArtigo removido com sucesso!");
    }
    else{
        printf("Nif n�o encontrado!");
        fclose(fp);
    }
}


//A fun��o permite remover um hamburguer;

void remover_ham()
{
    system("cls");
    int i, contar=0, index=-1;
    char nnome[MIN];
    FILE * fp;
    HArtigo s[MAX];
    HArtigo ss[MAX];
    fp = fopen("Hamburgers.txt", "rb");
    if (fp == NULL){
        printf ("Erro!");
        return;
    }
    printf("\n Introduza o nome do Hamb�rguer: ");
    scanf("%s", nnome);
    while(fread(&s[i], sizeof(HArtigo),1,fp)){
        ss[contar]=s[i];
        contar++;
    }
    for(int i = 0; i<contar; i++)
    {
        if(strcmp(ss[i].nome, nnome)==0){
           index = i;
        }
    }
    if(index >= 0){
        for (int i = index; i < contar; i++) {
            ss[i] = ss[i + 1];
        }
        contar = contar - 1;
        fclose(fp);

        FILE *fpp;
        fpp = fopen("Hamburgers.txt", "wb");
        if (fpp == NULL){
            printf ("Erro!");
            return;
        }
        for(i = 0; i < contar; i++)
            fwrite(&ss[i],sizeof(HArtigo),1,fp);

        fclose(fpp);
        printf("\nArtigo removido com sucesso!");
    }
    else{
        printf("Nome n�o encontrado!");
        fclose(fp);
    }
}


// A fun��o permite remover uma bebida

void remover_beb()
{
    system("cls");
    int i, contar=0, index=-1;
    char nnome[MIN];
    FILE * fp;
    BArtigo s[MAX];
    BArtigo ss[MAX];
    fp = fopen("Bebidas.txt", "rb");
    if (fp == NULL){
        printf ("Erro!");
        return;
    }
    printf("\n Introduza o nome da bebida: ");
    scanf("%s", nnome);
    while(fread(&s[i], sizeof(BArtigo),1,fp)){
        ss[contar]=s[i];
        contar++;
    }
    for(int i = 0; i<contar; i++)
    {
        if(strcmp(ss[i].nome, nnome)==0){
           index = i;
        }
    }
    if(index >= 0){
        for (int i = index; i < contar; i++) {
            ss[i] = ss[i + 1];
        }
        contar = contar - 1;
        fclose(fp);

        FILE *fpp;
        fpp = fopen("Bebidas.txt", "wb");
        if (fpp == NULL){
            printf ("Erro!");
            return;
        }
        for(i = 0; i < contar; i++)
            fwrite(&ss[i],sizeof(BArtigo),1,fp);

        fclose(fpp);
        printf("\n Artigo removido com sucesso!");
    }
    else{
        printf("\n Nome n�o encontrado!");
        fclose(fp);
    }
}

//A Fun��o permite remover um aperitivo

void remover_ape()
{
    system("cls");
    int i, contar=0, index=-1;
    char nnome[MIN];
    FILE * fp;
    EArtigo s[MAX];
    EArtigo ss[MAX];
    fp = fopen("Aperitivos.txt", "rb");
    if (fp == NULL){
        printf ("Erro!");
        return;
    }
    printf("\n Introduza o nome do aperitivo: ");
    scanf("%s", nnome);
    while(fread(&s[i], sizeof(EArtigo),1,fp)){
        ss[contar]=s[i];
        contar++;
    }
    for(int i = 0; i<contar; i++)
    {
        if(strcmp(ss[i].nome, nnome)==0){
           index = i;
        }
    }
    if(index >= 0){
        for (int i = index; i < contar; i++) {
            ss[i] = ss[i + 1];
        }
        contar = contar - 1;
        fclose(fp);

        FILE *fpp;
        fpp = fopen("Aperitivos.txt", "wb");
        if (fpp == NULL){
            printf ("Erro!");
            return;
        }
        for(i = 0; i < contar; i++)
            fwrite(&ss[i],sizeof(EArtigo),1,fp);

        fclose(fpp);
        printf("\n Artigo removido com sucesso!");
    }
    else{
        printf("\n Nome n�o encontrado!");
        fclose(fp);
    }
}


char menu_remover_artigo()
{
    char op;
    printf ("\n ----------------------------------------\n");
    printf (" ---Que Tipo De Produto Deseja Remover---\n");
    printf (" --------------(1)Hamburger--------------\n");
    printf (" ----------------(2)Bebida---------------\n");
    printf (" ------------(3)Acompanhamento-----------\n");
    printf (" -----------------(4)Sair----------------\n");
    printf (" ----------------------------------------\n");
    scanf ("%s", &op);
    return op;
}

void remover_artigo()
{
    char op;
    do
    {
        system("cls");
        op = menu_remover_artigo();
        switch(op)
        {
            case '1':
                remover_ham();
                break;
            case '2':
                remover_beb();
                break;
            case '3':
                remover_ape();
                break;
        }
    }   while(op!='4'); system("cls");
}


//Inserir novo Hamburger

void inserir_novo_artigo_hamburger()
{
    system("cls");
    int n, i;
    do{
        printf ("\n Quantos Produtos deseja inserir? \n");
        printf (" Insira um valor entre 1 e 10.\n");
        printf (" Resposta: ");
        scanf ("%d", &n);
        system("cls");
    } while(n<0 || n>10 || n==0);

    FILE *fp;
    HArtigo s[MAX];
    fp = fopen("Hamburgers.txt","ab");

    if (fp == NULL)
    {
        printf ("Erro");
        return;
    }
    for (i = 0; i < n; i++)
    {
        printf (" C�digo: ");
        scanf("%d%*c", &s[i].codigo);
        printf (" Nome: ");
        gets (s[i].nome);
        printf (" Pre�o: ");
        scanf ("%f%*c", &s[i].preco);
        fwrite (&s[i],sizeof(HArtigo),1,fp);
    }
    fclose(fp);
    return;
}


//Inserir nova bebida

void inserir_novo_artigo_bebida()
{
    system("cls");
    int n, i;
    do{
        printf ("\n Quantos produtos deseja inserir? \n");
        printf (" Insira um valor entre 1 e 10.\n");
        printf (" Resposta: ");
        scanf ("%d", &n);
        system("cls");
    } while(n<0 || n>10 || n==0);

    FILE *fp;
    BArtigo s[MAX];
    fp = fopen("Bebidas.txt","ab");

    if (fp == NULL)
    {
        printf ("Erro");
        return;
    }
    for (i = 0; i < n; i++)
    {
        printf (" C�digo: ");
        scanf("%d%*c", &s[i].codigo);
        printf (" Nome: ");
        gets (s[i].nome);
        printf (" Pre�o: ");
        scanf ("%f%*c", &s[i].preco);
        fwrite (&s[i],sizeof(BArtigo),1,fp);
    }
    fclose(fp);
    return;
}


//Inserir novo aperitivo

void inserir_novo_artigo_aperitivos()
{
    system("cls");
    int n, i;
    do{
        printf ("\n Quantos Produtos deseja inserir? \n");
        printf (" Insira um valor entre 1 e 10.\n");
        printf (" Resposta: ");
        scanf ("%d", &n);
        system("cls");
    } while(n<0 || n>10 || n==0);

    FILE *fp;
    fp = fopen("Aperitivos.txt","ab");
    EArtigo s[MAX];

    if (fp == NULL)
    {
        printf ("Erro");
        return;
    }
    for (i = 0; i < n; i++)
    {
        printf (" C�digo: ");
        scanf("%d%*c", &s[i].codigo);
        printf (" Nome: ");
        gets (s[i].nome);
        printf (" Pre�o: ");
        scanf ("%f%*c", &s[i].preco);
        fwrite (&s[i],sizeof(EArtigo),1,fp);
    }
    fclose(fp);
    return;
}


char menu_inserir_novo_artigo()
{
    char op;
    printf ("\n ----------------------------------------\n");
    printf (" ---Que Tipo De Produto Deseja Inserir---\n");
    printf (" --------------(1)Hamburger--------------\n");
    printf (" ----------------(2)Bebida---------------\n");
    printf (" ------------(3)Acompanhamento-----------\n");
    printf (" -----------------(4)Sair----------------\n");
    printf (" ----------------------------------------\n");
    scanf ("%s", &op);
    return op;
}

void inserir_novo_artigo()
{
    char op;
    do
    {
        system("cls");
        op = menu_inserir_novo_artigo();
        switch(op)
        {
            case '1':
                inserir_novo_artigo_hamburger();
                break;
            case '2':
                inserir_novo_artigo_bebida();
                break;
            case '3':
                inserir_novo_artigo_aperitivos();
                break;
        }
    }   while(op!='4'); system("cls");
}


//Listar todos os Hamb�rgeres, bebidas e acompanhamentos.

void listar_artigos()
{
    system("cls");
    HArtigo s1[MAX];
    FILE *fp1;
    fp1 = fopen ("Hamburgers.txt", "rb");
    int i;

    if (fp1 == NULL){
        printf ("Erro");
        return;
    }

    printf ("\n ----------Hamburgers----------\n");
    while (fread(&s1[i], sizeof(HArtigo),1,fp1)){
        printf (" C�digo: %d \n Nome: %s \n Pre�o: %.2f \n\n", s1[i].codigo, s1[i].nome, s1[i].preco);
    }
    fclose(fp1);

    BArtigo s2[MAX];
    FILE *fp2;
    fp2 = fopen ("Bebidas.txt", "rb");

    if (fp2 == NULL){
        printf ("Erro");
        return;
    }

    printf (" ----------Bebidas----------\n");
    while (fread(&s2[i], sizeof(BArtigo),1,fp2)){
        printf (" C�digo: %d \n Nome: %s \n Pre�o: %.2f \n\n", s2[i].codigo, s2[i].nome, s2[i].preco);
    }
    fclose(fp2);

    EArtigo s3[MAX];
    FILE *fp3;
    fp3 = fopen ("Aperitivos.txt", "rb");
    int j;

    if (fp3 == NULL){
        printf ("Erro");
        return;
    }

    printf (" ---------Aperitivos----------\n");
    while (fread(&s3[i], sizeof(EArtigo),1,fp3)){
        printf (" C�digo: %d \n Nome: %s \n Pre�o: %.2f \n\n", s3[i].codigo, s3[i].nome, s3[i].preco);
    }
    fclose(fp3);
    getchar();
    getchar();
    return;
}


//Fun��o que permite ver o total faturado

void total_faturado()
{
    system("cls");
    FILE *fp;
    fp = fopen("encomendas.txt", "rb");
    int i;
    float total;
    Encomenda s[MAX];
    if (fp == NULL){
        printf ("Erro");
        return;
    }
    while(fread(&s[i],sizeof(Encomenda),1,fp)){
        total = total + s[i].preco;
    }
    printf("\n Total Faturado: %.2f", total);
    fclose(fp);
    return;
}

char menufaturacao()
{
    char op;
    printf ("\n -----------------------------------\n");
    printf (" --------------Fatura��o------------\n");
    printf (" ---------(1)Total Faturado---------\n");
    printf (" --------------(2)Sair--------------\n");
    printf (" -----------------------------------\n\n");
    printf (" Op��o: ");
    scanf ("%s", &op);
    return op;
}

void faturacao()
{
    char op;
    do
    {
        system("cls");
        op = menufaturacao();
        switch (op)
        {
            case '1':
                total_faturado();
                break;
        }
    }
    while (op !='2'); system ("cls");
    return;
}


char menu_menus()
{
    char op;
    printf ("\n ----------------------------\n");
    printf (" ------------MENUS-----------\n");
    printf (" -------(1)Listar Menu-------\n");
    printf (" --------(2)Novo Menu--------\n");
    printf (" ------(3)Remover Menu-------\n");
    printf (" -----------(4)Sair----------\n");
    printf (" ----------------------------\n\n");
    printf (" Op��o: ");
    scanf ("%s", &op);
    return op;
}

void omenu()
{
    char op;
    do
    {
        system("cls");
        op = menu_menus();
        switch (op)
        {
            case '1':
                listar_menus();
                break;
            case '2':
                novo_menu();
                break;
            case '3':
                remover_menu();
                break;
        }
    }while (op !='4'); system ("cls");
    return;
}

char menu_gerir_encomendas()
{
    char op;
    printf ("\n ----------------------------------\n");
    printf (" ---------Gerir Encomendas---------\n");
    printf (" -------(1)Listar Encomendas-------\n");
    printf (" ---------(2)Nova Encomenda--------\n");
    printf (" --------------(3)Sair-------------\n");
    printf (" ----------------------------------\n\n");
    printf (" Op��o: ");
    scanf ("%s", &op);
    return op;
}

void gerir_encomendas()
{
    char op;
    do
    {
        system("cls");
        op = menu_gerir_encomendas();
        switch (op)
        {
            case '1':
                listar_encomendas();
                break;
            case '2':
                nova_encomenda();
                break;
        }
    }
    while (op !='3'); system ("cls");
    return;
}


char menu_gerir_clientes()
{
    char op;
    printf ("\n ---------------------------------------\n");
    printf (" -------------Gerir Clientes------------\n");
    printf (" -----------(1)Listar Clientes----------\n");
    printf (" ---------(2)Inserir Novo Cliente-------\n");
    printf (" ----------(3)Procurar Cliente----------\n");
    printf (" ----------(4)Alterar Cliente-----------\n");
    printf (" ------(5)Remover todos os Cliente------\n");
    printf (" ----------------(6)Sair---------------\n");
    printf (" --------------------------------------\n\n");
    printf (" Op��o: ");
    scanf ("%s", &op);
    return op;
}

void gerir_clientes()
{
    char op;
    do
    {
        system("cls");
        op = menu_gerir_clientes();
        switch (op)
        {
            case '1':
                listar_clientes();
                break;
            case '2':
                novocliente();
                break;
            case '3':
                procurar_cliente();
                break;
            case '4':
                update_cliente();
                break;
            case '5':
                remover_clientes();
                break;
        }
    }
    while (op != '6'); system("cls");
    return;
}


char menu_gerir_artigos()
{
    char op;
    printf ("\n -------------------------------------\n");
    printf (" -------------Gerir Artigos------------\n");
    printf (" -----------(1)Listar Artigos----------\n");
    printf (" ---------(2)Inserir Novo Artigo-------\n");
    printf (" -----------(3)Remover Artigo----------\n");
    printf (" ----------------(4)Sair---------------\n");
    printf (" --------------------------------------\n\n");
    printf (" Op��o: ");
    scanf ("%s", &op);
    return op;
}


void gerir_artigos()
{
    char op;
    do
    {
        system("cls");
        op = menu_gerir_artigos();
        switch (op)
        {
            case '1':
                listar_artigos();
                break;
            case '2':
                inserir_novo_artigo();
                break;
            case '3':
                remover_artigo();
                break;
        }
    }
    while (op != '4'); system("cls");
    return;
}



char adminstrador()
{
    char op;
    printf ("\n --------------------------------------\n");
    printf (" ------------------MENU----------------\n");
    printf (" -----------(1)Gerir Artigos-----------\n");
    printf (" -----------(2)Gerir Clientes----------\n");
    printf (" ----------(3)Gerir Encomendas---------\n");
    printf (" ------------(4)Gerir Menus------------\n");
    printf (" -------------(5)Fatura��o-------------\n");
    printf (" ----------------(6)Sair---------------\n");
    printf (" --------------------------------------\n\n");
    printf (" Op��o: ");
    scanf ("%s", &op);
    return op;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    system("color 7C");
    char op;
    do
    {
        system("cls");
        op = adminstrador();
        switch (op)
        {
            case '1':
                gerir_artigos();
                break;
            case '2':
                gerir_clientes();
                break;
            case '3':
                gerir_encomendas();
                break;
            case '4':
                omenu();
                break;
            case '5':
                faturacao();
                break;
        }
    }
    while (op !='6');
    system("cls");
    printf ("A fechar o programa...");
    return 0;
}

