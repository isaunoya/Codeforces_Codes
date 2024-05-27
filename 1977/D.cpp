#include <algorithm>
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
mt19937_64 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

using ull = unsigned long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vc<string> s(n);
  rep(i, n) cin >> s[i];
  vc<ull> R(n);
  rep(i, n) R[i] = rng();
  vc<ull> col(m);
  rep(i, n) {
    rep(j, m) {
      if (s[i][j] == '1') {
        col[j] ^= R[i];
      }
    }
  }
  vc<ull> tar;
  rep(i, n) {
    rep(j, m) {
      tar.pb(col[j] ^ R[i]);
    }
  }
  sort(all(tar));
  array<int, 3> ans;
  rep(3) ans[i] = 0;
  rep(i, n) {
    rep(j, m) {
      ull cur = col[j] ^ R[i];
      int res = upper_bound(all(tar), cur) - lower_bound(all(tar), cur);
      if (res > ans[0]) {
        ans[0] = res;
        ans[1] = i;
        ans[2] = j;
      }
    }
  }
  cout << ans[0] << "\n";
  rep(i, n) {
    cout << char(s[i][ans[2]] ^ (i == ans[1]));
  }
  cout << "\n";
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