#include "Cpu.hpp"

Program::Program(){}
Register::Register(){}

void Cpu::load(string cfg){
  cout << "cfg" << cfg;
  list<option_t> options = parse_cfg(cfg);
  label = find_in_cfg("LABEL", options);
  cores = stoi(find_in_cfg("CORES", options));
  frequency = stoi(find_in_cfg("FREQUENCY", options));
  prog.file_path = find_in_cfg("PROGRAM", options);
  prog.load();
}

void Program::load(){
  try {
    ifstream f(file_path);

    if (!f) {
      cerr << "ERROR: Target file could not be opened! [Cpu.cpp:Program::load()] "
           << endl;
      exit(1);
    }
  }
  catch (const exception &ex) {
    cerr << "Exception: '" << ex.what() << "'!" << endl;
    exit(1);
  }
}
