#ifndef __PIZZABUILDER_H__
#define __PIZZABUILDER_H__
#include <string>
#include <iostream>
#include <memory>
#include "pizza.h"

class PizzaBuilder
{
  public:
    virtual ~PizzaBuilder();

    Pizza* getPizza();

    void createNewPizzaProduct();

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
  protected:
    std::unique_ptr<Pizza> m_pizza;
};

#endif
