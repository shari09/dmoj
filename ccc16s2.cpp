#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int problem{}, n{}, total{}, temp{};
  vector<int> d{}, p{};

  cin >> problem >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    d.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    cin >> temp;
    p.push_back(temp);
  }

  sort(d.begin(), d.end());
  sort(p.begin(), p.end());

  for (int i = 0; i < n; i++) {
    if (problem == 1) {
      total += max(d[i], p[i]);
    } else {
      total += max(d[i], p[n-i-1]);
    }
  }
  cout << total << '\n';


  return 0;
}
