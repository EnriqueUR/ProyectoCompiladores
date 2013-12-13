/* tree.cpp.  Generated automatically by treecc */
#line 41 "tree.tc"

#include "tree.h"
void FreeRegister(string register)
{
    /* hacer algo */
} 
list<string> arrayList;

string getFreeLabel(string label)
{
    list<string>::iterator it;
    it = arrayList.begin();
    while(it != arrayList.end())
    {
        if(label == *it)
            return "NULL";
        it++;
    }
    return label;
}

string getFreeRegister(){return " ";}

string getLabel(string label){return "";}

map<string,Procedimiento *> methodDeclared;

int currentContexto = 0; 
Contexto *contextos[10];

list<string> stackCurrentLabel;
list<string> listElseLabel;
list<string> listIfLabel;
list<string> listEndIfLabel;
list<string> listWhileLabel;
list<string> listEndWhileLabel;
list<string> listForLabel;
list<string> listEndForLabel;
#line 42 "tree.cpp"

#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	((unsigned)(&(((struct _YYNODESTATE_align_##type *)0)->field)))
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

char *YYNODESTATE::currFilename()
{
	return (char *)0;
}

long YYNODESTATE::currLinenum()
{
	return 0;
}

#endif
#line 321 "tree.cpp"
void *TheNewClass::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void TheNewClass::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

TheNewClass::TheNewClass()
{
	this->kind__ = TheNewClass_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

TheNewClass::~TheNewClass()
{
	// not used
}

int TheNewClass::isA(int kind) const
{
	if(kind == TheNewClass_kind)
		return 1;
	else
		return 0;
}

const char *TheNewClass::getKindName() const
{
	return "TheNewClass";
}

NewClassDef::NewClassDef(string className, NewBlockStatement * newBlockStatement)
	: TheNewClass()
{
	this->kind__ = NewClassDef_kind;
	this->className = className;
	this->newBlockStatement = newBlockStatement;
}

NewClassDef::~NewClassDef()
{
	// not used
}

string NewClassDef::GenerarCodigo()
#line 1369 "tree.tc"
{
  ostringstream nuevo;
  Contexto *contextoTemp = contextos[0];
  map<string,Variable*>::iterator it1;
  it1 = contextoTemp->contextoMap.begin();
  nuevo << ".data \n";
  while(it1 != contextoTemp->contextoMap.end())
  {
    Variable *var = (*it1).second;
    if(var->isArray)
    {
        string label = getFreeLabel((*it1).first);
        if(label == "NULL")
            return "error !!";
        nuevo << label << ": \n";
        nuevo << ".space " << var->dimension * 4 << "\n";
    }
    else
    {
        string label = getFreeLabel((*it1).first);
        if(label == "NULL")
            return "error !!";
        nuevo << label <<": \n";
        if(var->type == Int){
            if(var->value != 0)
                nuevo << ".word " << var->value << " \n";
            else
                nuevo << ".word " << "0 \n";
        }
        else
        {
            if(var->value != 0)
                nuevo << ".word " << "1 \n";
            else
                nuevo << ".word " << "0 \n";
        }
    }
    it1++;
  }
  nuevo << ".text \n";

  map<string,Procedimiento*>::iterator it2;
  it2 = methodDeclared.begin();
  while(it2 != methodDeclared.end()){
      string label = getFreeLabel((*it2).first);
      nuevo << label <<": \n";
      nuevo << newBlockStatement->GenerarCodigo();
      it2++;
  }
  return nuevo.str();   
}
#line 423 "tree.cpp"

int NewClassDef::isA(int kind) const
{
	if(kind == NewClassDef_kind)
		return 1;
	else
		return TheNewClass::isA(kind);
}

const char *NewClassDef::getKindName() const
{
	return "NewClassDef";
}

NewExpression::NewExpression()
	: TheNewClass()
{
	this->kind__ = NewExpression_kind;
}

NewExpression::~NewExpression()
{
	// not used
}

int NewExpression::isA(int kind) const
{
	if(kind == NewExpression_kind)
		return 1;
	else
		return TheNewClass::isA(kind);
}

const char *NewExpression::getKindName() const
{
	return "NewExpression";
}

NewStatement::NewStatement()
	: TheNewClass()
{
	this->kind__ = NewStatement_kind;
}

NewStatement::~NewStatement()
{
	// not used
}

int NewStatement::isA(int kind) const
{
	if(kind == NewStatement_kind)
		return 1;
	else
		return TheNewClass::isA(kind);
}

const char *NewStatement::getKindName() const
{
	return "NewStatement";
}

NewConstantExpression::NewConstantExpression()
	: NewExpression()
{
	this->kind__ = NewConstantExpression_kind;
}

NewConstantExpression::~NewConstantExpression()
{
	// not used
}

int NewConstantExpression::isA(int kind) const
{
	if(kind == NewConstantExpression_kind)
		return 1;
	else
		return NewExpression::isA(kind);
}

const char *NewConstantExpression::getKindName() const
{
	return "NewConstantExpression";
}

NewBinaryExpression::NewBinaryExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewExpression()
{
	this->kind__ = NewBinaryExpression_kind;
	this->newfirstExpression = newfirstExpression;
	this->newSecondExpression = newSecondExpression;
}

NewBinaryExpression::~NewBinaryExpression()
{
	// not used
}

int NewBinaryExpression::isA(int kind) const
{
	if(kind == NewBinaryExpression_kind)
		return 1;
	else
		return NewExpression::isA(kind);
}

const char *NewBinaryExpression::getKindName() const
{
	return "NewBinaryExpression";
}

NewUnaryExpression::NewUnaryExpression(NewExpression * newfirstExpression)
	: NewExpression()
{
	this->kind__ = NewUnaryExpression_kind;
	this->newfirstExpression = newfirstExpression;
}

NewUnaryExpression::~NewUnaryExpression()
{
	// not used
}

int NewUnaryExpression::isA(int kind) const
{
	if(kind == NewUnaryExpression_kind)
		return 1;
	else
		return NewExpression::isA(kind);
}

const char *NewUnaryExpression::getKindName() const
{
	return "NewUnaryExpression";
}

NewParameterDef::NewParameterDef(string newId, Type newParameterType)
	: NewExpression()
{
	this->kind__ = NewParameterDef_kind;
	this->newId = newId;
	this->newParameterType = newParameterType;
}

NewParameterDef::~NewParameterDef()
{
	// not used
}

string NewParameterDef::GenerarCodigo()
#line 1858 "tree.tc"
{return "falta";}
#line 577 "tree.cpp"

int NewParameterDef::isA(int kind) const
{
	if(kind == NewParameterDef_kind)
		return 1;
	else
		return NewExpression::isA(kind);
}

const char *NewParameterDef::getKindName() const
{
	return "NewParameterDef";
}

NewLValueExpression::NewLValueExpression(string newId, NewExpression * newExpr, int offset, int level)
	: NewExpression()
{
	this->kind__ = NewLValueExpression_kind;
	this->newId = newId;
	this->newExpr = newExpr;
	this->offset = offset;
	this->level = level;
}

NewLValueExpression::~NewLValueExpression()
{
	// not used
}

string NewLValueExpression::GenerarCodigo()
#line 1860 "tree.tc"
{return "falta";}
#line 610 "tree.cpp"

int NewLValueExpression::isA(int kind) const
{
	if(kind == NewLValueExpression_kind)
		return 1;
	else
		return NewExpression::isA(kind);
}

const char *NewLValueExpression::getKindName() const
{
	return "NewLValueExpression";
}

NewMethodCallExpression::NewMethodCallExpression(string newId, NewExpressionList * newParameters)
	: NewExpression()
{
	this->kind__ = NewMethodCallExpression_kind;
	this->newId = newId;
	this->newParameters = newParameters;
}

NewMethodCallExpression::~NewMethodCallExpression()
{
	// not used
}

string NewMethodCallExpression::GenerarCodigo()
#line 1862 "tree.tc"
{return "falta";}
#line 641 "tree.cpp"

int NewMethodCallExpression::isA(int kind) const
{
	if(kind == NewMethodCallExpression_kind)
		return 1;
	else
		return NewExpression::isA(kind);
}

const char *NewMethodCallExpression::getKindName() const
{
	return "NewMethodCallExpression";
}

NewConstantIntExpression::NewConstantIntExpression(int Newconstant)
	: NewConstantExpression()
{
	this->kind__ = NewConstantIntExpression_kind;
	this->Newconstant = Newconstant;
}

NewConstantIntExpression::~NewConstantIntExpression()
{
	// not used
}

string NewConstantIntExpression::GenerarCodigo()
#line 1850 "tree.tc"
{return "falta";}
#line 671 "tree.cpp"

int NewConstantIntExpression::isA(int kind) const
{
	if(kind == NewConstantIntExpression_kind)
		return 1;
	else
		return NewConstantExpression::isA(kind);
}

const char *NewConstantIntExpression::getKindName() const
{
	return "NewConstantIntExpression";
}

NewConstantStringExpression::NewConstantStringExpression(string Newconstant)
	: NewConstantExpression()
{
	this->kind__ = NewConstantStringExpression_kind;
	this->Newconstant = Newconstant;
}

NewConstantStringExpression::~NewConstantStringExpression()
{
	// not used
}

string NewConstantStringExpression::GenerarCodigo()
#line 1854 "tree.tc"
{return "falta";}
#line 701 "tree.cpp"

int NewConstantStringExpression::isA(int kind) const
{
	if(kind == NewConstantStringExpression_kind)
		return 1;
	else
		return NewConstantExpression::isA(kind);
}

const char *NewConstantStringExpression::getKindName() const
{
	return "NewConstantStringExpression";
}

NewConstantBoolExpression::NewConstantBoolExpression(bool Newconstant)
	: NewConstantExpression()
{
	this->kind__ = NewConstantBoolExpression_kind;
	this->Newconstant = Newconstant;
}

NewConstantBoolExpression::~NewConstantBoolExpression()
{
	// not used
}

string NewConstantBoolExpression::GenerarCodigo()
#line 1852 "tree.tc"
{return "falta";}
#line 731 "tree.cpp"

int NewConstantBoolExpression::isA(int kind) const
{
	if(kind == NewConstantBoolExpression_kind)
		return 1;
	else
		return NewConstantExpression::isA(kind);
}

const char *NewConstantBoolExpression::getKindName() const
{
	return "NewConstantBoolExpression";
}

NewConstantCharExpression::NewConstantCharExpression(char Newconstant)
	: NewConstantExpression()
{
	this->kind__ = NewConstantCharExpression_kind;
	this->Newconstant = Newconstant;
}

NewConstantCharExpression::~NewConstantCharExpression()
{
	// not used
}

string NewConstantCharExpression::GenerarCodigo()
#line 1856 "tree.tc"
{return "falta";}
#line 761 "tree.cpp"

int NewConstantCharExpression::isA(int kind) const
{
	if(kind == NewConstantCharExpression_kind)
		return 1;
	else
		return NewConstantExpression::isA(kind);
}

const char *NewConstantCharExpression::getKindName() const
{
	return "NewConstantCharExpression";
}

NewAddExpression::NewAddExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewAddExpression_kind;
}

