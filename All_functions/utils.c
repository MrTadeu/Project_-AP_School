#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

int generate_unique_numbers(int *numbers, int size) {
  // seed the random number generator
  srand(time(NULL));
  int max = 100000, min = 1000;

  int unique = 0;  // flag to store whether a unique number has been found
  int number;      // declare the number variable

  // generate a random number and check if it is unique
  while (!unique) {
    number = rand() % (max - min + 1) + min;  // generate a random number between MIN_NUMBER and MAX_NUMBER
    unique = 1;  // assume the number is unique
    for (int i = 0; i < size; i++) {  // check if the number is already in the array
      if (numbers[i] == number) {
        unique = 0;  // number is not unique
        break;
      }
    }
  }

  return number;  // return the unique number
}
