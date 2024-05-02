#include <bits/stdc++.h>
using namespace std;
vector<int> getZ(const string &s) { // s[:Z[i]] = s[i:i+Z[i]]
  vector<int> Z(s.size());
  int N = s.size();
  Z[0] = N;
  for (int i = 1, l = 0, r = 0; i < N; i++) {
    if (i < r) {
      Z[i] = min(Z[i - l], r - i);
    }
    while (i + Z[i] < N && s[i + Z[i]] == s[Z[i]]) {
      Z[i] += 1;
    }
    if (i + Z[i] > r) {
      r = i + Z[i];
      l = i;
    }
  }
  return Z;
}
const int INF = -1e9;
void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  string s;
  cin >> s;
  auto Z = getZ(s);
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; i++)
    pos[Z[i]].push_back(i);
  set<int> st = {n};

  vector<int> ans(n + 1, 0);
  for (int len = n; len; len--) {
    for (int x : pos[len])
      st.emplace(x);
    int i = 0, j = 0;
    while (i < n) {
      i = *st.lower_bound(i);
      if (i == n)
        break;
      ++j;
      i += len;
    }
    ans[j] = max(ans[j], len);
  }
  for (int i = n - 1; i >= 0; i--)
    ans[i] = max(ans[i], ans[i + 1]);
  for (int i = l; i <= r; i++)
    cout << ans[i] << " \n"[i == r];
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