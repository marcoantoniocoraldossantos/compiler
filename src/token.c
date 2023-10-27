#include "libraries.h"

token_t *initialize_token() 
{
    token_t *token = (token_t *)malloc(sizeof(token_t));
    if (token == NULL) 
    {
        memory_alocation_error("token");
    }
    
    token->type = -1;
    token->line = -1;
    
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
        memory_alocation_error("token node");
    }

    new_node->token = *token;

    new_node->token.lexeme = (char *)malloc(strlen(token->lexeme) + 1);
    if (new_node->token.lexeme == NULL) 
    {
        free(new_node);
        memory_alocation_error("token lexeme");
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
        printf("Token list is empty.\n");
        return;
    }

    token_node_t *current = list->head;

    // Find the maximum token name length
    int maxTokenNameLength = 0;
    while (current != NULL) 
    {
        token_t token = current->token;
        int tokenNameLength = strlen(token_type_to_string(token.type));
        if (tokenNameLength > maxTokenNameLength) 
        {
            maxTokenNameLength = tokenNameLength;
        }
        current = current->next;
    }

    printf("  %-6s | %-*s | %s\n", "line", maxTokenNameLength, "token", "lexeme");
    printf("----------------------------------------\n");

    current = list->head;
    while (current != NULL) 
    {
        token_t token = current->token;
        printf("> %-6d | %-*s | '%s'\n", token.line, maxTokenNameLength, token_type_to_string(token.type), token.lexeme);
        current = current->next;
    }
}

void free_token_list(token_list_t *list) 
{
    token_node_t *current = list->head;

    while (current != NULL) 
    {
        token_node_t *temp = current;
        current = current->next;
        free(temp->token.lexeme);
        free(temp);
    }

    free(list);  
}

token_type_t get_token_type(bst_node_t* root, char* lexeme) 
{
    if (root == NULL) 
    {
        return ID;
    }

    int comparison_result = strcmp(lexeme, root->lexeme);
    if (comparison_result == 0) 
    {
        return root->token_type;
    } 
    else if (comparison_result < 0) 
    {
        return get_token_type(root->left, lexeme);
    } 
    else 
    {
        return get_token_type(root->right, lexeme);
    }
}

token_type_t identify_lexeme(bst_node_t* root, char* lexeme) 
{

    return get_token_type(root, lexeme);
}