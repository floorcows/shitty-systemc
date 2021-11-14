#ifndef PLATFORM_H
#define PLATFORM_H

#include "Bus.hpp"
#include "Cpu.hpp"
#include "Display.hpp"
#include "Memory.hpp"
#include "component.hpp"

class Platform {
public:
  void load_components();
  void simulate();
  void print();
  void bind();

  // constructors
  Platform(string cfg);

private:
  list<component *> members;
  list<string> member_paths;
};

#endif
