/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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


#line 92 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ELSE_TOKEN = 3,                 /* ELSE_TOKEN  */
  YYSYMBOL_IF_TOKEN = 4,                   /* IF_TOKEN  */
  YYSYMBOL_INT_TOKEN = 5,                  /* INT_TOKEN  */
  YYSYMBOL_RETURN_TOKEN = 6,               /* RETURN_TOKEN  */
  YYSYMBOL_VOID_TOKEN = 7,                 /* VOID_TOKEN  */
  YYSYMBOL_WHILE_TOKEN = 8,                /* WHILE_TOKEN  */
  YYSYMBOL_PLUS_TOKEN = 9,                 /* PLUS_TOKEN  */
  YYSYMBOL_MINUS_TOKEN = 10,               /* MINUS_TOKEN  */
  YYSYMBOL_MULTIPLY_TOKEN = 11,            /* MULTIPLY_TOKEN  */
  YYSYMBOL_DIVIDE_TOKEN = 12,              /* DIVIDE_TOKEN  */
  YYSYMBOL_LT_TOKEN = 13,                  /* LT_TOKEN  */
  YYSYMBOL_LTE_TOKEN = 14,                 /* LTE_TOKEN  */
  YYSYMBOL_GT_TOKEN = 15,                  /* GT_TOKEN  */
  YYSYMBOL_GTE_TOKEN = 16,                 /* GTE_TOKEN  */
  YYSYMBOL_EQ_TOKEN = 17,                  /* EQ_TOKEN  */
  YYSYMBOL_NEQ_TOKEN = 18,                 /* NEQ_TOKEN  */
  YYSYMBOL_ASSIGN_TOKEN = 19,              /* ASSIGN_TOKEN  */
  YYSYMBOL_SEMICOLON_TOKEN = 20,           /* SEMICOLON_TOKEN  */
  YYSYMBOL_COMMA_TOKEN = 21,               /* COMMA_TOKEN  */
  YYSYMBOL_LPAREN_TOKEN = 22,              /* LPAREN_TOKEN  */
  YYSYMBOL_RPAREN_TOKEN = 23,              /* RPAREN_TOKEN  */
  YYSYMBOL_LBRACKET_TOKEN = 24,            /* LBRACKET_TOKEN  */
  YYSYMBOL_RBRACKET_TOKEN = 25,            /* RBRACKET_TOKEN  */
  YYSYMBOL_LBRACE_TOKEN = 26,              /* LBRACE_TOKEN  */
  YYSYMBOL_RBRACE_TOKEN = 27,              /* RBRACE_TOKEN  */
  YYSYMBOL_ID_TOKEN = 28,                  /* ID_TOKEN  */
  YYSYMBOL_NUM_TOKEN = 29,                 /* NUM_TOKEN  */
  YYSYMBOL_UNKNOW_TOKEN = 30,              /* UNKNOW_TOKEN  */
  YYSYMBOL_ERROR_TOKEN = 31,               /* ERROR_TOKEN  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_decl_list = 34,                 /* decl_list  */
  YYSYMBOL_declaration = 35,               /* declaration  */
  YYSYMBOL_var_declaration = 36,           /* var_declaration  */
  YYSYMBOL_type_specifier = 37,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 38,           /* fun_declaration  */
  YYSYMBOL_params = 39,                    /* params  */
  YYSYMBOL_param_list = 40,                /* param_list  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_compound_decl = 42,             /* compound_decl  */
  YYSYMBOL_local_declarations = 43,        /* local_declarations  */
  YYSYMBOL_statement_list = 44,            /* statement_list  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_expression_decl = 46,           /* expression_decl  */
  YYSYMBOL_selection_decl = 47,            /* selection_decl  */
  YYSYMBOL_iteration_decl = 48,            /* iteration_decl  */
  YYSYMBOL_return_decl = 49,               /* return_decl  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simple_expression = 52,         /* simple_expression  */
  YYSYMBOL_relational = 53,                /* relational  */
  YYSYMBOL_sum_expression = 54,            /* sum_expression  */
  YYSYMBOL_sum = 55,                       /* sum  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_mult = 57,                      /* mult  */
  YYSYMBOL_factor = 58,                    /* factor  */
  YYSYMBOL_activation = 59,                /* activation  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_arg_list = 61                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   98

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    34,    34,    41,    46,    53,    58,    65,    70,    77,
      82,    89,    96,   101,   108,   113,   120,   125,   132,   139,
     145,   151,   157,   163,   168,   173,   178,   183,   190,   195,
     202,   207,   222,   236,   246,   259,   271,   278,   288,   301,
     308,   315,   325,   335,   345,   355,   365,   377,   384,   391,
     401,   413,   420,   427,   437,   449,   454,   460,   466,   480,
     495,   501,   507,   522
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ELSE_TOKEN",
  "IF_TOKEN", "INT_TOKEN", "RETURN_TOKEN", "VOID_TOKEN", "WHILE_TOKEN",
  "PLUS_TOKEN", "MINUS_TOKEN", "MULTIPLY_TOKEN", "DIVIDE_TOKEN",
  "LT_TOKEN", "LTE_TOKEN", "GT_TOKEN", "GTE_TOKEN", "EQ_TOKEN",
  "NEQ_TOKEN", "ASSIGN_TOKEN", "SEMICOLON_TOKEN", "COMMA_TOKEN",
  "LPAREN_TOKEN", "RPAREN_TOKEN", "LBRACKET_TOKEN", "RBRACKET_TOKEN",
  "LBRACE_TOKEN", "RBRACE_TOKEN", "ID_TOKEN", "NUM_TOKEN", "UNKNOW_TOKEN",
  "ERROR_TOKEN", "$accept", "program", "decl_list", "declaration",
  "var_declaration", "type_specifier", "fun_declaration", "params",
  "param_list", "param", "compound_decl", "local_declarations",
  "statement_list", "statement", "expression_decl", "selection_decl",
  "iteration_decl", "return_decl", "expression", "var",
  "simple_expression", "relational", "sum_expression", "sum", "term",
  "mult", "factor", "activation", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      37,   -77,   -77,    21,    37,   -77,   -77,     3,   -77,   -77,
     -77,    28,   -77,    58,    14,    31,    23,    41,    49,   -77,
      46,    48,    47,    37,    54,    50,   -77,   -77,   -77,   -77,
     -77,    37,   -77,    51,     7,    25,    56,    18,    60,   -77,
     -10,   -77,     8,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
      57,    61,   -77,    -8,    55,   -77,   -77,   -10,   -77,    63,
     -10,    53,   -10,   -10,   -77,   -10,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -10,   -10,   -77,   -77,   -10,    62,
     -77,    64,   -77,   -77,    65,    68,    66,   -77,   -77,    59,
      55,   -77,    33,    33,   -77,   -10,   -77,    78,   -77,   -77,
      33,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,     0,     0,    10,     0,     0,    12,    15,
       0,    16,     0,     0,     0,     0,    20,    11,    14,     8,
      17,    22,    19,     0,     0,     0,     0,     0,     0,    29,
       0,    18,    37,    58,    24,    21,    23,    25,    26,    27,
       0,    56,    36,    40,    48,    52,    57,     0,    33,     0,
       0,     0,    61,     0,    28,     0,    49,    50,    41,    42,
      43,    44,    45,    46,     0,     0,    53,    54,     0,     0,
      34,     0,    55,    63,     0,    60,     0,    35,    56,    39,
      47,    51,     0,     0,    59,     0,    38,    30,    32,    62,
       0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,    80,    67,    -9,   -77,   -77,   -77,    69,
      71,   -77,   -77,   -76,   -77,   -77,   -77,   -77,   -37,   -18,
     -77,   -77,    12,   -77,    15,   -77,    16,   -77,   -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      44,    31,    34,    45,    46,    47,    48,    49,    50,    51,
      52,    74,    53,    75,    54,    78,    55,    56,    84,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    66,    67,    61,    16,    68,    69,    70,    71,    72,
      73,    36,    40,    37,    16,    38,    97,    98,    42,    43,
      79,     9,    33,    81,   101,    83,    86,    39,    87,    40,
      62,    11,    63,    26,    41,    42,    43,    36,    58,    37,
      40,    38,     1,    20,     2,    12,    42,    43,    12,    14,
      13,    21,    14,    39,   -13,    40,    88,    88,    99,    26,
      88,    42,    43,     1,    22,    15,    76,    77,    66,    67,
      23,    24,    25,    26,    29,    30,    82,    64,    57,    35,
      65,   100,    60,    80,    10,    92,    89,    93,    94,    95,
      90,    96,    28,    27,    91,     0,     0,     0,    32
};

static const yytype_int8 yycheck[] =
{
      37,     9,    10,    40,    13,    13,    14,    15,    16,    17,
      18,     4,    22,     6,    23,     8,    92,    93,    28,    29,
      57,     0,    31,    60,   100,    62,    63,    20,    65,    22,
      22,    28,    24,    26,    27,    28,    29,     4,    20,     6,
      22,     8,     5,    29,     7,    20,    28,    29,    20,    24,
      22,    28,    24,    20,    23,    22,    74,    75,    95,    26,
      78,    28,    29,     5,    23,     7,    11,    12,     9,    10,
      21,    25,    24,    26,    20,    25,    23,    20,    22,    28,
      19,     3,    22,    20,     4,    23,    74,    23,    23,    21,
      75,    25,    23,    22,    78,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    33,    34,    35,    36,    37,    38,     0,
      35,    28,    20,    22,    24,     7,    37,    39,    40,    41,
      29,    28,    23,    21,    25,    24,    26,    42,    41,    20,
      25,    43,    36,    37,    44,    28,     4,     6,     8,    20,
      22,    27,    28,    29,    42,    45,    46,    47,    48,    49,
      50,    51,    52,    54,    56,    58,    59,    22,    20,    50,
      22,    50,    22,    24,    20,    19,     9,    10,    13,    14,
      15,    16,    17,    18,    53,    55,    11,    12,    57,    50,
      20,    50,    23,    50,    60,    61,    50,    50,    51,    54,
      56,    58,    23,    23,    23,    21,    25,    45,    45,    50,
       3,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    43,
      43,    44,    44,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    58,    58,    59,
      60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: decl_list  */
