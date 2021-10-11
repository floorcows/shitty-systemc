#include <list>
#include <string>
using namespace std;

class component {
public:
  virtual void simulate();
  virtual void load(string name);
};

class CPU : virtual public component {
public:
  void simulate();
  void load(string name);
};

class platform {
public:
  void read_config();
  void load_components();
  void start_simulation(int max_iter);
private:
  list<component> members;
};

void a_f(component salut);
