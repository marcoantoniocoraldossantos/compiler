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

    printf("> line %-6d | %-15s | '%s'\n", token->line, token_type_to_string(token->type), token->lexeme);

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

token_t* get_next_token(FILE *input_file, buffer_t *buffer, bst_node_t *bst_root) 
{
    // fill the buffer 
    if (buffer->data[buffer->position] == '\0') 
    {
        if (!fill_buffer(input_file, buffer)) 
        {
            return NULL;  // end of file
        }
    }

    // Inicializar o token
    token_t *token = initialize_token();
    token = lexical_analyzer(input_file, buffer, bst_root, token);

    return token;  // return the token
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