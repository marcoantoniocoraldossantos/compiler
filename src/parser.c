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

#line 91 "parser.c"

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
  YYSYMBOL_params_opt = 39,                /* params_opt  */
  YYSYMBOL_params = 40,                    /* params  */
  YYSYMBOL_param_list = 41,                /* param_list  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_compound_decl = 43,             /* compound_decl  */
  YYSYMBOL_local_declarations = 44,        /* local_declarations  */
  YYSYMBOL_statement_list = 45,            /* statement_list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_expression_decl = 47,           /* expression_decl  */
  YYSYMBOL_selection_decl = 48,            /* selection_decl  */
  YYSYMBOL_iteration_decl = 49,            /* iteration_decl  */
  YYSYMBOL_return_decl = 50,               /* return_decl  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_var = 52,                       /* var  */
  YYSYMBOL_simple_expression = 53,         /* simple_expression  */
  YYSYMBOL_relational = 54,                /* relational  */
  YYSYMBOL_sum_expression = 55,            /* sum_expression  */
  YYSYMBOL_sum = 56,                       /* sum  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_mult = 58,                      /* mult  */
  YYSYMBOL_factor = 59,                    /* factor  */
  YYSYMBOL_activation = 60,                /* activation  */
  YYSYMBOL_args = 61,                      /* args  */
  YYSYMBOL_arg_list = 62,                  /* arg_list  */
  YYSYMBOL_id = 63,                        /* id  */
  YYSYMBOL_num = 64                        /* num  */
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
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

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
       0,    33,    33,    39,    51,    57,    61,    67,    76,    88,
     101,   116,   128,   133,   138,   142,   153,   165,   171,   179,
     189,   204,   217,   222,   235,   240,   244,   248,   252,   256,
     262,   266,   272,   291,   311,   331,   346,   365,   383,   389,
     395,   405,   414,   420,   433,   446,   459,   472,   486,   501,
     510,   516,   529,   544,   554,   560,   573,   588,   592,   596,
     600,   608,   618,   623,   628,   640,   646,   674
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
  "var_declaration", "type_specifier", "fun_declaration", "params_opt",
  "params", "param_list", "param", "compound_decl", "local_declarations",
  "statement_list", "statement", "expression_decl", "selection_decl",
  "iteration_decl", "return_decl", "expression", "var",
  "simple_expression", "relational", "sum_expression", "sum", "term",
  "mult", "factor", "activation", "args", "arg_list", "id", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,   -88,   -88,    33,     0,   -88,   -88,    11,   -88,   -88,
     -88,   -88,    22,   -88,    27,    24,    28,    11,    34,   -88,
      41,   -88,   -88,    35,    40,    37,     0,    51,    47,   -88,
     -88,   -88,   -88,   -88,     0,   -88,    11,     9,    30,    44,
     -10,    57,   -88,    -1,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,    61,    63,   -88,    60,    13,   -88,   -88,   -18,   -88,
      -1,   -88,    64,    -1,    62,   -88,    -1,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,    -1,    -1,   -88,   -88,    -1,
      -1,    -1,    65,   -88,    66,   -88,   -88,   -88,    46,    13,
     -88,   -88,    67,    59,    58,    39,    39,   -88,    -1,   -88,
      83,   -88,   -88,    39,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    66,     0,     7,    13,     0,    10,     0,     0,    12,
      14,    17,    67,     0,    18,     0,     0,     0,     0,    22,
      11,    16,     8,    19,    24,    21,     0,     0,     0,     0,
       0,     0,    31,     0,    20,    26,    23,    25,    27,    28,
      29,     0,    58,    38,    42,    50,    54,    59,    39,    60,
       0,    35,     0,     0,     0,    30,     0,    51,    52,    43,
      44,    45,    46,    47,    48,     0,     0,    55,    56,     0,
      63,     0,     0,    36,     0,    57,    37,    58,    41,    49,
      53,    65,     0,    62,     0,     0,     0,    61,     0,    40,
      32,    34,    64,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,    87,    53,   -12,   -88,   -88,   -88,   -88,
      68,    70,   -88,   -88,   -87,   -88,   -88,   -88,   -88,   -40,
     -27,   -88,   -88,    17,   -88,    20,   -88,    14,   -88,   -88,
     -88,    -6,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    18,    19,    20,
      21,    45,    34,    37,    46,    47,    48,    49,    50,    51,
      52,    53,    75,    54,    76,    55,    79,    56,    57,    92,
      93,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    12,    17,    64,    80,     1,    81,     2,   100,   101,
      61,    24,    43,    39,    17,    40,   104,    41,    11,    22,
      82,    43,    36,    84,    77,    78,    86,    11,    22,    42,
      38,    43,     1,     9,    16,    29,    44,    11,    22,    11,
      91,    94,    13,    39,    14,    40,    15,    41,    87,    87,
      13,   -15,    87,    22,    15,    67,    68,    25,   102,    42,
      27,    43,    26,    29,    28,    29,    60,    11,    22,    67,
      68,    32,    33,    69,    70,    71,    72,    73,    74,    63,
      98,    65,    66,    99,    83,    85,   103,    35,    95,    96,
      97,    10,    88,    90,    31,    30,    89,    23
};