#line 35 "parser.y"
    {
        printf("reduced: program -> decl_list\n");
        //global_ast_tree = $1;
    }
#line 1214 "parser.c"
    break;

  case 3: /* decl_list: decl_list declaration  */
#line 42 "parser.y"
    {
        //printf("reduced: decl_list -> decl_list declaration\n");

    }
#line 1223 "parser.c"
    break;

  case 4: /* decl_list: declaration  */
#line 47 "parser.y"
    {
        //printf("reduced: decl_list -> declaration\n");

    }
#line 1232 "parser.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 54 "parser.y"
    {
        //printf("reduced: declaration -> var_declaration\n");

    }
#line 1241 "parser.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 59 "parser.y"
    {
        //printf("reduced: declaration -> fun_declaration\n");

    }
#line 1250 "parser.c"
    break;

  case 7: /* var_declaration: type_specifier ID_TOKEN SEMICOLON_TOKEN  */
#line 66 "parser.y"
    {
        //printf("reduced: var_declaration -> type_specifier ID_TOKEN SEMICOLON_TOKEN\n");
    
    }
#line 1259 "parser.c"
    break;

  case 8: /* var_declaration: type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN  */
#line 71 "parser.y"
    {
        //printf("reduced: var_declaration -> type_specifier ID_TOKEN LBRACKET_TOKEN NUM_TOKEN RBRACKET_TOKEN SEMICOLON_TOKEN\n");
    
    }
