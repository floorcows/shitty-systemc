#ifndef FILE_H
#define FILE_H

#include <list>
#include <string>
using namespace std;

list<string> file_to_list(string);
list<string> string_to_words(string);
list<list<string>> parse_cfg(string cfg);

bool string_contains(string, string);
double decode_and_execute(string);

#endif