static const yytype_int8 yycheck[] =
{
      40,     7,    14,    43,    22,     5,    24,     7,    95,    96,
      20,    17,    22,     4,    26,     6,   103,     8,    28,    29,
      60,    22,    34,    63,    11,    12,    66,    28,    29,    20,
      36,    22,     5,     0,     7,    26,    27,    28,    29,    28,
      80,    81,    20,     4,    22,     6,    24,     8,    75,    76,
      20,    23,    79,    29,    24,     9,    10,    23,    98,    20,
      25,    22,    21,    26,    24,    26,    22,    28,    29,     9,
      10,    20,    25,    13,    14,    15,    16,    17,    18,    22,
      21,    20,    19,    25,    20,    23,     3,    34,    23,    23,
      23,     4,    75,    79,    26,    25,    76,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    33,    34,    35,    36,    37,    38,     0,
      35,    28,    63,    20,    22,    24,     7,    37,    39,    40,
      41,    42,    29,    64,    63,    23,    21,    25,    24,    26,
      43,    42,    20,    25,    44,    36,    37,    45,    63,     4,
       6,     8,    20,    22,    27,    43,    46,    47,    48,    49,
      50,    51,    52,    53,    55,    57,    59,    60,    63,    64,
      22,    20,    51,    22,    51,    20,    19,     9,    10,    13,
      14,    15,    16,    17,    18,    54,    56,    11,    12,    58,
      22,    24,    51,    20,    51,    23,    51,    52,    55,    57,
      59,    51,    61,    62,    51,    23,    23,    23,    21,    25,
      46,    46,    51,     3,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      43,    44,    44,    45,    45,    46,    46,    46,    46,    46,
      47,    47,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    60,    61,    61,    62,    62,    63,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     0,     1,     1,     3,     1,     2,     4,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       2,     1,     5,     7,     5,     2,     3,     3,     1,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     4,     1,     0,     3,     1,     1,     1
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
#line 34 "parser.y"
    {
        global_ast_tree = yyvsp[0];
    }
#line 1217 "parser.c"
    break;

  case 3: /* decl_list: decl_list declaration  */
#line 40 "parser.y"
    {
        if (yyvsp[-1] != NULL) 
        {
            yyval = yyvsp[-1];
            add_sibling(yyval, yyvsp[0]);
        }
        else 
        {
            yyval = yyvsp[0];
        }
    }
#line 1233 "parser.c"
    break;

  case 4: /* decl_list: declaration  */
#line 52 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1241 "parser.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 58 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1249 "parser.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 62 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1257 "parser.c"
    break;

  case 7: /* var_declaration: type_specifier id SEMICOLON_TOKEN  */
#line 68 "parser.y"
    {
        yyval = yyvsp[-2];
        yyval->extended_type = EXT_VARIABLE_DECL;
        yyval->lineno = global_line_number;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[-1]);
    }
#line 1270 "parser.c"
    break;

  case 8: /* var_declaration: type_specifier id LBRACKET_TOKEN num RBRACKET_TOKEN SEMICOLON_TOKEN  */
#line 77 "parser.y"
    {
        yyval = yyvsp[-5];
        yyval->extended_type = EXT_VECTOR_DECL;
        yyval->lineno = global_line_number;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[-4]);
        add_child(yyval, yyvsp[-2]);
    }
#line 1284 "parser.c"
    break;

  case 9: /* type_specifier: INT_TOKEN  */
#line 89 "parser.y"
    {
        ast_node_t* int_node = new_ast_node(
            EXPRESSION_NODE,    // node_kind
            global_line_number, // lineno
            "int",              // lexeme
            NULL_STMT,          // stmt_kind
            CONST_EXP,          // exp_kind
            INT_TYPE            // exp_type
        );

        yyval = int_node;
    }
