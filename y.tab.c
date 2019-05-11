/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <string.h>
	#include "global.h"
    #include <stdbool.h>

typedef struct Entry Entry;
struct Entry {  //表中的一行
    int index;
    Value *id_ptr;
    Entry *next;
	char Kind[50];
	int Scope;
	char Attribute[50];
	char type[50];
};

typedef struct Header Header;
struct Header { //一張表
    int depth;
	int entry_num;
    Entry *table_root;
    //Entry *table_tail;
    Header *pre;
};
Header *header_root = NULL;
Header *cur_header = NULL;
int depth = 0;

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(const Header *header, const char *id);
Header* create_symbol();
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void dump_symbol(Header *header);
void new_scope();
void dump_scope();
void dump_all_scopes();


#line 112 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INC = 258,
    DEC = 259,
    MTE = 260,
    LTE = 261,
    EQ = 262,
    NE = 263,
    ADDASGN = 264,
    SUBASGN = 265,
    MULASGN = 266,
    DIVASGN = 267,
    MODASGN = 268,
    AND = 269,
    OR = 270,
    STR_TYPE = 271,
    PRINT = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    WHILE = 276,
    INT = 277,
    FLOAT = 278,
    VOID = 279,
    BOOL = 280,
    TRUE = 281,
    FALSE = 282,
    RET = 283,
    CONT = 284,
    BREAK = 285,
    I_CONST = 286,
    F_CONST = 287,
    STRING = 288,
    ID = 289
  };
#endif
/* Tokens.  */
#define INC 258
#define DEC 259
#define MTE 260
#define LTE 261
#define EQ 262
#define NE 263
#define ADDASGN 264
#define SUBASGN 265
#define MULASGN 266
#define DIVASGN 267
#define MODASGN 268
#define AND 269
#define OR 270
#define STR_TYPE 271
#define PRINT 272
#define IF 273
#define ELSE 274
#define FOR 275
#define WHILE 276
#define INT 277
#define FLOAT 278
#define VOID 279
#define BOOL 280
#define TRUE 281
#define FALSE 282
#define RET 283
#define CONT 284
#define BREAK 285
#define I_CONST 286
#define F_CONST 287
#define STRING 288
#define ID 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "compiler_hw2.y" /* yacc.c:355  */

    struct Value val;

