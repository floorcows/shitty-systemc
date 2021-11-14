#include "Cpu.hpp"

Program::Program(){}
Register::Register(){}

Cpu::Cpu(){
	//TODO
	 cout << "\t[\033[31mCpu\033[0m]constructor" << endl;
}

Cpu::~Cpu() {
	//TODO
	 cout << "\t[\033[31mCpu\033[0m]destructor" << endl;
}

void Cpu::load(string cfg){
  try {
  cout << "\t[\033[31mCpu\033[0m]load(" << cfg << ")" << endl;
  list<option_t> options = parse_cfg(cfg);
  label     = find_in_cfg("LABEL", options);
  cores     = stoi(find_in_cfg("CORES", options));
  frequency = stoi(find_in_cfg("FREQUENCY", options));
  prog_path = find_in_cfg("PROGRAM", options);
  prog.file_path = find_in_cfg("PROGRAM", options);
  //prog.load(); 
  }
  catch (const exception &ex) {
    cerr << "ERROR: " << ex.what() << "[Cpu.cpp:Cpu::load()]" << endl;
    exit(1);
  }
}

void Cpu::print(){
cout << "[CPU Print]" <<endl;
cout << "   Label    :\t"<<label<<endl;
cout << "   Cores    :\t"<<cores<<endl;
cout << "   Frequency:\t"<<frequency<<endl;
cout << "   Prog_path:\t"<<prog_path<<endl;
cout << endl; 
}



void Cpu::simulate(){
	//TODO
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


