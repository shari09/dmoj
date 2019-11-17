#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

bool isValid(const int (&arr)[10000], int n) {
  for (int i = 1; i < n; i++) {
    if ((arr[i] + arr[i-1]) % 3 == 0) {
      return false;
    }
  }
  return true;
}

void display(const int (&arr)[10000], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, temp;
  cin >> n;
  int arr[10000]{};

  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr[i] = temp;
  }
  sort(arr, arr+n);
  bool found{false};
  do {
    found = isValid(arr, n);
  } while (!found && next_permutation(arr, arr + n));

  if (found) display(arr, n);
  else cout << "impossible" << '\n';


  return 0;
}