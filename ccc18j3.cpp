#include <bits/stdc++.h>

using namespace std;

int main() {
  int distances[5];
  distances[0] = 0;

  int distance{0};
  int totalDistance{0};

  for (int i = 0; i < 4; i++) {
    cin >> distance;
    totalDistance += distance;
    distances[i+1] = totalDistance;
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << abs(distances[i] - distances[j]) << ' ';
    }
    cout << '\n';
  }
  return 0;
}
