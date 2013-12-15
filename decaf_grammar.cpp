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
#line 201 "decaf_grammar.cpp"
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
#line 226 "decaf_grammar.cpp"

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
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

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
      81,    82,    84,    86,    89,    91,    94,    97,   100,   102,
     104,   106,   109,   112,   115,   117,   120,   124,   126,   128,
     132,   137,   140,   143,   145,   147,   148,   152,   154,   158,
     160,   162,   164,   168,   170,   173,   177,   178,   185,   188,
     189,   195,   205,   209,   211,   214,   216,   218,   220,   221,
     225,   227,   231,   233,   237,   241,   245,   249,   253,   257,
     259,   263,   267,   271,   273,   277,   281,   283,   287,   291,
     295,   297,   300,   302,   307,   309,   313,   315,   317,   319,
     321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,     4,    56,    39,    52,    53,
      40,    -1,    54,    -1,    -1,    55,    -1,    -1,    54,    57,
      -1,    57,    -1,    55,    61,    -1,    61,    -1,     3,    -1,
      68,    58,    41,    -1,    58,    42,    59,    -1,    59,    -1,
       3,    60,    -1,     3,    43,    36,    44,    -1,    45,   100,
      -1,    -1,    62,     3,    46,    63,    47,    66,    -1,    68,
      -1,    17,    -1,    64,    -1,    -1,    64,    42,    65,    -1,
      65,    -1,    68,     3,    -1,    39,    67,    40,    -1,    69,
      -1,    -1,    16,    -1,    18,    -1,    69,    70,    -1,    70,
      -1,    74,    41,    -1,    71,    41,    -1,    75,    41,    -1,
      84,    -1,    86,    -1,    87,    -1,    89,    41,    -1,    90,
      41,    -1,    91,    41,    -1,    66,    -1,    68,    72,    -1,
      72,    42,    73,    -1,    73,    -1,     3,    -1,    82,    45,
      93,    -1,    76,    46,    77,    47,    -1,    13,    79,    -1,
      12,    81,    -1,     3,    -1,    78,    -1,    -1,    78,    42,
      93,    -1,    93,    -1,    79,    42,    80,    -1,    80,    -1,
      38,    -1,    93,    -1,    81,    42,    82,    -1,    82,    -1,
       3,    83,    -1,    43,    93,    44,    -1,    -1,     9,    46,
      93,    47,    66,    85,    -1,    10,    66,    -1,    -1,     7,
      46,    93,    47,    66,    -1,     8,    46,    88,    41,    93,
      41,    88,    47,    66,    -1,    88,    42,    74,    -1,    74,
      -1,    11,    92,    -1,     5,    -1,     6,    -1,    93,    -1,
      -1,    93,    19,    94,    -1,    94,    -1,    94,    20,    95,
      -1,    95,    -1,    95,    24,    96,    -1,    95,    25,    96,
      -1,    95,    26,    96,    -1,    95,    27,    96,    -1,    95,
      28,    96,    -1,    95,    29,    96,    -1,    96,    -1,    96,
      21,    97,    -1,    96,    22,    97,    -1,    96,    23,    97,
      -1,    97,    -1,    97,    30,    98,    -1,    97,    31,    98,
      -1,    98,    -1,    98,    32,    99,    -1,    98,    33,    99,
      -1,    98,    34,    99,    -1,    99,    -1,    48,    99,    -1,
      82,    -1,    76,    46,    77,    47,    -1,   100,    -1,    46,
      93,    47,    -1,    36,    -1,    35,    -1,   101,    -1,    14,
      -1,    15,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   131,   136,   137,   141,   142,   146,   147,
     151,   152,   156,   160,   164,   165,   171,   176,   184,   185,
     190,   200,   201,   205,   206,   210,   214,   221,   225,   232,
     233,   237,   238,   242,   243,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   260,   263,   264,   270,   275,
     279,   280,   281,   285,   289,   290,   294,   295,   299,   300,
     304,   305,   309,   310,   314,   318,   319,   323,   327,   328,
     332,   336,   341,   342,   347,   351,   355,   359,   360,   364,
     365,   368,   369,   373,   374,   375,   376,   377,   378,   379,
     383,   384,   385,   386,   390,   391,   392,   395,   396,   397,
     398,   402,   403,   404,   405,   406,   409,   410,   411,   415,
     416
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
  "statement_list", "statement", "local_variable_decl",
  "local_variable_list", "local_variable", "assign", "method_call",
  "method_name", "opt_method_call_argument_list",
  "method_call_argument_list", "print_argument_list", "print_argument",
  "read_argument_list", "lvalue", "opt_array_dimension", "if_statement",
  "opt_else", "while_statement", "for_statement", "for_assignment_list",
  "return_statement", "break_statement", "continue_statement", "opt_expr",
  "expr", "bool_term", "relational_expr", "bit_shift_expr", "arith_expr",
  "arith_term", "factor", "constant", "bool_constant", 0
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
      70,    70,    70,    70,    70,    71,    72,    72,    73,    74,
      75,    75,    75,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    83,    83,    84,    85,    85,
      86,    87,    88,    88,    89,    90,    91,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    97,    97,    97,    98,    98,    98,
      98,    99,    99,    99,    99,    99,   100,   100,   100,   101,
     101
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     1,     0,     1,     0,     2,     1,
       2,     1,     1,     3,     3,     1,     2,     4,     2,     0,
       6,     1,     1,     1,     0,     3,     1,     2,     3,     1,
       0,     1,     1,     2,     1,     2,     2,     2,     1,     1,
       1,     2,     2,     2,     1,     2,     3,     1,     1,     3,
       4,     2,     2,     1,     1,     0,     3,     1,     3,     1,
       1,     1,     3,     1,     2,     3,     0,     6,     2,     0,
       5,     9,     3,     1,     2,     1,     1,     1,     0,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     1,     4,     1,     3,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,    12,     0,     1,     5,    31,    32,
       7,     4,     9,     0,    22,     0,     6,    11,     0,    21,
       8,    19,     0,    15,     3,    10,     0,     0,     0,    16,
      13,     0,    24,     0,   109,   110,   107,   106,    18,   108,
      14,     0,    23,    26,     0,    17,     0,     0,    27,    30,
      20,    25,    66,    75,    76,     0,     0,     0,    78,     0,
       0,    44,     0,     0,    29,    34,     0,     0,     0,     0,
       0,    38,    39,    40,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,   102,    74,    77,    80,    82,
      89,    93,    96,   100,   104,    66,    52,    63,    60,    51,
      59,    61,    28,    48,    45,    47,    33,    36,    35,    37,
      55,     0,    41,    42,    43,     0,     0,    73,     0,     0,
       0,   101,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    57,    49,    65,     0,     0,     0,
       0,   105,     0,    79,    81,    83,    84,    85,    86,    87,
      88,    90,    91,    92,    94,    95,    97,    98,    99,    62,
      58,    46,    50,     0,    70,     0,    72,    69,   103,    56,
       0,     0,    67,     0,    68,     0,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    15,    11,    16,     5,    12,    22,
      23,    29,    17,    18,    41,    42,    43,    61,    62,    13,
      64,    65,    66,   104,   105,    67,    68,    84,   142,   143,
      99,   100,    96,    85,    78,    71,   182,    72,    73,   118,
      74,    75,    76,    86,   101,    88,    89,    90,    91,    92,
      93,    94,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
      37,    18,    45,   -80,   -80,    36,   -80,    10,   -80,   -80,
      34,    10,   -80,    64,   -80,    38,    34,   -80,    70,   -80,
     -80,    17,   -27,   -80,   -80,   -80,    31,    44,     4,   -80,
     -80,    64,    10,    62,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,    65,    75,   -80,   116,   -80,    88,    10,   -80,   102,
     -80,   -80,   -11,   -80,   -80,    82,    83,    84,    33,   128,
      28,   -80,    92,   131,   102,   -80,    95,    96,    97,    94,
      98,   -80,   -80,   -80,   101,   103,   104,    33,   -80,    33,
     128,    33,    33,    33,   100,   -80,   -80,   129,   127,    58,
      67,    25,    89,   -80,   -80,   106,   108,   -80,   -80,   109,
     -80,   129,   -80,   -80,   110,   -80,   -80,   -80,   -80,   -80,
      33,    33,   -80,   -80,   -80,   -14,   -13,   -80,    29,   -10,
      -9,   -80,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,   128,
      28,   131,   107,   111,   129,   129,   -80,    88,    33,   128,
      88,   -80,   112,   127,    58,    67,    67,    67,    67,    67,
      67,    25,    25,    25,    89,    89,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,    33,   -80,     8,   -80,   145,   -80,   129,
     128,    88,   -80,   -31,   -80,    88,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   146,   -80,
     125,   -80,   142,   -80,   -80,   -80,   113,   -46,   -80,    -3,
     -80,    99,   -80,   -80,    20,   -77,   -80,   -41,    40,   -80,
     -80,    24,   -80,   -47,   -80,   -80,   -80,   -80,   -80,   -15,
     -80,   -80,   -80,   -80,   -57,    43,    46,   -32,    -7,   -35,
     -79,   139,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -54
