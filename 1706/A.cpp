/*
 * a.cc
 * 2022-07-18 22:37:32
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] = min(a[i], m + 1 - a[i]);
    vector<char> s(m + 1, 'B');
    for (int i = 0; i < n; i++) if (s[a[i]] == 'B') s[a[i]] = 'A'; else s[m + 1 - a[i]] = 'A';
    for (int i = 1; i <= m; i++) cout << s[i]; cout << "\n";
  }
  return 0;
}