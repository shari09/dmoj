#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int numEntries, num;
  char action;
  cin >> numEntries;

  int friends[numEntries]{};
  int waitTime[numEntries]{};
  char actions[numEntries]{};

  int totalWaitTimes[100]{};

  int receiveArr[100]{};
  bool replied[100]{};
  fill_n(replied, 100, true);

  //getting the wait times
  for (int i = 1; i <= numEntries; i++) {
    cin >> action >> num;
    if (action == 'W') {
      waitTime[i] = num + waitTime[i-1]-1;
    } else {
      waitTime[i] = waitTime[i-1] + 1;
      actions[i] = action;
      friends[i] = num;
    }
  }

  for (int i = 0; i <= numEntries; i++) {
    if (friends[i] != 0) {
      int friendNum = friends[i];
      if (actions[i] == 'R') {
        receiveArr[friendNum] = waitTime[i];
        replied[friendNum] = false;
      } else if (actions[i] == 'S') {
        replied[friendNum] = true;
        totalWaitTimes[friendNum] += waitTime[i] - receiveArr[friendNum];
      }
    }

  }

  for (int i = 0; i < 100; i++) {
    if (replied[i] && totalWaitTimes[i] != 0) {
      cout << i << ' ' << totalWaitTimes[i] << '\n';
    } else if (!replied[i]) {
      cout << i << ' ' << -1 << '\n';
    }
  }

  return 0;
}
