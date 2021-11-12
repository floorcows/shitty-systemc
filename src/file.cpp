#include <errno.h>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>

#include "file.hpp"
#define debug_print 0

using namespace std;

//-------------------------------------------------------------------------------
// Stores each file line in a string list
list<string> file_to_list(string path) {
  if ( debug_print) {cout << "\t[\033[31mfile_to_list\033[0m]" << endl;}

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

  if ( debug_print) {cout << "\t[\033[31mstring_to_words\033[0m]" << endl;}

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
bool string_contains(string str1, string str2){
  if ( debug_print) {cout << "\t[\033[31mstring_contains\033[0m]" << endl;}
  return (strstr(str1.c_str(),str2.c_str()));
}

/*
  //-------------------------------------------------------------------------------
  //Extract a double from a string
  double string_to_double(string str){
    return std::stod(str);
  }

  //-------------------------------------------------------------------------------
  //Extract a double from a string
  double string_to_int(string str){
    return std::stoi(str); 
  }
*/

//-------------------------------------------------------------------------------
// Decode and execute one commad of the CPU
double decode_and_execute(string commandline){

  if ( debug_print) {cout << "\t[\033[31mdecode_and_execute\033[0m]" << endl;}
  list<string> word_list = string_to_words (commandline);
  list<string> :: iterator it;
  it = word_list.begin();
  string str_cmd = *it; it++;
  string str_a = *it; it++;
  string str_b = *it; it++;
   if ( debug_print) { cout << "\tcmd:" << str_cmd << "\ta:" << str_a << "\tb:" << str_b <<"\t"; }  
  try {
	double a = 0;
	double b = 0;	
    if (string_contains(str_cmd,"ADD")){
      a = stod(str_a);
	  b = stod(str_b);
	  return a+b;
     }
    else if(string_contains(str_cmd,"SUB")){
      a = stod(str_a);
	  b = stod(str_b);
	  return a-b;
     }
    else if(string_contains(str_cmd,"MUL")){
      a = stod(str_a);
	  b = stod(str_b);
	  return a*b;
     }
    else if(string_contains(str_cmd,"DIV")){
      a = stod(str_a);
	  b = stod(str_b);
	  return a/b;
     }
    else {
      throw "CPU instruction not recognized";
     }

  } catch (const exception &ex) {
    throw ex;
  }

}













