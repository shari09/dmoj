#include <bits/stdc++.h>
#define fi(n, i, m) for(int n = i; n < m; n++)

using namespace std;

set<int> primes;

bool isPrime(int num) {
  for (auto it = primes.begin(); it != primes.end(); it++) {
    if (num % *it == 0 && *it != num) {
      return false;
    }
  }
  return true;
}

void addPrime(int start, int end) {
  fi (i, start, end) {
    if (isPrime(i)) {
      primes.insert(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  primes.insert(2);
  primes.insert(3);

  int testCases, num;
  cin >> testCases;
  
  fi (i, 0, testCases) {
    cin >> num;
    if (*(primes.end()--) < num*2) {
      addPrime(*(primes.end()--), num*2);
    }

    for (auto it = primes.begin(); it != primes.end(); it++) {
      // if (*it > num*2) break;
      if (primes.count(num*2 - *it) != 0) {
        cout << *it << ' ' << num*2 - *it << '\n';
        break;
      }  
    }
  }
  return 0;
}

