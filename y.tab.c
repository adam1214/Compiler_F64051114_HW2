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
int printline_or_not=1;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(const Header *header, const char *id);
Header* create_symbol();
void insert_symbol(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void insert_symbol_forfun(Header *header, Value *t_ptr, Value *id_ptr,char *kind);
void dump_symbol(Header *header);
void new_scope();
void dump_scope();
void dump_all_scopes();


#line 113 "y.tab.c" /* yacc.c:339  */

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
#line 52 "compiler_hw2.y" /* yacc.c:355  */

    struct Value val;

#line 225 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   759

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

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
       0,    84,    84,   102,   103,   104,   105,   109,   110,   111,
     112,   113,   117,   120,   121,   122,   141,   160,   161,   162,
     166,   167,   171,   172,   173,   174,   178,   179,   180,   181,
     182,   183,   187,   188,   192,   193,   194,   195,   199,   200,
     201,   205,   209,   210,   211,   212,   213,   217,   218,   219,
     223,   224,   228,   229,   233,   234,   238,   239,   243,   244,
     248,   249,   253,   254,   282,   283,   284,   285,   286,   287,
     291,   292,   293,   294,   295,   299,   300,   320,   324,   325,
     326,   330,   331,   335,   336,   340,   341,   345,   346,   347,
     348,   349,   353,   354,   358,   359,   363,   364,   365,   366,
     367,   367,   368,   369,   369,   373,   374,   378,   382,   383,
     387,   388,   389,   393,   394,   398,   399,   403,   404,   405,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   421,
     422,   423,   427,   428,   432,   433,   434,   435,   436,   437,
     441,   445,   446,   447,   448,   452,   453,   457,   458,   462,
     463,   467,   468,   472,   473,   474,   478,   479,   480,   481,
     485,   486,   490,   491,   495,   496,   497,   498
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
  "primary_expression", "primary_expression_forfun",
  "postfix_expression_forfun", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
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

#define YYPACT_NINF -168

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-168)))

