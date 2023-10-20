#include "libraries.h"

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

int fill_buffer(FILE *file, buffer_t *buffer) 
{
    memset(buffer->data, '\0', buffer->size);
    buffer->position = 0;

    if (fgets(buffer->data, buffer->size, file) == NULL) 
    {
        buffer->data[0] = '\0';
        return 0;
    } 
    else 
    {
        int pos = strcspn(buffer->data, "\n\0");
        
        if (buffer->data[pos] == '\n')
            buffer->data[pos] = '\0';

        buffer->line++;
        return 1;  
    }
}

void print_buffer(buffer_t *buffer)
{
    printf("BUFFER: \tline %d: \'%s\'\n", buffer->line, buffer->data);
}

void advance_input_buffer(buffer_t *buffer)
{
    buffer->position++;
}