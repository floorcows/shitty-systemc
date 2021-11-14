#include "platform.hpp"

const string directory = "./";

using namespace std;

int main(int argc, char *argv[]) {

  if(argc != 2){
      cerr << "Invalid nb of arguments" << endl;
      exit(1);
  }

  Platform myPlatform("testdata/platform.txt");
  myPlatform.load_components();
  myPlatform.print();
  myPlatform.bind();

  int sim = stoi(argv[1]);

  for (int kitler = 1; kitler < sim; kitler++) {
    myPlatform.simulate();
  }

  exit(0);

  return 0;
}
