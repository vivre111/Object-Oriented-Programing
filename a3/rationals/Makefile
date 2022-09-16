CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = mypro
OBJECTS = a3q1.o rational.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
