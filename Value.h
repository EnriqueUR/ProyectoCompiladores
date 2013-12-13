/*
 * Value.h
 *
 *  Created on: Mar 27, 2009
 *      Author: ivan_deras
 */

#ifndef VALUE_H_
#define VALUE_H_

#include <string>
#include <iostream> 
#include <list>
#include <map>

using namespace std;


typedef unsigned char byte;

/*
 * Tipos de datos soportados por Decaf
 */
enum Type {
	Int,
	Char,
	Boolean,
	String,
	Void
};

inline string TypeToString(Type type)
{
	switch (type)
	{
		case Int: return "int";
		case Char: return "char";
		case Boolean: return "boolean";
		case String: return "string";
		case Void: return "void";
	}

	return "None";
}

inline void ErrorSemantico(string str)
{
	cout << str;
}

/*
 * Esta estructura representa el atributo sintetizado en la 
 * generacion de código de una Expresion.
 */
struct Result
{
	string place;
	string code;
};

struct Constant
{
	Type type;
	union {
		int int_value;
		bool bool_value;
		char *string_value;
	} value;
};

class Variable
{
public:
	Variable(int offset,int level, int value, bool isArray,int dimension,int isParameter,Type type)
	{
		this->offset = offset;
		this->level = level;
		this->value = value;
		this->isArray = isArray;
		this->dimension = dimension;
		this->type = type;
		this->isParameter = isParameter;
	}
	~Variable(){}

	int offset;
    int level;
    int value;
    bool isArray;
    bool isParameter;
    int dimension;
    Type type; 
};
class Contexto
{
public:
	Contexto(){
		this->currentOffset = 0;
		this->currentLevel = 0;
		contextoAnterior = NULL;
	}

	~Contexto(){}

	map<string, Variable*> contextoMap;
    int currentOffset;
    int currentLevel;
    Contexto *contextoAnterior;
};

#endif /* VALUE_H_ */
