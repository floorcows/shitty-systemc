#include "platform.hpp"

const string directory = "./";

using namespace std;

int main() {

  try {
    cout << "\t[\033[31mmain\033[0m]Start" << endl;

    list<string> my_list = file_to_list(directory + "testdata/program.txt");

    // for(string str : my_list){ cout<<str<<endl;}

    //---------------------------------------------------

    Cpu *test_cpu = new Cpu();
    test_cpu->load(directory + "testdata/cpu1.txt");
    test_cpu->print();

    Bus *test_bus = new Bus();
    test_bus->load(directory + "testdata/bus1.txt");
    test_bus->print();

    Memory *test_mem = new Memory();
    test_mem->load(directory + "testdata/mem1.txt");
    test_mem->print();

    Display *test_disp = new Display();
    test_disp->load(directory + "testdata/display.txt");
    test_disp->print();

    //---------------------------------------------------

    /*Decode an execute all CPU instruction
        for (string str : my_list) {
          // list<string> word_list = string_to_words(str);
          // for(string word : word_list){cout<<word<<"\t";}
        cout << decode_and_execute(str) << endl;
          // cout <<endl;
        }
    */
    cout << "\t[\033[31mmain\033[0m]End" << endl;
    Platform myPlatform("./testdata/platform.txt");
    myPlatform.load_components();
    myPlatform.print();
  }
  catch (const exception &ex) {
    cerr << "Exception: '" << ex.what() << "'!" << endl;
	
	//---------------------------------------------------
/*
	Cpu *test_cpu =  new Cpu() ;
	test_cpu->load(directory+ "testdata/cpu1.txt");
	test_cpu->print();
	
	Bus *test_bus =  new Bus() ;
	test_bus->load(directory+ "testdata/bus1.txt");
	test_bus->print();
	
	Memory *test_mem =  new Memory() ;
	test_mem->load(directory+ "testdata/mem1.txt");
	test_mem->print();
	
	Display *test_disp =  new Display() ;
	test_disp->load(directory+ "testdata/display.txt");
	test_disp->print();
	
*/
	Cpu test_cpu;
	test_cpu.load(directory+ "testdata/cpu1.txt");
	test_cpu.print();
	
	Bus test_bus;
	test_bus.load(directory+ "testdata/bus1.txt");
	test_bus.print();
	
	Memory test_mem;
	test_mem.load(directory+ "testdata/mem1.txt");
	test_mem.print();
	
	Display test_disp;
	test_disp.load(directory+ "testdata/display.txt");
	test_disp.print();
	
	test_cpu.simulate();
	test_cpu.prog.reset();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();	
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();	
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();	
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();	
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();	
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();
	test_cpu.simulate();	
	test_cpu.simulate();


	
	
	cout << endl <<endl;

>>>>>>> shitty-robert
	
	//---------------------------------------------------
	

    cout << "\t[\033[31mmain\033[0m]End" << endl;
    // Platform myPlatform("./testdata/platform.txt");

  } catch (const exception &ex) {
	cout << "Exception: '" << ex.what() << "' in [main()]" << endl;
	cerr << "Exception: '" << ex.what() << "' in [main()]" << endl;
>>>>>>> 076a05a30766aadd366518b23289ff886c8fb013
    exit(1);
  }
  exit(0);

  return 0;
}
