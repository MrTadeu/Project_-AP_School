#include <stdio.h>
#include <string.h>
#include <string.h>

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