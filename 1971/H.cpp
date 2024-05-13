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

using namespace std;
struct kosaraju {
  int n, c;
  vector<vector<int>> e1, e2;
  vector<bool> vis;
  kosaraju(vector<vector<int>> &e) {
    n = (int)e.size();
    e1 = e, e2.resize(n);
    rep(u, 0, n) for (auto v : e[u]) e2[v].emplace_back(u);
    vis.resize(n);
    scc.resize(n, -1);
    rep(i, 0, n) if (!vis[i]) dfs1(i);
    c = 0;
    for (auto i : r | views::reverse)
      if (scc[i] == -1)
        dfs2(i), c++;
  }
  vector<int> r;
  void dfs1(int u) {
    vis[u] = true;
    for (auto v : e1[u])
      if (!vis[v])
        dfs1(v);
    r.emplace_back(u);
  }
  vector<int> scc;
  void dfs2(int u) {
    scc[u] = c;
    for (auto v : e2[u])
      if (scc[v] == -1)
        dfs2(v);
  }
  const int &operator[](const int &x) { return scc[x]; }
};

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int n, m;
//   cin >> n >> m;
//   vector<vector<int>> e(2 * n);
//   while (m--) {
//     int i, a, j, b;
//     cin >> i >> a >> j >> b;
//     --i;
//     --j;
//     e[i * 2 + !a].push_back(j * 2 + b);
//     e[j * 2 + !b].push_back(i * 2 + a);
//   }
//   kosaraju k(e);
//   vector<int> ans;
//   for (int i = 0; i < n; i++)
//     if (k[i * 2] == k[i * 2 + 1]) {
//       cout << "IMPOSSIBLE\n";
//       return 0;
//     }
//   cout << "POSSIBLE\n";
//   for (int i = 0; i < n; i++)
//     cout << int(k[i * 2] < k[i * 2 + 1]) << " \n"[i + 1 == n];
// }
void solve() {
  int n;
  cin >> n;
  vc<vi> g(3, vi(n));
  rep(i, 3) {
    rep(j, n) {
      cin >> g[i][j];
    }
  }
  vi neg(n);
  rep(i, n) neg[i] = i;
  vi pos(n);
  rep(i, n) pos[i] = i + n;

  vc<vi> e(n * 2);
  rep(j, n) {
    int a = g[0][j];
    int b = g[1][j];
    int c = g[2][j];
    vi cur;
    for (auto x : {a, b, c}) {
      int f = 1;
      if (x < 0) {
        x = -x;
        f = -1;
      }
      x--;
      if (f == -1) {
        cur.pb(neg[x]); // a[x]=-1
      } else {
        cur.pb(pos[x]); // a[x]=1
      }
    }
    auto trans = [&](int i) {
      if (i >= n) {
        return i - n;
      } else {
        return i + n;
      }
    };

    rep(i, 3) {
      rep(j, i + 1, 3) {
        int x = cur[i];
        int y = cur[j];
        e[trans(x)].pb(y);
        e[trans(y)].pb(x);
      }
    }
  }

  kosaraju k(e);
  bool ok = true;
  rep(i, n) {
    if (k[i] == k[i + n]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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