#line 1301 "parser.c"
    break;

  case 10: /* type_specifier: VOID_TOKEN  */
#line 102 "parser.y"
    {
        ast_node_t* void_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "void",             
            NULL_STMT,          
            CONST_EXP,          
            VOID_TYPE           
        );

        yyval = void_node;
    }
#line 1318 "parser.c"
    break;

  case 11: /* fun_declaration: type_specifier id LPAREN_TOKEN params_opt RPAREN_TOKEN compound_decl  */
#line 117 "parser.y"
    {
        yyval = yyvsp[-5];        
        yyval->extended_type = EXT_FUNCTION_DECL;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[-2]);
        add_child(yyval, yyvsp[-4]);
        add_child(yyvsp[-4], yyvsp[0]);
    }
#line 1332 "parser.c"
    break;

  case 12: /* params_opt: params  */
#line 129 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1340 "parser.c"
    break;

  case 13: /* params_opt: %empty  */
#line 133 "parser.y"
    {
        yyval = NULL;
    }
#line 1348 "parser.c"
    break;

  case 14: /* params: param_list  */
#line 139 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1356 "parser.c"
    break;

  case 15: /* params: VOID_TOKEN  */
#line 143 "parser.y"
    {
        // Criação de um nó para representar parâmetros vazios
        ast_node_t* void_node = new_ast_node(NULL_NODE, global_line_number, "void", NULL_STMT, NULL_EXP, NULL_TYPE);

        yyval = void_node;
        yyval->extended_type = EXT_VOID_PARAMETER;
        yyval->node_kind = DECLARATION_NODE;
    }
#line 1369 "parser.c"
    break;

  case 16: /* param_list: param_list COMMA_TOKEN param  */
#line 154 "parser.y"
    {
        if (yyvsp[-2] != NULL) 
        {
            yyval = yyvsp[-2];
            add_sibling(yyval, yyvsp[0]);
        }
        else 
        {
            yyval = yyvsp[0];
        }
    }
#line 1385 "parser.c"
    break;

  case 17: /* param_list: param  */
#line 166 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1393 "parser.c"
    break;

  case 18: /* param: type_specifier id  */
#line 172 "parser.y"
    {
        yyval = yyvsp[-1];
        yyval->extended_type = EXT_VARIABLE_PARAMETER;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[0]);
    }
#line 1405 "parser.c"
    break;

  case 19: /* param: type_specifier id LBRACKET_TOKEN RBRACKET_TOKEN  */
#line 180 "parser.y"
    {
        yyval = yyvsp[-3];
        yyval->extended_type = EXT_VECTOR_PARAMETER;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[-2]);
    }
#line 1417 "parser.c"
    break;

  case 20: /* compound_decl: LBRACE_TOKEN local_declarations statement_list RBRACE_TOKEN  */
#line 190 "parser.y"
    {
        if(yyvsp[-2] != NULL) 
        {
            yyval = yyvsp[-2];
            add_sibling(yyval, yyvsp[-1]);
            
        }
        else 
        {
            yyval = yyvsp[-1];
        }
    }
#line 1434 "parser.c"
    break;

  case 21: /* local_declarations: local_declarations var_declaration  */
#line 205 "parser.y"
    {
        if (yyvsp[-1] != NULL) 
        {
            yyval = yyvsp[-1];
            add_sibling(yyval, yyvsp[0]);
        }
        else 
        {
            yyval = yyvsp[0];
        }
    }
#line 1450 "parser.c"
    break;

  case 22: /* local_declarations: %empty  */
#line 217 "parser.y"
    {
        yyval = NULL;
    }
#line 1458 "parser.c"
    break;

  case 23: /* statement_list: statement_list statement  */
#line 223 "parser.y"
    {
        if (yyvsp[-1] != NULL) 
        {
            yyval = yyvsp[-1];
            add_sibling(yyval, yyvsp[0]);
        }
        else 
        {
            yyval = yyvsp[0];
        }
    }
#line 1474 "parser.c"
    break;

  case 24: /* statement_list: %empty  */
#line 235 "parser.y"
    {
        yyval = NULL;
    }
#line 1482 "parser.c"
    break;

  case 25: /* statement: expression_decl  */
#line 241 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1490 "parser.c"
    break;

  case 26: /* statement: compound_decl  */
