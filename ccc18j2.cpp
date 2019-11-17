#include <bits/stdc++.h>

using namespace std;

int main() {
  int length{};
  string yesterday{}, today{};
  int count{0};

  cin >> length >> yesterday >> today;
  for (int i = 0; i < length; i++) {
    if (yesterday[i] == today[i] && yesterday[i] == 'C') {
      count++;
    }
  }
  cout << count << '\n';
  return 0;
}
