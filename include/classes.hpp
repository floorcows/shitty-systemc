#ifndef CLASSES_H
#define CLASSES_H
#include "file.hpp"
#include <iostream>
#include <list>
#include <string>
using namespace std;

typedef struct {
  double value;
  bool flag;
} dataValue;

class Program {
public:
  void compute();
  void reset();

  // constructors
  Program(string file);

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

class component {
public:
  virtual void simulate();
  virtual void load(string cfg);

  // constructors
  component();

private:
  string label;
};

class Memory : virtual public component {
public:
  void simulate();
  void load(string cfg);

  // constructors
  Memory();

private:
  string label;
  int size;
  int access;
  string source;
  list<dataValue> memory;
};

class Display : virtual public component {
public:
  void simulate();
  void load(string cfg);

  // constructors
  Display();

private:
  string label;
  int refresh;
  string source;
};

class Bus : virtual public component {
public:
  void simulate();
  void load(string cfg);
  dataValue read();

  // constructors
  Bus();

private:
  list<dataValue> pending;
  list<dataValue> ready;
  int counter;
};

class Cpu : virtual public component {
public:
  void simulate();
  void load(string cfg);
  dataValue read();

  // constructors
  Cpu();

private:
  string label;
  int cores;
  int frequency;
  string prog_path;
  Program prog;
  Register reg;
};
#endif
