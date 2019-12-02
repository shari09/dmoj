#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n{}, diff{};
  cin >> n >> diff;

  int elevation[n][n]{};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> elevation[i][j];
    }
  }

  int rConf[4] = {0, 0, 1, -1};
  int cConf[4] = {1, -1, 0, 0};

  bool solve = false;

  stack<pii> s;
  s.push({0, 0});
  bool visited[n][n]{};
  visited[0][0] = true;

  while (!s.empty()) {
    pii point = s.top();
    s.pop();
    int r = point.first;
    int c = point.second;
    if (r == n-1 && c == n-1) {
      solve = true;
      cout << "yes\n";
      break;
    }

    for (int i = 0; i < 4; i++) {
      r = r+rConf[i];
      c = c+cConf[i];

      if (!visited[r][c]
          && r>=0 && r<n && c>=0 && c<n
          && abs(elevation[r][c] - elevation[point.first][point.second]) <= diff) {
        visited[r][c] = true;
        s.push({r, c});
      }
    }
  }

  if (!solve) cout << "no\n";

  return 0;
}
