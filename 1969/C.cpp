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
  int n, k;
  cin >> n >> k;
  vl a(n);
  rep(i, n) { cin >> a[i]; }

  vc<array<ll, 11>> coef(n);
  rep(i, n) rep(j, 11) coef[i][j] = LNF;
  rep(i, n) {
    coef[i][0] = a[i];
    ll cur = a[i];
    for (int j = 1; i + j < n && j <= k; j++) {
      cur = min(cur, a[i + j]);
      coef[i][j] = cur * (j + 1);
    }
  }

  vc<array<ll, 11>> dp(n + 1);
  rep(i, 1, n + 1) rep(j, 11) dp[i][j] = LNF;

  rep(i, n) {
    for (int add = 0; add <= k; add++) {
      ll c = coef[i][add];
      for (int j = 0; j + add <= k; j++) {
        if (i + add + 1 <= n)
          cmin(dp[i + add + 1][j + add], dp[i][j] + c);
      }
    }
  }

  cout << dp[n][k] << "\n";
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