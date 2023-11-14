#include "libraries.h"

// function to initialize the token
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
        // handle the error in the error.c file
        memory_alocation_error("lexeme");
    }
    memset(token->lexeme, '\0', 64);
    
    return token;
}

// function to print the token
void print_token(token_t *token)
{
    if (token == NULL) 
    {
        printf("token is NULL.\n");
        return;
    }

    printf("> line %-6d | %-20s | '%s'\n", token->line, token_type_to_string(token->type), token->lexeme);

}

// function to free the token memory
void free_token(token_t *token) 
{
    if (token == NULL) 
    {
        return;
    }
    free(token->lexeme);
    free(token);
}

// function to return the next token of the file
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

    token_t *token = initialize_token(); // initialize the token
    token = lexical_analyzer(input_file, buffer, bst_root, token); // call the lexical analyzer to get what type of token it is

    return token;  // return the token
}

// function to process the token
void process_token(token_t *token, buffer_t *buffer) 
{
    if (token->type != ERROR && token->type != UNKNOWN) 
    {
        print_token(token);
        return;
        // TODO: parser
    } 
    else if (token->type == ERROR) 
    {
        lex_error(token, buffer, token->line, buffer->position);

        // TODO: implement other types of errors
    }
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