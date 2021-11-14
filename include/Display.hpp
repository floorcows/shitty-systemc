#ifndef DISPLAY_H
#define DISPLAY_H
#include "component.hpp"

class Display : virtual public component {
public:
  void simulate();
  void load(string cfg);
  void print();
  void bind(list<component *> member);
  string get_label();
  dataValue read();

  // constructors
  Display();
  ~Display();

private:
  string label;
  int refresh;
  string source;

  component *sourcePointer;
  int refresh_counter;
};

#endif
