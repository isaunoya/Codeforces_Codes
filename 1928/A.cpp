#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif

void solve() {
  int a, b;
  cin >> a >> b;
  bool ok = false;
  if (b % 2 == 0) {
    int c = a * 2;
    int d = b / 2;
    if (minmax(a, b) != minmax(c, d)) {
      ok = true;
    }
  }
  if (a % 2 == 0) {
    int c = a / 2;
    int d = b * 2;
    if (minmax(a, b) != minmax(c, d)) {
      ok = true;
    }
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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