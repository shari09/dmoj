#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)

using namespace std;

bool isSubstr(string &n, int &lenN, string &h, int &lenH) {
  fi(i, 0, lenH-lenN+1) {
    if (n.compare(h.substr(i, lenN)) == 0) {
      return true;
    }
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string n, h;
  cin >> n >> h;
  string other = n;
  int lenN = n.length();
  int lenH = h.length();

  if (lenN > lenH) cout << 0 << '\n';
  else {
    int num{0};
    do {
      if (isSubstr(n, lenN, h, lenH)) num++;
    } while (next_permutation(n.begin(), n.end()));

    while (prev_permutation(other.begin(), other.end())) {
      if (isSubstr(other, lenN, h, lenH)) num++;
    }

    cout << num << '\n';
  }
  
  return 0;
}
