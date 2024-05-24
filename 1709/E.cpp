/*
 * e.cc
 * 2022-07-22 10:33:00
*/
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
  
  vector<vector<int>> e(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  
  vector<int> sum(n);
  vector<set<int>> s(n);
  int ans = 0;
  
  auto dfs = [&](auto self, int u, int p) -> void {
    sum[u] ^= a[u];
    for (auto v : e[u]) {
      if (v != p) {
        sum[v] = sum[u];
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 0, -1);
  
  auto dfs2 = [&](auto self, int u, int p) -> void {
    bool ok = true;
    s[u].emplace(sum[u]);
    for (auto v : e[u]) {
      if (v != p) {
        self(self, v, u);
        if (ok == false) {
          continue;
        }
        if (s[u].size() < s[v].size()) {
          swap(s[u], s[v]);
        }
        for (auto x : s[v]) {
          if (s[u].count(x ^ a[u])) {
            ok = false;
            break;
          }
        }
        for (auto x : s[v]) {
          s[u].insert(x);
        }
        s[v].clear();
      }
    }
    if (ok == false) {
      s[u].clear();
      ++ans;
    }
  };
  dfs2(dfs2, 0, -1);
  
  cout << ans << "\n";
  return 0;
}