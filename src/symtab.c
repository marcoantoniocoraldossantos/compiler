#include "libraries.h"

int flag_semantic_error = 0;

char scope[MAX_LEXEME_LENGHT];

void construct_symtab(ast_node_t* node, hash_table_t* hash_table) 
{
    //insert input output functions
    insert_symbol(hash_table, "input", INT_DATA, FUNCTION, 0, "global", FUNCTION_TYPE);
    insert_symbol(hash_table, "output", VOID_DATA, FUNCTION, 0, "global", FUNCTION_TYPE);
}

void semantic_analysis(ast_node_t* node, hash_table_t* hash_table)
{
    if (node == NULL)
        return;

    if(flag_semantic_error)
        return;

    //printf("\n\ncurrent node: \'%s\' type %d line %d", node->lexeme, node->extended_type, node->lineno);

    switch(node->extended_type)
    {
        case EXT_VARIABLE_DECL:
            //printf("\next_variable_decl\n");
            process_variable_declaration(hash_table, node);

            break;
        case EXT_VECTOR_DECL:
            //printf("\next_vector_decl\n");
            process_vector_declaration(hash_table, node);
            
            break;
        case EXT_VARIABLE:
            //printf("\next_variable\n");
            process_variable(hash_table, node);

            break;
        case EXT_VECTOR:
            //printf("\next_vector\n");
            process_vector(hash_table, node);
            
            break;
        case EXT_FUNCTION_DECL:
            //printf("\next_function_decl\n");
            process_function_declaration(hash_table, node);
            
            break;
        case EXT_FUNCTION_CALL:
            //printf("\next_function_call\n");
            process_function_call(hash_table, node);

            break;
        case EXT_RETURN_INT:
            //printf("\next_return_int\n");
            process_return_int(hash_table, node);
            
            break;
        case EXT_RETURN_VOID:
            //printf("\next_return_void\n");
            process_return_void(hash_table, node);

            break;
        case EXT_VARIABLE_PARAMETER:
            //printf("\next_variable_parameter\n");
            process_variable_parameter(hash_table, node);

            break;
        case EXT_VECTOR_PARAMETER:
            //printf("\next_vector_parameter\n");
            process_vector_parameter(hash_table, node);

            break;
        case EXT_VOID_PARAMETER:
            //printf("\next_void_parameter\n");
            process_void_parameter(hash_table, node);

            break;
        case EXT_IF:
            //printf("\next_if\n");
            process_if(hash_table, node);

            break;
        case EXT_IF_ELSE:
            //printf("\next_if_else\n");
            process_if_else(hash_table, node);
            
            break;
        case EXT_WHILE:
            //printf("\next_while\n");
            process_while(hash_table, node);

            break;
        case EXT_ASSIGN:
            //printf("\next_assign\n");
            process_assign(hash_table, node);

            break;
        case EXT_OPERATOR:
            //printf("\next_operator\n");
            process_operator(hash_table, node);
            
            break;
        case EXT_RELATIONAL:
            //printf("\next_relational\n");
            process_relational(hash_table, node);
            
            break;
        case EXT_CONSTANT:
            //printf("\next_constant\n");
            process_constant(hash_table, node);

            break;
        case EXT_IDENTIFIER:
            //printf("\next_identifier\n");
            process_identifier(hash_table, node);

            break;
        case EXT_NULL:
            //printf("\next_null\n");
            process_null(hash_table, node);
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


void process_variable_declaration(hash_table_t* hash_table, ast_node_t* node)
{
    if(strcmp(node->lexeme, "void") == 0)
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m cannot be void\n", node->child[0]->lexeme);
        flag_semantic_error = 1;
        return;
    }

    if(seach_if_variable_already_exists(hash_table, node->child[0]->lexeme, global_scope))
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m already declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
        flag_semantic_error = 1;
    }
    else
    {
        if(ast_node_is_identifier(node->child[0]))
        {
            insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, VARIABLE_TYPE);
        }
    }
}

void process_vector_declaration(hash_table_t* hash_table, ast_node_t* node)
{
    if(strcmp(node->lexeme, "void") == 0)
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "array \x1b[1m'%s'\x1b[0m cannot be void\n", node->child[0]->lexeme);
        flag_semantic_error = 1;
        return;
    }

    if(seach_if_variable_already_exists(hash_table, node->child[0]->lexeme, global_scope))
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "array \x1b[1m'%s'\x1b[0m already declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
        flag_semantic_error = 1;
    }
    else
    {
        if(ast_node_is_identifier(node->child[0]))
        {
            insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, ARRAY_TYPE);
        }
    }
}

void process_variable(hash_table_t* hash_table, ast_node_t* node)
{
    if(strcmp(node->lexeme, "void") == 0)
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m cannot be void\n", node->child[0]->lexeme);
        flag_semantic_error = 1;
        return;
    }

    if(seach_if_variable_already_exists(hash_table, node->child[0]->lexeme, global_scope))
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m already declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
        flag_semantic_error = 1;
    }
    else
    {
        if(ast_node_is_identifier(node->child[0]))
        {
            insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, VARIABLE_TYPE);
        }
    }
}

