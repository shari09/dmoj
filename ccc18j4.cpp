#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;



void display(vvi &garden, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << garden[i][j] << ' ';
    }
    cout << '\n';
  }
}


vvi reflectHorizontally(vvi garden, int n) {
  int temp{};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < floor(n/2); j++) {
      temp = garden[i][j];
      garden[i][j] = garden[i][n-j-1];
      garden[i][n-j-1] = temp;
    }
  }
  return garden;
}

vvi reflectDiagonally(vvi garden, int n) {
  int temp{};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      temp = garden[i][j];
      garden[i][j] = garden[j][i];
      garden[j][i] = temp;
    }
  }
  return garden;
}

bool isCorrect(vvi &garden, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-1; j++) {
      if (garden[i][j] > garden[i][j+1]) {
        return false;
      } else if (garden[i][j] > garden[i+1][j]) {
        return false;
      }
    }
  }
  return true;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n{0};
  int temp{0};
  vvi garden{};

  cin >> n;

  for (int i = 0; i < n; i++) {
    vi row{};
    for (int j = 0; j < n; j++) {

      cin >> temp;
      row.push_back(temp);
    }
    garden.push_back(row);
  }

  bool correct = isCorrect(garden, n);
  while (!correct) {
    garden = reflectDiagonally(garden, n);
    garden = reflectHorizontally(garden, n);
    correct = isCorrect(garden, n);
  }
  display(garden, n);

  return 0;
}
