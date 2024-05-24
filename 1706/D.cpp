/*
 * d.cc
 * 2022-07-18 23:02:12
 */
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int res = INF;
    for (int l = 0; l <= a[0]; l++) {
      int r = l;
      for (int i = 0; i < n; i++) {
        int L = a[i] / (l + 1) + 1, R = (l == 0) ? INF : a[i] / l;
        R = min(R, k);
        r = max(r, a[i] / R);
      }
      res = min(res, r - l);
    }
    cout << res << "\n";
  }
  return 0;
}