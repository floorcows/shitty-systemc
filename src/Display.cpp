#include "Display.hpp"

Display::Display() {
  if(IS_DEBUG_ON)  if(IS_DEBUG_ON) cout  << "\t[\033[31mDisplay\033[0m]constructor" << endl;
}

Display::~Display() {
  if(IS_DEBUG_ON)  if(IS_DEBUG_ON) cout  << "\t[\033[31mDisplay\033[0m]destructor" << endl;
}

void Display::load(string cfg) {
  try {
     if(IS_DEBUG_ON) cout  << "\t[\033[31mDisplay\033[0m]load(" << cfg << ")" << endl;
    list<option_t> options = parse_cfg(cfg);
    source = find_in_cfg("SOURCE", options);
    refresh = stoi(find_in_cfg("REFRESH", options));
    label = "NULL";
  } catch (const exception &ex) {
    cout << "ERROR: " << ex.what() << "[Display.cpp:Display::load()]" << endl;
    cerr << "ERROR: " << ex.what() << "[Display.cpp:Display::load()]" << endl;
    exit(1);
  }
}

void Display::print() {
  cout << "[Display Print]" << endl;
  cout << "   Refresh  :\t" << refresh << endl;
  cout << "   Source   :\t" << source << endl;
  cout << endl;
}

void Display::simulate() {
  // TODO
}

string Display::get_label(){
  return label;
}

dataValue Display::read(){
  DEBUG("Calling read() on Display!");
  return {0,0};
}
