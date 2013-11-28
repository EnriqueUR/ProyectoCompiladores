/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "decaf_grammar.y"


#include <stdio.h>
#include "tree.h"
#include "Value.h"
#include "decaf_tokens.h"

#define YYERROR_VERBOSE 1

extern ClassDef *class_def;

int yylex(YYSTYPE*, YYLTYPE*);
void yyerror(const char *message);

VariableDefList *SetType(VariableDefList *list, Type type)
{
	VariableDefList::iterator it = list->begin();

	while (it != list->end()) {
		VariableDef *var = *it;

		var->variable_type = type;
		it++;
	}

	return list;
}



/* Line 268 of yacc.c  */
#line 102 "decaf_grammar.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     K_CLASS = 259,
     K_BREAK = 260,
     K_CONTINUE = 261,
     K_WHILE = 262,
     K_FOR = 263,
     K_IF = 264,
     K_ELSE = 265,
     K_RETURN = 266,
     K_READ = 267,
     K_PRINT = 268,
     K_TRUE = 269,
     K_FALSE = 270,
     K_INT = 271,
     K_VOID = 272,
     K_BOOLEAN = 273,
     OR = 274,
     AND = 275,
     SHIFT_LEFT = 276,
     SHIFT_RIGHT = 277,
     ROT = 278,
     BIGER_THAN = 279,
     LESS_THAN = 280,
     BIGER_THAN_EQUAL = 281,
     LESS_THAN_EQUAL = 282,
     EQUAL = 283,
     NOT_EQUAL = 284,
     ADD = 285,
     SUB = 286,
     MULT = 287,
     DIV = 288,
     MOD = 289,
     CHAR_CONSTANT = 290,
     INT_CONSTANT = 291,
     REAL_CONSTANT = 292,
     STRING_CONSTANT = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 31 "decaf_grammar.y"

	Expression		*expression;
	Statement		*statement;
	BlockStatement		*blockStatement;
	VariableDef		*variable_def;
	MethodDef		*method_def;
	ParameterDef		*parameter_def;
	ParameterDefList	*parameter_def_list;
	VariableDefList		*variable_def_list;
	StatementList		*statement_list;
	MethodDefList		*method_def_list;
	ClassDef		*class_def;
	Type 			type;
	ExpressionOperator	oper;
	ExpressionList		*expression_list;
	Constant		*constant;
	LValueExpression	*lvalueExpression;
	char			*string;
	int			integer;
	bool			boolean;



