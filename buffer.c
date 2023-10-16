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

buffer_t allocate_buffer(int size)
{
    buffer_t buffer;
    buffer.data = (char *)malloc(sizeof(char) * size);
    if (buffer.data == NULL)
    {
        memory_alocation_error("buffer");
    }

    buffer.size = size;
    buffer.line = 0;
    buffer.position = 0;

    return buffer;
}

void deallocate_buffer(buffer_t *buffer)
{
    free(buffer->data);
    buffer->data = NULL;
    buffer->size = 0;
    buffer->line = 0;
}

void fill_buffer(FILE *file, buffer_t *buffer)
{
    memset(buffer->data, '\0', buffer->size);
    buffer->position = 0;

    if (fgets(buffer->data, buffer->size, file) == NULL)
    {
        buffer->data[0] = '\0';
        return;
    }
    else
    {
        replace_newline(buffer->data);

        buffer->line++;

        if (strlen(buffer->data) == 0)
        {
            //fill_buffer(file, buffer);
        }

        return;
    }

    return;
}

void print_buffer(buffer_t *buffer)
{
    printf("line %d: \'%s\'\n", buffer->line, buffer->data);
}
/*

// buffer.c
#include "buffer.h"

void fillBuffer(FILE *inputFile, Buffer *buffer) 
{
    if (fgets(buffer->data, BUFFER_SIZE, inputFile) == NULL) 
    {
        // Handle EOF or error
        buffer->data[0] = '\0';  // Set an empty buffer
        return;
    }
    buffer->line++;
    buffer->position = 0;
}
*/