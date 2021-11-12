#include "Display.hpp"


void Display::load(string cfg){
  try {
  cout << "cfg" << cfg;
  list<option_t> options = parse_cfg(cfg);
  source  = find_in_cfg("SOURCE", options);
  refresh = stoi(find_in_cfg("REFRESH", options));
  }
  catch (const exception &ex) {
    cerr << "ERROR: " << ex.what() << "[Display.cpp:Display::load()]" << endl;
    exit(1);
  }
}

