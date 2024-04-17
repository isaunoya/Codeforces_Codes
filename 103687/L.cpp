#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int j = 0, ans = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    while (j < n && sum >= 1ll * a[j] * (i + 1)) {
      j++;
    }
    ans = max(ans, i - j + 1);
  }
  cout << ans << "\n";
}