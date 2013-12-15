/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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




/* Line 2068 of yacc.c  */
#line 113 "decaf_tokens.h"
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



