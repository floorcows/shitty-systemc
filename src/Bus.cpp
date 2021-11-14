#include "Bus.hpp"

Bus::Bus() {
  if(IS_DEBUG_ON)  if(IS_DEBUG_ON) cout  << "\t[\033[31mBus\033[0m]constructor" << endl;
}

Bus::~Bus() {
  if(IS_DEBUG_ON)  if(IS_DEBUG_ON) cout  << "\t[\033[31mBus\033[0m]destructor" << endl;
}

void Bus::load(string cfg) {
  try {
    if(IS_DEBUG_ON)  if(IS_DEBUG_ON) cout  << "\t[\033[31mBus\033[0m]load(" << cfg << ")" << endl;
    list<option_t> options = parse_cfg(cfg);
    label = find_in_cfg("LABEL", options);
    width = stoi(find_in_cfg("WIDTH", options));
    source = find_in_cfg("SOURCE", options);
  } catch (const exception &ex) {
    cerr << "ERROR: " << ex.what() << "[Bus.cpp:Bus::load()]" << endl;
    exit(1);
  }
}

void Bus::print() {
  cout << "[Bus Print]" << endl;
  cout << "   Label    :\t" << label << endl;
  cout << "   Width    :\t" << width << endl;
  cout << "   Source   :\t" << source << endl;
  cout << endl;
}

void Bus::bind(list<component *> members){
  if(IS_DEBUG_ON) cout << "Binding Bus: " << label << endl;
  for( component * member : members ){
    if( !source.compare(member->get_label()) ){
      sourcePointer = member;
    }
  }
  DEBUG("Bus is bound to: ");
  if(IS_DEBUG_ON) sourcePointer->print();
}

// Bus simulation step
void Bus::simulate() {
   if(IS_DEBUG_ON) cout  << "\t[\033[31mBus: " << label << "\033[0m]simulate" << endl;

  //Moving pending values to ready values
  while( !pending.empty() ){
    ready.push_back(pending.back());
    if(IS_DEBUG_ON) cout << "Moving value: " << pending.back().value << " to Ready" << endl;
    pending.pop_back();
  }

  // Fetching new pending values (only up to bus.width)
  int counter = 0;
  dataValue value;
  while((value = sourcePointer->read()).flag && counter < width){
    counter++;
    pending.push_front(value);
    if(IS_DEBUG_ON) cout << "Moving value number" << counter << ": " << pending.front().value << " to Pending" << endl;
    if(IS_DEBUG_ON) cout << "Pending: ";
    if(IS_DEBUG_ON){
      for(dataValue value : pending){
        cout << value.value << " | ";
      }
      cout << endl;
    }
  }
}

// Get bus label
string Bus::get_label(){
  return label;
}

dataValue Bus::read(){
  //TODO A bus does not return 0 value
  DEBUG("Calling read() on Bus!");
  
  dataValue dv = {0,0};
  dv.flag = !ready.empty();	
  if(dv.flag){
  dv.value = ready.front().value;
  pending.pop_front();
  }
  
  return dv;
  
  
  //return {0,0};
}
