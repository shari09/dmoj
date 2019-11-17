#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned int numLines{0};
  unsigned int numChar{0};
  char character{};

  cin >> numLines;

  for (unsigned int i = 0; i < numLines; i++) {
    cin >> numChar >> character;
    for (unsigned int j = 0; j < numChar; j++) {
      cout << character;
    }
    cout << '\n';
  }
  return 0;
}
