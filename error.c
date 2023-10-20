#include "error.h"
#include "arguments.h"
#include "utilities.h"

void lex_error(token_t *token, buffer_t buffer, int line, int column) 
{
   
    if (has_exclamation(token->lexeme)) 
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], line);
        fprintf(stderr, "\x1b[31mlexical error: \x1b[0m");
        fprintf(stderr, "unknown type name \x1b[1m\'!%c\'\x1b[0m; did you mean \x1b[1m'!='?\x1b[0m\n", token->lexeme[1]);

        char *before_error = get_substring(buffer.data, 0, buffer.position-1);
        char *after_error = get_substring(buffer.data, buffer.position+1, buffer.size);
        fprintf(stderr, "     %d:%d | %s\x1b[31m!%c\x1b[0m%s\n", line, buffer.position, before_error, buffer.data[buffer.position], after_error);

        
        print_spaces(line, column-1);
        fprintf(stderr, "\x1b[31m^~\x1b[0m\n");
        print_spaces(line, column-1);
        fprintf(stderr, "\x1b[32m!=\x1b[0m\n");
    } 
    else
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], line);
        fprintf(stderr, "\x1b[31mlexical error: \x1b[0m");
        fprintf(stderr, "unknown type name \x1b[1m'%c'\x1b[0m\n", token->lexeme[0]);

        char *before_error = get_substring(buffer.data, 0, buffer.position);
        char *after_error = get_substring(buffer.data, buffer.position+1, buffer.size);
        fprintf(stderr, "     %d:%d | %s\x1b[31m%c\x1b[0m%s\n", line, buffer.position, before_error, buffer.data[buffer.position], after_error);

        print_spaces(line, column);
        fprintf(stderr, "\x1b[31m^\x1b[0m\n");
    }
}

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
