CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++14

mainPizza: mainPizza.o pizza.o pizzabuilder.o hawaiianpizzabuilder.o cook.o
	$(CXX) $(CXXFLAGS) -o $@ $^

pizza.o: pizza.h

pizzabuilder.o: pizzabuilder.h

hawaiianpizzabuilder.o: hawaiianpizzabuilder.h

cook.o: cook.h
