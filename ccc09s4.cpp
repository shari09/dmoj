#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)
#define pii pair<int, int>

using namespace std;


int world[5001][5001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int numCity, numRoutes;
  cin >> numCity >> numRoutes;

  
  memset(world, 0x3f3f3f3f, sizeof(world));

  int x, y, cost;
  fi (i, 0, numRoutes) {
    cin >> x >> y >> cost;
    world[x][y] = cost;
    world[y][x] = cost;
  }
  int numStore, pencilCity, price;
  cin >> numStore;
  int pencilPrices[numCity+1];
  
  memset(pencilPrices, 0x3f3f3f3f, sizeof(pencilPrices));

  fi (i, 0, numStore) {
    cin >> pencilCity >> price;
    pencilPrices[pencilCity] = price;
  }

  int bestPrice = 0x3f3f3f3f;
  int destination;
  cin >> destination;

  int dist[numCity+1];
  memset(dist, 0x3f3f3f3f, sizeof(dist));
  dist[destination] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, destination});

  int cur{-1};
  bool visited[numCity+1]{};
  while (!q.empty()) {
    cur = q.top().second;
    q.pop();
    visited[cur] = true;
    if (dist[cur] > bestPrice) {
      break;
    }
    bestPrice = min(pencilPrices[cur] + dist[cur], bestPrice);
    fi (i, 1, numCity+1) {
      if (world[cur][i] < 0x3f3f3f3f && !visited[i]) {
        if (world[cur][i] + dist[cur] < dist[i]) {
          dist[i] = world[cur][i] + dist[cur];
          q.push({dist[i], i});
        }
      }
    }
  }

  cout << bestPrice << '\n';
  return 0;
}