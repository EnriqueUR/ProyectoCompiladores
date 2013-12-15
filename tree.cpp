/* tree.cpp.  Generated automatically by treecc */
#line 43 "tree.tc"


#include "tree.h"

map<string,string> variableStringMap;
list<string> listVariableName;

list<string> arrayList;

list<string> stackCurrentLabelBreak;
list<string> stackCurrentLabelContinue;

list<string> listElseLabel;
list<string> listIfLabel;
list<string> listEndIfLabel;

list<string> listStartWhileLabel;
list<string> listWhileLabel;
list<string> listEndWhileLabel;

list<string> listStartForLabel;
list<string> listForLabel;
list<string> listEndForLabel;
list<string> listContinuePointFor;

list<string> listRegister;
list<string> listRegisterS;

void FreeRegister(string reg)
{
   if(reg != ""){
    listRegister.push_back(reg);
    listRegister.unique();
   }
} 
string getFreeRegister()
{
    int cant = listRegister.size(); 
    if( cant > 0){
        string reg = listRegister.back(); 
        listRegister.pop_back(); 
        return reg;
    }else
        return "NULL";
}
void iniciarRegistros()
{
    for(int i=0;i<8;i++)
    {
      ostringstream reg;
      reg << "$t" << i;
      listRegister.push_front(reg.str());
    }
}

void FreeRegisterS(string reg)
{
   if(reg != ""){
    listRegister.push_back(reg);
    listRegister.unique();
   }
} 
string getFreeRegisterS()
{
    int cant = listRegister.size(); 
    if( cant > 0){
        string reg = listRegister.back(); 
        listRegister.pop_back(); 
        return reg;
    }else
        return "NULL";
}
void iniciarRegistrosS()
{
    for(int i=0;i<4;i++)
    {
      ostringstream reg;
      reg << "$a" << i;
      listRegister.push_front(reg.str());
    }
}

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

string getLabel(string label){
    if(label == "if")
    {
        ostringstream out;
        int indice = listIfLabel.size();
        out <<"if"<<indice;
        listIfLabel.push_back(out.str());
        return out.str();
    }
    if(label == "else")
    {
        ostringstream out;
        int indice = listElseLabel.size();
        out <<"else"<<indice;
        listElseLabel.push_back(out.str());
        return out.str();
    }
    if(label == "endIf")
    {
        ostringstream out;
        int indice = listEndIfLabel.size();
        out <<"endIf"<<indice;
        listEndIfLabel.push_back(out.str());
        return out.str();
    }
    if(label == "startWhile")
    {
        ostringstream out;
        int indice = listStartWhileLabel.size();
        out <<"startWhile"<<indice;
        listStartWhileLabel.push_back(out.str());
        return out.str();
    }
    if(label == "while")
    {
        ostringstream out;
        int indice = listStartWhileLabel.size();
        out <<"while"<<indice;
        listWhileLabel.push_back(out.str());
        return out.str();
    }
    if(label == "endWhile")
    {
        ostringstream out;
        int indice = listEndWhileLabel.size();
        out <<"endWhile"<<indice;
        listEndWhileLabel.push_back(out.str());
        return out.str();
    }
    if(label == "startFor")
    {
        ostringstream out;
        int indice = listStartForLabel.size();
        out <<"startFor"<<indice;
        listStartForLabel.push_back(out.str());
        return out.str();
    }
    if(label == "for")
    {
        ostringstream out;
        int indice = listForLabel.size();
        out <<"for"<<indice;
        listForLabel.push_back(out.str());
        return out.str();
    }
    if(label == "endFor")
    {
        ostringstream out;
        int indice = listEndForLabel.size();
        out <<"endFor"<<indice;
        listEndForLabel.push_back(out.str());
        return out.str();
    }
    if(label == "continuePoint")
    {
        ostringstream out;
        int indice = listContinuePointFor.size();
        out <<"continuePoint"<<indice;
        listContinuePointFor.push_back(out.str());
        return out.str();
    }
    if(label == "var_str")
    {
        ostringstream out;
        int indice = listVariableName.size();
        out <<"var_str"<<indice;
        listVariableName.push_back(out.str());
        return out.str();
    }
    
    return "";

}

map<string,Procedimiento *> methodDeclared;
map<string,Variable*> variableDeclared; 
int currentOffset = 0;

int currentContexto = 0; 
Contexto *contextos[10];

#line 200 "tree.cpp"

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
#line 479 "tree.cpp"
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
#line 1669 "tree.tc"
{
  currentContexto = 0;
  iniciarRegistros();
  ostringstream nuevo;
  Contexto *contextoTemp = contextos[0];
  map<string,Variable*>::iterator it1;
  it1 = variableDeclared.begin();
  nuevo << ".data \n";
  while(it1 != variableDeclared.end())
  {
    Variable *var = it1->second;
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
  map<string,string>::iterator mapIt;
  mapIt = variableStringMap.begin();
  while(mapIt != variableStringMap.end()) {
      nuevo << (*mapIt).first << ": \n";
      nuevo << ".asciiz " << (*mapIt).second  << "\n"; 
      mapIt++;
  }
  nuevo << ".text \n";

  nuevo << "main: \n";
  nuevo << newBlockStatement->GenerarCodigo();
  nuevo << "j end"<<endl;
  ostringstream epilogo,prologo;
  
  epilogo << "";
  map<string,Procedimiento*>::iterator it2;
  it2 = methodDeclared.begin();
  while(it2 != methodDeclared.end()) {
      Procedimiento*pro = (*it2).second;
      if(pro->id != "main" ){
        
        nuevo << pro->id << ": \n";
        prologo << "addi $sp, $sp, -32 " << endl;
        for (int i = 0; i < 8; i++) {
            prologo << "sw $s" << i << ", " << (i*4) << "($sp)" << endl;
        }
        prologo << "addi " << "$sp, " << "$sp, " << "-8"<<endl;
        prologo << "sw $ra, 0($sp)"<<endl;
        prologo << "sw $fp, 4($sp)"<<endl; 

        Contexto *con = contextos[0];
        map<string,Variable*>::iterator varIt;
        varIt = con->contextoMap.begin();
        while(varIt != con->contextoMap.end()) {
             Variable *var = varIt->second;
             /*if(var->isParameter)
             {
                prologo << "sw "<< << ", " << var->offset*4 << "($sp)";
             }*/
             varIt++;
         } 
        nuevo << prologo.str();
        nuevo << pro->newBlockStatement->GenerarCodigo();
        
        epilogo << "lw $ra, 0($sp)"<<endl;
        epilogo << "lw $fp, 4($sp)"<<endl;
        epilogo << "addi $sp, $sp, 8"<<endl;
        for (int i = 0; i < 8; i++) {
            epilogo << "lw $s" << i << ", " << (i*4) << "($sp)" << endl;
        }
        epilogo << "addi $sp, $sp, 32" << endl; 
        nuevo << epilogo.str();
        nuevo << "jr $ra"<< endl;
        nuevo << "end:" <<endl;
      }
      it2++;
  }
  

  return nuevo.str();   
}
#line 632 "tree.cpp"

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
#line 2351 "tree.tc"
{return "NADA \n";}
#line 786 "tree.cpp"

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
	this->isGlobal = false;
	this->isParameter = false;
	this->isLocal = false;
}