#line 224 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 241 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   764

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    35,     2,     2,    49,    42,     2,
      36,    37,    43,    44,    41,    45,    40,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    57,
      50,    56,    51,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    53,    59,    46,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    84,    85,    86,    87,    91,    92,    93,
      94,    95,    96,    97,   101,   102,   106,   107,   108,   109,
     113,   114,   115,   116,   117,   118,   122,   123,   127,   128,
     129,   130,   134,   135,   136,   140,   144,   145,   146,   147,
     148,   152,   153,   154,   158,   159,   163,   164,   168,   169,
     173,   174,   178,   179,   183,   184,   188,   189,   193,   194,
     195,   196,   197,   198,   202,   203,   204,   205,   206,   210,
     211,   215,   219,   220,   224,   225,   229,   230,   234,   235,
     239,   240,   241,   242,   243,   247,   248,   252,   253,   257,
     258,   259,   260,   261,   261,   262,   263,   263,   267,   268,
     272,   276,   277,   281,   282,   283,   287,   288,   292,   293,
     297,   298,   299,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   315,   316,   317,   321,   322,   326,   327,   328,
     329,   330,   331,   335,   339,   340,   341,   342,   346,   347,
     351,   352,   356,   357,   361,   362,   366,   367,   368,   372,
     373,   374,   375,   379,   380,   384,   385,   389,   390,   391,
     392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INC", "DEC", "MTE", "LTE", "EQ", "NE",
  "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND", "OR",
  "STR_TYPE", "PRINT", "IF", "ELSE", "FOR", "WHILE", "INT", "FLOAT",
  "VOID", "BOOL", "TRUE", "FALSE", "RET", "CONT", "BREAK", "I_CONST",
  "F_CONST", "STRING", "ID", "'\"'", "'('", "')'", "'['", "']'", "'.'",
  "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "print_arg", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "specifier_qualifier_list", "declarator",
  "direct_declarator", "$@1", "$@2", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "program", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    34,    40,    41,    91,    93,
      46,    44,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -167

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     429,  -167,  -167,  -167,  -167,  -167,  -167,   158,   -16,  -167,
     122,    75,    34,   157,   184,   166,  -167,  -167,     4,  -167,
    -167,    10,  -167,    21,  -167,   243,  -167,   122,  -167,    34,
      69,   614,   157,  -167,  -167,  -167,   158,  -167,   424,  -167,
      34,   104,   104,    17,    27,    35,   142,  -167,  -167,   458,
      48,   150,  -167,  -167,   126,   171,   528,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,    44,    20,   685,  -167,
      85,    49,  -167,    14,   124,   190,   224,   228,   269,     7,
    -167,  -167,    11,  -167,  -167,  -167,   288,   322,  -167,  -167,
    -167,  -167,   186,  -167,  -167,  -167,    75,   247,   116,  -167,
    -167,  -167,  -167,   254,  -167,   424,  -167,  -167,  -167,   597,
    -167,  -167,   110,   597,   492,   597,  -167,    29,  -167,  -167,
     390,   259,   162,    75,    66,   258,  -167,  -167,   631,   597,
     262,  -167,  -167,  -167,  -167,  -167,  -167,   685,  -167,   685,
     685,   685,   685,   685,   685,   685,   685,   685,   685,   685,
     685,   685,   685,   685,   685,   597,   685,  -167,  -167,   356,
    -167,  -167,   179,   260,   266,  -167,  -167,  -167,   264,  -167,
    -167,     1,  -167,   270,   284,   189,   492,   207,  -167,  -167,
    -167,  -167,  -167,   721,   648,   185,  -167,   195,   685,  -167,
     212,  -167,   202,  -167,  -167,  -167,  -167,  -167,    85,    85,
    -167,  -167,  -167,  -167,    14,    14,   124,   190,   224,   228,
     269,   -15,  -167,  -167,   717,  -167,   139,  -167,  -167,    75,
    -167,   193,  -167,   292,  -167,   390,   562,   390,  -167,   291,
     299,  -167,   290,   195,   147,   666,  -167,  -167,   685,  -167,
     685,  -167,  -167,  -167,  -167,   280,   390,   213,  -167,  -167,
    -167,  -167,  -167,   300,  -167,   302,  -167,  -167,   390,  -167,
     390,  -167,  -167,  -167,  -167
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    84,    81,    82,    80,    83,    89,     0,    98,   156,
       0,    74,     0,    88,     0,     0,   153,   155,     0,    99,
      72,     0,    76,    78,    75,     0,   138,     0,   160,     0,
      93,     0,    87,     1,   154,    90,     0,    73,     0,   158,
       0,     0,     0,     0,     0,     0,     0,    66,    67,     0,
       0,     0,     3,     4,     2,     0,     0,    20,    21,    22,
      23,    24,    25,   142,   134,     7,    16,    26,     0,    28,
      32,    35,    36,    41,    44,    46,    48,    50,    52,    54,
      56,    64,     0,   140,   127,   128,     0,     0,   129,   130,
     131,   132,    78,   139,   159,   106,     0,     0,     0,     2,
      92,    26,    71,     0,    77,     0,   122,    79,   157,     0,
      17,    18,     0,     0,     0,     0,   151,     0,   149,   150,
       0,     0,     0,    86,   108,     0,    12,    13,     0,     0,
       0,    62,    63,    59,    60,    61,    58,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   136,     0,
     135,   141,   105,     0,   100,   101,    97,    95,     0,    91,
     125,     0,    70,     0,     0,     0,     0,     0,   152,   133,
       5,     6,    85,     0,     0,   110,   109,   111,     0,     9,
       0,    14,     0,    11,    57,    29,    30,    31,    33,    34,
      40,    39,    37,    38,    42,    43,    45,    47,    49,    51,
      53,     0,    65,   137,     0,   103,   110,   104,    94,     0,
     107,     0,   123,     0,    68,     0,     0,     0,   118,     0,
       0,   114,     0,   112,     0,     0,    27,    10,     0,     8,
       0,   102,   124,   126,    69,   144,     0,     0,   146,   119,
     113,   115,   120,     0,   116,     0,    15,    55,     0,   147,
       0,   121,   117,   145,   148
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,   -29,  -167,   -51,    25,  -167,   111,
      38,   188,   204,   192,   208,   209,  -167,   -30,    24,  -167,
     -28,  -167,  -166,     9,     0,  -167,   326,   -49,   248,    -2,
      -8,  -167,  -167,     2,   -92,  -167,   151,  -167,  -167,   -89,
    -162,   -91,  -167,   -84,  -167,    43,   257,   286,   -98,  -167,
    -167,  -167,  -167,   360,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    65,    66,   190,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   137,
      82,   174,   103,    26,    27,    21,    22,    11,   124,    12,
      13,    96,    97,    14,   229,   164,   165,    98,   125,   230,
     187,   107,   171,    83,    84,    85,    29,    87,    88,    89,
      90,    91,    15,    16,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,   102,   101,   161,   163,    18,    32,   123,    23,     9,
      19,    24,   110,   111,   170,    10,   176,   138,   232,   144,
     145,   117,   154,   233,     9,    92,   156,     8,   122,   131,
     132,   133,   134,   135,    92,   186,   179,     1,    93,   101,
     240,    35,   221,     2,     3,     4,     5,   126,   127,    93,
       1,    36,   156,   112,   233,    28,     2,     3,     4,     5,
     222,   155,   106,   113,   146,   147,    39,    37,   157,   255,
     156,   114,    94,   217,   123,   161,   136,    38,   226,    25,
     128,   122,   129,   108,   130,   175,   178,   177,   195,   196,
     197,     1,    25,   142,   143,    93,   162,     2,     3,     4,
       5,   192,   183,    95,   184,   118,   -96,    41,    42,     8,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   185,   211,   139,   106,
     243,   148,   149,   140,   141,    52,    53,   236,    99,    55,
     109,   245,   253,   248,   172,   173,    57,    58,    59,    60,
      61,    62,   191,   167,   102,   101,     6,   168,     7,   101,
     215,   194,   259,     1,   216,     8,    33,   198,   199,     2,
       3,     4,     5,     6,   263,   214,   264,   184,   115,    20,
     212,   120,     1,   162,   252,   185,   204,   205,     2,     3,
       4,     5,     6,    30,     7,    31,    41,    42,   247,   181,
       6,     8,     7,   156,   121,   102,   101,   119,    32,     8,
     257,   101,    18,     6,   162,   214,   216,   184,     6,   162,
       7,   183,     8,   184,    52,    53,   225,    99,    55,    56,
     156,   234,   150,   235,   162,    57,    58,    59,    60,    61,
      62,   239,    38,   156,   227,   106,    41,    42,   156,   237,
     260,   105,   242,   238,   156,   200,   201,   202,   203,     1,
      43,    44,   256,    45,    46,     2,     3,     4,     5,    47,
      48,    49,    50,    51,    52,    53,   151,    54,    55,    56,
      40,   152,    86,   153,   166,    57,    58,    59,    60,    61,
      62,    41,    42,   169,   180,   188,   193,   218,   220,   258,
      63,    25,    64,   223,     1,    43,    44,   219,    45,    46,
       2,     3,     4,     5,    47,    48,    49,    50,    51,    52,
      53,   224,    54,    55,    56,    41,    42,   244,   249,   251,
      57,    58,    59,    60,    61,    62,   250,   261,   206,    43,
      44,   262,    45,    46,   208,    63,    25,   158,    47,    48,
      49,    50,    51,    52,    53,   207,    54,    55,    56,    41,
      42,   209,   104,   210,    57,    58,    59,    60,    61,    62,
     241,   182,   159,    43,    44,    34,    45,    46,     0,    63,
      25,   160,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    41,    42,     0,     0,     0,    57,    58,
      59,    60,    61,    62,     0,     0,     0,    43,    44,     0,
      45,    46,     0,    63,    25,   213,    47,    48,    49,    50,
      51,    52,    53,     0,    54,    55,    56,    41,    42,     0,
       0,     0,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     1,     0,    63,    25,     0,
       0,     2,     3,     4,     5,    52,    53,     0,    99,    55,
      56,    41,    42,     6,     0,     7,    57,    58,    59,    60,
      61,    62,     8,     0,     0,    43,     0,     0,     0,     0,
       0,     0,   105,     0,    47,    48,     0,     0,     0,    52,
      53,     0,    99,    55,    56,    41,    42,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,    43,
       0,     0,     0,     0,     0,   116,     0,     0,    47,    48,
       0,     0,     0,    52,    53,     0,    99,    55,    56,     0,
       0,    41,    42,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     1,    43,     0,     0,     0,    63,
       2,     3,     4,     5,    47,    48,     0,     0,     0,    52,
      53,     0,    99,    55,    56,    41,    42,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,     0,    52,    53,     0,    99,    55,    56,   246,
      41,    42,     0,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    43,     0,     0,    41,    42,     0,
       0,     0,     0,    47,    48,     0,     0,     0,    52,    53,
       0,    99,    55,    56,    41,    42,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    52,    53,     0,    99,    55,
      56,    41,    42,   100,     0,     0,    57,    58,    59,    60,
      61,    62,    52,    53,     0,    99,    55,    56,   189,    41,
      42,     0,     0,    57,    58,    59,    60,    61,    62,    52,
      53,     0,    99,    55,    56,     0,     0,   231,    41,    42,
      57,    58,    59,    60,    61,    62,     0,    52,    53,     0,
      99,    55,    56,     0,     0,   254,     0,     0,    57,    58,
      59,    60,    61,    62,     0,     0,    52,    53,     0,    99,
      55,    56,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,     1,     0,     0,     0,     1,     0,     2,
       3,     4,     5,     2,     3,     4,     5,     0,     0,     0,
       0,     6,     0,   214,   228,   184,     0,   183,   228,   184,
       8,     0,     0,     0,     8
};

