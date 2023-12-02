#ifndef SYMTAB_H
#define SYMTAB_H

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

typedef struct hash_entry_t 
{
    char name[MAX_LEXEME_LENGHT];
    data_type_t data_type;
    id_type_t id_type;
    int line_number;
    char scope[MAX_LEXEME_LENGHT];
    struct hash_entry_t* next; 
} hash_entry_t;

typedef struct 
{
    hash_entry_t** table;
    int size;
} hash_table_t;

hash_table_t* initialize_hash_table();
void free_hash_table(hash_table_t* hash_table);
void print_hash_table(hash_table_t* hash_table);
void insert_symbol(hash_table_t* hash_table, char* lexema, data_type_t data_type, id_type_t id_type, int line_number, char* scope);
void construct_symtab(ast_node_t* node, hash_table_t* hash_table);

#endif /* SYMTAB_H */
