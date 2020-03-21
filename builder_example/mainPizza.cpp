#include <string>
#include <iostream>
#include <memory>

#include "pizzabuilder.h"
#include "hawaiianpizzabuilder.h"
#include "cook.h"
#include "pizza.h"

int main()
{
	Cook cook;
	HawaiianPizzaBuilder hawaiianPizzaBuilder;

	cook.makePizza(&hawaiianPizzaBuilder);
	cook.openPizza();
}
