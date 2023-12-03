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

    printf("\n\n");

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

void semantic_analysis(ast_node_t* node, hash_table_t* hash_table)
{
    if (node == NULL)
        return;

    if(flag_semantic_error)
        return;

    printf("\n\ncurrent node: \'%s\' type %d line %d", node->lexeme, node->extended_type, node->lineno);

    switch(node->extended_type)
    {
        case EXT_VARIABLE_DECL:
            printf("\next_variable_decl\n");

            //printf("\nlexeme \'%s\'\n", node->lexeme);
            if(strcmp(node->lexeme, "void") == 0)
            {
                printf("semantic error: variable %s cannot be void\n", node->child[0]->lexeme);
                //exit(1);
                flag_semantic_error = 1;
                return;
            }

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
            printf("\next_vector_decl\n");
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
            printf("\next_variable\n");
            //printf("\n variable %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            break;
        case EXT_VECTOR:
            printf("\next_vector\n");
            
            printf("\n vector %s line %d\n", node->lexeme, node->child[0]->lineno);

            if(search_in_hash_table(hash_table, node->lexeme, "global"))
            {
                //add apparition
                add_apparition(hash_table, node->lexeme, node->lineno, "global");
            }
            else if(!search_in_hash_table(hash_table, node->lexeme, global_scope))
            {
                printf("semantic error: variable %s not declared in scope %s\n", node->lexeme, global_scope);
                //exit(1);
                flag_semantic_error = 1;
            }
            else
            {
                //add apparition
                add_apparition(hash_table, node->lexeme, node->lineno, global_scope);
            }

            
            if(search_in_hash_table(hash_table, node->child[0]->lexeme, "global"))
            {
                //add apparition
                add_apparition(hash_table, node->child[0]->lexeme, node->child[0]->lineno, global_scope);
                return;
            }
            if(!isdigit(node->child[0]->lexeme[0]))
            {
                if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
                {
                    printf("semantic error: variable %s not declared in scope %s\n", node->child[0]->lexeme, global_scope);
                    //exit(1);
                    flag_semantic_error = 1;
                }
                else
                {
                    //add apparition
                    add_apparition(hash_table, node->child[0]->lexeme, node->child[0]->lineno, global_scope);
                }
            }
            
            break;
        case EXT_FUNCTION_DECL:
            printf("\next_function_decl\n");
            //printf("\n function declaration %s line %d\n", node->child[1]->lexeme, node->child[1]->lineno);

            data_type_t data_type;
            //printf("\nlexeme %s\n", node->child[0]->lexeme);
            if(node->child[0]->kind.type == INT_TYPE)
                data_type = INT_DATA;
            else
                data_type = VOID_DATA;

            if(node->child[1] != NULL)
            {
                if(!search_in_hash_table(hash_table, node->child[1]->lexeme, global_scope))
                {
                    insert_symbol(hash_table, node->child[1]->lexeme, data_type, FUNCTION, node->child[1]->lineno, "global", FUNCTION_TYPE);
                }
                else
                {
                    printf("semantic error: function %s already declared in scope %s\n", node->child[1]->lexeme, global_scope);
                    //exit(1);
                    flag_semantic_error = 1;
                }
                strcpy(global_scope, node->child[1]->lexeme);
            }
            else
            {
                if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
                {
                    insert_symbol(hash_table, node->child[0]->lexeme, data_type, FUNCTION, node->child[0]->lineno, "global", FUNCTION_TYPE);
                }
                else
                {
                    printf("semantic error: function %s already declared in scope %s\n", node->child[0]->lexeme, global_scope);
                    //exit(1);
                    flag_semantic_error = 1;
                }
                
                strcpy(global_scope, node->child[0]->lexeme);
            }
            
            break;
        case EXT_FUNCTION_CALL:
            printf("\next_function_call\n");
            printf("\nfunction call %s line %d\n", node->lexeme, node->lineno);
            if(!search_in_hash_table(hash_table, node->lexeme, "global"))
            {
                printf("semantic error: function %s not declared\n", node->lexeme);
                //exit(1);
                flag_semantic_error = 1;
            }
            else
            {
                //add apparition
                add_apparition(hash_table, node->lexeme, node->lineno, "global");
            }
            break;
        case EXT_RETURN_INT:
            printf("\next_return_int\n");
            //printf(("\nis going to return int %s line %d\n"), node->child[0]->lexeme, node->child[0]->lineno);
            //todo verify if variable is declared and scope type
            // check if its going to return a function
            //print_hash_table(hash_table);

            if(isdigit(node->child[0]->lexeme[0]))
            {
                return;
            }

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
            printf("\next_return_void\n");
            break;
        case EXT_VARIABLE_PARAMETER:
            printf("\next_variable_parameter\n");
            //printf("\nvariable parameter %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            //insert in hash table
            insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, VARIABLE_TYPE);
            break;
        case EXT_VECTOR_PARAMETER:
            printf("\next_vector_parameter\n");

            //printf("\nvector parameter %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            //insert in hash table
            if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
            {
                insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, ARRAY_TYPE);
            }
            break;
        case EXT_VOID_PARAMETER:
            printf("\next_void_parameter\n");
            break;
        case EXT_IF:
            printf("\next_if\n");
            
            //printf("\nif %s line %d\n", node->lexeme, node->lineno);
            //printf("\ncondition %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);

            break;
        case EXT_IF_ELSE:
            printf("\next_if_else\n");
            
            //printf("\nif else %s line %d\n", node->lexeme, node->lineno);
            //printf("\ncondition %s line %d\n", node->child[0]->lexeme, node->child[0]->lineno);
            if(if_condition_is_valid(hash_table, node))
            {
                
            }

            break;
        case EXT_WHILE:
            printf("\next_while\n");

            break;
        case EXT_ASSIGN:
            printf("\next_assign\n");

            break;
        case EXT_OPERATOR:
            printf("\next_operator\n");
            
            break;
        case EXT_RELATIONAL:
            printf("\next_relational\n");
            //printf("\ntype %d\n", node->child[1]->kind.type);
            //printf("\nrelational %s line %d\n", node->lexeme, node->lineno);
            //print_hash_table(hash_table);
            if(function_is_void_type(hash_table, node->child[1]->lexeme))
            {
                printf("semantic error: function %s is void type\n", node->child[1]->lexeme);
                //exit(1);
                flag_semantic_error = 1;
            }
            break;
        case EXT_CONSTANT:
            printf("\next_constant\n");

            break;
        case EXT_IDENTIFIER:
            printf("\next_identifier\n");

            //print_hash_table(hash_table);

            printf("\nlexeme %s", node->lexeme);
            //print_hash_table(hash_table);

            if(strcmp(node->lexeme, global_scope) != 0) // if its not a function call
            {
                printf("\nlexeme %s global scope %s", node->lexeme, global_scope);
                if(search_in_hash_table(hash_table, node->lexeme, "global"))
                {
                    //add apparition
                    add_apparition(hash_table, node->lexeme, node->lineno, global_scope);
                    return;
                }
                if(!search_in_hash_table(hash_table, node->lexeme, global_scope))
                {
                    printf("semantic error: variable %s not declared in scope %s\n", node->lexeme, global_scope);
                    //exit(1);
                    flag_semantic_error = 1;
                }
                else
                {
                    //add apparition
                    add_apparition(hash_table, node->lexeme, node->lineno, global_scope);
                }
            }
            else if(!search_for_function_declaration(hash_table, node->lexeme))
            {
                printf("\nis function %s line %d\n", node->lexeme, node->lineno);
                printf("semantic error: function %s not declared\n", node->lexeme);
                //exit(1);
                flag_semantic_error = 1;
            }

            break;
        case EXT_NULL:
            printf("\next_null\n");
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

bool if_condition_is_valid(hash_table_t* symbol_table, ast_node_t* node)
{

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
        index = (index + 1) % TABLE_SIZE; 
    }

    return false;
}