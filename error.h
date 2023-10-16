// error.h
#ifndef ERROR_H
#define ERROR_H

void memory_alocation_error(char *caller);
void file_open_error(char *file_name);
void argument_error(char *program_name);

#endif