#include "libraries.h"

hash_table_t* initialize_hash_table() 
{
    hash_table_t* hash_table = (hash_table_t*)malloc(sizeof(hash_table_t));
    if (hash_table != NULL) 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            hash_table->table[i] = NULL;
        }
    }
    return hash_table;
}

void free_hash_table(hash_table_t* hash_table) 
{
    if (hash_table != NULL) 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            hash_entry_t* current = hash_table->table[i];
            while (current != NULL) 
            {
                hash_entry_t* temp = current;
                current = current->next;
                free(temp); 
            }
        }
        free(hash_table); 
    }
}

void print_hash_table(hash_table_t* hash_table) 
{
    printf("Hash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        hash_entry_t* current = hash_table->table[i];
        while (current != NULL) {
            printf("(Name: %s, Data Type: %d, ID Type: %d, Line: %d, Scope: %s, Scope Type: %d) -> ",
                   current->name, current->data_type, current->id_type,
                   current->line_number, current->scope, current->scope_type);
            current = current->next;
        }
        printf("NULL\n");
    }
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


void insert_symbol(hash_table_t* hash_table, ast_node_t* node, int table_size) 
{
    if (node == NULL) return;

    int hash_value = hash(node->lexeme, table_size);

    while (hash_table->table[hash_value] != NULL) 
    {
        hash_value = (hash_value + 1) % table_size;
    }

    hash_entry_t* new_entry = (hash_entry_t*)malloc(sizeof(hash_entry_t));
    if (new_entry != NULL) 
    {
        strncpy(new_entry->name, node->lexeme, MAX_LEXEME_LENGHT);
        new_entry->data_type = INT_DATA;//node->data_type;
        new_entry->id_type = VARIABLE;//node->id_type;
        new_entry->line_number = node->lineno;

        hash_table->table[hash_value] = new_entry;
    }
}

void construct_symtab(ast_node_t* node, hash_table_t* hash_table) 
{
    if (node == NULL) return;

    // ast_node_t* current = node;
    // ast_node_t* parent = node;

    // if (node->type == AST_DECLARATION) 
    // {
    //     insert_symbol(hash_table, node->child[1], TABLE_SIZE);
    // }

    // for (int i = 0; i < MAX_CHILDREN; i++) 
    // {
    //     construct_symtab(node->child[i], hash_table);
    // }

    // construct_symtab(node->sibling, hash_table);
}