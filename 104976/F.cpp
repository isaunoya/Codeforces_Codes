#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct lowest_common_ancestor {
  vector<vector<pair<int, int>>> g;
  vector<int> dep;
  vector<ll> len;
  vector<int> dfn;
  vector<int> out;
  vector<int> fa;
  vector<vector<int>> f;
  int n;
  int Index;
  int LG;
  void dfs(int u) {
    dfn[u] = Index++;
    for (auto [v, w] : g[u]) {
      if (dfn[v] == -1) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        len[v] = len[u] + w;
        dfs(v);
      }
    }
    out[u] = Index;
  }

  bool inside(int u, int x) { return dfn[x] <= dfn[u] && dfn[u] < out[x]; }
  int lca(int x, int y) {
    if (inside(x, y)) {
      return y;
    } else if (inside(y, x)) {
      return x;
    } else {
      for (int i = LG - 1, t; i >= 0; i--) {
        if (f[i][x] != -1 && !inside(y, t = f[i][x])) {
          x = t;
        }
      }
      return f[0][x];
    }
  }
  ll distance(int x, int y) { return len[x] + len[y] - 2 * len[lca(x, y)]; }
  lowest_common_ancestor(const vector<vector<pair<int, int>>> &graph,
                         int root = 0)
      : g(graph) {
    n = graph.size();
    dep.resize(n, 0);
    len.resize(n, 0);
    dfn.resize(n, -1);
    out.resize(n);
    fa.resize(n, -1);
    LG = __lg(n) + 1;
    f.resize(LG);
    Index = 0;
    dfs(root);
    f[0] = fa;
    for (int j = 1; j < LG; j++) {
      for (int i = 0; i < n; i++) {
        if (f[j - 1][i] == -1) {
          f[j].emplace_back(-1);
        } else {
          f[j].emplace_back(f[j - 1][f[j - 1][i]]);
        }
      }
    }
  }
  int operator()(int x, int y) { return lca(x, y); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  vector<int> ver(n, -1);
  for (int i = 0; i < n; i++) {
    if (w[i] < n) {
      ver[w[i]] = i;
    }
  }

  vector<vector<pair<int, int>>> g(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  lowest_common_ancestor lca(g);
  using diam = array<ll, 3>;
  auto merge = [&](diam a, diam b) {
    auto c = max(a, b);
    for (int i = 1; i < 3; i++) {
      for (int j = 1; j < 3; j++) {
        c = max(c, diam{lca.distance(a[i], b[j]), a[i], b[j]});
      }
    }
    return c;
  };
  int m = 0;
  vector<diam> d(n);
  while (m < n && ver[m] != -1) {
    int x = ver[m];
    if (m == 0)
      d[m] = diam{0, x, x};
    else
      d[m] = merge(d[m - 1], diam{0, x, x});
    m++;
  }

  while (q--) {
    int x;
    ll k;
    cin >> x >> k;
    --x;
    int l = -1, r = m;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      auto [rec, u, v] = d[mid];
      if (lca.distance(x, u) <= k && lca.distance(x, v) <= k) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << l + 1 << "\n";
  }
  return 0;
}