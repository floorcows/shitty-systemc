#ifndef BUS_H
#define BUS_H
#include "component.hpp"

class Bus : virtual public component {
public:
  void simulate();
  void load(string cfg);
  dataValue read();
  void print();
  
  // constructors
  Bus();
  ~Bus();
  
private:
  list<dataValue> pending;
  list<dataValue> ready;
  int counter;
   
  string label;
  int width;
  string source;
};
#endif
