#include "Bus.hpp"

Bus::Bus(){
	//TODO
	 cout << "\t[\033[31mBus\033[0m]constructor" << endl;
}

Bus::~Bus() {
	//TODO
	 cout << "\t[\033[31mBus\033[0m]destructor" << endl;
}


void Bus::load(string cfg){
  try {
  cout << "\t[\033[31mBus\033[0m]load(" << cfg << ")"  << endl;
  list<option_t> options = parse_cfg(cfg);
  label  = find_in_cfg("LABEL", options);
  width  = stoi(find_in_cfg("WIDTH", options));
  source = find_in_cfg("SOURCE", options);
  }
  catch (const exception &ex) {
    cerr << "ERROR: " << ex.what() << "[Bus.cpp:Bus::load()]" << endl;
    exit(1);
  }
}

void Bus::print(){
cout << "[Bus Print]" <<endl;
cout << "   Label    :\t"<<label<<endl;
cout << "   Width    :\t"<<width<<endl;
cout << "   Source   :\t"<<source<<endl;

cout << endl; 
}

void Bus::simulate(){
	//TODO
}