#line 1268 "parser.c"
    break;

  case 9: /* type_specifier: INT_TOKEN  */
#line 78 "parser.y"
    {
        //printf("reduced: type_specifier -> INT_TOKEN\n");

    }
#line 1277 "parser.c"
    break;

  case 10: /* type_specifier: VOID_TOKEN  */
#line 83 "parser.y"
    {
        //printf("reduced: type_specifier -> VOID_TOKEN\n");
    
    }
#line 1286 "parser.c"
    break;

  case 11: /* fun_declaration: type_specifier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl  */
#line 90 "parser.y"
    {
        //printf("reduced: fun_declaration -> type_specifier ID_TOKEN LPAREN_TOKEN params RPAREN_TOKEN compound_decl\n");
    
    }
#line 1295 "parser.c"
    break;

  case 12: /* params: param_list  */
#line 97 "parser.y"
    {
        //printf("reduced: params -> param_list\n");
    
    }
#line 1304 "parser.c"
    break;

  case 13: /* params: VOID_TOKEN  */
#line 102 "parser.y"
    {
        //printf("reduced: params -> VOID_TOKEN\n");
    
    }
#line 1313 "parser.c"
    break;

  case 14: /* param_list: param_list COMMA_TOKEN param  */
#line 109 "parser.y"
    {
        //printf("reduced: param_list -> param_list COMMA_TOKEN param\n");
    
    }
