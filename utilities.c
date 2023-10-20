// libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// include all header files
#include "utilities.h"
#include "buffer.h"
#include "token.h"
#include "lexer.h"
#include "error.h"
#include "arguments.h"

char **global_argv = NULL;
int global_argc = 0;

void verify_arguments(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        argument_error(argv[0]); 
    }
}

FILE *open_file(char *filename, char *mode) 
{
    FILE *file = fopen(filename, mode);
    if (file == NULL) 
    {
        file_open_error(filename);
    }

    return file;
}

void close_file(FILE *file) 
{
    fclose(file);
}

void replace_newline(char *string) 
{
    size_t length = strlen(string);
    if (string[length - 1] == '\n') 
    {
        string[length - 1] = '\0';
    }
}

bool is_number(char *string) 
{
    int length = strlen(string);
    for (int i = 0; i < length; i++) 
    {
        if (!isdigit(string[i])) 
        {
            return false;
        }
    }
    return true;
}

void print_spaces(int line, int column)
{
    int extra = 9;
    if(line < 10)
    {
       extra += 1;
    }
    else if (line >= 10 && line < 100)
    {
        extra += 2;
    }
    else if (line >= 100 && line < 1000)
    {
        extra += 3;
    }

    if(column < 10)
    {
        extra += 1;
    }
    else if (column >= 10 && column < 100)
    {
        extra += 2;
    }
    else if (column >= 100 && column < 1000)
    {
        extra += 3;
    }

    for(int i = 0; i < extra-2; i++)
    {
        fprintf(stderr, " ");
    }
    fprintf(stderr, "|");
    for (int i = 0; i < column+1; i++) 
    {
        fprintf(stderr, " ");
    }
}

bool has_exclamation(char *string)
{
    if(string[0] == '!')
    {
        return true;
    }
    return false;
}

char *get_substring(char *string, int start, int end)
{
    char *substring = malloc(sizeof(char) * (end - start + 1));
    int j = 0;
    for(int i = start; i < end; i++)
    {
        substring[j] = string[i];
        j++;
    }
    substring[j] = '\0';
    return substring;
}

void save_arguments(int argc, char **argv) 
{
    global_argc = argc;
    global_argv = argv;
}

char_t get_char_type(char c) 
{
    if (isspace(c))
    {
        return CHAR_SPACE;
    } 
    else if (isalpha(c)) 
    {
        return CHAR_LETTER;
    } 
    else if (isdigit(c)) 
    {
        return CHAR_DIGIT;
    } 
    else if (c == '+')
    {
        return CHAR_PLUS;
    }   
    else if (c == '-')
    {
        return CHAR_MINUS;
    } 
    else if (c == '*')
    {
        return CHAR_ASTERISK;
    } 
    else if (c == '/')
    {
        return CHAR_SLASH;
    } 
    else if (c == '<')
    {
        return CHAR_LESS_THAN;
    } 
    else if (c == '>')
    {
        return CHAR_GREATER_THAN;
    } 
    else if (c == '!')
    {
        return CHAR_EXCLAMATION;
    } 
    else if (c == '=')
    {
        return CHAR_EQUALS;
    } 
    else if (c == ';')
    {
        return CHAR_SEMICOLON;
    } 
    else if (c == ',')
    {
        return CHAR_COMMA;
    } 
    else if (c == '(')
    {
        return CHAR_LPAREN;
    } 
    else if (c == ')')
    {
        return CHAR_RPAREN;
    } 
    else if (c == '{')
    {
        return CHAR_LBRACE;
    } 
    else if (c == '}')
    {
        return CHAR_RBRACE;
    } 
    else if (c == '[')
    {
        return CHAR_LBRACKET;
    } 
    else if (c == ']')
    {
        return CHAR_RBRACKET;
    } 
    else 
    {
        return CHAR_OTHER;
    }
}

char *token_type_to_string(token_type_t type)
{
    switch (type)
    {
        case ELSE:
            return "ELSE";
        case IF:
            return "IF";
        case INT:
            return "INT";
        case RETURN:
            return "RETURN";
        case VOID:
            return "VOID";
        case WHILE:
            return "WHILE";
        case PLUS:
            return "PLUS";
        case MINUS:
            return "MINUS";
        case MULTIPLY:
            return "MULTIPLY";
        case DIVIDE:
            return "DIVIDE";
        case LESS_THAN:
            return "LESS_THAN";
        case LESS_THAN_EQUAL:
            return "LESS_THAN_EQUAL";
        case GREATER_THAN:
            return "GREATER_THAN";
        case GREATER_THAN_EQUAL:
            return "GREATER_THAN_EQUAL";
        case EQUAL:
            return "EQUAL";
        case NOT_EQUAL:
            return "NOT_EQUAL";
        case ASSIGN:
            return "ASSIGN";
        case SEMICOLON:
            return "SEMICOLON";
        case COMMA:
            return "COMMA";
        case LEFT_PAREN:
            return "LEFT_PAREN";
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
        case LEFT_BRACKET:
            return "LEFT_BRACKET";
        case RIGHT_BRACKET:
            return "RIGHT_BRACKET";
        case LEFT_BRACE:
            return "LEFT_BRACE";
        case RIGHT_BRACE:
            return "RIGHT_BRACE";
        case COMMENT_START:
            return "COMMENT_START";
        case COMMENT_END:
            return "COMMENT_END";
        case ID:
            return "ID";
        case NUM:
            return "NUM";
        default:
            return "UNKNOWN";
    }
}