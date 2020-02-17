#include <bits/stdc++.h>

using namespace std;


int world[5001][5001];
int main() {
  // bool i[1600][3600]{};
  // i[600][2000] = true;
  // memset(i, 0, sizeof(i));

  set<string> test;
  string str = "abacabaa";
  string other = str;
  // char arr[3] = {'t', 'h', 'e'};
  do {
    // cout << str << '\n';
    if (test.find(str) != test.end()) cout << "SDF" << '\n';
    test.insert(str);
  } while (next_permutation(str.begin(), str.end()));

  while (prev_permutation(other.begin(), other.end())) {
    // cout << other << '\n';
    if (test.find(other) != test.end()) cout << "SDF" << '\n';
    test.insert(other);
  }

  return 0;
}
