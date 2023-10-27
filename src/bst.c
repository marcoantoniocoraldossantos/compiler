#include "libraries.h"

bst_node_t* initialize_bst() 
{
    bst_node_t* root = NULL;

    char *optimal_root = find_optimal_root();

    root = insert_bst_node(root, "return", RETURN);
    root = insert_bst_node(root, "void", VOID);
    root = insert_bst_node(root, "int", INT);
    root = insert_bst_node(root, "if", IF);
    root = insert_bst_node(root, "else", ELSE);
    root = insert_bst_node(root, "while", WHILE);

    return root;
}

void print_bst(bst_node_t* root, int level) 
{
    if (root == NULL) 
    {
        return;
    }

    print_bst(root->right, level + 1);

    for (int i = 0; i < level; i++) 
    {
        printf("   ");
    }

    printf("%s\n", root->lexeme);
    print_bst(root->left, level + 1);
}

bst_node_t* insert_bst_node(bst_node_t* root, char* lexeme, token_type_t token_type) 
{
    if (root == NULL) 
    {
        bst_node_t* new_node = (bst_node_t*)malloc(sizeof(bst_node_t));
        if (new_node == NULL) 
        {
            memory_alocation_error("bst node");
        }

        strcpy(new_node->lexeme, lexeme);
        new_node->token_type = token_type;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    int comparison_result = strcmp(lexeme, root->lexeme);
    printf("comparison result between %s and %s is %d\n", lexeme, root->lexeme, comparison_result);


    if (comparison_result < 0) 
    {
        root->left = insert_bst_node(root->left, lexeme, token_type);
    } 
    else if (comparison_result > 0) 
    {
        root->right = insert_bst_node(root->right, lexeme, token_type);
    }

    return root;
}

void free_bst(bst_node_t* root) 
{
    if (root == NULL) 
    {
        return;
    }

    free_bst(root->left);
    free_bst(root->right);
    
    free(root);
}