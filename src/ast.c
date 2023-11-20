#include "libraries.h"

void add_child(ast_node_t *parent, ast_node_t *child) 
{
    if (parent == NULL || child == NULL) 
    {
        return;
    }

    // Encontrar o primeiro filho vazio do nó pai
    int i = 0;
    while (i < MAXCHILDREN && parent->child[i] != NULL) 
    {
        i++;
    }

    // Se o pai não tem mais espaço para filhos, retorna
    if (i == MAXCHILDREN) 
    {
        return;
    }

    // Adicionar o novo filho ao nó pai
    parent->child[i] = child;
}

void add_sibling(ast_node_t *node, ast_node_t *sibling) 
{
    if (node == NULL || sibling == NULL) 
    {
        return;
    }

    // Encontrar o último irmão vazio do nó
    ast_node_t *last_sibling = node;
    while (last_sibling->sibling != NULL) 
    {
        last_sibling = last_sibling->sibling;
    }

    // Adicionar o novo irmão ao final da lista de irmãos
    last_sibling->sibling = sibling;
}
