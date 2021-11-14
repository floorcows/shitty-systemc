#ifndef CLASSES_H
#define CLASSES_H
#include "file.hpp"
#include <errno.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct {
  double value;
  bool flag;
} dataValue;

class component {
public:
  virtual void simulate();
  virtual void load(string cfg);
  virtual void print();
  virtual void bind(list<component *> member);
  virtual string get_label();
  virtual dataValue read();

  // constructors
  component();
  virtual ~component();

private:
  string label;
};

#endif
