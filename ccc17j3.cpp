#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x1, y1, x2, y2, numMoves;
  cin >> x1 >> y1 >> x2 >> y2 >> numMoves;
  int minMoves{abs(x2 - x1) + abs(y2 - y1)};
  int remainingMoves{numMoves - minMoves};
  if (remainingMoves % 2 == 0 && remainingMoves >= 0) {
    cout << 'Y' << '\n';
  } else {
    cout << 'N' << '\n';
  }
  return 0;
}
