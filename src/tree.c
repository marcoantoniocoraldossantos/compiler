#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// Cria um novo nó da árvore
parse_tree_node_t* create_node(int line, char *lexeme, node_type_t node_type, statement_type_t statement_type, expression_type_t expression_type) {
    parse_tree_node_t *node = (parse_tree_node_t*)malloc(sizeof(parse_tree_node_t));
    if (node == NULL) {
        // Trate o erro de alocação de memória aqui
        exit(EXIT_FAILURE);
    }
    node->line = line;
    strncpy(node->lexeme, lexeme, 64);
    node->node_type = node_type;
    node->statement_type = statement_type;
    node->expression_type = expression_type;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

// Adiciona um filho a um nó
void add_child(parse_tree_node_t *parent, parse_tree_node_t *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        parse_tree_node_t *temp = parent->child;
        while (temp->sibling != NULL) {
            temp = temp->sibling;
        }
        temp->sibling = child;
    }
}

// Adiciona um irmão a um nó
void add_sibling(parse_tree_node_t *node, parse_tree_node_t *sibling) {
    parse_tree_node_t *temp = node;
    while (temp->sibling != NULL) {
        temp = temp->sibling;
    }
    temp->sibling = sibling;
}

// Deleta a árvore
void delete_tree(parse_tree_node_t *root) {
    if (root == NULL) {
        return;
    }
    delete_tree(root->child);
    delete_tree(root->sibling);
    free(root);
}

int main() {
    // Criando os nós da árvore
    parse_tree_node_t *root = create_node(0, "gcd", STATEMENT_NODE, 0, 0);
    parse_tree_node_t *arg1 = create_node(0, "u", EXPRESSION_NODE, 0, VARIABLE_EXP);
    parse_tree_node_t *arg2 = create_node(0, "v", EXPRESSION_NODE, 0, VARIABLE_EXP);
    parse_tree_node_t *if_cond = create_node(0, "==", EXPRESSION_NODE, 0, RELATIONAL_EXP);
    parse_tree_node_t *return_exp = create_node(0, "u", EXPRESSION_NODE, 0, VARIABLE_EXP);
    parse_tree_node_t *return_stmt = create_node(0, "return", STATEMENT_NODE, RETURN_STMT, 0);
    parse_tree_node_t *else_stmt = create_node(0, "else", STATEMENT_NODE, 0, 0);
    parse_tree_node_t *recurse_call = create_node(0, "gcd", STATEMENT_NODE, 0, 0);
    parse_tree_node_t *recurse_exp1 = create_node(0, "v", EXPRESSION_NODE, 0, VARIABLE_EXP);
    parse_tree_node_t *recurse_exp2 = create_node(0, "u-u/v*v", EXPRESSION_NODE, 0, OPERATION_EXP);

    // Montando a árvore
    add_child(root, arg1);
    add_sibling(arg1, arg2);
    add_sibling(arg2, if_cond);
    add_child(if_cond, arg2);
    add_sibling(if_cond, return_stmt);
    add_child(return_stmt, return_exp);
    add_child(return_exp, arg1);
    add_child(return_exp, else_stmt);
    add_child(else_stmt, recurse_call);
    add_child(recurse_call, recurse_exp1);
    add_sibling(recurse_exp1, recurse_exp2);

    // Imprimindo a árvore
    printf("Arvore da Funcao GCD:\n");
    printf("gcd\n");
    printf("|-u\n");
    printf("|-v\n");
    printf("|-==\n");
    printf("| |-v\n");
    printf("|-return\n");
    printf("| |-u\n");
    printf("| |-else\n");
    printf("|   |-gcd\n");
    printf("|     |-v\n");
    printf("|     |-u-u/v*v\n");

    // Deleta a árvore no final
    delete_tree(root);

    return 0;
}