NewLValueExpression::~NewLValueExpression()
{
	// not used
}

string NewLValueExpression::GenerarCodigo()
#line 2264 "tree.tc"
{
    ostringstream nuevo;

    string regS = getFreeRegisterS();
    Contexto *context = contextos[0];

   // if (isGlobal) 
   // {    
        nuevo << "la " << regS << ", " << newId << endl;
        if (newExpr != NULL) {
            nuevo << newExpr->GenerarCodigo();
            nuevo << "sll " << newExpr->place << ", " << newExpr->place << ", 2" << endl;
            nuevo << "add " << regS << ", " << regS << ", "<< newExpr->place << endl;
        }
        
   /* }
     else if (isParameter) {
        nuevo << "addi " << regS << ", $fp, " << (offset*4)*-1 << endl;
    }
     else 
    {
        nuevo << "la " << regS << ", display" << endl;
        nuevo << "addi " << regS << ", " << regS << ", " << (level*4) << endl;
        nuevo << "lw " << regS << ", 0(" << regS << ")" << endl;
        nuevo << "addi " << regS << ", " << regS << ", " << (offset * 4)+4 << endl;
      }*/
    nuevo <<"lw " << regS << ", 0(" << regS << ")" << endl;
    this->place = regS;

    return nuevo.str();
}
#line 852 "tree.cpp"

