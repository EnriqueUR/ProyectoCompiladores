%{

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

%}

%union {
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
}

%locations
%pure_parser

%token<string> ID "'identificador'"

%token K_CLASS 		"'class'"
%token K_BREAK		"'break'"
%token K_CONTINUE 	"'continue'"
%token K_WHILE 		"'while'"
%token K_FOR 		"'for'"
%token K_IF 		"'if'"
%token K_ELSE 		"'else'"
%token K_RETURN 	"'return'"
%token K_READ 		"'read'"
%token K_PRINT		"'print'"
%token<constant> K_TRUE	 "'true'"
%token<constant> K_FALSE "'false'"
%token<type> K_INT	"'int'"
%token<type> K_VOID 	"'void'"
%token<type> K_BOOLEAN	"'boolean'"

%token<oper> OR 	"operador booleano 'or'"
%token<oper> AND 	"operador booleano 'and'"

%token<oper> SHIFT_LEFT		"<<"
%token<oper> SHIFT_RIGHT	">>"
%token<oper> ROT		"rot"

%token<oper> BIGER_THAN		">"
%token<oper> LESS_THAN		"<"
%token<oper> BIGER_THAN_EQUAL	">="
%token<oper> LESS_THAN_EQUAL	"<="
%token<oper> EQUAL		"=="
%token<oper> NOT_EQUAL		"!="

%token<oper> ADD		"+"
%token<oper> SUB		"-"

%token<oper> MULT		"*"
%token<oper> DIV		"/"
%token<oper> MOD		"%"



%token<integer>	CHAR_CONSTANT 	"constante caracter"
%token<integer> INT_CONSTANT 	"constante entera"
%token<integer>	REAL_CONSTANT 	"constante real"
%token<string>	STRING_CONSTANT "constante de cadena"

%type<statement> statement assign method_call if_statement while_statement for_statement return_statement break_statement continue_statement
%type<blockStatement> block
%type<lvalueExpression> lvalue
%type<statement> for_assignment_list opt_else
%type<expression> opt_expr expr bool_term relational_expr bit_shift_expr arith_expr arith_term factor constant bool_constant
%type<expression> print_argument opt_array_dimension optional_initialization
%type<expression_list> opt_method_call_argument_list method_call_argument_list read_argument_list print_argument_list
%type<variable_def> var
%type<variable_def_list> field_decl field_decl_list var_list optional_field_decl_list
%type<method_def> method_decl
%type<method_def_list> optional_method_decl_list method_decl_list
%type<parameter_def> parameter_decl
%type<parameter_def_list> opt_parameter_decl_list parameter_decl_list
%type<class_def> class_def
%type<string> class_name method_name
%type<statement_list>	opt_statement_list statement_list
%type<type> return_type type

%expect 4

%%

program
	:	class_def	{ class_def = $1; }
;

class_def :
		K_CLASS class_name '{' optional_field_decl_list optional_method_decl_list '}'
		{ $$ = new ClassDef($2, $4, $5); }
;

optional_field_decl_list:
				field_decl_list		{ $$ = $1; }
				| /*Nada*/		{ $$ = 0; }
;

optional_method_decl_list:
				method_decl_list	{ $$ = $1; }
				| /*Nada*/		{ $$ = 0; }
;

field_decl_list:
			field_decl_list field_decl	{ $$ = $1; $$->insert($$->end(), $2->begin(), $2->end()); delete $2;}
			| field_decl			{ $$ = $1; }
;

method_decl_list:
			method_decl_list method_decl	{ $$ = $1; $$->push_back($2); }
			| method_decl			{ $$ = new MethodDefList(); $$->push_back($1); }
;

class_name
	:	ID { $$ = $1; }
;

field_decl
	:	  type var_list ';' { $$ = SetType($2, $1); }
;

var_list:
		var_list ',' var	{ $$ = $1; $$->push_back($3); }
		| var			{ 
						$$ = new VariableDefList;
						$$->push_back($1);
					}
;

