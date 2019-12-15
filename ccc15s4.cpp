#include <bits/stdc++.h>
#define vI vector<Island>
#define pii pair<int, int>
#define for(n, i, m) for (int n = i; n < m; n++)

using namespace std;

struct Island {
  int islandNum;
  int time;
  int rockHeight;
};

vI islands[2001];
int height, numIslands, numRoutes;


int solve(int start, int end) {
  int minDist[2001][201];
  memset(minDist, 0x3f3f3f3f, sizeof(minDist));
  bool visited[2001]{};

  priority_queue<pii, vector<pii>, greater<pii>> q;
  visited[start] = true;
  q.push({0, start});
  minDist[start][0] = 0;

  Island target;
  while (!q.empty()) {
    int cur = q.top().second;
    q.pop();
    visited[cur] = false;

    for (i, 0, islands[cur].size()) { //loop through adjacent islands
      target = islands[cur][i];
      for (j, 0, height-target.rockHeight) { //for every valid rock height
        int time = minDist[cur][j] + target.time; //time spent getting here + time need to reach new island
        if (time < minDist[target.islandNum][j+target.rockHeight]) {
          minDist[target.islandNum][j+target.rockHeight] = time;
          if (!visited[target.islandNum]) {
            visited[target.islandNum] = true;
            q.push({time, target.islandNum});
          }
        }
      }
    }

  }
  int shortest = 0x3f3f3f3f;
  for (i, 0, 201) {
    shortest = min(minDist[end][i], shortest);
  }
  return shortest;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  
  cin >> height >> numIslands >> numRoutes;
  
  int a, b, t, h;
  Island temp;

  for(i, 0, numRoutes) {
    cin >> a >> b >> t >> h;

    temp.islandNum = b;
    temp.time = t;
    temp.rockHeight = h;
    islands[a].push_back(temp);
    temp.islandNum = a;
    islands[b].push_back(temp);
  }

  int start, end;
  cin >> start >> end;

  int minTime = solve(start, end);

  if (minTime != 0x3f3f3f3f) cout << minTime << '\n';
  else cout << -1 << '\n';

  return 0;
}