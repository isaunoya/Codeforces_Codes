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
  int N;
  cin >> N;
  vl A(N);
  rep(N) cin >> A[i];

  vi p(N, -1);
  rep(i, 1, N) cin >> p[i], --p[i];

  ll ANS = 0;
  vector<vector<ll>> dp(N);

  for (int i = N - 1; i >= 0; i--) {
    if (dp[i].empty()) {
      dp[i].pb(LNF);
    }

    ll val = A[i];
    for (int v = 0; val > 0; v++) {
      ll delta = min(dp[i][v], val);
      ANS += delta * v;
      dp[i][v] -= delta;
      val -= delta;
    }
    dp[i].insert(dp[i].begin(), A[i]);
    dp[i].back() = LNF;

    int par = p[i];
    if (par == -1) {
      break;
    }

    if (dp[par].empty()) {
      swap(dp[par], dp[i]);
    } else {
      int new_len = min(sz(dp[par]), sz(dp[i]));
      dp[par].resize(new_len);
      for (int l = 0; l < new_len; l++) {
        dp[par][l] += dp[i][l];
      }
      cmin(dp[par].back(), LNF);
    }
  }
  cout << ANS << "\n";
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