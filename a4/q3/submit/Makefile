CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD  -Werror=vla
EXEC = a4q3
OBJECTS = ppm.o sepia.o flip.o main.o basic.o decorator.o image.o  rotate.o exception.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
