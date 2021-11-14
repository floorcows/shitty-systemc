#include "Memory.hpp"

Memory::Memory() {
  if (IS_DEBUG_ON)
    if (IS_DEBUG_ON)
      cout << "\t[\033[31mMemory\033[0m]constructor" << endl;
}

Memory::~Memory() {
  if (IS_DEBUG_ON)
    if (IS_DEBUG_ON)
      cout << "\t[\033[31mMemory\033[0m]destructor" << endl;
}

void Memory::load(string cfg) {
  try {
    if (IS_DEBUG_ON)
      cout << "\t[\033[31mMemory\033[0m]load(" << cfg << ")" << endl;
    list<option_t> options = parse_cfg(cfg);
    label = find_in_cfg("LABEL", options);
    size = stoi(find_in_cfg("SIZE", options));
    access = stoi(find_in_cfg("ACCESS", options));
    source = find_in_cfg("SOURCE", options);
    current_access = 0;
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
  if (IS_DEBUG_ON) cout << "\t[\033[31mMemory: " << label << "\033[0m]simulate" << endl;
  if (current_access != access) {
    if(IS_DEBUG_ON) cout << "Memory is waiting for access.." << endl;
    current_access++;
    return;
  }
  current_access = 0;
  dataValue value;
  while ((value = sourcePointer->read()).flag) {
    if(IS_DEBUG_ON) cout << "\t Adding value: " << value.value << " to memory." << endl;
    if (memory.size() == size){
      if(IS_DEBUG_ON) cout << "Memory full, dumping value" << endl;
      return;
    }
    memory.push_front(value);
  }
  if(IS_DEBUG_ON){
    cout << "Current memory is: ";
    for (dataValue i : memory) {
      cout << i.value << " | ";
    }
    cout << endl;
  }
}

string Memory::get_label() { return label; }

dataValue Memory::read() {
  dataValue out;
  if (memory.empty()) {
    out.flag = 0;
    out.value = 0;
  } else {
    out = memory.back();
    memory.pop_back();
  }

  return out;
}

void Memory::bind(list<component *> members) {
  if (IS_DEBUG_ON)
    cout << "Binding Bus: " << label << endl;
  for (component *member : members) {
    if (!source.compare(member->get_label())) {
      sourcePointer = member;
    }
  }
  DEBUG("Memory is bound to: ");
  if (IS_DEBUG_ON)
    sourcePointer->print();
}
