#include "component.hpp"

component::component(){
	//TODO
	 cout << "\t[\033[31mComponent\033[0m]constructor" << endl;
}

component::~component(){
	//TODO
	 cout << "\t[\033[31mComponent\033[0m]destructor" << endl;
}

void component::simulate(){
	//TODO
	 cout << "\t[\033[31mComponent\033[0m]simulate()" << endl;
}

void component::load(string cfg){
	//TODO
	 cout << "\t[\033[31mComponent\033[0m]load("<< cfg <<")" << endl;
}

void component::print(){
	//TODO
	 cout << "\t[\033[31mComponent\033[0m]print()" << endl;
}
