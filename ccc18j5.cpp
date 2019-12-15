#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi book[10001]{};
bool visited[10001]{false};

char allVisited(bool const (&visited)[10001], int pageNum) {
  for (int i = 1; i <= pageNum; i++) {
    if (!visited[i]) {
      return 'N';
    }
  }
  return 'Y';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int pageNum{};
  int numOptions, paths;

  cin >> pageNum;
  
  for (int i = 1; i <= pageNum; i++) {
    cin >> numOptions;
    for (int j = 0; j < numOptions; j++) {
      // cout << 0;
      cin >> paths;
      // cout << 1;
      book[i].push_back(paths);
      // cout << 2 << '\n';
    }
    // cout << "out" << '\n';
    // cout << i << ' ' << pageNum << '\n';
  }

  //bfs
  queue<vi> q;
  q.push({1, 1});
  visited[1] = true;
  int cur{}, dist{};
  int numPath{};
  bool found = false;
  

  while (!q.empty()) {
    cur = q.front()[0];
    dist = q.front()[1];
    q.pop();
    // cout << cur << '\n';

    if (book[cur].size() == 0 && !found) {
      found = true;
      numPath = dist;
    }

    for (int i = 0; i < book[cur].size(); i++) {
      if (!visited[book[cur][i]]) {
        q.push({book[cur][i], dist+1});
        visited[book[cur][i]] = true;
      }
    } 
  }

  cout << allVisited(visited, pageNum) << '\n';
  cout << numPath << '\n';

  return 0;
}
