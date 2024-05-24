/*
 * c.cc
 * 2022-07-18 22:50:43
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
      cin >> h[i];
    if (n % 2 == 1) {
      long long res = 0;
      for (int i = 1; i + 1 < n; i += 2) {
        if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) {
          res += max(h[i - 1], h[i + 1]) - h[i] + 1;
        }
      }
      cout << res << "\n";
    } else {
      long long od = 0;
      long long ev = 0;
      for (int i = 2; i + 1 < n; i += 2) {
        if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) {
          ev += max(h[i - 1], h[i + 1]) - h[i] + 1;
        }
      }
      long long res = ev;
      for (int i = 1; i + 1 < n; i += 1) {
        if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) {
          if (i % 2 == 1)
            od += max(h[i - 1], h[i + 1]) - h[i] + 1;
          if (i % 2 == 0)
            ev -= max(h[i - 1], h[i + 1]) - h[i] + 1;
        }
        if (i % 2 == 0)
          res = min(res, od + ev);
      }
      cout << res << "\n";
    }
  }
  return 0;
}