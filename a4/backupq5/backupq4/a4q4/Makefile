CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a.out
OBJECTS = main.o  textdisplay.o cell.o grid.o state.o info.o subject.o observer.o error.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
