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

const int N = 1e6 + 5;
bool isprime[N];
vl prime;
ll fac[N], inv[N];
ll f[N], f1[N], p[N];
void init(int n = 1e6) {
  for (int j = 2; j <= n; ++j) {
    if (!p[j] || j == 4) {
      for (int i = j; i <= n; i += j) {
        int pp = j - 1;
        if (j == 4)
          pp = 2;
        int tmp = ((i / j) * pp) % j;
        f1[i] += tmp, f1[i] %= mod;
        if (i + j <= n)
          f1[i + j] -= tmp, f1[i + j] %= mod;
      }
    }
    for (int i = 2 * j; i <= n; i += j)
      p[i] = 1;
  }
  for (int i = 1; i <= n; ++i)
    f1[i] += f1[i - 1], f1[i] %= mod;
  for (int i = 1; i <= n; ++i)
    f[i] += (f[i - 1] + f1[i]) % mod;
}

void solve() {
  ll n;
  cin >> n;
  cout << (f[n] % mod + mod) % mod << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 2; i < N; i++) {
    isprime[i] = 1;
  }
  for (int i = 2; i < N; i++) {
    if (isprime[i]) {
      prime.emplace_back(i);
      for (int j = i + i; j < N; j += i) {
        isprime[j] = 1;
      }
    }
  }
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[N - 1] = power(fac[N - 1], mod - 2);
  for (int i = N - 2; i >= 1; --i)
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  init();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}