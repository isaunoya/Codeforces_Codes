#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int a = 1; a * a <= n; a++) {
    for (int b = 1; b * b <= m; b++) {
      if (gcd(a, b) > 1) {
        continue;
      }
      ans += min(n / a / (a + b), m / b / (a + b));
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

/*

5
1 1
2 3
3 5
10 8
100 1233
*/