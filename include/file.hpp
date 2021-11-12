#ifndef FILE_H
#define FILE_H

#include <list>
#include <string>
using namespace std;

typedef struct{
  string field;
  string data;
} option_t;

list<string> file_to_list(string);
list<string> string_to_words(string);
list<option_t> parse_cfg(string);
string find_in_cfg(string,list<option_t>);

bool string_contains(string, string);
double decode_and_execute(string);


string rtrim(string);
string ltrim(string);
string  trim(string);

#endif