var	:	 ID optional_initialization	{ 
							$$ = new VariableDef($1, @1.last_line, @1.first_column);
							$$->initial_value = $2;
						}

		| ID '[' INT_CONSTANT ']'	{ 
							$$ = new VariableDef($1, @1.last_line, @1.first_column); 
							$$->isArrayDef = true;
							$$->array_dimension = $3;
						}
;

optional_initialization:
				'=' constant	{ $$ = $2; }
				| /*Empty*/		{ $$ = 0; }
;


method_decl
	:	return_type ID '(' opt_parameter_decl_list ')' block
		{
			$$ = new MethodDef($2); 
			$$->returnType = $1;
			$$->parameters = $4;
			$$->block =  $6;
		}
;

return_type:	
		type		{ $$ = $1; }
		| K_VOID	{ $$ = Void; }
;

opt_parameter_decl_list:
			parameter_decl_list 	{ $$ = $1; }
			| /*Nada*/		{ $$ = 0; }
;

parameter_decl_list:	
			parameter_decl_list ',' parameter_decl	{
									$$ = $1;
									$$->push_back($3);
								}
			| parameter_decl			{ 
									$$ = new ParameterDefList();
									$$->push_back($1);
								}
;

parameter_decl:	
		type ID		{ $$ = new ParameterDef($2, $1); }
;

block	
	:	'{' opt_statement_list '}'
		{ 
		  $$ = new BlockStatement(@1.first_line, @1.first_column);
		  $$->listStatements = $2;
		}
;

opt_statement_list:	statement_list	{ $$ = $1; }
			| /*Nada*/	{ $$ = 0; }
;

type	:	
		K_INT		{ $$ = Int; }
		| K_BOOLEAN	{ $$ = Boolean; }
;

statement_list:
		statement_list statement	{ $$ = $1; $$->push_back($2); }
		| statement			{ $$ = new StatementList(); $$->push_back($1); }
;
		
statement
	:	assign ';'			{ $$ = $1; }
		| method_call ';'		{ $$ = $1; }
		| if_statement			{ $$ = $1; }
		| while_statement 		{ $$ = $1; }
		| for_statement			{ $$ = $1; }
		| return_statement ';'		{ $$ = $1; }
		| break_statement ';'		{ $$ = $1; }
		| continue_statement ';'	{ $$ = $1; }
		| block 			{ $$ = $1; }
;
		
assign	:
		lvalue '=' expr { $$ = new AssignStatement($1, $3, @1.first_line, @1.first_column); };
		

method_call:
		method_name '(' opt_method_call_argument_list ')'	{ $$ = new MethodCallStatement($1, $3, @1.first_line, @1.first_column); }	
		| K_PRINT print_argument_list				{ $$ = new PrintStatement($2, @1.first_line, @1.first_column); }
		| K_READ read_argument_list				{ $$ = new ReadStatement($2, @1.first_line, @1.first_column); }
;

method_name
	:	ID	{ $$ = $1; }
;

opt_method_call_argument_list:	
				method_call_argument_list	{ $$ = $1; }
				| /*Nada*/			{ $$ = 0; }
;

method_call_argument_list:
				method_call_argument_list ',' expr	{ $$ = $1; $$->push_back($3); }
				| expr					{ $$ = new ExpressionList(); $$->push_back($1); }
;

print_argument_list: 
			print_argument_list ',' print_argument	{ $$ = $1; $$->push_back($3); }
			| print_argument			{ $$ = new ExpressionList(); $$->push_back($1); }
;

print_argument
	:	STRING_CONSTANT		{ $$ = new ConstantStringExpression($1); }
		| expr			{ $$ = $1; }
;

read_argument_list:
			read_argument_list ',' lvalue	{ $$ = $1; $$->push_back($3); }
			| lvalue			{ $$ = new ExpressionList(); $$->push_back($1); }
;
		
lvalue	
	:	ID opt_array_dimension	{ $$ = new LValueExpression($1); $$->expr = $2; }
;

opt_array_dimension: 
			'[' expr ']'	{ $$ = $2; }
			| /*Nada*/	{ $$ = 0; }
;		

if_statement:
		K_IF '(' expr ')' block opt_else	{ $$ = new IfStatement($3, $5, $6, @1.first_line, @1.first_column); }
