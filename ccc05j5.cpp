#include <bits/stdc++.h>

using namespace std;

bool isMonkeyWord(string word) {
  if (word.size() == 0) return false;
  if (word.compare("A") == 0) {
    return true;
  }
  if (word[0] == 'A' && word[1] == 'N') {
    return isMonkeyWord(word.substr(2));
  }
  if (word[0] == 'N') {
    return isMonkeyWord(word.substr(1));
  }
  if (word[0] == 'B') {
    int numB{}, numS{}, i{};
    for (i = 0; i < word.size(); i++) {
      if (word[i] == 'B') numB++;
      else if (word[i] == 'S') numS++;
      if (numB == numS) break;
    }
    if (numB != numS) return false;
    if (i == word.size()-1) {
      return isMonkeyWord(word.substr(1, word.size()-2));
    }
    return isMonkeyWord(word.substr(1, i-1)) && isMonkeyWord(word.substr(i+1));
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string word;
  // word = "BANANASNBANAS";
  cin >> word;
  while (word.compare("X") != 0) {
    if (isMonkeyWord(word)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    cin >> word;
  }
  // cout << isMonkeyWord(word) << '\n';
  return 0;
}