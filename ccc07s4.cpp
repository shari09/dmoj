#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vi slides[n+1]{};
  int numPaths[n+1]{};

  int x, y;
  cin >> x >> y;
  while (x != 0) {
    slides[y].push_back(x);
    cin >> x >> y;
  }

  numPaths[n] = 1;

  for (int i = n; i > 0; i--) {
    for (int num : slides[i]) {
      numPaths[num] += numPaths[i];
    }
  }

  cout << numPaths[1] << '\n';
  return 0;
}