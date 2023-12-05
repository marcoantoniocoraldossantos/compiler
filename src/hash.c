#include "libraries.h"

hash_table_t* initialize_hash_table() 
{
    hash_table_t* hash_table = (hash_table_t*)malloc(sizeof(hash_table_t));
    if (hash_table == NULL) 
    {
        return NULL;
    }

    hash_table->size = TABLE_SIZE;
    hash_table->table = (hash_entry_t**)malloc(TABLE_SIZE * sizeof(hash_entry_t*));
    if (hash_table->table == NULL) 
    {
        free(hash_table); 
        return NULL;
    }

    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        hash_table->table[i] = NULL;
    }

    return hash_table;
}

void free_hash_table(hash_table_t* hash_table) 
{
    if (hash_table == NULL) 
    {
        return;
    }

    for (int i = 0; i < hash_table->size; i++) 
    {
        hash_entry_t* entry = hash_table->table[i];
        free(entry); 
    }

    free(hash_table->table); 
    free(hash_table);
}

void print_hash_table(hash_table_t* hash_table) 
{
    if (hash_table == NULL) {
        printf("hash table not initialized\n");
        return;
    }

    printf("\n\n");

    printf("%-3s | %-15s | %-15s |  %-15s | %-15s | %-15s | %-15s\n", "entry", "name", "scope", "type", "id", "variable", "line");

    for (int i = 0; i < hash_table->size; i++) {
        hash_entry_t* entry = hash_table->table[i];

        if (entry == NULL) 
        {
            // printf("NULL\n");
        } else {
            if (i < 10) {
                printf("  [%d] |", i);
            } else if (i < 100) {
                printf(" [%d] |", i);
            } else {
                printf("[%d] |", i);
            }

            printf(" %-15s | %-15s |  %-15s | %-15s | %-15s |", 
                entry->name, entry->scope, data_type_to_string(entry->data_type), id_type_to_string(entry->id_type), variable_type_to_string(entry->variable_type));

            for (int j = 0; j < entry->number_of_appearances; j++) 
            {
                printf(" %d", entry->line_number[j]);
            }

            printf("\n");
        }
    }
}

int hash(hash_table_t* hash_table, char* lexema) 
{
    int index = 0;
    for (int i = 0; lexema[i] != '\0'; i++) 
    {
        index += lexema[i];
    }
    return index % hash_table->size;
}

void insert_symbol(hash_table_t* hash_table, char* lexema, data_type_t data_type, id_type_t id_type, int line_number, char* scope, variable_type_t variable_type) 
{
    int index = hash(hash_table, lexema);

    while (hash_table->table[index] != NULL) 
    {
        index = (index + 1) % TABLE_SIZE; 
    }

    hash_entry_t* new_symbol = (hash_entry_t*)malloc(sizeof(hash_entry_t));
    if (new_symbol == NULL) 
    {
        return;
    }

    strncpy(new_symbol->name, lexema, MAX_LEXEME_LENGHT);
    new_symbol->data_type = data_type;
    new_symbol->id_type = id_type;
    new_symbol->line_number[0] = line_number;
    new_symbol->number_of_appearances = 1;
    strncpy(new_symbol->scope, scope, MAX_LEXEME_LENGHT);
    //new_symbol->next = NULL;
    new_symbol->variable_type = variable_type;

    hash_table->table[index] = new_symbol;
}

bool search_in_hash_table(hash_table_t* hash_table, char* lexema, char* scope) 
{
    int index = hash(hash_table, lexema);

    while (hash_table->table[index] != NULL) 
    {
        if(strcmp(hash_table->table[index]->name, lexema) == 0 && strcmp(hash_table->table[index]->scope, scope) == 0) 
        {
            return true;
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    return false;
}

void add_apparition(hash_table_t* hash_table, char* lexema, int line_number, char* scope) 
{
    int index = hash(hash_table, lexema);

    while (hash_table->table[index] != NULL) 
    {
        if(strcmp(hash_table->table[index]->name, lexema) == 0 && strcmp(hash_table->table[index]->scope, scope) == 0) 
        {
            for(int i = 0; i < hash_table->table[index]->number_of_appearances; i++)
            {
                if(hash_table->table[index]->line_number[i] == line_number)
                    return;
            }
            hash_table->table[index]->line_number[hash_table->table[index]->number_of_appearances] = line_number;
            hash_table->table[index]->number_of_appearances++;
            return;
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    return;
}

bool seach_if_variable_already_exists(hash_table_t* hash_table, char* lexema, char* scope)
{
    int index = hash(hash_table, lexema);

    while (hash_table->table[index] != NULL) 
    {
        if(strcmp(hash_table->table[index]->name, lexema) == 0 && strcmp(hash_table->table[index]->scope, scope) == 0) 
        {
            return true;
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    return false;
}

bool search_for_function_declaration(hash_table_t* symbol_table, char* lexeme)
{
    int index = hash(symbol_table, lexeme);

    while (symbol_table->table[index] != NULL) 
    {
        //printf("\ncompare %s with %s\n", symbol_table->table[index]->name, lexeme);
        if(strcmp(symbol_table->table[index]->name, lexeme) == 0 && symbol_table->table[index]->id_type == FUNCTION) 
        {
            return true;
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    return false;
}

bool function_is_void_type(hash_table_t* symbol_table, char* lexeme)
{
    int index = hash(symbol_table, lexeme);

    while (symbol_table->table[index] != NULL) 
    {
        if(strcmp(symbol_table->table[index]->name, lexeme) == 0 && symbol_table->table[index]->id_type == FUNCTION) 
        {
            if(symbol_table->table[index]->data_type == VOID_DATA)
                return true;
            else
                return false;
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    return false;
}

bool is_variable(hash_table_t* symbol_table, char* lexeme)
{
    int index = hash(symbol_table, lexeme);

    while (symbol_table->table[index] != NULL) 
    {
        if(strcmp(symbol_table->table[index]->name, lexeme) == 0 && symbol_table->table[index]->id_type == VARIABLE) 
        {
            return true;
        }
        index = (index + 1)  % TABLE_SIZE; 
    }

    return false;
}
