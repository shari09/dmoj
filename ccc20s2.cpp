#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)
#define pii pair<int, int>
#define vpi vector<pii>

using namespace std;

vpi findFactors(int num, int m, int n) {
  vpi allFactors{};
  fi (i, 1, num+1) {
    if (i > m) break;
    if (num/i > n) continue;

    if (num%i == 0) {
      allFactors.push_back({i, num/i});
    }
  }
  return allFactors;
}

bool visited[1000000]{};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  cin >> m >> n;
  int room[m][n]{};

  fi (i, 0, m) {
    fi (j, 0, n) {
      cin >> room[i][j];
    }
  }

  bool path{false};
  // bool visited[m][n]{};
  queue<pii> q;
  q.push({1, 1});
  // visited[0][0] = true;
  visited[room[0][0]] = true;

  pii cur;
  int row, col;
  vpi factors;
  while(!q.empty()) {
    cur = q.front();
    q.pop();

    row = cur.first;
    col = cur.second;
    // if (row == m && col == n) {
    //   path = true;
    //   break;
    // }

    factors = findFactors(room[row-1][col-1], m, n);
    fi (i, 0, factors.size()) {
      //pos not visited
      // if (!visited[factors[i].first-1][factors[i].second-1]) {
      //   visited[factors[i].first-1][factors[i].second-1] = true;
      //   q.push(factors[i]);
      // }
      if (!visited[room[factors[i].first-1][factors[i].second-1]]) {
        visited[room[factors[i].first-1][factors[i].second-1]] = true;
        q.push(factors[i]);
      } 
      
      if (factors[i].first == m && factors[i].second == n) {
        path = true;
        break;
      }
    }

  }

  if (path) cout << "yes" << '\n';
  else cout << "no" << '\n';
  

  return 0;
}