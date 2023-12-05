// main function
#include "libraries.h"

// global variables
char **global_argv = NULL;
int global_argc = 0;
FILE *global_input_file = NULL;
buffer_t *global_buffer = NULL;
FILE *global_input_file;
bst_node_t *global_bst_tree;
ast_node_t *global_ast_tree;
hash_table_t *global_symtab;
char global_scope[64];

void parse(void);

int main(int argc, char *argv[]) 
{
    verify_arguments(argc, argv); // verify if the code was called correctly with "compiler <input_file>"
    save_arguments(argc, argv); // save the arguments in the global_argv and global_argc variables
    FILE *input_file = open_file(argv[1], "r"); // open the file in read mode
    buffer_t global_buffer = initialize_buffer(256); // initialize the global_buffer
    global_bst_tree = initialize_bst(); // initialize the bst
    ast_node_t *ast_tree = initialize_ast(); // initialize the ast
    global_symtab = initialize_hash_table(); // initialize the symtab
    strcpy(global_scope, "global");
    //token_t *token = NULL; // initialize the token

    save_global_variables(input_file, &global_buffer, global_bst_tree); // save the global variables
    global_ast_tree = ast_tree;
    free_ast(ast_tree); // deallocate the ast

    //printf("sintatic analysis...");

    parse();

    //print_ast(global_ast_tree);

    construct_symtab(global_ast_tree, global_symtab);
    
    semantic_analysis(global_ast_tree, global_symtab);

    if(flag_semantic_error == 0)
    {
        if(!search_in_hash_table(global_symtab, "main", "global"))
        {
            fprintf(stderr, "\x1b[1m%s:\x1b[0m\n", global_argv[1]);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "function \x1b[1m'%s'\x1b[0m not found\n", "main");
            flag_semantic_error = 1;
        }
    }

    // if(!flag_semantic_error)
    //     print_hash_table(global_symtab);

    close_file(input_file); // close the file
    deallocate_buffer(&global_buffer); // deallocate the global_buffer
    free_bst(global_bst_tree); // deallocate the bst
    free_ast(global_ast_tree); // deallocate the ast
    free_hash_table(global_symtab); // deallocate the symtab

    if(!flag_semantic_error)
        printf("\n\x1b[32mcompilation successful!\x1b[0m\n\n");

    return 0;
}
