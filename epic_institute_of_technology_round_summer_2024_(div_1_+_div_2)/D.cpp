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
  vi A(N);
  rep(N) cin >> A[i];
  sort(all(A));

  vi t;
  for (int i = 0, j = 0; i < N; i = j) {
    j = i;
    while (j < N && A[i] == A[j]) {
      j += 1;
    }
    t.pb(j - i);
  }
  // debug(t);
  vi dp(N + 1, -INF);
  dp[0] = 0;
  rep(i, sz(t)) {
    int cur = t[i];
    vi ndp(N + 1, -INF);
    rep(j, N + 1 - cur) cmax(ndp[j], dp[j + cur] + 1);
    rep(j, N + 1 - cur) cmax(ndp[j + 1], dp[j]);
    dp.swap(ndp);
  }
  int ANS = 0;
  rep(i, N+1) cmax(ANS, dp[i]);
  cout << sz(t) - ANS << "\n";
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