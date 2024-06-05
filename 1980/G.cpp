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

const int N = 2e5 + 5;
struct trie {
  int ch[N * 40][2], cnt, sz[N * 40];
  void init() {
    for (int i = 1; i <= cnt; i++) {
      ch[i][0] = ch[i][1] = 0;
      sz[i] = 0;
    }
    cnt = 1;
  }

  void add(int x, int v) {
    int p = 1;
    for (int i = 30; i >= 0; i--) {
      int c = x >> i & 1;
      if (!ch[p][c]) {
        ch[p][c] = ++cnt;
      }
      p = ch[p][c];
      sz[p] += v;
    }
  }

  int query(int x) {
    int p = 1;
    int res = 0;
    for (int i = 30; i >= 0; i--) {
      int c = (x >> i & 1) ^ 1;
      if (sz[ch[p][c]]) {
        res |= 1 << i;
      } else {
        c ^= 1;
      }
      p = ch[p][c];
    }
    return res;
  }
} a[2];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vc<pii>> e(n);
  int A = 0;
  rep(i, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    e[a].pb(b, c);
    e[b].pb(a, c);
  }
  a[0].init();
  a[1].init();

  vi d(n);
  vi X(n);
  auto dfs = [&](auto &dfs, int u, int p) -> void {
    a[d[u]].add(X[u], 1);
    for (auto [v, w] : e[u]) {
      if (v != p) {
        d[v] = d[u] ^ 1;
        X[v] = X[u] ^ w;
        dfs(dfs, v, u);
      }
    }
  };

  dfs(dfs, 0, -1);

  rep(i, m) {
    char c;
    cin >> c;
    if (c == '^') {
      int y;
      cin >> y;
      A ^= y;
    } else {
      int v, x;
      cin >> v >> x;
      --v;
      int ans = 0;
      a[d[v]].add(X[v], -1);
      cmax(ans, a[d[v]].query(X[v] ^ x));
      cmax(ans, a[d[v] ^ 1].query(X[v] ^ x ^ A));
      a[d[v]].add(X[v], 1);
      cout << ans << " \n"[i + 1 == m];
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