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

void print_ast_util(ast_node_t* root, int num) 
{
    if (root == NULL) 
    {
        return;
    }

    for (int i = 0; i < num; i++) 
    {
        printf("\t");
    }
    printf("%s\n", root->lexeme);

    for (int i = 0; i < 3; i++) 
    {
        print_ast_util(root->child[i], num + 1);
    }
    print_ast_util(root->sibling, num);
}


void print_ast(ast_node_t *root)
{
    printf("abstract syntax tree:\n");
    print_ast_util(root, 1);
    //printf("\nnode of the abstract syntax tree:\n");
    //print_ast_node(root);
}

void free_ast(ast_node_t* node) 
{
    if (node != NULL) 
    {
        for (int i = 0; i < MAXCHILDREN; ++i) 
        {
            free_ast(node->child[i]);
        }
        free_ast(node->sibling);
        free(node);
    }
}

void add_child(ast_node_t *parent, ast_node_t *child) 
{
    if (parent == NULL || child == NULL)
    {
        return;
    }

    for (int i = 0; i < MAXCHILDREN; ++i) 
    {
        if (parent->child[i] == NULL) 
        {
            parent->child[i] = child;
            return;
        }
    }
}

void add_sibling(ast_node_t *node, ast_node_t *sibling) 
{
    if (node == NULL || sibling == NULL) 
    {
        return;
    }

    if (node->sibling == NULL) 
    {
        node->sibling = sibling;  
    } 
    else 
    {
        ast_node_t *currentSibling = node->sibling;
        while (currentSibling->sibling != NULL) 
        {
            currentSibling = currentSibling->sibling;
        }
        currentSibling->sibling = sibling; 
    }
}

ast_node_t* new_ast_node(node_kind_t kind, int line, const char* lexeme, statement_kind_t statement, expression_kind_t expression, expression_type_t type)
{
    ast_node_t* new_node = (ast_node_t*)malloc(sizeof(ast_node_t));

    if (new_node != NULL) 
    {
        new_node->node_kind = kind;
        new_node->lineno = line;
        strcpy(new_node->lexeme, lexeme);
        new_node->sibling = NULL;
        for (int i = 0; i < MAXCHILDREN; ++i) 
        {
            new_node->child[i] = NULL;
        }
        new_node->kind.statement = statement;
        new_node->kind.expression = expression;
        new_node->kind.type = type;
    }
    new_node->extended_type = EXT_NULL;
    
    return new_node;
}

void print_ast_node(ast_node_t *node) 
{
    if (node == NULL) 
    {
        return;
    }

    printf("node: %s\n", node->lexeme);
    printf("kind: %d\n", node->node_kind);
    printf("line: %d\n", node->lineno);

    switch (node->node_kind) 
    {
        case EXPRESSION_NODE:
            printf("expression\n");
            printf("kind: %d\n", node->kind.expression);
            printf("type: %d\n", node->kind.type);
            break;
        case STATEMENT_NODE:
            printf("statement\n");
            printf("kind: %d\n", node->kind.statement);
            break;
        // Adicione outros cases para diferentes tipos de nós, se necessário
        default:
            printf("unknown\n");
            break;
    }

    printf("\n");

    // Percorre os filhos do nó
    for (int i = 0; i < MAXCHILDREN; ++i) {
        print_ast_node(node->child[i]);
    }

    // Percorre os irmãos do nó
    print_ast_node(node->sibling);
}
