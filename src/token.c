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
token_t* get_next_token() 
{
    // fill the buffer 
    if (global_buffer->data[global_buffer->position] == '\0') 
    {
        if (!fill_buffer(global_input_file, global_buffer)) 
        {
            return NULL;  // end of file
        }
    }

    token_t *token = initialize_token(); // initialize the token
    token = lexical_analyzer(global_input_file, global_buffer, global_bst_tree, token); // call the lexical analyzer to get what type of token it is

    return token;  // return the token
}

// function to process the token
void process_token(token_t *token, buffer_t *buffer, ast_node_t *ast_root) 
{
    if (token == NULL) 
    {
        return;
    }

    if (token->type != ERROR && token->type != UNKNOWN) 
    {
        print_token(token);
        return;
    } 
    else if (token->type == ERROR) 
    {
        lex_error(token, buffer, token->line, buffer->position);

        // TODO: implement other types of errors
    }
}

// function that returns the token type
token_type_t get_token_type(bst_node_t* root, char* lexeme) 
{
    if (root == NULL) 
    {
        return ID; // if the root is null, return ID, because there are no reserved words
    }

    // compare the lexeme with the root lexeme
    int comparison_result = strcmp(lexeme, root->lexeme);
    if (comparison_result == 0) 
    {
        return root->token_type;    // if the lexeme is equal to the root lexeme, return the token type
    } 
    else if (comparison_result < 0) 
    {
        return get_token_type(root->left, lexeme); // if the lexeme is less than the root lexeme, go to the left of the bst
    } 
    else 
    {
        return get_token_type(root->right, lexeme); // if the lexeme is greater than the root lexeme, go to the right of the bst
    }
}

// auxiliar function to identify the lexeme
token_type_t identify_lexeme(bst_node_t* root, char* lexeme) 
{
    return get_token_type(root, lexeme);
}