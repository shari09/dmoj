#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)
#define pii pair<int, int>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double maxSpeed{0};
  int t{};
  cin >> t;

  pii positions[t];

  int time, pos;
  fi (i, 0, t) {
    cin >> time >> pos;
    positions[i] = {time, pos};
  }

  sort(positions, positions+t);
  fi (i, 1, t) {
    maxSpeed = max(abs(positions[i].second-positions[i-1].second)/
                  (double)abs((positions[i].first-positions[i-1].first)), maxSpeed);
  }

  cout << maxSpeed << '\n';

  return 0;
}