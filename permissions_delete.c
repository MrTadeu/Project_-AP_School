/* void register_storage(){
    char reset_data[4], mode;
    printf("Deseja apagar os dados? [YES/NO]");
    scanf("%s", &reset_data);
    if(reset_data == "YES"){
        printf("Apagar dados");
        pontos();
        mode = "w";
    }
    else{
        printf("Não apagar dados.");
        Sleep(1);
        mode = "a";
    }
    FILE* userstxt = fopen("users.txt", mode);
} 

void pontos(){
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
}
*/