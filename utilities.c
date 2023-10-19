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

void print_spaces(int n) 
{
    for (int i = 0; i < n + 10; i++) 
    {
        fprintf(stderr, " ");
    }
    fprintf(stderr, "^\n");
}