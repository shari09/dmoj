//tle on first case
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi adjacencyList[100001]{};

int findMinDist(int start, int end) {
  queue<vi> q;
  vi node{};
  q.push({start, 0});
  bool visited[100001]{false};

  while (!q.empty()) {
    node = q.front();
    q.pop();
    if (node[0] == end) {
      return node[1];
    }

    for (auto num : adjacencyList[node[0]]) {
      if (!visited[num]) {
        visited[num] = true;
        q.push({num, node[1]+1});
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, q;
  int vertice1, vertice2;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> vertice1 >> vertice2;
    adjacencyList[vertice1].push_back(vertice2);
    adjacencyList[vertice2].push_back(vertice1);
  }

  int start, end;
  for (int i = 0; i < q; i++) {
    cin >> start >> end;
    cout << findMinDist(start, end) << '\n';
  }

  return 0;
}