;

opt_else:
		K_ELSE block	{ $$ = $2; }
		| /*Nada*/	{ $$ = 0; }
;

while_statement:
		K_WHILE '(' expr ')' block	{ $$ = new WhileStatement($3, $5, @1.first_line, @1.first_column); }
;

for_statement:
		K_FOR '(' for_assignment_list ';' expr ';' for_assignment_list ')' block
		{ $$ = new ForStatement($3, $5, $7, $9, @1.first_line, @1.first_column); }
;

for_assignment_list:
			for_assignment_list ',' assign		{ $$ = $1; ((BlockStatement*)$$)->AddStatement($3); }
			| assign				{ $$ = new BlockStatement(@1.first_line, @1.first_column); }
;

return_statement:
			 K_RETURN opt_expr	{ $$ = new ReturnStatement($2, @1.first_line, @1.first_column); }
;

break_statement:
			K_BREAK		{ $$ = new BreakStatement(@1.first_line, @1.first_column); }
;

continue_statement:
			K_CONTINUE	{ $$ = new ContinueStatement(@1.first_line, @1.first_column); }
;

opt_expr:
		expr		{ $$ = $1; }
		| /*Nada*/	{ $$ = 0; }
;

expr	:	
		expr OR bool_term	{ $$ = new OrExpression($1, $3); }
		| bool_term			{ $$ = $1; }
;

bool_term:	bool_term AND relational_expr	{ $$ = new AndExpression($1, $3); }
		| relational_expr			{ $$ = $1; }
;

relational_expr: 
			relational_expr  BIGER_THAN bit_shift_expr	{ $$ = new BigerThanExpression($1, $3); }
			| relational_expr  LESS_THAN bit_shift_expr	{ $$ = new LessThanExpression($1, $3); }
			| relational_expr  BIGER_THAN_EQUAL bit_shift_expr	{ $$ = new BigerThanEqualExpression($1, $3); }
			| relational_expr  LESS_THAN_EQUAL bit_shift_expr	{ $$ = new LessThanEqualExpression($1, $3); }
			| relational_expr  EQUAL bit_shift_expr	{ $$ = new EqualExpression($1, $3); }
			| relational_expr  NOT_EQUAL bit_shift_expr	{ $$ = new NotEqualExpression($1, $3); }
			| bit_shift_expr			{ $$ = $1; }
;

bit_shift_expr:
			bit_shift_expr SHIFT_LEFT arith_expr		{ $$ = new ShiftLeftExpression($1, $3); }
			| bit_shift_expr SHIFT_RIGHT arith_expr	{ $$ = new ShiftRightExpression($1, $3); }
			| bit_shift_expr ROT arith_expr			{ $$ = new RotExpression($1, $3); }
			| arith_expr				{ $$ = $1; }
;

arith_expr:
		arith_expr ADD arith_term		{ $$ = new AddExpression($1, $3); }
		| arith_expr SUB arith_term		{ $$ = new SubExpression($1, $3); }
		| arith_term					{ $$ = $1; }
;

arith_term:	arith_term MULT factor			{ $$ = new MultExpression($1, $3); }
		| arith_term DIV factor			{ $$ = new DivExpression($1, $3); }
		| arith_term MOD factor			{ $$ = new ModExpression($1, $3); }
		| factor					{ $$ = $1; }
;

factor:	
		'!' factor					{ $$ = new NotExpression($2); }
		| lvalue					{ $$ = $1; }
		| method_name '(' opt_method_call_argument_list ')'	{ $$ = new MethodCallExpression($1, $3); }
		| constant					{ $$ = $1; }
		| '(' expr ')'					{ $$ = $2; }
;
		
constant:	INT_CONSTANT 	{ $$ = new ConstantIntExpression($1); }
		| CHAR_CONSTANT { $$ = new ConstantCharExpression($1); }
		| bool_constant { $$ = $1; }
; 
		
bool_constant:
		K_TRUE		{ $$ = new ConstantBoolExpression(true); }
		| K_FALSE	{ $$ = new ConstantBoolExpression(false); }
;
