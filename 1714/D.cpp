/*
 * temp.cc
 * written by retired_user
 * 2022-08-01 22:48:05
 */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include </algo/debug.h>
#else
#define debug(...) 42
#endif
#define tr(x, v) for (auto &x : v)
#define rp(i, v) for (int i = 0; i < sz(v); i++)
#define rep(i, x, y) for (int i = x; i < y; i++)
#define pr(i, v) for (int i = sz(v) - 1; i >= 0; i--)
#define per(i, x, y) for (int i = x; i > y; i--)
template <typename T> void cmin(T &x, const T &y) {
  if (x > y)
    x = y;
}
template <typename T> void cmax(T &x, const T &y) {
  if (x < y)
    x = y;
}
using ll = long long;
using E = vector<vector<int>>;
using EW = vector<vector<array<int, 2>>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define ed(x) end(x)
#define all(x) bg(x), ed(x)
#define lb lower_bound
#define ub upper_bound
#define sort(x) sort(all(x))
#define unique(x) (x).erase(unique(all(x)), x.end())
#define rev(x) reverse(all(x))

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    int n;
    cin >> s >> n;
    vector<string> t(n);
    tr(x, t) cin >> x;
    auto cmp = [&](int i, int j) {
      int l = sz(t[j]);
      rep(k, 0, l) if (s[i + k] != t[j][k]) return false;
      return true;
    };
    vector<int> dp(sz(s) + 1, inf);
    vector<int> b(sz(s) + 1, -1);
    vector<int> id(sz(s) + 1, -1);
    vector<int> pre(sz(s) + 1, -1);
    dp[0] = 0, b[0] = id[0] = -1, pre[0] = -1;
    for (int i = 0; i < sz(s); i++) {
      for (int j = 0; j < n; j++)
        if (sz(t[j]) <= i + 1) {
          if (cmp(i - sz(t[j]) + 1, j)) {
            for (int k = i - sz(t[j]) + 1; k <= i; k++)
              if (dp[k] + 1 < dp[i + 1]) {
                dp[i + 1] = dp[k] + 1;
                b[i + 1] = i - sz(t[j]) + 1;
                id[i + 1] = j;
                pre[i + 1] = k;
              }
          }
        }
    }
    if (dp[sz(s)] == inf)
      cout << -1 << "\n";
    else {
      cout << dp[sz(s)] << "\n";
      int p = sz(s);
      while (p != -1) {
        if (id[p] == -1)
          break;
        cout << id[p] + 1 << " " << b[p] + 1 << "\n";
        p = pre[p];
      }
    }
  }
  return 0;
}