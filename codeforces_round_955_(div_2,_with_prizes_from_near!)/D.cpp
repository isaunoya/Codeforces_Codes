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
  int N, M, K;
  cin >> N >> M >> K;
  vc<vi> A(N, vi(M));
  rep(i, N) rep(j, M) cin >> A[i][j];
  vc<vi> B(N, vi(M));
  rep(i, N) {
    string S;
    cin >> S;
    rep(j, M) B[i][j] = S[j] - '0';
  }
  vc<vi> SUM(N + 1, vi(M + 1));
  rep(i, N) rep(j, M) SUM[i + 1][j + 1] = B[i][j] ? 1 : -1;
  rep(i, N + 1) rep(j, M + 1) if (j + 1 <= M) SUM[i][j + 1] += SUM[i][j];
  rep(i, N + 1) rep(j, M + 1) if (i + 1 <= N) SUM[i + 1][j] += SUM[i][j];
  auto calc = [&](int a, int b, int c, int d) { //[a,c)*[b,d)
    return SUM[c][d] - SUM[a][d] - SUM[c][b] + SUM[a][b];
  };
  ll D = 0;
  rep(i, N) rep(j, M) {
    if (B[i][j])
      D += A[i][j];
    else
      D -= A[i][j];
  }
  ll g = 0;
  rep(i, N) rep(j, M) {
    if (i + K > N || j + K > M)
      break;
    g = gcd(g, abs(calc(i, j, i + K, j + K)));
  }
  if (D == 0) {
    cout << "YES\n";
  } else if (g && D % g == 0) {
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