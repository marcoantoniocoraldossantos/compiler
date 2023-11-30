%{
    #define YYSTYPE ast_node_t*

    #include "libraries.h"

    int global_line_number;
    char global_lexeme[64];
    token_type_t global_token_type;

    #define MAX_TOKENS 100000
    token_t* token_list[MAX_TOKENS];
    int token_count = 0;

    void parse();

    int yylex();
    int yyparse();
    void yyerror(char *s);
%}

%expect 1

%token ELSE_TOKEN IF_TOKEN INT_TOKEN RETURN_TOKEN VOID_TOKEN WHILE_TOKEN
%token PLUS_TOKEN MINUS_TOKEN MULTIPLY_TOKEN DIVIDE_TOKEN
%token LT_TOKEN LTE_TOKEN GT_TOKEN GTE_TOKEN EQ_TOKEN NEQ_TOKEN ASSIGN_TOKEN
%token SEMICOLON_TOKEN COMMA_TOKEN 
%token LPAREN_TOKEN RPAREN_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN LBRACE_TOKEN RBRACE_TOKEN
%token ID_TOKEN NUM_TOKEN
%token UNKNOW_TOKEN ERROR_TOKEN

%%

    program : decl_list 
    {
        //printf("reduced: program -> decl_list\n");
        global_ast_tree = $1;
        //print_ast($$);
    }
    ;

    decl_list : decl_list declaration
    {
        //printf("reduced: decl_list -> decl_list declaration\n");
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $2);
        }
        else 
        {
            $$ = $2;
        }

        // print_ast($$);
    }
    | declaration
    {
        //printf("reduced: decl_list -> declaration\n");
        $$ = $1;

        // print_ast($$);
    }
    ;

    declaration : var_declaration
    {
        //printf("reduced: declaration -> var_declaration\n");
        $$ = $1;

        // print_ast($$);
    }
    | fun_declaration
    {
        //printf("reduced: declaration -> fun_declaration\n");
        $$ = $1;

        // print_ast($$);
    }
    ;

    var_declaration : type_specifier ID_TOKEN SEMICOLON_TOKEN
    {
        //printf("reduced: var_declaration -> type_specifier ID_TOKEN SEMICOLON_TOKEN\n");

        $$ = $1;

        //find ID in tokens list
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == ID_TOKEN) 
            {
                // printf("found token id\n");
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        add_child($$, id_node);

        // print_ast($$);

        // free_ast(id_node);
    }
    | type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN
    {
        //printf("reduced: var_declaration -> type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN\n");

        //find ID in tokens list
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == ID_TOKEN) 
            {
                // printf("found token id\n");
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);

        //find NUM in tokens list
        token_t* token_num = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == NUM_TOKEN) 
            {
                token_num = token_list[i];
                break;
            }
        }

        ast_node_t* num_node = new_ast_node(EXPRESSION_NODE, global_line_number, token_num->lexeme, NOT_STMT, CONST_EXP, NO_TYPE);

        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        $$ = $1;
        add_child($$, id_node);
        add_child($$, num_node);

        // print_ast($$);

        // free_ast(id_node);
    }
    ;

    type_specifier : INT_TOKEN
    {
        //printf("reduced: type_specifier -> INT_TOKEN\n");
        ast_node_t* int_node = new_ast_node(EXPRESSION_NODE, global_line_number, "int", NOT_STMT, CONST_EXP, INT_TYPE);
        //print_ast(int_node);
        //printf("int lexeme: %s line number: %d\n", int_node->lexeme, int_node->lineno);

        $$ = int_node;

        // print_ast($$);

        // free_ast(int_node);
    }
    | VOID_TOKEN
    {
        //printf("reduced: type_specifier -> VOID_TOKEN\n");
        ast_node_t* void_node = new_ast_node(EXPRESSION_NODE, global_line_number, "void", NOT_STMT, CONST_EXP, VOID_TYPE);
        //print_ast(void_node);
        //printf("void lexeme: %s line number: %d\n", void_node->lexeme, void_node->lineno);
       
        // print_ast($$);

        $$ = void_node;

    //    free_ast(void_node);
    }
    ;

    fun_declaration : type_specifier fun_id LPAREN_TOKEN params RPAREN_TOKEN compound_decl
    {
        //printf("reduced: fun_declaration -> type_specifier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl\n");

        //find ID in tokens list
        // token_t* token = NULL;
        // for(int i = token_count-1; i >= 0; i--)
        // {
        //     token_type_t type = token_list[i]->type;
        //     print_token(token_list[i]);
        //     if (convert_token(type) == ID_TOKEN) 
        //     {
        //         token = token_list[i];
        //         break;
        //     }
        // }

        // ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        $$ = $1;        
        add_child($$, $4);
        add_child($$, $2);
        add_child($2, $6);

        // print_ast($$);

        // free_ast(id_node);
    }
    ;

    fun_id : ID_TOKEN
    {
        //printf("reduced: fun_id -> ID_TOKEN\n");
        //find ID in tokens list
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == ID_TOKEN) 
            {
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        $$ = id_node;

        // print_ast($$);

        // free_ast(id_node);
    }

    params : param_list
    {
        //printf("reduced: params -> param_list\n");
        $$ = $1;
    }
    | VOID_TOKEN
    {
        //printf("reduced: params -> VOID_TOKEN\n");
        ast_node_t* void_node = new_ast_node(EXPRESSION_NODE, global_line_number, "void", NOT_STMT, CONST_EXP, VOID_TYPE);
        //print_ast(void_node);
        //printf("void lexeme: %s line number: %d\n", void_node->lexeme, void_node->lineno);
        $$ = void_node;

        // print_ast($$);

        // free_ast(void_node);
    }
    ;

    param_list : param_list COMMA_TOKEN param
    {
        //printf("reduced: param_list -> param_list COMMA_TOKEN param\n");
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $3);
            
        }
        else 
        {
            $$ = $3;
        }
    }
    | param
    {
        //printf("reduced: param_list -> param\n");
        $$ = $1;
    }
    ;

    param : type_specifier ID_TOKEN
    {
        //printf("reduced: param -> type_specifier ID_TOKEN\n");
        //find ID in tokens list
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == ID_TOKEN) 
            {
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);


        $$ = $1;
        add_child($$, id_node);
        

        // print_ast($$);

        // free_ast(id_node);
    }
    | type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN
    {
        //printf("reduced: param -> type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN\n");
        // find ID in tokens list
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == ID_TOKEN) 
            {
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        $$ = $1;
        add_child($$, id_node);
        

        // print_ast($$);

        // free_ast(id_node);
    }
    ;

    compound_decl : LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN
    {
        //printf("reduced: compound_decl -> LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN\n");
        if($2 != NULL) 
        {
            $$ = $2;
            add_sibling($$, $3);
            
        }
        else 
        {
            $$ = $3;
        }
    }
    ;

    local_declarations : local_declarations var_declaration
    {
        //printf("reduced: local_declarations -> local_declarations var_declaration\n");
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $2);
            
        }
        else 
        {
            $$ = $2;
        }

        // print_ast($$);
    }
    | /* vazio */
    {
        //printf("reduced: local_declarations -> vazio\n");
        $$ = NULL;

        // print_ast($$);
    }
    ;

    statement_list : statement_list statement
    {
        //printf("reduced: statement_list -> statement_list statement\n");
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $2);
           
        }
        else 
        {
            $$ = $2;
        }

        // print_ast($$);
    }
    | /* vazio */
    {
        //printf("reduced: statement_list -> vazio\n");
        $$ = NULL;

        //print_ast($$);
    }
    ;

    statement : expression_decl
    {
        //printf("reduced: statement -> expression_decl\n");
        $$ = $1;

        // print_ast($$);
    }
    | compound_decl
    {
        //printf("reduced: statement -> compound_decl\n");
        $$ = $1;

        // print_ast($$);
    }
    | selection_decl
    {
        //printf("reduced: statement -> selection_decl\n");
        $$ = $1;

        // print_ast($$);
    }
    | iteration_decl
    {
        //printf("reduced: statement -> iteration_decl\n");
        $$ = $1;

        // print_ast($$);
    }
    | return_decl
    {
        //printf("reduced: statement -> return_decl\n");
        $$ = $1;

        // print_ast($$);
    }
    ;

    expression_decl : expression SEMICOLON_TOKEN
    {
        //printf("reduced: expression_decl -> expression SEMICOLON_TOKEN\n");
        $$ = $1;

        // print_ast($$);
    }
    | SEMICOLON_TOKEN
    {
        //printf("reduced: expression_decl -> SEMICOLON_TOKEN\n");
        $$ = NULL;

        // print_ast($$);
    }
    ;

    selection_decl : IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement
    {
        //printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
        ast_node_t* if_node = new_ast_node(STATEMENT_NODE, global_line_number, "if", IF_STMT, NOT_EXP, NO_TYPE);
        //print_ast(if_node);
        //printf("if lexeme: %s line number: %d\n", if_node->lexeme, if_node->lineno);
        
        $$ = if_node;
        add_child($$, $3);
        add_child($$, $5);
        
        // print_ast($$);

        // free_ast(if_node);
    }
    | IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement
    {
        //printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement\n");
        ast_node_t* if_node = new_ast_node(STATEMENT_NODE, global_line_number, "if", IF_STMT, NOT_EXP, NO_TYPE);
        //ast_node_t* else_node = new_ast_node(STATEMENT_NODE, global_line_number, "else", ELSE_STMT, NOT_EXP, NO_TYPE);
        //print_ast(if_node);
        //printf("if lexeme: %s line number: %d\n", if_node->lexeme, if_node->lineno);
        
        add_child(if_node, $3);
        add_child(if_node, $5);
        add_child(if_node, $7);
        $$ = if_node;

        // print_ast($$);

        // free_ast(if_node);
    }
    ;

    // fun_else: ELSE_TOKEN statement
    // {
    //     //create else node
    //     //printf("reduced: fun_else -> ELSE_TOKEN statement\n");
    //     ast_node_t* else_node = new_ast_node(STATEMENT_NODE, global_line_number, "else", ELSE_STMT, NOT_EXP, NO_TYPE);
    //     //print_ast(else_node);
    //     //printf("else lexeme: %s line number: %d\n", else_node->lexeme, else_node->lineno);
    //     $$ = else_node;
    //     add_child($$, $2);
    // }
    // |
    // {
    //     $$ = NULL;
    // } 


    iteration_decl : WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement
    {
        //printf("reduced: iteration_decl -> WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
        ast_node_t* while_node = new_ast_node(STATEMENT_NODE, global_line_number, "while", WHILE_STMT, NOT_EXP, NO_TYPE);
        //print_ast(while_node);
        //printf("while lexeme: %s line number: %d\n", while_node->lexeme, while_node->lineno);
        
        $$ = while_node;
        add_child($$, $3);
        add_child($$, $5);

        // print_ast($$);

        // free_ast(while_node);
    }
    ;

    return_decl : RETURN_TOKEN SEMICOLON_TOKEN
    {
        //printf("reduced: return_decl -> RETURN_TOKEN SEMICOLON_TOKEN\n");
        ast_node_t* return_node = new_ast_node(STATEMENT_NODE, global_line_number, "return", RETURN_STMT, NOT_EXP, NO_TYPE);
        //print_ast(return_node);
        //printf("return lexeme: %s line number: %d\n", return_node->lexeme, return_node->lineno);
        
        $$ = return_node;

        // print_ast($$);

        // free_ast(return_node);
    }
    | RETURN_TOKEN expression SEMICOLON_TOKEN
    {
        //printf("reduced: return_decl -> RETURN_TOKEN expression SEMICOLON_TOKEN\n");
        ast_node_t* return_node = new_ast_node(STATEMENT_NODE, global_line_number, "return", RETURN_STMT, NOT_EXP, NO_TYPE);
        //print_ast(return_node);
        //printf("return lexeme: %s line number: %d\n", return_node->lexeme, return_node->lineno);
        
        $$ = return_node;
        add_child($$, $2);
        
        // print_ast($$);

        // free_ast(return_node);
    }
    ;

    expression : var ASSIGN_TOKEN expression
    {
        //printf("reduced: expression -> var ASSIGN_TOKEN expression\n");
        ast_node_t* assign_node = new_ast_node(EXPRESSION_NODE, global_line_number, "==", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(assign_node);
        //printf("assign lexeme: %s line number: %d\n", assign_node->lexeme, assign_node->lineno);
        
        $$ = assign_node;
        add_child($$, $1);
        add_child($$, $3);
        
        // print_ast($$);

        // free_ast(assign_node);
    }
    | simple_expression
    {
        //printf("reduced: expression -> simple_expression\n");
        $$ = $1;

        // print_ast($$);
    }
    ;

    var : ID_TOKEN
    {
        //printf("reduced: var -> ID_TOKEN\n");
        //find ID in tokens list

        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == ID_TOKEN) 
            {
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        $$ = id_node;

        // print_ast($$);

        // free_ast(id_node);
    }
    | ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN
    {
        //printf("reduced: var -> ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN\n");
        //find ID in tokens list
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == ID_TOKEN) 
            {
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        $$ = id_node;
        add_child($$, $3);
        

        // print_ast($$);

        //free_ast(id_node);
    }
    ;

    simple_expression : sum_expression relational sum_expression
    {
        //printf("reduced: simple_expression -> sum_expression relational sum_expression\n");
        
        $$ = $2;
        add_child($$, $1);
        add_child($$, $3);

        // print_ast($$);
    }
    | sum_expression
    {
        //printf("reduced: simple_expression -> sum_expression\n");
        $$ = $1;

        // print_ast($$);
    }
    ;

    relational : LT_TOKEN
    {
        //printf("reduced: relational -> LT_TOKEN\n");
        ast_node_t* lt_node = new_ast_node(EXPRESSION_NODE, global_line_number, "<", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(lt_node);
        //printf("lt lexeme: %s line number: %d\n", lt_node->lexeme, lt_node->lineno);
        
        $$ = lt_node;

        // print_ast($$);
        // free_ast(lt_node);
    }
    | LTE_TOKEN
    {
        //printf("reduced: relational -> LTE_TOKEN\n");
        ast_node_t* lte_node = new_ast_node(EXPRESSION_NODE, global_line_number, "<=", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(lte_node);
        //printf("lte lexeme: %s line number: %d\n", lte_node->lexeme, lte_node->lineno);
        
        $$ = lte_node;

        // print_ast($$);
        //free_ast(lte_node);
    }
    | GT_TOKEN
    {
        //printf("reduced: relational -> GT_TOKEN\n");
        ast_node_t* gt_node = new_ast_node(EXPRESSION_NODE, global_line_number, ">", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(gt_node);
        //printf("gt lexeme: %s line number: %d\n", gt_node->lexeme, gt_node->lineno);
        
        $$ = gt_node;

        // print_ast($$);
        //free_ast(gt_node);
    }
    | GTE_TOKEN
    {
        //printf("reduced: relational -> GTE_TOKEN\n");
        ast_node_t* gte_node = new_ast_node(EXPRESSION_NODE, global_line_number, ">=", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(gte_node);
        //printf("gte lexeme: %s line number: %d\n", gte_node->lexeme, gte_node->lineno);
        
        $$ = gte_node;

        // print_ast($$);
        // free_ast(gte_node);
    }
    | EQ_TOKEN
    {
        //printf("reduced: relational -> EQ_TOKEN\n");
        ast_node_t* eq_node = new_ast_node(EXPRESSION_NODE, global_line_number, "=", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(eq_node);
        //printf("eq lexeme: %s line number: %d\n", eq_node->lexeme, eq_node->lineno);
        
        $$ = eq_node;

        // print_ast($$);
        //free_ast(eq_node);
    }
    | NEQ_TOKEN
    {
        //printf("reduced: relational -> NEQ_TOKEN\n");
        ast_node_t* neq_node = new_ast_node(EXPRESSION_NODE, global_line_number, "!=", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(neq_node);
        //printf("neq lexeme: %s line number: %d\n", neq_node->lexeme, neq_node->lineno);
        $$ = neq_node;

        // print_ast($$);
        //free_ast(neq_node);
    }
    ;

    sum_expression : sum_expression sum term
    {
        //printf("reduced: sum_expression -> sum_expression sum term\n");
        
        $$ = $2;
        add_child($$, $1);
        add_child($$, $3);
        

        // print_ast($$);
    }
    | term
    {
        //printf("reduced: sum_expression -> term\n");
        $$ = $1;

        // print_ast($$);
    }
    ;

    sum : PLUS_TOKEN
    {
        //printf("reduced: sum -> PLUS_TOKEN\n");
        ast_node_t* plus_node = new_ast_node(EXPRESSION_NODE, global_line_number, "+", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(plus_node);
        //printf("plus lexeme: %s line number: %d\n", plus_node->lexeme, plus_node->lineno);
        $$ = plus_node;

        //free_ast(plus_node);
        // print_ast($$);
    }
    | MINUS_TOKEN
    {
        //printf("reduced: sum -> MINUS_TOKEN\n");
        ast_node_t* minus_node = new_ast_node(EXPRESSION_NODE, global_line_number, "-", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(minus_node);
        //printf("minus lexeme: %s line number: %d\n", minus_node->lexeme, minus_node->lineno);
        $$ = minus_node;

        //free_ast(minus_node);
        // print_ast($$);
    }
    ;

    term : term mult factor
    {
        //printf("reduced: term -> term mult factor\n");
        
        
        $$ = $2;
        add_child($$, $1);
        add_child($$, $3);
        
        // print_ast($$);
    }
    | factor
    {
        //printf("reduced: term -> factor\n");
        $$ = $1;

        // print_ast($$);
    }
    ;

    mult : MULTIPLY_TOKEN
    {
        //printf("reduced: mult -> MULTIPLY_TOKEN\n");
        ast_node_t* multiply_node = new_ast_node(EXPRESSION_NODE, global_line_number, "*", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(multiply_node);
        //printf("multiply lexeme: %s line number: %d\n", multiply_node->lexeme, multiply_node->lineno);
        $$ = multiply_node;

        // print_ast($$);
        //free_ast(multiply_node);
    }
    | DIVIDE_TOKEN
    {
        //printf("reduced: mult -> DIVIDE_TOKEN\n");
        ast_node_t* divide_node = new_ast_node(EXPRESSION_NODE, global_line_number, "/", NOT_STMT, OP_EXP, NO_TYPE);
        //print_ast(divide_node);
        //printf("divide lexeme: %s line number: %d\n", divide_node->lexeme, divide_node->lineno);
        $$ = divide_node;

        // print_ast($$);

        // free_ast(divide_node);
    }   
    ;

    factor : LPAREN_TOKEN expression RPAREN_TOKEN
    {
        //printf("reduced: factor -> LPAREN_TOKEN expression RPAREN_TOKEN\n");
        $$ = $2;
    }
    | var
    {
        //printf("reduced: factor -> var\n");
        $$ = $1;
    
    }
    | activation
    {
        //printf("reduced: factor -> activation\n");
        $$ = $1;
    
    }
    | NUM_TOKEN
    {
        //printf("reduced: factor -> NUM_TOKEN\n");
        //create NUM node

        //find num is tokens list
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            //print_token(token_list[i]);
            if (convert_token(type) == NUM_TOKEN) 
            {
                // printf("found token num\n");
                token = token_list[i];
                break;
            }
        }

        ast_node_t* num_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, CONST_EXP, NO_TYPE);
        //print_ast(num_node);
        //printf("num lexeme: %s line number: %d\n", num_node->lexeme, num_node->lineno);

        $$ = num_node;
        
        //free_ast(num_node);
    }
    ;

    activation : fun_id LPAREN_TOKEN args RPAREN_TOKEN
    {
        //printf("reduced: activation -> ID_TOKEN LPAREN_TOKEN args RPAREN_TOKEN\n");
        //create ID node

        //find ID lexeme in token list
        // token_t* token = NULL;
        // for (int i = token_count-1; i >= 0; i--) 
        // {
        //     token_type_t type = token_list[i]->type;
        //     print_token(token_list[i]);
        //     if (convert_token(type) == ID_TOKEN) 
        //     {
        //         // printf("found token id\n");
        //         token = token_list[i];
        //         break;
        //     }
        // }

        // // printf("needed to find token id\n");
        // // printf("found token: %s\n", token->lexeme);

        // ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, token->lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        //print_ast(id_node);
        //printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        $$ = $1;
        add_child($$, $3);
        
        
        //free_ast(id_node);
    }
    ;

    args : arg_list
    {
        //printf("reduced: args -> arg_list\n");
        $$ = $1;
    }
    | /* vazio */
    {
        //printf("reduced: args -> vazio\n");
        $$ = NULL;
    }
    ;

    arg_list : arg_list COMMA_TOKEN expression
    {
        //printf("reduced: arg_list -> arg_list COMMA_TOKEN expression\n");
        // arg_list have expression as sibling
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $3);
            
        }
        else 
        {
            $$ = $3;
        }

    }
    | expression
    {
        //printf("reduced: arg_list -> expression\n");
        $$ = $1;
    }
    ;

%%

void yyerror(char *s)
{
    printf("\n%s: \'%s\' at line %d\n", s, global_lexeme, global_line_number);
    printf("exiting...\n");

    //free_ast(global_ast_tree);

    exit(1);
}

int yylex()
{
    token_t *token = get_next_token();
    //print_token(token);
    if(token!=NULL) save_token_info(token);


    if (token == NULL) 
    {
        // EOF
        return YYEOF;
    }

    int flag = process_token(token);
    int token_to_return = convert_token(token->type);  
    
    if (flag != 1) 
    {
        printf("lexical error: invalid token\n");
        free(token);
        return ERROR_TOKEN; // 
    }    


    token_list[token_count++] = token; 
    //free_token(token);

    //printf("will return token: %d\n", token_to_return);
    return token_to_return;
}

void free_tokens() 
{
    for(int i = token_count-1; i >= 0; i--)
    {
        free_token(token_list[i]);
    }
}

void parse() 
{ 
    yyparse(); 

    // for(int i = 0; i < token_count; ++i) 
    // {
    //     print_token(token_list[i]);
    // }

    free_tokens();    
}