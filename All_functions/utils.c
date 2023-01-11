#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
//#include "global.h"
#include "structs.h"

extern TempoAnoAtualDiferenca tempo;

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

char *capitalize(char *str){
    int i;
    lowercase(str);
    str[0] = toupper(str[0]);
    return str;
}


int isdigit_cheker(char *str){
    int i, flag = 0;
    for(i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
          flag = 1;
        }
    }
    if (flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isletter_cheker(char *str){
    int i, flag = 0;
    for(i = 0; i < strlen(str); i++){
        if(isalpha(str[i])){
          flag = 1;
        }
    }
    if (flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

void ValidarZeroUm(int num){
    if(num == 1 || num == 0){
        return;
    }
    else{
        while (num != 0 || num != 1){
            printf("\n[yellow]Escolha uma opção: Não --> 0 Sim --> 1[/yellow]\n");
            scanf("%d", &num);
        }
    return;
    }
}

void timeNow(){
    time_t now;
    time(&now);
    struct tm *tempoAgora;

    tempoAgora = localtime(&now);

    //printf("Current date and time: %04d-%02d-%02d %02d:%02d:%02d\n", tempoAgora->tm_year + 1900, tempoAgora->tm_mon + 1, tempoAgora->tm_mday, tempoAgora->tm_hour, tempoAgora->tm_min, tempoAgora->tm_sec);
}

void diferencaTempo(int mes, int dia, int hora, int minuto){
    struct tm *tempoAgora;
    timeNow();
    tempo.difMes = tempoAgora->tm_mon + 1 - mes;
    tempo.difDia = tempoAgora->tm_mday - dia;
    tempo.difHora = tempoAgora->tm_hour - hora;
    tempo.difMinuto = tempoAgora->tm_min;
}

struct tm add_time(struct tm original_time,int minutes_to_add, int hours_to_add){
    original_time.tm_min += minutes_to_add;
    original_time.tm_hour += hours_to_add;
    mktime(&original_time);
    return original_time;
}

int TempoDeTeste(int mes, int dia, int hora, int minuto, int n_TesteTempoHora, int n_TesteTempoMinuto){
    struct tm *tempoAgora;
    timeNow();
    struct tm start_datetime, end_datetime, check_datetime;

    // Inicio da data
    start_datetime.tm_year = tempoAgora->tm_year + 1900;
    start_datetime.tm_mon = mes;  // janeiro
    start_datetime.tm_mday = dia;
    start_datetime.tm_hour = hora;
    start_datetime.tm_min = minuto;
    start_datetime.tm_sec = tempoAgora->tm_sec;

    // Fim da data
    end_datetime = add_time(start_datetime, n_TesteTempoMinuto, n_TesteTempoHora);
    /* end_datetime.tm_year = tempoAgora->tm_year + 1900;
    end_datetime.tm_mon = mes;  // dezembro
    end_datetime.tm_mday = dia;
    end_datetime.tm_min = add_minutes(start_datetime, n_TesteTempoMinuto);
    end_datetime.tm_hour = add_hour(start_datetime, n_TesteTempoHora);
    end_datetime.tm_sec = tempoAgora->tm_sec; */

    //Verificar se a data está correta
    check_datetime.tm_year = tempoAgora->tm_year + 1900;
    check_datetime.tm_mon = mes;
    check_datetime.tm_mday = dia;
    check_datetime.tm_hour = hora;
    check_datetime.tm_min = minuto;
    check_datetime.tm_sec = tempoAgora->tm_sec;

    time_t start_time = mktime(&start_datetime);
    time_t end_time = mktime(&end_datetime);
    time_t check_time = mktime(&check_datetime);

    if (check_time >= start_time && check_time <= end_time) {
        return 1; // tempo certo //The date and time is between the start and end datetime.
    } else {
        printf("[red]O tempo está incorreto![/red]\n"); // The date and time is NOT between the start and end datetime.
    }
    return 0;
}
/* int generate_unique_numbers(int *numbers, int size) {
  // seed the random number generator
  srand(time(NULL));
  int max = 100000000, min = 1000;

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
} */

void generate_unique_numbers(int *array, int length) {
  // Create a set to store the unique values
  int max = 150000, min = 1000;
  int unique_values[150000 - 1000 + 1] = {0}; //<-- MAX AND MIN NEED TO BE THE SAME AS ^^ 

  // Loop through the array and check for duplicates
  for (int i = 0; i < length; i++) {
    if (unique_values[array[i] - min] == 1) {
      // Generate a new unique number and replace the duplicate
      int new_number;
      do {
        new_number = rand() % (max - min + 1) + min;
      } while (unique_values[new_number - min] == 1);
      array[i] = new_number;

      // Mark the new number as seen
      unique_values[new_number - min] = 1;
    } else {
      // Mark the current number as seen
      unique_values[array[i] - min] = 1;
    }
  }
}