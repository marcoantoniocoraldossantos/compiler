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
    int error_flag = 0;

    while(1)
    {
        if(error_flag != 0)
        {
            break;
        }

        if(buffer.data[buffer.position] == '\0')
        {
            if(!fill_buffer(input_file, &buffer))
            {
                break;
            }
        }

        //advance_input_buffer(&buffer);

        token = initialize_token();
        token = lexical_analyzer(input_file, &buffer, bst_root, token);
        
        //print_token(token);

        if(token->type != ERROR && token->type != UNKNOWN)
        {
            print_token(token);
        }
        else if(token->type == ERROR)
        {
            lex_error(token, &buffer, token->line, buffer.position);
            error_flag = 1;
        }

        free_token(token); // Free token after using it
    }

    close_file(input_file);
    deallocate_buffer(&buffer);
    free_bst(bst_root);

    return 0;
}
