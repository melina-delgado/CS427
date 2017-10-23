CXX = g++
CXXFLAGS = -g -Wall -pedantic -std=c++11

Conway: mainConway.o conway.o
	${CXX} ${CXXFLAGS} -o Conway mainConway.o conway.o

mainConway.o: mainConway.cpp
	${CXX} ${CXXFLAGS} -c mainConway.cpp

conway.o: conway.cpp conway.h
	${CXX} ${CXXFLAGS} -c conway.cpp
