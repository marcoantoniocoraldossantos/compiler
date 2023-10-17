// libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// include all header files
#include "utilities.h"
#include "buffer.h"
#include "token.h"
#include "lexer.h"
#include "error.h"


token_t *initialize_token() 
{
    token_t *token = (token_t *)malloc(sizeof(token_t));
    if (token == NULL) 
    {
        memory_alocation_error("token");
    }
    
    // Initialize type and line
    token->type = -1;
    token->line = -1;
    
    // Allocate memory for lexeme and initialize it to '\0'
    token->lexeme = (char *)malloc(64 * sizeof(char));
    if (token->lexeme == NULL) 
    {
        memory_alocation_error("lexeme");
    }
    memset(token->lexeme, '\0', 64);
    
    return token;
}

void print_token(token_t *token) 
{
    if (token == NULL) 
    {
        printf("token is NULL.\n");
        return;
    }

    printf("token: %d, line: %d, lexeme: %s\n", token->type, token->line, token->lexeme);
}

void free_token(token_t *token) 
{
    if (token == NULL) 
    {
        return;
    }
    free(token->lexeme);
    free(token);
}

token_list_t* initialize_token_list() 
{
    token_list_t *list = (token_list_t *)malloc(sizeof(token_list_t));
    if (list == NULL) 
    {
        memory_alocation_error("token list");
    }
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void add_token_to_list(token_list_t *list, token_t *token) 
{
    token_node_t *new_node = (token_node_t *)malloc(sizeof(token_node_t));
    if (new_node == NULL)
    {
        exit(EXIT_FAILURE);
    }

    new_node->token = *token; // Copy the provided token

    // Allocate memory for the lexeme and copy the provided lexeme
    new_node->token.lexeme = (char *)malloc(strlen(token->lexeme) + 1);
    if (new_node->token.lexeme == NULL) 
    {
        // Handle memory allocation error
        free(new_node);
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->token.lexeme, token->lexeme);

    new_node->next = NULL;

    if (list->tail == NULL) 
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else 
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->count++;
}

void print_token_list(token_list_t *list) 
{
    if (list == NULL || list->head == NULL) 
    {
        printf("token list is empty.\n");
        return;
    }

    token_node_t *current = list->head;

    while (current != NULL) 
    {
        token_t token = current->token;

        printf("line: %d token: %s lexeme: '%s'\n", token.line, token_type_to_string(token.type), token.lexeme);

        current = current->next;
    }
}

void free_token_list(token_list_t *list) 
{
    token_node_t *current = list->head;
    while (current != NULL) {
        token_node_t *temp = current;
        current = current->next;
        free(temp->token.lexeme);
        free(temp);
    }
    free(list);  
}

token_type_t get_token_type(char *lexeme)
{
    unsigned int index = hash(lexeme) % HASH_TABLE_SIZE;
    //printf("lexem %s hash %d cmp %s\n", lexeme, index, hash_table[index].lexeme);
    if(hash_table[index].lexeme != NULL && strcmp(hash_table[index].lexeme, lexeme) == 0)
    {
        //printf("returning hash %s\n", token_type_to_string(hash_table[index].type));
        return hash_table[index].type;
    }
    else
    {
        return ID;
    }
}

token_type_t identify_lexeme(char *lexeme)
{
    if(is_number(lexeme))
    {
        return NUM;
    }
    else
    {
        return get_token_type(lexeme);
    }
}

unsigned int hash(char *lexeme) 
{
    unsigned int hash_val = 0;
    for (int i = 0; lexeme[i] != '\0'; i++) 
    {
        hash_val = (hash_val << 5) + lexeme[i];
    }
    return hash_val % HASH_TABLE_SIZE;
}

void initialize_hash_table()
{   
    memset(hash_table, 0, sizeof(hash_table));

    // Operators and special symbols
    hash_table[hash("+") % HASH_TABLE_SIZE] = (token_lookup_t) {"+", PLUS};
    hash_table[hash("-") % HASH_TABLE_SIZE] = (token_lookup_t) {"-", MINUS};
    hash_table[hash("*") % HASH_TABLE_SIZE] = (token_lookup_t) {"*", MULTIPLY};
    hash_table[hash("/") % HASH_TABLE_SIZE] = (token_lookup_t) {"/", DIVIDE};
    hash_table[hash("<") % HASH_TABLE_SIZE] = (token_lookup_t) {"<", LESS_THAN};
    hash_table[hash("<=") % HASH_TABLE_SIZE] = (token_lookup_t) {"<=", LESS_THAN_EQUAL};
    hash_table[hash(">") % HASH_TABLE_SIZE] = (token_lookup_t) {">", GREATER_THAN};
    hash_table[hash(">=") % HASH_TABLE_SIZE] = (token_lookup_t) {">=", GREATER_THAN_EQUAL};
    hash_table[hash("=") % HASH_TABLE_SIZE] = (token_lookup_t) {"=", ASSIGN};
    hash_table[hash("==") % HASH_TABLE_SIZE] = (token_lookup_t) {"==", EQUAL};
    hash_table[hash("!=") % HASH_TABLE_SIZE] = (token_lookup_t) {"!=", NOT_EQUAL};
    hash_table[hash("(") % HASH_TABLE_SIZE] = (token_lookup_t) {"(", LEFT_PAREN};
    hash_table[hash(")") % HASH_TABLE_SIZE] = (token_lookup_t) {")", RIGHT_PAREN};
    hash_table[hash("[") % HASH_TABLE_SIZE] = (token_lookup_t) {"[", LEFT_BRACKET};
    hash_table[hash("]") % HASH_TABLE_SIZE] = (token_lookup_t) {"]", RIGHT_BRACKET};
    hash_table[hash("{") % HASH_TABLE_SIZE] = (token_lookup_t) {"{", LEFT_BRACE};
    hash_table[hash("}") % HASH_TABLE_SIZE] = (token_lookup_t) {"}", RIGHT_BRACE};
    hash_table[hash(";") % HASH_TABLE_SIZE] = (token_lookup_t) {";", SEMICOLON};
    hash_table[hash(",") % HASH_TABLE_SIZE] = (token_lookup_t) {",", COMMA};

    // Reserved words
    hash_table[hash("else") % HASH_TABLE_SIZE] = (token_lookup_t) {"else", ELSE};
    hash_table[hash("if") % HASH_TABLE_SIZE] = (token_lookup_t) {"if", IF};
    hash_table[hash("int") % HASH_TABLE_SIZE] = (token_lookup_t) {"int", INT};
    hash_table[hash("return") % HASH_TABLE_SIZE] = (token_lookup_t) {"return", RETURN};
    hash_table[hash("void") % HASH_TABLE_SIZE] = (token_lookup_t) {"void", VOID};
    hash_table[hash("while") % HASH_TABLE_SIZE] = (token_lookup_t) {"while", WHILE};

    // Comments
    hash_table[hash("/*") % HASH_TABLE_SIZE] = (token_lookup_t) {"/*", COMMENT_START};
    hash_table[hash("*/") % HASH_TABLE_SIZE] = (token_lookup_t) {"*/", COMMENT_END};

    printf("\'%s\'\n", hash_table[hash("else") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("if") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("int") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("return") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("void") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("while") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("+") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("-") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("*") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("/") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("<") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("<=") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash(">") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash(">=") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("==") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("!=") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("=") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash(";") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash(",") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("(") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash(")") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("[") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("]") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("{") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("}") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("/*") % HASH_TABLE_SIZE].lexeme);
    printf("\'%s\'\n", hash_table[hash("*/") % HASH_TABLE_SIZE].lexeme);
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