/*
 * temp.cc
 * written by retired_user
 * 2022-08-04 23:35:40
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

int n;
ll a[262144];
ll pre[512][512];
ll suf[512][512];
ll sum[512];
ll res[512][512];
ll id[512];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < 1 << n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 512; i++) {
    id[i] = i;
    int t = 0;
    for (int j = 0; j < 1 << n; j += 512) {
      ll s = 0;
      for (int k = j; k < j + 512; k++) {
        s += a[k ^ i];
        cmax(pre[i][t], s);
      }
      sum[t] = s;
      s = 0;
      for (int k = j + 511; k >= j; k--) {
        s += a[k ^ i];
        cmax(suf[i][t], s);
      }
      s = 0;
      for (int k = j; k < j + 512; k++) {
        if (s < 0)
          s = 0;
        s += a[k ^ i];
        cmax(res[i][t], s);
      }
      t++;
    }
  }
  int q;
  cin >> q;
  int tag = 0;
  while (q--) {
    int k;
    cin >> k;
    if (k >= 9) {
      k -= 9;
      int t = 1 << k;
      for (int i = 0; i < 512; i += t * 2) {
        for (int j = 0; j < t; j++) {
          swap(id[i + j], id[i + j + t]);
        }
      }
    } else {
      tag ^= 1 << k;
    }
    ll ans = 0;
    ll p = 0;
    for (int t = 0; t < 512; t++) {
      int i = id[t];
      cmax(ans, p + pre[tag][i]);
      p = max(p + sum[i], suf[tag][i]);
      cmax(ans, res[tag][i]);
    }
    cout << ans << "\n";
  }
  return 0;
}