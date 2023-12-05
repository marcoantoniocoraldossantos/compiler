/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ELSE_TOKEN = 258,              /* ELSE_TOKEN  */
    IF_TOKEN = 259,                /* IF_TOKEN  */
    INT_TOKEN = 260,               /* INT_TOKEN  */
    RETURN_TOKEN = 261,            /* RETURN_TOKEN  */
    VOID_TOKEN = 262,              /* VOID_TOKEN  */
    WHILE_TOKEN = 263,             /* WHILE_TOKEN  */
    PLUS_TOKEN = 264,              /* PLUS_TOKEN  */
    MINUS_TOKEN = 265,             /* MINUS_TOKEN  */
    MULTIPLY_TOKEN = 266,          /* MULTIPLY_TOKEN  */
    DIVIDE_TOKEN = 267,            /* DIVIDE_TOKEN  */
    LT_TOKEN = 268,                /* LT_TOKEN  */
    LTE_TOKEN = 269,               /* LTE_TOKEN  */
    GT_TOKEN = 270,                /* GT_TOKEN  */
    GTE_TOKEN = 271,               /* GTE_TOKEN  */
    EQ_TOKEN = 272,                /* EQ_TOKEN  */
    NEQ_TOKEN = 273,               /* NEQ_TOKEN  */
    ASSIGN_TOKEN = 274,            /* ASSIGN_TOKEN  */
    SEMICOLON_TOKEN = 275,         /* SEMICOLON_TOKEN  */
    COMMA_TOKEN = 276,             /* COMMA_TOKEN  */
    LPAREN_TOKEN = 277,            /* LPAREN_TOKEN  */
    RPAREN_TOKEN = 278,            /* RPAREN_TOKEN  */
    LBRACKET_TOKEN = 279,          /* LBRACKET_TOKEN  */
    RBRACKET_TOKEN = 280,          /* RBRACKET_TOKEN  */
    LBRACE_TOKEN = 281,            /* LBRACE_TOKEN  */
    RBRACE_TOKEN = 282,            /* RBRACE_TOKEN  */
    ID_TOKEN = 283,                /* ID_TOKEN  */
    NUM_TOKEN = 284,               /* NUM_TOKEN  */
    UNKNOW_TOKEN = 285,            /* UNKNOW_TOKEN  */
    ERROR_TOKEN = 286,             /* ERROR_TOKEN  */
    NULL_TOKEN = 287               /* NULL_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
