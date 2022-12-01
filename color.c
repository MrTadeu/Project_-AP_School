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

typedef struct {
    int valid;
    tag_t tag;
} validator;

static const char *fg_color_strings[] = {
        [RED] = "31",
        [GREEN] = "32",
        [YELLOW] = "33",
        [BLUE] = "34",
        [MAGENTA] = "35",
        [CYAN] = "36",
        [WHITE] = "37",
        [RESET] = "0",
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
static int color_checker(const char* str, validator* valida_tag){
    int lenght_str = strlen(str);
    int i = 0;
    valida_tag->valid = 0;
    if (lenght_str == 0){
        return 0;
    }
    else{
        while(i < lenght_str){
            if(str[i] == '['){
                valida_tag->valid = 1;
                valida_tag->tag = TAG_OPEN;
                return 1;
            }
            else if(str[i] == ']'){
                valida_tag->valid = 1;
                valida_tag->tag = TAG_CLOSE;
                return 1;
            }
            i++;
        }
        
    }
}
static void what_color(int* string, color_t* color) {
    int i;
    if(strcmp(string, "[") == 0){
        if(strcmp(string, "b") == 0 || strcmp(string, "blue") == 0){
            color->color = BLUE;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "g") == 0 || strcmp(string, "green") == 0){
            color->color = GREEN;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "r") == 0 || strcmp(string, "red") == 0){
            color->color = RED;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "y") == 0 || strcmp(string, "yellow") == 0){
            color->color = YELLOW;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "m") == 0 || strcmp(string, "magenta") == 0){
            color->color = MAGENTA;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "c") == 0 || strcmp(string, "cyan") == 0){
            color->color = CYAN;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "w") == 0 || strcmp(string, "white") == 0){
            color->color = WHITE;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "br") == 0 || strcmp(string, "bred") == 0){
            color->color = RED;
            color->type = FOREGROUND;
        }
        else if(strcmp(string, "bg") == 0 || strcmp(string, "bgreen") == 0){
            color->color = GREEN;
            color->type = BACKGROUND;
        }
        else if(strcmp(string, "by") == 0 || strcmp(string, "byellow") == 0){
            color->color = YELLOW;
            color->type = BACKGROUND;
        }
        else if(strcmp(string, "bb") == 0 || strcmp(string, "bblue") == 0){
            color->color = BLUE;
            color->type = BACKGROUND;
        }
        else if(strcmp(string, "bm") == 0 || strcmp(string, "bmagenta") == 0){
            color->color = MAGENTA;
            color->type = BACKGROUND;
        }
        else if(strcmp(string, "bc") == 0 || strcmp(string, "bcyan") == 0){
            color->color = CYAN;
            color->type = BACKGROUND;
        }
        else if(strcmp(string, "bw") == 0 || strcmp(string, "bwhite") == 0){
            color->color = WHITE;
            color->type = BACKGROUND;
        }
        else if(strcmp(string, "reset") == 0 || strcmp(string, "rr") == 0){
            color->color = RESET;
            color->type = FOREGROUND;
        }
    }
}
