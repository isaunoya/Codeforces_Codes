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
  int a, b, n, m;
  cin >> a >> b >> n >> m;
  vi x(n), y(n);
  set<tuple<int, int, int>> X, Y;
  rep(i, n) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
    X.emplace(x[i], y[i], i);
    Y.emplace(y[i], x[i], i);
  }
  int cur_x1 = 0;
  int cur_x2 = a;
  int cur_y1 = 0;
  int cur_y2 = b;
  int s1 = 0;
  int s2 = 0;
  rep(tt, m) {
    char c;
    int xx;
    int add = 0;
    cin >> c >> xx;
    if (c == 'D') {
      int f = cur_x2 - xx;
      auto w = X.lower_bound(make_tuple(f, 0, 0));
      vi cur;
      while (w != X.end()) {
        auto [x, y, i] = *w;
        if (x >= cur_x2) {
          break;
        }
        cur.pb(i);
        w++;
      }
      add = sz(cur);
      for (auto i : cur) {
        X.erase(X.find(make_tuple(x[i], y[i], i)));
        Y.erase(Y.find(make_tuple(y[i], x[i], i)));
      }
      cur_x2 = f;
    }
    if (c == 'U') {
      int f = cur_x1 + xx;
      auto w = X.lower_bound(make_tuple(cur_x1, 0, 0));
      vi cur;
      while (w != X.end()) {
        auto [x, y, i] = *w;
        if (x >= f) {
          break;
        }
        cur.pb(i);
        w++;
      }
      add = sz(cur);
      for (auto i : cur) {
        X.erase(X.find(make_tuple(x[i], y[i], i)));
        Y.erase(Y.find(make_tuple(y[i], x[i], i)));
      }
      cur_x1 = f;
    }
    if (c == 'L') {
      int f = cur_y1 + xx;
      auto w = Y.lower_bound(make_tuple(cur_y1, 0, 0));
      vi cur;
      while (w != Y.end()) {
        auto [y, x, i] = *w;
        if (y >= f) {
          break;
        }
        cur.pb(i);
        w++;
      }
      add = sz(cur);
      for (auto i : cur) {
        X.erase(X.find(make_tuple(x[i], y[i], i)));
        Y.erase(Y.find(make_tuple(y[i], x[i], i)));
      }
      cur_y1 = f;
    }
    if (c == 'R') {
      int f = cur_y2 - xx;
      auto w = Y.lower_bound(make_tuple(f, 0, 0));
      vi cur;
      while (w != Y.end()) {
        auto [y, x, i] = *w;
        if (y >= cur_y2) {
          break;
        }
        cur.pb(i);
        w++;
      }
      add = sz(cur);
      for (auto i : cur) {
        X.erase(X.find(make_tuple(x[i], y[i], i)));
        Y.erase(Y.find(make_tuple(y[i], x[i], i)));
      }
      cur_y2 = f;
    }
    if (tt % 2 == 0) {
      s1 += add;
    } else {
      s2 += add;
    }

    // debug(s1, s2);
    // debug(add, cur_x1, cur_x2, cur_y1, cur_y2);
    // debug(X, Y);
  }
  cout << s1 << " " << s2 << "\n";
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