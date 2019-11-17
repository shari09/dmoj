#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi comparisons[1000001]{};

bool isTaller(int height, int target) {
  queue <int> q;
  q.push(height);
  while (!q.empty()) {
    height = q.front();
    q.pop();
    if (height == target) {
      return true;
    }
    for (int i = 0; i < comparisons[height].size(); i++) {
      q.push(comparisons[height][i]);
    }
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int numStudents, numCompared;
  int x, y;

  cin >> numStudents >> numCompared;

  for (int i = 0; i < numCompared; i++) {
    cin >> x >> y;
    comparisons[x].push_back(y);
  }

  cin >> x >> y;
  if (isTaller(x, y)) cout << "yes" << '\n';
  else if (isTaller(y, x)) cout << "no" << '\n';
  else cout << "unknown" << '\n';

  return 0;
}