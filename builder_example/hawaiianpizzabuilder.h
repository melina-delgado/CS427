#include <string>
#include <iostream>
#include <memory>
#include "pizzabuilder.h"

class HawaiianPizzaBuilder: public PizzaBuilder 
{
  public:
    virtual ~HawaiianPizzaBuilder();
    virtual void buildDough();
    virtual void buildSauce();
    virtual void buildTopping();
};
