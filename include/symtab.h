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

typedef struct symtab_entry_t 
{
    char name[MAX_LEXEME_LENGHT];
    data_type_t data_type;
    id_type_t id_type;
    int line_number;
    char scope[MAX_LEXEME_LENGHT];
    scope_t scope_type;
    struct symtab_entry_t* next; // Para encadeamento em caso de colisões (caso use tabela hash)
} symtab_entry_t;

// Função para inicializar a tabela de símbolos
void initialize_symtab();

// Função para inserir um símbolo na tabela de símbolos
void insert_symbol(const char* name, data_type_t data_type, id_type_t id_type);

// Função para imprimir a tabela de símbolos
void print_symtab();

#endif /* SYMTAB_H */
