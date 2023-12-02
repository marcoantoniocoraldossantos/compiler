#include "libraries.h"

#include <stdlib.h>

hash_table_t* initialize_hash_table() {
    hash_table_t* hash_table = (hash_table_t*)malloc(sizeof(hash_table_t));
    if (hash_table == NULL) {
        // Tratamento de erro, se a alocação de memória falhar
        return NULL;
    }

    hash_table->size = TABLE_SIZE;
    hash_table->table = (hash_entry_t**)malloc(TABLE_SIZE * sizeof(hash_entry_t*));
    if (hash_table->table == NULL) {
        // Tratamento de erro, se a alocação de memória falhar
        free(hash_table); // Libera a memória alocada para a tabela hash
        return NULL;
    }

    // Inicializa cada entrada na tabela com NULL (tabela vazia)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table->table[i] = NULL;
    }

    return hash_table;
}

void free_hash_table(hash_table_t* hash_table) {
    if (hash_table == NULL) {
        return; // Verifica se a tabela já é nula
    }

    // Libera cada lista encadeada em cada entrada da tabela
    for (int i = 0; i < hash_table->size; i++) {
        hash_entry_t* entry = hash_table->table[i];
        while (entry != NULL) {
            hash_entry_t* temp = entry;
            entry = entry->next;
            free(temp); // Libera cada entrada na lista encadeada
        }
    }

    free(hash_table->table); // Libera a matriz de ponteiros
    free(hash_table); // Libera a estrutura da tabela hash
}


void print_hash_table(hash_table_t* hash_table) 
{
    if (hash_table == NULL) 
    {
        printf("hash table not initialized\n");
        return;
    }

    printf("hash table:\n");
    for (int i = 0; i < hash_table->size; i++) 
    {
        hash_entry_t* entry = hash_table->table[i];
        printf("[%d]: ", i);
        if (entry == NULL) {
            printf("NULL\n");
        } else {
            while (entry != NULL) {
                printf(" -> Name: %s, DataType: %d, IdType: %d, LineNumber: %d, Scope: %s", entry->name, entry->data_type, entry->id_type, entry->line_number, entry->scope);
                entry = entry->next;
            }
            printf("\n");
        }
    }
}

// Função para calcular o índice da tabela hash usando o lexema
int hash(hash_table_t* hash_table, char* lexema) 
{
    // Lógica de uma função de hash simples
    int index = 0;
    for (int i = 0; lexema[i] != '\0'; i++) 
    {
        index += lexema[i];
    }
    return index % hash_table->size;
}

void insert_symbol(hash_table_t* hash_table, char* lexema, data_type_t data_type, id_type_t id_type, int line_number, char* scope) 
{
    int index = hash(hash_table, lexema);

    hash_entry_t* new_symbol = (hash_entry_t*)malloc(sizeof(hash_entry_t));
    if (new_symbol == NULL) 
    {
        return;
    }

    strncpy(new_symbol->name, lexema, MAX_LEXEME_LENGHT);
    new_symbol->data_type = data_type;
    new_symbol->id_type = id_type;
    new_symbol->line_number = line_number;
    strncpy(new_symbol->scope, scope, MAX_LEXEME_LENGHT);
    new_symbol->next = NULL;

    if (hash_table->table[index] == NULL) 
    {
        hash_table->table[index] = new_symbol;
    } 
    else 
    {
        new_symbol->next = hash_table->table[index];
        hash_table->table[index] = new_symbol;
    }
}

void construct_symtab(ast_node_t* node, hash_table_t* hash_table) 
{
    if (node == NULL) return;

    insert_symbol(hash_table, node->lexeme, node->kind.type, node->kind.type, node->lineno, "nao sei");

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










