#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

char *lowercase(char *str){
    int i;
    for(i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

char *uppercase(char *str){
    int i;
    for(i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

int isdigit_cheker(char *str){
    int i;
    for(i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
            return 1;
        }
        else{
            return 0;
        }
    }
}
