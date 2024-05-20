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
  int m, X;
  cin >> m >> X;
  vi c(m), h(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> h[i];
  }

  int s = 0;
  rep(i, m) s += h[i];
  vl dp(s + 1, LNF);
  dp[0] = 0;
  rep(i, m) {
    int x = c[i];
    int y = h[i];
    for (int j = s; j >= y; j--) {
      cmin(dp[j], dp[j - y] + x);
    }
    for (int j = 0; j <= s; j++) {
      if (dp[j] > 1ll * i * X) {
        dp[j] = LNF;
      }
    }
  }
  // debug(dp);
  ll ans = 0;
  for (int i = 0; i <= s; i++) {
    if (dp[i] < LNF) {
      cmax(ans, i);
    }
  }
  cout << ans << "\n";
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