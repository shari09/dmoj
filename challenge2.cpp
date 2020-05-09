#include <bits/stdc++.h>
#define fi(i, n, m) for(int i = n; i < m; i++)
#define fd(i, n, m) for(int i = n; i > m; i--)

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int arr[n];

  fi(i, 0, n) {
    cin >> arr[i];
  }

  int maxCount{}, maxNum{}, count{};
  fd(i, n-1, -1) {
    if (arr[i] >= maxNum) {
      maxCount = max(maxCount, count);
      maxNum = arr[i];
      count = 0;
    } else {
      count++;
    }
  }
  maxCount = max(maxCount, count);

  cout << maxCount << '\n';


  return 0;
}