static const yytype_int16 yycheck[] =
{
       0,    31,    31,    87,    96,     7,    14,    56,    10,     0,
       8,    11,    41,    42,   105,    15,   114,    68,   184,     5,
       6,    49,    15,   185,    15,    27,    41,    43,    56,     9,
      10,    11,    12,    13,    36,   124,   120,    16,    29,    68,
      55,    37,    41,    22,    23,    24,    25,     3,     4,    40,
      16,    41,    41,    36,   216,    12,    22,    23,    24,    25,
      59,    54,    38,    36,    50,    51,    23,    57,    57,   235,
      41,    36,    29,   162,   123,   159,    56,    56,   176,    58,
      36,   109,    38,    40,    40,   113,    57,   115,   139,   140,
     141,    16,    58,    44,    45,    86,    96,    22,    23,    24,
      25,   129,    36,    34,    38,    57,    37,     3,     4,    43,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   124,   155,    43,   105,
     221,     7,     8,    48,    49,    31,    32,   188,    34,    35,
      36,   225,   234,   227,    34,    35,    42,    43,    44,    45,
      46,    47,   128,    37,   184,   184,    34,    41,    36,   188,
     162,   137,   246,    16,   162,    43,     0,   142,   143,    22,
      23,    24,    25,    34,   258,    36,   260,    38,    36,    57,
     156,    55,    16,   183,    37,   183,   148,   149,    22,    23,
      24,    25,    34,    36,    36,    38,     3,     4,   226,    37,
      34,    43,    36,    41,    33,   235,   235,    57,   216,    43,
     240,   240,   214,    34,   214,    36,   214,    38,    34,   219,
      36,    36,    43,    38,    31,    32,    37,    34,    35,    36,
      41,    36,    42,    38,   234,    42,    43,    44,    45,    46,
      47,    39,    56,    41,    37,   221,     3,     4,    41,    37,
      37,    58,    59,    41,    41,   144,   145,   146,   147,    16,
      17,    18,   238,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    52,    34,    35,    36,
      23,    53,    25,    14,    37,    42,    43,    44,    45,    46,
      47,     3,     4,    39,    35,    37,    34,    37,    34,    19,
      57,    58,    59,    33,    16,    17,    18,    41,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    37,    34,    35,    36,     3,     4,    35,    37,    39,
      42,    43,    44,    45,    46,    47,    37,    37,   150,    17,
      18,    39,    20,    21,   152,    57,    58,    59,    26,    27,
      28,    29,    30,    31,    32,   151,    34,    35,    36,     3,
       4,   153,    36,   154,    42,    43,    44,    45,    46,    47,
     219,   123,    86,    17,    18,    15,    20,    21,    -1,    57,
      58,    59,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,     3,     4,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    57,    58,    59,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,     3,     4,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    57,    58,    -1,
      -1,    22,    23,    24,    25,    31,    32,    -1,    34,    35,
      36,     3,     4,    34,    -1,    36,    42,    43,    44,    45,
      46,    47,    43,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    26,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,     3,     4,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    26,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    -1,
      -1,     3,     4,    -1,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    57,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,     3,     4,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
       3,     4,    -1,    -1,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    17,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,     3,     4,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    31,    32,    -1,    34,    35,
      36,     3,     4,    39,    -1,    -1,    42,    43,    44,    45,
      46,    47,    31,    32,    -1,    34,    35,    36,    37,     3,
       4,    -1,    -1,    42,    43,    44,    45,    46,    47,    31,
      32,    -1,    34,    35,    36,    -1,    -1,    39,     3,     4,
      42,    43,    44,    45,    46,    47,    -1,    31,    32,    -1,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    45,    46,    47,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    16,    -1,    -1,    -1,    16,    -1,    22,
      23,    24,    25,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    34,    -1,    36,    37,    38,    -1,    36,    37,    38,
      43,    -1,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    22,    23,    24,    25,    34,    36,    43,    83,
      84,    87,    89,    90,    93,   112,   113,   114,    89,    93,
      57,    85,    86,    89,    84,    58,    83,    84,   105,   106,
      36,    38,    90,     0,   113,    37,    41,    57,    56,   105,
     106,     3,     4,    17,    18,    20,    21,    26,    27,    28,
      29,    30,    31,    32,    34,    35,    36,    42,    43,    44,
      45,    46,    47,    57,    59,    61,    62,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    80,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    89,    83,   105,    34,    91,    92,    97,    34,
      39,    64,    77,    82,    86,    58,    78,   101,   105,    36,
      64,    64,    36,    36,    36,    36,    57,    80,    57,    57,
      55,    33,    80,    87,    88,    98,     3,     4,    36,    38,
      40,     9,    10,    11,    12,    13,    56,    79,    66,    43,
      48,    49,    44,    45,     5,     6,    50,    51,     7,     8,
      42,    52,    53,    14,    15,    54,    41,    57,    59,   107,
      59,   103,    84,    94,    95,    96,    37,    37,    41,    39,
     101,   102,    34,    35,    81,    80,   108,    80,    57,   103,
      35,    37,    88,    36,    38,    93,    99,   100,    37,    37,
      63,    78,    80,    34,    78,    66,    66,    66,    67,    67,
      69,    69,    69,    69,    70,    70,    71,    72,    73,    74,
      75,    80,    78,    59,    36,    89,    93,    99,    37,    41,
      34,    41,    59,    33,    37,    37,   108,    37,    37,    94,
      99,    39,    82,   100,    36,    38,    66,    37,    41,    39,
      55,    96,    59,   101,    35,   103,    37,    80,   103,    37,
      37,    39,    37,    94,    39,    82,    78,    77,    19,   103,
      37,    37,    39,   103,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      67,    67,    68,    68,    68,    69,    70,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    81,
      81,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    91,    90,    90,    92,    90,    93,    93,
      94,    95,    95,    96,    96,    96,    97,    97,    98,    98,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   104,   105,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   112,   112,   113,   113,   114,   114,   114,
     114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     4,     3,
       4,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     4,     3,
       1,     1,     2,     3,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       3,     4,     3,     0,     5,     4,     0,     4,     1,     2,
       1,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     6,     7,     2,
       2,     2,     3,     1,     2,     1,     1,     4,     3,     3,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 83 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val) = yylval.val;/*printf("333");*/}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 84 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 134 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 140 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 144 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 152 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 158 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 163 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 168 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 173 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 178 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 183 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 188 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 220 "compiler_hw2.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-2].val);Value *v2=&(yyvsp[-1].val); insert_symbol(cur_header,v1,v2,"variable");}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 224 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 229 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 234 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[-2].val);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 239 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 240 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 241 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 242 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 243 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 253 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 257 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val) = yylval.val;/*printf("111");*/}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 261 "compiler_hw2.y" /* yacc.c:1646  */
    {new_scope();}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 263 "compiler_hw2.y" /* yacc.c:1646  */
    {new_scope();}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 281 "compiler_hw2.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-1].val);Value *v2=&(yyvsp[0].val); insert_symbol(cur_header,v1,v2,"parameter");}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 315 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 384 "compiler_hw2.y" /* yacc.c:1646  */
    {dump_scope();}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 390 "compiler_hw2.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-2].val);Value *v2=&(yyvsp[-1].val);insert_symbol_forfun(cur_header,v1,v2,"function");}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1845 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 395 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    extern FILE *yyin;
    yyin = fopen(argv[1],"r");

	yylineno = 0;
	new_scope();
    yyparse();
    extern int line_cnt;

	dump_all_scopes();
	printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

