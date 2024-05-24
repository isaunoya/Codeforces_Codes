/*
 * b.cc
 * 2022-07-18 22:45:57
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
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    vector<array<int, 2>> dp(n);
    for (int i = 0; i < n; i++) {
      dp[a[i]][i % 2] = dp[a[i]][(i + 1) % 2] + 1;
    }
    for (int i = 0; i < n; i++) {
      cout << max(dp[i][0], dp[i][1]) << " \n"[i + 1 == n];
    }
  }
  return 0;
}