// main function
#include "libraries.h"

int main(int argc, char *argv[]) 
{
    verify_arguments(argc, argv); // verify if the code was called correctly with "compiler <input_file>"
    save_arguments(argc, argv); // save the arguments in the global_argv and global_argc variables

    FILE *input_file = open_file(argv[1], "r"); // open the file in read mode
    buffer_t buffer = initialize_buffer(256); // initialize the buffer
    bst_node_t *bst_tree = initialize_bst(); // initialize the bst
    ast_node_t *ast_tree = initialize_ast(); // initialize the ast
    token_t *token = NULL; // initialize the token

    save_global_variables(input_file, &buffer, bst_tree); // save the global variables

    // while(1)
    // {
    //     // fill the buffer, if it finds the end of file, it will return 0 and break the loop
    //     if (!handle_buffer_end(input_file, &buffer)) break; 

    //     // get the next token  
    //     token_t *token = get_next_token();
        
    //     // if token is not null, process it
    //     if (token != NULL) process_token(token, &buffer);
    //     else break;

    //     free_token(token); // free token memory
    // }

    printf("sintatic analysis:\n");
    ast_tree = parse();
    //print_ast(ast_tree);

    printf("freeing memory...\n");
    close_file(input_file); // close the file
    deallocate_buffer(&buffer); // deallocate the buffer
    free_bst(bst_tree); // deallocate the bst
    //free_ast(ast_tree); // deallocate the ast

    return 0;
}