/*
 * temp.cc
 * written by retired_user
 * 2022-08-01 23:28:00
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d12, d23, d13;
    cin >> n >> d12 >> d23 >> d13;
    if (d12 + d13 < d23) {
      cout << "no\n";
      continue;
    }
    if (d12 + d23 < d13) {
      cout << "no\n";
      continue;
    }
    if (d13 + d23 < d12) {
      cout << "no\n";
      continue;
    }
    if ((d12 + d13) % 2 != d23 % 2) {
      cout << "no\n";
      continue;
    }
    bool r = false;
    if (d12 > d13)
      swap(d12, d13), r = true;
    int nd = 3;
    vector<pair<int, int>> edge;
    vector<int> rev(n);
    rev[0] = 1;
    for (int i = 1; i < d12; i++) {
      nd++;
      rev[i] = nd;
      edge.emplace_back(nd, rev[i - 1]);
    }
    edge.emplace_back(2, rev[d12 - 1]);
    rev[d12] = 2;
    for (int i = 0; i <= d12; i++) {
      if (d13 + d12 - 2 * i == d23) {
        for (int j = i + 1; j < d13; j++) {
          nd++;
          rev[j] = nd;
          edge.emplace_back(nd, rev[j - 1]);
        }
        edge.emplace_back(3, rev[d13 - 1]);
      }
    }
    if (nd > n)
      cout << "no\n";
    else {
      cout << "yes\n";
      while (nd < n)
        edge.emplace_back(++nd, 1);
      for (auto [x, y] : edge) {
        if (r) {
          if (x == 2)
            x = 3;
          else if (x == 3)
            x = 2;
          if (y == 2)
            y = 3;
          else if (y == 3)
            y = 2;
        }
        cout << x << " " << y << "\n";
      }
    }
  }
  return 0;
}