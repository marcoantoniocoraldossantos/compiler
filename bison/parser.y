%{

    #include "libraries.h"

    ast_node_t* parse();

    int yylex();
    int yyparse();
    void yyerror(char *s);

    ast_node_t* ast_root;
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
}
;

decl_list : decl_list declaration
{
    printf("reduced: decl_list -> decl_list declaration\n");
}
| declaration
{
    printf("reduced: decl_list -> declaration\n");
}
;

declaration : var_declaration
{
    printf("reduced: declaration -> var_declaration\n");
}
| fun_declaration
{
    printf("reduced: declaration -> fun_declaration\n");
}
;

var_declaration : type_specifier ID_TOKEN SEMICOLON_TOKEN
{
    printf("reduced: var_declaration -> type_specifier ID_TOKEN SEMICOLON_TOKEN\n");
}
| type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN
{
    printf("reduced: var_declaration -> type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN\n");
}
;

type_specifier : INT_TOKEN
{
    printf("reduced: type_specifier -> INT_TOKEN\n");
}
| VOID_TOKEN
{
    printf("reduced: type_specifier -> VOID_TOKEN\n");
}
;

fun_declaration : type_specifier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl
{
    printf("reduced: fun_declaration -> type_specifier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl\n");
}
;

params : param_list
{
    printf("reduced: params -> param_list\n");
}
| VOID_TOKEN
{
    printf("reduced: params -> VOID_TOKEN\n");
}
;

param_list : param_list COMMA_TOKEN param
{
    printf("reduced: param_list -> param_list COMMA_TOKEN param\n");
}
| param
{
    printf("reduced: param_list -> param\n");
}
;

param : type_specifier ID_TOKEN
{
    printf("reduced: param -> type_specifier ID_TOKEN\n");
}
| type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN
{
    printf("reduced: param -> type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN\n");
}
;

compound_decl : LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN
{
    printf("reduced: compound_decl -> LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN\n");
}
;

local_declarations : local_declarations var_declaration
{
    printf("reduced: local_declarations -> local_declarations var_declaration\n");
}
| /* vazio */
{
    printf("reduced: local_declarations -> vazio\n");
}
;

statement_list : statement_list statement
{
    printf("reduced: statement_list -> statement_list statement\n");
}
| /* vazio */
{
    printf("reduced: statement_list -> vazio\n");
}
;

statement : expression_decl
{
    printf("reduced: statement -> expression_decl\n");
}
| compound_decl
{
    printf("reduced: statement -> compound_decl\n");
}
| selection_decl
{
    printf("reduced: statement -> selection_decl\n");
}
| iteration_decl
{
    printf("reduced: statement -> iteration_decl\n");
}
| return_decl
{
    printf("reduced: statement -> return_decl\n");
}
;

expression_decl : expression SEMICOLON_TOKEN
{
    printf("reduced: expression_decl -> expression SEMICOLON_TOKEN\n");
}
| SEMICOLON_TOKEN
{
    printf("reduced: expression_decl -> SEMICOLON_TOKEN\n");
}
;

selection_decl : IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement 
{
    printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
}
| IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement
{
    printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement\n");
}
;

iteration_decl : WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement
{
    printf("reduced: iteration_decl -> WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
}
;

return_decl : RETURN_TOKEN SEMICOLON_TOKEN
{
    printf("reduced: return_decl -> RETURN_TOKEN SEMICOLON_TOKEN\n");
}
| RETURN_TOKEN expression SEMICOLON_TOKEN
{
    printf("reduced: return_decl -> RETURN_TOKEN expression SEMICOLON_TOKEN\n");
}
;

expression : var ASSIGN_TOKEN expression
{
    printf("reduced: expression -> var ASSIGN_TOKEN expression\n");
}
| simple_expression
{
    printf("reduced: expression -> simple_expression\n");
}
;

var : ID_TOKEN
{
    printf("reduced: var -> ID_TOKEN\n");
}
| ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN
{
    printf("reduced: var -> ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN\n");
}
;

simple_expression : sum_expression relational sum_expression
{
    printf("reduced: simple_expression -> sum_expression relational sum_expression\n");
}
| sum_expression
{
    printf("reduced: simple_expression -> sum_expression\n");
}
;

relational : LT_TOKEN
{
    printf("reduced: relational -> LT_TOKEN\n");
}
| LTE_TOKEN
{
    printf("reduced: relational -> LTE_TOKEN\n");
}
| GT_TOKEN
{
    printf("reduced: relational -> GT_TOKEN\n");
}
| GTE_TOKEN
{
    printf("reduced: relational -> GTE_TOKEN\n");
}
| EQ_TOKEN
{
    printf("reduced: relational -> EQ_TOKEN\n");
}
| NEQ_TOKEN
{
    printf("reduced: relational -> NEQ_TOKEN\n");
}
;

sum_expression : sum_expression sum term
{
    printf("reduced: sum_expression -> sum_expression sum term\n");
}
| term
{
    printf("reduced: sum_expression -> term\n");
}
;

sum : PLUS_TOKEN
{
    printf("reduced: sum -> PLUS_TOKEN\n");
}
| MINUS_TOKEN
{
    printf("reduced: sum -> MINUS_TOKEN\n");
}
;

term : term mult factor
{
    printf("reduced: term -> term mult factor\n");
}
| factor
{
    printf("reduced: term -> factor\n");
}
;

mult : MULTIPLY_TOKEN
{
    printf("reduced: mult -> MULTIPLY_TOKEN\n");
}
| DIVIDE_TOKEN
{
    printf("reduced: mult -> DIVID_TOKEN\n");
}
;

factor : LPAREN_TOKEN expression RPAREN_TOKEN
{
    printf("reduced: factor -> LPAREN_TOKEN expression RPAREN_TOKEN\n");
}
| var
{
    printf("reduced: factor -> var\n");
}
| activation
{
    printf("reduced: factor -> activation\n");
}
| NUM_TOKEN
{
    printf("reduced: factor -> NUM_TOKEN\n");
}
;

activation : ID_TOKEN LPAREN_TOKEN args RPAREN_TOKEN
{
    printf("reduced: activation -> ID_TOKEN LPAREN_TOKEN args RPAREN_TOKEN\n");
}
;

args : arg_list
{
    printf("reduced: args -> arg_list\n");
}
| /* vazio */
{
    printf("reduced: args -> vazio\n");
}
;

arg_list : arg_list COMMA_TOKEN expression
{
    printf("reduced: arg_list -> arg_list COMMA_TOKEN expression\n");
}
| expression
{
    printf("reduced: arg_list -> expression\n");
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

    if (token == NULL) {
        // EOF: Retorna um token especial para indicar o fim do arquivo
        printf("lexical error: unexpected EOF\n");
        return YYEOF;
    }

    int flag = process_token(token);
    int token_to_return = convert_token(token->type);  
    
    if (flag != 1) {
        printf("lexical error: invalid token\n");
        return ERROR_TOKEN; // Retornando um token de erro especial
    }

    printf("will return token: %d\n", token_to_return);
    return token_to_return;
}

ast_node_t *parse()
{       
    ast_root = initialize_ast();

    yyparse();

    return ast_root;
}