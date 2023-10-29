#include "libraries.h"

char **global_argv = NULL;
int global_argc = 0;

// arguments functions
void verify_arguments(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        argument_error(argv[0]); 
    }
}

void save_arguments(int argc, char *argv[])
{
    global_argc = argc;
    global_argv = argv;
}

// functions to open and close files
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

// char / string functions
void replace_newline(char *string) 
{
    size_t length = strlen(string);

    if (string[length - 1] == '\n') 
    {
        string[length - 1] = '\0';
    }
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

// auxiliar functions
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

// functions to help with the state machine
char *state_to_string(state_t state)
{
    if(state == ST_SRT)
    {
        return "ST_SRT";
    }
    else if(state == ST_ID)
    {
        return "ST_ID";
    }
    else if(state == ST_NUM)
    {
        return "ST_NUM";
    }
    else if(state == ST_ADD)
    {
        return "ST_ADD";
    }
    else if(state == ST_SUB)
    {
        return "ST_SUB";
    }
    else if(state == ST_MUL)
    {
        return "ST_MUL";
    }
    else if(state == ST_LT)
    {
        return "ST_LT";
    }
    else if(state == ST_GT)
    {
        return "ST_GT";
    }
    else if(state == ST_LE)
    {
        return "ST_LE";
    }
    else if(state == ST_GE)
    {
        return "ST_GE";
    }
    else if(state == ST_EQ)
    {
        return "ST_EQ";
    }
    else if(state == ST_LE)
    {
        return "ST_LE";
    }
    else if(state == ST_GE)
    {
        return "ST_GE";
    }
    else if(state == ST_EQ)
    {
        return "ST_EQ";
    }
    else if(state == ST_ASG)
    {
        return "ST_ASG";
    }
    else if(state == ST_NE)
    {
        return "ST_NE";
    }
    else if(state == ST_SEM)
    {
        return "ST_SEM";
    }
    else if(state == ST_COM)
    {
        return "ST_COM";
    }
    else if(state == ST_LPA)
    {
        return "ST_LPA";
    }
    else if(state == ST_RPA)
    {
        return "ST_RPA";
    }
    else if(state == ST_LBK)
    {
        return "ST_LBK";
    }
    else if(state == ST_RBK)
    {
        return "ST_RBK";
    }
    else if(state == ST_LBC)
    {
        return "ST_LBC";
    }
    else if(state == ST_RBC)
    {
        return "ST_RBC";
    }
    else if(state == ST_ENC)
    {
        return "ST_ENC";
    }
    else if(state == ST_INC)
    {
        return "ST_INC";
    }
    else if(state == ST_EXC)
    {
        return "ST_EXC";
    }
    else if(state == ST_ERR)
    {
        return "ST_ERR";
    }
    else if(state == ST_END)
    {
        return "ST_END";
    }

    return "UNKNOWN";
}

token_type_t state_to_token_type(state_t state)
{
    if(state == ST_ID)
    {
        return ID;
    }
    else if(state == ST_NUM)
    {
        return NUM;
    }
    else if(state == ST_ADD)
    {
        return PLUS;
    }
    else if(state == ST_SUB)
    {
        return MINUS;
    }
    else if(state == ST_MUL)
    {
        return MULTIPLY;
    }
    else if(state == ST_LT)
    {
        return LESS_THAN;
    }
    else if(state == ST_GT)
    {
        return GREATER_THAN;
    }
    else if(state == ST_LE)
    {
        return LESS_THAN_EQUAL;
    }
    else if(state == ST_GE)
    {
        return GREATER_THAN_EQUAL;
    }
    else if(state == ST_EQ)
    {
        return EQUAL;
    }
    else if(state == ST_ASG)
    {
        return ASSIGN;
    }
    else if(state == ST_NE)
    {
        return NOT_EQUAL;
    }
    else if(state == ST_SEM)
    {
        return SEMICOLON;
    }
    else if(state == ST_COM)
    {
        return COMMA;
    }
    else if(state == ST_LPA)
    {
        return LEFT_PAREN;
    }
    else if(state == ST_RPA)
    {
        return RIGHT_PAREN;
    }
    else if(state == ST_LBK)
    {
        return LEFT_BRACKET;
    }
    else if(state == ST_RBK)
    {
        return RIGHT_BRACKET;
    }
    else if(state == ST_LBC)
    {
        return LEFT_BRACE;
    }
    else if(state == ST_RBC)
    {
        return RIGHT_BRACE;
    }
    else if(state == ST_ENC)
    {
        return DIVIDE;
    }
    else if(state == ST_INC)
    {
        return COMMENT_END;
    }
    else if(state == ST_EXC)
    {
        return COMMENT_END;
    }
    return UNKNOWN;
}

token_type_t reserved_word_token_type(const char *word) 
{
    if (strcmp(word, "else") == 0) 
    {
        return ELSE;
    } 
    else if (strcmp(word, "if") == 0) 
    {
        return IF;
    } 
    else if (strcmp(word, "int") == 0) 
    {
        return INT;
    } 
    else if (strcmp(word, "return") == 0) 
    {
        return RETURN;
    } 
    else if (strcmp(word, "void") == 0) 
    {
        return VOID;
    } 
    else if (strcmp(word, "while") == 0) 
    {
        return WHILE;
    } 
    else 
    {
        return ID; 
    }
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