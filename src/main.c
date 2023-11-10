// main function
#include "libraries.h"

int main(int argc, char *argv[]) 
{
    verify_arguments(argc, argv);
    save_arguments(argc, argv);

    FILE *input_file = open_file(argv[1], "r");
    buffer_t buffer = initialize_buffer(256);
    bst_node_t *bst_root = initialize_bst();
    token_t *token = NULL;

    while(1)
    {
        // fill the buffer, if it finds the end of file, it will return 0 and break the loop
        if (!handle_buffer_end(input_file, &buffer)) break; 

        // get the next token  
        token_t *token = get_next_token(input_file, &buffer, bst_root);
        
        if (token != NULL) 
        {
            process_token(token, &buffer);
        } 
        else 
        {
            break;
        }

        free_token(token); // free token memory
    }

    close_file(input_file);
    deallocate_buffer(&buffer);
    free_bst(bst_root);

    return 0;
}