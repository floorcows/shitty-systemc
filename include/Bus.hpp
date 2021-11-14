#ifndef BUS_H
#define BUS_H
#include "component.hpp"

class Bus : virtual public component {
public:
  void simulate();
  void load(string cfg);
  dataValue read();
  void print();
  void bind(list<component *> member);
  string get_label();

  // constructors
  Bus();
  ~Bus();

private:
  list<dataValue> pending;
  list<dataValue> ready;
  int counter;

  string label;
  component *sourcePointer;
  int width;
  string source;
};
#endif
