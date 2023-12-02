#include "libraries.h"

// arguments functions
void verify_arguments(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        argument_error(argv[0]); 
    }
}

// function to save the arguments in the global variables
void save_arguments(int argc, char *argv[])
{
    global_argc = argc;
    global_argv = argv;
}

// function to save global variables
void save_global_variables(FILE *input_file, buffer_t *buffer, bst_node_t *bst_root)
{
    global_input_file = input_file;
    global_buffer = buffer;
    global_bst_tree = bst_root;
}

// functions to open and close files
FILE *open_file(char *filename, char *mode) 
{
    FILE *file = fopen(filename, mode);
    if (file == NULL) 
    {
        // handle the error in the error.c file
        file_open_error(filename);
    }

    return file;
}

// function to close the file
void close_file(FILE *file) 
{
    fclose(file);
}

// function to check if the buffer reached the end of file
int handle_buffer_end(FILE *input_file, buffer_t *buffer) 
{
    if (buffer->data[buffer->position] == '\0') 
    {
        if (!fill_buffer(input_file, buffer)) 
        {
            return 0;  // end of file
        }
    }
    return 1;  // buffer filled successfully
}

// function to replace the newline character with the null character
void replace_newline(char *string) 
{
    size_t length = strlen(string);

    if (string[length - 1] == '\n') 
    {
        string[length - 1] = '\0';
    }
}

// function to get the substring of a string based on the start and end index
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

// auxiliar function to print the spaces in the lexical error message
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

// function to help with the state machine that returns the string of the state
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

// function to help with the state machine that returns the token type of the state
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

// function to help with the state machine that returns the character type of the current char
char_t get_char_type(char c) 
{
    if (isspace(c) || c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f' || c == '\b' || c == '\a' || c == '\0')
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

// function to help with the state machine that returns the string of the token type
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
        case UNKNOWN:
            return "UNKNOWN";
        case ERROR:
            return "ERROR";
        default:
            return "TYPE TBD";
    }
}

// function to help with the bst that returns the token type of the reserved word
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
        return UNKNOWN;
    }
}

// convert tokentype to yytokentype to int
int convert_token(token_type_t token_type)
{
    switch(token_type)
    {
        case ELSE:
            return ELSE_TOKEN;
        case IF:
            return IF_TOKEN;
        case INT:
            return INT_TOKEN;
        case RETURN:
            return RETURN_TOKEN;
        case VOID:
            return VOID_TOKEN;
        case WHILE:
            return WHILE_TOKEN;
        case PLUS:
            return PLUS_TOKEN;
        case MINUS:
            return MINUS_TOKEN;
        case MULTIPLY:
            return MULTIPLY_TOKEN;
        case DIVIDE:
            return DIVIDE_TOKEN;
        case LESS_THAN:
            return LT_TOKEN;
        case LESS_THAN_EQUAL:
            return LTE_TOKEN;
        case GREATER_THAN:
            return GT_TOKEN;
        case GREATER_THAN_EQUAL:
            return GTE_TOKEN;
        case EQUAL:
            return EQ_TOKEN;
        case NOT_EQUAL:
            return NEQ_TOKEN;
        case ASSIGN:
            return ASSIGN_TOKEN;
        case SEMICOLON:
            return SEMICOLON_TOKEN;
        case COMMA:
            return COMMA_TOKEN;
        case LEFT_PAREN:
            return LPAREN_TOKEN;
        case RIGHT_PAREN:
            return RPAREN_TOKEN;
        case LEFT_BRACKET:
            return LBRACKET_TOKEN;
        case RIGHT_BRACKET:
            return RBRACKET_TOKEN;
        case LEFT_BRACE:
            return LBRACE_TOKEN;
        case RIGHT_BRACE:
            return RBRACE_TOKEN;
        case COMMENT_START:
            return ERROR_TOKEN;
        case COMMENT_END:
            return ERROR_TOKEN;
        case ID:
            return ID_TOKEN;
        case NUM:   
            return NUM_TOKEN;   
        case UNKNOWN:
            return UNKNOW_TOKEN;
        case ERROR:
            return ERROR_TOKEN;
        default:
            return ERROR_TOKEN;
    }
}

bool ast_node_is_identifier(ast_node_t *node)
{
    if (isdigit(node->lexeme[0]))
    {
        return false;
    }

    char special_characters[] = "+-*/<>=";
    if (strchr(special_characters, node->lexeme[0]) != NULL)
    {
        return false;
    }
    else if(strcmp(node->lexeme, "else") == 0)
    {
        return false;
    }
    else if(strcmp(node->lexeme, "if") == 0)
    {
        return false;
    }
    else if(strcmp(node->lexeme, "int") == 0)
    {
        return false;
    }
    else if(strcmp(node->lexeme, "return") == 0)
    {
        return false;
    }
    else if(strcmp(node->lexeme, "void") == 0)
    {
        return false;
    }
    else if(strcmp(node->lexeme, "while") == 0)
    {
        return false;
    }
    else
    {
        //printf("\nlexeme: \'%s\' is identifier\n", node->lexeme);
        return true;
    }
}