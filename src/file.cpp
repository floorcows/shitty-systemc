#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <exception>
#include <errno.h>
#include <stdlib.h>
#include <sstream>

#include "file.hpp"

using namespace std;

//-------------------------------------------------------------------------------
list<string> file_to_list (string path){

  cout<< "\t[file_to_list]"<<endl;
  
  list<string> mylist;  
   try
  {
    ifstream f (path);

    if(!f)
    {
        cerr << "ERROR: Cannot open 'teste.txt'!" << endl;
        exit(1);
    }
    string line;
    

    while (getline(f,line))
    {
        mylist.push_back(line);     
        //cout << mylist.back() << endl;
    }
  }
  catch(const exception& ex)
  {
    cerr << "Exception: '" << ex.what() << "'!" << endl;
    exit(1);
  }
  
  return mylist;

}

//-------------------------------------------------------------------------------

list<string> string_to_words (string str){
 
  cout<< "\t[string_to_words]"<<endl;

  list<string> mylist;
  stringstream ss(str);
  string word; // for storing each word
  
  while (ss >> word) 
  {
      // print the read word
      mylist.push_back(word);
      //cout << word << "\n";
  }




  return mylist;

}


