/*
 * temp.cc
 * written by retired_user
 * 2022-08-01 23:53:19
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
    int n;
    cin >> n;
    vector<array<ll, 20>> p(n + 1), b(n + 1);
    vector<ll> a(n + 1), bs(n + 1), d(n + 1);
    a[1] = 0, d[1] = 0;
    auto e = E(n + 1);
    for (int i = 2; i <= n; i++) {
      cin >> p[i][0] >> a[i] >> b[i][0];
      e[p[i][0]].push_back(i);
    }
    auto dfs = [&](auto self, int i) -> void {
      if (i != 1) {
        a[i] += a[p[i][0]];
        bs[i] = bs[p[i][0]] + b[i][0];
        d[i] = d[p[i][0]] + 1;
      }
      for (auto j : e[i])
        self(self, j);
    };
    dfs(dfs, 1);

    for (int j = 1; j < 20; j++)
      for (int i = 1; i <= n; i++) {
        p[i][j] = p[p[i][j - 1]][j - 1];
        b[i][j] = b[i][j - 1] + b[p[i][j - 1]][j - 1];
      }

    for (int i = 2; i <= n; i++) {
      //      debug(i,a[i],bs[i]);
      ll w = 0, c = 0, x = i;
      if (bs[i] <= a[i]) {
        cout << d[i] << " \n"[i == n];
        continue;
      }
      for (int j = 19; j >= 0; j--)
        if (p[x][j] && bs[i] - (w + b[x][j]) > a[i]) {
          w += b[x][j];
          x = p[x][j];
          c += 1 << j;
        }
      //      debug(i,d[i],c);
      cout << d[i] - c - 1 << " \n"[i == n];
    }
  }
  return 0;
}