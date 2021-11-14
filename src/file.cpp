#include <algorithm>
#include <bits/stdc++.h>
#include <errno.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <string>

#include "file.hpp"
#define debug_print 0

using namespace std;

//-------------------------------------------------------------------------------
// Stores each file line in a string list
list<string> file_to_list(string path) {
  if (debug_print) {
     if(IS_DEBUG_ON) cout  << "\t[\033[31mfile_to_list\033[0m]" << endl;
  }

  list<string> mylist;
  try {
    ifstream f(path);

    if (!f) {
      cout << "ERROR: Target file could not be opened! [file.cpp:file_to_list] "
           << endl;
      cerr << "ERROR: Target file could not be opened! [file.cpp:file_to_list] "
           << endl;

      exit(1);
    }
    string line;

    while (getline(f, line)) {
      mylist.push_back(line);
      // cout << mylist.back() << endl;
    }
  } catch (const exception &ex) {
    cout << "Exception: '" << ex.what() << "' in [file.cpp:file_to_list]"
         << endl;
    cerr << "Exception: '" << ex.what() << "' in [file.cpp:file_to_list]"
         << endl;
    exit(1);
  }

  return mylist;
}

//-------------------------------------------------------------------------------
// Stores each word in a string list
list<string> string_to_words(string str) {

  if (debug_print) {
     if(IS_DEBUG_ON) cout  << "\t[\033[31mstring_to_words\033[0m]" << endl;
  }

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

//-------------------------------------------------------------------------------
// Return true if the first string contains the other
bool string_contains(string str1, string str2) {
  if (debug_print) {
     if(IS_DEBUG_ON) cout  << "\t[\033[31mstring_contains\033[0m]" << endl;
  }
  return (strstr(str1.c_str(), str2.c_str()));
}

/*
  //-------------------------------------------------------------------------------
  //Extract a double from a string
  double string_to_double(string str){
    return stod(str);
  }

  //-------------------------------------------------------------------------------
  //Extract a double from a string
  double string_to_int(string str){
    return stoi(str);
  }
*/

//-------------------------------------------------------------------------------
// Parses configs
list<option_t> parse_cfg(string cfg) {
  // cout << "test\n\n";
  list<option_t> output;
  list<string> cfg_lines = file_to_list(cfg);
  for (string line : cfg_lines) {
    option_t option;
    stringstream ss(line);
    getline(ss, option.field, ':');
    getline(ss, option.data, ':');
    option.field = trim(option.field);
    option.data = trim(option.data);
    output.push_back(option);
  }
  return output;
}
//-------------------------------------------------------------------------------
// Finds element in a parsed config file
string find_in_cfg(string field, list<option_t> options) {
  field = trim(field);
  for (option_t option : options) {
    if (option.field == field) {
      return trim(option.data);
    }
  }
  return "NULL_STRING";
}

//-------------------------------------------------------------------------------
// trim strings and remove space from both sides
const string WHITESPACE = " \n\r\t\f\v";
string ltrim(const string s) {
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == string::npos) ? "" : s.substr(start);
}
string rtrim(const string s) {
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == string::npos) ? "" : s.substr(0, end + 1);
}
string trim(const string s) { return rtrim(ltrim(s)); }
