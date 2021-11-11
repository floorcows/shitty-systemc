#include <list>
#include <string>
using namespace std;

typedef struct {double value; bool flag;} dataValue;

class Program {
public:
  Program(string file);
  void compute();
  void reset();

private:
  int counter;
  string file;
};

class Register {
public:
  Register();
  dataValue read();
  void write(dataValue value);
private:
  list<dataValue> contents;
};

class component {
public:
  virtual void simulate();
  
//constructors
  component();
  component(string label);

private:
  string label;
};

class Memory : virtual public component {
public:
  void simulate();
  Memory(string label, int size, int access, string source);
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
  Display(string label, int refresh, string source);
private:
  string label;
  int refresh;
  string source;
};

class Bus : virtual public component {
public:
  void simulate();
  Bus(string label, int width, string source);
  dataValue read();
private:
  list<dataValue> pending;
  list<dataValue> ready;
  int counter;
};

class CPU : virtual public component {
public:
  void simulate();
  dataValue read();

  //constructors
  CPU(string label, int cores, int frequency, string prog_path);

private:
  string label;
  int cores;
  int frequency;
  string prog_path;
  Program prog;
  Register reg;
};

class Platform {
public:
  void read_config();
  void load_components();
  void simulate();
  Platform();
private:
  list<component> members;
};

