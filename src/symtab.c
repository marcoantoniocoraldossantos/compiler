#include "libraries.h"

int flag_semantic_error = 0;
char scope[MAX_LEXEME_LENGHT];

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


void print_hash_table(hash_table_t* hash_table) {
    if (hash_table == NULL) {
        printf("hash table not initialized\n");
        return;
    }

    printf("index   | name    | scope  | data_type   | id_type   | variable_type | line_number\n");

    for (int i = 0; i < hash_table->size; i++) {
        hash_entry_t* entry = hash_table->table[i];

        if (entry == NULL) {
            // printf("NULL\n");
        } else {
            if (i < 10) {
                printf("  [%d]: ", i);
            } else if (i < 100) {
                printf(" [%d]: ", i);
            } else {
                printf("[%d]: ", i);
            }

            printf(" %-10s | %-8s |  %-4s | %-4s | %-6s | ", entry->name, entry->scope, data_type_to_string(entry->data_type), id_type_to_string(entry->id_type), variable_type_to_string(entry->variable_type));

            for (int j = 0; j < entry->number_of_appearances; j++) {
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

void construct_symtab(ast_node_t* node, hash_table_t* hash_table) 
{
    //insert input output functions
    insert_symbol(hash_table, "input", INT_DATA, FUNCTION, 0, "global", FUNCTION_TYPE);
    insert_symbol(hash_table, "output", VOID_DATA, FUNCTION, 0, "global", FUNCTION_TYPE);

    //print_hash_table(hash_table);

    /*
    if (node == NULL) return;

    if(ast_node_is_identifier(node)) 
    {   
        if(!search_in_hash_table(hash_table, node->lexeme, "global"))
            insert_symbol(hash_table, node->lexeme, node->kind.type, node->kind.type, node->lineno, "global", VARIABLE_TYPE);
        else
            add_apparition(hash_table, node->lexeme, node->lineno);
    }
   
    // Percorre os filhos do nó atual
    for (int i = 0; i < MAXCHILDREN; i++) 
    {
        construct_symtab(node->child[i], hash_table);
    }

    // Percorre os irmãos (próximo nó)
    construct_symtab(node->sibling, hash_table);
    */
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

void add_apparition(hash_table_t* hash_table, char* lexema, int line_number) 
{
    int index = hash(hash_table, lexema);

    while (hash_table->table[index] != NULL) 
    {
        if(strcmp(hash_table->table[index]->name, lexema) == 0) 
        {
            if(!verify_if_line_number_already_exists(hash_table->table[index], line_number))
            {
                hash_table->table[index]->line_number[hash_table->table[index]->number_of_appearances] = line_number;
                hash_table->table[index]->number_of_appearances++;
            }
            return;
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    //remove_duplicate_line_numbers(hash_table->table[index]);

    return;
}

void semantic_analysis(ast_node_t* node, hash_table_t* hash_table)
{
    if (node == NULL)
        return;

    if(flag_semantic_error)
        return;

    switch(node->extended_type)
    {
        case EXT_VARIABLE_DECL:
            //printf("\n variable declaration %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            if(seach_if_variable_already_exists(hash_table, node->child[0]->lexeme, global_scope))
            {
                printf("semantic error: variable %s already declared in scope %s\n", node->child[0]->lexeme, global_scope);
                //exit(1);
                flag_semantic_error = 1;
            }
            else
            {
                if(ast_node_is_identifier(node->child[0]))
                    insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, VARIABLE_TYPE);
            }
            break;
        case EXT_VECTOR_DECL:
            //printf("\n vector declaration %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            if(seach_if_variable_already_exists(hash_table, node->child[0]->lexeme, global_scope))
            {
                printf("semantic error: variable %s already declared in scope %s\n", node->child[0]->lexeme, global_scope);
                //exit(1);
                flag_semantic_error = 1;
            }
            else
            {
                if(ast_node_is_identifier(node->child[0]))
                    insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, ARRAY_TYPE);
            }
            break;
        case EXT_VARIABLE:
            //printf("\n variable %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            break;
        case EXT_VECTOR:
            //printf("\n vector %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            break;
        case EXT_FUNCTION_DECL:
            //printf("\n function declaration %s line %d\n", node->child[1]->lexeme, node->child[1]->lineno);
            if(!search_in_hash_table(hash_table, node->child[1]->lexeme, global_scope))
                insert_symbol(hash_table, node->child[1]->lexeme, INT_DATA, FUNCTION, node->child[1]->lineno, "global", FUNCTION_TYPE);
            else
            {
                printf("semantic error: function %s already declared in scope %s\n", node->child[1]->lexeme, global_scope);
                //exit(1);
                flag_semantic_error = 1;
            }
            strcpy(global_scope, node->child[1]->lexeme);
            break;
        case EXT_FUNCTION_CALL:
            //printf("\n function call %s line %d\n", node->lexeme, node->lineno);
            if(!search_for_function_declaration(hash_table, node->lexeme))
            {
                printf("semantic error: function %s not declared\n", node->lexeme);
                //exit(1);
                flag_semantic_error = 1;
            }
            break;
        case EXT_RETURN_INT:
            //printf(("\nis going to return int %s line %d\n"), node->child[0]->lexeme, node->child[0]->lineno);
            //todo verify if variable is declared and scope type
            // check if its going to return a function
            //print_hash_table(hash_table);
            int flag_not_found = 0;
            if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
            {
                flag_not_found = 1;
            }

            if(id_is_variable(hash_table, node->child[0]->lexeme))
            {
                if(flag_not_found == 1)
                {
                    printf("semantic error: variable %s not declared in scope %s\n", node->child[0]->lexeme, global_scope);
                    //exit(1);
                    flag_semantic_error = 1;
                    return;
                }
               // printf("\nis variable %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
                if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
                {
                    printf("semantic error: variable %s not declared in scope %s\n", node->child[0]->lexeme, global_scope);
                    //exit(1);
                    flag_semantic_error = 1;
                    return;
                }
            }
            else if(!search_for_function_declaration(hash_table, node->child[0]->lexeme))
            {
                if(flag_not_found == 1)
                {
                    printf("semantic error: function %s not declared\n", node->child[0]->lexeme);
                    //exit(1);
                    flag_semantic_error = 1;
                    return;
                }
                //printf("\nis function %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
                printf("semantic error: function %s not declared\n", node->child[0]->lexeme);
                //exit(1);
                flag_semantic_error = 1;
                return;
            }
            break;
        case EXT_RETURN_VOID:
            break;
        case EXT_VARIABLE_PARAMETER:
            //printf("\nvariable parameter %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            //insert in hash table
            insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, VARIABLE_TYPE);
            break;
        case EXT_VECTOR_PARAMETER:
            break;
        case EXT_VOID_PARAMETER:
            break;
        case EXT_IF:
            break;
        case EXT_IF_ELSE:
            break;
        case EXT_WHILE:
            break;
        case EXT_ASSIGN:
            break;
        case EXT_OPERATOR:
            break;
        case EXT_RELATIONAL:
            break;
        case EXT_CONSTANT:
            break;
        case EXT_IDENTIFIER:
            //printf("\nutilized variable %s line %d\n", node->lexeme, node->lineno);
            break;
        case EXT_NULL:
            break;
        default:
            break;
    }

    for (int i = 0; i < MAXCHILDREN; ++i) 
    {
        semantic_analysis(node->child[i], hash_table);
    }

    semantic_analysis(node->sibling, hash_table);
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

void go_through_tree(ast_node_t* node, hash_table_t* symbol_table, char* scope) 
{
    if (node == NULL) 
    {
        return;
    }

    if(flag_semantic_error)
        return;

    data_type_t data_type;
    id_type_t id_type;

    char new_scope[MAX_LEXEME_LENGHT];
    strncpy(new_scope, scope, MAX_LEXEME_LENGHT);

    //printf("\nscope: %s\n", scope);
    switch(node->node_kind)
    {
        case PROGRAM_NODE:
            break;
        case STATEMENT_NODE:
            break;
        case EXPRESSION_NODE:
            process_expression(node, symbol_table, scope);
            break;
        case DECLARATION_NODE:
            process_declaration(node, symbol_table, scope);
            break;
        case PARAMETER_NODE:
            break;
        case NULL_NODE:
            break;
    }

    for (int i = 0; i < MAXCHILDREN; ++i) 
    {
        go_through_tree(node->child[i], symbol_table, new_scope);
    }

    go_through_tree(node->sibling, symbol_table, new_scope);
}

void process_expression(ast_node_t* node, hash_table_t* symbol_table, char* scope)
{
    switch (node->extended_type)
    {
    case EXT_IDENTIFIER:
        verify_declaration_of_identifier(symbol_table, node, scope);
        break;
    case EXT_VECTOR:
        break;
    case EXT_FUNCTION_CALL:
        break;
    case EXT_ASSIGN:
        break;

    default:
        break;
    }
}

void verify_declaration_of_identifier(hash_table_t* symbol_table, ast_node_t* node, char* scope)
{

}

void process_declaration(ast_node_t* node, hash_table_t* symbol_table, char* scope)
{
    char new_scope[MAX_LEXEME_LENGHT];
    strncpy(new_scope, scope, MAX_LEXEME_LENGHT);

    data_type_t data_type;
    id_type_t id_type;

    switch(node->extended_type)
    {
        case EXT_VARIABLE_DECL:
        case EXT_VECTOR_DECL:
            verify_if_variable_already_exists(symbol_table, node, new_scope);
            break;
        case EXT_FUNCTION_DECL:
            verify_function_declaration(symbol_table, node, scope);
            break;
        default:
            break;
    }
}

// double declaration of variable
void verify_if_variable_already_exists(hash_table_t* symbol_table, ast_node_t* node, char* scope)
{
    //printf("\nlexeme %s line %d\n", node->lexeme, node->lineno);
    //printf("\nchild lexeme %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
    if(search_in_hash_table(symbol_table, node->child[0]->lexeme, scope))
    {
        printf("semantic error: variable %s already declared in scope %s\n", node->child[0]->lexeme, scope);
        //exit(1);
        flag_semantic_error = 1;
        return;
    }
    else
    {
        if(ast_node_is_identifier(node->child[0]))
            insert_symbol(symbol_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, scope, VARIABLE_TYPE);
    }
}

void verify_function_declaration(hash_table_t* symbol_table, ast_node_t* node, char* scope)
{
    data_type_t data_type;
    if(strcmp(node->child[0]->lexeme, "int") == 0)
        data_type = INT_DATA;
    else
        data_type = VOID_DATA;

    char new_scope[MAX_LEXEME_LENGHT];
    strncpy(new_scope, node->child[1]->lexeme, MAX_LEXEME_LENGHT);
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



