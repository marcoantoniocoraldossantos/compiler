#ifndef SYMTAB_H
#define SYMTAB_H

#define MAX_LEXEME_LENGHT 64

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
    GLOBAL,
    LOCAL,
} scope_t;

typedef struct hash_entry_t 
{
    char name[MAX_LEXEME_LENGHT];
    data_type_t data_type;
    id_type_t id_type;
    int line_number;
    char scope[MAX_LEXEME_LENGHT];
    scope_t scope_type;
    struct hash_entry_t* next; // Para encadeamento em caso de colisões (caso use tabela hash)
} hash_entry_t;

hash_entry_t* initialize_symtab();
void insert_symbol(hash_entry_t* symtab, ast_node_t* node, int table_size);
void print_symtab(hash_entry_t* symtab);
void free_hash_table(hash_entry_t* symtab);
void semantic_analysis(ast_node_t* ast_tree, hash_entry_t* symtab);
unsigned int hash(const char* lexeme, int table_size);

#endif /* SYMTAB_H */