string NewLValueExpression::GetDirLValue()
#line 2355 "tree.tc"
{
 ostringstream nuevo;

    string regS = getFreeRegisterS();
    Contexto *context = contextos[0];

    //if (isGlobal) 
    //{    
        nuevo << "la " << regS << ", " << newId << endl;
        if (newExpr != NULL) {
            nuevo << newExpr->GenerarCodigo();
            nuevo << "sll " << newExpr->place << ", " << newExpr->place << ", 2" << endl;
            nuevo << "add " << regS << ", " << regS << ", "<< newExpr->place << endl;
        }
        
    /*}
     else if (isParameter) {
        nuevo << "addi " << regS << ", $fp, " << (offset*4)*-1 << endl;
    }
     else 
    {
        nuevo << "la " << regS << ", display" << endl;
        nuevo << "addi " << regS << ", " << regS << ", " << (level*4) << endl;
        nuevo << "lw " << regS << ", 0(" << regS << ")" << endl;
        nuevo << "addi " << regS << ", " << regS << ", " << (offset * 4)+4 << endl;
      }*/
    this->place = regS;

    return nuevo.str();
}
#line 886 "tree.cpp"

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
#line 2297 "tree.tc"
{
   ostringstream nuevo;
    if(newParameters != NULL){
       list<NewExpression *>::iterator it;
       it = newParameters->begin();
       int parameterCount = newParameters->size();
       nuevo << "addi " << "$sp, $sp, " << (-1 * (parameterCount*4)) << "\n";
       while(it != newParameters->end())
       {   
           NewExpression * newExpr = *it; 
           string reg = getFreeRegister();
           nuevo << "sw " << (newExpr->indice * 4)<<"($sp)" << "\n";
           FreeRegister(reg);
           it++;
       }
     }
     place = "$v0";
    return nuevo.str();
}
#line 935 "tree.cpp"

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
#line 2230 "tree.tc"
{
   ostringstream nuevo;
   
   string reg = getFreeRegister();
   nuevo << "li " << reg <<", "<< Newconstant << "\n";
   place = reg;

   return nuevo.str();
}
#line 973 "tree.cpp"

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
#line 2255 "tree.tc"
{
    ostringstream nuevo;
    string reg = getFreeRegister();
    nuevo << "la "<< reg <<", "<< Newconstant << "\n"; 
    place = reg;
    return nuevo.str();
}
#line 1009 "tree.cpp"

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
#line 2241 "tree.tc"
{
   ostringstream nuevo;
   
   string reg = getFreeRegister();
   if(Newconstant)
      nuevo << "li " << reg <<", 1"<<"\n";
   else
      nuevo << "li " << reg <<", 0"<<"\n";
   place = reg;

   return nuevo.str();
}
#line 1050 "tree.cpp"

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
#line 2349 "tree.tc"
{return "NADA \n";}
#line 1080 "tree.cpp"

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
#line 1773 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo ;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "add " << reg <<","<<newfirstExpression->place<<","<<newSecondExpression->place << "\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1122 "tree.cpp"

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
#line 1789 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "sub "<< reg <<","<<newfirstExpression->place<<","<<newSecondExpression->place << "\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1164 "tree.cpp"

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
#line 1805 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "mul "<< reg <<", "<<newfirstExpression->place<<", "<<newSecondExpression->place<<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1206 "tree.cpp"

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
#line 1821 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "div "<< reg <<", " <<newfirstExpression->place<<", "<<newSecondExpression->place<< "\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1248 "tree.cpp"

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
#line 1837 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "slt "<< reg << ", "<<newfirstExpression->place<<", "<<newSecondExpression->place << "\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();   
}
#line 1290 "tree.cpp"

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
#line 1853 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "sle "<< reg << ", " << newfirstExpression->place<<", "<<newSecondExpression->place <<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();   
}
#line 1332 "tree.cpp"

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
#line 1869 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "slt "<< reg << ", " <<newSecondExpression->place<<", "<<newfirstExpression->place <<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();   
}
#line 1374 "tree.cpp"

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
#line 1885 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "sle "<< reg << ", "<<newSecondExpression->place<<", "<<newfirstExpression->place <<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();   
}
#line 1416 "tree.cpp"

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
#line 1901 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "seq "<< reg <<", "<<newfirstExpression->place<<", "<<newSecondExpression->place <<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();  
}
#line 1458 "tree.cpp"

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
#line 1917 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo ;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "sne "<< reg <<", "<<newfirstExpression->place<<", "<<newSecondExpression->place<<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1500 "tree.cpp"

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
#line 1933 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "srlv "<< reg <<", "<< newfirstExpression->place<<", "<<newSecondExpression->place<<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1542 "tree.cpp"

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
#line 1949 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "sllv "<< reg <<", "<< newfirstExpression->place<<", "<<newSecondExpression->place << "\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1584 "tree.cpp"

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
#line 1965 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "ror "<< reg <<", "<< newfirstExpression->place<<", "<<newSecondExpression->place<<"\n";
    place = reg;
    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1626 "tree.cpp"

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
#line 1981 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    //FreeRegister(newfirstExpression->place);
    //FreeRegister(newSecondExpression->place);
    string reg = "";//= getFreeRegister();
    nuevo << "or "<< reg <<", "<< newfirstExpression->place<<", "<<newSecondExpression->place<<"\n";
    place = reg;

    return nuevo.str();
}
#line 1668 "tree.cpp"

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
#line 1997 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;
    //FreeRegister(newfirstExpression->place);
    //FreeRegister(newSecondExpression->place);
    string registro = "";// = getFreeRegister();
    nuevo << "and "<< registro << newfirstExpression->place<<","<<newSecondExpression->place <<"\n";
    place = registro;

    return nuevo.str();
}
#line 1710 "tree.cpp"

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
#line 2028 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();
    string R = newSecondExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L + R;

    string reg = getFreeRegister();
    nuevo << "rem "<<reg<<", "<< newfirstExpression->place<<", "<<newSecondExpression->place<<"\n";
    place = reg;

    FreeRegister(newfirstExpression->place);
    FreeRegister(newSecondExpression->place);
    return nuevo.str();
}
#line 1753 "tree.cpp"

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
#line 2013 "tree.tc"
{
    string L = newfirstExpression->GenerarCodigo();

    ostringstream nuevo;
    nuevo << L ;
    
    string reg = getFreeRegister();
    nuevo << "seq " << reg <<", "<<"$zero, "<< newfirstExpression->place << "\n";
    place = reg;

    FreeRegister(newfirstExpression->place);
    return nuevo.str();
}
#line 1794 "tree.cpp"

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
#line 2047 "tree.tc"
{
    string labelIf = getLabel("if");
    string labelElse = getLabel("else");
    string labelEndIf = getLabel("endIf");

    bool elseStatement = (newStatementFalse != NULL); 
    string condition = newCondition->GenerarCodigo();
    string newTrueBlock = newStatementTrue->GenerarCodigo();
    string newFalseBlock;
    if(elseStatement)
        newFalseBlock = newStatementFalse->GenerarCodigo();
    
    ostringstream nuevo;
    nuevo << condition << "\n";
    if(elseStatement)
        nuevo << "beq " << newCondition->place <<", "<< "$zero, " << labelElse << "\n";
    else 
        nuevo << "beq " << newCondition->place <<", "<< "$zero, " << labelEndIf << "\n";
    nuevo << newTrueBlock << "\n";
    if(elseStatement){
        nuevo <<"j "<< labelEndIf << endl;
        nuevo << labelElse << ": \n";
        nuevo << newFalseBlock  << "\n";
    }
    nuevo << labelEndIf << ": \n";

    return nuevo.str();
}
#line 1853 "tree.cpp"

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
#line 2077 "tree.tc"
{
    cout << "entro << NewWhileStatement"<<endl;
    string labelStartWhile = getLabel("startWhile");
    string labelWhile = getLabel("while");
    string labelEndWhile = getLabel("endWhile");
    stackCurrentLabelBreak.push_back(labelEndWhile);
    stackCurrentLabelContinue.push_back(labelStartWhile);

    string condition = newCondition->GenerarCodigo();
    string stmTrue = newStatementTrue->GenerarCodigo();
    
    ostringstream nuevo;
    nuevo << labelStartWhile << ": \n";
    nuevo << condition;
    nuevo << "beq " << newCondition->place <<", "<< "$zero, " << labelEndWhile << "\n";
    nuevo << stmTrue;
    nuevo << "j "<< labelStartWhile << "\n";
    nuevo << labelEndWhile << ": \n";

    stackCurrentLabelContinue.pop_back();
    stackCurrentLabelBreak.pop_back();
    FreeRegister(newCondition->place);

    return nuevo.str();
}
#line 1908 "tree.cpp"

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
#line 2104 "tree.tc"
{

    string labelStartFor = getLabel("startFor");
    string labelfor = getLabel("for");
    string labelEndfor = getLabel("endFor");
    string continuePoint = getLabel("continuePoint");

    stackCurrentLabelBreak.push_back(labelEndfor);
    stackCurrentLabelContinue.push_back(continuePoint);

    string firstListAssign = newFirstListAssign->GenerarCodigo();
    string lastListAssign = newLastListAssign->GenerarCodigo();
    string condition = newCondition->GenerarCodigo();
    string newTrueBlock = newStatementTrue->GenerarCodigo();
    ostringstream nuevo;

    nuevo << firstListAssign;
    nuevo << labelStartFor << ": \n";
    nuevo << condition;
    nuevo << "beq " << newCondition->place <<", " << "$zero, " << labelEndfor << "\n";
    nuevo << newTrueBlock;
    nuevo << continuePoint << ": \n"; 
    nuevo << lastListAssign;
    nuevo << "j " << labelStartFor << "\n"; 
    nuevo << labelEndfor << ": \n";

    stackCurrentLabelContinue.pop_back();
    stackCurrentLabelBreak.pop_back();
    FreeRegister(newCondition->place);

    return nuevo.str();
}
#line 1972 "tree.cpp"

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
#line 2138 "tree.tc"
{
    ostringstream nuevo;
    string leftValue = ((NewLValueExpression*)newLeftValue)->GetDirLValue();
    string value = newValue->GenerarCodigo();

    nuevo << leftValue;
    nuevo << value;
    nuevo << "sw "<< newValue->place <<", 0("<< newLeftValue->place << ")\n";

    FreeRegister(newLeftValue->place);
    FreeRegister(newValue->place);
    return nuevo.str();
}
#line 2015 "tree.cpp"

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
#line 2215 "tree.tc"
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
#line 2057 "tree.cpp"

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
#line 2186 "tree.tc"
{
    ostringstream nuevo;
    list<NewExpression *>::iterator it;
    it = newListExpression->begin();
    while(it != newListExpression->end())
    { 
        NewExpression *expr = *it;
        nuevo << expr->GenerarCodigo();
        if(expr->type == Int)
        {
            nuevo << "li " << "$v0" <<", "<< "1 \n";
            nuevo << "move " << "$a0"<<", " << expr->place << "\n";
            nuevo << "syscall \n";
        }
        else if(expr->type == String)
        {
            nuevo << "li " << "$v0" <<", "<< "4 \n";
            nuevo << "move " << "$a0" <<", "<< expr->place <<"\n";
            nuevo << "syscall \n";
        }

        FreeRegister(expr->place);
        it++;
    }

    return nuevo.str();
}
#line 2113 "tree.cpp"

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
	this->indexLevel = 0;
}

