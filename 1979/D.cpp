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

const int base = 131;
using ull = unsigned long long;
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int c0 = 0, c1 = 0;
  rep(i, n) {
    if (s[i] == '0')
      c0++;
    else
      c1++;
  }
  int part = n / k;
  if (part % 2 == 0) {
    if (c0 != c1) {
      cout << -1 << "\n";
      return;
    }
  }

  vi pref(n);
  vi suf(n + 1);
  
  suf[n] = 1;
  for (int i = 0; i < k; i++) {
    pref[i] = 1;
    suf[n - 1 - i] = 1;
  }

  for (int i = k; i < n; i++) {
    pref[i] = pref[i - 1] & (s[i] != s[i - k]);
  }

  for (int i = n - 1 - k; i >= 0; i--) {
    suf[i] = suf[i + 1] & (s[i] != s[i + k]);
  }

  vector<int> cand;
  for (int i = 0; i < n; i++) {
    if (pref[i] && suf[i + 1]) {
      cand.push_back(i + 1);
    }
  }

  vc<ull> pw(n + 1);
  pw[0] = 1;
  for (int i = 0; i < n; i++) {
    pw[i + 1] = pw[i] * base;
  }

  ull tar0 = 0;
  ull tar1 = 0;
  rep(i, k) tar0 = tar0 * base + 48;
  rep(i, k) tar1 = tar1 * base + 49;

  vc<ull> f(n + 1);
  f[0] = 0;
  rep(i, n) f[i + 1] = f[i] * base + s[i];
  vc<ull> rf(n + 1);
  rf[0] = 0;
  rep(i, n) rf[i + 1] = rf[i] * base + (s[i] ^ 1);
  vc<ull> g(n + 1);
  vc<ull> rg(n + 1);
  g[n] = 0;
  rg[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    g[i] = g[i + 1] * base + s[i];
    rg[i] = rg[i + 1] * base + (s[i] ^ 1);
  }

  // debug(s, cand);

  auto rangef = [&](vc<ull> &F, int l, int r) {
    return F[r] - F[l] * pw[r - l];
  };
  auto rangeg = [&](vc<ull> &G, int l, int r) {
    return G[l] - G[r] * pw[r - l];
  };

  auto check = [&](int i) {
    // [i, n) + (i, 0]
    int cut = n - i;
    int x = cut / k;
    int len = cut % k;
    ull cur = rangef((x % 2 == 1) ? rf : f, i + x * k, n) * pw[k - len] + rangeg((x % 2 == 1) ? rg : g, i - (k - len), i);

    ull cur0 = 0;
    if (i + k <= n) {
      cur0 = rangef(f, i, i + k);
    } else {
      cur0 = rangef(f, i, n) * pw[k - (n - i)] + rangeg(g, i - (k - (n - i)), i);
      // debug(s, i, cur0);
    }

    ull curn = 0;
    int y = (n - 1) / k;
    if (i >= k) {
      curn = rangeg((y % 2 == 1) ? rg : g, 0, k);
    } else {
      curn = rangef((y % 2 == 1) ? rf : f, n + i - k, n) * pw[i] + rangeg((y % 2 == 1) ? rg : g, 0, i);
    }

    // debug(s, i);
    // debug(cur0, cur, curn);
    if (cur0 == tar0 || cur0 == tar1) 
      return cur == cur0 && cur == curn;
    else
      return false;
  };

  for (int i : cand) {
    if (check(i)) {
      cout << i << "\n";
      return;
    }
  }

  cout << -1 << "\n";
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