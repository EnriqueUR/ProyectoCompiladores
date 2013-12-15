/* tree.h.  Generated automatically by treecc */
#ifndef __yy_tree_h
#define __yy_tree_h
#line 1 "tree.tc"

  #include <list>
  #include <map>
  #include <string>
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
  class Procedimiento;
  class LValueExpression;
  class NewStatement;
  class NewExpression;
  class ClassDef;
  class NewClassDef;

  void AddStatement(BlockStatement *block,Statement *stm);
  typedef list<Statement *> StatementList;
  typedef list<Expression *> ExpressionList;
  typedef list<AssignStatement *> AssignList;
  typedef list<VariableDef *> VariableDefList;
  typedef list<MethodDef *> MethodDefList;
  typedef list<ParameterDef *> ParameterDefList;
  typedef list<string> VariableNameList;

  typedef enum {OpAdd,OpSub,OpMul,OpDiv,OpMod,OpAnd,OpOr,OpNot,OpGT,OpLT,OpGTE,
  OpLTE,OpEq,OpNotEq,OpRShift,OpLShift,OpRot} ExpressionOperator;
  /* Aqui estan las nuevas listas */

  typedef list<NewStatement *> NewStatementList;
  typedef list<NewExpression *> NewExpressionList;

#line 46 "tree.h"

#include <new>

const int TheNewClass_kind = 47;
const int NewClassDef_kind = 48;
const int NewExpression_kind = 49;
const int NewStatement_kind = 50;
const int NewConstantExpression_kind = 52;
const int NewBinaryExpression_kind = 57;
const int NewUnaryExpression_kind = 58;
const int NewParameterDef_kind = 59;
const int NewLValueExpression_kind = 60;
const int NewMethodCallExpression_kind = 61;
const int NewConstantIntExpression_kind = 53;
const int NewConstantStringExpression_kind = 54;
const int NewConstantBoolExpression_kind = 55;
const int NewConstantCharExpression_kind = 56;
const int NewAddExpression_kind = 62;
const int NewSubExpression_kind = 63;
const int NewMultExpression_kind = 64;
const int NewDivExpression_kind = 65;
const int NewLessThanExpression_kind = 66;
const int NewLessThanEqualExpression_kind = 67;
const int NewBigerThanExpression_kind = 68;
const int NewBigerThanEqualExpression_kind = 69;
const int NewEqualExpression_kind = 70;
const int NewNotEqualExpression_kind = 71;
const int NewShiftRightExpression_kind = 72;
const int NewShiftLeftExpression_kind = 73;
const int NewRotExpression_kind = 74;
const int NewOrExpression_kind = 75;
const int NewAndExpression_kind = 76;
const int NewModExpression_kind = 78;
const int NewNotExpression_kind = 77;
const int NewIfStatement_kind = 79;
const int NewWhileStatement_kind = 80;
const int NewForStatement_kind = 81;
const int NewAssignStatement_kind = 82;
const int NewReadStatement_kind = 83;
const int NewPrintStatement_kind = 84;
const int NewMethodCallStatement_kind = 85;
const int NewReturnStatement_kind = 86;
const int NewBreakStatement_kind = 87;
const int NewContinueStatement_kind = 88;
const int NewBlockStatement_kind = 89;
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
const int LocalVariableDef_kind = 34;
const int MethodDef_kind = 35;
const int IfStatement_kind = 36;
const int WhileStatement_kind = 37;
const int ForStatement_kind = 38;
const int AssignStatement_kind = 39;
const int ReadStatement_kind = 40;
const int PrintStatement_kind = 41;
const int MethodCallStatement_kind = 42;
const int ReturnStatement_kind = 43;
const int BreakStatement_kind = 44;
const int ContinueStatement_kind = 45;
const int BlockStatement_kind = 46;
const int Main_kind = 1;
const int Procedimiento_kind = 51;