#line 245 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1498 "parser.c"
    break;

  case 27: /* statement: selection_decl  */
#line 249 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1506 "parser.c"
    break;

  case 28: /* statement: iteration_decl  */
#line 253 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1514 "parser.c"
    break;

  case 29: /* statement: return_decl  */
#line 257 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1522 "parser.c"
    break;

  case 30: /* expression_decl: expression SEMICOLON_TOKEN  */
#line 263 "parser.y"
    {
        yyval = yyvsp[-1];
    }
#line 1530 "parser.c"
    break;

  case 31: /* expression_decl: SEMICOLON_TOKEN  */
#line 267 "parser.y"
    {
        yyval = NULL;
    }
#line 1538 "parser.c"
    break;

  case 32: /* selection_decl: IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement  */
#line 273 "parser.y"
    {
        ast_node_t* if_node = new_ast_node(
            STATEMENT_NODE,      
            global_line_number,  
            "if",                
            IF_STMT,             
            NULL_EXP,            
            NULL_TYPE            
        );
        
        yyval = if_node;

        yyval->extended_type = EXT_IF;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[-2]);     
        add_child(yyval, yyvsp[0]);     
    }
#line 1561 "parser.c"
    break;

  case 33: /* selection_decl: IF_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement ELSE_TOKEN statement  */
#line 292 "parser.y"
    {
        ast_node_t* if_node = new_ast_node(
            STATEMENT_NODE,      
            global_line_number,  
            "if",               
            IF_STMT,            
            NULL_EXP,            
            NULL_TYPE           
        );

        add_child(if_node, yyvsp[-4]); 
        add_child(if_node, yyvsp[-2]); 
        add_child(if_node, yyvsp[0]); 
        yyval = if_node;
        yyval->extended_type = EXT_IF_ELSE;
        yyval->node_kind = DECLARATION_NODE;
    }
#line 1583 "parser.c"
    break;

  case 34: /* iteration_decl: WHILE_TOKEN LPAREN_TOKEN expression RPAREN_TOKEN statement  */
#line 312 "parser.y"
    {
        ast_node_t* while_node = new_ast_node(
            STATEMENT_NODE,     
            global_line_number, 
            "while",            
            WHILE_STMT,       
            NULL_EXP,          
            NULL_TYPE         
        );

        yyval = while_node;
        yyval->extended_type = EXT_WHILE;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[-2]);      
        add_child(yyval, yyvsp[0]);     
    }
#line 1605 "parser.c"
    break;

  case 35: /* return_decl: RETURN_TOKEN SEMICOLON_TOKEN  */
#line 332 "parser.y"
    {
        ast_node_t* return_node = new_ast_node(
            STATEMENT_NODE,      
            global_line_number,  
            "return",            
            RETURN_STMT,         
            NULL_EXP,           
            NULL_TYPE           
        );
    
        yyval = return_node;
        yyval->extended_type = EXT_RETURN_VOID;
        yyval->node_kind = DECLARATION_NODE;
    }
#line 1624 "parser.c"
    break;

  case 36: /* return_decl: RETURN_TOKEN expression SEMICOLON_TOKEN  */
#line 347 "parser.y"
    {
        ast_node_t* return_node = new_ast_node(
            STATEMENT_NODE,     
            global_line_number,  
            "return",            
            RETURN_STMT,        
            NULL_EXP,            
            NULL_TYPE           
        );

        yyval = return_node;
        yyval->extended_type = EXT_RETURN_INT;
        yyval->node_kind = DECLARATION_NODE;

        add_child(yyval, yyvsp[-1]);     
    }
#line 1645 "parser.c"
    break;

  case 37: /* expression: var ASSIGN_TOKEN expression  */
#line 366 "parser.y"
    {
        ast_node_t* assign_node = new_ast_node(
            EXPRESSION_NODE,       
            global_line_number,   
            "==",                  
            NULL_STMT,             
            ATTR_EXP,              
            NULL_TYPE             
        );

        yyval = assign_node;
        yyval->extended_type = EXT_OPERATOR;
        yyval->node_kind = EXPRESSION_NODE;

        add_child(yyval, yyvsp[-2]);
        add_child(yyval, yyvsp[0]);
    }
#line 1667 "parser.c"
    break;

  case 38: /* expression: simple_expression  */
#line 384 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1675 "parser.c"
    break;

  case 39: /* var: id  */
