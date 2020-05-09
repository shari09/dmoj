#include <bits/stdc++.h>
#define fi(i, n, m) for (int i = n; i < m; i++)

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  int scores[n]{};

  fi(i, 0, n) {
    cin >> scores[i];
  }

  sort(scores, scores+n);
  long long sum{};
  fi(i, 0, k) {
    sum += scores[i+n-k];
  }

  cout << sum << '\n';

  return 0;
}
