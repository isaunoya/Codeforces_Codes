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
const int p10[] = {1, 10, 100, 1000, 10000};

void solve() {
  int n;
  string s;
  cin >> s;
  n = s.size();
  const int inf = 2e9;
  int f[5][2];
  rep(i, 0, 5) rep(j, 0, 2) f[i][j] = -inf;
  f[0][0] = 0;
  for (int pos = n - 1; pos >= 0; pos--) {
    int nf[5][2];
    rep(i, 0, 5) rep(j, 0, 2) nf[i][j] = -inf;
    int ori = s[pos] - 'A';
    rep(mx, 0, 5) {
      rep(h, 0, 2) {
        rep(d, 0, 5) {
          int nm = max(mx, d), nh = h + (d != ori),
              nv = f[mx][h] + (d < mx ? -1 : 1) * p10[d];
          if (nh <= 1) {
            nf[nm][nh] = max(nf[nm][nh], nv);
          }
        }
      }
    }
    memcpy(f, nf, sizeof f);
  }
  int ans = -inf;
  rep(i, 0, 5) rep(j, 0, 2) ans = max(ans, f[i][j]);
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