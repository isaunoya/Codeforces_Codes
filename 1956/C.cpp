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

void solve() {
  int n;
  cin >> n;
  vc<vi> a(n, vi(n));
  vc<vi> ops;
  for (int k = n - 1; k >= 0; k--) {
    rep(w, 2) {
      vi op;
      op.emplace_back(w + 1);
      op.emplace_back(k + 1);
      rep(i, n) op.emplace_back(i + 1);
      if (w == 0)
        rep(i, n) a[k][i] = i + 1;
      else
        rep(i, n) a[i][k] = i + 1;
      ops.emplace_back(op);
    }
  }
  ll ans = 0;
  rep(i, n) rep(j, n) ans += a[i][j];
  cout << ans << " " << sz(ops) << "\n";
  for (auto op : ops) {
    for (auto i : op) {
      cout << i << " ";
    }
    cout << "\n";
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