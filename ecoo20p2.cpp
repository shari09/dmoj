#include <bits/stdc++.h>
#define fi(i, n, m) for(int i = n; i < m; i++)
#define vpi vector<pair<int, int>>
#define coolMap map<string, vector<pair<int, int>>>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, m, p, q, k, d, amount, itemsLeft;
  string s, s2;
  cin >> t;

  fi (qtt, 0, t) { //testcase
    cin >> n;
    coolMap stuff{};
    vpi shoppingList{};
    amount = 0;

    fi (stt, 0, n) { //stores
      cin >> m;
      fi (dtt, 0, m) { //items
        cin >> s >> p >> q;
        stuff[s].push_back({p, q});
      }
    }

    cin >> k;

    fi (ott, 0, k) {
      cin >> s2 >> d;
      shoppingList = stuff[s2];
      sort(shoppingList.begin(), shoppingList.end());
      fi (idk, 0, shoppingList.size()) {
        itemsLeft = min(d, shoppingList[idk].second);
        amount += shoppingList[idk].first*itemsLeft;
        d -= itemsLeft;
        if (d == 0) break;
      }
    }
    cout << amount << '\n';

  }

  return 0;
}