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
  int start = 50;
  int pass = 0;
  while (std::getline(file, s)) {
    Step st;
    st.dir = s[0];
    st.dist = std::stoi(s.substr(1));
    steps.push_back(st);
  }
  for (auto& st : steps) {
    std::cout << st.dir << st.dist << "\n";
    if (st.dir == 'L') {
      start = (start - st.dist + 100) % 100;
    } else {
      start = (start + st.dist) % 100;
    }
    if (start == 0)
      pass++;
  }
  std::cout << pass << std::endl;
}
