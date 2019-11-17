#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

// void test(const int (&arr)[], int n) {
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << '\n';
//   }
//   cout << "COMPILEEEEE" << '\n';
// }

void test(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << *(arr+i) << '\n';
  }
}


int main() {
  int arr[10]{};
  // test(arr);
  test(arr, 10);
  return 0;
}
