CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a.out
OBJECTS = zblock.o textdisplay.o grid.o cell.o fallingBlock.o fallenBlock.o iblock.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
