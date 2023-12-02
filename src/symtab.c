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
    int indice = 0;
    for (int i = 0; lexema[i] != '\0'; i++) 
    {
        indice += lexema[i];
    }
    return indice % hash_table->size;
}

// Função para inserir um novo elemento na tabela hash usando o lexema como chave
void insert_symbol(hash_table_t* hash_table, char* lexema, data_type_t data_type, id_type_t id_type, int line_number, char* scope) 
{
    int indice = hash(hash_table, lexema);

    hash_entry_t* novo_elemento = (hash_entry_t*)malloc(sizeof(hash_entry_t));
    if (novo_elemento == NULL) 
    {
        // Tratamento de erro se a alocação de memória falhar
        return;
    }

    strncpy(novo_elemento->name, lexema, MAX_LEXEME_LENGHT);
    novo_elemento->data_type = data_type;
    novo_elemento->id_type = id_type;
    novo_elemento->line_number = line_number;
    strncpy(novo_elemento->scope, scope, MAX_LEXEME_LENGHT);
    novo_elemento->next = NULL;

    // Verifica se a posição na tabela está vazia
    if (hash_table->table[indice] == NULL) 
    {
        hash_table->table[indice] = novo_elemento;
    } 
    else 
    {
        // Caso contrário, há uma colisão, insira no início da lista encadeada
        novo_elemento->next = hash_table->table[indice];
        hash_table->table[indice] = novo_elemento;
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










// unsigned int hash(const char* lexeme, int table_size) 
// {
//     unsigned int hash_value = 0;
//     for (int i = 0; lexeme[i] != '\0'; i++) 
//     {
//         hash_value = lexeme[i] + (hash_value << 5) - hash_value;
//     }
//     return hash_value % table_size;
// }


// void insert_symbol(hash_table_t* hash_table, ast_node_t* node, int table_size) 
// {
//     if (node == NULL) return;

//     int hash_value = hash(node->lexeme, table_size);

//     while (hash_table->table[hash_value] != NULL) 
//     {
//         hash_value = (hash_value + 1) % table_size;
//     }

//     hash_entry_t* new_entry = (hash_entry_t*)malloc(sizeof(hash_entry_t));
//     if (new_entry != NULL) 
//     {
//         strncpy(new_entry->name, node->lexeme, MAX_LEXEME_LENGHT);
//         new_entry->data_type = INT_DATA;//node->data_type;
//         new_entry->id_type = VARIABLE;//node->id_type;
//         new_entry->line_number = node->lineno;

//         hash_table->table[hash_value] = new_entry;
//     }
// }
