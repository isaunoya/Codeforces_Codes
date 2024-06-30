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

// #include <atcoder/modint>
#include <atcoder/segtree>
using namespace atcoder;
using node = array<ll, 6>;
// ans, L-inc, R-inc, lv, rv, len
node merge(node a, node b) {
  node c{};
  c[0] = a[0] + b[0] + (a[4] <= b[3] ? a[2] * b[1] : 0);
  c[1] = a[1] + ((a[1] == a[5] && a[4] <= b[3]) ? b[1] : 0);
  c[2] = b[2] + ((b[2] == b[5] && a[4] <= b[3]) ? a[2] : 0);
  c[3] = a[3];
  c[4] = b[4];
  c[5] = a[5] + b[5];
  return c;
}
node e() { return node{}; }

void solve() {
  int N, Q;
  cin >> N >> Q;
  vi A(N);
  rep(N) cin >> A[i];
  segtree<node, merge, e> st(N);
  rep(x, N) st.set(x, node{1, 1, 1, A[x], A[x], 1});
  rep(Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      --x;
      A[x] = y;
      st.set(x, node{1, 1, 1, y, y, 1});
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      cout << st.prod(l, r)[0] << "\n";
    }
  }
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