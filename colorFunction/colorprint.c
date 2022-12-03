//#include "printfcolor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceWord(const char* s, const char* oldW, const char* newW){ 
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW);
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) { 
        if (strstr(&s[i], oldW) == &s[i]) { 
            cnt++;
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    }
    // Making new string of enough length 
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1); 
    i = 0; 
    while (*s) { 
        // compare the substring with the result 
        if (strstr(s, oldW) == s) { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    }
    result[i] = '\0'; 
    return result; 
}

/* void main(){
    
    char str[] = "This <red>is</red> a test string";
    char red[] = "\033[0;31m";
    char reset[] = "\033[0m";
    char* result = replaceWord(str, "<red>", red);
    result = replaceWord(result, "</red>", reset);
    printf("%s", result);
}  */
void* printf_color(const char* str){
    char red[] = "\033[0;31m";
    char blue[] = "\033[0;34m";
    char black[] = "\033[0;30m";
    char magenta[] = "\033[0;35m";
    char cyan[] = "\033[0;36m";
    char green[] = "\033[0;32m";
    char yellow[] = "\033[0;33m";
    char reset[] = "\033[0m";
    char* result = replaceWord(str, "<red>", red);
    result = replaceWord(result, "<blue>", blue);
    result = replaceWord(result, "<black>", black);
    result = replaceWord(result, "<magenta>", magenta);
    result = replaceWord(result, "<cyan>", cyan);
    result = replaceWord(result, "<green>", green);
    result = replaceWord(result, "<yellow>", yellow);
    result = replaceWord(result, "<stop>", reset);
    printf("%s", result);
}