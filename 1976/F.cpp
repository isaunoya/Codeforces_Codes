#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define debug(...) 42
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
template <typename T> using vc = vector<T>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

#include <atcoder/lazysegtree>

struct HLD {
  HLD() {}
  vector<vector<int>> G;
  int n;
  vector<int> dfn, sz, son, top, d, fa;
  int idx;
  void dfs(int u, int p) {
    sz[u] = 1;
    for (auto v : G[u])
      if (v != p) {
        fa[v] = u;
        d[v] = d[u] + 1;
        dfs(v, u), sz[u] += sz[v];
        if (son[u] == -1 || sz[v] > sz[son[u]])
          son[u] = v;
      }
  }
  void dfs2(int u, int t) {
    top[u] = t, dfn[u] = idx++;
    // debug(u, t, dfn[u]);
    if (son[u] != -1)
      dfs2(son[u], t);
    for (auto v : G[u])
      if (top[v] == -1)
        dfs2(v, v);
  }
  HLD(const vector<vector<int>> &g, const int &root = 0) {
    n = g.size();
    G = g;
    sz.resize(n);
    dfn.resize(n);
    son.resize(n, -1);
    top.resize(n, -1);
    d.resize(n);
    fa.resize(n);
    dfs(root, -1), idx = 0, dfs2(root, root);
  }
  int lca(int x, int y) {
    while (top[x] != top[y]) {
      if (d[top[x]] < d[top[y]])
        swap(x, y);
      x = fa[top[x]];
    }
    return d[x] < d[y] ? x : y;
  }
  vector<pair<int, int>> chain(int x, int y) {
    assert(0 <= x && x < n);
    assert(0 <= y && y < n);
    vector<pair<int, int>> L, R;
    while (top[x] != top[y]) {
      assert(0 <= x && x < n);
      assert(0 <= y && y < n);
      if (d[top[x]] > d[top[y]]) {
        L.emplace_back(dfn[x], dfn[top[x]]);
        x = fa[top[x]];
      } else {
        R.emplace_back(dfn[top[y]], dfn[y]);
        y = fa[top[y]];
      }
    }
    L.emplace_back(dfn[x], dfn[y]);
    reverse(R.begin(), R.end());
    L.insert(L.end(), R.begin(), R.end());
    return L;
  }

  int distance(int x, int y) { return d[x] + d[y] - 2 * d[lca(x, y)]; }
};
using S = pair<int, int>;
using F = int;

S e() { return {0, 0}; }

S op(S a, S b) { return max(a, b); }
S mapping(F add, S a) { return {a.first + add, a.second}; }

F composition(F a, F b) { return a + b; }

F id() { return 0; }

void solve() {
  int n;
  cin >> n;
  vc<vi> g(n);
  rep(n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }

  HLD hld(g);
  auto dfn = hld.dfn;
  auto sz = hld.sz;
  auto d = hld.d;
  auto fa = hld.fa;

  vc<pii> a(n);
  rep(i, n) a[dfn[i]] = {d[i], i};

  using namespace atcoder;
  lazy_segtree<S, op, e, F, mapping, composition, id> st(a);

  vi vis(n);
  vis[0] = 1;
  int ans = n - 1;
  for (int k = 1; k <= n - 1; k++) {
    int cnt = 1 + (k > 1);
    while (cnt--) {
      auto [mx, x] = st.all_prod();
      while (!vis[x]) {
        st.apply(dfn[x], dfn[x] + sz[x], -1);
        vis[x] = 1;
        ans--;
        x = fa[x];
      }
    }
    cout << ans << " \n"[k + 1 == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}