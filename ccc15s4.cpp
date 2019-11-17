//to be completed later

#include <bits/stdc++.h>
#define vvIsland vector<vector<Island>>
#define vIsland vector<Island>
#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std;


class Island {
  public:
  int num, time, destruction, totalTime, hullHeight;
  vvi visited{};

  Island(){};
  Island(int n, int t, int d, int tt, int hh, vvi vis) {
    num = n;
    time = t;
    destruction = d;
    totalTime = tt;
    hullHeight = hh;
    visited = vis;
  }
};

void display(vvIsland const &islands) {
  for (int i = 0; i < islands.size(); i++) {
    cout << i << ": ";
    for (int j = 0; j < islands[i].size(); j++) {
      cout << islands[i][j].num << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

void display(vvi const &vector) {
  for (auto i: vector) {
    for (auto j: i) cout << j << ' ';
    cout << '\n';
  }
  cout << '\n';
}

vvi combine(vvi a, vvi b) {
  vvi res(a);
  res.insert(res.end(), b.begin(), b.end());
  return res;
}

bool visited(const vvi &cur, const Island &next) {
  for (int i = 0; i < cur.size(); i++) {
    if (cur[i][0] == next.num && cur[i][1] == next.time && cur[i][2] == next.destruction) {
      // cout << "true" << cur.size() << '\n';
      return true;
    }
  }
  return false;
}

int minTime(vvIsland const &islands, int hullHeight, int start, int end) {
  queue <Island> q;
  q.push(Island(start, 0, 0, 0, 0, {{start, 0, 0}}));
  
  Island pos;
  int bestTime = INT_MAX;
  bool found = false;
  bool possible = true;

  while (!q.empty()) {
    pos = q.front();
    q.pop();

    while (pos.hullHeight >= hullHeight && q.size() > 0) {
      pos = q.front();
      q.pop();
      if (q.empty()) {
        possible = false;
      }
    }
    if (pos.num == 19) {
      cout << q.size() << '\n';
      display(pos.visited);
      int i;
      cin >> i;
    }
    // cout << pos.num << '\n';
    // cout << q.size() << '\n';
    if (possible) {
      if (pos.num == end && pos.hullHeight < hullHeight) {
        found = true;
        bestTime = min(pos.totalTime, bestTime);
        break;
      }
      
      for (int i = 0; i < islands[pos.num].size(); i++) {
        Island next = islands[pos.num][i];
        if (!visited(pos.visited, next)) {
          // cout << pos.num << next.num << '\n';
          q.push(Island(
            next.num,
            next.time,
            next.destruction,
            next.time + pos.totalTime,
            next.destruction + pos.hullHeight,
            combine(pos.visited, next.visited)
          ));
        }
      }
    }
    
  }
  if (found) return bestTime;
  else return -1;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int hullHeight, numIslands, numRoutes;
  int a, b, time, destruction;
  
  cin >> hullHeight >> numIslands >> numRoutes;
  vvIsland allIslands(numIslands+1, vIsland{});

  for (int i = 0; i < numRoutes; i++) {
    cin >> a >> b >> time >> destruction;
    allIslands[a].push_back(Island (b, time, destruction, 0, 0, {{b, time, destruction}}));
    allIslands[b].push_back(Island (a, time, destruction, 0, 0, {{a, time, destruction}}));
    // display(allIslands);
  }

  int start, end;
  cin >> start >> end;
  display(allIslands);
  cout << minTime(allIslands, hullHeight, start, end) << '\n';

  return 0;
}