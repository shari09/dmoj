#include <bits/stdc++.h>

using namespace std;

bool checkMagic(int const (&square)[4][4], int sum) {
  int rowSum{0};
  int colSum{0};
  for (int i = 0; i < 4; i++) {
    rowSum = 0;
    colSum = 0;
    for (int j = 0; j < 4; j++) {
      rowSum += square[i][j];
      colSum += square[j][i];
    }
    if (rowSum != sum || colSum != sum) {
      return false;
    }
  }
  return true;
}

int findSum(int const (&row)[4]) {
  int sum{};
  for (int i = 0; i < 4; i++) {
    sum += row[i];
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int square[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> square[i][j];
    }
  }
  int sum{findSum(square[0])};
  if (checkMagic(square, sum)) {
    cout << "magic" << '\n';
  } else {
    cout << "not magic" << '\n';
  }

  return 0;
}
