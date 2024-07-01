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
  int N; cin >> N;
  vi A(N); for (auto &a : A) cin >> a, --a;

  vc<vi> dp(N+1, vi(N+1, INF));

  for (int i = N-1; i >= 0; i--) {
    for (int j = i+1; j < N; j += 2) {
      // debug(i, j);
      if (A[i] <= i && (i-A[i])%2 == 0) {
        int mov = (i-A[i])/2;
        if (dp[i+1][j-1] <= mov || j-i == 1) {
          dp[i][j] = mov;
        }
      }
      for (int k = i+1; k <= j; k += 2) {
        int x = dp[i][k];
        int y = dp[k+1][j];
        y -= (k-i+1)/2;
        cmin(dp[i][j], max(x, y));
      }
    }
  }

  vi ANS(N+1);
  rep(i, N) {
    cmax(ANS[i+1], ANS[i]);
    rep(j, i+1, N) {
      if (ANS[i] >= dp[i][j]) {
        cmax(ANS[j+1], ANS[i]+(j-i+1)/2);
      }
    }
  }
  cout << ANS[N] << "\n";
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