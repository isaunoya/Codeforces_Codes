/*
 * c.cc
 * 2022-07-05 00:41:56
*/
#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      p[x] = i;
    }
    int mx = p[0], mn = p[0];
    long long ans = 1;
    for (int i = 1; i < n; i++) {
      if (mn < p[i] && p[i] < mx) {
        ans = ans * (mx - mn + 1 - i) % P;
      } else {
        mx = max(mx, p[i]);
        mn = min(mn, p[i]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}