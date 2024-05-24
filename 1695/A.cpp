/*
 * a.cpp
 * 2022-06-18 22:37:50
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
    vector<vector<int>> a(n, vector<int>(m, 0));
    int mx = -2e9, x = -1, y = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] > mx) {
          mx = a[i][j];
          x = i;
          y = j;
        }
      }
    }
    cout << max(n - x, x + 1) * max(m - y, y + 1) << "\n";
  }
  return 0;
}