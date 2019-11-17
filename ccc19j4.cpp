#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int nums[4] = {1, 2, 3, 4};
  int temp{};
  string sequence{};


  cin >> sequence;
  for (unsigned int i = 0; i < sequence.length(); i++) {
    if (sequence[i] == 'H') {
      temp = nums[0];
      nums[0] = nums[2];
      nums[2] = temp;

      temp = nums[1];
      nums[1] = nums[3];
      nums[3] = temp;
    } else {
      temp = nums[0];
      nums[0] = nums[1];
      nums[1] = temp;

      temp = nums[2];
      nums[2] = nums[3];
      nums[3] = temp;
    }
  }

  cout << nums[0] << ' ' << nums[1] << '\n';
  cout << nums[2] << ' ' << nums[3] << '\n';

  return 0;
}
