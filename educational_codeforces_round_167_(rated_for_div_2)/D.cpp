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

int mn[1000001];
int dp[1000001];
void solve() {
  int n, m;
  cin >> n >> m;
  vl a(n);
  rep(i, n) cin >> a[i];
  vl b(n);
  rep(i, n) cin >> b[i];
  vl c(m);
  rep(i, m) cin >> c[i];

  for (int i = 0; i <= 1000000; i++) {
    mn[i] = INF;
  }
  rep(n) cmin(mn[a[i]], a[i] - b[i]);
  for (int i = 1; i <= 1000000; i++) {
    cmin(mn[i], mn[i - 1]);
  }

  for (int i = 1; i <= 1000000; i++) {
    if (i - mn[i] >= 0)
      cmax(dp[i], dp[i - mn[i]] + 2);
  }

  ll ans = 0;
  rep(i, m) {
    int cur = c[i];
    if (cur <= 1000000) {
      ans += dp[cur];
    } else {
      ll res = (cur - 1000000) / mn[1000000];
      ans += res * 2;
      cur -= res * mn[1000000];
      ans += dp[cur];
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}