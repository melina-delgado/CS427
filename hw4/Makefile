CXX = g++
CXXFLAGS = -g -Wall -pedantic -std=c++11

Cooccur: main_cooccur.o cooccur.o
	${CXX} ${CXXFLAGS} -o Cooccur main_cooccur.o cooccur.o

main_cooccur.o: main_cooccur.cpp
	${CXX} ${CXXFLAGS} -c main_cooccur.cpp

cooccur.o: cooccur.cpp cooccur.h
	${CXX} ${CXXFLAGS} -c cooccur.cpp
