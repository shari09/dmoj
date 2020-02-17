#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool h{false};
  bool v{false};

  string sequence;
  cin >> sequence;

  fi (i, 0, sequence.length()) {
    if (sequence[i] == 'H') {
      h = !h;
    } else {
      v = !v;
    }
  }

  if (h && v) {
    cout << "4 3\n2 1\n";
  } else if (h) {
    cout << "3 4\n1 2\n";
  } else if (v) {
    cout << "2 1\n4 3\n";
  } else {
    cout << "1 2\n3 4\n";
  }

  return 0;
}