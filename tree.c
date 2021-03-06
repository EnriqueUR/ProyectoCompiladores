/* tree.c.  Generated automatically by treecc */
#line 27 "tree.tc"

#include "tree.h"
#line 6 "tree.c"

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
#line 285 "tree.c"
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

BinaryExpression::BinaryExpression(Expression * FirstExpression, Expression * SecondExpression)
	: Expression()
{
	this->kind__ = BinaryExpression_kind;
	this->FirstExpression = FirstExpression;
	this->SecondExpression = SecondExpression;
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

UnaryExpression::UnaryExpression(Expression * FirstExpression)
	: Expression()
{
	this->kind__ = UnaryExpression_kind;
	this->FirstExpression = FirstExpression;
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
#line 211 "tree.tc"
{
}
#line 461 "tree.c"

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

LValueExpression::LValueExpression(string id, Expression * expr)
	: Expression()
{
	this->kind__ = LValueExpression_kind;
	this->id = id;
	this->expr = expr;
}

LValueExpression::~LValueExpression()
{
	// not used
}

string LValueExpression::ToString()
#line 281 "tree.tc"
{
}
#line 493 "tree.c"

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
#line 285 "tree.tc"
{
}
#line 525 "tree.c"

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

AddExpression::AddExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = AddExpression_kind;
}

AddExpression::~AddExpression()
{
	// not used
}

string AddExpression::ToString()
#line 214 "tree.tc"
{
}
#line 555 "tree.c"

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

SubExpression::SubExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = SubExpression_kind;
}

SubExpression::~SubExpression()
{
	// not used
}

string SubExpression::ToString()
#line 217 "tree.tc"
{
}
#line 585 "tree.c"

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

MultExpression::MultExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = MultExpression_kind;
}

MultExpression::~MultExpression()
{
	// not used
}

string MultExpression::ToString()
#line 220 "tree.tc"
{
}
#line 615 "tree.c"

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

DivExpression::DivExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = DivExpression_kind;
}

DivExpression::~DivExpression()
{
	// not used
}

string DivExpression::ToString()
#line 223 "tree.tc"
{
}
#line 645 "tree.c"

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

LessThanExpression::LessThanExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = LessThanExpression_kind;
}

LessThanExpression::~LessThanExpression()
{
	// not used
}

string LessThanExpression::ToString()
#line 226 "tree.tc"
{
}
#line 675 "tree.c"

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

LessThanEqualExpression::LessThanEqualExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = LessThanEqualExpression_kind;
}

LessThanEqualExpression::~LessThanEqualExpression()
{
	// not used
}

string LessThanEqualExpression::ToString()
#line 229 "tree.tc"
{
}
#line 705 "tree.c"

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

BigerThanExpression::BigerThanExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = BigerThanExpression_kind;
}

BigerThanExpression::~BigerThanExpression()
{
	// not used
}

string BigerThanExpression::ToString()
#line 232 "tree.tc"
{
}
#line 735 "tree.c"

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

BigerThanEqualExpression::BigerThanEqualExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = BigerThanEqualExpression_kind;
}

BigerThanEqualExpression::~BigerThanEqualExpression()
{
	// not used
}

string BigerThanEqualExpression::ToString()
#line 235 "tree.tc"
{
}
#line 765 "tree.c"

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

EqualExpression::EqualExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = EqualExpression_kind;
}

EqualExpression::~EqualExpression()
{
	// not used
}

string EqualExpression::ToString()
#line 238 "tree.tc"
{
}
#line 795 "tree.c"

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

NotEqualExpression::NotEqualExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = NotEqualExpression_kind;
}

NotEqualExpression::~NotEqualExpression()
{
	// not used
}

string NotEqualExpression::ToString()
#line 241 "tree.tc"
{
}
#line 825 "tree.c"

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

ShiftRightExpression::ShiftRightExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = ShiftRightExpression_kind;
}

ShiftRightExpression::~ShiftRightExpression()
{
	// not used
}

string ShiftRightExpression::ToString()
#line 244 "tree.tc"
{
}
#line 855 "tree.c"

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

ShiftLeftExpression::ShiftLeftExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = ShiftLeftExpression_kind;
}

ShiftLeftExpression::~ShiftLeftExpression()
{
	// not used
}

string ShiftLeftExpression::ToString()
#line 247 "tree.tc"
{
}
#line 885 "tree.c"

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

RotExpression::RotExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = RotExpression_kind;
}

RotExpression::~RotExpression()
{
	// not used
}

string RotExpression::ToString()
#line 250 "tree.tc"
{
}
#line 915 "tree.c"

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

OrExpression::OrExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = OrExpression_kind;
}

OrExpression::~OrExpression()
{
	// not used
}

string OrExpression::ToString()
#line 259 "tree.tc"
{
}
#line 945 "tree.c"

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

