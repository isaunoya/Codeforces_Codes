/*
 * b.cc
 * 2022-07-04 22:38:09
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
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        if ((i >> 1 & 1) ^ (j >> 1 & 1)) {
          a[i][j] = a[i + 1][j + 1] = 1;
          a[i + 1][j] = a[i][j + 1] = 0;
        } else {
          a[i][j] = a[i + 1][j + 1] = 0;
          a[i + 1][j] = a[i][j + 1] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << " \n"[j + 1 == m];
      }
    }
  }
  return 0;
}