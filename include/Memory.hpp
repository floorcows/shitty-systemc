#ifndef MEMORY_H
#define MEMORY_H
#include "component.hpp"

class Memory : virtual public component {
public:
  void simulate();
  void load(string cfg);
  void print();
  virtual void bind(list<component*> member){member.size();}
  
  // constructors
  Memory();
  ~Memory();
  
private:
  string label;
  int size;
  int access;
  string source;
  list<dataValue> memory;
};
#endif