NewMethodCallStatement::~NewMethodCallStatement()
{
	// not used
}

string NewMethodCallStatement::GenerarCodigo()
#line 2153 "tree.tc"
{
   cout << "entro <<NewMethodCallStatement"<<endl;
    ostringstream nuevo;
    if(newParameters != NULL){
       list<NewExpression *>::iterator it;
       it = newParameters->begin();
       int parameterCount = newParameters->size();
       nuevo << "addi " << "$sp, $sp, " << (-1 * (parameterCount*4)) << "\n";
       while(it != newParameters->end())
       {   
           NewExpression * newExpr = *it;
           nuevo << newExpr->GenerarCodigo(); 
           string reg = getFreeRegister();
           nuevo << "sw " << newExpr->place << ", "<<(newExpr->indice * 4)<<"($sp)"<< "\n";
           FreeRegister(reg);
           it++;
       }
     }
     cout << "salio <<NewMethodCallStatement"<<endl;
    nuevo << "jal " << id << "\n";
    return nuevo.str();
}
#line 2166 "tree.cpp"

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
#line 2177 "tree.tc"
{
    ostringstream nuevo;
    nuevo << newReturnExpression->GenerarCodigo();
    nuevo << "move "<< "$v0" <<" , "<< newReturnExpression->place << "\n"; 
    nuevo << "jr " << "$ra" << "\n";
    return nuevo.str();
}
#line 2202 "tree.cpp"

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
#line 2318 "tree.tc"
{
   ostringstream nuevo;
   string label = stackCurrentLabelBreak.back();
   nuevo << "j "<< label<< "\n";
   return nuevo.str();
}
#line 2236 "tree.cpp"

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
#line 2326 "tree.tc"
{
   ostringstream nuevo;
   string label = stackCurrentLabelContinue.back();
   nuevo << "j "<< label<< "\n";
   return nuevo.str();  
}
#line 2270 "tree.cpp"

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
#line 2334 "tree.tc"
{
   cout << "entro <<NewBlockStatement"<<endl;
    ostringstream nuevo;
    list<NewStatement*>::iterator it;
    it = newListStatements->begin();
    while(it != newListStatements->end()) {
        NewStatement *stm = (*it);
        nuevo << stm->GenerarCodigo();
        it++;
    }
    cout << "salio <<NewBlockStatement"<<endl;
    return nuevo.str();
}
#line 2311 "tree.cpp"

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
#line 850 "tree.tc"
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
#line 2435 "tree.cpp"

TheNewClass * ClassDef::ValidarSemantica()
#line 864 "tree.tc"
{
    contextos[0] = new Contexto();
    list<VariableDef*>::iterator it1;
    it1 = listVariable->begin();
    while(it1 != listVariable->end())
    {
        (*it1)->ValidarSemantica();
        it1++;
    }

    NewBlockStatement *newBlockStatement = NULL;
    list<MethodDef*>::iterator it2;
    it2 = listMethod->begin();
    while(it2 != listMethod->end())
    {
        (*it2)->ValidarSemantica();
        if((*it2)->id == "main")
            newBlockStatement = (NewBlockStatement*)(*it2)->block->ValidarSemantica();
         else
            (*it2)->block->ValidarSemantica();
        it2++;
    }
    
    return new NewClassDef(className,newBlockStatement);
}
#line 2464 "tree.cpp"

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
#line 573 "tree.tc"
{
    ostringstream out;

    out << this->id << "(" << ListToString(parameters, ", ", false) << ")";

    return out.str();
}
#line 2576 "tree.cpp"

TheNewClass * MethodCallExpression::ValidarSemantica()
#line 1235 "tree.tc"
{
    cout << "Entro MethodCallExpression" << endl;
    list<NewExpression*> *newListExpression = new list<NewExpression*>();
    list<Expression*>::iterator it;
    it = parameters->begin();
    while(it != parameters->end())
    {
        NewExpression * newExpr = (NewExpression*)((*it)->ValidarSemantica());
        newListExpression->push_back(newExpr);
        it++;
    }
    cout << "Salio MethodCallExpression" << endl;
    return new NewMethodCallExpression(id,newListExpression);
}
#line 2594 "tree.cpp"

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
#line 711 "tree.tc"
{
    ostringstream out;

    out << this->id;

    if (expr != 0)
      out << "[" << expr->ToString() << "]";

    return out.str();
}
#line 2634 "tree.cpp"

