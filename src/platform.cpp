#include "platform.hpp"
#include "Cpu.hpp"
#include "Memory.hpp"
#include "Display.hpp"
#include "Bus.hpp"
//Load the platform's config file
//Platform::Platform(string cfg){
  //cout << "Initialising platform.." << endl;
  //member_paths = file_to_list(cfg);
//}

/*
void Platform::load_components(){
  for( string member_path : member_paths ){
    list<string> cfg = file_to_list(member_path);
    //TODO parse cfg[0] and put the member type in the type variable =======> cfg.front(); for the first elemet -> otherwise you have to make an iterator!
    string type = cfg.front();
    //if( type == "CPU" ){
      //Cpu myCpu;
      //myCpu.load(member_path);
      //members.push_back(myCpu);
    //}
    //if( type == "BUS" ){
      //Bus myBus;
      //myBus.load(member_path);
      //members.push_back(myBus);
    //}
    //if( type == "MEMORY" ){
      //Memory myMemory;
      //myMemory.load(member_path);
      //members.push_back(myMemory);
    //}
    //if( type == "DISPLAY
	" ){
      //Display myDisplay;
      //myDisplay.load(member_path);
      //members.push_back(myDisplay);
    //}
  }
}
*/
 