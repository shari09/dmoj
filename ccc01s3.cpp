#include <bits/stdc++.h>
#define vi vector<int>
#define fi(n, i, m) for(int n = i; n < m; n++)
#define vs vector<string>

using namespace std;

vi roads[26]{};

bool exist(int a, int b) {
  queue<int> q;
  bool visited[26]{};
  q.push('A'-'A');
  visited['A'-'A'] = true;

  int cur;
  while(!q.empty()) {
    cur = q.front();
    q.pop();

    if (cur+'A' == 'B') {
      return true;
    }

    

    // cout << (char)(a+'A') << ' ' << (char)(b+'A') << '\n';
    
    fi (i, 0, roads[cur].size()) {
      if (!visited[roads[cur][i]]
          && ((cur != a && roads[cur][i] != b)
          || (cur != b && roads[cur][i] != a))) {
        visited[roads[cur][i]] = true;
        q.push(roads[cur][i]);
        if (a == 'C'-'A' && b == 'F'-'A') {
          cout << (char)(cur+'A') << ' ' << (char)(roads[cur][i]+'A') << '\n';
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  vs allRoads{};
  string cities{""};
  cin >> cities;
  while (cities.compare("**") != 0) {
    allRoads.push_back(cities);
    roads[cities[0]-'A'].push_back(cities[1]-'A');
    roads[cities[1]-'A'].push_back(cities[0]-'A');
    cin >> cities;
  }

  int numConnecting{0};
  fi (i, 0, allRoads.size()) {
    if (!exist(allRoads[i][0]-'A', allRoads[i][1]-'A')) {
      numConnecting++;
      cout << allRoads[i] << '\n';
    }
  }
  cout << numConnecting << '\n';
  
  return 0;
}