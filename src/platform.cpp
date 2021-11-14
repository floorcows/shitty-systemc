#include "platform.hpp"
#include "Bus.hpp"
#include "Cpu.hpp"
#include "Display.hpp"
#include "Memory.hpp"
// Load the platform's config file
Platform::Platform(string cfg) {
  cout << "Initialising platform.." << endl;
  member_paths = file_to_list(cfg);
}

void Platform::load_components() {
  cout << "Loading components..." << endl;
  for (string member_path : member_paths) {
    list<string> cfg = file_to_list(member_path);
    string type;
    stringstream ss(cfg.front());
    getline(ss, type, ':');
    getline(ss, type, ':');
    type = trim(type);
    if (type == "CPU") {
      Cpu *myCpu = new Cpu;
      myCpu->load(member_path);
      members.push_back(myCpu);
    }
    if (type == "BUS") {
      Bus *myBus = new Bus;
      myBus->load(member_path);
      members.push_back(myBus);
    }
    if (type == "MEMORY") {
      Memory *myMemory = new Memory;
      myMemory->load(member_path);
      members.push_back(myMemory);
    }
    if (type == "DISPLAY") {
      Display *myDisplay = new Display;
      myDisplay->load(member_path);
      members.push_back(myDisplay);
    }
  }
}

void Platform::print() {
  cout << "Printing platform's contents!" << endl;
  for (component *comp : members) {
    comp->print();
  }
  cout << "Done printing! kitler" << endl;
}

void Platform::simulate() {
  if(IS_DEBUG_ON) cout << "Simulating platform!" << endl;
  for (component *comp : members) {
    comp->simulate();
  }
  if(IS_DEBUG_ON) cout << "Done simulating! kitler" << endl;
}

void Platform::bind() {
  cout << "Platform bind!" << endl;
  for (component *comp : members) {
    comp->bind(members);
  }
  cout << "Done platform bind! kitler" << endl;
}
