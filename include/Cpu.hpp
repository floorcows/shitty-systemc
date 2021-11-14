#ifndef CPU_H
#define CPU_H
#include "component.hpp"

class Program {
public:
  string compute();
  void reset();
  void load();
  void set_file_path(string path);
  bool get_done();
  // constructors
  Program();

private:
  list<string> program_list;
  list<string>::iterator program_list_it;

  string file_path;
  bool done;
  bool nop_sended;
};

class Register {
public:
  double read();
  void write(double value);
  bool is_not_empty();
  virtual void bind(list<component*> member){member.size();}

  // constructors
  Register();
  ~Register();

private:
  list<double> reg_list;
};

class Cpu : virtual public component {
public:
  void simulate();
  void load(string cfg);
  void print();
  // TODO
  dataValue read();

  // constructors
  Cpu();
  ~Cpu();

  Program prog; // TODO return private
private:
  string label;
  int cores;
  int frequency;
  string prog_path;
  int current_active_core;

  Register reg;
};
#endif