AndExpression::AndExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = AndExpression_kind;
}

AndExpression::~AndExpression()
{
	// not used
}

string AndExpression::ToString()
#line 256 "tree.tc"
{
}
#line 975 "tree.c"

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

ModExpression::ModExpression(Expression * FirstExpression, Expression * SecondExpression)
	: BinaryExpression(FirstExpression, SecondExpression)
{
	this->kind__ = ModExpression_kind;
}

ModExpression::~ModExpression()
{
	// not used
}

string ModExpression::ToString()
#line 262 "tree.tc"
{
}
#line 1005 "tree.c"

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

NotExpression::NotExpression(Expression * FirstExpression)
	: UnaryExpression(FirstExpression)
{
	this->kind__ = NotExpression_kind;
}

NotExpression::~NotExpression()
{
	// not used
}

string NotExpression::ToString()
#line 253 "tree.tc"
{
}
#line 1035 "tree.c"

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
#line 265 "tree.tc"
{
}
#line 1066 "tree.c"

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
#line 269 "tree.tc"
{
}
#line 1097 "tree.c"

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
#line 277 "tree.tc"
{
}
#line 1128 "tree.c"

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
#line 273 "tree.tc"
{
}
#line 1159 "tree.c"

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
#line 293 "tree.tc"
{
}
#line 1192 "tree.c"

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
#line 289 "tree.tc"
{
}
#line 1223 "tree.c"

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
#line 307 "tree.tc"
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
#line 1269 "tree.c"

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
#line 322 "tree.tc"
{
    ostringstream out;

	out << "while (" << condition->ToString() << ")" << endl;
	out << "{" << statementTrue->ToString() << endl << "}";

    return out.str();
}
#line 1309 "tree.c"

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

ForStatement::ForStatement(Statement * firstListAssign, Expression * condition, Statement * lasttListAssign, Statement * statementTrue, int first_line, int first_column)
	: Statement()
{
	this->kind__ = ForStatement_kind;
	this->firstListAssign = firstListAssign;
	this->condition = condition;
	this->lasttListAssign = lasttListAssign;
	this->statementTrue = statementTrue;
	this->first_line = first_line;
	this->first_column = first_column;
}

ForStatement::~ForStatement()
{
	// not used
}

string ForStatement::ToString()
#line 332 "tree.tc"
{
  return "for () {}";
}
#line 1346 "tree.c"

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
#line 337 "tree.tc"
{
   ostringstream out;

	out << "// Linea " << first_line << " Columna " << first_column << "\n"; 
	out << leftValue->ToString() << " = " << value->ToString() << ";";

   return out.str();
}
#line 1386 "tree.c"

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
#line 297 "tree.tc"
{
     cout << "read ;";
}
#line 1420 "tree.c"

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
#line 302 "tree.tc"
{
    cout << "print ;";
}
#line 1454 "tree.c"

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

MethodCallStatement::MethodCallStatement(string name, ExpressionList * parameters, int first_line, int first_column)
	: Statement()
{
	this->kind__ = MethodCallStatement_kind;
	this->name = name;
	this->parameters = parameters;
	this->first_line = first_line;
	this->first_column = first_column;
}

MethodCallStatement::~MethodCallStatement()
{
	// not used
}

string MethodCallStatement::ToString()
#line 347 "tree.tc"
{
    return this->name + "(" + ListToString(parameters, ", ", false) + ");";
}
#line 1489 "tree.c"

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
#line 352 "tree.tc"
{
    return "return " + returnExpression->ToString() + ";";
}
#line 1523 "tree.c"

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
#line 357 "tree.tc"
{
    cout << "break;";
}
#line 1556 "tree.c"

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
#line 362 "tree.tc"
{
    cout << "continue;";
}
#line 1589 "tree.c"

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
#line 367 "tree.tc"
{
    ostringstream out;

	out << "{" << endl;

	if (listStatements != 0)
		out << ListToString(listStatements, "\n", true);

	out << "}";

    return out.str();
}
#line 1631 "tree.c"

void BlockStatement::AddStatement(Statement * stm)
#line 203 "tree.tc"
{
    if(listStatements == 0)
      listStatements = new StatementList();
      
    listStatements->push_back(stm);
}
#line 1641 "tree.c"

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

void *ClassDef::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void ClassDef::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

ClassDef::ClassDef(string className, VariableDefList * listVariable, MethodDefList * listMethod)
{
	this->kind__ = ClassDef_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->className = className;
	this->listVariable = listVariable;
	this->listMethod = listMethod;
}

ClassDef::~ClassDef()
{
	// not used
}

int ClassDef::isA(int kind) const
{
	if(kind == ClassDef_kind)
		return 1;
	else
		return 0;
}

const char *ClassDef::getKindName() const
{
	return "ClassDef";
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

