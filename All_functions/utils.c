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

/* void timeNow(){
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
}*/

/*     struct Date date;
    date.year = 2020;
    date.month = 1;
    date.day = 31;
    date.hour = 12;
    date.minute = 30; */

/*     date = add_time(date, 10, 90);

    printf("New date and time: %d-%02d-%02d %02d:%02d\n", date.year, date.month, date.day, date.hour, date.minute); */

//auxiliar
int days_in_month(int month, int year) {
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

struct Date dataFinal(struct Date date, int hours, int minutes) {
    int days = 0;
    date.minute += minutes;
    while (date.minute >= 60) {
        date.minute -= 60;
        date.hour++;
    }

    date.hour += hours;
    while (date.hour >= 24) {
        date.hour -= 24;
        days++;
    }

    date.day += days;
    while (date.day > days_in_month(date.month, date.year)) {
        date.day -= days_in_month(date.month, date.year);
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

int chackIfdataExiste(struct Date dataInicaial, struct Date dataFinal, struct Date check){
    if (check.year < dataInicaial.year || check.year > dataFinal.year){
        return 0;
    }
    if (check.month < dataInicaial.month || check.month > dataFinal.month){
        return 0;
    }
    if (check.day < dataInicaial.day || check.day > dataFinal.day){
        return 0;
    }
    if (check.hour < dataInicaial.hour || check.hour > dataFinal.hour){
        return 0;
    }
    if (check.minute < dataInicaial.minute || check.minute > dataFinal.minute){
        return 0;
    }
    return 1;
}


int isValidDate(struct Date date) {
    if (date.year < 1) {
        return 0;
    }

    int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check for leap year
    if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0)) {
        monthLength[1] = 29;
    }

    if (date.month < 1 || date.month > 12) {
        return 0;
    }
    if (date.day < 1 || date.day > monthLength[date.month - 1]) {
        return 0;
    }
    if (date.hour < 0 || date.hour > 23) {
        return 0;
    }
    if (date.minute < 0 || date.minute > 59) {
        return 0;
    }
    return 1;
}

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