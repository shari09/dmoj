#include <bits/stdc++.h>

using namespace std;


int world[5001][5001];
int main() {
  int count{0};
  for (int i = 0; i < 1000000; i++) {
    for (int j = i+1; j < 1000000; j++) {
      count++;
    }
  }
  cout << count << '\n';
  return 0;
}
