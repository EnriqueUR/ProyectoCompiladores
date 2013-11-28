/* tree.h.  Generated automatically by treecc */
#ifndef __yy_tree_h
#define __yy_tree_h
#line 1 "tree.tc"

  #include <list>
  #include <iostream>
  using namespace std;
  
  #include "Value.h"
  #include "Util.h"
  class Expression;
  class Statement;
  class AssignStatement;
  class VariableDef;
  class MethodDef;
  class ConstantExpression;
  class ParameterDef;
  class BlockStatement;
  class LValueExpression;
  void AddStatement(BlockStatement *block,Statement *stm);
  typedef list<Statement *> StatementList;
  typedef list<Expression *> ExpressionList;
  typedef list<AssignStatement *> AssignList;
  typedef list<VariableDef *> VariableDefList;
  typedef list<MethodDef *> MethodDefList;
  typedef list<ParameterDef *> ParameterDefList;
  
  typedef enum {OpAdd,OpSub,OpMul,OpDiv,OpMod,OpAnd,OpOr,OpNot,OpGT,OpLT,OpGTE,
  OpLTE,OpEq,OpNotEq,OpRShift,OpLShift,OpRot} ExpressionOperator;
#line 32 "tree.h"

#include <new>

const int TheClass_kind = 2;
const int Expression_kind = 3;
const int Statement_kind = 4;
const int ClassDef_kind = 5;
const int BinaryExpression_kind = 6;
const int UnaryExpression_kind = 7;
const int ConstantExpression_kind = 8;
const int MethodCallExpression_kind = 9;
const int LValueExpression_kind = 14;
const int ParameterDef_kind = 32;
const int AddExpression_kind = 15;
const int SubExpression_kind = 16;
const int MultExpression_kind = 17;
const int DivExpression_kind = 18;
const int LessThanExpression_kind = 19;
const int LessThanEqualExpression_kind = 20;
const int BigerThanExpression_kind = 21;
const int BigerThanEqualExpression_kind = 22;
const int EqualExpression_kind = 23;
const int NotEqualExpression_kind = 24;
const int ShiftRightExpression_kind = 25;
const int ShiftLeftExpression_kind = 26;
const int RotExpression_kind = 27;
const int OrExpression_kind = 28;
const int AndExpression_kind = 29;
const int ModExpression_kind = 31;
const int NotExpression_kind = 30;
const int ConstantIntExpression_kind = 10;
const int ConstantBoolExpression_kind = 11;
const int ConstantCharExpression_kind = 12;
const int ConstantStringExpression_kind = 13;
const int VariableDef_kind = 33;
const int MethodDef_kind = 34;
const int IfStatement_kind = 35;
const int WhileStatement_kind = 36;
const int ForStatement_kind = 37;
const int AssignStatement_kind = 38;
const int ReadStatement_kind = 39;
const int PrintStatement_kind = 40;
const int MethodCallStatement_kind = 41;
const int ReturnStatement_kind = 42;
const int BreakStatement_kind = 43;
const int ContinueStatement_kind = 44;
const int BlockStatement_kind = 45;
const int Main_kind = 1;

class TheClass;
class Expression;
class Statement;
class ClassDef;
class BinaryExpression;
class UnaryExpression;
class ConstantExpression;
class MethodCallExpression;
class LValueExpression;
class ParameterDef;
class AddExpression;
class SubExpression;
class MultExpression;
class DivExpression;
class LessThanExpression;
class LessThanEqualExpression;
class BigerThanExpression;
class BigerThanEqualExpression;
class EqualExpression;
class NotEqualExpression;
class ShiftRightExpression;
class ShiftLeftExpression;
class RotExpression;
class OrExpression;
class AndExpression;
class ModExpression;
class NotExpression;
class ConstantIntExpression;
class ConstantBoolExpression;
class ConstantCharExpression;
class ConstantStringExpression;
class VariableDef;
class MethodDef;
class IfStatement;
class WhileStatement;
class ForStatement;
class AssignStatement;
class ReadStatement;
class PrintStatement;
class MethodCallStatement;
class ReturnStatement;
class BreakStatement;
class ContinueStatement;
class BlockStatement;
class Main;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 141 "tree.h"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual char *currFilename();
	virtual long currLinenum();

};

class TheClass
{
protected:

	int kind__;
	char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	TheClass();

public:

	virtual string ToString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~TheClass();

};

class Expression : public TheClass
{
protected:

	Expression();

public:

	virtual string ToString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expression();

};

class Statement : public TheClass
{
protected:

	Statement();

public:

	virtual string ToString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Statement();

};

class ClassDef : public TheClass
{
public:

	ClassDef(string className, VariableDefList * listVariable, MethodDefList * listMethod);

public:

	string className;
	VariableDefList * listVariable;
	MethodDefList * listMethod;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ClassDef();

};

class BinaryExpression : public Expression
{
protected:

	BinaryExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	Expression * FirstExpression;
	Expression * SecondExpression;

	virtual string ToString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpression();

};

class UnaryExpression : public Expression
{
protected:

	UnaryExpression(Expression * FirstExpression);

public:

	Expression * FirstExpression;

	virtual string ToString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~UnaryExpression();

};

class ConstantExpression : public Expression
{
protected:

	ConstantExpression();

public:

	virtual string ToString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ConstantExpression();

};

class MethodCallExpression : public Expression
{
public:

	MethodCallExpression(string id, ExpressionList * parameters);

public:

	string id;
	ExpressionList * parameters;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodCallExpression();

};

class LValueExpression : public Expression
{
public:

	LValueExpression(string id);

public:

	string id;
	Expression * expr;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LValueExpression();

};

