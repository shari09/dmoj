#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int distance, numClubs;
  cin >> distance >> numClubs;

  int clubs[numClubs]{};
  for (int i = 0; i < numClubs; i++) {
    cin >> clubs[i];
  }


  int numStrokes[distance+1]{};
  
  for (int i = 0; i < distance+1; i++) {
    numStrokes[i] = -1;
  }
  numStrokes[distance] = 0;

  for (int i = distance; i >= 0; i--) {
    if (numStrokes[i] != -1) {
      for (int j = 0; j < numClubs; j++) {
        if (i-clubs[j] >= 0 && numStrokes[i-clubs[j]] == -1) {
          numStrokes[i-clubs[j]] = numStrokes[i]+1;
        }
      }
    }
  }

  if (numStrokes[0] == -1) cout << "Roberta acknowledges defeat." << '\n';
  else cout << "Roberta wins in " << numStrokes[0] << " strokes." << '\n';

  return 0;
}