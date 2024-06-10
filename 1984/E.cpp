#include <bits/stdc++.h>
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define pb emplace_back
using namespace std;
#define int long long
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

void solve() {
  int N;
  cin >> N;
  vc<vi> e(N);
  rep(i, N - 1) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    e[x].pb(y);
    e[y].pb(x);
  }

  vc<array<int, 2>> dp(N);
  vc<array<int, 2>> dq(N);

  int cur_mx = 0;

  auto dgs = [&](auto &dgs, int u, int p) -> void {
    dq[u] = array<int, 2>{0, 1};
    if (p != -1) {
      int f = max(dq[p][0], dq[p][1]), g = dq[p][0];
      dq[u][0] += f, dq[u][1] += g;
    }
    int acf = 0, acg = 0;
    for (auto v : e[u]) {
      if (v != p) {
        int f = max(dp[v][0], dp[v][1]), g = dp[v][0];
        acf += f, acg += g;
      }
    }
    dq[u][0] += acf;
    dq[u][1] += acg;
    int s = 0;
    for (auto v : e[u]) {
      if (v != p) {
        int f = max(dp[v][0], dp[v][1]), g = dp[v][0];
        dq[u][0] -= f, dq[u][1] -= g;
        dgs(dgs, v, u);
        dq[u][0] += f, dq[u][1] += g;
        s++;
      }
    }
    if ((int)e[u].size() == 1)
      cmax(cur_mx, dq[u][0] + 1);
  };

  auto dfs = [&](auto &dfs, int u, int p) -> void {
    dp[u] = array<int, 2>{0, 1};
    for (auto v : e[u])
      if (v != p) {
        dfs(dfs, v, u);
        int f = max(dp[v][0], dp[v][1]), g = dp[v][0];
        dp[u][0] += f, dp[u][1] += g;
      }
  };

  dfs(dfs, 0, -1), dgs(dgs, 0, -1);
  int ans = max(dp[0][0], dp[0][1]);
  rep(i, N) cmax(ans, dq[i][0]), cmax(ans, dq[i][1]);
  cout << max(ans, cur_mx) << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}