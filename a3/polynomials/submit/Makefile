CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a3q2
#OBJECTS = temp.o aha.o  rational.o
OBJECTS = rational.o polynomial.o a3q2.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
