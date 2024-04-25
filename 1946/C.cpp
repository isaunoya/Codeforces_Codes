#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
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

void solve() {
  int n, k;
  cin >> n >> k;
  vc<vi> g(n);
  rep(i, n - 1) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].pb(y);
    g[y].pb(x);
  }
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int comp = 0;
    auto dfs = [&](auto &&dfs, int u, int p) -> int {
      int sz = 1;
      for (auto v : g[u]) if (v != p) {
        sz += dfs(dfs, v, u);
      }
      if (sz >= m) {
        comp++;
        return 0;
      } else {
        return sz;
      }
    };
    dfs(dfs, 0, -1);
    if (comp >= k + 1) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << "\n";
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