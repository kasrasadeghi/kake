#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
  ifstream kakefile {"kakefile"};
  stringstream ss;
  ss << kakefile.rdbuf();
  cout << ss.str();
}