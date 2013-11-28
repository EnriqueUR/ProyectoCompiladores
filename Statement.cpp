/*
 * Statement.cpp
 *
 *  Created on: Mar 27, 2009
 *      Author: Ivan Deras
 */

#include "Variable.h"
#include "Expression.h"
#include "Statement.h"
#include "Util.h"

/*
 * GenerateCode
 */
string AssignmentStatement::GenerateCode()
{
	/* TODO: Implementar AssignmentStatement::GenerateCode() */
}

string MethodCallStatement::GenerateCode()
{
	/* TODO: Implementar MethodCallStatement::GenerateCode() */
}

string IfStatement::GenerateCode()
{
	/* TODO: Implementar IfStatement::GenerateCode() */
}

string WhileStatement::GenerateCode()
{
	/* TODO: Implementar WhileStatement::GenerateCode() */
}

string ForStatement::GenerateCode()
{
	/* TODO: Implementar ForStatement::GenerateCode() */
}

string ReturnStatement::GenerateCode()
{
	/* TODO: Implementar ReturnStatement::GenerateCode() */
}

string BreakStatement::GenerateCode()
{
	/* TODO: Implementar BreakStatement::GenerateCode() */
}

string ContinueStatement::GenerateCode()
{
	/* TODO: Implementar ContinueStatement::GenerateCode() */
}

string BlockStatement::GenerateCode()
{
	/* TODO: Implementar BlockStatement::GenerateCode() */
}

/*
 * ToString
 */
string AssignmentStatement::ToString()
{
	ostringstream out;

	out << "// Linea " << line << " Columna " << column << "\n"; 
	out << lvalue->ToString() << " = " << expr->ToString() << ";";

	return out.str();
}

string MethodCallStatement::ToString()
{
	return this->name + "(" + ListToString(arguments, ", ", false) + ");";
}

string IfStatement::ToString()
{
	ostringstream out;

	out << "if (" << condition->ToString() << ")" << endl;
	out << true_part->ToString() << endl;

	if (false_part != 0) {
		out << "else" << endl;
		out << false_part->ToString() << endl;
	}

	return out.str();
}

string WhileStatement::ToString()
{
	ostringstream out;

	out << "while (" << condition->ToString() << ")" << endl;
	out << "{" << loop_body->ToString() << endl << "}";

	return out.str();
}

string ForStatement::ToString()
{
	return "for () {}";
}

string ReturnStatement::ToString()
{
	return "return " + expr->ToString() + ";";
}

string BreakStatement::ToString()
{
	return "break;";
}

string ContinueStatement::ToString()
{
	return "continue;";
}

string BlockStatement::ToString()
{
	ostringstream out;

	out << "{" << endl;

	if (statement_list != 0)
		out << ListToString(statement_list, "\n", true);

	out << "}";

	return out.str();
}

