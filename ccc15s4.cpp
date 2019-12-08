#include <bits/stdc++.h>
#define vi vector<int>
#define vI vector<Island>
#define for(n, i, m) for (int n = i; n < m; n++)

using namespace std;

struct Island {
  int islandNum;
  int time;
  int rockHeight;
};

struct Route {
  int islandNum;
  int totalTime;
  int destroyedHeight;
  vi visited;
};

struct CompareTime {
  bool operator() (Route const& a, Route const& b) {
    return a.totalTime > b.totalTime;
  }
};

vI islands[2001];
int height, numIslands, numRoutes;

int solve(int start, int end) {
  priority_queue<Route, vector<Route>, CompareTime> allRoutes;
  Route route;
  int runNum{0};
  for (i, 0, islands[start].size()) {
    Island island = islands[start][i];
    route.islandNum = island.islandNum;
    route.totalTime = island.time;
    route.destroyedHeight = island.rockHeight;
    route.visited = {start};

    if (route.destroyedHeight < height) {
      allRoutes.push(route);
    }
  }


  Route curRoute;
  Island curIsland;
  while(!allRoutes.empty()) {
    curRoute = allRoutes.top();
    allRoutes.pop();

    if (curRoute.islandNum == end) {
      cout << runNum << '\n';
      return curRoute.totalTime;
    }

    //going through all the neighbours of that node
    
    for (i, 0, islands[curRoute.islandNum].size()) {
       curIsland = islands[curRoute.islandNum][i];

      //if it's not visited
      
      if (find(curRoute.visited.begin(), curRoute.visited.end(), curIsland.islandNum) == curRoute.visited.end()) {
        route.islandNum = curIsland.islandNum;
        route.totalTime = curIsland.time+curRoute.totalTime;
        route.destroyedHeight = curIsland.rockHeight+curRoute.destroyedHeight;
        route.visited = curRoute.visited;
        route.visited.push_back(curIsland.islandNum);

        //if the ship's not destroyed
        if (route.destroyedHeight < height) {
          allRoutes.push(route);
        }
      }
      
    }
    runNum++;

  }
  cout << runNum << '\n';
  return -1;
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

  cout << minTime << '\n';

  return 0;
}