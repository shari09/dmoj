#include <bits/stdc++.h>

using namespace std;
typedef vector<pair<int, int>> vpi;

bool win(int (&scores)[5], int team) {
  for (int i = 1; i < 5; i++) {
    if (i != team && scores[team] <= scores[i]) return false;
  }
  return true;
}


int solve(vpi matches, int (&scores)[5], int team, int index, int (&outcomes)[3][2]) {
  
  if (index == matches.size()) {
    if (win(scores, team)) return 1;
    return 0;
  }

  int winNum{0};
  for (int i = 0; i < 3; i++) {
    scores[matches[index].first] += outcomes[i][0];
    scores[matches[index].second] += outcomes[i][1];
    winNum += solve(matches, scores, team, index+1, outcomes);
    scores[matches[index].first] -= outcomes[i][0];
    scores[matches[index].second] -= outcomes[i][1];
  }
  return winNum;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int team, n;
  cin >> team >> n;

  int scores[5]{};

  bool gamesPlayed[5][5]{};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == j) gamesPlayed[i][j] = true;
      gamesPlayed[0][j] = true;
      gamesPlayed[i][0] = true;
    }
  }

  int a, b, sa, sb;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> sa >> sb;
    gamesPlayed[a][b] = true;
    gamesPlayed[b][a] = true;
    if (sa > sb) scores[a] += 3;
    else if (sa < sb) scores[b] += 3;
    else {
      scores[a]++;
      scores[b]++;
    }
  }

  vpi matches;
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < i+1; j++) {
      if (!gamesPlayed[i][j]) {
        matches.push_back({i, j});
      }
    }
  }
  int outcomes[3][2]{{3, 0}, {1, 1}, {0, 3}};

  cout << solve(matches, scores, team, 0, outcomes) << '\n';
  
  return 0;
}