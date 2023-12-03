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
hash_entry_t *global_symtab;
char global_scope[64];

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

    //printf("\n");

    construct_symtab(global_ast_tree, global_symtab);
    //go_through_tree(global_ast_tree, symtab, "global");
    
    semantic_analysis(global_ast_tree, global_symtab);

    //print_hash_table(symtab);
    if(flag_semantic_error == 0)
    {
        if(!search_in_hash_table(global_symtab, "main", "global"))
        {
            printf("semantic error: main function not found\n");
            flag_semantic_error = 1;
        }
    }

    //print_hash_table(symtab);

    if(!flag_semantic_error)
        print_hash_table(global_symtab);

    //printf("freeing memory...\n");
    close_file(input_file); // close the file
    deallocate_buffer(&global_buffer); // deallocate the global_buffer
    free_bst(global_bst_tree); // deallocate the bst
    //free_ast(ast_tree); // deallocate the ast
    free_ast(global_ast_tree); // deallocate the ast
    free_hash_table(global_symtab); // deallocate the symtab

    return 0;
}