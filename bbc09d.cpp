#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, temp{};
    long long total{};
    vi tasks{};
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> temp;
      tasks.push_back(temp);
    }

    sort(tasks.begin(), tasks.end());
    for (int i = 0; i < ceil(n/2.0); i++) {
      total += tasks[i] * tasks[n-i-1];
      total %= 10007;
    }
    cout << total << '\n';
    return 0;
}
