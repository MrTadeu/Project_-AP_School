#include <stdio.h>
#include <string.h>
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
} */
char* printf_color(const char* str){
    char red[] = "\033[0;31m";
    char blue[] = "\033[0;34m";
    char green[] = "\033[0;32m";
    char yellow[] = "\033[0;33m";
    char reset[] = "\033[0m";
    char* result = replaceWord(str, "<red>", red);
    result = replaceWord(result, "</red>", reset);
    return result;
}