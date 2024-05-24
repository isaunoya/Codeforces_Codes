/*
 * b.cpp
 * 2022-06-18 23:18:27
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n % 2 == 0) {
      int mn = *min_element(a.begin(), a.end());
      for (int i = 0; i < n; i++) {
        if (a[i] == mn) {
          if (i % 2 == 0) {
            cout << "Joe\n";
          } else {
            cout << "Mike\n";
          }
          break;
        }
      }
    } else {
      cout << "Mike\n";
    }
  }
  return 0;
}