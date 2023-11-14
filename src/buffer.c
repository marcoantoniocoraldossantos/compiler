#include "libraries.h"

// function to initialize the buffer
buffer_t initialize_buffer(int size)
{
    buffer_t buffer;
    buffer.data = (char *)malloc(sizeof(char) * size);
    if (buffer.data == NULL)
    {
        // handle error in the error.c file
        memory_alocation_error("buffer");
    }

    buffer.size = size;
    buffer.line = 0;
    buffer.position = 0;

    for (int i = 0; i < size; i++) 
    {
        buffer.data[i] = '\0';
    }

    return buffer;
}

// function to deallocate the buffer
void deallocate_buffer(buffer_t *buffer)
{
    free(buffer->data);
    buffer->data = NULL;
    buffer->size = 0;
    buffer->line = 0;
}

// function to fill the buffer
int fill_buffer(FILE *file, buffer_t *buffer) 
{
    memset(buffer->data, '\0', buffer->size); // clear the buffer
    buffer->position = 0; // reset the position

    // if the file is empty, return 0
    if (fgets(buffer->data, buffer->size, file) == NULL) 
    {
        buffer->data[0] = '\0';
        return 0;
    }
    else // if the file is not empty, return 1 
    {
        int pos = strcspn(buffer->data, "\n\0"); // get the position of the first newline or null character
        
        if (buffer->data[pos] == '\n') // if the first character is a newline, remove it
            buffer->data[pos] = '\0'; // remove the newline character

        buffer->line++; // increment the line number
        return 1;  
    }
}

// function to print the buffer
void print_buffer(buffer_t *buffer)
{
    printf("BUFFER: \tline %d: \'%s\'\n", buffer->line, buffer->data);
}

// function to advance the position of the buffer
void advance_input_buffer(buffer_t *buffer)
{
    buffer->position++;
}