#line 1322 "parser.c"
    break;

  case 15: /* param_list: param  */
#line 114 "parser.y"
    {
        //printf("reduced: param_list -> param\n");
    
    }
#line 1331 "parser.c"
    break;

  case 16: /* param: type_specifier ID_TOKEN  */
#line 121 "parser.y"
    {
        //printf("reduced: param -> type_specifier ID_TOKEN\n");
    
    }
#line 1340 "parser.c"
    break;

  case 17: /* param: type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN  */
#line 126 "parser.y"
    {
        //printf("reduced: param -> type_specifier ID_TOKEN LBRACKET_TOKEN RBRACKET_TOKEN\n");
    
    }
#line 1349 "parser.c"
    break;

  case 18: /* compound_decl: LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN  */
#line 133 "parser.y"
    {
        //printf("reduced: compound_decl -> LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN\n");
    
    }
#line 1358 "parser.c"
    break;

  case 19: /* local_declarations: local_declarations var_declaration  */
#line 140 "parser.y"
    {
        //printf("reduced: local_declarations -> local_declarations var_declaration\n");
    
    }
#line 1367 "parser.c"
    break;

  case 20: /* local_declarations: %empty  */
#line 145 "parser.y"
    {
        //printf("reduced: local_declarations -> vazio\n");
    
    }
#line 1376 "parser.c"
    break;

  case 21: /* statement_list: statement_list statement  */
#line 152 "parser.y"
    {
        //printf("reduced: statement_list -> statement_list statement\n");
    
    }
#line 1385 "parser.c"
    break;

  case 22: /* statement_list: %empty  */
#line 157 "parser.y"
    {
        //printf("reduced: statement_list -> vazio\n");
    
    }
#line 1394 "parser.c"
    break;

  case 23: /* statement: expression_decl  */
#line 164 "parser.y"
    {
        //printf("reduced: statement -> expression_decl\n");
    
    }
#line 1403 "parser.c"
    break;

  case 24: /* statement: compound_decl  */
#line 169 "parser.y"
    {
        //printf("reduced: statement -> compound_decl\n");
    
    }
#line 1412 "parser.c"
    break;

  case 25: /* statement: selection_decl  */
#line 174 "parser.y"
    {
        //printf("reduced: statement -> selection_decl\n");
    
    }
#line 1421 "parser.c"
    break;

  case 26: /* statement: iteration_decl  */
#line 179 "parser.y"
    {
        //printf("reduced: statement -> iteration_decl\n");
    
    }
#line 1430 "parser.c"
    break;

  case 27: /* statement: return_decl  */
#line 184 "parser.y"
    {
        //printf("reduced: statement -> return_decl\n");
    
    }
#line 1439 "parser.c"
    break;

  case 28: /* expression_decl: expression SEMICOLON_TOKEN  */
#line 191 "parser.y"
    {
        //printf("reduced: expression_decl -> expression SEMICOLON_TOKEN\n");
    
    }
#line 1448 "parser.c"
    break;

  case 29: /* expression_decl: SEMICOLON_TOKEN  */
#line 196 "parser.y"
    {
        //printf("reduced: expression_decl -> SEMICOLON_TOKEN\n");
    
    }
#line 1457 "parser.c"
    break;

  case 30: /* selection_decl: IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement  */
#line 203 "parser.y"
    {
        //printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
    
    }
#line 1466 "parser.c"
    break;

  case 31: /* selection_decl: IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement  */
#line 208 "parser.y"
    {
        //printf("reduced: selection_decl -> IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement\n");
        ast_node_t* if_node = new_ast_node(STATEMENT_NODE, global_line_number, global_lexeme, IF_STMT, NOT_EXP, NO_TYPE);
        print_ast(if_node);
        printf("if lexeme: %s line number: %d\n", if_node->lexeme, if_node->lineno);
        //add_child(if_node, $3);
        //add_child(if_node, $5);
        //add_child(if_node, $7);
        //$$ = if_node;

        free_ast(if_node);
    }
