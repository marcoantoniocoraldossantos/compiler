#include "libraries.h"

#define HASH_SIZE 101

// Estrutura para a tabela de hash
typedef struct HashTable {
    symtab_entry_t *table[HASH_SIZE];
} HashTable;

// Variável global para a tabela de símbolos
HashTable symbol_table;

// Função de hash simples
unsigned int hash(const char *str) {
    unsigned int hashval = 0;
    for (; *str != '\0'; str++) {
        hashval = *str + (hashval << 5) - hashval;
    }
    return hashval % HASH_SIZE;
}

// Função para inicializar a tabela de símbolos
void initialize_symtab() {
    for (int i = 0; i < HASH_SIZE; i++) {
        symbol_table.table[i] = NULL;
    }
}

// Função para inserir um símbolo na tabela de símbolos
void insert_symbol(const char *name, data_type_t data_type, id_type_t id_type) {
    unsigned int index = hash(name);
    
    symtab_entry_t *new_entry = (symtab_entry_t *)malloc(sizeof(symtab_entry_t));
    if (new_entry == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo símbolo.\n");
        exit(EXIT_FAILURE);
    }
    
    strncpy(new_entry->name, name, MAX_LEXEME_LENGHT);
    new_entry->data_type = data_type;
    new_entry->id_type = id_type;
    new_entry->line_number = -1; // Pode ser ajustado conforme necessário
    new_entry->next = symbol_table.table[index];
    symbol_table.table[index] = new_entry;
}

// Função para imprimir a tabela de símbolos
void print_symtab() {
    printf("=========== Tabela de Símbolos ===========\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        symtab_entry_t *current = symbol_table.table[i];
        while (current != NULL) {
            printf("Nome: %s, Tipo de Dados: %d, Tipo de Identificador: %d\n",
                   current->name, current->data_type, current->id_type);
            current = current->next;
        }
    }
    printf("=========================================\n");
}
