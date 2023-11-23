#include "libraries.h"

ast_node_t* initialize_ast() 
{
    ast_node_t* root = (ast_node_t*)malloc(sizeof(ast_node_t));

    if (root != NULL) 
    {
        root->node_kind = PROGRAM_NODE;
        strcpy(root->lexeme, "program");
        root->lineno = 0;
        root->sibling = NULL;

        for (int i = 0; i < MAXCHILDREN; i++) 
        {
            root->child[i] = NULL;
        }
    }
    return root;
}

void print_ast_util(ast_node_t *node, int level) 
{
    if (node == NULL) 
    {
        return;
    }

    for (int i = 0; i < level; i++) 
    {
        printf("  "); 
    }

    printf("node: %s\n", node->lexeme);

    for (int i = 0; i < MAXCHILDREN; i++) 
    {
        print_ast_util(node->child[i], level + 1);
    }

    print_ast_util(node->sibling, level);
}

void print_ast(ast_node_t *root) 
{
    printf("abstract syntax tree:\n");
    print_ast_util(root, 0);
}

void free_ast(ast_node_t* node) 
{
    if (node == NULL) 
    {
        return;
    }

    // Free children recursively
    for (int i = 0; i < MAXCHILDREN; i++) 
    {
        free_ast(node->child[i]);
    }

    free_ast(node->sibling);

    free(node);
}

void add_child(ast_node_t *parent, ast_node_t *child) 
{
    if (parent == NULL || child == NULL)
    {
        // Tratamento de erro ou saída antecipada, se necessário
        return;
    }

    int i;
    for (i = 0; i < MAXCHILDREN; ++i) 
    {
        if (parent->child[i] == NULL) 
        {
            parent->child[i] = child;
            return; // Adicionou o filho com sucesso
        }
    }
    // Se chegou até aqui, não foi possível adicionar o filho
    // Tratamento de erro, se necessário
}

void add_sibling(ast_node_t *node, ast_node_t *sibling) 
{
    if (node == NULL || sibling == NULL) 
    {
        // Tratamento de erro ou saída antecipada, se necessário
        return;
    }

    while (node->sibling != NULL)
    {
        node = node->sibling;
    }
    node->sibling = sibling;
}