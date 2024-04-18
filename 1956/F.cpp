#include <bits/stdc++.h>

using i64 = long long;
struct DSU {
  std::vector<int> f, siz;

  DSU() {}
  DSU(int n) { init(n); }

  void init(int n) {
    f.resize(n);
    std::iota(f.begin(), f.end(), 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) { return find(x) == find(y); }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }

  int size(int x) { return siz[find(x)]; }
};
void solve() {
  int n;
  std::cin >> n;

  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> l[i] >> r[i];
  }

  std::vector<std::vector<int>> add(n), del(n);
  for (int i = 0; i < n; i++) {
    int L = std::max(0, i - r[i]);
    int R = i - l[i];
    if (L <= R) {
      add[L].push_back(i);
      del[R].push_back(i);
    }
    L = i + l[i];
    R = std::min(n - 1, i + r[i]);
    if (L <= R) {
      add[L].push_back(i);
      del[R].push_back(i);
    }
  }

  std::vector<int> cnt(n);
  std::vector<int> stk;
  DSU dsu(n);
  int cntl = 0, cntr = 0;
  for (int i = 0; i < n; i++) {
    for (auto j : add[i]) {
      cnt[dsu.find(j)]++;
      stk.push_back(dsu.find(j));
      cntl += (i < j);
      cntr += (i > j);
    }
    if (cntl > 0 && cntr > 0) {
      int x = -1;
      for (auto y : stk) {
        if (cnt[y] > 0) {
          cnt[y] = 0;
          if (x == -1) {
            x = y;
          } else {
            dsu.merge(x, y);
          }
        }
      }
      stk.clear();
      stk.push_back(x);
      cnt[x] = cntl + cntr;
    }
    for (auto j : del[i]) {
      cnt[dsu.find(j)]--;
      cntl -= (i < j);
      cntr -= (i > j);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dsu.find(i) == i;
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}