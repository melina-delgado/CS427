#ifndef __PIZZA_H__
#define __PIZZA_H__

#include <string>
#include <iostream>
#include <memory>

class Pizza
{
  public:
    void setDough(const std::string& dough);

    void setSauce(const std::string& sauce);

    void setTopping(const std::string& topping);

    void open() const;
  private:
    std::string m_dough;
    std::string m_sauce;
    std::string m_topping;
};

#endif
