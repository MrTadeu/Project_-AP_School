#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum{
    RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, RESET, LIGHTRED, LIGHTGREEN, LIGHTYELLOW, LIGHTBLUE, LIGHTMAGENTA, LIGHTCYAN, LIGHTWHITE
} ansi_color_t;

typedef enum {
    TAG_OPEN,
    TAG_CLOSE
} tag_t;

typedef enum {
    FOREGROUND,
    BACKGROUND
} color_type_t;

typedef struct {
    ansi_color_t stack[16];
    int ptr;
} colorstack_t;

typedef struct {
    ansi_color_t color;
    color_type_t type;
} color_t;

static const char *fg_color_strings[] = {
        [RED] = "31",
        [GREEN] = "32",
        [YELLOW] = "33",
        [BLUE] = "34",
        [MAGENTA] = "35",
        [CYAN] = "36",
        [WHITE] = "37",
        [RESET] = "0",
        [LIGHTRED] = "91",
        [LIGHTGREEN] = "92",
        [LIGHTYELLOW] = "93",
        [LIGHTBLUE] = "94",
        [LIGHTMAGENTA] = "95",
        [LIGHTCYAN] = "96",
        [LIGHTWHITE] = "97"
};

static const char *bg_color_strings[] = {
        [RED] = "41",
        [GREEN] = "42",
        [YELLOW] = "43",
        [BLUE] = "44",
        [MAGENTA] = "45",
        [CYAN] = "46",
        [WHITE] = "47",
        [RESET] = "0",
        [LIGHTRED] = "101",
        [LIGHTGREEN] = "102",
        [LIGHTYELLOW] = "103",
        [LIGHTBLUE] = "104",
        [LIGHTMAGENTA] = "105",
        [LIGHTCYAN] = "106",
        [LIGHTWHITE] = "107"
};

static const char *tag_strings[] = {
        [TAG_OPEN] = "[",
        [TAG_CLOSE] = "]"
};

static const char *color_type_strings[] = {
        [FOREGROUND] = "3",
        [BACKGROUND] = "4"
};

static const char *bold_strings[] = {
        [TAG_OPEN] = "\033[1m",
        [TAG_CLOSE] = "\033[0m"
};

static void what_color(int* string, color_t* color) {
    int i;
    for(i = 0; string[i] != '\0', i++){
        if(strcmp(string[i], "[") == 0){
            if(strcmp(string[i+1], "b") == 0 || strcmp(string[i+1], "blue") == 0){
                color->color = BLUE;
            }
            else if(strcmp(string[i+1], "g") == 0 || strcmp(string[i+1], "green") == 0)
        }
    }
}