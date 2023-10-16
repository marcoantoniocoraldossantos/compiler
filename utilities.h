#ifndef UTILITIES_H
#define UTILITIES_H

// verify if the number of arguments is correct
void verify_arguments(int argc, char *argv[]);

// functions to open and close files
FILE *open_file(char *filename, char *mode);
void close_file(FILE *file);

// 
void replace_newline(char *string);

#endif