class TheNewClass;
class NewClassDef;
class NewExpression;
class NewStatement;
class NewConstantExpression;
class NewBinaryExpression;
class NewUnaryExpression;
class NewParameterDef;
class NewLValueExpression;
class NewMethodCallExpression;
class NewConstantIntExpression;
class NewConstantStringExpression;
class NewConstantBoolExpression;
class NewConstantCharExpression;
class NewAddExpression;
class NewSubExpression;
class NewMultExpression;
class NewDivExpression;
class NewLessThanExpression;
class NewLessThanEqualExpression;
class NewBigerThanExpression;
class NewBigerThanEqualExpression;
class NewEqualExpression;
class NewNotEqualExpression;
class NewShiftRightExpression;
class NewShiftLeftExpression;
class NewRotExpression;
class NewOrExpression;
class NewAndExpression;
class NewModExpression;
class NewNotExpression;
class NewIfStatement;
class NewWhileStatement;
class NewForStatement;
class NewAssignStatement;
class NewReadStatement;
class NewPrintStatement;
class NewMethodCallStatement;
class NewReturnStatement;
class NewBreakStatement;
class NewContinueStatement;
class NewBlockStatement;
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
class LocalVariableDef;
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
class Procedimiento;

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
#line 243 "tree.h"
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

class TheNewClass
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

	TheNewClass();

public:

	virtual string GenerarCodigo() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~TheNewClass();

};

class NewClassDef : public TheNewClass
{
public:

	NewClassDef(string className, NewBlockStatement * newBlockStatement);

public:

	string className;
	NewBlockStatement * newBlockStatement;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewClassDef();

};

class NewExpression : public TheNewClass
{
protected:

	NewExpression();

public:

	string place;
	int indice;
	Type type;

	virtual string GenerarCodigo() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewExpression();

};

class NewStatement : public TheNewClass
{
protected:

	NewStatement();

public:

	virtual string GenerarCodigo() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewStatement();

};

class NewConstantExpression : public NewExpression
{
protected:

	NewConstantExpression();

public:

	virtual string GenerarCodigo() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewConstantExpression();

};

class NewBinaryExpression : public NewExpression
{
protected:

	NewBinaryExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	NewExpression * newfirstExpression;
	NewExpression * newSecondExpression;

	virtual string GenerarCodigo() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewBinaryExpression();

};

class NewUnaryExpression : public NewExpression
{
protected:

	NewUnaryExpression(NewExpression * newfirstExpression);

public:

	NewExpression * newfirstExpression;

	virtual string GenerarCodigo() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewUnaryExpression();

};

class NewParameterDef : public NewExpression
{
public:

	NewParameterDef(string newId, Type newParameterType);

public:

	string newId;
	Type newParameterType;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewParameterDef();

};

class NewLValueExpression : public NewExpression
{
public:

	NewLValueExpression(string newId, NewExpression * newExpr, int offset, int level);

public:

	string newId;
	NewExpression * newExpr;
	int offset;
	int level;
	bool isGlobal;
	bool isParameter;
	bool isLocal;

	virtual string GenerarCodigo();
	virtual string GetDirLValue();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewLValueExpression();

};

class NewMethodCallExpression : public NewExpression
{
public:

	NewMethodCallExpression(string newId, NewExpressionList * newParameters);

public:

	string newId;
	NewExpressionList * newParameters;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewMethodCallExpression();

};

class NewConstantIntExpression : public NewConstantExpression
{
public:

	NewConstantIntExpression(int Newconstant);

public:

	int Newconstant;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewConstantIntExpression();

};

class NewConstantStringExpression : public NewConstantExpression
{
public:

	NewConstantStringExpression(string Newconstant);

public:

	string Newconstant;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewConstantStringExpression();

};

class NewConstantBoolExpression : public NewConstantExpression
{
public:

	NewConstantBoolExpression(bool Newconstant);

public:

	bool Newconstant;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewConstantBoolExpression();

};

class NewConstantCharExpression : public NewConstantExpression
{
public:

	NewConstantCharExpression(char Newconstant);

public:

	char Newconstant;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewConstantCharExpression();

};

class NewAddExpression : public NewBinaryExpression
{
public:

	NewAddExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewAddExpression();

};

class NewSubExpression : public NewBinaryExpression
{
public:

	NewSubExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewSubExpression();

};

class NewMultExpression : public NewBinaryExpression
{
public:

	NewMultExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewMultExpression();

};

class NewDivExpression : public NewBinaryExpression
{
public:

	NewDivExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewDivExpression();

};

class NewLessThanExpression : public NewBinaryExpression
{
public:

	NewLessThanExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewLessThanExpression();

};

class NewLessThanEqualExpression : public NewBinaryExpression
{
public:

	NewLessThanEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewLessThanEqualExpression();

};

class NewBigerThanExpression : public NewBinaryExpression
{
public:

	NewBigerThanExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewBigerThanExpression();

};

class NewBigerThanEqualExpression : public NewBinaryExpression
{
public:

	NewBigerThanEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewBigerThanEqualExpression();

};

class NewEqualExpression : public NewBinaryExpression
{
public:

	NewEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewEqualExpression();

};

class NewNotEqualExpression : public NewBinaryExpression
{
public:

	NewNotEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewNotEqualExpression();

};

class NewShiftRightExpression : public NewBinaryExpression
{
public:

	NewShiftRightExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewShiftRightExpression();

};

class NewShiftLeftExpression : public NewBinaryExpression
{
public:

	NewShiftLeftExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewShiftLeftExpression();

};

class NewRotExpression : public NewBinaryExpression
{
public:

	NewRotExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewRotExpression();

};

class NewOrExpression : public NewBinaryExpression
{
public:

	NewOrExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewOrExpression();

};

class NewAndExpression : public NewBinaryExpression
{
public:

	NewAndExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewAndExpression();

};

class NewModExpression : public NewBinaryExpression
{
public:

	NewModExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewModExpression();

};

class NewNotExpression : public NewUnaryExpression
{
public:

	NewNotExpression(NewExpression * newfirstExpression);

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewNotExpression();

};

class NewIfStatement : public NewStatement
{
public:

	NewIfStatement(NewExpression * newCondition, NewStatement * newStatementTrue, NewStatement * newStatementFalse);

public:

	NewExpression * newCondition;
	NewStatement * newStatementTrue;
	NewStatement * newStatementFalse;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewIfStatement();

};

class NewWhileStatement : public NewStatement
{
public:

	NewWhileStatement(NewExpression * newCondition, NewStatement * newStatementTrue);

public:

	NewExpression * newCondition;
	NewStatement * newStatementTrue;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewWhileStatement();

};

class NewForStatement : public NewStatement
{
public:

	NewForStatement(NewStatement * newFirstListAssign, NewExpression * newCondition, NewStatement * newLastListAssign, NewStatement * newStatementTrue);

public:

	NewStatement * newFirstListAssign;
	NewExpression * newCondition;
	NewStatement * newLastListAssign;
	NewStatement * newStatementTrue;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewForStatement();

};

class NewAssignStatement : public NewStatement
{
public:

	NewAssignStatement(NewExpression * newLeftValue, NewExpression * newValue);

public:

	NewExpression * newLeftValue;
	NewExpression * newValue;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewAssignStatement();

};

class NewReadStatement : public NewStatement
{
public:

	NewReadStatement(NewExpressionList * newListExpression);

public:

	NewExpressionList * newListExpression;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewReadStatement();

};

class NewPrintStatement : public NewStatement
{
public:

	NewPrintStatement(NewExpressionList * newListExpression);

public:

	NewExpressionList * newListExpression;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewPrintStatement();

};

class NewMethodCallStatement : public NewStatement
{
public:

	NewMethodCallStatement(string id, NewExpressionList * newParameters);

public:

	string id;
	NewExpressionList * newParameters;
	int indexLevel;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewMethodCallStatement();

};

class NewReturnStatement : public NewStatement
{
public:

	NewReturnStatement(NewExpression * newReturnExpression);

public:

	NewExpression * newReturnExpression;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewReturnStatement();

};

class NewBreakStatement : public NewStatement
{
public:

	NewBreakStatement();

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewBreakStatement();

};

class NewContinueStatement : public NewStatement
{
public:

	NewContinueStatement();

public:

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewContinueStatement();

};

