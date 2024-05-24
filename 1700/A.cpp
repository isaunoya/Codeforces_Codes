/*
 * a.cpp
 * 2022-06-24 22:37:30
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
      ans += i;
    }
    for (int j = 2; j <= n; j++) {
      ans += j * m;
    }
    cout << ans << "\n";
  }
  return 0;
}