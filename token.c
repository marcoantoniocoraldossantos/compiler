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

        printf("Type: %d, Line: %d, Lexeme: %s\n", token.type, token.line, token.lexeme);

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

char *token_type_to_string(token_type_t type)
{
}