class NewBlockStatement : public NewStatement
{
public:

	NewBlockStatement();

public:

	NewStatementList * newListStatements;

	virtual string GenerarCodigo();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NewBlockStatement();

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
	virtual TheNewClass * ValidarSemantica() = 0;

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
	virtual TheNewClass * ValidarSemantica() = 0;

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
	virtual TheNewClass * ValidarSemantica() = 0;

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
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ClassDef();

};

class BinaryExpression : public Expression
{
protected:

	BinaryExpression(Expression * firstExpression, Expression * secondExpression);

public:

	Expression * firstExpression;
	Expression * secondExpression;

	virtual string ToString() = 0;
	virtual TheNewClass * ValidarSemantica() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpression();

};

class UnaryExpression : public Expression
{
protected:

	UnaryExpression(Expression * firstExpression);

public:

	Expression * firstExpression;

	virtual string ToString() = 0;
	virtual TheNewClass * ValidarSemantica() = 0;

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
	virtual TheNewClass * ValidarSemantica() = 0;

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ParameterDef();

};

class AddExpression : public BinaryExpression
{
public:

	AddExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpression();

};

class SubExpression : public BinaryExpression
{
public:

	SubExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpression();

};

class MultExpression : public BinaryExpression
{
public:

	MultExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MultExpression();

};

class DivExpression : public BinaryExpression
{
public:

	DivExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpression();

};

class LessThanExpression : public BinaryExpression
{
public:

	LessThanExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessThanExpression();

};

class LessThanEqualExpression : public BinaryExpression
{
public:

	LessThanEqualExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessThanEqualExpression();

};

class BigerThanExpression : public BinaryExpression
{
public:

	BigerThanExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BigerThanExpression();

};

class BigerThanEqualExpression : public BinaryExpression
{
public:

	BigerThanEqualExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BigerThanEqualExpression();

};

class EqualExpression : public BinaryExpression
{
public:

	EqualExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EqualExpression();

};

class NotEqualExpression : public BinaryExpression
{
public:

	NotEqualExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotEqualExpression();

};

class ShiftRightExpression : public BinaryExpression
{
public:

	ShiftRightExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ShiftRightExpression();

};

class ShiftLeftExpression : public BinaryExpression
{
public:

	ShiftLeftExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ShiftLeftExpression();

};

class RotExpression : public BinaryExpression
{
public:

	RotExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RotExpression();

};

class OrExpression : public BinaryExpression
{
public:

	OrExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OrExpression();

};

class AndExpression : public BinaryExpression
{
public:

	AndExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndExpression();

};

class ModExpression : public BinaryExpression
{
public:

	ModExpression(Expression * firstExpression, Expression * secondExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpression();

};

class NotExpression : public UnaryExpression
{
public:

	NotExpression(Expression * firstExpression);

public:

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	ConstantExpression * initial_value;
	bool isArrayDef;
	int array_dimension;
	Type variable_type;

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableDef();

};

class LocalVariableDef : public Statement
{
public:

	LocalVariableDef(int first_line, int first_column);

public:

	int first_line;
	int first_column;
	Type variable_type;
	VariableNameList * variable_names;

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LocalVariableDef();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStatement();

};

class ForStatement : public Statement
{
public:

	ForStatement(Statement * firstListAssign, Expression * condition, Statement * lastListAssign, Statement * statementTrue, int first_line, int first_column);

public:

	Statement * firstListAssign;
	Expression * condition;
	Statement * lastListAssign;
	Statement * statementTrue;
	int first_line;
	int first_column;

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStatement();

};

class MethodCallStatement : public Statement
{
public:

	MethodCallStatement(string id, ExpressionList * parameters, int first_line, int first_column);

public:

	string id;
	ExpressionList * parameters;
	int first_line;
	int first_column;

	virtual string ToString();
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();

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
	virtual TheNewClass * ValidarSemantica();
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

class Procedimiento
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

	Procedimiento(string id, NewBlockStatement * newBlockStatement);

public:

	string id;
	NewBlockStatement * newBlockStatement;
	int countParametros;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Procedimiento();

};



#endif