class ParameterDef : public Expression
{
public:

	ParameterDef(string id, Type parameterType);

public:

	string id;
	Type parameterType;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ParameterDef();

};

class AddExpression : public BinaryExpression
{
public:

	AddExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpression();

};

class SubExpression : public BinaryExpression
{
public:

	SubExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpression();

};

class MultExpression : public BinaryExpression
{
public:

	MultExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MultExpression();

};

class DivExpression : public BinaryExpression
{
public:

	DivExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpression();

};

class LessThanExpression : public BinaryExpression
{
public:

	LessThanExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessThanExpression();

};

class LessThanEqualExpression : public BinaryExpression
{
public:

	LessThanEqualExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessThanEqualExpression();

};

class BigerThanExpression : public BinaryExpression
{
public:

	BigerThanExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BigerThanExpression();

};

class BigerThanEqualExpression : public BinaryExpression
{
public:

	BigerThanEqualExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BigerThanEqualExpression();

};

class EqualExpression : public BinaryExpression
{
public:

	EqualExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EqualExpression();

};

class NotEqualExpression : public BinaryExpression
{
public:

	NotEqualExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotEqualExpression();

};

class ShiftRightExpression : public BinaryExpression
{
public:

	ShiftRightExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ShiftRightExpression();

};

class ShiftLeftExpression : public BinaryExpression
{
public:

	ShiftLeftExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ShiftLeftExpression();

};

class RotExpression : public BinaryExpression
{
public:

	RotExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RotExpression();

};

class OrExpression : public BinaryExpression
{
public:

	OrExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OrExpression();

};

class AndExpression : public BinaryExpression
{
public:

	AndExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndExpression();

};

class ModExpression : public BinaryExpression
{
public:

	ModExpression(Expression * FirstExpression, Expression * SecondExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpression();

};

class NotExpression : public UnaryExpression
{
public:

	NotExpression(Expression * FirstExpression);

public:

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotExpression();

};

class ConstantIntExpression : public ConstantExpression
{
public:

	ConstantIntExpression(int constant);

public:

	int constant;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ConstantIntExpression();

};

class ConstantBoolExpression : public ConstantExpression
{
public:

	ConstantBoolExpression(bool constant);

public:

	bool constant;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ConstantBoolExpression();

};

class ConstantCharExpression : public ConstantExpression
{
public:

	ConstantCharExpression(char constant);

public:

	char constant;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ConstantCharExpression();

};

class ConstantStringExpression : public ConstantExpression
{
public:

	ConstantStringExpression(string constant);

public:

	string constant;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ConstantStringExpression();

};

class VariableDef : public Statement
{
public:

	VariableDef(string id, int first_line, int first_column);

public:

	string id;
	int first_line;
	int first_column;
	Expression * initial_value;
	bool isArrayDef;
	int array_dimension;
	Type variable_type;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableDef();

};

class MethodDef : public Statement
{
public:

	MethodDef(string id);

public:

	string id;
	Statement * block;
	ParameterDefList * parameters;
	Type returnType;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodDef();

};

class IfStatement : public Statement
{
public:

	IfStatement(Expression * condition, Statement * statementTrue, Statement * statementFalse, int first_line, int first_column);

public:

	Expression * condition;
	Statement * statementTrue;
	Statement * statementFalse;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStatement();

};

class WhileStatement : public Statement
{
public:

	WhileStatement(Expression * condition, Statement * statementTrue, int first_line, int first_column);

public:

	Expression * condition;
	Statement * statementTrue;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStatement();

};

class ForStatement : public Statement
{
public:

	ForStatement(Statement * firstListAssign, Expression * condition, Statement * lasttListAssign, Statement * statementTrue, int first_line, int first_column);

public:

	Statement * firstListAssign;
	Expression * condition;
	Statement * lasttListAssign;
	Statement * statementTrue;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ForStatement();

};

class AssignStatement : public Statement
{
public:

	AssignStatement(Expression * leftValue, Expression * value, int first_line, int first_column);

public:

	Expression * leftValue;
	Expression * value;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignStatement();

};

class ReadStatement : public Statement
{
public:

	ReadStatement(ExpressionList * listExpression, int first_line, int first_column);

public:

	ExpressionList * listExpression;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReadStatement();

};

class PrintStatement : public Statement
{
public:

	PrintStatement(ExpressionList * listExpression, int first_line, int first_column);

public:

	ExpressionList * listExpression;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStatement();

};

class MethodCallStatement : public Statement
{
public:

	MethodCallStatement(string name, ExpressionList * parameters, int first_line, int first_column);

public:

	string name;
	ExpressionList * parameters;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodCallStatement();

};

class ReturnStatement : public Statement
{
public:

	ReturnStatement(Expression * returnExpression, int first_line, int first_column);

public:

	Expression * returnExpression;
	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReturnStatement();

};

class BreakStatement : public Statement
{
public:

	BreakStatement(int first_line, int first_column);

public:

	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BreakStatement();

};

class ContinueStatement : public Statement
{
public:

	ContinueStatement(int first_line, int first_column);

public:

	int first_line;
	int first_column;

	virtual string ToString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ContinueStatement();

};

class BlockStatement : public Statement
{
public:

	BlockStatement(int first_line, int first_column);

public:

	StatementList * listStatements;
	int first_line;
	int first_column;

	virtual string ToString();
	virtual void AddStatement(Statement * stm);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BlockStatement();

};

class Main
{
protected:

	int kind__;
	char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

public:

	Main(StatementList * list);

public:

	StatementList * list;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Main();

};



#endif
