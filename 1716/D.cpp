/*
 * temp.cc
 * written by retired_user
 * 2022-08-04 22:48:22
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

const int P = 998244353;

void add(int &x, const int &y) {
  x += y;
  if (x >= P)
    x -= P;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> sum(n + 1);
  vector<int> dp(n + 1);
  dp[0] = 1;
  int s = 0, t = k;
  while (s <= n) {
    s += t;
    t++;
  }
  for (int w = k; w < t; w++) {
    for (int i = 0; i <= n; i++)
      add(sum[i], dp[i]);
    vector<int> ndp(n + 1);
    for (int i = w; i <= n; i++)
      ndp[i] = dp[i - w];
    for (int i = w; i <= n; i++)
      add(ndp[i], ndp[i - w]);
    dp = ndp;
  }
  for (int i = 1; i <= n; i++) {
    cout << sum[i] << " \n"[i == n];
  }
  return 0;
}