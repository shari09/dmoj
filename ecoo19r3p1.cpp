#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)
#define fd(n, i, m) for(int n = i; n > m; n--)

using namespace std;
int keys[1000000]{};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num;
  fi(t, 0, 10) {
    cin >> num;
    // memset(keys, 0, 1000000);

    fi(i, 0, num) {
      cin >> keys[i];
    }
    sort(keys, keys+num);

    int ans{0};
    fi(i, 0, num) {
      fi(j, i+1, num) {
        if(keys[j] % keys[i] == 0) {
          ans++;
        }
      }
    }
    cout << ans << '\n';

  }

  return 0;
}