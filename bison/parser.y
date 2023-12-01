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
        global_ast_tree = $1;
    }
    ;

    decl_list : decl_list declaration
    {
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $2);
        }
        else 
        {
            $$ = $2;
        }
    }
    | declaration
    {
        $$ = $1;
    }
    ;

    declaration : var_declaration
    {
        $$ = $1;
    }
    | fun_declaration
    {
        $$ = $1;
    }
    ;

    var_declaration : type_specifier id SEMICOLON_TOKEN
    {
        $$ = $1;

        add_child($$, $2);
    }
    | type_specifier id LBRACKET_TOKEN num RBRACKET_TOKEN SEMICOLON_TOKEN
    {
        $$ = $1;
        add_child($$, $2);
        add_child($$, $4);
    }
    ;

    type_specifier : INT_TOKEN
    {
        ast_node_t* int_node = new_ast_node(EXPRESSION_NODE, global_line_number, "int", NULL_STMT, CONST_EXP, INT_TYPE);

        $$ = int_node;
    }
    | VOID_TOKEN
    {
        ast_node_t* void_node = new_ast_node(EXPRESSION_NODE, global_line_number, "void", NULL_STMT, CONST_EXP, VOID_TYPE);

        $$ = void_node;

    }
    ;

    fun_declaration : type_specifier id LPAREN_TOKEN params RPAREN_TOKEN compound_decl
    {
        $$ = $1;        
        add_child($$, $4);
        add_child($$, $2);
        add_child($2, $6);
    }
    ;

    

    params : param_list
    {
        $$ = $1;
    }
    | VOID_TOKEN
    {
        ast_node_t* void_node = new_ast_node(NULL_NODE, global_line_number, "void", NULL_STMT, NULL_EXP, NULL_TYPE);

        $$ = void_node;
    }
    ;

    param_list : param_list COMMA_TOKEN param
    {
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
        $$ = $1;
    }
    ;

    param : type_specifier id
    {
        $$ = $1;
        add_child($$, $2);
    }
    | type_specifier id LBRACKET_TOKEN RBRACKET_TOKEN
    {
        $$ = $1;
        add_child($$, $2);
    }
    ;

    compound_decl : LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN
    {
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
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $2);
        }
        else 
        {
            $$ = $2;
        }
    }
    | /* vazio */
    {
        $$ = NULL;
    }
    ;

    statement_list : statement_list statement
    {
        if ($1 != NULL) 
        {
            $$ = $1;
            add_sibling($$, $2);
        }
        else 
        {
            $$ = $2;
        }
    }
    | /* vazio */
    {
        $$ = NULL;
    }
    ;

    statement : expression_decl
    {
        $$ = $1;
    }
    | compound_decl
    {
        $$ = $1;
    }
    | selection_decl
    {
        $$ = $1;
    }
    | iteration_decl
    {
        $$ = $1;
    }
    | return_decl
    {
        $$ = $1;
    }
    ;

    expression_decl : expression SEMICOLON_TOKEN
    {
        $$ = $1;
    }
    | SEMICOLON_TOKEN
    {
        $$ = NULL;
    }
    ;

    selection_decl : IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement
    {
        ast_node_t* if_node = new_ast_node(NULL_NODE, global_line_number, "if", NULL_STMT, NULL_EXP, NULL_TYPE);
        
        $$ = if_node;
        add_child($$, $3);
        add_child($$, $5);
    }
    | IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement
    {
        ast_node_t* if_node = new_ast_node(NULL_NODE, global_line_number, "if", NULL_STMT, NULL_EXP, NULL_TYPE);

        add_child(if_node, $3);
        add_child(if_node, $5);
        add_child(if_node, $7);
        $$ = if_node;
    }
    ;

    iteration_decl : WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement
    {
        ast_node_t* while_node = new_ast_node(NULL_NODE, global_line_number, "while", NULL_STMT, NULL_EXP, NULL_TYPE);

        $$ = while_node;
        add_child($$, $3);
        add_child($$, $5);
    }
    ;

    return_decl : RETURN_TOKEN SEMICOLON_TOKEN
    {
        ast_node_t* return_node = new_ast_node(NULL_NODE, global_line_number, "return", NULL_STMT, NULL_EXP, NULL_TYPE);
    
        $$ = return_node;
    }
    | RETURN_TOKEN expression SEMICOLON_TOKEN
    {
        ast_node_t* return_node = new_ast_node(NULL_NODE, global_line_number, "return", NULL_STMT, NULL_EXP, NULL_TYPE);

        $$ = return_node;
        add_child($$, $2);
    }
    ;

    expression : var ASSIGN_TOKEN expression
    {
        ast_node_t* assign_node = new_ast_node(NULL_NODE, global_line_number, "==", NULL_STMT, NULL_EXP, NULL_TYPE);
     
        $$ = assign_node;
        add_child($$, $1);
        add_child($$, $3);
    }
    | simple_expression
    {
        $$ = $1;
    }
    ;

    var : id
    {
        $$ = $1;
    }
    | id LBRACKET_TOKEN expression RBRACKET_TOKEN
    {
        $$ = $1;
        add_child($$, $3);
    }
    ;

    simple_expression : sum_expression relational sum_expression
    {
        $$ = $2;
        add_child($$, $1);
        add_child($$, $3);
    }
    | sum_expression
    {
        $$ = $1;
    }
    ;

    relational : LT_TOKEN
    {
        ast_node_t* lt_node = new_ast_node(NULL_NODE, global_line_number, "<", NULL_STMT, NULL_EXP, NULL_TYPE);
        
        $$ = lt_node;
    }
    | LTE_TOKEN
    {
        ast_node_t* lte_node = new_ast_node(NULL_NODE, global_line_number, "<=", NULL_STMT, NULL_EXP, NULL_TYPE);

        $$ = lte_node;
    }
    | GT_TOKEN
    {
        ast_node_t* gt_node = new_ast_node(NULL_NODE, global_line_number, ">", NULL_STMT, NULL_EXP, NULL_TYPE);

        $$ = gt_node;
    }
    | GTE_TOKEN
    {
        ast_node_t* gte_node = new_ast_node(NULL_NODE, global_line_number, ">=", NULL_STMT, NULL_EXP, NULL_TYPE);
      
        $$ = gte_node;
    }
    | EQ_TOKEN
    {
        ast_node_t* eq_node = new_ast_node(NULL_NODE, global_line_number, "=", NULL_STMT, NULL_EXP, NULL_TYPE);

        $$ = eq_node;
    }
    | NEQ_TOKEN
    {
        ast_node_t* neq_node = new_ast_node(NULL_NODE, global_line_number, "!=", NULL_STMT, NULL_EXP, NULL_TYPE);
   
        $$ = neq_node;
    }
    ;

    sum_expression : sum_expression sum term
    {        
        $$ = $2;
        add_child($$, $1);
        add_child($$, $3);
    }
    | term
    {
        $$ = $1;
    }
    ;

    sum : PLUS_TOKEN
    {
        ast_node_t* plus_node = new_ast_node(NULL_NODE, global_line_number, "+", NULL_STMT, NULL_EXP, NULL_TYPE);

        $$ = plus_node;
    }
    | MINUS_TOKEN
    {
        ast_node_t* minus_node = new_ast_node(NULL_NODE, global_line_number, "-", NULL_STMT, NULL_EXP, NULL_TYPE);
      
        $$ = minus_node;
    }
    ;

    term : term mult factor
    {
        $$ = $2;
        add_child($$, $1);
        add_child($$, $3);
        
    }
    | factor
    {
        $$ = $1;
    }
    ;

    mult : MULTIPLY_TOKEN
    {
        ast_node_t* multiply_node = new_ast_node(
            EXPRESSION_NODE,    // Tipo do nó: Expressão
            global_line_number, // Número da linha onde ocorre a operação de multiplicação
            "*",                // Lexema representando a operação de multiplicação
            NULL_STMT,          // Operação de multiplicação não requer um statement específico
            OP_EXP,             // Tipo de expressão: Operação
            NULL_TYPE           // Não se aplica o tipo aqui, pode ser NULL_TYPE
        );

        $$ = multiply_node;
    }
    | DIVIDE_TOKEN
    {
        ast_node_t* divide_node = new_ast_node(
            EXPRESSION_NODE,    // Tipo do nó: Expressão
            global_line_number, // Número da linha onde ocorre a operação de divisão
            "/",                // Lexema representando a operação de divisão
            NULL_STMT,          // Operação de divisão não requer um statement específico
            OP_EXP,             // Tipo de expressão: Operação
            NULL_TYPE           // Não se aplica o tipo aqui, pode ser NULL_TYPE
        );

        $$ = divide_node;
    }   
    ;

    factor : LPAREN_TOKEN expression RPAREN_TOKEN
    {
        $$ = $2;
    }
    | var
    {
        $$ = $1;
    }
    | activation
    {
        $$ = $1;
    }
    | num
    {
        $$ = $1;
    }
    ;

    activation : id LPAREN_TOKEN args RPAREN_TOKEN
    {
        $$ = $1;
        add_child($$, $3);
    }
    ;

    args : arg_list
    {
        $$ = $1;
    }
    | /* vazio */
    {
        $$ = NULL;
    }
    ;

    arg_list : arg_list COMMA_TOKEN expression
    {
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
        $$ = $1;
    }
    ;

    id : ID_TOKEN
    {
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            if (convert_token(type) == ID_TOKEN) 
            {
                token = token_list[i];
                break;
            }
        }

        ast_node_t* id_node = new_ast_node(
            EXPRESSION_NODE,         // Tipo do nó: Expressão
            global_line_number,      // Número da linha onde o identificador foi encontrado
            token->lexeme,           // Valor do identificador em formato de string
            NULL_STMT,               // Se for um identificador, pode ser NULL_STMT
            ID_EXP,                  // Tipo de expressão: Identificador
            NULL_TYPE                // Não se aplica o tipo aqui, pode ser NULL_TYPE
        );

        $$ = id_node; 


    }
    ;

    num : NUM_TOKEN
    {
        token_t* token = NULL;
        for(int i = token_count-1; i >= 0; i--)
        {
            token_type_t type = token_list[i]->type;
            if (convert_token(type) == NUM_TOKEN) 
            {
                token = token_list[i];
                break;
            }
        }

        ast_node_t* num_node = new_ast_node(
            EXPRESSION_NODE,        
            global_line_number,          
            token->lexeme,        
            NULL_STMT,              
            CONST_EXP,              
            INT_TYPE                
        );

        $$ = num_node; 
    }

%%

void yyerror(char *s)
{
    printf("\n%s: \'%s\' at line %d\n", s, global_lexeme, global_line_number);
    printf("exiting...\n");

    exit(1);
}

int yylex()
{
    token_t *token = get_next_token();
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
        return ERROR_TOKEN; 
    }    

    token_list[token_count++] = token; 

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