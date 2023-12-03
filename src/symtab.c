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
            
            if(strcmp(node->lexeme, "void") == 0)
            {
                printf("semantic error: variable %s cannot be void\n", node->child[0]->lexeme);
                //exit(1);
                flag_semantic_error = 1;
                return;
            }
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

            //process_variable_parameter(hash_table, node, global_scope);
            insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, VARIABLE_TYPE);
            break;
        case EXT_VECTOR_PARAMETER:
            //printf("\next_vector_parameter\n");


            if(!search_in_hash_table(hash_table, node->child[0]->lexeme, global_scope))
            {
                insert_symbol(hash_table, node->child[0]->lexeme, INT_DATA, VARIABLE, node->child[0]->lineno, global_scope, ARRAY_TYPE);
            }
            break;
        case EXT_VOID_PARAMETER:
            //printf("\next_void_parameter\n");


            break;
        case EXT_IF:
            //printf("\next_if\n");


            break;
        case EXT_IF_ELSE:
            //printf("\next_if_else\n");
            
            break;
        case EXT_WHILE:
            //printf("\next_while\n");

            break;
        case EXT_ASSIGN:
            //printf("\next_assign\n");

            break;
        case EXT_OPERATOR:
            //printf("\next_operator\n");
            
            break;
        case EXT_RELATIONAL:
            //printf("\next_relational\n");
            

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

            //printf("\nlexeme %s", node->lexeme);
            //print_hash_table(hash_table);

            if(strcmp(node->lexeme, global_scope) != 0) // if its not a function call
            {
                //printf("\nlexeme %s global scope %s", node->lexeme, global_scope);
                if(search_in_hash_table(hash_table, node->lexeme, "global"))
                {
                    //add apparition
                    if(search_for_function_declaration(hash_table, node->lexeme))
                    {
                        //printf("\nis function %s line %d\n", node->lexeme, node->lineno);
                        printf("semantic error: %s already declared as function\n", node->lexeme);
                        //exit(1);
                        flag_semantic_error = 1;
                        return;
                    }
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
                //printf("\nis function %s line %d\n", node->lexeme, node->lineno);
                printf("semantic error: function %s not declared\n", node->lexeme);
                //exit(1);
                flag_semantic_error = 1;
            }

            //printf("\n-------------------");
            //print_hash_table(hash_table);

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