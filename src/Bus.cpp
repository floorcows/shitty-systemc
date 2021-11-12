#include "Bus.hpp"



void Bus::load(string cfg){
  try {
  cout << "cfg" << cfg;
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


