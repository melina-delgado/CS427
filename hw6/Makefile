CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Checkers: board.o piece.o checkers.o checkerboard.o checker.o king.o math.o
	${CXX} -o $@ ${CXXFLAGS} $^

board.o: board.cpp board.h

piece.o: piece.cpp piece.h

checkerboard.o: checkerboard.cpp checkerboard.h

checker.o: checker.cpp checker.h

king.o: king.cpp king.h