#line 390 "parser.y"
    {
        yyval = yyvsp[0];
        yyval->extended_type = EXT_IDENTIFIER;
        yyval->node_kind = EXPRESSION_NODE;
    }
#line 1685 "parser.c"
    break;

  case 40: /* var: id LBRACKET_TOKEN expression RBRACKET_TOKEN  */
#line 396 "parser.y"
    {
        yyval = yyvsp[-3];
        yyval->extended_type = EXT_VECTOR;
        yyval->node_kind = EXPRESSION_NODE;

        add_child(yyval, yyvsp[-1]);
    }
#line 1697 "parser.c"
    break;

  case 41: /* simple_expression: sum_expression relational sum_expression  */
#line 406 "parser.y"
    {
        yyval = yyvsp[-1];
        yyval->extended_type = EXT_RELATIONAL;
        yyval->node_kind = EXPRESSION_NODE;

        add_child(yyval, yyvsp[-2]);
        add_child(yyval, yyvsp[0]);
    }
#line 1710 "parser.c"
    break;

  case 42: /* simple_expression: sum_expression  */
#line 415 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1718 "parser.c"
    break;

  case 43: /* relational: LT_TOKEN  */
#line 421 "parser.y"
    {
        ast_node_t* lt_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "<",                
            NULL_STMT,         
            REL_EXP,           
            NULL_TYPE           
        );
        
        yyval = lt_node;
    }
#line 1735 "parser.c"
    break;

  case 44: /* relational: LTE_TOKEN  */
#line 434 "parser.y"
    {
        ast_node_t* lte_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "<=",               
            NULL_STMT,         
            REL_EXP,            
            NULL_TYPE          
        );

        yyval = lte_node;
    }
#line 1752 "parser.c"
    break;

  case 45: /* relational: GT_TOKEN  */
#line 447 "parser.y"
    {
        ast_node_t* gt_node = new_ast_node(
            EXPRESSION_NODE,   
            global_line_number, 
            ">",                
            NULL_STMT,          
            REL_EXP,            
            NULL_TYPE          
        );

        yyval = gt_node;
    }
#line 1769 "parser.c"
    break;

  case 46: /* relational: GTE_TOKEN  */
#line 460 "parser.y"
    {
        ast_node_t* gte_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            ">=",               
            NULL_STMT,         
            REL_EXP,          
            NULL_TYPE          
        );
      
        yyval = gte_node;
    }
#line 1786 "parser.c"
    break;

  case 47: /* relational: EQ_TOKEN  */
#line 473 "parser.y"
    {   
        ast_node_t* eq_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "=",                
            NULL_STMT,         
            REL_EXP,           
            NULL_TYPE         
        );

        yyval = eq_node;
        yyval->extended_type = EXT_ASSIGN;
    }
#line 1804 "parser.c"
    break;

  case 48: /* relational: NEQ_TOKEN  */
#line 487 "parser.y"
    {
        ast_node_t* neq_node = new_ast_node(
            EXPRESSION_NODE,   
            global_line_number, 
            "!=",               
            NULL_STMT,          
            REL_EXP,            
            NULL_TYPE          
        );
   
        yyval = neq_node;
    }
#line 1821 "parser.c"
    break;

  case 49: /* sum_expression: sum_expression sum term  */
#line 502 "parser.y"
    {        
        yyval = yyvsp[-1];
        yyval->extended_type = EXT_OPERATOR;
        yyval->node_kind = EXPRESSION_NODE;

        add_child(yyval, yyvsp[-2]);
        add_child(yyval, yyvsp[0]);
    }
#line 1834 "parser.c"
    break;

  case 50: /* sum_expression: term  */
#line 511 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1842 "parser.c"
    break;

  case 51: /* sum: PLUS_TOKEN  */
#line 517 "parser.y"
    {
        ast_node_t* plus_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "+",               
            NULL_STMT,         
            OP_EXP,            
            NULL_TYPE          
        );

        yyval = plus_node;
    }
#line 1859 "parser.c"
    break;

  case 52: /* sum: MINUS_TOKEN  */
#line 530 "parser.y"
    {
        ast_node_t* minus_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "-",               
            NULL_STMT,         
            OP_EXP,            
            NULL_TYPE          
        );
      
        yyval = minus_node;
    }
#line 1876 "parser.c"
    break;

  case 53: /* term: term mult factor  */
