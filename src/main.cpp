#include <iostream>
#include "file.hpp"
#include "classes.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <exception>
#include <errno.h>
#include <stdlib.h>

const string directory = "/mnt/c/robert/grenoble/phelma/3a/S9/oop/Project/github_project/shitty-systemc/";

using namespace std;


int main(){
  cout << "\t[main]Start" << endl;

  list<string> my_list = file_to_list(directory+"testdata/program.txt");
  for(string str : my_list){
     cout<<str<<endl;
   }  
  cout << "\t[main]End" << endl;
  exit(0);
}


