#include <bits/stdc++.h>
#define fi(i, n, m) for (int i = n; i < m; i++)


using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num;
  cin >> num;
  fi(i, 1, num+1) {
    if (i % 15 == 0) {
      cout << "fizzbuzz\n";
    } else if (i % 3 == 0) {
      cout << "fizz\n";
    } else if (i % 5 == 0) {
      cout << "buzz\n";
    } else {
      cout << i << '\n';
    }
  }


  return 0;
}