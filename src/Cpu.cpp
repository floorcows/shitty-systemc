#include "Cpu.hpp"
//*************************************Cpu***********************************
Cpu::Cpu() {
  if (IS_DEBUG_ON)
    if (IS_DEBUG_ON)
      cout << "\t[\033[31mCpu\033[0m]constructor" << endl;
  current_active_core = 0;
}

Cpu::~Cpu() {
  if (IS_DEBUG_ON)
    if (IS_DEBUG_ON)
      cout << "\t[\033[31mCpu\033[0m]destructor" << endl;
}

void Cpu::load(string cfg) {
  try {
    if (IS_DEBUG_ON)
      cout << "\t[\033[31mCpu\033[0m]load(" << cfg << ")" << endl;
    list<option_t> options = parse_cfg(cfg);
    label = find_in_cfg("LABEL", options);
    cores = stoi(find_in_cfg("CORES", options));
    frequency = stoi(find_in_cfg("FREQUENCY", options));
    prog_path = find_in_cfg("PROGRAM", options);
    prog.set_file_path(find_in_cfg("PROGRAM", options));
    prog.load();
  } catch (const exception &ex) {
    cout << "ERROR: " << ex.what() << "[Cpu.cpp:Cpu::load()]" << endl;
    cerr << "ERROR: " << ex.what() << "[Cpu.cpp:Cpu::load()]" << endl;
    exit(1);
  }
}

void Cpu::print() {
  cout << "[CPU Print]" << endl;
  cout << "   Label    :\t" << label << endl;
  cout << "   Cores    :\t" << cores << endl;
  cout << "   Frequency:\t" << frequency << endl;
  cout << "   Prog_path:\t" << prog_path << endl;
  cout << endl;
}

void Cpu::simulate() {

  if (IS_DEBUG_ON)
    cout << "\t[\033[31mCpu: " << label << "\033[0m]simulate" << endl;
  for (int i = 0; i < frequency; i++) {
    string commandline = prog.compute();
    if (!prog.get_done()) {
      string str_cmd;
      string str_a;
      string str_b;

      try {
        list<string> word_list = string_to_words(commandline);
        list<string>::iterator it;
        it = word_list.begin();
        str_cmd = *it;
        it++;
        str_a = *it;
        it++;
        str_b = *it;
        it++;
        if (IS_DEBUG_ON)
          cout << "\tcmd:" << str_cmd << "\ta:" << str_a << "\tb:" << str_b
               << "\t";
      } catch (const exception &ex) {
        cout << "ERROR: " << ex.what()
             << "[Cpu.cpp:Cpu::simulate()] missing parameters" << endl;
        cerr << "ERROR: " << ex.what()
             << "[Cpu.cpp:Cpu::simulate()] missing parameters" << endl;
        exit(1);
      }
      double val = 0;
      try {
        double a = 0;
        double b = 0;
        if (string_contains(str_cmd, "ADD")) {
          a = stod(str_a);
          b = stod(str_b);
          val = (a + b);
        } else if (string_contains(str_cmd, "SUB")) {
          a = stod(str_a);
          b = stod(str_b);
          val = (a - b);
        } else if (string_contains(str_cmd, "MUL")) {
          a = stod(str_a);
          b = stod(str_b);
          val = (a * b);
        } else if (string_contains(str_cmd, "DIV")) {
          a = stod(str_a);
          b = stod(str_b);
          val = (a / b);
        } else if (string_contains(str_cmd, "NOP")) {
          val = 0;
        } else {
          throw "CPU instruction not recognized";
        }
      } catch (const exception &ex) {
        cout << "ERROR: " << ex.what()
             << "[Cpu.cpp:Cpu::simulate()] error in executing instruction "
             << endl;
        cerr << "ERROR: " << ex.what()
             << "[Cpu.cpp:Cpu::simulate()] error in executing instruction "
             << endl;
        exit(1);
      }
      if (IS_DEBUG_ON)
        cout << val << endl;
      // TODO add val to the fifo register of the cpu */
      reg.write(val);
    } else {
      if (current_active_core < (cores - 1)) {
        current_active_core++;
        if (IS_DEBUG_ON)
          cout << "************************************************************"
                  "**"
                  "********************"
               << endl;
        if (IS_DEBUG_ON)
          cout << "*********************************CORE #"
               << current_active_core + 1;
        if (IS_DEBUG_ON)
          cout << " enabeled*********************************" << endl;
        if (IS_DEBUG_ON)
          cout << "************************************************************"
                  "**"
                  "********************"
               << endl;

        prog.reset();
      }
    }
  }
}

dataValue Cpu::read() {
  //  if(IS_DEBUG_ON) cout  << "\t[\033[31mCpu\033[0m]read"<< endl;
  dataValue dv;
  dv.flag = reg.is_not_empty();
  dv.value = reg.read();
  return dv;
}

string Cpu::get_label() { return label; }

void bind(list<component *> member) { member.size(); }
//*************************************Program***********************************
Program::Program() {
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mProgram\033[0m]constructor" << endl;
  done = false;
  nop_sended = false;
}

void Program::set_file_path(string path) { file_path = path; }

void Program::load() {

  if (IS_DEBUG_ON)
    cout << "\t[\033[31mProgram\033[0m]load()" << endl;
  program_list = file_to_list(file_path);
  program_list_it = program_list.begin();
}

string Program::compute() {
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mProgram\033[0m]compute" << endl;

  if (program_list_it != program_list.end()) {
    string str = *program_list_it;
    program_list_it++;
    return str;
  } else {

    if (nop_sended) {
      done = true;
    } else {
      nop_sended = true;
    }
    return "NOP 0 0";
  }
}

void Program::reset() {

  cout << endl;
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mProgram\033[0m]reset()" << endl;
  cout << endl;
  program_list_it = program_list.begin();
  done = false;
  nop_sended = false;
}

bool Program::get_done() { return done; }

//*************************************Register***********************************
Register::Register() {
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mRegister\033[0m]constructor" << endl;
}

Register::~Register() {
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mRegister\033[0m]destructor" << endl;
}

bool Register::is_not_empty() {
  return (!reg_list.empty());
}

void Register::write(double value) {
  if (IS_DEBUG_ON)
    cout << "\t[\033[31mRegister\033[0m]write(" << value << ")" << endl;
  reg_list.push_back(value);
}

double Register::read() {
  if (is_not_empty()) {
    double dd = reg_list.front();
    reg_list.pop_front();
    return dd;
  }
  return 0;
}