TheNewClass * LValueExpression::ValidarSemantica()
#line 1251 "tree.tc"
{
    cout << "Entro LValueExpression" << endl;
    NewExpression *newExpr = NULL;
    NewLValueExpression *nlv = new NewLValueExpression("",NULL,0,0);
    
    Contexto *con = contextos[0];
    if(con->contextoMap[id] != NULL)
    {
        nlv->isLocal = true;
    }
    else if(variableDeclared[id] != NULL)
    {
        nlv->isGlobal = true;
    }
    else
    {
        nlv->isParameter = true;
    }

    cout << "Salio LValueExpression" << endl;
    int offset = 0;
    int level = 0;
    Contexto *cont = contextos[0];
    map<string,Variable*>::iterator itva;
    itva = cont->contextoMap.begin();
    while(itva != cont->contextoMap.end()) {
      cout << itva->first;
      itva++;
    }
    if(cont->contextoMap[id] == NULL){
        if(variableDeclared[id] ==NULL ){
            ErrorSemantico("variable no definida");
            return NULL;
        }
        else
        {
            offset = variableDeclared[id]->offset;
            level = variableDeclared[id]->level;
        }
    }
    else
    {
        offset = cont->contextoMap[id]->offset;
        level = cont->contextoMap[id]->level;
    }
    nlv->newId = id;
    nlv->newExpr = newExpr;
    nlv->offset = offset;
    nlv->level = level;
    return nlv;
}
#line 2689 "tree.cpp"

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
#line 723 "tree.tc"
{
    ostringstream out;    
    out << TypeToString(parameterType) << " " << id; 
    return out.str();
}
#line 2724 "tree.cpp"

TheNewClass * ParameterDef::ValidarSemantica()
#line 1230 "tree.tc"
{
    return new NewParameterDef(id,parameterType);
}
#line 2731 "tree.cpp"

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
#line 581 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "+" << this->secondExpression->ToString();
    return out.str();
}
#line 2764 "tree.cpp"

TheNewClass * AddExpression::ValidarSemantica()
#line 891 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && (first->type == Int))
        {
            NewAddExpression *addExpr = new NewAddExpression(first,second);
            addExpr->type = Int;
            return addExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2786 "tree.cpp"

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
#line 587 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "-" << this->secondExpression->ToString();
    return out.str();
}
#line 2819 "tree.cpp"

TheNewClass * SubExpression::ValidarSemantica()
#line 911 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewSubExpression *subExpr = new NewSubExpression(first,second);
            subExpr->type = Int;
            return subExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2841 "tree.cpp"

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
#line 593 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "*" << this->secondExpression->ToString();
    return out.str();
}
#line 2874 "tree.cpp"

TheNewClass * MultExpression::ValidarSemantica()
#line 931 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewMultExpression *multExpr = new NewMultExpression(first,second);
            multExpr->type = Int;
            return multExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2896 "tree.cpp"

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
#line 599 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "/" << this->secondExpression->ToString();
    return out.str();
}
#line 2929 "tree.cpp"

TheNewClass * DivExpression::ValidarSemantica()
#line 951 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewDivExpression *divExpr = new NewDivExpression(first,second);
            divExpr->type = Int;
            return divExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 2951 "tree.cpp"

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
#line 605 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "<" << this->secondExpression->ToString();
    return out.str();
}
#line 2984 "tree.cpp"

TheNewClass * LessThanExpression::ValidarSemantica()
#line 971 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewLessThanExpression *lessThanExpr = new NewLessThanExpression(first,second); 
            lessThanExpr->type = Boolean;
            return lessThanExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3006 "tree.cpp"

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
#line 611 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "<=" << this->secondExpression->ToString();
    return out.str();
}
#line 3039 "tree.cpp"

TheNewClass * LessThanEqualExpression::ValidarSemantica()
#line 1011 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewLessThanEqualExpression *lessThanEqualExpr = new NewLessThanEqualExpression(first,second);
            lessThanEqualExpr->type = Boolean;
            return lessThanEqualExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3061 "tree.cpp"

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
#line 617 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << ">" << this->secondExpression->ToString();
    return out.str();
}
#line 3094 "tree.cpp"

TheNewClass * BigerThanExpression::ValidarSemantica()
#line 991 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewBigerThanExpression *bigerThanExpr = new NewBigerThanExpression(first,second);
            bigerThanExpr->type = Boolean;
            return bigerThanExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3116 "tree.cpp"

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
#line 623 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << ">=" << this->secondExpression->ToString();
    return out.str();
}
#line 3149 "tree.cpp"

TheNewClass * BigerThanEqualExpression::ValidarSemantica()
#line 1031 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewBigerThanEqualExpression * bigerThanEqualExpr = new NewBigerThanEqualExpression(first,second);
            bigerThanEqualExpr->type = Boolean;
            return bigerThanEqualExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3171 "tree.cpp"

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
#line 629 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "==" << this->secondExpression->ToString();
    return out.str();
}
#line 3204 "tree.cpp"

TheNewClass * EqualExpression::ValidarSemantica()
#line 1051 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && (first->type == Int || first->type == Boolean))
        {
            NewEqualExpression *equalExpr = new NewEqualExpression(first,second);
            equalExpr->type = Boolean; 
            return equalExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3226 "tree.cpp"

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
#line 635 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "!=" << this->secondExpression->ToString();
    return out.str();
}
#line 3259 "tree.cpp"

TheNewClass * NotEqualExpression::ValidarSemantica()
#line 1071 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && (first->type == Int || first->type == Boolean))
        {
            NewNotEqualExpression *notEqualExpr = new NewNotEqualExpression(first,second);
            notEqualExpr->type = Boolean;
            return notEqualExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3281 "tree.cpp"

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
#line 641 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << ">>" << this->secondExpression->ToString();
    return out.str();
}
#line 3314 "tree.cpp"

TheNewClass * ShiftRightExpression::ValidarSemantica()
#line 1111 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewShiftRightExpression *shifRightExpr = new NewShiftRightExpression(first,second);
            shifRightExpr->type = Int;
            return shifRightExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3336 "tree.cpp"

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
#line 647 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "<<" << this->secondExpression->ToString();
    return out.str();
}
#line 3369 "tree.cpp"

TheNewClass * ShiftLeftExpression::ValidarSemantica()
#line 1091 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewShiftLeftExpression *shiftLeftExpr = new NewShiftLeftExpression(first,second);
            shiftLeftExpr->type = Int;
            return shiftLeftExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3391 "tree.cpp"

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
#line 653 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "rot" << this->secondExpression->ToString();
    return out.str();
}
#line 3424 "tree.cpp"

