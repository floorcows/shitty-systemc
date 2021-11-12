#include <errno.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <string>

#include "file.hpp"

using namespace std;

//-------------------------------------------------------------------------------
// Stores each file line in a string list
list<string> file_to_list(string path) {
  cout << "\t[\033[31mfile_to_list\033[0m]" << endl;

  list<string> mylist;
  try {
    ifstream f(path);

    if (!f) {
      cerr << "ERROR: Target file could not be opened! [file.cpp:file_to_list] " << endl;
      exit(1);
    }
    string line;

    while (getline(f, line)) {
      mylist.push_back(line);
      // cout << mylist.back() << endl;
    }
  } catch (const exception &ex) {
    cerr << "Exception: '" << ex.what() << "'!" << endl;
    exit(1);
  }

  return mylist;
}

//-------------------------------------------------------------------------------
// Stores each word in a string list
list<string> string_to_words(string str) {

  cout << "\t[\033[31mstring_to_words\033[0m]" << endl;

  list<string> mylist;
  stringstream ss(str);
  string word; // for storing each word

  while (ss >> word) {
    // print the read word
    mylist.push_back(word);
    // cout << word << "\n";
  }

  return mylist;
}