#define YYTABLE_NINF -104

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     716,  -168,  -168,  -168,  -168,  -168,  -168,   158,   -15,  -168,
     103,    78,   508,    35,   119,   683,  -168,  -168,    43,  -168,
    -168,   -17,  -168,   175,  -168,   224,  -168,   103,  -168,   508,
     153,   561,    35,  -168,  -168,  -168,   158,  -168,   138,  -168,
     508,   632,   632,     7,   118,   135,   159,  -168,  -168,   405,
     151,   182,   189,   196,   -13,   228,   475,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,   221,    71,    37,
     650,  -168,   -11,    19,  -168,    46,   124,   222,   213,   223,
     260,     6,  -168,  -168,    20,    78,  -168,  -168,   269,   303,
    -168,  -168,  -168,  -168,   219,  -168,  -168,  -168,    78,   240,
      54,   242,  -168,  -168,  -168,   241,  -168,   138,  -168,  -168,
    -168,   544,  -168,  -168,   131,   544,   439,   544,  -168,    42,
    -168,  -168,   371,   244,    69,    78,   113,   247,   578,  -168,
    -168,   544,   254,  -168,  -168,  -168,  -168,  -168,  -168,   650,
    -168,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   544,   650,  -168,
    -168,  -168,   337,  -168,    78,   168,   265,   267,  -168,  -168,
    -168,   275,  -168,  -168,    -6,  -168,   277,   280,    97,   439,
     111,  -168,  -168,   282,   283,  -168,   711,   595,   169,  -168,
     183,   650,  -168,   152,  -168,    66,  -168,  -168,  -168,  -168,
    -168,   -11,   -11,  -168,  -168,  -168,  -168,    46,    46,   124,
     222,   213,   223,   260,   -10,  -168,  -168,  -168,   687,  -168,
     141,  -168,  -168,    78,  -168,    23,  -168,   287,  -168,   371,
     509,   371,  -168,   288,   299,  -168,   304,   183,   721,   613,
    -168,  -168,   650,  -168,   650,  -168,  -168,  -168,  -168,   323,
     371,   176,  -168,  -168,  -168,  -168,  -168,   307,  -168,   312,
    -168,  -168,   371,  -168,   371,  -168,  -168,  -168,  -168
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      80,    91,    88,    89,    87,    90,    96,     0,   105,   163,
       0,    81,     0,    95,     0,     0,   160,   162,     0,   106,
      78,     0,    83,    85,    82,     0,   145,     0,   167,     0,
     100,     0,    94,     1,   161,    97,     0,    79,     0,   165,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,     0,     3,     4,     2,     0,     0,    26,    27,    28,
      29,    30,    31,   149,   141,    13,    12,     0,    22,    32,
       0,    34,    38,    41,    42,    47,    50,    52,    54,    56,
      58,    60,    62,    70,     0,    80,   134,   135,     0,     0,
     136,   137,   138,   139,    85,   146,   166,   113,     0,     0,
       0,     2,    99,    32,    77,     0,    84,     0,   129,    86,
     164,     0,    23,    24,     0,     0,     0,     0,   158,     0,
     156,   157,     0,     0,     0,    93,   115,     0,     0,    18,
      19,     0,     0,    68,    69,    65,    66,    67,    64,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     147,   143,     0,   142,    80,   112,     0,   107,   108,   104,
     102,     0,    98,   132,     0,    76,     0,     0,     0,     0,
       0,   159,   140,     5,     6,    92,     0,     0,   117,   116,
     118,     0,    15,     0,    20,     0,    17,    63,    35,    36,
      37,    39,    40,    46,    45,    43,    44,    48,    49,    51,
      53,    55,    57,    59,     0,    71,   144,   148,     0,   110,
     117,   111,   101,     0,   114,     0,   130,     0,    74,     0,
       0,     0,   125,     0,     0,   121,     0,   119,     0,     0,
      33,    16,     0,    14,     0,   109,   131,   133,    75,   151,
       0,     0,   153,   126,   120,   122,   127,     0,   123,     0,
      21,    61,     0,   154,     0,   128,   124,   152,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,  -168,  -168,  -168,  -168,   -29,  -168,   -56,    85,
    -168,    88,   112,   200,   203,   205,   198,   214,  -168,   -30,
       1,  -168,   -27,  -168,  -167,     4,     0,  -168,   340,   -47,
     252,    -2,    -8,  -168,  -168,     2,   -91,  -168,   155,  -168,
    -168,  -109,  -158,   -89,  -168,   -86,  -168,   121,   199,   297,
    -100,  -168,  -168,  -168,  -168,   372,  -168
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    65,    66,    67,    68,   193,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   139,    84,   177,   105,    26,    27,    21,    22,    11,
     126,    12,    13,    98,    99,    14,   233,   167,   168,   100,
     127,   234,   190,   109,   174,    85,    86,    87,    29,    89,
      90,    91,    92,    93,    15,    16,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,   104,   103,   164,     9,    18,    32,   166,    23,   125,
      19,    24,   112,   113,   140,    10,   179,   189,   173,     9,
     236,   156,   119,    -7,    36,    94,    41,    42,     8,   124,
     237,   158,   141,    95,    94,   225,   182,   142,   143,   108,
      37,   103,   122,   114,    95,   244,   133,   134,   135,   136,
     137,   146,   147,   226,    52,    53,   221,   101,    55,    56,
     157,   158,   237,   144,   145,    57,    58,    59,    60,    61,
      62,    30,   259,    31,   129,   130,   164,   159,   125,   230,
      35,   107,   246,   158,   124,   198,   199,   200,   178,   160,
     180,   170,    95,   138,     1,   171,   148,   149,   165,   181,
       2,     3,     4,     5,   195,   243,   184,   158,   108,   131,
     158,   132,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   188,   194,
     214,   150,   151,    28,   229,   240,   247,     6,   158,     7,
     197,    41,    42,   249,    39,   252,     8,   257,   231,   186,
      96,   187,   158,     6,   115,     7,     8,   104,   103,   215,
      20,   110,   103,   219,   263,   175,   176,   220,   217,    52,
      53,   116,   101,    55,    56,     6,   267,   218,   268,   187,
      57,    58,    59,    60,    61,    62,   165,    97,   188,   241,
    -103,     1,     6,   242,     7,   117,   107,     2,     3,     4,
       5,     8,     6,   251,   218,   186,   187,   187,   120,   104,
     103,     8,    32,   264,   261,   103,    18,   158,   165,   238,
     220,   239,    40,   165,    88,    -8,   108,    41,    42,   201,
     202,    38,    -9,    25,   203,   204,   205,   206,   165,   121,
       1,    43,    44,   260,    45,    46,     2,     3,     4,     5,
      47,    48,    49,    50,    51,    52,    53,   128,    54,    55,
      56,   123,   207,   208,   152,   153,    57,    58,    59,    60,
      61,    62,    41,    42,   155,    38,   154,   169,    -7,   183,
     172,    63,    25,    64,   191,     1,    43,    44,   196,    45,
      46,     2,     3,     4,     5,    47,    48,    49,    50,    51,
      52,    53,   222,    54,    55,    56,    41,    42,   223,   224,
     227,    57,    58,    59,    60,    61,    62,   228,   -10,   -11,
      43,    44,   248,    45,    46,   253,    63,    25,   161,    47,
      48,    49,    50,    51,    52,    53,   254,    54,    55,    56,
      41,    42,   262,   255,   265,    57,    58,    59,    60,    61,
      62,   266,   209,   212,    43,    44,   210,    45,    46,   211,
      63,    25,   163,    47,    48,    49,    50,    51,    52,    53,
     213,    54,    55,    56,    41,    42,   106,   185,   245,    57,
      58,    59,    60,    61,    62,   162,     0,    34,    43,    44,
       0,    45,    46,     0,    63,    25,   216,    47,    48,    49,
      50,    51,    52,    53,     0,    54,    55,    56,    41,    42,
       0,     0,     0,    57,    58,    59,    60,    61,    62,     0,
       0,     0,    43,     0,     0,     0,     0,     0,    63,    25,
       0,    47,    48,     0,     0,     0,    52,    53,     0,   101,
      55,    56,    41,    42,     0,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     0,     0,    43,     0,     0,     0,
       0,     0,   118,     0,     0,    47,    48,     0,     0,     0,
      52,    53,     0,   101,    55,    56,     0,     0,    41,    42,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     1,    43,     0,     0,     0,    63,     2,     3,     4,
       5,    47,    48,     0,     0,     0,    52,    53,     0,   101,
      55,    56,    41,    42,     0,     0,     0,    57,    58,    59,
      60,    61,    62,     0,     1,     0,    43,     0,     0,     0,
       2,     3,     4,     5,     0,    47,    48,     0,     0,     0,
      52,    53,     0,   101,    55,    56,   250,    41,    42,     0,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,    43,     0,     0,    41,    42,    25,     0,     0,     0,
      47,    48,     0,     0,     0,    52,    53,     0,   101,    55,
      56,    41,    42,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    52,    53,     0,   101,    55,    56,    41,    42,
     102,     0,     0,    57,    58,    59,    60,    61,    62,    52,
      53,     0,   101,    55,    56,   192,    41,    42,     0,     0,
      57,    58,    59,    60,    61,    62,    52,    53,     0,   101,
      55,    56,     0,     0,   235,    41,    42,    57,    58,    59,
      60,    61,    62,     0,    52,    53,     0,   101,    55,    56,
       0,     0,   258,    41,    42,    57,    58,    59,    60,    61,
      62,     0,     0,    52,    53,     0,   101,    55,   111,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    62,
       0,    52,    53,    33,   101,    55,    56,     0,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    62,     0,     1,
       0,     0,     0,     1,     0,     2,     3,     4,     5,     2,
       3,     4,     5,     0,     0,     0,     0,     6,     0,     7,
       0,     6,     0,   218,   232,   187,     8,     1,     0,     0,
       8,     0,     1,     2,     3,     4,     5,     1,     2,     3,
       4,     5,     0,     2,     3,     4,     5,   186,   232,   187,
       6,     0,     7,     0,     8,     0,     0,     0,   256,     8
};

