#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, x;
  
  cin >> t;
  for (int j = 0; j < t; j++) {
    cin >> n;
    stack <int> mountainTop, branch;
    for (int i = 0; i < n; i++) {
      cin >> x;
      mountainTop.push(x);
    }


    int i = 1;
    while (mountainTop.size() > 0) {
      if (mountainTop.top() == i) {
        mountainTop.pop();
        i++;
      } else if (branch.size() > 0 && branch.top() == i) {
        branch.pop();
        i++;
      } else {
        branch.push(mountainTop.top());
        mountainTop.pop();
      }
    }

    while (branch.size() > 0 && branch.top() == i) {
      branch.pop();
      i++;
    }

    if (i - 1 == n) {
      cout << 'Y' << '\n';
    } else {
      cout << 'N' << '\n';
    }

  }

  return 0;
}