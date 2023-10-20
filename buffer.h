#ifndef BUFFER_H
#define BUFFER_H

#include "libraries.h"

#include "lexer.h"
#include "token.h"
#include "error.h"
#include "utilities.h"
#include "arguments.h"

typedef struct 
{
    char *data;
    int size;
    int line;
    int position;
} buffer_t;

buffer_t allocate_buffer(int size);
void deallocate_buffer(buffer_t *buffer);
int fill_buffer(FILE *file, buffer_t *buffer);
void print_buffer(buffer_t *buffer);
void advance_input_buffer(buffer_t *buffer);

#endif