Header* create_symbol() 
{
	Header *ptr = malloc(sizeof(Header)); //創新的table
	ptr->depth=depth;
	depth++;
	ptr->table_root=malloc(sizeof(Entry));
	ptr->table_root=NULL;
	//ptr->table_root->next = NULL;
	//ptr->table_tail = ptr->table_root;
	ptr->pre = NULL;
	ptr->entry_num=-1;
	return ptr;
}
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind) 
{
	//printf("%s\n",id_ptr->id_name);

	Value* id_ptr_copy=malloc(sizeof(Value));
	id_ptr_copy->id_name=malloc(sizeof(char)*50);
	strcpy(id_ptr_copy->id_name,id_ptr->id_name);


	if (cur_header == NULL) //無table
	{
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header, id_ptr->id_name) == NULL) 
	{
        
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
		
        tmp->id_ptr = id_ptr_copy;
		//printf("Insert a symbol: %s in table %d,INDEX: %d\n", tmp->id_ptr->id_name, header->depth,tmp->index);
        tmp->next = NULL;
		tmp->Scope=header->depth;
		strcpy(tmp->Kind,kind);
		if(strcmp(kind,"function")==0)
		{

		}
		else //只有kind為function的,Attribute才有內容
		{
			strcat(tmp->Attribute,"");
		}

		//TYPE
		if(t_ptr->type==V_T)
		{
			strcat(tmp->type,"void");
		}	
		else if(t_ptr->type==I_T)
		{
			strcat(tmp->type,"int");
		}	
		else if(t_ptr->type==F_T)
		{
			strcat(tmp->type,"float");
		}
		else if(t_ptr->type==S_T)
		{
			strcat(tmp->type,"string");
		}
		else if(t_ptr->type==B_T)
		{
			strcat(tmp->type,"bool");
		}
		Entry *e=cur_header->table_root;
		if(e==NULL)
		{
			cur_header->table_root=tmp;
		}
		else
		{
			while(e->next!=NULL)
			{
				e=e->next;
			}
			e->next=tmp;
		}
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        char errmsg[64];
        sprintf(errmsg, "redefined variable \'%s\'", id_ptr->id_name);
        yyerror(errmsg);
    }
}