static const yytype_int16 yycheck[] =
{
       0,    31,    31,    89,     0,     7,    14,    98,    10,    56,
       8,    11,    41,    42,    70,    15,   116,   126,   107,    15,
     187,    15,    49,    36,    41,    27,     3,     4,    43,    56,
     188,    41,    43,    29,    36,    41,   122,    48,    49,    38,
      57,    70,    55,    36,    40,    55,     9,    10,    11,    12,
      13,     5,     6,    59,    31,    32,   165,    34,    35,    36,
      54,    41,   220,    44,    45,    42,    43,    44,    45,    46,
      47,    36,   239,    38,     3,     4,   162,    57,   125,   179,
      37,    58,    59,    41,   111,   141,   142,   143,   115,    85,
     117,    37,    88,    56,    16,    41,    50,    51,    98,    57,
      22,    23,    24,    25,   131,    39,    37,    41,   107,    38,
      41,    40,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   126,   128,
     157,     7,     8,    12,    37,   191,   225,    34,    41,    36,
     139,     3,     4,   229,    23,   231,    43,   238,    37,    36,
      29,    38,    41,    34,    36,    36,    43,   187,   187,   158,
      57,    40,   191,   165,   250,    34,    35,   165,   164,    31,
      32,    36,    34,    35,    36,    34,   262,    36,   264,    38,
      42,    43,    44,    45,    46,    47,   186,    34,   186,    37,
      37,    16,    34,    41,    36,    36,    58,    22,    23,    24,
      25,    43,    34,   230,    36,    36,    38,    38,    57,   239,
     239,    43,   220,    37,   244,   244,   218,    41,   218,    36,
     218,    38,    23,   223,    25,    36,   225,     3,     4,   144,
     145,    56,    36,    58,   146,   147,   148,   149,   238,    57,
      16,    17,    18,   242,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    36,    34,    35,
      36,    33,   150,   151,    42,    52,    42,    43,    44,    45,
      46,    47,     3,     4,    14,    56,    53,    37,    36,    35,
      39,    57,    58,    59,    37,    16,    17,    18,    34,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    37,    34,    35,    36,     3,     4,    41,    34,
      33,    42,    43,    44,    45,    46,    47,    37,    36,    36,
      17,    18,    35,    20,    21,    37,    57,    58,    59,    26,
      27,    28,    29,    30,    31,    32,    37,    34,    35,    36,
       3,     4,    19,    39,    37,    42,    43,    44,    45,    46,
      47,    39,   152,   155,    17,    18,   153,    20,    21,   154,
      57,    58,    59,    26,    27,    28,    29,    30,    31,    32,
     156,    34,    35,    36,     3,     4,    36,   125,   223,    42,
      43,    44,    45,    46,    47,    88,    -1,    15,    17,    18,
      -1,    20,    21,    -1,    57,    58,    59,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    36,     3,     4,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    57,    58,
      -1,    26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,     3,     4,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    26,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    -1,    -1,     3,     4,
      -1,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    57,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,     3,     4,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    16,    -1,    17,    -1,    -1,    -1,
      22,    23,    24,    25,    -1,    26,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,     3,     4,    -1,
      -1,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    17,    -1,    -1,     3,     4,    58,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,     3,     4,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    31,    32,    -1,    34,    35,    36,     3,     4,
      39,    -1,    -1,    42,    43,    44,    45,    46,    47,    31,
      32,    -1,    34,    35,    36,    37,     3,     4,    -1,    -1,
      42,    43,    44,    45,    46,    47,    31,    32,    -1,    34,
      35,    36,    -1,    -1,    39,     3,     4,    42,    43,    44,
      45,    46,    47,    -1,    31,    32,    -1,    34,    35,    36,
      -1,    -1,    39,     3,     4,    42,    43,    44,    45,    46,
      47,    -1,    -1,    31,    32,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      -1,    31,    32,     0,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    -1,    16,
      -1,    -1,    -1,    16,    -1,    22,    23,    24,    25,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    34,    -1,    36,
      -1,    34,    -1,    36,    37,    38,    43,    16,    -1,    -1,
      43,    -1,    16,    22,    23,    24,    25,    16,    22,    23,
      24,    25,    -1,    22,    23,    24,    25,    36,    37,    38,
      34,    -1,    36,    -1,    43,    -1,    -1,    -1,    37,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    22,    23,    24,    25,    34,    36,    43,    85,
      86,    89,    91,    92,    95,   114,   115,   116,    91,    95,
      57,    87,    88,    91,    86,    58,    85,    86,   107,   108,
      36,    38,    92,     0,   115,    37,    41,    57,    56,   107,
     108,     3,     4,    17,    18,    20,    21,    26,    27,    28,
      29,    30,    31,    32,    34,    35,    36,    42,    43,    44,
      45,    46,    47,    57,    59,    61,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    82,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    91,    85,   107,    34,    93,    94,
      99,    34,    39,    66,    79,    84,    88,    58,    80,   103,
     107,    36,    66,    66,    36,    36,    36,    36,    57,    82,
      57,    57,    55,    33,    82,    89,    90,   100,    36,     3,
       4,    38,    40,     9,    10,    11,    12,    13,    56,    81,
      68,    43,    48,    49,    44,    45,     5,     6,    50,    51,
       7,     8,    42,    52,    53,    14,    15,    54,    41,    57,
      85,    59,   109,    59,   105,    86,    96,    97,    98,    37,
      37,    41,    39,   103,   104,    34,    35,    83,    82,   110,
      82,    57,   105,    35,    37,    90,    36,    38,    95,   101,
     102,    37,    37,    65,    80,    82,    34,    80,    68,    68,
      68,    69,    69,    71,    71,    71,    71,    72,    72,    73,
      74,    75,    76,    77,    82,    80,    59,    85,    36,    91,
      95,   101,    37,    41,    34,    41,    59,    33,    37,    37,
     110,    37,    37,    96,   101,    39,    84,   102,    36,    38,
      68,    37,    41,    39,    55,    98,    59,   103,    35,   105,
      37,    82,   105,    37,    37,    39,    37,    96,    39,    84,
      80,    79,    19,   105,    37,    37,    39,   105,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    82,    82,    82,    82,    83,    83,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    92,    92,
      93,    92,    92,    94,    92,    95,    95,    96,    97,    97,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     106,   107,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   116,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       3,     3,     1,     1,     4,     3,     4,     3,     2,     2,
       1,     3,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     4,     3,     1,     1,     2,     3,
       0,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     3,     4,     3,
       0,     5,     4,     0,     4,     1,     2,     1,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     4,     1,     2,     2,     3,     1,
       2,     5,     7,     5,     6,     7,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     3,     2
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
#line 85 "compiler_hw2.y" /* yacc.c:1646  */
    {
		(yyval.val) = yylval.val;
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(cur_header,(yyval.val).id_name)==-10 && lookup_symbol(tmp,(yyval.val).id_name)==-10)
		{
			int lineno=yylineno+1;
			printf("%d: %s\n", lineno, buf);
			printline_or_not=0;
			char errmsg[64];
        	sprintf(errmsg, "Undeclared variable %s", (yyval.val).id_name);
        	yyerror(errmsg);
		} 
	  }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 112 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=yylval.val;}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "compiler_hw2.y" /* yacc.c:1646  */
    {
		(yyval.val) = (yyvsp[-2].val);
		//printf("function name: %s",$$.id_name);
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(tmp,(yyval.val).id_name)==-10)
		{
			int lineno=yylineno+1;
			printf("%d: %s\n", lineno, buf);
			printline_or_not=0;
			char errmsg[64];
        	sprintf(errmsg, "Undeclared function %s", (yyval.val).id_name);
        	yyerror(errmsg);
		}
	  }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 142 "compiler_hw2.y" /* yacc.c:1646  */
    {
		(yyval.val) = (yyvsp[-3].val);
		//printf("function name: %s",$$.id_name);
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(tmp,(yyval.val).id_name)==-10)
		{
			int lineno=yylineno+1;
			printf("%d: %s\n", lineno, buf);
			printline_or_not=0;
			char errmsg[64];
        	sprintf(errmsg, "Undeclared function %s", (yyval.val).id_name);
        	yyerror(errmsg);
		} 
	  }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 171 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 187 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 192 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 199 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 205 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 209 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 217 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 223 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 228 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 233 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 238 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 243 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 248 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 253 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 255 "compiler_hw2.y" /* yacc.c:1646  */
    {
		/*
		$$=$1;
		Header *tmp=cur_header;
		while(tmp->pre!=NULL)
		{
			tmp=tmp->pre;
		}
		if(lookup_symbol(cur_header,$$.id_name)==-10 && lookup_symbol(tmp,$$.id_name)==-10)
		{
			char errmsg[64];
        	sprintf(errmsg, "Undeclared variable %s", $$.id_name);
        	yyerror(errmsg);
		} 

		$$=$3;
		if(lookup_symbol(cur_header,$$.id_name)==-10 && lookup_symbol(tmp,$$.id_name)==-10)
		{
			char errmsg[64];
        	sprintf(errmsg, "Undeclared variable %s", $$.id_name);
        	yyerror(errmsg);
		} 
		*/
	  }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 301 "compiler_hw2.y" /* yacc.c:1646  */
    {
			Header *tmp=cur_header;
			while(tmp->pre!=NULL)
			{
				tmp=tmp->pre;
			}
			if(lookup_symbol(cur_header,yylval.val.id_name)==-10&&lookup_symbol(tmp,yylval.val.id_name)==-10)
			{
				int lineno=yylineno+1;
				printf("%d: %s\n", lineno, buf);
				printline_or_not=0;
				char errmsg[64];
        		sprintf(errmsg, "Undeclared variable %s", yylval.val.id_name);
        		yyerror(errmsg);
			} 
		}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 325 "compiler_hw2.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-2].val);Value *v2=&(yyvsp[-1].val); insert_symbol(cur_header,v1,v2,"variable");}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 330 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 335 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 340 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 341 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[-2].val);}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 345 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 346 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 347 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 348 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 349 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.val) = yylval.val;/*printf("222");*/ }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 359 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 363 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val) = yylval.val;/*printf("111");*/}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 367 "compiler_hw2.y" /* yacc.c:1646  */
    {new_scope();}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 369 "compiler_hw2.y" /* yacc.c:1646  */
    {new_scope();}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 387 "compiler_hw2.y" /* yacc.c:1646  */
    {Value *v1=&(yyvsp[-1].val);Value *v2=&(yyvsp[0].val); insert_symbol(cur_header,v1,v2,"parameter");}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 421 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.val)=(yyvsp[0].val);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 490 "compiler_hw2.y" /* yacc.c:1646  */
    {dump_scope();}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 496 "compiler_hw2.y" /* yacc.c:1646  */
    { Value *v1=&(yyvsp[-2].val);Value *v2=&(yyvsp[-1].val); insert_symbol_forfun(cur_header,v1,v2,"function");}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1987 "y.tab.c" /* yacc.c:1646  */
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
#line 501 "compiler_hw2.y" /* yacc.c:1906  */


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
	int lineno=yylineno+1;
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", lineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");

	if(strcmp(s,"syntax error")==0)
	{
		exit(1);
	}
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
    if (lookup_symbol(cur_header, id_ptr->id_name) == -10) 
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

		//insert Attribute in previous table
		if(strcmp(kind,"parameter")==0)
		{
			Header* p=cur_header->pre;
			Entry* e=p->table_root;
			if(e!=NULL)
			{
				while(e->next!=NULL)
				{
					e=e->next;
				}
				if(e->index!=-8)
				{
					Entry *t = malloc(sizeof(Entry));
					t->next=NULL;
					t->index=-8; // use to identify that this entry hasn't had function name yet
					strcat(t->Attribute,tmp->type);
					e->next=t;
				}
				else
				{
					strcat(e->Attribute,", ");
					strcat(e->Attribute,tmp->type);
				}
			}
			else
			{
				Entry *t = malloc(sizeof(Entry));
				t->next=NULL;
				t->index=-8; // use to identify that this entry hasn't had function name yet
				strcat(t->Attribute,tmp->type);
				p->table_root=t;
			}
			
		}
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        int lineno=yylineno+1;
		printf("%d: %s\n", lineno, buf);
		printline_or_not=0;
		char errmsg[64];
        sprintf(errmsg, "Redeclared variable %s", id_ptr->id_name);
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
    if (lookup_symbol(cur_header->pre, id_ptr->id_name) == -10) 
	{
        if(table_or_not==1)
		{
			header=header->pre;
		}
        Entry *tmp = malloc(sizeof(Entry));
		header->entry_num=(header->entry_num)+1;
        tmp->index = header->entry_num;
		
        tmp->id_ptr = id_ptr_copy;
		//printf("Insert a function: %s in table %d,INDEX: %d\n", tmp->id_ptr->id_name, header->depth,tmp->index);
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

		//要去檢查前一個table的最後一個entry是不是有Attribute存在,如果有,則直接使用該entry,若無,則須創新的entry
		if(cur_header->pre!=NULL&&cur_header->pre->table_root!=NULL) 
		{
			//printf("7777777\n");
			Entry *tr=cur_header->pre->table_root;
			//printf("17171717\n");
			while(tr->next!=NULL)
			{
				//printf("767676\n");
				tr=tr->next;
			}
			
			if(strcmp(tr->Attribute,"")!=0&&tr->index==-8) //有Attribute存在
			{
				
				//printf("88888888\n");
				tr->index=tmp->index;
				tr->id_ptr=tmp->id_ptr;
				strcpy(tr->Kind,tmp->Kind);
				strcat(tr->type,tmp->type);
				tr->Scope=tmp->Scope;
			}
			else //無Attribute存在
			{
				//printf("999999\n");
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
		}
		else
		{
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
		
    } 
	else 
	{
		//printf("lookup_symbol=%d\n",lookup_symbol(cur_header, id_ptr->id_name));
        int lineno=yylineno+1;
		printf("%d: %s\n", lineno, buf);
		printline_or_not=0;
		char errmsg[64];
        sprintf(errmsg, "Redeclared function %s", id_ptr->id_name);
        yyerror(errmsg);
    }
}
int lookup_symbol(const Header *header, const char *id) 
{
	if (header->table_root == NULL) 
	{
		//printf("NULLLLLLLL\n");
        return -10;
    }
    Entry *cur = header->table_root;
    while (cur != NULL)
	{
		/*
		printf("\nindex:%d\n",cur->index);
		printf("%s\n",id);
		if(cur->id_ptr!=NULL)
			printf("%s\n",cur->id_ptr->id_name);
		*/

        if (cur->id_ptr!=NULL&&strcmp(cur->id_ptr->id_name, id) == 0)
		{
            return cur->index;
        }
        cur = cur->next;
    }
    return -10;
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
