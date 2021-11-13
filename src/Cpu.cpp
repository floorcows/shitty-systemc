#include "Cpu.hpp"
 //*************************************Cpu***********************************
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
  prog.set_file_path(find_in_cfg("PROGRAM", options));
  prog.load(); 
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
	
    /*Decode an execute all CPU instruction
    for (string str : my_list) {
      // list<string> word_list = string_to_words(str);
      // for(string word : word_list){cout<<word<<"\t";}
    cout << decode_and_execute(str) << endl;
      // cout <<endl;
    }
	*/

	
}
 

 //*************************************Register***********************************
Register::Register(){
	cout << "\t[\033[31mRegister\033[0m]constructor" << endl;
}
 
 //*************************************Program***********************************
Program::Program(){
	cout << "\t[\033[31mProgram\033[0m]constructor" << endl;
}

void Program::set_file_path(string path){
	file_path = path ;
}
 
void Program::load(){

	cout << "\t[\033[31mProgram\033[0m]load()" << endl;
    
	program_list = file_to_list(file_path);
	program_list_it = program_list.begin();
	
}