#line 545 "parser.y"
    {
        yyval = yyvsp[-1];
        yyval->extended_type = EXT_OPERATOR;
        yyval->node_kind = EXPRESSION_NODE;

        add_child(yyval, yyvsp[-2]);
        add_child(yyval, yyvsp[0]);
        
    }
#line 1890 "parser.c"
    break;

  case 54: /* term: factor  */
#line 555 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1898 "parser.c"
    break;

  case 55: /* mult: MULTIPLY_TOKEN  */
#line 561 "parser.y"
    {
        ast_node_t* multiply_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "*",              
            NULL_STMT,          
            OP_EXP,           
            NULL_TYPE         
        );

        yyval = multiply_node;
    }
#line 1915 "parser.c"
    break;

  case 56: /* mult: DIVIDE_TOKEN  */
#line 574 "parser.y"
    {
        ast_node_t* divide_node = new_ast_node(
            EXPRESSION_NODE,    
            global_line_number, 
            "/",               
            NULL_STMT,         
            OP_EXP,            
            NULL_TYPE          
        );

        yyval = divide_node;
    }
#line 1932 "parser.c"
    break;

  case 57: /* factor: LPAREN_TOKEN expression RPAREN_TOKEN  */
#line 589 "parser.y"
    {
        yyval = yyvsp[-1];
    }
#line 1940 "parser.c"
    break;

  case 58: /* factor: var  */
#line 593 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1948 "parser.c"
    break;

  case 59: /* factor: activation  */
#line 597 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1956 "parser.c"
    break;

  case 60: /* factor: num  */
#line 601 "parser.y"
    {
        yyval = yyvsp[0];
        yyval->extended_type = EXT_CONSTANT;
        yyval->node_kind = EXPRESSION_NODE;
    }
#line 1966 "parser.c"
    break;

  case 61: /* activation: id LPAREN_TOKEN args RPAREN_TOKEN  */
#line 609 "parser.y"
    {
        yyval = yyvsp[-3];
        yyval->extended_type = EXT_FUNCTION_CALL;
        yyval->node_kind = EXPRESSION_NODE;

        add_child(yyval, yyvsp[-1]);
    }
#line 1978 "parser.c"
    break;

  case 62: /* args: arg_list  */
#line 619 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1986 "parser.c"
    break;

  case 63: /* args: %empty  */
#line 623 "parser.y"
    {
        yyval = NULL;
    }
#line 1994 "parser.c"
    break;

  case 64: /* arg_list: arg_list COMMA_TOKEN expression  */
#line 629 "parser.y"
    {
        if (yyvsp[-2] != NULL) 
        {
            yyval = yyvsp[-2];
            add_sibling(yyval, yyvsp[0]);
        }
        else 
        {
            yyval = yyvsp[0];
        }
    }
#line 2010 "parser.c"
    break;

  case 65: /* arg_list: expression  */
#line 641 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 2018 "parser.c"
    break;

  case 66: /* id: ID_TOKEN  */
#line 647 "parser.y"
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
            EXPRESSION_NODE,         
            global_line_number,      
            token->lexeme,           
            NULL_STMT,              
            ID_EXP,                
            NULL_TYPE                
        );

        yyval = id_node; 
        yyval->extended_type = EXT_IDENTIFIER;
        yyval->node_kind = EXPRESSION_NODE;
    }
#line 2048 "parser.c"
    break;

  case 67: /* num: NUM_TOKEN  */
#line 675 "parser.y"
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

        yyval = num_node; 
    }
#line 2076 "parser.c"
    break;


#line 2080 "parser.c"

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

#line 699 "parser.y"


void yyerror(char *s)
{
    fprintf(stderr, "\x1b[1m%s:\x1b[0m in line \x1b[1m%d:\x1b[0m\n", global_argv[1], global_line_number);
    printf("\x1b[31m%s:\x1b[0m symbol \x1b[1m'%s'\x1b[0m not expected\n", s, global_lexeme);
    exit(1);
    
}

int yylex()
{
    token_t *token = get_next_token();
    if(flag_lexical_error == 1)
    {
        //printf("lexical error: invalid token\n");
        free(token);
        return ERROR_TOKEN;
    }
    if(token!=NULL) 
    {
        save_token_info(token);
    }
    //print_token(token);

    if (token == NULL) 
    {
        // EOF
        return YYEOF;
    }

    int flag = process_token(token);
    int token_to_return = convert_token(token->type);  
    
    if (flag != 1) 
    {
        //printf("lexical error: invalid token\n");
        free(token);
        exit(1);
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
