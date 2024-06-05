#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif

void solve() {
  int n, b, x;
  cin >> n >> b >> x;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());

  vector<int> d = c;
  d.resize(unique(d.begin(), d.end()) - d.begin());

  long long res = 0;

  auto get = [&](int k) {
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] <= k) {
        cur += 1ll * c[i] * (c[i] - 1) / 2;
      } else {
        cur += 1ll * c[i] * (c[i] - 1) / 2;
        int per = c[i] / k;
        int rem = c[i] % k;
        cur -= 1ll * (k - rem) * per * (per - 1) / 2;
        cur -= 1ll * rem * (per + 1) * per / 2;
      }
    }
    return cur * b - 1ll * (k - 1) * x;
  };

  int l = 0, r = 2e5 + 1;
  while (r - l > 1) {
    int m1 = (l + r) / 2;
    int m2 = m1 + 1;
    long long g1 = get(m1);
    long long g2 = get(m2);
    res = max(res, g1);
    res = max(res, g2);
    if (g1 < g2) {
      l = m2;
    } else {
      r = m1;
    }
  }
  cout << res << "\n";
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