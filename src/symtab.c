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

unsigned int hash(const char* lexeme, int table_size) 
{
    unsigned int hash_value = 0;
    for (int i = 0; lexeme[i] != '\0'; i++) 
    {
        hash_value = lexeme[i] + (hash_value << 5) - hash_value;
    }
    return hash_value % table_size;
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