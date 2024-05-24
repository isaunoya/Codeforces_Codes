/*
 * d.cc
 * 2022-07-04 23:42:32
*/
#include <bits/stdc++.h>
using namespace std;
int n, a[5005], f[5005], buc[5005];
const int inf = 1e9;
void sol() {
  cin >> n;
  memset(a, 0, n + 3 << 2);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n + 1; i++) {
    int val = -inf;
    for (int j = 1; j <= i; j++) buc[a[j]] = 0;
    int mx = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (j + 1 < i) {
        ++buc[a[j + 1]];
        mx = max(mx, buc[a[j + 1]]);
      }
      if (mx * 2 <= i - j - 1 && ((i ^ j) & 1) && (a[i] == a[j] || a[i] == 0 || a[j] == 0)) {
        val = max(val, f[j] + 1);
      }
    }
    f[i] = val;
  }
  cout << f[n + 1] - 1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    sol();
  }
  return 0;
}