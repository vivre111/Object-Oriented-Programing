CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a.out
OBJECTS = main.o makefile.o  target.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