void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind) 
{
	//printf("%s\n",id_ptr->id_name);
	int table_or_not=1; //have table yet
	Value* id_ptr_copy=malloc(sizeof(Value));
	id_ptr_copy->id_name=malloc(sizeof(char)*50);
	strcpy(id_ptr_copy->id_name,id_ptr->id_name);

	if (cur_header == NULL) //無table
	{
		table_or_not=0; //not have table yet
        cur_header = create_symbol();
        header_root = cur_header;
        header = cur_header;
    }
    if (lookup_symbol(cur_header->pre, id_ptr->id_name) == NULL) 
	{
        if(table_or_not==1)
		{
			header=header->pre;
		}
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
		
        tmp->id_ptr = id_ptr_copy;
		//printf("Insert a symbol: %s in table %d,INDEX: %d\n", tmp->id_ptr->id_name, header->depth,tmp->index);
        tmp->next = NULL;
		tmp->Scope=header->depth;
		strcpy(tmp->Kind,kind);
		
		//TYPE
		if(t_ptr->type==V_T)
		{
			strcat(tmp->type,"void");
		}	
		else if(t_ptr->type==I_T)
		{
			strcat(tmp->type,"int");
		}	
		else if(t_ptr->type==F_T)
		{
			strcat(tmp->type,"float");
		}
		else if(t_ptr->type==S_T)
		{
			strcat(tmp->type,"string");
		}
		else if(t_ptr->type==B_T)
		{
			strcat(tmp->type,"bool");
		}
		Entry *e=header->table_root;
		if(e==NULL)
		{
			header->table_root=tmp;
		}
		else
		{
			while(e->next!=NULL)
			{
				e=e->next;
			}
			e->next=tmp;
		}
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        char errmsg[64];
        sprintf(errmsg, "redefined variable \'%s\'", id_ptr->id_name);
        yyerror(errmsg);
    }
}
int lookup_symbol(const Header *header, const char *id) 
{
	if (header->table_root == NULL) 
	{
		//printf("NULLLLLLLL\n");
        return NULL;
    }
    Entry *cur = header->table_root;
    while (cur != NULL)
	{
		//printf("\nindex:%d\n",cur->index);
		//printf("%s\n",id);
		//printf("%s\n",cur->id_ptr->id_name);
        if (strcmp(cur->id_ptr->id_name, id) == 0)
		{
            return cur->index;
        }
        cur = cur->next;
    }
    return NULL;
}
void dump_symbol(Header *header) 
{
    printf("\n\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	if (header->table_root == NULL) 
	{
        return;
    }

    Entry *cur = header->table_root;
    while (cur != NULL)
	{
		printf("\n%-10d%-10s%-12s%-10s%-10d%-10s",
		cur->index, cur->id_ptr->id_name, cur->Kind, cur->type, cur->Scope, cur->Attribute);
		//printf("\n%d %s\n",cur->index, cur->id_ptr->id_name);
        Entry *tmp = cur;
        cur = cur->next;
		
		/*free(tmp->id_ptr->val_ptr);
        tmp->id_ptr->val_ptr = NULL;
		
		free(tmp->id_ptr);
        tmp->id_ptr = NULL;*/
		
		free(tmp);
        tmp = NULL;
    }
	printf("\n\n");
}

void new_scope()
{
    Header *ptr = create_symbol();
    ptr->pre = cur_header;
    cur_header = ptr;
}

void dump_scope()
{
    Header *tmp = cur_header;
	//printf("\ndump_scope: %d",tmp->depth);
    cur_header = cur_header->pre;
    dump_symbol(tmp);
    free(tmp);
    tmp = NULL;
    depth--;
}

void dump_all_scopes()
{
	while (cur_header != NULL) 
	{
        dump_scope();
    }
}

