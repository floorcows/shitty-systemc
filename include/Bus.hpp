#ifndef BUS_H
#define BUS_H
#include "component.hpp"

class Bus : virtual public component {
public:
  void simulate();
  void load(string cfg);
  dataValue read();

  // constructors
  Bus();

private:
  list<dataValue> pending;
  list<dataValue> ready;
  int counter;
};
#endif
