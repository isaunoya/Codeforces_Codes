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
  int N, M;
  cin >> N >> M;
  vc<string> S(N);
  rep(i, N) cin >> S[i];
  auto id = [&](int i, int j) { return i * M + j; };
  vi p(N * M, -1), lx(N * M), rx(N * M), ly(N * M), ry(N * M), s(N * M);
  auto ok = [&](int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M && S[i][j] == '#';
  };

  rep(x, N) {
    rep(y, M) {
      if (S[x][y] == '.')
        continue;
      int k = id(x, y);
      if (p[k] != -1)
        continue;
      p[k] = k;
      vi q{k};
      lx[k] = rx[k] = x;
      ly[k] = ry[k] = y;
      rep(t, sz(q)) {
        int u = q[t];
        int i = u / M;
        int j = u % M;
        cmin(lx[k], i), cmax(rx[k], i);
        cmin(ly[k], j), cmax(ry[k], j);
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx * dx + dy * dy == 1) {
              int i2 = i + dx;
              int j2 = j + dy;
              if (ok(i2, j2)) {
                int v = id(i2, j2);
                if (p[v] == -1) {
                  p[v] = k;
                  q.pb(v);
                }
              }
            }
          }
        }
      }
      s[k] = sz(q);
    }
  }

  vc<vi> SUM(N + 1, vi(M + 1, 0));

  auto add = [&](int i1, int j1, int i2, int j2, int v) {
    i1 = clamp(i1, 0, N - 1);
    i2 = clamp(i2, 0, N - 1);
    j1 = clamp(j1, 0, M - 1);
    j2 = clamp(j2, 0, M - 1);

    i2++, j2++;
    SUM[i1][j1] += v;
    SUM[i1][j2] -= v;
    SUM[i2][j1] -= v;
    SUM[i2][j2] += v;
  };

  rep(i, N) rep(j, M) {
    int k = id(i, j);
    if (p[k] == k) {
      add(lx[k] - 1, 0, rx[k] + 1, M - 1, s[k]);
      add(0, ly[k] - 1, N - 1, ry[k] + 1, s[k]);
      add(lx[k] - 1, ly[k] - 1, rx[k] + 1, ry[k] + 1, -s[k]);
    }
  }

  vi adx(N), ady(M);
  rep(i, N) rep(j, M) {
    if (S[i][j] == '.') {
      ++adx[i];
      ++ady[j];
    }
  }
  rep(i, N + 1) rep(j, M) SUM[i][j + 1] += SUM[i][j];
  rep(i, N) rep(j, M + 1) SUM[i + 1][j] += SUM[i][j];

  // debug(SUM);
  int ans = 0;
  rep(i, N) rep(j, M) {
    int cur = SUM[i][j] + adx[i] + ady[j] - (S[i][j] == '.');
    cmax(ans, cur);
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