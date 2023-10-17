#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// verify if the number of arguments is correct
void verify_arguments(int argc, char *argv[]);

// functions to open and close files
FILE *open_file(char *filename, char *mode);
void close_file(FILE *file);

// 
void replace_newline(char *string);

bool is_number(char *string);

#endif
