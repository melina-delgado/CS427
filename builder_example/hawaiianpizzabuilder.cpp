#include <string>
#include <iostream>
#include <memory>
#include "hawaiianpizzabuilder.h"

HawaiianPizzaBuilder::~HawaiianPizzaBuilder() {}
void HawaiianPizzaBuilder::buildDough()
{
  m_pizza->setDough("cross");
}
void HawaiianPizzaBuilder::buildSauce()
{
  m_pizza->setSauce("mild");
}
void HawaiianPizzaBuilder::buildTopping()
{
  m_pizza->setTopping("ham+pineapple");
}
