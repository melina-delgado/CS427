CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Fission: board.o piece.o fission.o fissionboard.o stone.o king.o math.o
	${CXX} -o $@ ${CXXFLAGS} $^

board.o: board.cpp board.h

piece.o: piece.cpp piece.h

fissionboard.o: fissionboard.cpp fissionboard.h

stone.o: stone.cpp stone.h

king.o: king.cpp king.h


