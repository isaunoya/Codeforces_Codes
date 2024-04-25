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

const int P = 1e9 + 7;
void solve() {
  int r, c;
  cin >> r >> c;
  vector<string> a(r);
  rep(i, r) cin >> a[i];
  unionfind f(r * 2);
  rep(j, c) {
    int k = c - 1 - j; // symmetry point
    if (j > k) {
      break;
    }
    // assume j <= k
    vi A, B;
    rep(i, r) {
      if (a[i][j] == '1') {
        A.pb(i);
      }
      if (j < k && a[i][k] == '1') {
        B.pb(i);
      }
    }
    if (sz(A) + sz(B) >= 3) {
      cout << 0 << "\n";
      return;
    }
    if (sz(A) + sz(B) <= 1) {
      continue;
    }
    // sz(A) + sz(B) == 2

    // always two in one column
    if (j == k) {
      cout << 0 << "\n";
      return;
    }

    vi R;
    for (auto i : A)
      R.pb(i);
    for (auto i : B)
      R.pb(i);
    // sz(R) = 2
    if (R[0] == R[1]) {
      continue;
    } // dont care it

    int i1 = R[0];
    int i2 = R[1];
    int op = (a[i1][j] == a[i2][j]);
    for (int w = 0; w < 2; w++) {
      f.unite(i1 * 2 + w, i2 * 2 + (w ^ op));
    }
  }
  rep(r) if (f.same(i * 2, i * 2 + 1)) {
    cout << 0 << "\n";
    return;
  }
  int comp = 0;
  rep(r * 2) if (f.root(i) == i) { comp++; }
  comp /= 2;
  int ans = 1;
  rep(comp) { ans = ans * 2 % P; }
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