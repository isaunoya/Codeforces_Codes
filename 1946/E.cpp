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


const int P = 1e9 + 7;
const int N = 2e5 + 5;

int fac[N], ifac[N];

int power(int x, int y) {
  int r = 1;
  while (y) {
    if (y % 2 == 1) {
      r = 1ll * r * x % P;
    }
    x = 1ll * x * x % P;
    y /= 2;
  }
  return r;
}
ll C(int x, int y) {
  return (ll)fac[x] * ifac[y] % P * ifac[x - y] % P;
}
void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vi a(x), b(y);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  if (a.back() != b[0]) {
    cout << 0 << "\n";
    return;
  }
  ll ans = 1;
  vi vis(n + 1);
  for (auto ai : a) vis[ai]++;
  for (auto bi : b) vis[bi]++;
  for (int i = 1; i < a.back(); i++) {
    if (!vis[i]) {
      ans = 1ll * ans * (i - 1) % P;
    }
  }
  for (int i = a.back() + 1; i <= n; i++) {
    if (!vis[i]) {
      ans = 1ll * ans * (n - i) % P;
    }
  }
  // debug(ans);
  // value n is on the pos a.back()
  // rem n-1 values
  ans = 1ll * ans * C(n - 1, a.back() - 1) % P;
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = 1ll * fac[i - 1] * i % P;
  }
  rep(N) ifac[i] = power(fac[i], P - 2);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}