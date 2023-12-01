#include "libraries.h"

#define TABLE_SIZE 257

hash_entry_t* initialize_symtab()
{
    hash_entry_t* symtab = (hash_entry_t*) malloc(sizeof(hash_entry_t));
    symtab->next = NULL;
    return symtab;
}

void free_hash_table(hash_entry_t* symtab)
{
    hash_entry_t* aux = symtab;
    while (aux != NULL)
    {
        hash_entry_t* aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
}

void print_symtab(hash_entry_t* symtab)
{
    printf("printing symtab...\n");
    hash_entry_t* aux = symtab->next;
    while (aux != NULL)
    {
        printf("name: %s, data_type: %d, id_type: %d\n", aux->name, aux->data_type, aux->id_type);
        aux = aux->next;
    }
}

void semantic_analysis(ast_node_t* ast_tree, hash_entry_t* symtab)
{
    if (ast_tree == NULL) return;
    return;
}

void construct_symtab(ast_node_t* ast_tree, hash_entry_t* symtab)
{
    // if (ast_tree == NULL) return;
    // if (ast_tree->node_kind == STATEMENT_NODE)
    // {
    //     if (ast_tree->kind.statement == DECL_STMT)
    //     {
    //         insert_symbol(symtab, ast_tree->child[0], TABLE_SIZE);
    //     }
    // }
    // construct_symtab(ast_tree->child[0], symtab);
    // construct_symtab(ast_tree->child[1], symtab);
    // construct_symtab(ast_tree->child[2], symtab);
    // construct_symtab(ast_tree->sibling, symtab);
}

unsigned int hash(const char* lexeme, int table_size) 
{
    unsigned int hash_value = 0;
    for (int i = 0; lexeme[i] != '\0'; i++) 
    {
        hash_value = lexeme[i] + (hash_value << 5) - hash_value;
    }
    return hash_value % table_size;
}

void insert_symbol(hash_entry_t* symtab, ast_node_t* node, int table_size) 
{
    unsigned int index = hash(node->lexeme, table_size);

    hash_entry_t* aux = symtab[index].next;

    if (aux == NULL) 
    {
        symtab[index].next = (hash_entry_t*)malloc(sizeof(hash_entry_t));
        aux = symtab[index].next;
    } 
    else 
    {
        while (aux->next != NULL) 
        {
            aux = aux->next;
        }
        aux->next = (hash_entry_t*)malloc(sizeof(hash_entry_t));
        aux = aux->next;
    }

    //verify info about the tree node and save to insert
    // fill_entry_info(aux, node)

    //default values to insert for testing
    strcpy(aux->name, node->lexeme);
    aux->data_type = INT_DATA;
    aux->id_type = VARIABLE;
    aux->line_number = node->lineno;
    strcpy(aux->scope, "global");
    aux->scope_type = GLOBAL;

    aux->next = NULL;

    printf("\n\ninserted %s\n", aux->name);
    printf("data_type: %d\n", aux->data_type);
    printf("id_type: %d\n", aux->id_type);
    printf("line_number: %d\n", aux->line_number);
    printf("scope: %s\n", aux->scope);
}

