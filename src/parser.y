%{

    #include "libraries.h"

    

    int yylex();
    int yyparse();
    void yyerror(char *s);

%}

%expect 1

%token ELSE IF INT RETURN VOID WHILE
%token PLUS MINUS MULTIPLY DIVIDE
%token LT LTE GT GTE EQ NEQ ASSIGN
%token SEMICOLON COMMA 
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%token ID NUM
%token UNKNOW ERROR

%%

//1
program : decl_list {printf("$$ = %p\n", $1);}
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
var_declaration : type_specifier ID SEMICOLON
                | type_specifier ID LBRACKET NUM RBRACKET SEMICOLON
                ;

//5
type_specifier : INT
               | VOID
               ;

//6
fun_declaration : type_specifier ID LPAREN params RPAREN compound_decl
                ;

//7
params : param_list
       | VOID
       ;

//8
param_list : param_list COMMA param
           | param
           ;

//9
param : type_specifier ID
      | type_specifier ID LBRACKET RBRACKET
      ;

//10
compound_decl : LBRACE local_declarations statement_list RBRACE
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
expression_decl : expression SEMICOLON
                | SEMICOLON
                ;

//15
selection_decl : IF LPAREN expression RPAREN statement 
               | IF LPAREN expression RPAREN statement ELSE statement
               ;

//16
iteration_decl : WHILE LPAREN expression RPAREN statement
               ;

//17
return_decl : RETURN SEMICOLON
            | RETURN expression SEMICOLON
            ;

//18
expression : var ASSIGN expression
           | simple_expression
           ;

//19
var : ID
    | ID LBRACKET expression RBRACKET
    ;

//20
simple_expression : sum_expression relational sum_expression
                  | sum_expression
                  ;

//21
relational : LT
           | LTE
           | GT
           | GTE
           | EQ
           | NEQ
           ;

//22
sum_expression : sum_expression sum term
               | term
               ;

//23
sum : PLUS
    | MINUS
    ;

//24
term : term mult factor
     | factor
     ;

//25
mult : MULTIPLY
     | DIVIDE
     ;

//26
factor : LPAREN expression RPAREN
       | var
       | activation
       | NUM
       ;

//27
activation : ID LPAREN args RPAREN
           ;

//28
args : arg_list
     | /* vazio */
     ;

//29
arg_list : arg_list COMMA expression
         | expression
         ;
%%

void yyerror(char *s)
{
    printf("\n%s: invalid lexeme!\n", s);
}

int yylex()
{
    token_t token;
    token = get_next_token(input_file, &buffer, bst_root);
    return token->type;
}

ast_node_t parse(FILE *input_file, bst_node_t *bst_root)
{
    ast_node_t ast_root = NULL;

    yyin = input_file;
    yyout = fopen("output.txt", "w");

    yyrestart(yyin);
    
    yyparse(&ast_root);

    fclose(yyout);

    return ast_root;
}

//estrutura de dados usar YYSTYPE