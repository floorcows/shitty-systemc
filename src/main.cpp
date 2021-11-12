#include "platform.hpp"

const string directory = "./";

using namespace std;

int main() {

  try {
    cout << "\t[\033[31mmain\033[0m]Start" << endl;

    list<string> my_list = file_to_list(directory + "testdata/program.txt");

    // for(string str : my_list){ cout<<str<<endl;}

    for (string str : my_list) {
      // list<string> word_list = string_to_words(str);
      // for(string word : word_list){cout<<word<<"\t";}
      cout << decode_and_execute(str) << endl;
      // cout <<endl;
    }

    cout << "\t[\033[31mmain\033[0m]End" << endl;
    // Platform myPlatform("./testdata/platform.txt");

  } catch (const exception &ex) {
    cerr << "Exception: '" << ex.what() << "'!" << endl;
    exit(1);
  }
  exit(0);

  return 0;
}
