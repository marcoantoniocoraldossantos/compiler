#include "libraries.h"

ast_node_t* initialize_ast() {
    ast_node_t* root = (ast_node_t*)malloc(sizeof(ast_node_t));
    if (root != NULL) {
        root->node_kind = PROGRAM_NODE;
        strcpy(root->lexeme, "Program");
        root->lineno = 0;
        root->sibling = NULL;
        for (int i = 0; i < MAXCHILDREN; i++) {
            root->child[i] = NULL;
        }
    }
    return root;
}


// void add_child(ast_node_t *parent, ast_node_t *child) {
//     if (parent == NULL || child == NULL) {
//         return;
//     }

//     // Encontra o primeiro filho vazio do nó pai
//     int i = 0;
//     while (i < MAXCHILDREN && parent->child[i] != NULL) {
//         i++;
//     }

//     // Se o pai não tem mais espaço para filhos, retorna
//     if (i == MAXCHILDREN) {
//         return;
//     }

//     // Adiciona o novo filho ao nó pai
//     parent->child[i] = child;
// }

// void add_sibling(ast_node_t *node, ast_node_t *sibling) {
//     if (node == NULL || sibling == NULL) {
//         return;
//     }

//     // Encontra o último irmão vazio do nó
//     ast_node_t *last_sibling = node;
//     while (last_sibling->sibling != NULL) {
//         last_sibling = last_sibling->sibling;
//     }

//     // Adiciona o novo irmão ao final da lista de irmãos
//     last_sibling->sibling = sibling;
// }

void print_ast_util(ast_node_t *node, int level) {
    if (node == NULL) {
        return;
    }

    // Imprime as informações do nó baseado no nível
    for (int i = 0; i < level; i++) {
        printf("  "); // Ajusta a indentação com base no nível
    }

    printf("Node: %s\n", node->lexeme);

    // Imprime os filhos e os irmãos
    for (int i = 0; i < MAXCHILDREN; i++) {
        print_ast_util(node->child[i], level + 1);
    }
    print_ast_util(node->sibling, level);
}

void print_ast(ast_node_t *root) {
    printf("Abstract Syntax Tree:\n");
    print_ast_util(root, 0);
}

// void add_sample_nodes() {
//     // Create nodes
//     ast_node_t* root = create_ast_node(PROGRAM_NODE, "Program", 1);
//     ast_node_t* decl = create_ast_node(DECLARATION_NODE, "Declaration", 2);
//     ast_node_t* stmt = create_ast_node(STATEMENT_NODE, "Statement", 3);
//     ast_node_t* expr = create_ast_node(EXPRESSION_NODE, "Expression", 4);

//     // Add nodes to form a simple tree structure
//     add_child(root, decl);
//     add_child(root, stmt);
//     add_child(stmt, expr);

//     // Print the tree structure
//     print_ast(root);

//     // Clean up: Free memory allocated for nodes (assuming a function for freeing nodes)
//     // free_ast(root);
// }

void free_ast(ast_node_t* node) {
    if (node == NULL) {
        return;
    }

    // Free children recursively
    for (int i = 0; i < MAXCHILDREN; i++) {
        free_ast(node->child[i]);
    }

    // Free sibling
    free_ast(node->sibling);

    // Free current node
    free(node);
}