#line 1483 "parser.c"
    break;

  case 32: /* iteration_decl: WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement  */
#line 223 "parser.y"
    {
        //printf("reduced: iteration_decl -> WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement\n");
        ast_node_t* while_node = new_ast_node(STATEMENT_NODE, global_line_number, global_lexeme, WHILE_STMT, NOT_EXP, NO_TYPE);
        print_ast(while_node);
        printf("while lexeme: %s line number: %d\n", while_node->lexeme, while_node->lineno);
        //add_child(while_node, $3);
        //add_child(while_node, $5);
        //$$ = while_node;

        free_ast(while_node);
    }
#line 1499 "parser.c"
    break;

  case 33: /* return_decl: RETURN_TOKEN SEMICOLON_TOKEN  */
#line 237 "parser.y"
    {
        //printf("reduced: return_decl -> RETURN_TOKEN SEMICOLON_TOKEN\n");
        ast_node_t* return_node = new_ast_node(STATEMENT_NODE, global_line_number, global_lexeme, RETURN_STMT, NOT_EXP, NO_TYPE);
        print_ast(return_node);
        printf("return lexeme: %s line number: %d\n", return_node->lexeme, return_node->lineno);
        //$$ = return_node;

        free_ast(return_node);
    }
#line 1513 "parser.c"
    break;

  case 34: /* return_decl: RETURN_TOKEN expression SEMICOLON_TOKEN  */
#line 247 "parser.y"
    {
        //printf("reduced: return_decl -> RETURN_TOKEN expression SEMICOLON_TOKEN\n");
        ast_node_t* return_node = new_ast_node(STATEMENT_NODE, global_line_number, global_lexeme, RETURN_STMT, NOT_EXP, NO_TYPE);
        print_ast(return_node);
        printf("return lexeme: %s line number: %d\n", return_node->lexeme, return_node->lineno);
        //add_child(return_node, $2);
        //$$ = return_node;

        free_ast(return_node);
    }
#line 1528 "parser.c"
    break;

  case 35: /* expression: var ASSIGN_TOKEN expression  */
#line 260 "parser.y"
    {
        //printf("reduced: expression -> var ASSIGN_TOKEN expression\n");
        ast_node_t* assign_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(assign_node);
        printf("assign lexeme: %s line number: %d\n", assign_node->lexeme, assign_node->lineno);
        //add_child(assign_node, $1);
        //add_child(assign_node, $3);
        //$$ = assign_node;

        free_ast(assign_node);
    }
#line 1544 "parser.c"
    break;

  case 36: /* expression: simple_expression  */
#line 272 "parser.y"
    {
        //printf("reduced: expression -> simple_expression\n");
        yyval = yyvsp[0];
    }
#line 1553 "parser.c"
    break;

  case 37: /* var: ID_TOKEN  */
#line 279 "parser.y"
    {
        //printf("reduced: var -> ID_TOKEN\n");
        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        print_ast(id_node);
        printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        //$$ = id_node;

        free_ast(id_node);
    }
#line 1567 "parser.c"
    break;

  case 38: /* var: ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN  */
#line 289 "parser.y"
    {
        //printf("reduced: var -> ID_TOKEN LBRACKET_TOKEN expression RBRACKET_TOKEN\n");
        ast_node_t* id_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, ID_EXP, NO_TYPE);
        print_ast(id_node);
        printf("id lexeme: %s line number: %d\n", id_node->lexeme, id_node->lineno);
        //add_child(id_node, $3);
        //$$ = id_node;

        free_ast(id_node);
    }
#line 1582 "parser.c"
    break;

  case 39: /* simple_expression: sum_expression relational sum_expression  */
#line 302 "parser.y"
    {
        //printf("reduced: simple_expression -> sum_expression relational sum_expression\n");
        add_child(yyvsp[-1], yyvsp[-2]);
        add_child(yyvsp[-1], yyvsp[0]);
        yyval = yyvsp[-1];
    }
#line 1593 "parser.c"
    break;

  case 40: /* simple_expression: sum_expression  */
#line 309 "parser.y"
    {
        //printf("reduced: simple_expression -> sum_expression\n");
        yyval = yyvsp[0];
    }
