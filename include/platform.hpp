#ifndef PLATFORM_H
#define PLATFORM_H

#include "component.hpp"
#include "Cpu.hpp"
#include "Bus.hpp"
#include "Memory.hpp"
#include "Display.hpp"


class Platform {
public:
  void load_components();
  void simulate();
  void print();
  void bind();

  //constructors
  Platform(string cfg);

private:
  list<component *> members;
  list<string> member_paths;
};

#endif
