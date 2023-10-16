#ifndef BUFFER_H
#define BUFFER_H



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

#endif
