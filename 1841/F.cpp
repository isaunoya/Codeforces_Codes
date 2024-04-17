#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
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

int quadrant(int x, int y) {
  if (x > 0 && y >= 0) {
    return 1;
  }
  if (x <= 0 && y > 0) {
    return 2;
  }
  if (x < 0 && y <= 0) {
    return 3;
  }
  if (x >= 0 && y < 0) {
    return 4;
  }
  // assert(0)
  return 4;
}

int quadrant(pii p) { return quadrant(p.fi, p.se); }

ll cross(pii x, pii y) { return (ll)x.fi * y.se - (ll)x.se * y.fi; }

void solve() {
  int n;
  cin >> n;

  vc<pii> p(n);
  rep(i, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    p[i] = {a - b, c - d};
  }

  vc<pii> v;
  double cur_x = 0;
  double cur_y = 0;
  rep(i, n) {
    v.pb(p[i]);
    v.pb(-p[i].fi, -p[i].se);
    if (quadrant(p[i]) >= 3)
      cur_x += p[i].fi, cur_y += p[i].se;
  }
  sort(all(v), [&](auto i, auto j) {
    int a = quadrant(i), b = quadrant(j);
    return a != b ? a < b : cross(i, j) > 0;
  });

  double ans = cur_x * cur_x + cur_y * cur_y;
  // debug(cur_x, cur_y);
  for (auto [x, y] : v) {
    cur_x += x, cur_y += y;
    cmax(ans, cur_x * cur_x + cur_y * cur_y);
  }
  cout << fixed << setprecision(20) << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}