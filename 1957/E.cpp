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

const int mod = 1e9 + 7;

int power(int x, int y) {
  int r = 1;
  while (y) {
    if (y % 2 == 1) {
      r = 1ll * r * x % mod;
    }
    x = 1ll * x * x % mod;
    y /= 2;
  }
  return r;
}

void solve() {
  int n;
  cin >> n;
  vl fac(n + 1), inv(n + 1);
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = power(fac[n], mod - 2);
  for (int i = n - 1; i >= 1; --i)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;

  auto C = [&](int n, int m) -> ll {
    if (m < 0 || n < m)
      return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
  };

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      ans += 1ll * C(i, j) * fac[j - 1] % j;
      if (ans >= mod) {
        ans -= mod;
      }
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