CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

Distance: Distance.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ 

Distance.o: Distance.cpp
	g++ $(CXXFLAGS) -c Distance.cpp
