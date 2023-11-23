%{

    #include "libraries.h"

    int yylex();
    int yyparse();
    void yyerror(char *s);
%}

%expect 1

%token ELSE_TOKEN IF_TOKEN INT_TOKEN RETURN_TOKEN VOID_TOKEN WHILE_TOKEN
%token PLUS_TOKEN MINUS_TOKEN MULTIPLY_TOKEN DIVID_TOKENE
%token LT_TOKEN LTE_TOKEN GT_TOKEN GTE_TOKEN EQ_TOKEN NEQ_TOKEN ASSIGN_TOKEN
%token SEMICOLON_TOKEN COMMA_TOKEN 
%token LPAREN_TOKEN RPAREN_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN LBRACE_TOKEN RBRACE_TOKEN
%token ID_TOKEN NUM_TOKEN
%token UNKNOW_TOKEN ERROR_TOKEN

%%

//1
program : decl_list 
    ;

//2
decl_list : decl_list declaration
          | declaration
          ;

//3
declaration : var_declaration
            | fun_declaration
            ;

//4
var_declaration : type_specIF_TOKENier ID_TOKEN SEMICOLON_TOKEN
                | type_specIF_TOKENier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN
                ;

//5
type_specIF_TOKENier : INT_TOKEN
               | VOID_TOKEN
               ;

//6
fun_declaration : type_specIF_TOKENier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl
                ;

//7
params : param_list
       | VOID_TOKEN
       ;

//8
param_list : param_list COMMA_TOKEN param
           | param
           ;

//9
param : type_specIF_TOKENier ID_TOKEN
      | type_specIF_TOKENier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN
      ;

//10
compound_decl : LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN
              ;

//11
local_declarations : local_declarations var_declaration
                   | /* vazio */
                   ;

//12
statement_list : statement_list statement
               | /* vazio */
               ;

//13
statement : expression_decl
          | compound_decl
          | selection_decl
          | iteration_decl
          | return_decl
          ;

//14
expression_decl : expression SEMICOLON_TOKEN
                | SEMICOLON_TOKEN
                ;

//15
selection_decl : IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement 
               | IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement
               ;

//16
iteration_decl : WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement
               ;

//17
return_decl : RETURN_TOKEN SEMICOLON_TOKEN
            | RETURN_TOKEN expression SEMICOLON_TOKEN
            ;

//18
expression : var ASSIGN_TOKEN expression
           | simple_expression
           ;

//19
var : ID_TOKEN
    | ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN
    ;

//20
simple_expression : sum_expression relational sum_expression
                  | sum_expression
                  ;

//21
relational : LT_TOKEN
           | LTE_TOKEN
           | GT_TOKEN
           | GTE_TOKEN
           | EQ_TOKEN
           | NEQ_TOKEN
           ;

//22
sum_expression : sum_expression sum term
               | term
               ;

//23
sum : PLUS_TOKEN
    | MINUS_TOKEN
    ;

//24
term : term mult factor
     | factor
     ;

//25
mult : MULTIPLY_TOKEN
     | DIVID_TOKENE
     ;

//26
factor : LPAREN_TOKEN expression RPAREN_TOKEN
       | var
       | activation
       | NUM_TOKEN
       ;

//27
activation : ID_TOKEN LPAREN_TOKEN args RPAREN_TOKEN
           ;

//28
args : arg_list
     | /* vazio */
     ;

//29
arg_list : arg_list COMMA_TOKEN expression
         | expression
         ;
%%

void yyerror(char *s)
{
    printf("\n%s: invalid lexeme!\n", s);
}

int yylex()
{
    //token_t token;
    //token = get_next_token(input_file, &buffer, bst_root);
    return 1;
}

void parse(FILE *input_file)
{    
    //ast_node_t ast_root = NULL;
    yyparse();

    return;// ast_root;
}

//estrutura de dados usar YYSTYPE