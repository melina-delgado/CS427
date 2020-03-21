CXX = g++
CXXFLAGS = -g -Wall -pedantic -std=c++11

SpinOut: mainSpinout.o spinout.o 
	${CXX} ${CXXFLAGS} -o SpinOut mainSpinout.o spinout.o 

mainSpinout.o: mainSpinout.cpp 
	${CXX} ${CXXFLAGS} -c mainSpinout.cpp

spinout.o: spinout.cpp spinout.h
	${CXX} ${CXXFLAGS} -c spinout.cpp
