#include "Memory.hpp"

Memory::Memory() {
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mMemory\033[0m]constructor" << endl;
}

Memory::~Memory() {
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mMemory\033[0m]destructor" << endl;
}

void Memory::load(string cfg) {
  try {
    cout << "\t[\033[31mMemory\033[0m]load(" << cfg << ")" << endl;
    list<option_t> options = parse_cfg(cfg);
    label = find_in_cfg("LABEL", options);
    size = stoi(find_in_cfg("SIZE", options));
    access = stoi(find_in_cfg("ACCESS", options));
    source = find_in_cfg("SOURCE", options);
    // list<dataValue> memory;
  } catch (const exception &ex) {
    cout << "ERROR: " << ex.what() << "[Memory.cpp:Memory::load()]" << endl;
    cerr << "ERROR: " << ex.what() << "[Memory.cpp:Memory::load()]" << endl;
    exit(1);
  }
}

void Memory::print() {
  cout << "[Memory Print]" << endl;
  cout << "   Label    :\t" << label << endl;
  cout << "   Size     :\t" << size << endl;
  cout << "   Access   :\t" << access << endl;
  cout << "   Source   :\t" << source << endl;
  // list<dataValue> memory;
  cout << endl;
}

void Memory::simulate() {
  // TODO
}

string Memory::get_label() { return label; }

dataValue Memory::read() {
  DEBUG("Calling read() on Memory!");
  return {0, 0};
}
