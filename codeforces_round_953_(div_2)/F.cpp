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

#include <atcoder/dsu>

const int N = 1e6 + 5;
int M[N];
auto init = []() {
  rep(i, N) M[i] = i;
  for (int i = 2; i < N; i++) {
    if (M[i] == i) {
      for (int j = i * 2; j < N; j += i) {
        M[j] = i;
      }
    }
  }
  return 0;
}();

int vis[N];
vi v[N];
void solve() {
  int N, K;
  cin >> N >> K;
  using namespace atcoder;
  dsu F(N+N);
  auto factor = [&](int X) {
    vi p;
    while (X > 1) {
      if (p.empty() || M[X] != p.back())
        p.pb(M[X]);
      X /= M[X];
    }
    return p;
  };
  vi A(N);
  vi cand;
  rep(i, N) {
    int X;
    cin >> X;
    A[i] = X;
    auto p = factor(X);
    // debug(X, p);
    for (auto j : p) {
      v[j].pb(i);
      if (!vis[j]) {
        vis[j] = 1;
        cand.pb(j);
      }
    }
  }
  for (auto c : cand) {
    vi cur;
    for (auto i : v[c]) {
      if (i != 0)
        cur.pb(i);
    }
    for (auto i : v[c]) {
      cur.pb(i+N);
    }
    rep(i, sz(cur)-1) {
      int x = cur[i], y = cur[i+1];
      if (y-x <= K) {
        F.merge(x, y);
      }
    }
  }
  ll ans = 0;
  rep(i, 1, N+N) {
    if (F.leader(i) == i) {
      ans += 1;
    }
  }
  rep(i, N) {
    if (A[i] == 1) {
      if (i > 0) {
        ans += N-2;
      } else {
        ans += N-1;
      }
    } 
  }
  cout << ans << "\n";

  for (auto c : cand) {
    vis[c] = 0;
    v[c].clear();
  }
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
