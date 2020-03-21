#include <string>
#include <iostream>
#include <memory>

#include "cook.h"
#include "pizzabuilder.h"
void Cook::openPizza()
{
  m_pizzaBuilder->getPizza()->open();
}
void Cook::makePizza(PizzaBuilder* pb)
{
  m_pizzaBuilder = pb;
  m_pizzaBuilder->createNewPizzaProduct();
  m_pizzaBuilder->buildDough();
  m_pizzaBuilder->buildSauce();
  m_pizzaBuilder->buildTopping();
}

