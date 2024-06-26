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

#include <atcoder/segtree>

using S = array<int, 2>;
S op(S a, S b) { return S{max(a[0], b[0]), min(a[1], b[1])}; }
S e() { return S{-INF, INF}; }
void solve() {
  int N;
  cin >> N;
  vi A(N);
  rep(N) cin >> A[i];
  set<int> st;
  rep(N - 1) if (A[i] > A[i + 1]) st.emplace(i);
  using namespace atcoder;
  segtree<S, op, e> seg(N);
  rep(N) seg.set(i, {A[i], A[i]});

  auto query = [&]() {
    if (st.empty()) {
      cout << -1 << " " << -1 << "\n";
      return;
    }
    int L = *st.begin();
    int R = *st.rbegin();

    {
      int suf = seg.prod(L, N)[1];
      L = seg.max_right(0, [&](auto f) { return f[0] <= suf; });
    }

    {
      int pref = seg.prod(0, R + 1)[0];
      R = seg.min_left(N, [&](auto f) { return f[1] >= pref; });
    }

    cout << L + 1 << " " << R << "\n";
  };

  query();

  int Q;
  cin >> Q;
  rep(Q) {
    int x, v;
    cin >> x >> v;
    --x;
    st.erase(x - 1);
    st.erase(x);
    A[x] = v;
    if (x > 0 && A[x - 1] > A[x])
      st.emplace(x - 1);
    if (x + 1 < N && A[x] > A[x + 1])
      st.emplace(x);
    seg.set(x, {v, v});
    query();
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