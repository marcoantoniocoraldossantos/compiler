#include "libraries.h"

// main function
int main(int argc, char *argv[]) 
{
    verify_arguments(argc, argv);
    save_arguments(argc, argv);

    FILE *input_file = open_file(argv[1], "r");

    token_list_t *token_list = lexical_analyzer(input_file);

    if(token_list == NULL)
    {
        printf("error: lexical analysis failed\n");
    }
    else
    {
        printf("lexical analysis successful\n");
        print_token_list(token_list);
        free_token_list(token_list);
    }

    close_file(input_file);

    return 0;
}
