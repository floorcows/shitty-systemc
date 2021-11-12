#include "Cpu.hpp"

Program::Program(){}
Register::Register(){}

void Cpu::load(string cfg){
  cout << "cfg" << cfg;
  list<string> lines = file_to_list(cfg);
}
