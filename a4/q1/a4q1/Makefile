CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a4q1
OBJECTS = expression.o main.o  absOperation.o variable.o intVal.o binaryOper.o unaryOper.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
