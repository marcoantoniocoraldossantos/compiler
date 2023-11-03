#include "libraries.h"

// main function
int main(int argc, char *argv[]) 
{
    verify_arguments(argc, argv);
    save_arguments(argc, argv);

    FILE *input_file = open_file(argv[1], "r");
    buffer_t buffer = initialize_buffer(256);
    token_t *token = NULL;

    while(1)
    {
        if(buffer.data[buffer.position] == '\0')
        {
            if(!fill_buffer(input_file, &buffer))
            {
                break;
            }
        }

        token = lexical_analyzer(input_file, &buffer);
        print_token(token);
        free_token(token);
    }

    close_file(input_file);
    deallocate_buffer(&buffer);

    return 0;
}
