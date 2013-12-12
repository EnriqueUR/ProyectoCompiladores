#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "tree.h"


extern ifstream in;
extern int current_line;

static int errors = 0;

using namespace std;

int yyparse();

ClassDef *class_def;
NewClassDef *newClassDef;

int main(int argc, char *argv[])
{
	if (argc > 0) {
		++argv, --argc; /* El primer argumento es el nombre del programa */
		in.open(argv[0], ifstream::in|ifstream::binary);

		if (!in.is_open()) {
			cerr << "No se pudo abrir el archivo " << argv[0] << endl << endl;
			return 0;
		}
	}
	else {
		cerr << "Uso: " << argv[0] << " <archivo>" << endl << endl;
		return 0;
	}

	class_def = 0;
	newClassDef = 0;
	yyparse();

	if (errors == 0) {
        if(class_def != 0)
           newClassDef = (NewClassDef*)class_def->ValidarSemantica();
      
	}

	return 0;
}

void yyerror(const char *message)
{
	errors++;

	fprintf(stderr, "%d:%s\n", current_line, message);
}
