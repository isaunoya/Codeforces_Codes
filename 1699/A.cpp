/*
 * a.cc
 * 2022-07-04 22:37:21
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
    if (n % 2 == 0) {
      cout << n / 2 << " " << n / 2 << " " << 0 << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}