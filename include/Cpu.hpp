#ifndef CPU_H
#define CPU_H
#include "component.hpp"

class Program {
public:
  void compute();
  void reset();
  void load(string file);

  // constructors
  Program();

private:
  int counter;
  string file;
};

class Register {
public:
  dataValue read();
  void write(dataValue value);

  // constructors
  Register();

private:
  list<dataValue> contents;
};

class Cpu : virtual public component {
public:
  void simulate();
  void load(string cfg);
  dataValue read();

  // constructors
  Cpu();
  ~Cpu();

private:
  string label;
  int cores;
  int frequency;
  string prog_path;
  Program prog;
  Register reg;
};
#endif
