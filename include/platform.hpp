#ifndef PLATFORM_H
#define PLATFORM_H

#include "component.hpp"
#include "Cpu.hpp"

class Platform {
public:
  void load_components();
  void simulate();

  //constructors
  Platform(string cfg);

private:
  list<component> members;
  list<string> member_paths;
};

#endif
