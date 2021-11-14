#include "platform.hpp"

const string directory = "./";

using namespace std;

int main( int argc , char* argv[]) {

  try {
     if(IS_DEBUG_ON) cout  << "\t[\033[31mmain\033[0m]Start" << endl;

    list<string> my_list = file_to_list(directory + "testdata/program.txt");


	Platform myPlatform("testdata/platform.txt");
	myPlatform.load_components();
	myPlatform.print();
	myPlatform.bind();
/*----------------well done main------------------------------------------------------------------*/
	if (argc == 2){
      int sim = stoi(argv[1]);
      
      for (int kitler = 1 ; kitler < sim ; kitler ++){
      myPlatform.simulate();
      }
	}
	else cerr << "Invalid nb of arguments" << endl;

     if(IS_DEBUG_ON) cout  << "\t[\033[31mmain\033[0m]End" << endl;
    // Platform myPlatform("./testdata/platform.txt");
/*----------------well done main------------------------------------------------------------------*/

  } catch (const exception &ex) {
    cout << "Exception: '" << ex.what() << "' in [main()]" << endl;
    cerr << "Exception: '" << ex.what() << "' in [main()]" << endl;
    exit(1);
  }

  exit(0);

  return 0;
}