TheNewClass * RotExpression::ValidarSemantica()
#line 1131 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewRotExpression *rotExpr = new NewRotExpression(first,second);
            rotExpr->type = Int;
            return rotExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3446 "tree.cpp"

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
#line 671 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "||" << this->secondExpression->ToString();
    return out.str();
}
#line 3479 "tree.cpp"

TheNewClass * OrExpression::ValidarSemantica()
#line 1151 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Boolean)
        {
            NewOrExpression *orExpr = new NewOrExpression(first,second);
            orExpr->type;
            return orExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3501 "tree.cpp"

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
#line 665 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "&&" << this->secondExpression->ToString();
    return out.str();
}
#line 3534 "tree.cpp"

TheNewClass * AndExpression::ValidarSemantica()
#line 1171 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Boolean)
        {
            NewAndExpression *andExpr = new NewAndExpression(first,second);
            andExpr->type = Boolean;
            return andExpr; 
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3556 "tree.cpp"

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
#line 677 "tree.tc"
{
    ostringstream out;
    out << this->firstExpression->ToString() << "%" << this->secondExpression->ToString();
    return out.str();
}
#line 3589 "tree.cpp"

TheNewClass * ModExpression::ValidarSemantica()
#line 1191 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    NewExpression *second = (NewExpression*)secondExpression->ValidarSemantica();

    if(first != NULL && second != NULL)
    {
        if((first->type == second->type) && first->type == Int)
        {
            NewModExpression *modExpr = new NewModExpression(first,second);
            modExpr->type = Boolean;
            return modExpr;
        }
        ErrorSemantico("Error: Tipos Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3611 "tree.cpp"

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
#line 659 "tree.tc"
{
    ostringstream out;
    out <<  "!" << this->firstExpression->ToString();
    return out.str();
}
#line 3644 "tree.cpp"

TheNewClass * NotExpression::ValidarSemantica()
#line 1211 "tree.tc"
{
    NewExpression *first = (NewExpression*)firstExpression->ValidarSemantica();
    
    if(first != NULL )
    {
        if(first->type == Boolean)
        {
            NewNotExpression *notExpr = new NewNotExpression(first);
            notExpr->type = Boolean;
            return notExpr;
        }
        ErrorSemantico("Error: Tipo Incompatibles");
        return NULL;
    }
    ErrorSemantico("Error: No se pudo Evaluar la Expresion");
    return NULL;
}
#line 3665 "tree.cpp"

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
#line 683 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3699 "tree.cpp"

TheNewClass * ConstantIntExpression::ValidarSemantica()
#line 1304 "tree.tc"
{
    return new NewConstantIntExpression(constant);
}
#line 3706 "tree.cpp"

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
#line 690 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3740 "tree.cpp"

TheNewClass * ConstantBoolExpression::ValidarSemantica()
#line 1323 "tree.tc"
{
    return new NewConstantBoolExpression(constant);
}
#line 3747 "tree.cpp"

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
#line 704 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3781 "tree.cpp"

TheNewClass * ConstantCharExpression::ValidarSemantica()
#line 1309 "tree.tc"
{
    return new NewConstantCharExpression(constant);
}
#line 3788 "tree.cpp"

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
#line 697 "tree.tc"
{
    ostringstream out;
    out << this->constant;
    return out.str();
}
#line 3822 "tree.cpp"

TheNewClass * ConstantStringExpression::ValidarSemantica()
#line 1314 "tree.tc"
{
    string id = getLabel("var_str");
    variableStringMap[id] = constant;
    NewConstantStringExpression *tem = new NewConstantStringExpression(id);
    tem->type = String; 
    return tem;
}
#line 3833 "tree.cpp"

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
#line 741 "tree.tc"
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
#line 3875 "tree.cpp"

TheNewClass * VariableDef::ValidarSemantica()
#line 1613 "tree.tc"
{
  cout << "entro "<< endl;
    Variable *var = variableDeclared[id];
    if(var != NULL){
      string error = "Variable ya definida";
      ErrorSemantico(error);
      return NULL;
    }
    Variable *newVariable;
    if(isArrayDef)
    {
        newVariable = new Variable(currentOffset,0,0,true,array_dimension,false,variable_type);
    }
    else
    {
        NewConstantExpression * expr = (NewConstantExpression*)initial_value->ValidarSemantica();
        if(dynamic_cast<NewConstantIntExpression*>(expr) != NULL){
            NewConstantIntExpression *intExpr = (NewConstantIntExpression*)expr;    
            newVariable = new Variable(currentOffset,0,intExpr->Newconstant,false,0,false,Int);
        }
        else
        {
            if(dynamic_cast<NewConstantBoolExpression*>(expr) != NULL){
                NewConstantBoolExpression *boolExpr = (NewConstantBoolExpression*)expr;
                if(boolExpr->Newconstant)
                    newVariable = new Variable(currentOffset,0,1,false,0,false,Boolean);
                else
                    newVariable = new Variable(currentOffset,0,0,false,0,false,Boolean);
            }
        }
    }
    currentOffset+=1;
    variableDeclared[id] = newVariable;
    return NULL;
}
#line 3914 "tree.cpp"

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

LocalVariableDef::LocalVariableDef(int first_line, int first_column)
	: Statement()
{
	this->kind__ = LocalVariableDef_kind;
	this->first_line = first_line;
	this->first_column = first_column;
	this->variable_names = NULL;
}

LocalVariableDef::~LocalVariableDef()
{
	// not used
}

string LocalVariableDef::ToString()
#line 753 "tree.tc"
{
   return "NADA";
}
#line 3948 "tree.cpp"

TheNewClass * LocalVariableDef::ValidarSemantica()
#line 1649 "tree.tc"
{
   cout<<"entro <<LocalVariableDef" << endl;
   return NULL;
}
#line 3956 "tree.cpp"

int LocalVariableDef::isA(int kind) const
{
	if(kind == LocalVariableDef_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *LocalVariableDef::getKindName() const
{
	return "LocalVariableDef";
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
#line 730 "tree.tc"
{
    ostringstream out;
    out << TypeToString(returnType) << " " << id << "(";
    if (parameters != 0)
      out << ListToString(parameters, ",", false);
    out << ")" << endl;
    out << block->ToString();
    return out.str();
}
#line 3994 "tree.cpp"

TheNewClass * MethodDef::ValidarSemantica()
#line 1561 "tree.tc"
{
  Contexto *contextoActual = contextos[0];
  currentContexto += 1;

 /* Contexto *contextoNuevo = new Contexto();
  contextoNuevo->currentLevel = 0;
  contextoNuevo->currentOffset = 0;
*/
  list<ParameterDef *>::iterator it;

  if(parameters != NULL){
      it = parameters->begin();
      while(it != parameters->end())
      {
        NewParameterDef *param = (NewParameterDef*)(*it)->ValidarSemantica();
        string str = param->newId;
        Type tipo = param->newParameterType;
        Variable *var = new Variable(contextoActual->currentOffset,contextoActual->currentLevel,0,false,0,true,tipo);
        if(contextoActual->contextoMap[str] != NULL){
          string str = "Parametros repetidos";
          ErrorSemantico(str);
          return NULL;
        }else{
          contextoActual->contextoMap[str] = var;
          contextoActual->currentOffset += 1;
        }
        it++;
      }
  }
  //contextos[currentContexto] = contextoNuevo;
  //contextoNuevo->contextoAnterior = contestoActual;
  if(methodDeclared[id] != NULL)
  {
    string str = "Metodo ya definido << MethodDef ";
    ErrorSemantico(str);
    return NULL;
  }
  Procedimiento *p = new Procedimiento(id,NULL);
  if(parameters != NULL)
    p->countParametros = parameters->size();
  else 
    p->countParametros = 0;

  methodDeclared[id] = p;
  NewBlockStatement *newBlockStatement  = (NewBlockStatement*)(block->ValidarSemantica());
  methodDeclared[id]->newBlockStatement = newBlockStatement;


  return NULL;
}
#line 4048 "tree.cpp"

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
#line 777 "tree.tc"
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
#line 4093 "tree.cpp"

TheNewClass * IfStatement::ValidarSemantica()
#line 1330 "tree.tc"
{
    cout <<"Entro IfStatement"<<endl;
    NewExpression *newCondition = (NewExpression*)condition->ValidarSemantica();
    if(newCondition == NULL){
        cout<<"fallo newCondition << IfStatement"<<endl;
        return NULL;
    }
    if(newCondition->type != Boolean)
    {
        ErrorSemantico("Error: Condicion if debe se bool");
        return NULL;
    }
    NewStatement *newTrueBlock = (NewStatement*)statementTrue->ValidarSemantica();
    NewStatement *newFalseBlock;
    if(newTrueBlock == NULL){
        cout<<"fallo newTrueBlock << IfStatement"<<endl;
        return NULL;
    }
    if(statementFalse != NULL)
    {
        newFalseBlock = (NewStatement*)statementFalse->ValidarSemantica();
        if(newFalseBlock == NULL){
            cout<<"fallo newFalseBlock << IfStatement"<<endl;
            return NULL;
        }
    }
    cout <<"Salio IfStatement"<<endl;
    return new NewIfStatement(newCondition,newTrueBlock,newFalseBlock);
}
#line 4126 "tree.cpp"

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
#line 791 "tree.tc"
{
    ostringstream out;
    out << "while (" << condition->ToString() << ")" << endl;
    out << "{" << statementTrue->ToString() << endl << "}";
    return out.str();
}
#line 4164 "tree.cpp"

TheNewClass * WhileStatement::ValidarSemantica()
#line 1361 "tree.tc"
{
    cout <<"Entro WhileStatement"<<endl;
    NewExpression *newCondition = (NewExpression*)condition->ValidarSemantica();
    if(newCondition == NULL){
        cout<<"fallo newCondition << WhileStatement"<<endl;
        return NULL;
    }
    if(newCondition->type != Boolean)
    {
        ErrorSemantico("Error: Condicion if debe se bool");
        return NULL;                       
    }

    NewStatement *newStatementTrue = (NewStatement*)statementTrue->ValidarSemantica();
    if(newStatementTrue == NULL){
        cout<<"fallo newStatementTrue << WhileStatement"<<endl;
        return NULL;
    }
    cout <<"Salio WhileStatement"<<endl;
    return new NewWhileStatement(newCondition,newStatementTrue);
}
#line 4189 "tree.cpp"

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
#line 799 "tree.tc"
{
    ostringstream out;
    out << "for(";
    out << firstListAssign->ToString() << ";" << condition->ToString() << ";" << lastListAssign->ToString() <<")";
    out << statementTrue->ToString();

    return out.str();
}
#line 4231 "tree.cpp"

TheNewClass * ForStatement::ValidarSemantica()
#line 1384 "tree.tc"
{
    cout <<"Entro ForStatement"<<endl;
    NewStatement *newFirstListAssign = (NewStatement*)firstListAssign->ValidarSemantica();
    if(newFirstListAssign == NULL){
        cout<<"fallo newFirstListAssign << ForStatement"<<endl;
        return NULL;
    }
    NewExpression *newCondition = (NewExpression*)condition->ValidarSemantica();
    if(newCondition == NULL){
        cout<<"fallo newCondition << ForStatement"<<endl;
        return NULL;
    }

    if(newCondition->type != Boolean){
        string str = "La condicion tiene que se bool << ForStatement";
        ErrorSemantico(str);
        return NULL;
    }

    NewStatement *newLastListAssign = (NewStatement*)lastListAssign->ValidarSemantica();
    if(newLastListAssign == NULL){
        cout<<"fallo newLastListAssign << ForStatement"<<endl;
        return NULL;
    }

    NewStatement *newStatementTrue = (NewStatement*)statementTrue->ValidarSemantica();
    if(newStatementTrue == NULL){
        cout<<"fallo newStatementTrue"<<endl;
        return NULL;
    }
    cout <<"Salio ForStatement"<<endl;
    return new NewForStatement(newFirstListAssign,newCondition,newLastListAssign,newStatementTrue);
}
#line 4268 "tree.cpp"

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
#line 809 "tree.tc"
{
    ostringstream out;
    out << "// Linea " << first_line << " Columna " << first_column << "\n"; 
    out << leftValue->ToString() << " = " << value->ToString() << ";";
    return out.str();
}
#line 4306 "tree.cpp"

TheNewClass * AssignStatement::ValidarSemantica()
#line 1517 "tree.tc"
{
    cout<<"Entro AssignStatement"<<endl;
    NewExpression *newLeftValue = (NewExpression*)leftValue->ValidarSemantica();
    if(newLeftValue == NULL){
        cout<<"fallo newLeftValue << AssignStatement"<<endl;
        return NULL;
    }

    NewExpression *newValue = (NewExpression*)value->ValidarSemantica();
    if(newValue == NULL){
        cout<<"fallo newValue << AssignStatement"<<endl;
        return NULL;
    }
    cout<<"Salio AssignStatement"<<endl;
    return new NewAssignStatement(newLeftValue,newValue);
}
#line 4326 "tree.cpp"

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
#line 758 "tree.tc"
{
    ostringstream out;
    out << "read ";
    if (listExpression != 0)
      out << ListToString(listExpression, ",", false);
    return out.str();
}
#line 4364 "tree.cpp"

TheNewClass * ReadStatement::ValidarSemantica()
#line 1476 "tree.tc"
{
    cout <<"Entro ReadStatement"<<endl;
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
    cout <<"Salio ReadStatement"<<endl;
    return new NewReadStatement(newListExpression);
}
#line 4387 "tree.cpp"

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
#line 767 "tree.tc"
{
    ostringstream out;
    out << "print ";
    if (listExpression != 0)
      out << ListToString(listExpression, ",", false);
    out << ";";
    return out.str();
}
#line 4426 "tree.cpp"

TheNewClass * PrintStatement::ValidarSemantica()
#line 1497 "tree.tc"
{
    cout <<"Entro PrintStatement"<<endl;
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
    cout <<"Salio PrintStatement"<<endl;
    return new NewPrintStatement(newListExpression);
}
#line 4448 "tree.cpp"

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
#line 817 "tree.tc"
{
    return this->id + "(" + ListToString(parameters, ", ", false) + ");";
}
#line 4483 "tree.cpp"

TheNewClass * MethodCallStatement::ValidarSemantica()
#line 1535 "tree.tc"
{
   cout << "Entro MethodCallStatement" << endl;
  list<NewExpression*> *newListExpression = new list<NewExpression*>();
  if(parameters != NULL){
     list<Expression*>::iterator it;
     it = parameters->begin();
     int indice_parametro = 0;
     while(it != parameters->end()){
       NewExpression * newExpr = (NewExpression*)((*it)->ValidarSemantica());
       if(newExpr == NULL)
       {
         string str = "Error << MethodCallStatement";
         ErrorSemantico(str);
         return NULL;
       }
       newExpr->indice = indice_parametro;
       newListExpression->push_back(newExpr);
       it++;  
       indice_parametro++;
     }
   }
  cout<<"Salio MethodCallStatement"<<endl;
  return new NewMethodCallStatement(id,newListExpression);
}
#line 4511 "tree.cpp"

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
#line 822 "tree.tc"
{
    return "return " + returnExpression->ToString() + ";";
}
#line 4545 "tree.cpp"

TheNewClass * ReturnStatement::ValidarSemantica()
#line 1419 "tree.tc"
{
    cout <<"Entro ReturnStatement"<<endl;
    NewExpression *newReturnExpression = (NewExpression*)returnExpression->ValidarSemantica();
    if(newReturnExpression == NULL){
        cout<<"fallo newReturnExpression << ReturnStatement"<<endl;
        return NULL;
    }
    cout <<"Salio ReturnStatement"<<endl;
    return new NewReturnStatement(newReturnExpression);
}
#line 4559 "tree.cpp"

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
#line 827 "tree.tc"
{
    return "break;";
}
#line 4592 "tree.cpp"

TheNewClass * BreakStatement::ValidarSemantica()
#line 1655 "tree.tc"
{
    return new NewBreakStatement();
}
#line 4599 "tree.cpp"

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
#line 832 "tree.tc"
{
    return "continue;";
}
#line 4632 "tree.cpp"

TheNewClass * ContinueStatement::ValidarSemantica()
#line 1660 "tree.tc"
{
    return new NewContinueStatement();
}
#line 4639 "tree.cpp"

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
#line 837 "tree.tc"
{
    ostringstream out;

    out << "{" << endl;

    if (listStatements != 0)
		  out << ListToString(listStatements, "\n", true);

    out << "}";

    return out.str();
}
#line 4681 "tree.cpp"

TheNewClass * BlockStatement::ValidarSemantica()
#line 1431 "tree.tc"
{
    cout << "Entro BlockStatement" << endl;
    list<NewStatement*> *newListStatement = new list<NewStatement*>();
    if(listStatements == NULL){
        string str = "Error: newListStatement es nulo";
        ErrorSemantico(str);
        return NULL;
    }

    list<Statement*>::iterator it;
    it = listStatements->begin();
    while(it != listStatements->end()){
        Statement *stmTemp = *it;
        NewStatement *newStm ;
        if(dynamic_cast<BlockStatement*>(stmTemp)!= NULL)
        {
            cout<<"entro 1"<<endl;
          currentContexto += 1; 
          contextos[currentContexto] = new Contexto();
          newStm = (NewStatement*)stmTemp->ValidarSemantica();
          contextos[currentContexto] = contextos[currentContexto - 1];
          currentContexto -= 1;
        }
        else
        {
          newStm = (NewStatement*)(stmTemp->ValidarSemantica());
        }
        if(newStm == NULL && dynamic_cast<LocalVariableDef*>(stmTemp) == NULL){
            string str = "Error en el bloque ";
            ErrorSemantico(str);
            return NULL;
        }
        if (dynamic_cast<LocalVariableDef*>(stmTemp)== NULL) {
           newListStatement->push_back(newStm);
        }
        
        it++;
    }
    NewBlockStatement *newblock = new NewBlockStatement(); 
    newblock->newListStatements = newListStatement;
    cout << "Salio BlockStatement" << endl;
    return newblock;
}
#line 4728 "tree.cpp"

void BlockStatement::AddStatement(Statement * stm)
#line 565 "tree.tc"
{
    if(listStatements == 0)
      listStatements = new StatementList();
      
    listStatements->push_back(stm);
}
#line 4738 "tree.cpp"

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
	this->countParametros = 0;
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

