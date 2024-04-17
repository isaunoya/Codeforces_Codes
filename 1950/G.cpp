#include <cstdio>
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

void solve() {
  int n;
  cin >> n;
  map<string, int> p1, p2;
  vc<string> s1(n), s2(n);
  vi a1(n), a2(n);
  int c1 = 0, c2 = 0;
  rep(i, n) {
    cin >> s1[i] >> s2[i];
    if (!p1.count(s1[i])) {
      p1[s1[i]] = ++c1;
    }
    if (!p2.count(s2[i])) {
      p2[s2[i]] = ++c2;
    }
    a1[i] = p1[s1[i]];
    a2[i] = p2[s2[i]];
  }
  vector<vector<bool>> dp(1 << n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 1;
  }

  for (int s = 1; s < (1 << n); s++) {
    for (int i = 0; i < n; i++) {
      if (!dp[s][i]) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        if (~s >> j & 1) {
          if (a1[i] == a1[j] || a2[i] == a2[j]) {
            dp[s | 1 << j][j] = 1;
          }
        }
      }
    }
  }

  int mx = 0;
  for (int s = 0; s < (1 << n); s++) {
    for (int i = 0; i < n; i++) {
      if (dp[s][i]) {
        mx = max(mx, __builtin_popcount(s));
      }
    }
  }
  cout << n - mx << "\n";
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