static const yytype_int16 yytable[] =
{
      50,    87,    70,   117,   121,   123,   123,    19,    69,   123,
     123,   149,    97,    19,    30,    31,   185,    70,    34,    35,
     115,     4,   116,    69,   119,   120,     8,   123,     9,    44,
     146,    52,    77,    70,   147,   -53,    52,   150,   151,    36,
      37,     1,    34,    35,    44,     6,    63,    34,    35,   180,
       8,    14,     9,   144,   145,   134,   135,   166,   167,   168,
      27,    63,    28,    36,    37,   144,    98,    21,    36,    37,
     148,   149,   176,    26,    82,     7,    83,    32,    24,    82,
      33,    83,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   175,   169,   155,   156,   157,   158,   159,   160,   164,
     165,   174,    70,   117,   177,    52,    45,    53,    54,    55,
      56,    57,    46,    58,    59,    60,   179,    47,     8,    48,
       9,   136,   137,   138,   161,   162,   163,    49,    79,    80,
      81,    95,   102,    70,   103,   184,   107,   108,   109,   186,
     110,    49,   112,   111,   113,   114,   122,   124,   123,    77,
     139,   140,   141,   173,   172,   181,    40,    20,    25,   178,
      51,   171,   152,   106,   170,   183,   153,    38,     0,     0,
     154
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-80))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      46,    58,    49,    80,    83,    19,    19,    10,    49,    19,
      19,    42,    59,    16,    41,    42,    47,    64,    14,    15,
      77,     3,    79,    64,    81,    82,    16,    19,    18,    32,
      44,     3,    43,    80,    47,    46,     3,    47,    47,    35,
      36,     4,    14,    15,    47,     0,    49,    14,    15,    41,
      16,    17,    18,   110,   111,    30,    31,   136,   137,   138,
      43,    64,    45,    35,    36,   122,    38,     3,    35,    36,
      41,    42,   149,     3,    46,    39,    48,    46,    40,    46,
      36,    48,    24,    25,    26,    27,    28,    29,    21,    22,
      23,   148,   139,   125,   126,   127,   128,   129,   130,   134,
     135,   147,   149,   180,   150,     3,    44,     5,     6,     7,
       8,     9,    47,    11,    12,    13,   173,    42,    16,     3,
      18,    32,    33,    34,   131,   132,   133,    39,    46,    46,
      46,     3,    40,   180,     3,   181,    41,    41,    41,   185,
      46,    39,    41,    45,    41,    41,    46,    20,    19,    43,
      42,    42,    42,    42,    47,    10,    31,    11,    16,    47,
      47,   141,   122,    64,   140,   180,   123,    28,    -1,    -1,
     124
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    50,    51,     3,    56,     0,    39,    16,    18,
      52,    54,    57,    68,    17,    53,    55,    61,    62,    68,
      57,     3,    58,    59,    40,    61,     3,    43,    45,    60,
      41,    42,    46,    36,    14,    15,    35,    36,   100,   101,
      59,    63,    64,    65,    68,    44,    47,    42,     3,    39,
      66,    65,     3,     5,     6,     7,     8,     9,    11,    12,
      13,    66,    67,    68,    69,    70,    71,    74,    75,    76,
      82,    84,    86,    87,    89,    90,    91,    43,    83,    46,
      46,    46,    46,    48,    76,    82,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     3,    81,    82,    38,    79,
      80,    93,    40,     3,    72,    73,    70,    41,    41,    41,
      46,    45,    41,    41,    41,    93,    93,    74,    88,    93,
      93,    99,    46,    19,    20,    24,    25,    26,    27,    28,
      29,    21,    22,    23,    30,    31,    32,    33,    34,    42,
      42,    42,    77,    78,    93,    93,    44,    47,    41,    42,
      47,    47,    77,    94,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    98,    98,    99,    99,    99,    82,
      80,    73,    47,    42,    66,    93,    74,    66,    47,    93,
      41,    10,    85,    88,    66,    47,    66
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
#line 127 "decaf_grammar.y"
    { class_def = (yyvsp[(1) - (1)].class_def); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 132 "decaf_grammar.y"
    { (yyval.class_def) = new ClassDef((yyvsp[(2) - (6)].string), (yyvsp[(4) - (6)].variable_def_list), (yyvsp[(5) - (6)].method_def_list)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 136 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (1)].variable_def_list); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 137 "decaf_grammar.y"
    { (yyval.variable_def_list) = 0; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 141 "decaf_grammar.y"
    { (yyval.method_def_list) = (yyvsp[(1) - (1)].method_def_list); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 142 "decaf_grammar.y"
    { (yyval.method_def_list) = 0; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 146 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (2)].variable_def_list); (yyval.variable_def_list)->insert((yyval.variable_def_list)->end(), (yyvsp[(2) - (2)].variable_def_list)->begin(), (yyvsp[(2) - (2)].variable_def_list)->end()); delete (yyvsp[(2) - (2)].variable_def_list);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 147 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (1)].variable_def_list); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 151 "decaf_grammar.y"
    { (yyval.method_def_list) = (yyvsp[(1) - (2)].method_def_list); (yyval.method_def_list)->push_back((yyvsp[(2) - (2)].method_def)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 152 "decaf_grammar.y"
    { (yyval.method_def_list) = new MethodDefList(); (yyval.method_def_list)->push_back((yyvsp[(1) - (1)].method_def)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 156 "decaf_grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 160 "decaf_grammar.y"
    { (yyval.variable_def_list) = SetType((yyvsp[(2) - (3)].variable_def_list), (yyvsp[(1) - (3)].type)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 164 "decaf_grammar.y"
    { (yyval.variable_def_list) = (yyvsp[(1) - (3)].variable_def_list); (yyval.variable_def_list)->push_back((yyvsp[(3) - (3)].variable_def)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 165 "decaf_grammar.y"
    { 
						(yyval.variable_def_list) = new VariableDefList;
						(yyval.variable_def_list)->push_back((yyvsp[(1) - (1)].variable_def));
					}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 171 "decaf_grammar.y"
    { 
							(yyval.variable_def) = new VariableDef((yyvsp[(1) - (2)].string), (yylsp[(1) - (2)]).last_line, (yylsp[(1) - (2)]).first_column);
							(yyval.variable_def)->initial_value = (yyvsp[(2) - (2)].expression);
						}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 176 "decaf_grammar.y"
    { 
							(yyval.variable_def) = new VariableDef((yyvsp[(1) - (4)].string), (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).first_column); 
							(yyval.variable_def)->isArrayDef = true;
							(yyval.variable_def)->array_dimension = (yyvsp[(3) - (4)].integer);
						}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 184 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(2) - (2)].expression); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 185 "decaf_grammar.y"
    { (yyval.expression) = 0; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 191 "decaf_grammar.y"
    {
			(yyval.method_def) = new MethodDef((yyvsp[(2) - (6)].string)); 
			(yyval.method_def)->returnType = (yyvsp[(1) - (6)].type);
			(yyval.method_def)->parameters = (yyvsp[(4) - (6)].parameter_def_list);
			(yyval.method_def)->block =  (yyvsp[(6) - (6)].blockStatement);
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 200 "decaf_grammar.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 201 "decaf_grammar.y"
    { (yyval.type) = Void; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 205 "decaf_grammar.y"
    { (yyval.parameter_def_list) = (yyvsp[(1) - (1)].parameter_def_list); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 206 "decaf_grammar.y"
    { (yyval.parameter_def_list) = 0; }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 210 "decaf_grammar.y"
    {
									(yyval.parameter_def_list) = (yyvsp[(1) - (3)].parameter_def_list);
									(yyval.parameter_def_list)->push_back((yyvsp[(3) - (3)].parameter_def));
								}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 214 "decaf_grammar.y"
    { 
									(yyval.parameter_def_list) = new ParameterDefList();
									(yyval.parameter_def_list)->push_back((yyvsp[(1) - (1)].parameter_def));
								}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 221 "decaf_grammar.y"
    { (yyval.parameter_def) = new ParameterDef((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].type)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 226 "decaf_grammar.y"
    { 
		  (yyval.blockStatement) = new BlockStatement((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
		  (yyval.blockStatement)->listStatements = (yyvsp[(2) - (3)].statement_list);
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 232 "decaf_grammar.y"
    { (yyval.statement_list) = (yyvsp[(1) - (1)].statement_list); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 233 "decaf_grammar.y"
    { (yyval.statement_list) = 0; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 237 "decaf_grammar.y"
    { (yyval.type) = Int; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 238 "decaf_grammar.y"
    { (yyval.type) = Boolean; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 242 "decaf_grammar.y"
    { (yyval.statement_list) = (yyvsp[(1) - (2)].statement_list); (yyval.statement_list)->push_back((yyvsp[(2) - (2)].statement)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 243 "decaf_grammar.y"
    { (yyval.statement_list) = new StatementList(); (yyval.statement_list)->push_back((yyvsp[(1) - (1)].statement)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 247 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 248 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 249 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 250 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 251 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 252 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 253 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 254 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 255 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 256 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].blockStatement); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 260 "decaf_grammar.y"
    {(yyval.statement) = (yyvsp[(2) - (2)].statement); ((LocalVariableDef*)(yyval.statement))->variable_type = (yyvsp[(1) - (2)].type); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 263 "decaf_grammar.y"
    {(yyval.statement) = (yyvsp[(1) - (3)].statement); ((LocalVariableDef*)(yyval.statement))->variable_names->push_back((yyvsp[(3) - (3)].string));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 264 "decaf_grammar.y"
    {(yyval.statement) = new LocalVariableDef((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column);
                                           ((LocalVariableDef*)(yyval.statement))->variable_names = new list<string>();
                                           ((LocalVariableDef*)(yyval.statement))->variable_names->push_back((yyvsp[(1) - (1)].string));
                                           }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 270 "decaf_grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 275 "decaf_grammar.y"
    { (yyval.statement) = new AssignStatement((yyvsp[(1) - (3)].lvalueExpression), (yyvsp[(3) - (3)].expression), (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 279 "decaf_grammar.y"
    { (yyval.statement) = new MethodCallStatement((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].expression_list), (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 280 "decaf_grammar.y"
    { (yyval.statement) = new PrintStatement((yyvsp[(2) - (2)].expression_list), (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 281 "decaf_grammar.y"
    { (yyval.statement) = new ReadStatement((yyvsp[(2) - (2)].expression_list), (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 285 "decaf_grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 289 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (1)].expression_list); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 290 "decaf_grammar.y"
    { (yyval.expression_list) = 0; }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 294 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); (yyval.expression_list)->push_back((yyvsp[(3) - (3)].expression)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 295 "decaf_grammar.y"
    { (yyval.expression_list) = new ExpressionList(); (yyval.expression_list)->push_back((yyvsp[(1) - (1)].expression)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 299 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); (yyval.expression_list)->push_back((yyvsp[(3) - (3)].expression)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 300 "decaf_grammar.y"
    { (yyval.expression_list) = new ExpressionList(); (yyval.expression_list)->push_back((yyvsp[(1) - (1)].expression)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 304 "decaf_grammar.y"
    { (yyval.expression) = new ConstantStringExpression((yyvsp[(1) - (1)].string)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 305 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 309 "decaf_grammar.y"
    { (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); (yyval.expression_list)->push_back((yyvsp[(3) - (3)].lvalueExpression)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 310 "decaf_grammar.y"
    { (yyval.expression_list) = new ExpressionList(); (yyval.expression_list)->push_back((yyvsp[(1) - (1)].lvalueExpression)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 314 "decaf_grammar.y"
    { (yyval.lvalueExpression) = new LValueExpression((yyvsp[(1) - (2)].string)); (yyval.lvalueExpression)->expr = (yyvsp[(2) - (2)].expression); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 318 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 319 "decaf_grammar.y"
    { (yyval.expression) = 0; }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 323 "decaf_grammar.y"
    { (yyval.statement) = new IfStatement((yyvsp[(3) - (6)].expression), (yyvsp[(5) - (6)].blockStatement), (yyvsp[(6) - (6)].statement), (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 327 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(2) - (2)].blockStatement); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 328 "decaf_grammar.y"
    { (yyval.statement) = 0; }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 332 "decaf_grammar.y"
    { (yyval.statement) = new WhileStatement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].blockStatement), (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 337 "decaf_grammar.y"
    { (yyval.statement) = new ForStatement((yyvsp[(3) - (9)].statement), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].statement), (yyvsp[(9) - (9)].blockStatement), (yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 341 "decaf_grammar.y"
    { (yyval.statement) = (yyvsp[(1) - (3)].statement); ((BlockStatement*)(yyval.statement))->AddStatement((yyvsp[(3) - (3)].statement)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 342 "decaf_grammar.y"
    { (yyval.statement) = new BlockStatement((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column); 
									((BlockStatement*)(yyval.statement))->AddStatement((yyvsp[(1) - (1)].statement));}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 347 "decaf_grammar.y"
    { (yyval.statement) = new ReturnStatement((yyvsp[(2) - (2)].expression), (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 351 "decaf_grammar.y"
    { (yyval.statement) = new BreakStatement((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 355 "decaf_grammar.y"
    { (yyval.statement) = new ContinueStatement((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 359 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 360 "decaf_grammar.y"
    { (yyval.expression) = 0; }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 364 "decaf_grammar.y"
    { (yyval.expression) = new OrExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 365 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 368 "decaf_grammar.y"
    { (yyval.expression) = new AndExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 369 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 373 "decaf_grammar.y"
    { (yyval.expression) = new BigerThanExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 374 "decaf_grammar.y"
    { (yyval.expression) = new LessThanExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 375 "decaf_grammar.y"
    { (yyval.expression) = new BigerThanEqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 376 "decaf_grammar.y"
    { (yyval.expression) = new LessThanEqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 377 "decaf_grammar.y"
    { (yyval.expression) = new EqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 378 "decaf_grammar.y"
    { (yyval.expression) = new NotEqualExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 379 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 383 "decaf_grammar.y"
    { (yyval.expression) = new ShiftLeftExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 384 "decaf_grammar.y"
    { (yyval.expression) = new ShiftRightExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 385 "decaf_grammar.y"
    { (yyval.expression) = new RotExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 386 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 390 "decaf_grammar.y"
    { (yyval.expression) = new AddExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 391 "decaf_grammar.y"
    { (yyval.expression) = new SubExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 392 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 395 "decaf_grammar.y"
    { (yyval.expression) = new MultExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 396 "decaf_grammar.y"
    { (yyval.expression) = new DivExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 397 "decaf_grammar.y"
    { (yyval.expression) = new ModExpression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 398 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 402 "decaf_grammar.y"
    { (yyval.expression) = new NotExpression((yyvsp[(2) - (2)].expression)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 403 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].lvalueExpression); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 404 "decaf_grammar.y"
    { (yyval.expression) = new MethodCallExpression((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].expression_list)); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 405 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 406 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 409 "decaf_grammar.y"
    { (yyval.expression) = new ConstantIntExpression((yyvsp[(1) - (1)].integer)); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 410 "decaf_grammar.y"
    { (yyval.expression) = new ConstantCharExpression((yyvsp[(1) - (1)].integer)); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 411 "decaf_grammar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 415 "decaf_grammar.y"
    { (yyval.expression) = new ConstantBoolExpression(true); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 416 "decaf_grammar.y"
    { (yyval.expression) = new ConstantBoolExpression(false); }
    break;



/* Line 1806 of yacc.c  */
#line 2475 "decaf_grammar.cpp"
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



