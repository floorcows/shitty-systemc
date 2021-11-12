#ifndef CPU_H
#define CPU_H
#include "component.hpp"

class Program {
public:
  void compute();
  void reset();
  void load();
  string file_path;

  // constructors
  Program();

private:
  ifstream file;
  int counter;
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
  void print();
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