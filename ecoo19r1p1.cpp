#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int shirtNum, eventNum, numDays;
  for (int testcase = 0; testcase < 10; testcase++) {

    cin >> shirtNum >> eventNum >> numDays;
    int laundryTimes{0};
    int dirtyShirts{0};
    int eventDays[eventNum];
    int currentEventDay{0};

    for (int i = 0; i < eventNum; i++) {
      cin >> eventDays[i];
    }
    sort(eventDays, eventDays+eventNum);
    //display
    // for (int i = 0; i < eventNum; i++) {
    //   cout << eventDays[i] << ' ';
    // }
    // cout << '\n';

    //calculate
    for (int i = 1; i <= numDays; i++) {
      if (dirtyShirts == shirtNum) {
        // cout << shirtNum << ' ' << dirtyShirts << '\n';
        dirtyShirts = 0;
        laundryTimes++;
      }
      if (eventDays[currentEventDay] == i) {
        shirtNum++;
        if (currentEventDay < eventNum-1) currentEventDay++;
      }

      dirtyShirts++;
    }

    cout << laundryTimes << '\n';

  }

  return 0;
}
