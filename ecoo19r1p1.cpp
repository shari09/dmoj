#include <bits/stdc++.h>
#define for(n, i, m) for(int n = i; n < m; n++)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int numShirts, numEvents, numDays, dirtyShirts, n;
  int temp;
  for (t, 0, 10) {

    cin >> numShirts >> numEvents >> numDays;
    int events[numDays+1]{};
    for (i, 0, numEvents) {
      cin >> temp;
      events[temp]++;
    }
    dirtyShirts = 0;
    n = 0;
    for(i, 1, numDays+1) {
      if (dirtyShirts == numShirts) {
        n++;
        dirtyShirts = 0;
      }
      numShirts += events[i];
      dirtyShirts++;
    }
    cout << n << '\n';
  }

  return 0;
}
