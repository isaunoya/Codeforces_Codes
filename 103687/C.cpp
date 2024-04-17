#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    if (y >= x)
      ans++;
  }
  for (int i = 0; i < m; i++) {
    int y;
    cin >> y;
    if (y <= x)
      ans++;
  }
  cout << ans << "\n";
}