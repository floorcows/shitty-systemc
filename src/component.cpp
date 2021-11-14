#include "component.hpp"

component::component() {
   if(IS_DEBUG_ON) cout  << "\t[\033[31mComponent\033[0m]constructor" << endl;
}

component::~component() {
   if(IS_DEBUG_ON) cout  << "\t[\033[31mComponent\033[0m]destructor" << endl;
}

void component::simulate() {
   if(IS_DEBUG_ON) cout  << "\t[\033[31mComponent\033[0m]simulate()" << endl;
}

void component::load(string cfg) {
   if(IS_DEBUG_ON) cout  << "\t[\033[31mComponent\033[0m]load()" << cfg << ")" << endl;
}

void component::print() {
   if(IS_DEBUG_ON) cout  << "\t[\033[31mComponent\033[0m]print()" << endl;
}

void component::bind(list<component *> member) {
   member.size();
   if(IS_DEBUG_ON) cout  << "\t[\033[31mComponent\033[0m]print()" << endl;
}

string component::get_label(){
   DEBUG("Calling get_labal() on component!");
   return "NULL";
}

dataValue component::read(){
   DEBUG("Calling get_labal() on component!");
   return {0,0};
}
