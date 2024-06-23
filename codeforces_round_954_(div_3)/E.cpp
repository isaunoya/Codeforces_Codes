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
  ll n, k;
  cin >> n >> k;
  vl a(n);
  rep(i, n) cin >> a[i];

  vi p(n);
  iota(all(p), 0);
  sort(all(p), [&](int i, int j) {
    if (a[i] % k == a[j] % k) {
      return a[i] < a[j];
    } else {
      return a[i] % k < a[j] % k;
    }
  });

  int odd = 0;
  ll ans = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    j = i;
    while (j < n && a[p[i]] % k == a[p[j]] % k) {
      j += 1;
    }
    int len = (j - i);
    if (len % 2 == 1) {
      // debug(i, j, len);
      odd += 1;
      ll cur1 = 0;
      ll cur2 = 0;
      for (int t = 1; t < len; t += 2) {
        cur2 += (a[p[i + t + 1]] - a[p[i + t]]) / k;
      }
      ll cur = cur2;
      for (int t = 0; t < len - 1; t += 2) {
        cur2 -= (a[p[i + t + 2]] - a[p[i + t + 1]]) / k;
        cur1 += (a[p[i + t + 1]] - a[p[i + t]]) / k;
        cmin(cur, cur1 + cur2);
      }
      if (len > 1) ans += cur;
    } else {
      for (int t = 0; t < len; t += 2) {
        ans += (a[p[i + t + 1]] - a[p[i + t]]) / k;
      }
    }
  }

  // debug(ans);
  if (odd > (n % 2)) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
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