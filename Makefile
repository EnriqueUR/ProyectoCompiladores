DECAF_LEXER 	:= decaf_lexer.cpp
DECAF_GRAMMAR	:= decaf_grammar.cpp
DECAF_TOKENS	:= decaf_tokens.h
DECAF_TREE	:= tree.cpp
TARGET  := decaf
SRCS    := ${DECAF_LEXER} ${DECAF_GRAMMAR} ${DECAF_TREE} Util.cpp main.cpp
OBJS    := ${SRCS:.cpp=.o} 

CCFLAGS = -fpermissive -g
LDFLAGS = 
LIBS    = 

.PHONY: all clean

all:: ${TARGET} 

${TARGET}: ${OBJS} 
	${CXX} ${LDFLAGS} -o $@ $^ ${LIBS} 

${OBJS}: %.o: %.cpp
	${CXX} ${CCFLAGS} -o $@ -c $<
	
${DECAF_TREE}: tree.tc 
	treecc -o tree.cpp $<
	
${DECAF_LEXER}:	decaf_lexer.l ${DECAF_TOKENS}
	flex -o $@ $<
	
${DECAF_GRAMMAR} ${DECAF_TOKENS}: decaf_grammar.y
	bison --defines=${DECAF_TOKENS} -r all -o ${DECAF_GRAMMAR} $<
	

clean:: 
	-rm -f *~ *.o ${TARGET} ${DECAF_LEXER} ${DECAF_GRAMMAR} ${DECAF_TOKENS} decaf_grammar.output tree.h tree.cpp

