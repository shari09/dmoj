#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void display(vvi subsets) {
  for (unsigned int i = 0; i < subsets.size(); i++) {
    for (unsigned int j = 0; j < subsets[i].size(); j++) {
      cout << subsets[i][j];
    }
    cout << '\n';
  }
}


vvi subArrays(vi nums, unsigned int k, vvi subsets, int index) {
  if (index == nums.size()) {
    return subsets;
  }
  vi subset{};
  for (int i = index; i < nums.size(); i++) {
    
  }

}

//wasn't subsets, just subarrays D:
// vvi generateSubsets(vi nums, unsigned int k) {
//   vvi subsets{};
//   for (unsigned int i = 0; i < pow(2, nums.size()); i++) {
//     vi subset{};
//     for (unsigned int j = 0; j < nums.size(); j++) {
//       if ((i & (1 << j)) > 0) {
//         //if (!(find(subset.begin(), subset.end(), nums[j]) != subset.end())) {
//           subset.push_back(nums[j]);
//         //}
//       }
//     }
//     if (subset.size() >= k) {
//       subsets.push_back(subset);
//     }
//   }
//   return subsets;
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vi nums {1, 2, 2, 2};
  vvi subsets = subArrays(nums, 2);
  display(subsets);
  cout << subsets.size() << '\n';

  return 0;
}
