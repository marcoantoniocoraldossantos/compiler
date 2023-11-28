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
        printf("reduced: program -> decl_list\n");
        //global_ast_tree = $1;
    }
    ;

    decl_list : decl_list declaration
    {
        //printf("reduced: decl_list -> decl_list declaration\n");

    }
    | declaration
    {
        //printf("reduced: decl_list -> declaration\n");

    }
    ;

    declaration : var_declaration
    {
        //printf("reduced: declaration -> var_declaration\n");

    }
    | fun_declaration
    {
        //printf("reduced: declaration -> fun_declaration\n");

    }
    ;

    var_declaration : type_specifier ID_TOKEN SEMICOLON_TOKEN
    {
        //printf("reduced: var_declaration -> type_specifier ID_TOKEN SEMICOLON_TOKEN\n");
    
    }
    | type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN
    {
        //printf("reduced: var_declaration -> type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN\n");
    
    }
    ;

    type_specifier : INT_TOKEN
    {
        //printf("reduced: type_specifier -> INT_TOKEN\n");

    }
    | VOID_TOKEN
    {
        //printf("reduced: type_specifier -> VOID_TOKEN\n");
    
    }
    ;

    fun_declaration : type_specifier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl
    {
        //printf("reduced: fun_declaration -> type_specifier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl\n");
    
    }
    ;

    params : param_list
    {
        //printf("reduced: params -> param_list\n");
    
    }
    | VOID_TOKEN
    {
        //printf("reduced: params -> VOID_TOKEN\n");
    
    }
    ;

    param_list : param_list COMMA_TOKEN param
    {
        //printf("reduced: param_list -> param_list COMMA_TOKEN param\n");
    
    }
    | param
    {
        //printf("reduced: param_list -> param\n");
    
    }
    ;

    param : type_specifier ID_TOKEN
    {
        //printf("reduced: param -> type_specifier ID_TOKEN\n");
    
    }
    | type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN
    {
        //printf("reduced: param -> type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN\n");
    
    }
    ;

    compound_decl : LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN
    {
        //printf("reduced: compound_decl -> LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN\n");
    
    }
    ;

    local_declarations : local_declarations var_declaration
    {
        //printf("reduced: local_declarations -> local_declarations var_declaration\n");
    
    }
    | /* vazio */
    {
        //printf("reduced: local_declarations -> vazio\n");
    
    }
    ;

    statement_list : statement_list statement
    {
        //printf("reduced: statement_list -> statement_list statement\n");
    
    }
    | /* vazio */
    {
        //printf("reduced: statement_list -> vazio\n");
    
    }
    ;

    statement : expression_decl
    {
        //printf("reduced: statement -> expression_decl\n");
    
    }
    | compound_decl
    {
        //printf("reduced: statement -> compound_decl\n");
    
    }
    | selection_decl
    {
        //printf("reduced: statement -> selection_decl\n");
    
    }
    | iteration_decl
    {
        //printf("reduced: statement -> iteration_decl\n");
    
    }
    | return_decl
    {
        //printf("reduced: statement -> return_decl\n");
    
    }
    ;

    expression_decl : expression SEMICOLON_TOKEN
    {
        //printf("reduced: expression_decl -> expression SEMICOLON_TOKEN\n");
    
    }
    | SEMICOLON_TOKEN
    {
        //printf("reduced: expression_decl -> SEMICOLON_TOKEN\n");
    
    }
    ;

    selection_decl : IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement 
    {
        //printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
    
    }
    | IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement
    {
        //printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement\n");
    
    }
    ;

    iteration_decl : WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement
    {
        //printf("reduced: iteration_decl -> WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
    
    }
    ;

    return_decl : RETURN_TOKEN SEMICOLON_TOKEN
    {
        //printf("reduced: return_decl -> RETURN_TOKEN SEMICOLON_TOKEN\n");
    
    }
    | RETURN_TOKEN expression SEMICOLON_TOKEN
    {
        //printf("reduced: return_decl -> RETURN_TOKEN expression SEMICOLON_TOKEN\n");
    
    }
    ;

    expression : var ASSIGN_TOKEN expression
    {
        //printf("reduced: expression -> var ASSIGN_TOKEN expression\n");
    
    }
    | simple_expression
    {
        //printf("reduced: expression -> simple_expression\n");
    
    }
    ;

    var : ID_TOKEN
    {
        //printf("reduced: var -> ID_TOKEN\n");
    
    }
    | ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN
    {
        //printf("reduced: var -> ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN\n");
    
    }
    ;

    simple_expression : sum_expression relational sum_expression
    {
        //printf("reduced: simple_expression -> sum_expression relational sum_expression\n");
    
    }
    | sum_expression
    {
        //printf("reduced: simple_expression -> sum_expression\n");
    
    }
    ;

    relational : LT_TOKEN
    {
        //printf("reduced: relational -> LT_TOKEN\n");
    
    }
    | LTE_TOKEN
    {
        //printf("reduced: relational -> LTE_TOKEN\n");
    
    }
    | GT_TOKEN
    {
        //printf("reduced: relational -> GT_TOKEN\n");
    
    }
    | GTE_TOKEN
    {
        //printf("reduced: relational -> GTE_TOKEN\n");
    
    }
    | EQ_TOKEN
    {
        //printf("reduced: relational -> EQ_TOKEN\n");
    
    }
    | NEQ_TOKEN
    {
        //printf("reduced: relational -> NEQ_TOKEN\n");
    
    }
    ;

    sum_expression : sum_expression sum term
    {
        //printf("reduced: sum_expression -> sum_expression sum term\n");
    
    }
    | term
    {
        //printf("reduced: sum_expression -> term\n");
    
    }
    ;

    sum : PLUS_TOKEN
    {
        //printf("reduced: sum -> PLUS_TOKEN\n");
    
    }
    | MINUS_TOKEN
    {
        //printf("reduced: sum -> MINUS_TOKEN\n");
    
    }
    ;

    term : term mult factor
    {
        //printf("reduced: term -> term mult factor\n");
    
    }
    | factor
    {
        //printf("reduced: term -> factor\n");
    
    }
    ;

    mult : MULTIPLY_TOKEN
    {
        //printf("reduced: mult -> MULTIPLY_TOKEN\n");
        ast_node_t* multiply_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(multiply_node);
        printf("multiply lexeme: %s line number: %d\n", multiply_node->lexeme, multiply_node->lineno);
        //$$ = multiply_node;

        free_ast(multiply_node);
    }
    | DIVIDE_TOKEN
    {
        //printf("reduced: mult -> DIVIDE_TOKEN\n");
        ast_node_t* divide_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(divide_node);
        printf("divide lexeme: %s line number: %d\n", divide_node->lexeme, divide_node->lineno);
        //$$ = divide_node;

        free_ast(divide_node);
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
        //rintf("reduced: factor -> activation\n");
        $$ = $1;
    
    }
    | NUM_TOKEN
    {
        //printf("reduced: factor -> NUM_TOKEN\n");
        //create NUM node
        ast_node_t* num_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, CONST_EXP, NO_TYPE);
        print_ast(num_node);
        printf("num lexeme: %s line number: %d\n", num_node->lexeme, num_node->lineno);

        //$$ = num_node;
        
        free_ast(num_node);
    }
    ;

    activation : ID_TOKEN LPAREN_TOKEN args RPAREN_TOKEN
    {
        //printf("reduced: activation -> ID_TOKEN LPAREN_TOKEN args RPAREN_TOKEN\n");
        //create ID node
        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        print_ast(id_node);
        printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        
        //add_child(id_node, $3);
        //$$ = id_node;
        
        free_ast(id_node);
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
            add_sibling($1, $3);
            $$ = $1;
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

        // node_kind_t kind = EXPRESSION_NODE;
        // ast_node_t* node = create_default_node(kind);
        // printf("\n\n\ncreated node: %s\n\n\n", node->lexeme);
        // add_child(global_ast_tree, node);
        // add_child(node, $1);
        // print_ast(global_ast_tree);
    }
    ;

%%

void yyerror(char *s)
{
    printf("\n%s: invalid lexeme!\n", s);
    printf("exiting...\n");
    exit(1);
}

int yylex()
{
    token_t *token = get_next_token();
    print_token(token);
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
    for (int i = 0; i < token_count; ++i) 
    {
        free_token(token_list[i]);
    }
}

void parse() 
{ 
    yyparse(); 
    free_tokens();    
}