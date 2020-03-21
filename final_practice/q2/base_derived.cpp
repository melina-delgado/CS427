#include <iostream>
#include <memory>

class Base
{
public:
  virtual void kick() = 0;
  virtual void pass() { std::cout << "Base::pass" << std::endl; }
  void run() { std::cout << "Base::run" << std::endl; }
private:
  int x;
};

class DerivedA : public Base
{
public:
  void kick() { std::cout << "DerivedA::kick" << std::endl; }
  void pass() { std::cout << "DerivedA::pass" << std::endl; }
  void punt() { std::cout << "DerivedA::punt" << std::endl; }
  //inherits run()
};

class DerivedB : public Base
{
public:
  void kick() { std::cout << "DerivedB::kick" << std::endl; }
  void punt() { std::cout << "DerivedB::punt" << std::endl; }
  void run() { std::cout << "DerivedB::run" << std::endl; }
  //inherits pass()
private:
  int y;
};

class DerivedC : public DerivedA
{
public:
  void kick() { 
    std::cout << "DerivedC::kick" << std::endl; 
    DerivedA::kick(); //outputs DerivedA::kick 
  }
  void run() { std::cout << "DerivedC::run" << std::endl; }
  //inherits pass
  //inherits punt
  //inherits base::run()
};

class DerivedD : private Base
{
public:
  void kick() { std::cout << "DerivedD::kick" << std::endl; }
  void punt() { std::cout << "DerivedD::punt" << std::endl; }
//private:
//  run();
//  pass();
};

int main(int argc, char **argv)
{
  // Which of the following are legal, and for legal statements what is the output?
  std::shared_ptr<DerivedA> one = std::make_shared<DerivedA>(); //legal
  std::shared_ptr<DerivedB> two = std::make_shared<DerivedB>(); //legal
  std::shared_ptr<Base> three = std::make_shared<DerivedC>(); //this is legal because lhs is Base and rhs is Derived class. doesn't work the other way around
  std::shared_ptr<DerivedD> four = std::make_shared<DerivedD>(); //legal
  DerivedA five = DerivedC(); //pretty sure this is legal?

  one->kick(); //one is DerivedA, kick() prints "DerivedA::kick"
  one->pass(); //pass() prints "DerivedA::pass"
  one->run(); // run(0 not defined in DerivedA, prints "Base::run"
  one->punt(); //punt() prints "DerivedA::punt"
  
  two->kick(); //two is DerivedB, kick() prints "DerivedB::kick"
  two->pass();  //pass(), not defined in DerivedB, prints "Base::pass"
  two->run();   //run() prints "DerivedB::run"
  two->punt();  //punt() prints "DerivedB::punt"

  three->kick();  // this prints "DerivedC:kick\n DerivedA::kick"
  three->pass();  //prints "DerivedA::pass"
  three->run();   //prints "Base::run"
  //three->punt();  this isn't in Base.

  four->kick(); //four is DerivedD, kick() prints "DerivedD::kick"
  //four->pass(); // pass() is defined but it's private. pretty sure this is an error 
  //four->run();  //same for run()
  four->punt(); //punt() prints "DerivedD::punt"

  five.kick(); //prints exactly the same as one
  five.pass();
  five.run();
  five.punt();

  // Which of the following cause compiler errors, and what is the result of the ones that do not?
  //std::shared_ptr<Base> v = std::make_shared<DerivedD>(); //this is illegal because Base is a private Base class of D. can't be accessed i guess?
  //std::shared_ptr<Base> w = std::make_shared<Base>();   //Base is abstract since it has a pure virtual function in it. therefore it cannot be instantiated since not all methods are defined!
  //std::shared_ptr<DerivedC> x = one;  //illegal because rhs must be the same or derived class of lhs. one is DerivedA aka a parent
  //std::shared_ptr<DerivedA> y = three;  //same. three is Base, base is a parent.
  std::shared_ptr<DerivedB> z = std::dynamic_pointer_cast<DerivedB>(three); //this is cool. the rhs can only be a Parent class iff there's a dynamic pointer cast. but z is a nullptr because three is a pointer to instance of DerivedC, not DerivedB or something derived from it.
  
  return 0;
}