NewAddExpression::~NewAddExpression()
{
	// not used
}

string NewAddExpression::GenerarCodigo()
#line 1422 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo ;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << "add " << registro <<","<<newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 803 "tree.cpp"

int NewAddExpression::isA(int kind) const
{
	if(kind == NewAddExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewAddExpression::getKindName() const
{
	return "NewAddExpression";
}

NewSubExpression::NewSubExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewSubExpression_kind;
}

NewSubExpression::~NewSubExpression()
{
	// not used
}

string NewSubExpression::GenerarCodigo()
#line 1438 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << "sub "<< registro <<","<<newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 845 "tree.cpp"

int NewSubExpression::isA(int kind) const
{
	if(kind == NewSubExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewSubExpression::getKindName() const
{
	return "NewSubExpression";
}

NewMultExpression::NewMultExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewMultExpression_kind;
}

NewMultExpression::~NewMultExpression()
{
	// not used
}

string NewMultExpression::GenerarCodigo()
#line 1454 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    nuevo << "mult "<< newfirstExpression->place<<","<<newSecondExpression->place;
    place = newfirstExpression->place;

    return nuevo.str();
}
#line 886 "tree.cpp"

int NewMultExpression::isA(int kind) const
{
	if(kind == NewMultExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewMultExpression::getKindName() const
{
	return "NewMultExpression";
}

NewDivExpression::NewDivExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewDivExpression_kind;
}

NewDivExpression::~NewDivExpression()
{
	// not used
}

string NewDivExpression::GenerarCodigo()
#line 1469 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    nuevo << "div "<< newfirstExpression->place<<","<<newSecondExpression->place;
    place = newfirstExpression->place;

    return nuevo.str();
}
#line 927 "tree.cpp"

int NewDivExpression::isA(int kind) const
{
	if(kind == NewDivExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewDivExpression::getKindName() const
{
	return "NewDivExpression";
}

NewLessThanExpression::NewLessThanExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewLessThanExpression_kind;
}

NewLessThanExpression::~NewLessThanExpression()
{
	// not used
}

string NewLessThanExpression::GenerarCodigo()
#line 1484 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string label = "stackCurrentLabel.pop_back()";    
    nuevo << "blt "<< newfirstExpression->place<<","<<newSecondExpression->place <<","<< label;

    place = "";

    return nuevo.str();   
}
#line 970 "tree.cpp"

int NewLessThanExpression::isA(int kind) const
{
	if(kind == NewLessThanExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewLessThanExpression::getKindName() const
{
	return "NewLessThanExpression";
}

NewLessThanEqualExpression::NewLessThanEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewLessThanEqualExpression_kind;
}

NewLessThanEqualExpression::~NewLessThanEqualExpression()
{
	// not used
}

string NewLessThanEqualExpression::GenerarCodigo()
#line 1501 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string label = "stackCurrentLabel.pop_back()";
    nuevo << "ble "<< newfirstExpression->place<<","<<newSecondExpression->place <<","<< label;
    place = "";

    return nuevo.str();   
}
#line 1012 "tree.cpp"

int NewLessThanEqualExpression::isA(int kind) const
{
	if(kind == NewLessThanEqualExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewLessThanEqualExpression::getKindName() const
{
	return "NewLessThanEqualExpression";
}

NewBigerThanExpression::NewBigerThanExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewBigerThanExpression_kind;
}

NewBigerThanExpression::~NewBigerThanExpression()
{
	// not used
}

string NewBigerThanExpression::GenerarCodigo()
#line 1517 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string label = "stackCurrentLabel.pop_back()";
    nuevo << "bgt "<< newfirstExpression->place<<","<<newSecondExpression->place <<","<< label;
    place = "";

    return nuevo.str();   
}
#line 1054 "tree.cpp"

int NewBigerThanExpression::isA(int kind) const
{
	if(kind == NewBigerThanExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewBigerThanExpression::getKindName() const
{
	return "NewBigerThanExpression";
}

NewBigerThanEqualExpression::NewBigerThanEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewBigerThanEqualExpression_kind;
}

NewBigerThanEqualExpression::~NewBigerThanEqualExpression()
{
	// not used
}

string NewBigerThanEqualExpression::GenerarCodigo()
#line 1533 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string label =" stackCurrentLabel.pop_back()";
    nuevo << "bge "<< newfirstExpression->place<<","<<newSecondExpression->place <<","<< label;
    place = "";

    return nuevo.str();   
}
#line 1096 "tree.cpp"

int NewBigerThanEqualExpression::isA(int kind) const
{
	if(kind == NewBigerThanEqualExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewBigerThanEqualExpression::getKindName() const
{
	return "NewBigerThanEqualExpression";
}

NewEqualExpression::NewEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewEqualExpression_kind;
}

NewEqualExpression::~NewEqualExpression()
{
	// not used
}

string NewEqualExpression::GenerarCodigo()
#line 1549 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string label = "stackCurrentLabel.pop_back()";
    nuevo << "beq "<< newfirstExpression->place<<","<<newSecondExpression->place <<","<< label;
    place = "";

    return nuevo.str();  
}
#line 1138 "tree.cpp"

int NewEqualExpression::isA(int kind) const
{
	if(kind == NewEqualExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewEqualExpression::getKindName() const
{
	return "NewEqualExpression";
}

NewNotEqualExpression::NewNotEqualExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewNotEqualExpression_kind;
}

NewNotEqualExpression::~NewNotEqualExpression()
{
	// not used
}

string NewNotEqualExpression::GenerarCodigo()
#line 1565 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo ;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string label = "stackCurrentLabel.pop_back()";
    nuevo << "bne "<< newfirstExpression->place<<","<<newSecondExpression->place<<","<<label;
    place = "";

    return nuevo.str();
}
#line 1180 "tree.cpp"

int NewNotEqualExpression::isA(int kind) const
{
	if(kind == NewNotEqualExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewNotEqualExpression::getKindName() const
{
	return "NewNotEqualExpression";
}

NewShiftRightExpression::NewShiftRightExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewShiftRightExpression_kind;
}

NewShiftRightExpression::~NewShiftRightExpression()
{
	// not used
}

string NewShiftRightExpression::GenerarCodigo()
#line 1581 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << "srl "<< registro << newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 1222 "tree.cpp"

int NewShiftRightExpression::isA(int kind) const
{
	if(kind == NewShiftRightExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewShiftRightExpression::getKindName() const
{
	return "NewShiftRightExpression";
}

NewShiftLeftExpression::NewShiftLeftExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewShiftLeftExpression_kind;
}

NewShiftLeftExpression::~NewShiftLeftExpression()
{
	// not used
}

string NewShiftLeftExpression::GenerarCodigo()
#line 1597 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << "sll "<< registro << newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 1264 "tree.cpp"

int NewShiftLeftExpression::isA(int kind) const
{
	if(kind == NewShiftLeftExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewShiftLeftExpression::getKindName() const
{
	return "NewShiftLeftExpression";
}

NewRotExpression::NewRotExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewRotExpression_kind;
}

NewRotExpression::~NewRotExpression()
{
	// not used
}

string NewRotExpression::GenerarCodigo()
#line 1613 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << "rot "<< registro << newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 1306 "tree.cpp"

int NewRotExpression::isA(int kind) const
{
	if(kind == NewRotExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewRotExpression::getKindName() const
{
	return "NewRotExpression";
}

NewOrExpression::NewOrExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewOrExpression_kind;
}

NewOrExpression::~NewOrExpression()
{
	// not used
}

string NewOrExpression::GenerarCodigo()
#line 1629 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << "or "<< registro << newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 1348 "tree.cpp"

int NewOrExpression::isA(int kind) const
{
	if(kind == NewOrExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewOrExpression::getKindName() const
{
	return "NewOrExpression";
}

NewAndExpression::NewAndExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewAndExpression_kind;
}

NewAndExpression::~NewAndExpression()
{
	// not used
}

string NewAndExpression::GenerarCodigo()
#line 1645 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << "and "<< registro << newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 1390 "tree.cpp"

int NewAndExpression::isA(int kind) const
{
	if(kind == NewAndExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewAndExpression::getKindName() const
{
	return "NewAndExpression";
}

NewModExpression::NewModExpression(NewExpression * newfirstExpression, NewExpression * newSecondExpression)
	: NewBinaryExpression(newfirstExpression, newSecondExpression)
{
	this->kind__ = NewModExpression_kind;
}

NewModExpression::~NewModExpression()
{
	// not used
}

string NewModExpression::GenerarCodigo()
#line 1677 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    string registro = getFreeRegister();
    nuevo << " "<< registro << newfirstExpression->place<<","<<newSecondExpression->place;
    place = registro;

    return nuevo.str();
}
#line 1432 "tree.cpp"

int NewModExpression::isA(int kind) const
{
	if(kind == NewModExpression_kind)
		return 1;
	else
		return NewBinaryExpression::isA(kind);
}

const char *NewModExpression::getKindName() const
{
	return "NewModExpression";
}

NewNotExpression::NewNotExpression(NewExpression * newfirstExpression)
	: NewUnaryExpression(newfirstExpression)
{
	this->kind__ = NewNotExpression_kind;
}

NewNotExpression::~NewNotExpression()
{
	// not used
}

string NewNotExpression::GenerarCodigo()
#line 1662 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L ;
    FreeRegister(newfirstExpression->place);
    string registro = getFreeRegister();
    nuevo << " "<< registro << newfirstExpression->place;;
    place = registro;

    return nuevo.str();
}
#line 1472 "tree.cpp"

int NewNotExpression::isA(int kind) const
{
	if(kind == NewNotExpression_kind)
		return 1;
	else
		return NewUnaryExpression::isA(kind);
}

const char *NewNotExpression::getKindName() const
{
	return "NewNotExpression";
}

NewIfStatement::NewIfStatement(NewExpression * newCondition, NewStatement * newStatementTrue, NewStatement * newStatementFalse)
	: NewStatement()
{
	this->kind__ = NewIfStatement_kind;
	this->newCondition = newCondition;
	this->newStatementTrue = newStatementTrue;
	this->newStatementFalse = newStatementFalse;
}

NewIfStatement::~NewIfStatement()
{
	// not used
}

string NewIfStatement::GenerarCodigo()
#line 1695 "tree.tc"
{
    string labelIf = getLabel("if");
    string labelElse = getLabel("else");
    string labelEndIf = getLabel("endIf");
    
    //no se si lo de arriba o esto
    stackCurrentLabel.push_back(labelIf);

    string condition = newCondition->GenerarCodigo();
    ostringstream nuevo;
    nuevo << condition;
    
    if(newStatementFalse != NULL)
        nuevo << "j " << labelElse;
    else
        nuevo << "j " << labelEndIf;

    nuevo << labelIf << " :";
    nuevo << newStatementTrue->GenerarCodigo();

    if(newStatementFalse != NULL)
    {
        nuevo << labelElse << " :";
        nuevo << newStatementFalse->GenerarCodigo();
    }

    nuevo << labelEndIf << " :";
    return nuevo.str();
}
#line 1532 "tree.cpp"

int NewIfStatement::isA(int kind) const
{
	if(kind == NewIfStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewIfStatement::getKindName() const
{
	return "NewIfStatement";
}

NewWhileStatement::NewWhileStatement(NewExpression * newCondition, NewStatement * newStatementTrue)
	: NewStatement()
{
	this->kind__ = NewWhileStatement_kind;
	this->newCondition = newCondition;
	this->newStatementTrue = newStatementTrue;
}

NewWhileStatement::~NewWhileStatement()
{
	// not used
}

string NewWhileStatement::GenerarCodigo()
#line 1726 "tree.tc"
{
    string labelStartWhile = getLabel("startWhile");
    string labelWhile = getLabel("while");
    string labelEndWhile = getLabel("endWhile");

    stackCurrentLabel.push_back(labelWhile);
    string condition = newCondition->GenerarCodigo();
    
    ostringstream nuevo;
    nuevo << labelStartWhile << " :";
    nuevo << condition;
    nuevo << "j " << labelEndWhile;

    nuevo << labelWhile << " :";
    nuevo << newStatementTrue->GenerarCodigo();
    nuevo << "j " << labelStartWhile; 

    nuevo << labelEndWhile << " :";
    return nuevo.str();
}
#line 1582 "tree.cpp"

int NewWhileStatement::isA(int kind) const
{
	if(kind == NewWhileStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewWhileStatement::getKindName() const
{
	return "NewWhileStatement";
}

NewForStatement::NewForStatement(NewStatement * newFirstListAssign, NewExpression * newCondition, NewStatement * newLastListAssign, NewStatement * newStatementTrue)
	: NewStatement()
{
	this->kind__ = NewForStatement_kind;
	this->newFirstListAssign = newFirstListAssign;
	this->newCondition = newCondition;
	this->newLastListAssign = newLastListAssign;
	this->newStatementTrue = newStatementTrue;
}

NewForStatement::~NewForStatement()
{
	// not used
}

string NewForStatement::GenerarCodigo()
#line 1748 "tree.tc"
{
    string labelStartFor = getLabel("startFor");
    string labelfor = getLabel("for");
    string labelEndfor = getLabel("endfor");

    stackCurrentLabel.push_back(labelfor);

    string firstListAssign = newFirstListAssign->GenerarCodigo();
    string lastListAssign = newLastListAssign->GenerarCodigo();

    ostringstream nuevo;
    nuevo << firstListAssign;
    nuevo << lastListAssign;
    string condition = newCondition->GenerarCodigo();

    nuevo << labelStartFor << " :";
    nuevo << condition;
    nuevo << "j " << labelEndfor;

    nuevo << labelfor << " :";
    nuevo << newStatementTrue->GenerarCodigo();
    nuevo << "j " << labelStartFor; 

    nuevo << labelEndfor << " :";
    return nuevo.str();
}
#line 1640 "tree.cpp"

int NewForStatement::isA(int kind) const
{
	if(kind == NewForStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewForStatement::getKindName() const
{
	return "NewForStatement";
}

NewAssignStatement::NewAssignStatement(NewExpression * newLeftValue, NewExpression * newValue)
	: NewStatement()
{
	this->kind__ = NewAssignStatement_kind;
	this->newLeftValue = newLeftValue;
	this->newValue = newValue;
}

NewAssignStatement::~NewAssignStatement()
{
	// not used
}

string NewAssignStatement::GenerarCodigo()
#line 1776 "tree.tc"
{

}
#line 1673 "tree.cpp"

int NewAssignStatement::isA(int kind) const
{
	if(kind == NewAssignStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewAssignStatement::getKindName() const
{
	return "NewAssignStatement";
}

NewReadStatement::NewReadStatement(NewExpressionList * newListExpression)
	: NewStatement()
{
	this->kind__ = NewReadStatement_kind;
	this->newListExpression = newListExpression;
}

NewReadStatement::~NewReadStatement()
{
	// not used
}

string NewReadStatement::GenerarCodigo()
#line 1836 "tree.tc"
{
    ostringstream nuevo;
    list<NewExpression *>::iterator it;
    it = newListExpression->begin();
    while(it != newListExpression->end())
    { 
        NewExpression *expr = (*it);
        nuevo << expr->GenerarCodigo();
        it++;
    }

    return nuevo.str();
}
#line 1715 "tree.cpp"

int NewReadStatement::isA(int kind) const
{
	if(kind == NewReadStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewReadStatement::getKindName() const
{
	return "NewReadStatement";
}

NewPrintStatement::NewPrintStatement(NewExpressionList * newListExpression)
	: NewStatement()
{
	this->kind__ = NewPrintStatement_kind;
	this->newListExpression = newListExpression;
}

NewPrintStatement::~NewPrintStatement()
{
	// not used
}

string NewPrintStatement::GenerarCodigo()
#line 1809 "tree.tc"
{
    /*ostringstream nuevo;
    list<NewExpression *>::iterator it;
    it = newListExpression->begin();
    while(it != newListExpression->end())
    { 
        NewExpression *expr = *it;
        nuevo << expr->GenerarCodigo();
        if(expr->type == Type.Int)
        {
            nuevo << "li " << "$v0" <<","<< "1";
            nuevo << "move " << "$a0" << expr->place;
            nuevo << "syscall";
        }
        else if(expr->type == Type.String)
        {
            nuevo << "li " << "$v0" <<","<< "4";
            nuevo << "move " << "$a0" <<","<< expr->place;
            nuevo << "syscall";
        }
    }*/

    //return nuevo.str();
    return "falta";
}
#line 1769 "tree.cpp"

int NewPrintStatement::isA(int kind) const
{
	if(kind == NewPrintStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewPrintStatement::getKindName() const
{
	return "NewPrintStatement";
}

NewMethodCallStatement::NewMethodCallStatement(string id, NewExpressionList * newParameters)
	: NewStatement()
{
	this->kind__ = NewMethodCallStatement_kind;
	this->id = id;
	this->newParameters = newParameters;
}

NewMethodCallStatement::~NewMethodCallStatement()
{
	// not used
}

string NewMethodCallStatement::GenerarCodigo()
#line 1781 "tree.tc"
{
    ostringstream nuevo ;
    list<NewExpression *>::iterator it;
    it = newParameters->begin();
    int parameterCount = newParameters->size();
    nuevo << "addi " << "$sp" << (-1 * parameterCount);
    int parameterPosition = 0;
    while(it != newParameters->end())
    {   
        nuevo << (*it)->GenerarCodigo();
        nuevo << "sw " << "("<< (parameterPosition * 4)<<")$sp"<< "," ;
        it++;
    }

    nuevo << "jal " + id;
    return nuevo.str();
}
#line 1816 "tree.cpp"

int NewMethodCallStatement::isA(int kind) const
{
	if(kind == NewMethodCallStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewMethodCallStatement::getKindName() const
{
	return "NewMethodCallStatement";
}

NewReturnStatement::NewReturnStatement(NewExpression * newReturnExpression)
	: NewStatement()
{
	this->kind__ = NewReturnStatement_kind;
	this->newReturnExpression = newReturnExpression;
}

NewReturnStatement::~NewReturnStatement()
{
	// not used
}

string NewReturnStatement::GenerarCodigo()
#line 1800 "tree.tc"
{
    ostringstream nuevo;
    nuevo << newReturnExpression->GenerarCodigo();
    nuevo << "move "<< "$v0" <<" , "<< newReturnExpression->place; 
    nuevo << "jr " << "$ra";
    return nuevo.str();
}
#line 1852 "tree.cpp"

int NewReturnStatement::isA(int kind) const
{
	if(kind == NewReturnStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewReturnStatement::getKindName() const
{
	return "NewReturnStatement";
}

NewBreakStatement::NewBreakStatement()
	: NewStatement()
{
	this->kind__ = NewBreakStatement_kind;
}

NewBreakStatement::~NewBreakStatement()
{
	// not used
}

string NewBreakStatement::GenerarCodigo()
#line 1864 "tree.tc"
{return "falta";}
#line 1881 "tree.cpp"

int NewBreakStatement::isA(int kind) const
{
	if(kind == NewBreakStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewBreakStatement::getKindName() const
{
	return "NewBreakStatement";
}

NewContinueStatement::NewContinueStatement()
	: NewStatement()
{
	this->kind__ = NewContinueStatement_kind;
}

NewContinueStatement::~NewContinueStatement()
{
	// not used
}

string NewContinueStatement::GenerarCodigo()
#line 1866 "tree.tc"
{return "falta";}
#line 1910 "tree.cpp"

int NewContinueStatement::isA(int kind) const
{
	if(kind == NewContinueStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewContinueStatement::getKindName() const
{
	return "NewContinueStatement";
}

NewBlockStatement::NewBlockStatement()
	: NewStatement()
{
	this->kind__ = NewBlockStatement_kind;
}

NewBlockStatement::~NewBlockStatement()
{
	// not used
}

string NewBlockStatement::GenerarCodigo()
#line 1868 "tree.tc"
{return "falta";}
#line 1939 "tree.cpp"

int NewBlockStatement::isA(int kind) const
{
	if(kind == NewBlockStatement_kind)
		return 1;
	else
		return NewStatement::isA(kind);
}

const char *NewBlockStatement::getKindName() const
{
	return "NewBlockStatement";
}

void *TheClass::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void TheClass::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

TheClass::TheClass()
{
	this->kind__ = TheClass_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

TheClass::~TheClass()
{
	// not used
}

int TheClass::isA(int kind) const
{
	if(kind == TheClass_kind)
		return 1;
	else
		return 0;
}

const char *TheClass::getKindName() const
{
	return "TheClass";
}

Expression::Expression()
	: TheClass()
{
	this->kind__ = Expression_kind;
}

Expression::~Expression()
{
	// not used
}

int Expression::isA(int kind) const
{
	if(kind == Expression_kind)
		return 1;
	else
		return TheClass::isA(kind);
}

const char *Expression::getKindName() const
{
	return "Expression";
}

Statement::Statement()
	: TheClass()
{
	this->kind__ = Statement_kind;
}

Statement::~Statement()
{
	// not used
}

int Statement::isA(int kind) const
{
	if(kind == Statement_kind)
		return 1;
	else
		return TheClass::isA(kind);
}

const char *Statement::getKindName() const
{
	return "Statement";
}

ClassDef::ClassDef(string className, VariableDefList * listVariable, MethodDefList * listMethod)
	: TheClass()
{
	this->kind__ = ClassDef_kind;
	this->className = className;
	this->listVariable = listVariable;
	this->listMethod = listMethod;
}

ClassDef::~ClassDef()
{
	// not used
}

string ClassDef::ToString()
#line 673 "tree.tc"
{
  ostringstream out;
  out << "class " << className << "{" << endl; 
  if (listVariable != 0)
      out << ListToString(listVariable, "\n", true);
  if (listMethod != 0)
      out << ListToString(listMethod, "\n", true);
  out << "}";
  return out.str(); 
}
#line 2063 "tree.cpp"

TheNewClass * ClassDef::ValidarSemantica()
#line 687 "tree.tc"
{
    contextos[0] = new Contexto();
    list<VariableDef*>::iterator it1;
    it1 = listVariable->begin();
    while(it1 != listVariable->end())
    {
        (*it1)->ValidarSemantica();
        it1++;
    }

    list<MethodDef*>::iterator it2;
    it2 = listMethod->begin();
    while(it2 != listMethod->end())
    {
        (*it2)->ValidarSemantica();
        it2++;
    }
    
    return new NewClassDef(className,NULL);
}
#line 2087 "tree.cpp"

int ClassDef::isA(int kind) const
{
	if(kind == ClassDef_kind)
		return 1;
	else
		return TheClass::isA(kind);
}

const char *ClassDef::getKindName() const
{
	return "ClassDef";
}

BinaryExpression::BinaryExpression(Expression * firstExpression, Expression * secondExpression)
	: Expression()
{
	this->kind__ = BinaryExpression_kind;
	this->firstExpression = firstExpression;
	this->secondExpression = secondExpression;
}

BinaryExpression::~BinaryExpression()
{
	// not used
}

int BinaryExpression::isA(int kind) const
{
	if(kind == BinaryExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *BinaryExpression::getKindName() const
{
	return "BinaryExpression";
}

UnaryExpression::UnaryExpression(Expression * firstExpression)
	: Expression()
{
	this->kind__ = UnaryExpression_kind;
	this->firstExpression = firstExpression;
}

UnaryExpression::~UnaryExpression()
{
	// not used
}

int UnaryExpression::isA(int kind) const
{
	if(kind == UnaryExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *UnaryExpression::getKindName() const
{
	return "UnaryExpression";
}

ConstantExpression::ConstantExpression()
	: Expression()
{
	this->kind__ = ConstantExpression_kind;
}

ConstantExpression::~ConstantExpression()
{
	// not used
}

int ConstantExpression::isA(int kind) const
{
	if(kind == ConstantExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *ConstantExpression::getKindName() const
{
	return "ConstantExpression";
}

MethodCallExpression::MethodCallExpression(string id, ExpressionList * parameters)
	: Expression()
{
	this->kind__ = MethodCallExpression_kind;
	this->id = id;
	this->parameters = parameters;
}

MethodCallExpression::~MethodCallExpression()
{
	// not used
}

string MethodCallExpression::ToString()
#line 400 "tree.tc"
{
    ostringstream out;

    out << this->id << "(" << ListToString(parameters, ", ", false) << ")";

    return out.str();
}
#line 2199 "tree.cpp"

TheNewClass * MethodCallExpression::ValidarSemantica()
#line 1019 "tree.tc"
{
    cout<<"entro aqui en MethodCallExpression";
    list<NewExpression*> *newListExpression = new list<NewExpression*>();
    list<Expression*>::iterator it;
    it = parameters->begin();
    while(it != parameters->end())
    {
        NewExpression * newExpr = (NewExpression*)((*it)->ValidarSemantica());
        cout<<"entro aqui en los parametros";
        newListExpression->push_back(newExpr);
        it++;
    }
    return new NewMethodCallExpression(id,newListExpression);
}
#line 2217 "tree.cpp"

int MethodCallExpression::isA(int kind) const
{
	if(kind == MethodCallExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *MethodCallExpression::getKindName() const
{
	return "MethodCallExpression";
}

LValueExpression::LValueExpression(string id)
	: Expression()
{
	this->kind__ = LValueExpression_kind;
	this->id = id;
	this->expr = NULL;
}

LValueExpression::~LValueExpression()
{
	// not used
}

string LValueExpression::ToString()
#line 538 "tree.tc"
{
    ostringstream out;

    out << this->id;

    if (expr != 0)
      out << "[" << expr->ToString() << "]";

    return out.str();
}
#line 2257 "tree.cpp"

TheNewClass * LValueExpression::ValidarSemantica()
#line 1035 "tree.tc"
{
    NewExpression *newExpr = NULL;
    if(expr != NULL){
        newExpr = (NewExpression*)(expr->ValidarSemantica());
    }
    if(newExpr == NULL && expr != NULL)
    {
        string msj = "Error en valor asignado";
        ErrorSemantico(msj);
        return NULL;
    } 
    else
    {
        if(newExpr!= NULL && newExpr->type != Int && newExpr->type != Boolean)
        {
            string msj = "Valor no asignable";
            ErrorSemantico(msj);
            return  NULL;
        }
    }
    Contexto *cont = contextos[currentContexto];
    return new NewLValueExpression(id,newExpr,cont->currentOffset,cont->currentLevel);
}
#line 2284 "tree.cpp"

int LValueExpression::isA(int kind) const
{
	if(kind == LValueExpression_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *LValueExpression::getKindName() const
{
	return "LValueExpression";
}

ParameterDef::ParameterDef(string id, Type parameterType)
	: Expression()
{
	this->kind__ = ParameterDef_kind;
	this->id = id;
	this->parameterType = parameterType;
}

ParameterDef::~ParameterDef()
{
	// not used
}

string ParameterDef::ToString()
#line 550 "tree.tc"
{
    ostringstream out;    
    out << TypeToString(parameterType) << " " << id; 
    return out.str();
}
#line 2319 "tree.cpp"

TheNewClass * ParameterDef::ValidarSemantica()
#line 1014 "tree.tc"
{
    return new NewParameterDef(id,parameterType);
}
#line 2326 "tree.cpp"

int ParameterDef::isA(int kind) const
{
	if(kind == ParameterDef_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *ParameterDef::getKindName() const
{
	return "ParameterDef";
}

AddExpression::AddExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = AddExpression_kind;
}

AddExpression::~AddExpression()
{
	// not used
}

string AddExpression::ToString()
#line 408 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "+" << this->secondExpression->ToString();
    return out.str();
}
#line 2359 "tree.cpp"

TheNewClass * AddExpression::ValidarSemantica()
#line 709 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && (first->type == Int))
        {
            return new NewAddExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2379 "tree.cpp"

int AddExpression::isA(int kind) const
{
	if(kind == AddExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *AddExpression::getKindName() const
{
	return "AddExpression";
}

SubExpression::SubExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = SubExpression_kind;
}

SubExpression::~SubExpression()
{
	// not used
}

string SubExpression::ToString()
#line 414 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "-" << this->secondExpression->ToString();
    return out.str();
}
#line 2412 "tree.cpp"

TheNewClass * SubExpression::ValidarSemantica()
#line 727 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewSubExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2432 "tree.cpp"

int SubExpression::isA(int kind) const
{
	if(kind == SubExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *SubExpression::getKindName() const
{
	return "SubExpression";
}

MultExpression::MultExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = MultExpression_kind;
}

MultExpression::~MultExpression()
{
	// not used
}

string MultExpression::ToString()
#line 420 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "*" << this->secondExpression->ToString();
    return out.str();
}
#line 2465 "tree.cpp"

TheNewClass * MultExpression::ValidarSemantica()
#line 745 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewMultExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2485 "tree.cpp"

int MultExpression::isA(int kind) const
{
	if(kind == MultExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *MultExpression::getKindName() const
{
	return "MultExpression";
}

DivExpression::DivExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = DivExpression_kind;
}

DivExpression::~DivExpression()
{
	// not used
}

string DivExpression::ToString()
#line 426 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "/" << this->secondExpression->ToString();
    return out.str();
}
#line 2518 "tree.cpp"

TheNewClass * DivExpression::ValidarSemantica()
#line 763 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewDivExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2538 "tree.cpp"

int DivExpression::isA(int kind) const
{
	if(kind == DivExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *DivExpression::getKindName() const
{
	return "DivExpression";
}

LessThanExpression::LessThanExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = LessThanExpression_kind;
}

LessThanExpression::~LessThanExpression()
{
	// not used
}

string LessThanExpression::ToString()
#line 432 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "<" << this->secondExpression->ToString();
    return out.str();
}
#line 2571 "tree.cpp"

TheNewClass * LessThanExpression::ValidarSemantica()
#line 781 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewLessThanExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2591 "tree.cpp"

int LessThanExpression::isA(int kind) const
{
	if(kind == LessThanExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *LessThanExpression::getKindName() const
{
	return "LessThanExpression";
}

LessThanEqualExpression::LessThanEqualExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = LessThanEqualExpression_kind;
}

LessThanEqualExpression::~LessThanEqualExpression()
{
	// not used
}

string LessThanEqualExpression::ToString()
#line 438 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "<=" << this->secondExpression->ToString();
    return out.str();
}
#line 2624 "tree.cpp"

TheNewClass * LessThanEqualExpression::ValidarSemantica()
#line 817 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewLessThanEqualExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2644 "tree.cpp"

int LessThanEqualExpression::isA(int kind) const
{
	if(kind == LessThanEqualExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *LessThanEqualExpression::getKindName() const
{
	return "LessThanEqualExpression";
}

BigerThanExpression::BigerThanExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = BigerThanExpression_kind;
}

BigerThanExpression::~BigerThanExpression()
{
	// not used
}

string BigerThanExpression::ToString()
#line 444 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << ">" << this->secondExpression->ToString();
    return out.str();
}
#line 2677 "tree.cpp"

TheNewClass * BigerThanExpression::ValidarSemantica()
#line 799 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewBigerThanExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2697 "tree.cpp"

int BigerThanExpression::isA(int kind) const
{
	if(kind == BigerThanExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *BigerThanExpression::getKindName() const
{
	return "BigerThanExpression";
}

BigerThanEqualExpression::BigerThanEqualExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = BigerThanEqualExpression_kind;
}

BigerThanEqualExpression::~BigerThanEqualExpression()
{
	// not used
}

string BigerThanEqualExpression::ToString()
#line 450 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << ">=" << this->secondExpression->ToString();
    return out.str();
}
#line 2730 "tree.cpp"

TheNewClass * BigerThanEqualExpression::ValidarSemantica()
#line 835 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewBigerThanEqualExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2750 "tree.cpp"

int BigerThanEqualExpression::isA(int kind) const
{
	if(kind == BigerThanEqualExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *BigerThanEqualExpression::getKindName() const
{
	return "BigerThanEqualExpression";
}

EqualExpression::EqualExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = EqualExpression_kind;
}

EqualExpression::~EqualExpression()
{
	// not used
}

string EqualExpression::ToString()
#line 456 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "==" << this->secondExpression->ToString();
    return out.str();
}
#line 2783 "tree.cpp"

TheNewClass * EqualExpression::ValidarSemantica()
#line 853 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewEqualExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2803 "tree.cpp"

int EqualExpression::isA(int kind) const
{
	if(kind == EqualExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *EqualExpression::getKindName() const
{
	return "EqualExpression";
}

NotEqualExpression::NotEqualExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = NotEqualExpression_kind;
}

NotEqualExpression::~NotEqualExpression()
{
	// not used
}

string NotEqualExpression::ToString()
#line 462 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "!=" << this->secondExpression->ToString();
    return out.str();
}
#line 2836 "tree.cpp"

TheNewClass * NotEqualExpression::ValidarSemantica()
#line 871 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewNotEqualExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2856 "tree.cpp"

int NotEqualExpression::isA(int kind) const
{
	if(kind == NotEqualExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *NotEqualExpression::getKindName() const
{
	return "NotEqualExpression";
}

ShiftRightExpression::ShiftRightExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = ShiftRightExpression_kind;
}

ShiftRightExpression::~ShiftRightExpression()
{
	// not used
}

string ShiftRightExpression::ToString()
#line 468 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << ">>" << this->secondExpression->ToString();
    return out.str();
}
#line 2889 "tree.cpp"

TheNewClass * ShiftRightExpression::ValidarSemantica()
#line 907 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewShiftRightExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2909 "tree.cpp"

int ShiftRightExpression::isA(int kind) const
{
	if(kind == ShiftRightExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *ShiftRightExpression::getKindName() const
{
	return "ShiftRightExpression";
}

ShiftLeftExpression::ShiftLeftExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = ShiftLeftExpression_kind;
}

ShiftLeftExpression::~ShiftLeftExpression()
{
	// not used
}

string ShiftLeftExpression::ToString()
#line 474 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "<<" << this->secondExpression->ToString();
    return out.str();
}
#line 2942 "tree.cpp"

TheNewClass * ShiftLeftExpression::ValidarSemantica()
#line 889 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewShiftLeftExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2962 "tree.cpp"

int ShiftLeftExpression::isA(int kind) const
{
	if(kind == ShiftLeftExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *ShiftLeftExpression::getKindName() const
{
	return "ShiftLeftExpression";
}

RotExpression::RotExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = RotExpression_kind;
}

RotExpression::~RotExpression()
{
	// not used
}

string RotExpression::ToString()
#line 480 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "rot" << this->secondExpression->ToString();
    return out.str();
}
#line 2995 "tree.cpp"

TheNewClass * RotExpression::ValidarSemantica()
#line 925 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewRotExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3015 "tree.cpp"

int RotExpression::isA(int kind) const
{
	if(kind == RotExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *RotExpression::getKindName() const
{
	return "RotExpression";
}

OrExpression::OrExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = OrExpression_kind;
}

OrExpression::~OrExpression()
{
	// not used
}

string OrExpression::ToString()
#line 498 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "||" << this->secondExpression->ToString();
    return out.str();
}
#line 3048 "tree.cpp"

TheNewClass * OrExpression::ValidarSemantica()
#line 943 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewOrExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3068 "tree.cpp"

int OrExpression::isA(int kind) const
{
	if(kind == OrExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *OrExpression::getKindName() const
{
	return "OrExpression";
}

AndExpression::AndExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = AndExpression_kind;
}

AndExpression::~AndExpression()
{
	// not used
}

string AndExpression::ToString()
#line 492 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "&&" << this->secondExpression->ToString();
    return out.str();
}
#line 3101 "tree.cpp"

TheNewClass * AndExpression::ValidarSemantica()
#line 961 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewAndExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3121 "tree.cpp"

int AndExpression::isA(int kind) const
{
	if(kind == AndExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *AndExpression::getKindName() const
{
	return "AndExpression";
}

ModExpression::ModExpression(Expression * firstExpression, Expression * secondExpression)
	: BinaryExpression(firstExpression, secondExpression)
{
	this->kind__ = ModExpression_kind;
}

ModExpression::~ModExpression()
{
	// not used
}

string ModExpression::ToString()
#line 504 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "%" << this->secondExpression->ToString();
    return out.str();
}
#line 3154 "tree.cpp"

TheNewClass * ModExpression::ValidarSemantica()
#line 979 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            return new NewModExpression(first,second);
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3174 "tree.cpp"

int ModExpression::isA(int kind) const
{
	if(kind == ModExpression_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *ModExpression::getKindName() const
{
	return "ModExpression";
}

NotExpression::NotExpression(Expression * firstExpression)
	: UnaryExpression(firstExpression)
{
	this->kind__ = NotExpression_kind;
}

NotExpression::~NotExpression()
{
	// not used
}

string NotExpression::ToString()
#line 486 "tree.tc"
{
    ostringstream out;
    out <<  "!" << this->firstExpression->ToString();
    return out.str();
}
#line 3207 "tree.cpp"

TheNewClass * NotExpression::ValidarSemantica()
#line 997 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    
    if(first != NULL )
    {
        if(first->type == Boolean)
        {
            return new NewNotExpression(first);
        }
        ErrorSemantico("Error: Tipo Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3226 "tree.cpp"

int NotExpression::isA(int kind) const
{
	if(kind == NotExpression_kind)
		return 1;
	else
		return UnaryExpression::isA(kind);
}

const char *NotExpression::getKindName() const
{
	return "NotExpression";
}

ConstantIntExpression::ConstantIntExpression(int constant)
	: ConstantExpression()
{
	this->kind__ = ConstantIntExpression_kind;
	this->constant = constant;
}

ConstantIntExpression::~ConstantIntExpression()
{
	// not used
}

string ConstantIntExpression::ToString()
#line 510 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3260 "tree.cpp"

TheNewClass * ConstantIntExpression::ValidarSemantica()
#line 1060 "tree.tc"
{
    return new NewConstantIntExpression(constant);
}
#line 3267 "tree.cpp"

int ConstantIntExpression::isA(int kind) const
{
	if(kind == ConstantIntExpression_kind)
		return 1;
	else
		return ConstantExpression::isA(kind);
}

const char *ConstantIntExpression::getKindName() const
{
	return "ConstantIntExpression";
}

ConstantBoolExpression::ConstantBoolExpression(bool constant)
	: ConstantExpression()
{
	this->kind__ = ConstantBoolExpression_kind;
	this->constant = constant;
}

ConstantBoolExpression::~ConstantBoolExpression()
{
	// not used
}

string ConstantBoolExpression::ToString()
#line 517 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3301 "tree.cpp"

TheNewClass * ConstantBoolExpression::ValidarSemantica()
#line 1075 "tree.tc"
{
    return new NewConstantBoolExpression(constant);
}
#line 3308 "tree.cpp"

int ConstantBoolExpression::isA(int kind) const
{
	if(kind == ConstantBoolExpression_kind)
		return 1;
	else
		return ConstantExpression::isA(kind);
}

const char *ConstantBoolExpression::getKindName() const
{
	return "ConstantBoolExpression";
}

ConstantCharExpression::ConstantCharExpression(char constant)
	: ConstantExpression()
{
	this->kind__ = ConstantCharExpression_kind;
	this->constant = constant;
}

ConstantCharExpression::~ConstantCharExpression()
{
	// not used
}

string ConstantCharExpression::ToString()
#line 531 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3342 "tree.cpp"

TheNewClass * ConstantCharExpression::ValidarSemantica()
#line 1065 "tree.tc"
{
    return new NewConstantCharExpression(constant);
}
#line 3349 "tree.cpp"

int ConstantCharExpression::isA(int kind) const
{
	if(kind == ConstantCharExpression_kind)
		return 1;
	else
		return ConstantExpression::isA(kind);
}

const char *ConstantCharExpression::getKindName() const
{
	return "ConstantCharExpression";
}

ConstantStringExpression::ConstantStringExpression(string constant)
	: ConstantExpression()
{
	this->kind__ = ConstantStringExpression_kind;
	this->constant = constant;
}

ConstantStringExpression::~ConstantStringExpression()
{
	// not used
}

string ConstantStringExpression::ToString()
#line 524 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3383 "tree.cpp"

TheNewClass * ConstantStringExpression::ValidarSemantica()
#line 1070 "tree.tc"
{
    return new NewConstantStringExpression(constant);
}
#line 3390 "tree.cpp"

int ConstantStringExpression::isA(int kind) const
{
	if(kind == ConstantStringExpression_kind)
		return 1;
	else
		return ConstantExpression::isA(kind);
}

const char *ConstantStringExpression::getKindName() const
{
	return "ConstantStringExpression";
}

VariableDef::VariableDef(string id, int first_line, int first_column)
	: Statement()
{
	this->kind__ = VariableDef_kind;
	this->id = id;
	this->first_line = first_line;
	this->first_column = first_column;
}

VariableDef::~VariableDef()
{
	// not used
}

string VariableDef::ToString()
#line 568 "tree.tc"
{
    ostringstream out;
    out << TypeToString(variable_type) << " " << id;
    if(isArrayDef){
      out << "[" << array_dimension << "]";
    }else if(initial_value != 0){
      out << "=" << initial_value->ToString();
    }
    out << ";";
    return out.str();
}
#line 3432 "tree.cpp"

TheNewClass * VariableDef::ValidarSemantica()
#line 1317 "tree.tc"
{
    Variable *var = contextos[currentContexto]->contextoMap[id];
    if(var != NULL){
      string error = "Variable ya definida";
      ErrorSemantico(error);
      return NULL;
    }
    contextos[currentContexto]->currentOffset+=1;
    int offset = contextos[currentContexto]->currentOffset;
    int level = contextos[currentContexto]->currentLevel;
    Variable *newVariable;
    if(isArrayDef)
    {
        newVariable = new Variable(offset,level,0,true,array_dimension,false,variable_type);
    }
    else
    {
        NewConstantExpression * expr = (NewConstantExpression*)initial_value->ValidarSemantica();
        if(dynamic_cast<NewConstantIntExpression*>(expr) != NULL){
            NewConstantIntExpression *intExpr = (NewConstantIntExpression*)expr;    
            newVariable = new Variable(offset,level,intExpr->Newconstant,false,0,false,variable_type);
        }
        else
        {
            if(dynamic_cast<NewConstantBoolExpression*>(expr) != NULL){
                NewConstantBoolExpression *boolExpr = (NewConstantBoolExpression*)expr;
                if(boolExpr->Newconstant)
                    newVariable = new Variable(offset,level,1,false,0,false,variable_type);
                else
                    newVariable = new Variable(offset,level,0,false,0,false,variable_type);
            }
        }
    }
    contextos[currentContexto]->contextoMap[id] = newVariable;
    return NULL;
}
#line 3472 "tree.cpp"

int VariableDef::isA(int kind) const
{
	if(kind == VariableDef_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *VariableDef::getKindName() const
{
	return "VariableDef";
}

MethodDef::MethodDef(string id)
	: Statement()
{
	this->kind__ = MethodDef_kind;
	this->id = id;
}

MethodDef::~MethodDef()
{
	// not used
}

string MethodDef::ToString()
#line 557 "tree.tc"
{
    ostringstream out;
    out << TypeToString(returnType) << " " << id << "(";
    if (parameters != 0)
      out << ListToString(parameters, ",", false);
    out << ")" << endl;
    out << block->ToString();
    return out.str();
}
#line 3510 "tree.cpp"

TheNewClass * MethodDef::ValidarSemantica()
#line 1272 "tree.tc"
{
  Contexto *contestoActual = contextos[currentContexto];
  currentContexto += 1;

  Contexto *contextoNuevo = new Contexto();
  contextoNuevo->currentLevel = 0;
  contextoNuevo->currentOffset = 1;

  list<ParameterDef *>::iterator it;
  if(parameters != NULL){
      it = parameters->begin();
      while(it != parameters->end())
      {
        NewParameterDef *param = (NewParameterDef*)(*it)->ValidarSemantica();
        string str = param->newId;
        Type tipo = param->newParameterType;
        Variable *var = new Variable(contextoNuevo->currentOffset,contextoNuevo->currentLevel,0,false,0,true,tipo);
        if(contextoNuevo->contextoMap[str] != NULL){
          string str = "Parametros repetidos";
          ErrorSemantico(str);
          return NULL;
        }else{
          contextoNuevo->contextoMap[str] = var;
          contextoNuevo->currentOffset += 1;
        }
        it++;
      }
  }
  contextos[currentContexto] = contextoNuevo;
  contextoNuevo->contextoAnterior = contestoActual;
  cout<<"funcion: "<<id<<endl;
  NewBlockStatement *newBlockStatement = (NewBlockStatement*)(block->ValidarSemantica());
  //NewBlockStatement *newBlockStatement = NULL;
  if(methodDeclared[id] != NULL)
  {
    string str = "Metodo ya definido";
    ErrorSemantico(str);
    return NULL;
  }
  Procedimiento *p = new Procedimiento(id,newBlockStatement);
  methodDeclared[id] = p;
  return NULL;
}
#line 3557 "tree.cpp"

int MethodDef::isA(int kind) const
{
	if(kind == MethodDef_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *MethodDef::getKindName() const
{
	return "MethodDef";
}

IfStatement::IfStatement(Expression * condition, Statement * statementTrue, Statement * statementFalse, int first_line, int first_column)
	: Statement()
{
	this->kind__ = IfStatement_kind;
	this->condition = condition;
	this->statementTrue = statementTrue;
	this->statementFalse = statementFalse;
	this->first_line = first_line;
	this->first_column = first_column;
}

IfStatement::~IfStatement()
{
	// not used
}

string IfStatement::ToString()
#line 600 "tree.tc"
{
    ostringstream out;
    out << "if (" << condition->ToString() << ")" << endl;
    out << statementTrue->ToString() << endl;

    if (statementFalse != 0) {
		  out << "else" << endl;
		  out << statementFalse->ToString() << endl;
    }

    return out.str();
}
#line 3602 "tree.cpp"

TheNewClass * IfStatement::ValidarSemantica()
#line 1082 "tree.tc"
{
    NewExpression *newCondition = (NewExpression*)condition->ValidarSemantica();
    if(newCondition == NULL)
        return NULL;
    if(newCondition->type != Boolean)
    {
        ErrorSemantico("Error: Condicion if debe se bool");
        return NULL;
    }
    NewStatement *newTrueBlock = (NewStatement*)statementTrue->ValidarSemantica();
    NewStatement *newFalseBlock;
    if(newTrueBlock == NULL)
        return NULL;
    if(statementFalse != NULL)
    {
        newFalseBlock = (NewStatement*)statementFalse->ValidarSemantica();
        if(newFalseBlock == NULL)
            return NULL;
    }
    return new NewIfStatement(newCondition,newTrueBlock,newFalseBlock);
}
#line 3627 "tree.cpp"

int IfStatement::isA(int kind) const
{
	if(kind == IfStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *IfStatement::getKindName() const
{
	return "IfStatement";
}

WhileStatement::WhileStatement(Expression * condition, Statement * statementTrue, int first_line, int first_column)
	: Statement()
{
	this->kind__ = WhileStatement_kind;
	this->condition = condition;
	this->statementTrue = statementTrue;
	this->first_line = first_line;
	this->first_column = first_column;
}

WhileStatement::~WhileStatement()
{
	// not used
}

string WhileStatement::ToString()
#line 614 "tree.tc"
{
    ostringstream out;
    out << "while (" << condition->ToString() << ")" << endl;
    out << "{" << statementTrue->ToString() << endl << "}";
    return out.str();
}
#line 3665 "tree.cpp"

TheNewClass * WhileStatement::ValidarSemantica()
#line 1105 "tree.tc"
{
    NewExpression *newCondition = (NewExpression*)condition->ValidarSemantica();
    if(newCondition == NULL)
        return NULL;
    if(newCondition->type == Boolean)
    {
        ErrorSemantico("Error: Condicion if debe se bool");
        return NULL;                       
    }

    NewStatement *newStatementTrue = (NewStatement*)statementTrue->ValidarSemantica();
    if(newStatementTrue == NULL)
        return NULL;

    return new NewWhileStatement(newCondition,newStatementTrue);
}
#line 3685 "tree.cpp"

int WhileStatement::isA(int kind) const
{
	if(kind == WhileStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *WhileStatement::getKindName() const
{
	return "WhileStatement";
}

ForStatement::ForStatement(Statement * firstListAssign, Expression * condition, Statement * lastListAssign, Statement * statementTrue, int first_line, int first_column)
	: Statement()
{
	this->kind__ = ForStatement_kind;
	this->firstListAssign = firstListAssign;
	this->condition = condition;
	this->lastListAssign = lastListAssign;
	this->statementTrue = statementTrue;
	this->first_line = first_line;
	this->first_column = first_column;
}

ForStatement::~ForStatement()
{
	// not used
}

string ForStatement::ToString()
#line 622 "tree.tc"
{
    ostringstream out;
    out << "for(";
    out << firstListAssign->ToString() << ";" << condition->ToString() << ";" << lastListAssign->ToString() <<")";
    out << statementTrue->ToString();

    return out.str();
}
#line 3727 "tree.cpp"

TheNewClass * ForStatement::ValidarSemantica()
#line 1123 "tree.tc"
{
    NewStatement *newFirstListAssign = (NewStatement*)firstListAssign->ValidarSemantica();
    if(newFirstListAssign == NULL)
        return NULL;

    NewExpression *newCondition = (NewExpression*)condition->ValidarSemantica();
    if(newCondition == NULL)
        return NULL;

    if(newCondition->type != Boolean)
        return NULL;

    NewStatement *newLastListAssign = (NewStatement*)lastListAssign->ValidarSemantica();
    if(newLastListAssign == NULL)
        return NULL;

    NewStatement *newStatementTrue = (NewStatement*)statementTrue->ValidarSemantica();
    if(newStatementTrue == NULL)
        return NULL;

    return new NewForStatement(newFirstListAssign,newCondition,newLastListAssign,newStatementTrue);
}
#line 3753 "tree.cpp"

int ForStatement::isA(int kind) const
{
	if(kind == ForStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ForStatement::getKindName() const
{
	return "ForStatement";
}

AssignStatement::AssignStatement(Expression * leftValue, Expression * value, int first_line, int first_column)
	: Statement()
{
	this->kind__ = AssignStatement_kind;
	this->leftValue = leftValue;
	this->value = value;
	this->first_line = first_line;
	this->first_column = first_column;
}

AssignStatement::~AssignStatement()
{
	// not used
}

string AssignStatement::ToString()
#line 632 "tree.tc"
{
    ostringstream out;
    out << "// Linea " << first_line << " Columna " << first_column << "\n"; 
    out << leftValue->ToString() << " = " << value->ToString() << ";";
    return out.str();
}
#line 3791 "tree.cpp"

TheNewClass * AssignStatement::ValidarSemantica()
#line 1231 "tree.tc"
{
    NewExpression *newLeftValue = (NewExpression*)leftValue->ValidarSemantica();
    if(newLeftValue == NULL)
        return NULL;

    NewExpression *newValue = (NewExpression*)value->ValidarSemantica();
    if(newValue == NULL)
        return NULL;

    return new NewAssignStatement(newLeftValue,newValue);
}
#line 3806 "tree.cpp"

int AssignStatement::isA(int kind) const
{
	if(kind == AssignStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *AssignStatement::getKindName() const
{
	return "AssignStatement";
}

ReadStatement::ReadStatement(ExpressionList * listExpression, int first_line, int first_column)
	: Statement()
{
	this->kind__ = ReadStatement_kind;
	this->listExpression = listExpression;
	this->first_line = first_line;
	this->first_column = first_column;
}

ReadStatement::~ReadStatement()
{
	// not used
}

string ReadStatement::ToString()
#line 581 "tree.tc"
{
    ostringstream out;
    out << "read ";
    if (listExpression != 0)
      out << ListToString(listExpression, ",", false);
    return out.str();
}
#line 3844 "tree.cpp"

TheNewClass * ReadStatement::ValidarSemantica()
#line 1194 "tree.tc"
{
    list<NewExpression*> *newListExpression = new list<NewExpression*>();
    if(listExpression == NULL)
        return NULL;

    list<Expression*>::iterator it;
    it = listExpression->begin();
    while(it != listExpression->end()) {
        Expression *exprTemp = *it;
        NewExpression *newExpr = (NewExpression*)exprTemp->ValidarSemantica();
        if(newExpr == NULL)
            return NULL;
        newListExpression->push_back(newExpr);
        it++;
    }
    return new NewReadStatement(newListExpression);
}
#line 3865 "tree.cpp"

int ReadStatement::isA(int kind) const
{
	if(kind == ReadStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ReadStatement::getKindName() const
{
	return "ReadStatement";
}

PrintStatement::PrintStatement(ExpressionList * listExpression, int first_line, int first_column)
	: Statement()
{
	this->kind__ = PrintStatement_kind;
	this->listExpression = listExpression;
	this->first_line = first_line;
	this->first_column = first_column;
}

PrintStatement::~PrintStatement()
{
	// not used
}

string PrintStatement::ToString()
#line 590 "tree.tc"
{
    ostringstream out;
    out << "print ";
    if (listExpression != 0)
      out << ListToString(listExpression, ",", false);
    out << ";";
    return out.str();
}
#line 3904 "tree.cpp"

TheNewClass * PrintStatement::ValidarSemantica()
#line 1213 "tree.tc"
{
    list<NewExpression*> *newListExpression = new list<NewExpression*>();
    if(listExpression == NULL)
        return NULL;

    list<Expression*>::iterator it = listExpression->begin();
    while(it != listExpression->end()) {
        Expression *exprTemp = *it;
        NewExpression *newExpr = (NewExpression*)exprTemp->ValidarSemantica();
        if(newExpr == NULL)
            return NULL;
        newListExpression->push_back(newExpr);
        it++;
    }
    return new NewPrintStatement(newListExpression);
}
#line 3924 "tree.cpp"

int PrintStatement::isA(int kind) const
{
	if(kind == PrintStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *PrintStatement::getKindName() const
{
	return "PrintStatement";
}

MethodCallStatement::MethodCallStatement(string id, ExpressionList * parameters, int first_line, int first_column)
	: Statement()
{
	this->kind__ = MethodCallStatement_kind;
	this->id = id;
	this->parameters = parameters;
	this->first_line = first_line;
	this->first_column = first_column;
}

MethodCallStatement::~MethodCallStatement()
{
	// not used
}

string MethodCallStatement::ToString()
#line 640 "tree.tc"
{
    return this->id + "(" + ListToString(parameters, ", ", false) + ");";
}
#line 3959 "tree.cpp"

TheNewClass * MethodCallStatement::ValidarSemantica()
#line 1244 "tree.tc"
{
  if(methodDeclared[id]!= NULL)
  {
    string str = "Metodo no declarado";
    ErrorSemantico(str);
    return NULL;
  }

  list<NewExpression*> *newListExpression = new list<NewExpression*>();

  list<Expression*>::iterator it;
  it = parameters->begin();
  while(it != parameters->end()){
    NewExpression * newExpr = (NewExpression*)((*it)->ValidarSemantica());
    if(newExpr == NULL)
    {
      string str = "Error";
      ErrorSemantico(str);
      return NULL;
    }
    newListExpression->push_back(newExpr);
    it++;  
  }

  return new NewMethodCallStatement(id,newListExpression);
}
#line 3989 "tree.cpp"

int MethodCallStatement::isA(int kind) const
{
	if(kind == MethodCallStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *MethodCallStatement::getKindName() const
{
	return "MethodCallStatement";
}

ReturnStatement::ReturnStatement(Expression * returnExpression, int first_line, int first_column)
	: Statement()
{
	this->kind__ = ReturnStatement_kind;
	this->returnExpression = returnExpression;
	this->first_line = first_line;
	this->first_column = first_column;
}

ReturnStatement::~ReturnStatement()
{
	// not used
}

string ReturnStatement::ToString()
#line 645 "tree.tc"
{
    return "return " + returnExpression->ToString() + ";";
}
#line 4023 "tree.cpp"

TheNewClass * ReturnStatement::ValidarSemantica()
#line 1147 "tree.tc"
{
    NewExpression *newReturnExpression = (NewExpression*)returnExpression->ValidarSemantica();
    if(newReturnExpression != NULL)
        return NULL;
    return new NewReturnStatement(newReturnExpression);
}
#line 4033 "tree.cpp"

int ReturnStatement::isA(int kind) const
{
	if(kind == ReturnStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ReturnStatement::getKindName() const
{
	return "ReturnStatement";
}

BreakStatement::BreakStatement(int first_line, int first_column)
	: Statement()
{
	this->kind__ = BreakStatement_kind;
	this->first_line = first_line;
	this->first_column = first_column;
}

BreakStatement::~BreakStatement()
{
	// not used
}

string BreakStatement::ToString()
#line 650 "tree.tc"
{
    return "break;";
}
#line 4066 "tree.cpp"

TheNewClass * BreakStatement::ValidarSemantica()
#line 1355 "tree.tc"
{
    return new NewBreakStatement();
}
#line 4073 "tree.cpp"

int BreakStatement::isA(int kind) const
{
	if(kind == BreakStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *BreakStatement::getKindName() const
{
	return "BreakStatement";
}

ContinueStatement::ContinueStatement(int first_line, int first_column)
	: Statement()
{
	this->kind__ = ContinueStatement_kind;
	this->first_line = first_line;
	this->first_column = first_column;
}

ContinueStatement::~ContinueStatement()
{
	// not used
}

string ContinueStatement::ToString()
#line 655 "tree.tc"
{
    return "continue;";
}
#line 4106 "tree.cpp"

TheNewClass * ContinueStatement::ValidarSemantica()
#line 1360 "tree.tc"
{
    return new NewContinueStatement();
}
#line 4113 "tree.cpp"

int ContinueStatement::isA(int kind) const
{
	if(kind == ContinueStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ContinueStatement::getKindName() const
{
	return "ContinueStatement";
}

BlockStatement::BlockStatement(int first_line, int first_column)
	: Statement()
{
	this->kind__ = BlockStatement_kind;
	this->first_line = first_line;
	this->first_column = first_column;
}

BlockStatement::~BlockStatement()
{
	// not used
}

string BlockStatement::ToString()
#line 660 "tree.tc"
{
    ostringstream out;

    out << "{" << endl;

    if (listStatements != 0)
		  out << ListToString(listStatements, "\n", true);

    out << "}";

    return out.str();
}
#line 4155 "tree.cpp"

TheNewClass * BlockStatement::ValidarSemantica()
#line 1155 "tree.tc"
{
    list<NewStatement*> *newListStatement = new list<NewStatement*>();
    if(listStatements == NULL){
        return NULL;
    }

    list<Statement*>::iterator it;
    it = listStatements->begin();
    while(it != listStatements->end()) {
        Statement *stmTemp = *it;
        NewStatement *newStm ;
        if(dynamic_cast<BlockStatement*>(stmTemp)!= NULL)
        {
          cout<<"entro1" << endl;
          currentContexto += 1; 
          newStm = (NewStatement*)stmTemp->ValidarSemantica();
          currentContexto -= 1;
          cout<<"entro2" << endl;
        }
        else
        {
          cout<<"entro3" << endl;
          newStm = (NewStatement*)(stmTemp->ValidarSemantica());
          cout<<"entro4" << endl;
        }
        if(newStm == NULL){
            string str = "Error en el bloque ";
            ErrorSemantico(str);
            return NULL;
        }
        newListStatement->push_back(newStm);
        it++;
    }
    NewBlockStatement *newblock = new NewBlockStatement(); 
    newblock->newListStatements = newListStatement;
    return newblock;
}
#line 4196 "tree.cpp"

void BlockStatement::AddStatement(Statement * stm)
#line 392 "tree.tc"
{
    if(listStatements == 0)
      listStatements = new StatementList();
      
    listStatements->push_back(stm);
}
#line 4206 "tree.cpp"

int BlockStatement::isA(int kind) const
{
	if(kind == BlockStatement_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *BlockStatement::getKindName() const
{
	return "BlockStatement";
}

void *Main::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Main::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Main::Main(StatementList * list)
{
	this->kind__ = Main_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->list = list;
}

Main::~Main()
{
	// not used
}

int Main::isA(int kind) const
{
	if(kind == Main_kind)
		return 1;
	else
		return 0;
}

const char *Main::getKindName() const
{
	return "Main";
}

void *Procedimiento::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Procedimiento::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Procedimiento::Procedimiento(string id, NewBlockStatement * newBlockStatement)
{
	this->kind__ = Procedimiento_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->id = id;
	this->newBlockStatement = newBlockStatement;
}

Procedimiento::~Procedimiento()
{
	// not used
}

int Procedimiento::isA(int kind) const
{
	if(kind == Procedimiento_kind)
		return 1;
	else
		return 0;
}

const char *Procedimiento::getKindName() const
{
	return "Procedimiento";
}

