#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif

void solve() {
  int n, x;
  cin >> n >> x;
  set<int> res;
  if (x == 1) {
    int w = n - x;
    for (int i = 1; i <= sqrt(w); i++) {
      if (w % i == 0) {
        for (int j : {i, w / i}) {
          if (j % 2 == 0) {
            int k = (j + 2) / 2;
            if (k >= x) {
              res.emplace(k);
            }
          }
        }
      }
    }
  } else {
    int w = n - x;
    for (int i = 1; i <= sqrt(w); i++) {
      if (w % i == 0) {
        for (int j : {i, w / i}) {
          if (j % 2 == 0) {
            int k = (j + 2) / 2;
            if (k >= x) {
              res.emplace(k);
            }
          }
        }
      }
    }
    w = n + x - 2;
    for (int i = 1; i <= sqrt(w); i++) {
      if (w % i == 0) {
        for (int j : {i, w / i}) {
          if (j % 2 == 0 && (w / j) >= 1) {
            int k = (j + 2) / 2;
            if (k >= x) {
              res.emplace(k);
            }
          }
        }
      }
    }
  }

  cout << (int)res.size() << "\n";
  // n = t(2k-2) + x, t >= 0
  // n = t(2k-2) + 2 - x, t >= 1
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}