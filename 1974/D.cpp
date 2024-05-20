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
  string s;
  cin >> n >> s;
  int x = 0, y = 0;
  // debug(n, s);
  rep(i, n) {
    if (s[i] == 'W')
      y--;
    if (s[i] == 'E')
      y++;
    if (s[i] == 'N')
      x--;
    if (s[i] == 'S')
      x++;
  }
  // debug(x, y);
  if (x % 2 || y % 2) {
    cout << "NO\n";
    return;
  }
  vi rx, ry;
  vi hx, hy;
  {
    // int tar_x = x / 2;
    int w1 = 0, w2 = 0;
    rep(i, n) {
      if (s[i] == 'N')
        w1++;
      if (s[i] == 'S')
        w2++;
    }
    int f1 = 0, f2 = 0;
    if (w1 % 2) {
      f1 = 1 + w1 / 2;
      f2 = 1 + w2 / 2;
    } else {
      f1 = w1 / 2;
      f2 = w2 / 2;
    }
    // debug(f1,f2);
    rep(i, n) {
      if (s[i] == 'N') {
        if (f1)
          rx.pb(i), f1--;
        else
          hx.pb(i);
      }
      if (s[i] == 'S') {
        if (f2)
          rx.pb(i), f2--;
        else
          hx.pb(i);
      }
    }
  }
  {
    // int tar_y = y / 2;
    int w1 = 0;
    int w2 = 0;
    rep(i, n) {
      if (s[i] == 'W')
        w1++;
      if (s[i] == 'E')
        w2++;
    }
    int f1 = 0, f2 = 0;
    if (w1 % 2) {
      f1 = 1 + w1 / 2;
      f2 = 1 + w2 / 2;
    } else {
      f1 = w1 / 2;
      f2 = w2 / 2;
    }
    rep(i, n) {
      if (s[i] == 'W') {
        if (f1)
          ry.pb(i), f1--;
        else
          hy.pb(i);
      }
      if (s[i] == 'E') {
        if (f2)
          ry.pb(i), f2--;
        else
          hy.pb(i);
      }
    }
  }
  for (int it = 0; it < 2; it++) {
    string t(n, 'H');
    for (auto i : rx)
      t[i] = 'R';
    for (auto i : ry)
      t[i] = 'R';
    int c = 0;
    rep(i, n) if (t[i] == 'H') c++;
    if (0 < c && c < n) {
      cout << t << "\n";
      return;
    }
    swap(rx, hx);
  }
  cout << "NO\n";
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