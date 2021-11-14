#include "Display.hpp"

Display::Display() {
  if(IS_DEBUG_ON)  if(IS_DEBUG_ON) cout  << "\t[\033[31mDisplay\033[0m]constructor" << endl;
  refresh_counter = 0;
}

Display::~Display() {
  if(IS_DEBUG_ON)  if(IS_DEBUG_ON) cout  << "\t[\033[31mDisplay\033[0m]destructor" << endl;
}

void Display::load(string cfg) {
  try {
     if(IS_DEBUG_ON) cout  << "\t[\033[31mDisplay\033[0m]load(" << cfg << ")" << endl;
    list<option_t> options = parse_cfg(cfg);
    source = find_in_cfg("SOURCE", options);
	//source = "Main processing unit";
	//source = "My bus 1";
	//source = "Coproc";
	//source = "Main processing unit";
	//source = "Main processing unit";
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
  refresh_counter ++;
  if(IS_DEBUG_ON)  cout  << "\t[\033[31mDisplay\033[0m]simulate" << endl;
  if(refresh_counter == refresh){
	   
	  refresh_counter= 0;
	  
	  dataValue dv = read();

	  if (dv.flag) cout  << "\t[\033[34mDisplay\033[0m]:\t" ;

      while (dv.flag) {
        cout << dv.value << endl << "\t\t\t";
        dv = read();
      }
	  cout << endl;
  }
  
}

string Display::get_label(){
  return label;
}

dataValue Display::read(){
  return sourcePointer->read();
  return {0,0};

}

void Display::bind(list<component *> members) {
  if(IS_DEBUG_ON) cout << "Binding Display: " << label << endl;
  for( component * member : members ){
    if( !source.compare(member->get_label()) ){
      sourcePointer = member;
    }
  }
  DEBUG("Display is bound to: ");
  if(IS_DEBUG_ON) sourcePointer->print();
}











