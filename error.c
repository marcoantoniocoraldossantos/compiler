// libraries used
#include <stdio.h>
#include <stdlib.h>

// include all header files
#include "utilities.h"
#include "buffer.h"
#include "token.h"
#include "lexer.h"
#include "error.h"


void memory_alocation_error(char *caller) 
{
    fprintf(stderr, "error: unable to allocate memory (%s).\n", caller);
    //...
    exit(EXIT_FAILURE);
}

void file_open_error(char *file_name) 
{
    fprintf(stderr, "error: unable to open file '%s'.\n", file_name);
    //...
    exit(EXIT_FAILURE);
}

void argument_error(char *program_name) 
{
    fprintf(stderr, "error: invalid arguments\n");
    fprintf(stderr, "usage: %s <input_file>\n", program_name);
    //...
    exit(EXIT_FAILURE);
}