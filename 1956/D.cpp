#include <numeric>
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

vc<pii> res[20];
void solve() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  vi s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  vi dp(n + 1, 0);
  dp[0] = 0;
  rep(i, n) {
    rep(j, i + 1, n + 1) cmax(dp[j], dp[i] + s[j] - s[i]),
        cmax(dp[j], dp[i] + (j - i) * (j - i));
  }
  // debug(dp[n]);
  // debug(dp);
  int p = n;
  vc<pii> seg;
  while (p != 0) {
    int new_p = -1;
    rep(i, p) if (dp[p] == dp[i] + s[p] - s[i]) {
      new_p = i;
      break;
    }
    if (new_p == -1) {
      rep(i, p) if (dp[p] == dp[i] + (p - i) * (p - i)) {
        new_p = i;
        break;
      }
      seg.emplace_back(new_p, p);
      p = new_p;
    } else {
      p = new_p;
    }
  }
  // debug(seg);

  vc<pii> ops;
  for (auto [l, r] : seg) {
    rep(k, l, r) if (a[k] != 0) ops.emplace_back(k, k);
  }
  for (auto [l, r] : seg) {
    int len = r - l;
    for (auto [L, R] : res[len]) {
      ops.emplace_back(l + L, l + R);
    }
  }
  cout << dp[n] << " " << sz(ops) << "\n";
  for (auto [l, r] : ops) {
    // vi A=a, c(n);
    // rep(i, l, r+1) if(a[i]<n)c[a[i]]++;
    // int mex=0;
    // while(mex<n&&c[mex])mex++;
    // rep(i, l, r+1) A[i]=mex;
    cout << l + 1 << " " << r + 1 << "\n";
    // swap(a,A);
  }
  // assert(accumulate(all(a),0)==dp[n]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  res[1] = {{0, 0}};
  res[2] = {{1, 1}, {0, 1}};
  // {0, 1}
  // {2, 2}
  res[3] = {{1, 1}, {0, 2}, {0, 1}, {1, 1}, {0, 2}};
  // {0, 1, 0}
  // {2, 2, 2}
  // {0, 0, 2}
  // {0, 1, 2}
  // {3, 3, 3}
  for (int k = 4; k <= 18; k++) {
    rep(i, sz(res[k - 1])) {
      if (i + 1 == sz(res[k - 1])) {
        res[k].emplace_back(res[k - 1][i].fi, res[k - 1][i].se + 1);
      } else {
        res[k].emplace_back(res[k - 1][i]);
      }
    }
    res[k].emplace_back(0, k - 2);
    rep(i, sz(res[k - 1])) {
      if (i + 1 == sz(res[k - 1])) {
        res[k].emplace_back(res[k - 1][i].fi, res[k - 1][i].se + 1);
      } else {
        res[k].emplace_back(res[k - 1][i]);
      }
    }
  }
  // {
  //   rep(k, 3, 19) {
  //     vi a(k, 0);
  //     for (auto [l, r] : res[k]) {
  //       vi A = a, c(k);
  //       rep(i, l, r + 1) if (a[i] < k) c[a[i]]++;
  //       int mex = 0;
  //       while (mex < k && c[mex])
  //         mex++;
  //       rep(i, l, r + 1) A[i] = mex;
  //       // cout << l + 1 << " " << r + 1 << "\n";
  //       swap(a, A);
  //     }
  //     debug(a);
  //     assert(accumulate(all(a), 0) == k * k);
  //   }
  // }
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}