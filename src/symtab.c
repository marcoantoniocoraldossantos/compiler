#include "libraries.h"

#include <stdlib.h>

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
        // while (entry != NULL) 
        // {
        //     hash_entry_t* temp = entry;
        //     entry = entry->next;
        //     free(temp); // Libera cada entrada na lista encadeada
        // }

        free(entry); 
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

        if (entry == NULL) 
        {
            printf("NULL\n");
        } 
        else 
        {
            // while (entry != NULL) 
            // {
            //     entry = entry->next;
            // }
            printf(" name \'%-8s\' | scope %-8s | data_type %-4d | id_type %-4d | line_number %d \n", entry->name, entry->scope, entry->data_type, entry->id_type, entry->line_number);
            // printf("\n");
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

void insert_symbol(hash_table_t* hash_table, char* lexema, data_type_t data_type, id_type_t id_type, int line_number, char* scope) {
    int index = hash(hash_table, lexema);

    // Verifica se a posição está ocupada
    while (hash_table->table[index] != NULL) 
    {
        index = (index + 1) % TABLE_SIZE; // Sondagem linear
    }

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
    //new_symbol->next = NULL;

    hash_table->table[index] = new_symbol;
}


void construct_symtab(ast_node_t* node, hash_table_t* hash_table) 
{
    if (node == NULL) return;

    insert_symbol(hash_table, node->lexeme, node->kind.type, node->kind.type, node->lineno, "global");

    // Percorre os filhos do nó atual
    for (int i = 0; i < MAXCHILDREN; i++) {
        construct_symtab(node->child[i], hash_table);
    }

    // Percorre os irmãos (próximo nó)
    construct_symtab(node->sibling, hash_table);
}

void semantic_analysis(ast_node_t* node, hash_table_t* symbol_table) 
{
    if (node == NULL) 
    {
        return;
    }

    switch(node->node_kind)
    {
        case PROGRAM_NODE:
            program_node(node, symbol_table);
            break;
        case STATEMENT_NODE:
            statement_node(node, symbol_table);
            break;
        case EXPRESSION_NODE:
            expression_node(node, symbol_table);
            break;
        case DECLARATION_NODE:
            declaration_node(node, symbol_table);
            break;
        case PARAMETER_NODE:
            parameter_node(node, symbol_table);
            break;
        case NULL_NODE:
            null_node(node, symbol_table);
            break;
    }

    for (int i = 0; i < MAXCHILDREN; ++i) 
    {
        semantic_analysis(node->child[i], symbol_table);
    }

    semantic_analysis(node->sibling, symbol_table);
}

void program_node(ast_node_t* node, hash_table_t* symbol_table) 
{
    if (node == NULL) 
    {
        return;
    }

    switch(node->kind.statement)
    {
        case IF_STMT:
            break;
        case WHILE_STMT:
            break;
        case RETURN_STMT:
            break;
        case DECL_STMT:
            break;
        case PARAM_STMT:
            break;
        case COMPOUND_STMT:
            break;
        case EXP_STMT:
            break;
        case NULL_STMT:
            break;
    }
}

void statement_node(ast_node_t* node, hash_table_t* symbol_table) 
{
    if (node == NULL) 
    {
        return;
    }

    switch(node->kind.statement)
    {
        case IF_STMT:
            break;
        case WHILE_STMT:
            break;
        case RETURN_STMT:
            break;
        case DECL_STMT:
            break;
        case PARAM_STMT:
            break;
        case COMPOUND_STMT:
            break;
        case EXP_STMT:
            break;
        case NULL_STMT:
            break;
    }
}

void expression_node(ast_node_t* node, hash_table_t* symbol_table) 
{
    if (node == NULL) 
    {
        return;
    }

    switch(node->kind.expression)
    {
        case OP_EXP:
            break;
        case CONST_EXP:
            break;
        case REL_EXP:
            break;
        case ID_EXP:
            break;
        case NOT_EXP:
            break;
        case FUNCTION_EXP:
            break;
        case VECTOR_EXP:
            break;
        case ATTR_EXP:
            break;
        case CALL_EXP:
            break;
        case NULL_EXP:
            break;
    }
}

void declaration_node(ast_node_t* node, hash_table_t* symbol_table) 
{
    if (node == NULL) 
    {
        return;
    }

    switch(node->kind.expression)
    {
        case OP_EXP:
            break;
        case CONST_EXP:
            break;
        case REL_EXP:
            break;
        case ID_EXP:
            break;
        case NOT_EXP:
            break;
        case FUNCTION_EXP:
            break;
        case VECTOR_EXP:
            break;
        case ATTR_EXP:
            break;
        case CALL_EXP:
            break;
        case NULL_EXP:
            break;
    }
}

void parameter_node(ast_node_t* node, hash_table_t* symbol_table) 
{
    if (node == NULL) 
    {
        return;
    }

    switch(node->kind.expression)
    {
        case OP_EXP:
            break;
        case CONST_EXP:
            break;
        case REL_EXP:
            break;
        case ID_EXP:
            break;
        case NOT_EXP:
            break;
        case FUNCTION_EXP:
            break;
        case VECTOR_EXP:
            break;
        case ATTR_EXP:
            break;
        case CALL_EXP:
            break;
        case NULL_EXP:
            break;
    }
}

void null_node(ast_node_t* node, hash_table_t* symbol_table) 
{
    if (node == NULL) 
    {
        return;
    }

    switch(node->kind.expression)
    {
        case OP_EXP:
            break;
        case CONST_EXP:
            break;
        case REL_EXP:
            break;
        case ID_EXP:
            break;
        case NOT_EXP:
            break;
        case FUNCTION_EXP:
            break;
        case VECTOR_EXP:
            break;
        case ATTR_EXP:
            break;
        case CALL_EXP:
            break;
        case NULL_EXP:
            break;
    }
}



