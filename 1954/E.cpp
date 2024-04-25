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
  int n;
  cin >> n;
  vi a(n);
  int mx = 0;
  rep(i, n) cin >> a[i], cmax(mx, a[i]);
  // for (int k = 1; k <= mx; k++) {
  //   vi b(n);
  //   rep(i, n) b[i] = (a[i] + k - 1) / k;
  //   debug(b);
  //   int lst = 0;
  //   int ans = 0;
  //   rep(i, n) {
  //     if (b[i] > lst) {
  //       ans += b[i] - lst;
  //     }
  //     lst = b[i];
  //   }
  //   // cout << ans << " \n"[k == mx];
  // }

  vc<vi> upd(mx + 1);
  // debug(mx);
  rep(i, n) {
    int x = a[i] - 1;
    for (int l = 1, r = 0; l <= x; l = r + 1) {
      // debug(l, r);
      r = x / (x / l);
      // debug(l, i);
      upd[l].push_back(i);
    }
    upd[x + 1].push_back(i);
  }
  vi b(n);
  ll cur = 0;
  for (int k = 1; k <= mx; k++) {
    for (auto i : upd[k]) {
      // debug(k, i);
      {
        int lst = 0;
        if (i > 0) {
          lst = b[i - 1];
        }
        int suf = b[i];
        if (i + 1 < n) {
          suf = b[i + 1];
        }
        cur -= max(suf - b[i], 0) + max(b[i] - lst, 0);
      }
      b[i] = (a[i] + k - 1) / k;
      {
        int lst = 0;
        if (i > 0) {
          lst = b[i - 1];
        }
        int suf = b[i];
        if (i + 1 < n) {
          suf = b[i + 1];
        }
        cur += max(suf - b[i], 0) + max(b[i] - lst, 0);
      }
    }
    // debug(b);
    cout << cur << " \n"[k == mx];
  }
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