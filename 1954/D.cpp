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

// sum max(max{a_i}, (sum{a_i}+1)/2)
// sum max{a_i}+(sum_{a_i}+1)/2-min(max{a_i},(sum_{a_i}+1)/2}

const int P = 998244353;
const int inv2 = (P + 1) / 2;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  int ans = 0;
  int coef = 1;
  rep(i, n) {
    ans += 1ll * coef * a[i] % P;
    if (ans >= P) {
      ans -= P;
    }
    coef = coef * 2 % P;
  }
  // debug(coef);
  int sum = 0;
  rep(i, n) sum += a[i];
  rep(i, n - 1) sum = sum * 2 % P;
  int have_1 = 0;
  rep(i, n) if (a[i] % 2 == 1) have_1 = 1;
  if (have_1) {
    int cur = 1;
    rep(i, n - 1) cur = cur * 2 % P;
    sum += cur;
    if (sum >= P) {
      sum -= P;
    }
  }
  sum = 1ll * sum * inv2 % P;
  ans += sum;
  if (ans >= P) {
    ans -= P;
  }
  // debug(ans);
  array<int, 10001> dp;
  rep(i, 10001) dp[i] = 0;
  dp[0] = 1;
  rep(i, n) {
    int x = a[i];
    for (int j = x; j <= 10000; j++) {
      ans -= 1ll * min(x, (j + 1) / 2) * dp[j - x] % P;
      if (ans < 0) {
        ans += P;
      }
    }
    array<int, 10001> ndp = dp;
    for (int j = 10000; j >= x; j--) {
      ndp[j] += dp[j - x];
      if (ndp[j] >= P) {
        ndp[j] -= P;
      }
    }
    dp.swap(ndp);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}