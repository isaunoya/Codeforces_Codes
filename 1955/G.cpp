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
  int n, m;
  cin >> n >> m;
  vc<vi> a(n, vi(m));
  rep(i, n) rep(j, m) cin >> a[i][j];
  vi d;
  const int X = a[0][0];
  for (int i = 1; i <= sqrt(X); i++) {
    if (X % i == 0) {
      d.pb(i);
      d.pb(X / i);
    }
  }
  int ans = 1;
  auto id = [&](int x, int y) { return x * m + y; };
  for (auto g : d) {
    vi vis(n*m);
    vi q{0};
    vis[0] = 1;
    rep((int)q.size()) {
      int u = q[i];
      int x = u / m, y = u % m;
      for (int dx = 0; dx <= 1; dx++) {
        for (int dy = 0; dy <= 1; dy++) {
          if (dx * dx + dy * dy == 1) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= n)
              continue;
            if (ny < 0 || ny >= m)
              continue;
            if (a[nx][ny] % g)
              continue;
            if (!vis[id(nx, ny)]) {
              vis[id(nx, ny)] = 1;
              q.emplace_back(id(nx, ny));
            }
          }
        }
      }
    }
    if (vis.back())
      cmax(ans, g);
  }
  cout << ans << "\n";
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