void process_vector(hash_table_t* hash_table, ast_node_t* node)
{
    if(search_in_hash_table(hash_table, node->lexeme, "global"))
    {
        add_apparition(hash_table, node->lexeme, node->lineno, "global");
    }
    else if(!search_in_hash_table(hash_table, node->lexeme, global_scope))
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m already declared in scope \x1b[1m'%s'\x1b[0m\n", node->lexeme, global_scope);
        flag_semantic_error = 1;
    }
    else
    {
        add_apparition(hash_table, node->lexeme, node->lineno, global_scope);
    }

    if(search_in_hash_table(hash_table, node->child[0]->lexeme, "global"))
    {
        add_apparition(hash_table, node->child[0]->lexeme, node->child[0]->lineno, global_scope);
        return;
    }
    if(!isdigit(node->child[0]->lexeme[0]))
    {
        if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
        {
            fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m not declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
            flag_semantic_error = 1;
        }
        else
        {
            add_apparition(hash_table, node->child[0]->lexeme, node->child[0]->lineno, global_scope);
        }
    }
}

void process_function_declaration(hash_table_t* hash_table, ast_node_t* node)
{
    data_type_t data_type;

    if(node->child[0]->kind.type == INT_TYPE)
    {
        data_type = INT_DATA;
    }
    else
    {
        data_type = VOID_DATA;
    }

    if(node->child[1] != NULL)
    {
        if(!search_in_hash_table(hash_table, node->child[1]->lexeme, global_scope))
        {
            insert_symbol(hash_table, node->child[1]->lexeme, data_type, FUNCTION, node->child[1]->lineno, "global", FUNCTION_TYPE);
        }
        else
        {
            fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[1]->lineno);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m already declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[1]->lexeme, global_scope);
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
            fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "function \x1b[1m'%s'\x1b[0m already declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
            flag_semantic_error = 1;
        }
        
        strcpy(global_scope, node->child[0]->lexeme);
    }
}

void process_function_call(hash_table_t* hash_table, ast_node_t* node)
{
    if(!search_in_hash_table(hash_table, node->lexeme, "global"))
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "function \x1b[1m'%s'\x1b[0m not declared\n", node->lexeme);
        flag_semantic_error = 1;
    }
    else
    {
        add_apparition(hash_table, node->lexeme, node->lineno, "global");
    } 
}

void process_return_int(hash_table_t* hash_table, ast_node_t* node)
{
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
            fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m not declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
            flag_semantic_error = 1;
            return;
        }
        if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
        {
            fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m not declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
            flag_semantic_error = 1;
            return;
        }
    }
    else if(!search_for_function_declaration(hash_table, node->child[0]->lexeme))
    {
        if(flag_not_found == 1)
        {
            fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "function \x1b[1m'%s'\x1b[0m not declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
            flag_semantic_error = 1;
            return;
        }
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[0]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "function \x1b[1m'%s'\x1b[0m not declared in scope \x1b[1m'%s'\x1b[0m\n", node->child[0]->lexeme, global_scope);
        flag_semantic_error = 1;
        return;
    }
}

void process_return_void(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_variable_parameter(hash_table_t* hash_table, ast_node_t* node)
{
    if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
    {
        insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, VARIABLE_TYPE);
    }
}

void process_vector_parameter(hash_table_t* hash_table, ast_node_t* node)
{
    if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
    {
        insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, ARRAY_TYPE);
    }
}

void process_void_parameter(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_if(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_if_else(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_while(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_assign(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_operator(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_relational(hash_table_t* hash_table, ast_node_t* node)
{
    
    if(function_is_void_type(hash_table, node->child[1]->lexeme))
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->child[1]->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "function \x1b[1m'%s'\x1b[0m is void type\n", node->child[1]->lexeme);
        flag_semantic_error = 1;
    } 
}

void process_constant(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

void process_identifier(hash_table_t* hash_table, ast_node_t* node)
{
    if(strcmp(node->lexeme, global_scope) != 0) // if its not a function call
    {
        if(search_in_hash_table(hash_table, node->lexeme, "global"))
        {
            if(search_for_function_declaration(hash_table, node->lexeme))
            {
                fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->lineno);
                fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
                fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m declared as function\n", node->lexeme);
                flag_semantic_error = 1;
                return;
            }
            add_apparition(hash_table, node->lexeme, node->lineno, global_scope);
            return;
        }
        if(!search_in_hash_table(hash_table, node->lexeme, global_scope))
        {
            fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->lineno);
            fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
            fprintf(stderr, "variable \x1b[1m'%s'\x1b[0m not declared in scope \x1b[1m'%s'\x1b[0m\n", node->lexeme, global_scope);
            flag_semantic_error = 1;
        }
        else
        {
            add_apparition(hash_table, node->lexeme, node->lineno, global_scope);
        }
    }
    else if(!search_for_function_declaration(hash_table, node->lexeme))
    {
        fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], node->lineno);
        fprintf(stderr, "\x1b[31msemantic error: \x1b[0m");
        fprintf(stderr, "function \x1b[1m'%s'\x1b[0m not declared\n", node->lexeme);
        flag_semantic_error = 1;
    }
}

void process_null(hash_table_t* hash_table, ast_node_t* node)
{
    // 
}

