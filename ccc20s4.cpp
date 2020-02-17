#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)
#define psi pair<string, int>
#define vpi vector<pair<int, int>>

using namespace std;

bool isHappy(string arrangement) {
  set<char> used{};
  fi (i, 1, arrangement.length()) {
    if (arrangement[i] != arrangement[i-1]) {
      if (used.find(arrangement[i]) != used.end()) {
        if (i != arrangement.length()-1) return false;

        if (arrangement[i] == arrangement[0]) {
          return true;
        } else {
          return false;
        }
      }
      used.insert(arrangement[i-1]);
    }
  }
  return true;
}

vpi generateCombo(int len) {
  vpi combos{};
  fi (i, 0, len) {
    fi (j, i+1, len) {
      combos.push_back({i, j});
    }
  }
  return combos;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string arrangement;
  cin >> arrangement;

  vpi combos = generateCombo(arrangement.length());

  set<string> used;
  queue<psi> q;
  q.push({arrangement, 0});
  used.insert(arrangement);

  psi cur;
  char temp;
  while(!q.empty()) {
    cur = q.front();
    q.pop();

    cout << cur.first << '\n';
    if (isHappy(cur.first)) {
      cout << cur.second << '\n';
      break;
    }
    
    fi (i, 0, combos.size()) {
      temp = cur.first[combos[i].first];
      cur.first[combos[i].first] = cur.first[combos[i].second];
      cur.first[combos[i].second] = temp;

      if (used.find(cur.first) == used.end()) {
        used.insert(cur.first);
        q.push({cur.first, cur.second+1});
      }
      //swap back
      temp = cur.first[combos[i].first];
      cur.first[combos[i].first] = cur.first[combos[i].second];
      cur.first[combos[i].second] = temp;
    }
  }

  return 0;
}