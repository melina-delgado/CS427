CXX = g++
CXXFLAGS = -g -Wall -pedantic -std=c++11 

Game: game_main.o conway.o spinout.o puzzle_move.o puzzle.o
	${CXX} ${CXXFLAGS} -o $@ $^