#line 1602 "parser.c"
    break;

  case 41: /* relational: LT_TOKEN  */
#line 316 "parser.y"
    {
        //printf("reduced: relational -> LT_TOKEN\n");
        ast_node_t* lt_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(lt_node);
        printf("lt lexeme: %s line number: %d\n", lt_node->lexeme, lt_node->lineno);
        //$$ = lt_node;

        free_ast(lt_node);
    }
#line 1616 "parser.c"
    break;

  case 42: /* relational: LTE_TOKEN  */
#line 326 "parser.y"
    {
        //printf("reduced: relational -> LTE_TOKEN\n");
        ast_node_t* lte_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(lte_node);
        printf("lte lexeme: %s line number: %d\n", lte_node->lexeme, lte_node->lineno);
        //$$ = lte_node;

        free_ast(lte_node);
    }
#line 1630 "parser.c"
    break;

  case 43: /* relational: GT_TOKEN  */
#line 336 "parser.y"
    {
        //printf("reduced: relational -> GT_TOKEN\n");
        ast_node_t* gt_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(gt_node);
        printf("gt lexeme: %s line number: %d\n", gt_node->lexeme, gt_node->lineno);
        //$$ = gt_node;

        free_ast(gt_node);
    }
#line 1644 "parser.c"
    break;

  case 44: /* relational: GTE_TOKEN  */
#line 346 "parser.y"
    {
        //printf("reduced: relational -> GTE_TOKEN\n");
        ast_node_t* gte_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(gte_node);
        printf("gte lexeme: %s line number: %d\n", gte_node->lexeme, gte_node->lineno);
        //$$ = gte_node;

        free_ast(gte_node);
    }
#line 1658 "parser.c"
    break;

  case 45: /* relational: EQ_TOKEN  */
#line 356 "parser.y"
    {
        //printf("reduced: relational -> EQ_TOKEN\n");
        ast_node_t* eq_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(eq_node);
        printf("eq lexeme: %s line number: %d\n", eq_node->lexeme, eq_node->lineno);
        //$$ = eq_node;

        free_ast(eq_node);
    }
#line 1672 "parser.c"
    break;

  case 46: /* relational: NEQ_TOKEN  */
#line 366 "parser.y"
    {
        //printf("reduced: relational -> NEQ_TOKEN\n");
        ast_node_t* neq_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(neq_node);
        printf("neq lexeme: %s line number: %d\n", neq_node->lexeme, neq_node->lineno);
        //$$ = neq_node;

        free_ast(neq_node);
    }
#line 1686 "parser.c"
    break;

  case 47: /* sum_expression: sum_expression sum term  */
#line 378 "parser.y"
    {
        //printf("reduced: sum_expression -> sum_expression sum term\n");
        add_child(yyvsp[-1], yyvsp[-2]);
        add_child(yyvsp[-1], yyvsp[0]);
        yyval = yyvsp[-1];
    }
#line 1697 "parser.c"
    break;

  case 48: /* sum_expression: term  */
#line 385 "parser.y"
    {
        //printf("reduced: sum_expression -> term\n");
        yyval = yyvsp[0];
    }
#line 1706 "parser.c"
    break;

  case 49: /* sum: PLUS_TOKEN  */
#line 392 "parser.y"
    {
        //printf("reduced: sum -> PLUS_TOKEN\n");
        ast_node_t* plus_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(plus_node);
        printf("plus lexeme: %s line number: %d\n", plus_node->lexeme, plus_node->lineno);
        //$$ = plus_node;

        free_ast(plus_node);
    }
#line 1720 "parser.c"
    break;

  case 50: /* sum: MINUS_TOKEN  */
#line 402 "parser.y"
    {
        //printf("reduced: sum -> MINUS_TOKEN\n");
        ast_node_t* minus_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(minus_node);
        printf("minus lexeme: %s line number: %d\n", minus_node->lexeme, minus_node->lineno);
        //$$ = minus_node;

        free_ast(minus_node);
    }
#line 1734 "parser.c"
    break;

  case 51: /* term: term mult factor  */
#line 414 "parser.y"
    {
        //printf("reduced: term -> term mult factor\n");
        add_child(yyvsp[-1], yyvsp[-2]);
        add_child(yyvsp[-1], yyvsp[0]);
        yyval = yyvsp[-1];
    }
