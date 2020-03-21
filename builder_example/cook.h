#ifndef __COOK_H__
#define __COOK_H__
#include <string>
#include <iostream>
#include <memory>

#include "pizzabuilder.h"

class Cook
{
public:
	void openPizza();
	void makePizza(PizzaBuilder* pb);
private:
	PizzaBuilder* m_pizzaBuilder;
};
#endif
