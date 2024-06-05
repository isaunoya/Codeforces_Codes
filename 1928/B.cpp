#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"  // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  
  int j = 0;
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    while (j < a.size() && a[j] - a[i] < n) {
      j++;
    }
    ans = max(ans, j - i);
  }
  
  cout << ans << "\n";
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