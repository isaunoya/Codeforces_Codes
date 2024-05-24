/*
 * temp.cc
 * written by retired_user
 * 2022-08-01 23:05:02
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
  vector<int> w(10);
  rep(i, 0, 10) {
    int x = i + i, c = 0;
    while (x % 10 != i) {
      x += x % 10;
      c++;
      if (c > 20)
        break;
    }
    if (c == 21)
      w[i] = -1;
    else
      w[i] = x - i;
  }
  //  debug(w); return 0;
  w[0] = -1;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    tr(x, a) cin >> x;
    sort(a);
    unique(a);
    n = sz(a);
    bool can = false;
    rep(k, 0, 10) {
      vector<int> b;
      rep(i, 0, n) {
        int c = 0;
        int x = a[i];
        while (x % 10 != k) {
          x += x % 10;
          c++;
          if (c > 20)
            break;
        }
        if (c <= 20)
          b.push_back(x);
      }
      if (sz(b) == n) {
        sort(b);
        unique(b);
        if (sz(b) == 1)
          can = true;
        else if (w[k] != -1) {
          bool fl = true;
          int mx = b.back();
          tr(x, b) fl &= ((mx - x) % w[k] == 0);
          if (fl)
            can = true;
        }
      }
    }
    if (can)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}