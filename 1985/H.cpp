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

struct unionfind {
  vector<int> p;
  unionfind(int N) { p = vector<int>(N, -1); }
  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (p[x] < p[y]) {
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
    }
  }
  int size(int x) { return -p[root(x)]; }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vc<string> S(N);
  rep(i, N) cin >> S[i];
  unionfind f(N * M);
  auto id = [&](int i, int j) { return i * M + j; };

  rep(i, N) {
    rep(j, M) {
      if (S[i][j] == '#') {
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx * dx + dy * dy == 1) {
              int ni = i + dx;
              int nj = j + dy;
              if (0 <= ni && ni < N && 0 <= nj && nj < M && S[ni][nj] == '#') {
                f.unite(id(i, j), id(ni, nj));
              }
            }
          }
        }
      }
    }
  }

  int ans = 0;
  rep(i, N) {
    map<int, int> oc;
    int cur = 0;
    rep(j, M) {
      if (S[i][j] == '#') {
        int F = f.root(id(i, j));
        if (!oc.count(F)) {
          oc[F] = 1;
          cur += f.size(F);
        }
      } else {
        cur++;
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx * dx + dy * dy == 1) {
              int ni = i + dx;
              int nj = j + dy;
              if (0 <= ni && ni < N && 0 <= nj && nj < M && S[ni][nj] == '#') {

                int F = f.root(id(ni, nj));
                if (!oc.count(F)) {
                  oc[F] = 1;
                  cur += f.size(F);
                }
              }
            }
          }
        }
      }
    }
    cmax(ans, cur);
  }

  rep(j, M) {
    map<int, int> oc;
    int cur = 0;
    rep(i, N) {
      if (S[i][j] == '#') {
        int F = f.root(id(i, j));
        if (!oc.count(F)) {
          oc[F] = 1;
          cur += f.size(F);
        }
      } else {
        cur++;
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx * dx + dy * dy == 1) {
              int ni = i + dx;
              int nj = j + dy;
              if (0 <= ni && ni < N && 0 <= nj && nj < M && S[ni][nj] == '#') {
                int F = f.root(id(ni, nj));
                if (!oc.count(F)) {
                  oc[F] = 1;
                  cur += f.size(F);
                }
              }
            }
          }
        }
      }
    }
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