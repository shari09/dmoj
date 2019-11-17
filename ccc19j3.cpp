#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned int numLines{0};
  string line{};
  unsigned int count{1};

  cin >> numLines;

  for (unsigned int i = 0; i < numLines; i++) {
    cin >> line;
    for (unsigned int j = 0; j < line.length(); j++) {
      if (line[j] == line[j+1]) {
        count++;
      } else {
        cout << count << ' ' << line[j] << ' ';
        count = 1;
      }
    }
    cout << '\n';
  }

  return 0;
}
