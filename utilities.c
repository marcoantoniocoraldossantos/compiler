// libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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