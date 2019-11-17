#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, shiftySum;

  cin >> n >> k;

  shiftySum = n;
  for (int i = 0; i < k; i++) {
    n *= 10;
    shiftySum += n;
  }
  cout << shiftySum << '\n';
  return 0;
}
