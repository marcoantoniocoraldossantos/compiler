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

token_type_t get_token_type(bst_node_t* root, char* lexeme) {
    if (root == NULL) {
        return ID;
    }

    int comparison_result = strcmp(lexeme, root->lexeme);
    if (comparison_result == 0) {
        return root->token_type;
    } else if (comparison_result < 0) {
        return get_token_type(root->left, lexeme);
    } else {
        return get_token_type(root->right, lexeme);
    }
}

token_type_t identify_lexeme(bst_node_t* root, char* lexeme) {
    if (is_number(lexeme)) {
        return NUM;
    } else {
        return get_token_type(root, lexeme);
    }
}


bst_node_t* initialize_bst() 
{
    bst_node_t* root = NULL;

    root = insert_bst_node(root, "else", ELSE);
    root = insert_bst_node(root, "if", IF);
    root = insert_bst_node(root, "int", INT);
    root = insert_bst_node(root, "return", RETURN);
    root = insert_bst_node(root, "void", VOID);
    root = insert_bst_node(root, "while", WHILE);

    root = insert_bst_node(root, "+", PLUS);
    root = insert_bst_node(root, "-", MINUS);
    root = insert_bst_node(root, "*", MULTIPLY);
    root = insert_bst_node(root, "/", DIVIDE);
    root = insert_bst_node(root, "<", LESS_THAN);
    root = insert_bst_node(root, "<=", LESS_THAN_EQUAL);
    root = insert_bst_node(root, ">", GREATER_THAN);
    root = insert_bst_node(root, ">=", GREATER_THAN_EQUAL);
    root = insert_bst_node(root, "==", EQUAL);
    root = insert_bst_node(root, "!=", NOT_EQUAL);
    root = insert_bst_node(root, "=", ASSIGN);
    root = insert_bst_node(root, ";", SEMICOLON);
    root = insert_bst_node(root, ",", COMMA);
    root = insert_bst_node(root, "(", LEFT_PAREN);
    root = insert_bst_node(root, ")", RIGHT_PAREN);
    root = insert_bst_node(root, "[", LEFT_BRACKET);
    root = insert_bst_node(root, "]", RIGHT_BRACKET);
    root = insert_bst_node(root, "{", LEFT_BRACE);
    root = insert_bst_node(root, "}", RIGHT_BRACE);
    root = insert_bst_node(root, "/*", COMMENT_START);
    root = insert_bst_node(root, "*/", COMMENT_END);

    return root;
}

void print_bst(bst_node_t* root, int level) {
    if (root == NULL) {
        return;
    }

    print_bst(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("   ");  // Adjust spaces for indentation
    }

    printf("%s\n", root->lexeme);
    print_bst(root->left, level + 1);
}

bst_node_t* insert_bst_node(bst_node_t* root, char* lexeme, token_type_t token_type) 
{
    if (root == NULL) {
        bst_node_t* new_node = (bst_node_t*)malloc(sizeof(bst_node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        strcpy(new_node->lexeme, lexeme);
        new_node->token_type = token_type;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    int comparison_result = strcmp(lexeme, root->lexeme);

    if (comparison_result < 0) {
        root->left = insert_bst_node(root->left, lexeme, token_type);
    } else if (comparison_result > 0) {
        root->right = insert_bst_node(root->right, lexeme, token_type);
    }

    return root;
}

void free_bst(bst_node_t* root) 
{
    if (root == NULL) {
        return;
    }

    free_bst(root->left);
    free_bst(root->right);
    free(root);
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