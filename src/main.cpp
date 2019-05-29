#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Target {
  Target(string n) : name(n) {}
  string name;
  vector<string> lines;
};

int main(int argc, char* argv[]) {
  /// parse lines ===--------------=== ///
  vector<Target> targets;
  targets.emplace_back("root");

  ifstream kakefile {"kakefile"};

  std::string line;
  while (std::getline(kakefile, line)) {
    if (line.empty()) continue;

    if (line[0] != ' ') {
      targets.emplace_back(line);
    } else {
      targets.back().lines.emplace_back(line.substr(2));
    }
  }

  /// make targets ===-------------=== ///

  Target t = ([&]() {
    if (argc == 1) {
      return targets[0];
    } else if (argc == 2) {
      auto t = find_if(targets.begin(), targets.end(), [](Target& t){ return t.name == "root"; });
      if (t != targets.end()) {
        return *t;
      } else {
        exit(1);
      }
    } else {
      // print help
      cout << "usage: kake [target]" << endl;
      exit(1);
    }
  })();
  
  cout << t.name << endl;
  for (auto&& line : t.lines) {
    cout << " $ " << line << endl;
    system(line.c_str());
  }
}