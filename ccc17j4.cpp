#include <bits/stdc++.h>

using namespace std;

void display(int const (&time)[4]) {
  for (int i = 0; i < 4; i++) {
    cout << time[i] << ' ';
  }
  cout << '\n';
}

void addHour(int (&time)[4]) {
  if (time[1] == 9) { // 9 to 10
    time[0] = 1;
    time[1] = 0;
  } else if (time[0] == 1 && time[1] == 2) {
    time[0] = 0;
    time[1] = 1;
  } else {
    time[1]++;
  }
}

void addMin(int (&time)[4]) {
  if (time[3] == 9 && time[2] != 5) {
    time[3] = 0;
    time[2]++;
  } else if (time[2] == 5 && time[3] == 9) {
    time[2] = 0;
    time[3] = 0;
  } else {
    time[3]++;
  }
}

bool isSpecial(int (&time)[4]) {
  if (time[3] - time[2] == time[2] - time[1]) {
    if (time[0] == 0) {
      return true;
    } else if (time[2] - time[1] == time[1] - time[0]) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int minPassed;
  int time[4]{1, 2, 0, 0};
  cin >> minPassed;

  int halfDays{minPassed/720};
  minPassed %= 720;
  int hours{minPassed/60};
  int min{minPassed%60};
  int numSpecial{0};


  int specialHalfDay{0};
  int timeHalfDay[4]{*time};

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 60; j++) {
      addMin(timeHalfDay);
      if (isSpecial(timeHalfDay)) {
        specialHalfDay++;
      }
    }
    addHour(timeHalfDay);
  }

  for (int i = 0; i < hours; i++) {
    for (int j = 0; j < 60; j++) {
      addMin(time);
      if (isSpecial(time)) {
        numSpecial++;
      }
    }
    addHour(time);
  }

  for (int i = 0; i < min; i++) {
    addMin(time);
    if (isSpecial(time)) {
      numSpecial++;
    }
  }
  numSpecial += specialHalfDay * halfDays;
  cout << numSpecial << '\n';
  // display(time);
  return 0;
}
