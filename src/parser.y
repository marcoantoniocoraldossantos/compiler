%{

    #include "libraries.h"

    int yylex();
    int yyparse();
    void yyerror(char *s);

%}

%token ELSE IF INT RETURN VOID WHILE
%token PLUS MINUS MULTIPLY DIVIDE
%token LT LTE GT GTE EQ NEQ ASSIGN
%token SEMICOLON COMMA 
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%token ID NUM
%token UNKNOW ERROR

%%

program : decl_list
    ;

decl_list : decl_list declaration
          | declaration
          ;

declaration : var_declaration
            | fun_declaration
            ;

var_declaration : type_specifier ID SEMICOLON
                | type_specifier ID LBRACKET NUM_TOKEN RBRACKET SEMICOLON
                ;

type_specifier : INT
               | VOID
               ;

fun_declaration : type_specifier ID LPAREN params RPAREN compound_decl
                ;

params : param_list
       | VOID
       ;

param_list : param_list ',' param
           | param
           ;

param : type_specifier ID
      | type_specifier ID LBRACKET RBRACKET
      ;

compound_decl : LBRACE local_declarations statement_list RBRACE
              ;

local_declarations : local_declarations var_declaration
                   | /* vazio */
                   ;

statement_list : statement_list statement
               | /* vazio */
               ;

statement : expression_decl
          | compound_decl
          | selection_decl
          | iteration_decl
          | return_decl
          ;

expression_decl : expression SEMICOLON
                | SEMICOLON
                ;

selection_decl : IF LPAREN expression RPAREN statement %prec LESS
               | IF LPAREN expression RPAREN statement ELSE statement
               ;

iteration_decl : WHILE LPAREN expression RPAREN statement
               ;

return_decl : RETURN SEMICOLON
            | RETURN expression SEMICOLON
            ;

expression : var ASSIGN expression
           | simple_expression
           ;

var : ID
    | ID LBRACKET expression RBRACKET
    ;

simple_expression : sum_expression relational sum_expression
                  | sum_expression
                  ;

relational : LESS
           | LESSEQUAL
           | GREATER
           | GREATEREQUAL
           | EQUAL
           | NOTEQUAL
           ;

sum_expression : sum_expression PLUS term
               | sum_expression MINUS term
               | term
               ;

term : term TIMES factor
     | term DIVIDE factor
     | factor
     ;

mult : TIMES
     | DIVIDE
     ;

factor : LPAREN expression RPAREN
       | var
       | activation
       | NUM
       ;

activation : ID LPAREN args RPAREN
           ;

args : arg_list
     | /* vazio */
     ;

arg_list : arg_list ',' expression
         | expression
         ;
%%

void yyerror(char *s)
{
    printf("\n%s: invalid lexeme!\n", s);
}

int yylex()
{

    
}

int main()
{
    yyparse();
    return 0;
}

//estrutura de dados usar YYSTYPE