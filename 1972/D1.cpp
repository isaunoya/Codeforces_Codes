#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int b = 1; b <= m; b++) {
    for (int a = b; a <= n; a += b) {
      if ((a + b) % (1ll * b * b) == 0) {
        ans++;
      }
    }
  }

  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}