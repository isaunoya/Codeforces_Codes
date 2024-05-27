#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
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
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second

struct lowest_common_ancestor {
  vector<vector<int>> g;
  vector<int> dep;
  vector<int> dfn;
  vector<int> out;
  vector<int> fa;
  vector<vector<int>> f;
  int n;
  int Index;
  int LG;
  void dfs(int u) {
    dfn[u] = Index++;
    for (auto v : g[u]) {
      if (dfn[v] == -1) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
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
  int distance(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
  lowest_common_ancestor(const vector<vector<int>> &graph, int root = 0)
      : g(graph) {
    n = graph.size();
    dep.resize(n, 0);
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

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}

} // namespace internal

} // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
  segtree() : segtree(0) {}
  segtree(int n) : segtree(std::vector<S>(n, e())) {}
  segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1)
        sml = op(sml, d[l++]);
      if (r & 1)
        smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  template <bool (*f)(S)> int max_right(int l) {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F> int max_right(int l, F f) {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n)
      return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0)
        l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(S)> int min_left(int r) {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F> int min_left(int r, F f) {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0)
      return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2))
        r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

private:
  int _n, size, log;
  std::vector<S> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

} // namespace atcoder
int E() { return 0; }
int op(int x, int y) { return x + y; }

void solve() {
  int n, q;
  cin >> n >> q;
  vi c(n);
  rep(i, n) cin >> c[i];

  vc<vi> g(n);
  rep(i, n - 1) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  lowest_common_ancestor lca(g);
  using diam = array<int, 3>;
  diam e{-1, -1, -1};
  auto merge = [&](diam a, diam b) {
    if (a == e) {
      return b;
    }
    if (b == e) {
      return a;
    }
    auto c = max(a, b);
    rep(i, 1, 3) rep(j, 1, 3) {
      cmax(c, diam{lca.distance(a[i], b[j]), a[i], b[j]});
    }
    return c;
  };

  vc<diam> t(n * 2, e);
  auto modify = [&](int p, diam cur) {
    p += n;
    t[p] = cur;
    p /= 2;
    while (p) {
      t[p] = merge(t[p * 2], t[p * 2 + 1]);
      p /= 2;
    }
  };

  HLD hld(g);
  auto dfn = hld.dfn;
  atcoder::segtree<int, op, E> s(n);

  int cnt = 0;
  rep(i, n) if (c[i]) modify(i, diam{0, i, i}), cnt++, s.set(dfn[i], c[i]);

  while (q--) {
    int x;
    cin >> x;
    --x;
    cnt -= c[x];
    c[x] ^= 1;
    cnt += c[x];

    s.set(dfn[x], c[x]);
    if (c[x]) {
      modify(x, diam{0, x, x});
    } else {
      modify(x, e);
    }
    if (cnt == 0) {
      cout << "No\n";
      continue;
    }
    int X = t[1][1];
    int Y = t[1][2];
    auto path = hld.chain(X, Y);
    int cur = 0;
    for (auto [l, r] : path) {
      if (l > r) {
        swap(l, r);
      }
      cur += s.prod(l, r + 1);
    }
    if (t[1][0] + 1 == cnt && cnt == cur) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
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