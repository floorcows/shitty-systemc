#ifndef MEMORY_H
#define MEMORY_H
#include "component.hpp"

class Memory : virtual public component {
public:
  void simulate();
  void load(string cfg);
  void print();
  void bind(list<component *> members);
  string get_label();
  dataValue read();

  // constructors
  Memory();
  ~Memory();

private:
  component * sourcePointer;
  string label;
  unsigned int size;
  int access;
  int current_access;
  string source;
  list<dataValue> memory;
};
#endif
