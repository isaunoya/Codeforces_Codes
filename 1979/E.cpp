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
  cin >> n;
  int d;
  cin >> d;
  vector<int> X(n);
  vector<int> Y(n);
  for (int i = 0; i < n; i++) {
    cin >> X[i] >> Y[i];
  }

  rep(ox, 2) {
    rep(oy, 2) {
      vc<array<int, 4>> p(n);
      rep(i, n) {
        int x = ox ? X[i] : -X[i];
        int y = oy ? Y[i] : -Y[i];
        p[i] = array<int, 4>{x + y, x, y, i};
      }
      sort(all(p));
      map<int, vc<pii>> ok;
      for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && p[i][0] == p[j][0]) {
          j++;
        }
        auto &v = ok[p[i][0] - d];
        // debug(p[i][0] - d, v, p[i][0], p[i][3]);
        for (int k = i; k < j; k++) {
          int x = p[k][1];
          int y = p[k][2];
          int l = -1, r = (int)v.size();
          while (r - l > 1) {
            int m = (l + r) / 2;
            auto [b, c] = v[m];
            // debug(b, c);
            int xb = ox ? X[b] : -X[b];
            int yb = oy ? Y[b] : -Y[b];
            int xc = ox ? X[c] : -X[c];
            int yc = oy ? Y[c] : -Y[c];

            // debug(xb, yb, xc, yc, x, y);
            // xb < xc
            // yb > yc

            // assert(xb < xc && yb > yc);
            if (xc > x) {
              r = m;
            }
            if (yb > y) {
              l = m;
            }

            
            if (xc <= x && yb <= y) {
              cout << p[k][3] + 1 << " " << b + 1 << " " << c + 1 << "\n";
              return;
            }
          }
        }

        int l = i;
        for (int k = i; k < j; k++) {
          // debug(i, j, k, p[k][1]);
          while (l < j && p[l][1] - p[k][1] < d / 2) {
            l++;
          }
          if (l < j && p[l][1] - p[k][1] == d / 2) {
            ok[p[i][0]].pb(p[k][3], p[l][3]);
          }
        }
      }
    }
  }
  cout << 0 << " " << 0 << " " << 0 << "\n";
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