/* Line 293 of yacc.c  */
#line 200 "decaf_grammar.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 225 "decaf_grammar.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    12,    14,    15,    17,    18,    21,
      23,    26,    28,    30,    34,    38,    40,    43,    48,    51,
      52,    59,    61,    63,    65,    66,    70,    72,    75,    79,
      81,    82,    84,    86,    89,    91,    94,    97,    99,   101,
     103,   106,   109,   112,   114,   118,   123,   126,   129,   131,
     133,   134,   138,   140,   144,   146,   148,   150,   154,   156,
     159,   163,   164,   171,   174,   175,   181,   191,   195,   197,
     200,   202,   204,   206,   207,   211,   213,   217,   219,   223,
     227,   231,   235,   239,   243,   245,   249,   253,   257,   259,
     263,   267,   269,   273,   277,   281,   283,   286,   288,   293,
     295,   299,   301,   303,   305,   307
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,     4,    56,    39,    52,    53,
      40,    -1,    54,    -1,    -1,    55,    -1,    -1,    54,    57,
      -1,    57,    -1,    55,    61,    -1,    61,    -1,     3,    -1,
      68,    58,    41,    -1,    58,    42,    59,    -1,    59,    -1,
       3,    60,    -1,     3,    43,    36,    44,    -1,    45,    97,
      -1,    -1,    62,     3,    46,    63,    47,    66,    -1,    68,
      -1,    17,    -1,    64,    -1,    -1,    64,    42,    65,    -1,
      65,    -1,    68,     3,    -1,    39,    67,    40,    -1,    69,
      -1,    -1,    16,    -1,    18,    -1,    69,    70,    -1,    70,
      -1,    71,    41,    -1,    72,    41,    -1,    81,    -1,    83,
      -1,    84,    -1,    86,    41,    -1,    87,    41,    -1,    88,
      41,    -1,    66,    -1,    79,    45,    90,    -1,    73,    46,
      74,    47,    -1,    13,    76,    -1,    12,    78,    -1,     3,
      -1,    75,    -1,    -1,    75,    42,    90,    -1,    90,    -1,
      76,    42,    77,    -1,    77,    -1,    38,    -1,    90,    -1,
      78,    42,    79,    -1,    79,    -1,     3,    80,    -1,    43,
      90,    44,    -1,    -1,     9,    46,    90,    47,    66,    82,
      -1,    10,    66,    -1,    -1,     7,    46,    90,    47,    66,
      -1,     8,    46,    85,    41,    90,    41,    85,    47,    66,
      -1,    85,    42,    71,    -1,    71,    -1,    11,    89,    -1,
       5,    -1,     6,    -1,    90,    -1,    -1,    90,    19,    91,
      -1,    91,    -1,    91,    20,    92,    -1,    92,    -1,    92,
      24,    93,    -1,    92,    25,    93,    -1,    92,    26,    93,
      -1,    92,    27,    93,    -1,    92,    28,    93,    -1,    92,
      29,    93,    -1,    93,    -1,    93,    21,    94,    -1,    93,
      22,    94,    -1,    93,    23,    94,    -1,    94,    -1,    94,
      30,    95,    -1,    94,    31,    95,    -1,    95,    -1,    95,
      32,    96,    -1,    95,    33,    96,    -1,    95,    34,    96,
      -1,    96,    -1,    48,    96,    -1,    79,    -1,    73,    46,
      74,    47,    -1,    97,    -1,    46,    90,    47,    -1,    36,
      -1,    35,    -1,    98,    -1,    14,    -1,    15,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   129,   134,   135,   139,   140,   144,   145,
     149,   150,   154,   158,   162,   163,   169,   174,   182,   183,
     188,   198,   199,   203,   204,   208,   212,   219,   223,   230,
     231,   235,   236,   240,   241,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   257,   261,   262,   263,   267,   271,
     272,   276,   277,   281,   282,   286,   287,   291,   292,   296,
     300,   301,   305,   309,   310,   314,   318,   323,   324,   328,
     332,   336,   340,   341,   345,   346,   349,   350,   354,   355,
     356,   357,   358,   359,   360,   364,   365,   366,   367,   371,
     372,   373,   376,   377,   378,   379,   383,   384,   385,   386,
     387,   390,   391,   392,   396,   397
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"'identificador'\"", "\"'class'\"",
  "\"'break'\"", "\"'continue'\"", "\"'while'\"", "\"'for'\"", "\"'if'\"",
  "\"'else'\"", "\"'return'\"", "\"'read'\"", "\"'print'\"", "\"'true'\"",
  "\"'false'\"", "\"'int'\"", "\"'void'\"", "\"'boolean'\"",
  "\"operador booleano 'or'\"", "\"operador booleano 'and'\"", "\"<<\"",
  "\">>\"", "\"rot\"", "\">\"", "\"<\"", "\">=\"", "\"<=\"", "\"==\"",
  "\"!=\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"",
  "\"constante caracter\"", "\"constante entera\"", "\"constante real\"",
  "\"constante de cadena\"", "'{'", "'}'", "';'", "','", "'['", "']'",
  "'='", "'('", "')'", "'!'", "$accept", "program", "class_def",
  "optional_field_decl_list", "optional_method_decl_list",
  "field_decl_list", "method_decl_list", "class_name", "field_decl",
  "var_list", "var", "optional_initialization", "method_decl",
  "return_type", "opt_parameter_decl_list", "parameter_decl_list",
  "parameter_decl", "block", "opt_statement_list", "type",
  "statement_list", "statement", "assign", "method_call", "method_name",
  "opt_method_call_argument_list", "method_call_argument_list",
  "print_argument_list", "print_argument", "read_argument_list", "lvalue",
  "opt_array_dimension", "if_statement", "opt_else", "while_statement",
  "for_statement", "for_assignment_list", "return_statement",
  "break_statement", "continue_statement", "opt_expr", "expr", "bool_term",
  "relational_expr", "bit_shift_expr", "arith_expr", "arith_term",
  "factor", "constant", "bool_constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   123,
     125,    59,    44,    91,    93,    61,    40,    41,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    63,    64,    64,    65,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    72,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      80,    80,    81,    82,    82,    83,    84,    85,    85,    86,
      87,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    94,
      94,    94,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    97,    97,    97,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     1,     0,     1,     0,     2,     1,
       2,     1,     1,     3,     3,     1,     2,     4,     2,     0,
       6,     1,     1,     1,     0,     3,     1,     2,     3,     1,
       0,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       2,     2,     2,     1,     3,     4,     2,     2,     1,     1,
       0,     3,     1,     3,     1,     1,     1,     3,     1,     2,
       3,     0,     6,     2,     0,     5,     9,     3,     1,     2,
       1,     1,     1,     0,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     1,     4,     1,
       3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,    12,     0,     1,     5,    31,    32,
       7,     4,     9,     0,    22,     0,     6,    11,     0,    21,
       8,    19,     0,    15,     3,    10,     0,     0,     0,    16,
      13,     0,    24,     0,   104,   105,   102,   101,    18,   103,
      14,     0,    23,    26,     0,    17,     0,     0,    27,    30,
      20,    25,    61,    70,    71,     0,     0,     0,    73,     0,
       0,    43,     0,    29,    34,     0,     0,     0,     0,    37,
      38,    39,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,    97,    69,    72,    75,    77,    84,    88,
      91,    95,    99,    61,    47,    58,    55,    46,    54,    56,
      28,    33,    35,    36,    50,     0,    40,    41,    42,     0,
       0,    68,     0,     0,     0,    96,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    52,    44,    60,
       0,     0,     0,     0,   100,     0,    74,    76,    78,    79,
      80,    81,    82,    83,    85,    86,    87,    89,    90,    92,
      93,    94,    57,    53,    45,     0,    65,     0,    67,    64,
      98,    51,     0,     0,    62,     0,    63,     0,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    15,    11,    16,     5,    12,    22,
      23,    29,    17,    18,    41,    42,    43,    61,    62,    13,
      63,    64,    65,    66,    82,   135,   136,    97,    98,    94,
      83,    76,    69,   174,    70,    71,   112,    72,    73,    74,
      84,    99,    86,    87,    88,    89,    90,    91,    92,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
      17,    23,    33,   -79,   -79,     4,   -79,    -1,   -79,   -79,
      64,    -1,   -79,    46,   -79,    27,    64,   -79,    54,   -79,
     -79,    21,    -4,   -79,   -79,   -79,    26,    47,    15,   -79,
     -79,    46,    -1,    41,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,    49,    51,   -79,    99,   -79,    82,    -1,   -79,    98,
     -79,   -79,    19,   -79,   -79,    78,    80,    84,    10,   125,
      25,   -79,    89,    98,   -79,    92,    93,    86,    90,   -79,
     -79,   -79,    95,    97,   100,    10,   -79,    10,   125,    10,
      10,    10,    94,   -79,   -79,   120,   122,    50,    91,    39,
      83,   -79,   -79,   101,   103,   -79,   -79,   104,   -79,   120,
     -79,   -79,   -79,   -79,    10,    10,   -79,   -79,   -79,     0,
     -13,   -79,    58,   -12,   -11,   -79,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,   125,    25,    96,   105,   120,   120,   -79,
      82,    10,   125,    82,   -79,   102,   122,    50,    91,    91,
      91,    91,    91,    91,    39,    39,    39,    83,    83,   -79,
     -79,   -79,   -79,   -79,   -79,    10,   -79,    -9,   -79,   138,
     -79,   120,   125,    82,   -79,   -33,   -79,    82,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   139,   -79,
     121,   -79,   135,   -79,   -79,   -79,   106,   -46,   -79,    -5,
     -79,   107,   -74,   -79,    -8,    38,   -79,   -79,    22,   -79,
     -47,   -79,   -79,   -79,   -79,   -79,   -17,   -79,   -79,   -79,
     -79,   -57,    40,    42,   -32,    -7,    -6,   -78,   130,   -79
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      50,    85,    68,   115,   111,    19,   117,   117,   117,   142,
     117,    19,    95,    52,   177,     8,    68,     9,   109,   117,
     110,     1,   113,   114,    34,    35,     4,    44,    52,    34,
      35,    68,   172,     6,   140,   143,   144,    30,    31,    34,
      35,    67,    44,     7,   139,    36,    37,   137,   138,    21,
      36,    37,   159,   160,   161,    67,    80,    26,    81,   137,
      36,    37,    75,    96,    27,   -48,    28,    24,   168,   128,
     129,    80,    32,    81,   119,   120,   121,   122,   123,   124,
       8,    14,     9,    33,   167,    45,   162,   148,   149,   150,
     151,   152,   153,    47,   166,    68,    46,   169,   111,   141,
     142,    52,    48,    53,    54,    55,    56,    57,   171,    58,
      59,    60,   125,   126,   127,   130,   131,   132,   154,   155,
     156,    49,   157,   158,    77,    68,    78,   176,    93,   100,
      79,   178,   104,   102,   103,   105,   106,    49,   107,   117,
     116,   108,   118,   164,    75,   133,   134,   165,   173,   170,
      20,    25,    40,    51,   145,   175,   163,   146,    38,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-79))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      46,    58,    49,    81,    78,    10,    19,    19,    19,    42,
      19,    16,    59,     3,    47,    16,    63,    18,    75,    19,
      77,     4,    79,    80,    14,    15,     3,    32,     3,    14,
      15,    78,    41,     0,    47,    47,    47,    41,    42,    14,
      15,    49,    47,    39,    44,    35,    36,   104,   105,     3,
      35,    36,   130,   131,   132,    63,    46,     3,    48,   116,
      35,    36,    43,    38,    43,    46,    45,    40,   142,    30,
      31,    46,    46,    48,    24,    25,    26,    27,    28,    29,
      16,    17,    18,    36,   141,    44,   133,   119,   120,   121,
     122,   123,   124,    42,   140,   142,    47,   143,   172,    41,
      42,     3,     3,     5,     6,     7,     8,     9,   165,    11,
      12,    13,    21,    22,    23,    32,    33,    34,   125,   126,
     127,    39,   128,   129,    46,   172,    46,   173,     3,    40,
      46,   177,    46,    41,    41,    45,    41,    39,    41,    19,
      46,    41,    20,    47,    43,    42,    42,    42,    10,    47,
      11,    16,    31,    47,   116,   172,   134,   117,    28,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    50,    51,     3,    56,     0,    39,    16,    18,
      52,    54,    57,    68,    17,    53,    55,    61,    62,    68,
      57,     3,    58,    59,    40,    61,     3,    43,    45,    60,
      41,    42,    46,    36,    14,    15,    35,    36,    97,    98,
      59,    63,    64,    65,    68,    44,    47,    42,     3,    39,
      66,    65,     3,     5,     6,     7,     8,     9,    11,    12,
      13,    66,    67,    69,    70,    71,    72,    73,    79,    81,
      83,    84,    86,    87,    88,    43,    80,    46,    46,    46,
      46,    48,    73,    79,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     3,    78,    79,    38,    76,    77,    90,
      40,    70,    41,    41,    46,    45,    41,    41,    41,    90,
      90,    71,    85,    90,    90,    96,    46,    19,    20,    24,
      25,    26,    27,    28,    29,    21,    22,    23,    30,    31,
      32,    33,    34,    42,    42,    74,    75,    90,    90,    44,
      47,    41,    42,    47,    47,    74,    91,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    96,    79,    77,    47,    42,    66,    90,    71,    66,
      47,    90,    41,    10,    82,    85,    66,    47,    66
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 125 "decaf_grammar.y"
    { class_def = (yyvsp[(1) - (1)].class_def); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 130 "decaf_grammar.y"
    { (yyval.class_def) = new ClassDef((yyvsp[(2) - (6)].string), (yyvsp[(4) - (6)].variable_def_list), (yyvsp[(5) - (6)].method_def_list)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 134 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (1)].variable_def_list); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 135 "decaf_grammar.y"
    { (yyval.variable_def_list) = 0; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 139 "decaf_grammar.y"
    { (yyval.method_def_list) = (yyvsp[(1) - (1)].method_def_list); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 140 "decaf_grammar.y"
    { (yyval.method_def_list) = 0; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 144 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (2)].variable_def_list); (yyval.variable_def_list)->insert((yyval.variable_def_list)->end(), (yyvsp[(2) - (2)].variable_def_list)->begin(), (yyvsp[(2) - (2)].variable_def_list)->end()); delete (yyvsp[(2) - (2)].variable_def_list);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 145 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (1)].variable_def_list); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 149 "decaf_grammar.y"
    { (yyval.method_def_list) = (yyvsp[(1) - (2)].method_def_list); (yyval.method_def_list)->push_back((yyvsp[(2) - (2)].method_def)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 150 "decaf_grammar.y"
    { (yyval.method_def_list) = new MethodDefList(); (yyval.method_def_list)->push_back((yyvsp[(1) - (1)].method_def)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 154 "decaf_grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 158 "decaf_grammar.y"
    { (yyval.variable_def_list) = SetType((yyvsp[(2) - (3)].variable_def_list), (yyvsp[(1) - (3)].type)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 162 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (3)].variable_def_list); (yyval.variable_def_list)->push_back((yyvsp[(3) - (3)].variable_def)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 163 "decaf_grammar.y"
    { 
						(yyval.variable_def_list) = new VariableDefList;
						(yyval.variable_def_list)->push_back((yyvsp[(1) - (1)].variable_def));
					}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 169 "decaf_grammar.y"
    { 
							(yyval.variable_def) = new VariableDef((yyvsp[(1) - (2)].string), (yylsp[(1) - (2)]).last_line, (yylsp[(1) - (2)]).first_column);
							(yyval.variable_def)->initial_value = (yyvsp[(2) - (2)].expression);
						}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 174 "decaf_grammar.y"
    { 
							(yyval.variable_def) = new VariableDef((yyvsp[(1) - (4)].string), (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).first_column); 
							(yyval.variable_def)->isArrayDef = true;
							(yyval.variable_def)->array_dimension = (yyvsp[(3) - (4)].integer);
						}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 182 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(2) - (2)].expression); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 183 "decaf_grammar.y"
    { (yyval.expression) = 0; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 189 "decaf_grammar.y"
    {
			(yyval.method_def) = new MethodDef((yyvsp[(2) - (6)].string)); 
			(yyval.method_def)->returnType = (yyvsp[(1) - (6)].type);
			(yyval.method_def)->parameters = (yyvsp[(4) - (6)].parameter_def_list);
			(yyval.method_def)->block =  (yyvsp[(6) - (6)].blockStatement);
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 198 "decaf_grammar.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 199 "decaf_grammar.y"
    { (yyval.type) = Void; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 203 "decaf_grammar.y"
    { (yyval.parameter_def_list) = (yyvsp[(1) - (1)].parameter_def_list); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 204 "decaf_grammar.y"
    { (yyval.parameter_def_list) = 0; }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 208 "decaf_grammar.y"
    {
									(yyval.parameter_def_list) = (yyvsp[(1) - (3)].parameter_def_list);
									(yyval.parameter_def_list)->push_back((yyvsp[(3) - (3)].parameter_def));
								}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 212 "decaf_grammar.y"
    { 
									(yyval.parameter_def_list) = new ParameterDefList();
									(yyval.parameter_def_list)->push_back((yyvsp[(1) - (1)].parameter_def));
								}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 219 "decaf_grammar.y"
    { (yyval.parameter_def) = new ParameterDef((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].type)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 224 "decaf_grammar.y"
    { 
		  (yyval.blockStatement) = new BlockStatement((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
		  (yyval.blockStatement)->listStatements = (yyvsp[(2) - (3)].statement_list);
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 230 "decaf_grammar.y"
    { (yyval.statement_list) = (yyvsp[(1) - (1)].statement_list); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 231 "decaf_grammar.y"
    { (yyval.statement_list) = 0; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 235 "decaf_grammar.y"
    { (yyval.type) = Int; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 236 "decaf_grammar.y"
    { (yyval.type) = Boolean; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 240 "decaf_grammar.y"
    { (yyval.statement_list) = (yyvsp[(1) - (2)].statement_list); (yyval.statement_list)->push_back((yyvsp[(2) - (2)].statement)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 241 "decaf_grammar.y"
    { (yyval.statement_list) = new StatementList(); (yyval.statement_list)->push_back((yyvsp[(1) - (1)].statement)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 245 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 246 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 247 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 248 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 249 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 250 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 251 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 252 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 253 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].blockStatement); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 257 "decaf_grammar.y"
    { (yyval.statement) = new AssignStatement((yyvsp[(1) - (3)].lvalueExpression), (yyvsp[(3) - (3)].expression), (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 261 "decaf_grammar.y"
    { (yyval.statement) = new MethodCallStatement((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].expression_list), (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 262 "decaf_grammar.y"
    { (yyval.statement) = new PrintStatement((yyvsp[(2) - (2)].expression_list), (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 263 "decaf_grammar.y"
    { (yyval.statement) = new ReadStatement((yyvsp[(2) - (2)].expression_list), (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 267 "decaf_grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 271 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (1)].expression_list); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 272 "decaf_grammar.y"
    { (yyval.expression_list) = 0; }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 276 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); (yyval.expression_list)->push_back((yyvsp[(3) - (3)].expression)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 277 "decaf_grammar.y"
    { (yyval.expression_list) = new ExpressionList(); (yyval.expression_list)->push_back((yyvsp[(1) - (1)].expression)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 281 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); (yyval.expression_list)->push_back((yyvsp[(3) - (3)].expression)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 282 "decaf_grammar.y"
    { (yyval.expression_list) = new ExpressionList(); (yyval.expression_list)->push_back((yyvsp[(1) - (1)].expression)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 286 "decaf_grammar.y"
    { (yyval.expression) = new ConstantStringExpression((yyvsp[(1) - (1)].string)); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 287 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 291 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); (yyval.expression_list)->push_back((yyvsp[(3) - (3)].lvalueExpression)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 292 "decaf_grammar.y"
    { (yyval.expression_list) = new ExpressionList(); (yyval.expression_list)->push_back((yyvsp[(1) - (1)].lvalueExpression)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 296 "decaf_grammar.y"
    { (yyval.lvalueExpression) = new LValueExpression((yyvsp[(1) - (2)].string)); (yyval.lvalueExpression)->expr = (yyvsp[(2) - (2)].expression); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 300 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 301 "decaf_grammar.y"
    { (yyval.expression) = 0; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 305 "decaf_grammar.y"
    { (yyval.statement) = new IfStatement((yyvsp[(3) - (6)].expression), (yyvsp[(5) - (6)].blockStatement), (yyvsp[(6) - (6)].statement), (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 309 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(2) - (2)].blockStatement); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 310 "decaf_grammar.y"
    { (yyval.statement) = 0; }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 314 "decaf_grammar.y"
    { (yyval.statement) = new WhileStatement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].blockStatement), (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 319 "decaf_grammar.y"
    { (yyval.statement) = new ForStatement((yyvsp[(3) - (9)].statement), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].statement), (yyvsp[(9) - (9)].blockStatement), (yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 323 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (3)].statement); ((BlockStatement*)(yyval.statement))->AddStatement((yyvsp[(3) - (3)].statement)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 324 "decaf_grammar.y"
    { (yyval.statement) = new BlockStatement((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 328 "decaf_grammar.y"
    { (yyval.statement) = new ReturnStatement((yyvsp[(2) - (2)].expression), (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 332 "decaf_grammar.y"
    { (yyval.statement) = new BreakStatement((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 336 "decaf_grammar.y"
    { (yyval.statement) = new ContinueStatement((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 340 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 341 "decaf_grammar.y"
    { (yyval.expression) = 0; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 345 "decaf_grammar.y"
    { (yyval.expression) = new OrExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 346 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 349 "decaf_grammar.y"
    { (yyval.expression) = new AndExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 350 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 354 "decaf_grammar.y"
    { (yyval.expression) = new BigerThanExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 355 "decaf_grammar.y"
    { (yyval.expression) = new LessThanExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 356 "decaf_grammar.y"
    { (yyval.expression) = new BigerThanEqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 357 "decaf_grammar.y"
    { (yyval.expression) = new LessThanEqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 358 "decaf_grammar.y"
    { (yyval.expression) = new EqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 359 "decaf_grammar.y"
    { (yyval.expression) = new NotEqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 360 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 364 "decaf_grammar.y"
    { (yyval.expression) = new ShiftLeftExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 365 "decaf_grammar.y"
    { (yyval.expression) = new ShiftRightExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 366 "decaf_grammar.y"
    { (yyval.expression) = new RotExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 367 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 371 "decaf_grammar.y"
    { (yyval.expression) = new AddExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 372 "decaf_grammar.y"
    { (yyval.expression) = new SubExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 373 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 376 "decaf_grammar.y"
    { (yyval.expression) = new MultExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 377 "decaf_grammar.y"
    { (yyval.expression) = new DivExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 378 "decaf_grammar.y"
    { (yyval.expression) = new ModExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 379 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 383 "decaf_grammar.y"
    { (yyval.expression) = new NotExpression((yyvsp[(2) - (2)].expression)); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 384 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].lvalueExpression); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 385 "decaf_grammar.y"
    { (yyval.expression) = new MethodCallExpression((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].expression_list)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 386 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 387 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 390 "decaf_grammar.y"
    { (yyval.expression) = new ConstantIntExpression((yyvsp[(1) - (1)].integer)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 391 "decaf_grammar.y"
    { (yyval.expression) = new ConstantCharExpression((yyvsp[(1) - (1)].integer)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 392 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 396 "decaf_grammar.y"
    { (yyval.expression) = new ConstantBoolExpression(true); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 397 "decaf_grammar.y"
    { (yyval.expression) = new ConstantBoolExpression(false); }
    break;



/* Line 1806 of yacc.c  */
#line 2423 "decaf_grammar.cpp"
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
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


