#include <bits/stdc++.h>

#include <vector>

struct Step {
  char dir;
  int dist;
};

int main(int argc, char* argv[]) {
  std::ifstream file("input.txt");
  std::string s;
  std::vector<Step> steps;
  int pass1 = 0;
  int pass2 = 0;

  while (std::getline(file, s)) {
    Step st;
    st.dir = s[0];
    st.dist = std::stoi(s.substr(1));
    steps.push_back(st);
  }

  int start1 = 50;
  for (auto& st : steps) {
    if (st.dir == 'L') {
      start1 = ((start1 - st.dist) % 100 + 100) % 100;
    } else {
      start1 = (start1 + st.dist) % 100;
    }
    if (start1 == 0)
      pass1++;
  }

  int start2 = 50;
  for (auto& st : steps) {
    for (int i = 0; i < st.dist; i++) {
      if (st.dir == 'L') {
        start2 = (start2 - 1 + 100) % 100;
      } else {
        start2 = (start2 + 1) % 100;
      }
      if (start2 == 0) {
        pass2++;
      }
    }
  }

  std::cout << "Task 1: " << pass1 << std::endl;
  std::cout << "Task 2: " << pass2 << std::endl;
}