#line 1745 "parser.c"
    break;

  case 52: /* term: factor  */
#line 421 "parser.y"
    {
        //printf("reduced: term -> factor\n");
        yyval = yyvsp[0];
    }
#line 1754 "parser.c"
    break;

  case 53: /* mult: MULTIPLY_TOKEN  */
#line 428 "parser.y"
    {
        //printf("reduced: mult -> MULTIPLY_TOKEN\n");
        ast_node_t* multiply_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(multiply_node);
        printf("multiply lexeme: %s line number: %d\n", multiply_node->lexeme, multiply_node->lineno);
        //$$ = multiply_node;

        free_ast(multiply_node);
    }
#line 1768 "parser.c"
    break;

  case 54: /* mult: DIVIDE_TOKEN  */
#line 438 "parser.y"
    {
        //printf("reduced: mult -> DIVIDE_TOKEN\n");
        ast_node_t* divide_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, OP_EXP, NO_TYPE);
        print_ast(divide_node);
        printf("divide lexeme: %s line number: %d\n", divide_node->lexeme, divide_node->lineno);
        //$$ = divide_node;

        free_ast(divide_node);
    }
#line 1782 "parser.c"
    break;

  case 55: /* factor: LPAREN_TOKEN expression RPAREN_TOKEN  */
#line 450 "parser.y"
    {
        //printf("reduced: factor -> LPAREN_TOKEN expression RPAREN_TOKEN\n");
        yyval = yyvsp[-1];
    }
#line 1791 "parser.c"
    break;

  case 56: /* factor: var  */
#line 455 "parser.y"
    {
        //printf("reduced: factor -> var\n");
        yyval = yyvsp[0];
    
    }
#line 1801 "parser.c"
    break;

  case 57: /* factor: activation  */
#line 461 "parser.y"
    {
        //rintf("reduced: factor -> activation\n");
        yyval = yyvsp[0];
    
    }
#line 1811 "parser.c"
    break;

  case 58: /* factor: NUM_TOKEN  */
#line 467 "parser.y"
    {
        //printf("reduced: factor -> NUM_TOKEN\n");
        //create NUM node
        ast_node_t* num_node = new_ast_node(EXPRESSION_NODE, global_line_number, global_lexeme, NOT_STMT, CONST_EXP, NO_TYPE);
        print_ast(num_node);
        printf("num lexeme: %s line number: %d\n", num_node->lexeme, num_node->lineno);

        //$$ = num_node;
        
        free_ast(num_node);
    }
#line 1827 "parser.c"
    break;

  case 59: /* activation: ID_TOKEN LPAREN_TOKEN args RPAREN_TOKEN  */
#line 481 "parser.y"
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
#line 1844 "parser.c"
    break;

  case 60: /* args: arg_list  */
#line 496 "parser.y"
    {
        //printf("reduced: args -> arg_list\n");
        yyval = yyvsp[0];
    }
#line 1853 "parser.c"
    break;

  case 61: /* args: %empty  */
#line 501 "parser.y"
    {
        //printf("reduced: args -> vazio\n");
        yyval = NULL;
    }
#line 1862 "parser.c"
    break;

  case 62: /* arg_list: arg_list COMMA_TOKEN expression  */
#line 508 "parser.y"
    {
        //printf("reduced: arg_list -> arg_list COMMA_TOKEN expression\n");
        // arg_list have expression as sibling
        if (yyvsp[-2] != NULL) 
        {
            add_sibling(yyvsp[-2], yyvsp[0]);
            yyval = yyvsp[-2];
        }
        else 
        {
            yyval = yyvsp[0];
        }

    }
#line 1881 "parser.c"
    break;

  case 63: /* arg_list: expression  */
#line 523 "parser.y"
    {
        //printf("reduced: arg_list -> expression\n");
        yyval = yyvsp[0];

        // node_kind_t kind = EXPRESSION_NODE;
        // ast_node_t* node = create_default_node(kind);
        // printf("\n\n\ncreated node: %s\n\n\n", node->lexeme);
        // add_child(global_ast_tree, node);
        // add_child(node, $1);
        // print_ast(global_ast_tree);
    }
#line 1897 "parser.c"
    break;


#line 1901 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 536 "parser.y"


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
