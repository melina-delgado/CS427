#include <string>
#include <iostream>
#include <memory>

#include "pizza.h"
#include "pizzabuilder.h"

PizzaBuilder::~PizzaBuilder() {}

Pizza* PizzaBuilder::getPizza()
{
  return m_pizza.release();
}
void PizzaBuilder::createNewPizzaProduct()
{
  m_pizza = std::make_unique<Pizza>();
}
