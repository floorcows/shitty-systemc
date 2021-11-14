#ifndef CLASSES_H
#define CLASSES_H
#include "file.hpp"
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <errno.h>
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
  virtual void bind(list<component*> member){member.size();}

  // constructors
   component();
   virtual ~component();

private:
  string label;
};

#endif
