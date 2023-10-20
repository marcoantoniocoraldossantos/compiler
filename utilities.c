// libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// include all header files
#include "utilities.h"
#include "buffer.h"
#include "token.h"
#include "lexer.h"
#include "error.h"

char **global_argv = NULL;
int global_argc = 0;

void verify_arguments(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        argument_error(argv[0]); 
    }
}

FILE *open_file(char *filename, char *mode) 
{
    FILE *file = fopen(filename, mode);
    if (file == NULL) 
    {
        file_open_error(filename);
    }

    return file;
}

void close_file(FILE *file) 
{
    fclose(file);
}

void replace_newline(char *string) 
{
    size_t length = strlen(string);
    if (string[length - 1] == '\n') 
    {
        string[length - 1] = '\0';
    }
}

bool is_number(char *string) 
{
    int length = strlen(string);
    for (int i = 0; i < length; i++) 
    {
        if (!isdigit(string[i])) 
        {
            return false;
        }
    }
    return true;
}

void print_spaces(int line, int column)
{
    int extra = 9;
    if(line < 10)
    {
       extra += 1;
    }
    else if (line >= 10 && line < 100)
    {
        extra += 2;
    }
    else if (line >= 100 && line < 1000)
    {
        extra += 3;
    }

    if(column < 10)
    {
        extra += 1;
    }
    else if (column >= 10 && column < 100)
    {
        extra += 2;
    }
    else if (column >= 100 && column < 1000)
    {
        extra += 3;
    }

    for(int i = 0; i < extra-2; i++)
    {
        fprintf(stderr, " ");
    }
    fprintf(stderr, "|");
    for (int i = 0; i < column+1; i++) 
    {
        fprintf(stderr, " ");
    }
}

bool has_exclamation(char *string)
{
    if(string[0] == '!')
    {
        return true;
    }
    return false;
}

char *get_substring(char *string, int start, int end)
{
    char *substring = malloc(sizeof(char) * (end - start + 1));
    int j = 0;
    for(int i = start; i < end; i++)
    {
        substring[j] = string[i];
        j++;
    }
    substring[j] = '\0';
    return substring;
}

void save_arguments(int argc, char *argv[])
{
    global_argc = argc;
    global_argv = argv;
}