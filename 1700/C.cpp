/*
 * c.cpp
 * 2022-06-24 22:44:10
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long p = a[0];
    long long ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] < a[i + 1]) {
        ans += a[i + 1] - a[i];
      } else {
        ans += a[i] - a[i + 1];
        p -= a[i] - a[i + 1];
      }
    }
    ans += abs(p);
    cout << ans << "\n";
  }
  return 0;
}