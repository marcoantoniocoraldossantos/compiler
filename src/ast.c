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

    if (node->child[0] != NULL) 
    {
        print_ast_util(node->child[0]->sibling, level);
    }
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

ast_node_t* new_node(node_kind_t kind, const char* lexeme) {
    ast_node_t* new_node = (ast_node_t*)malloc(sizeof(ast_node_t));
    if (new_node != NULL) {
        new_node->node_kind = kind;
        new_node->lineno = 1;
        strcpy(new_node->lexeme, lexeme);
        new_node->sibling = NULL;
        for (int i = 0; i < MAXCHILDREN; ++i) {
            new_node->child[i] = NULL;
        }
    }
    return new_node;
}

ast_node_t* create_sample_tree() 
{
    ast_node_t* root = new_node(PROGRAM_NODE, "PROGRAM");
    ast_node_t* declaration1 = new_node(DECLARATION_NODE, "DECLARATION_1");
    ast_node_t* declaration2 = new_node(DECLARATION_NODE, "DECLARATION_2");
    ast_node_t* statement = new_node(STATEMENT_NODE, "STATEMENT");
    ast_node_t* expression = new_node(EXPRESSION_NODE, "EXPRESSION");

    root->child[0] = declaration1;
    declaration1->sibling = declaration2;
    declaration2->sibling = statement;
    statement->sibling = expression;

    ast_node_t* varDeclaration = new_node(DECLARATION_NODE, "VAR_DECLARATION");
    declaration1->child[0] = varDeclaration;

    ast_node_t* funDeclaration = new_node(DECLARATION_NODE, "FUN_DECLARATION");
    declaration2->child[0] = funDeclaration;

    ast_node_t* assignment = new_node(EXPRESSION_NODE, "ASSIGNMENT");
    statement->child[0] = assignment;

    ast_node_t* binaryExpression = new_node(EXPRESSION_NODE, "BINARY_EXPRESSION");
    expression->child[0] = binaryExpression;

    return root;
}
