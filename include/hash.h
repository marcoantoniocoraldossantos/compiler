#ifndef HASH_H
#define HASH_H

#define MAX_LEXEME_LENGHT 64
#define TABLE_SIZE 211

typedef enum 
{
    INT_DATA,
    VOID_DATA,
} data_type_t;

typedef enum 
{
    VARIABLE,
    FUNCTION,
} id_type_t;

typedef enum
{
    VARIABLE_TYPE,
    ARRAY_TYPE,
    FUNCTION_TYPE,
} variable_type_t;

typedef struct hash_entry_t 
{
    char name[MAX_LEXEME_LENGHT];
    data_type_t data_type;
    id_type_t id_type;
    int line_number[20];
    int number_of_appearances;
    char scope[MAX_LEXEME_LENGHT];
    variable_type_t variable_type;
} hash_entry_t;

typedef struct 
{
    hash_entry_t** table;
    int size;

} hash_table_t;

hash_table_t* initialize_hash_table();
void free_hash_table(hash_table_t* hash_table);
void print_hash_table(hash_table_t* hash_table);
void insert_symbol(hash_table_t* hash_table, char* lexema, data_type_t data_type, id_type_t id_type, int line_number, char* scope, variable_type_t variable_type);
int hash(hash_table_t* hash_table, char* lexema);
bool search_in_hash_table(hash_table_t* hash_table, char* lexema, char* scope);
void verify_declaration_of_identifier(hash_table_t* symbol_table, ast_node_t* node, char* scope);
void verify_if_variable_already_exists(hash_table_t* symbol_table, ast_node_t* node, char* scope);
bool search_for_function_declaration(hash_table_t* symbol_table, char* lexeme);
bool seach_if_variable_already_exists(hash_table_t* hash_table, char* lexema, char* scope);
bool function_returns_int(hash_table_t* symbol_table, char* lexeme);
bool function_is_void_type(hash_table_t* symbol_table, char* lexeme);
bool is_variable(hash_table_t* symbol_table, char* lexeme);
void add_apparition(hash_table_t* hash_table, char* lexema, int line_number, char* scope);


#endif /* HASH_H */