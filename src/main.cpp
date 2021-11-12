#include <iostream>
#include "file.hpp"
#include "classes.hpp"
#include "platform.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <exception>
#include <errno.h>
#include <stdlib.h>

const string directory = "./";

using namespace std;


int main(){
  cout << "\t[\033[31mmain\033[0m]Start" << endl;

  list<string> my_list = file_to_list(directory+"testdata/program.txt");
  list<string> my_list2 = my_list;

/*  for(string str : my_list2){
     cout<<str<<endl;
   }
*/

   for(string str : my_list2){
     list<string> word_list = string_to_words(str);
       for(string word : word_list){
         cout<<word<<"\t";
        }
       cout <<endl;
   }

  cout << "\t[\033[31mmain\033[0m]End" << endl;
  //Platform myPlatform("./testdata/platform.txt");
  exit(0);

  return 0;
}


