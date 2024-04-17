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

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  rep(i, n) cin >> a[i];
  vc<vc<pii>> at(n);
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    --l;
    at[l].pb(r, i);
  }
  vi pos(n + 1);
  rep(n) pos[a[i]] = i;
  vl ans(q);
  vl add(n + 1);
  vl t(n * 2);
  auto upd = [&](int x, ll v) {
    x += n;
    while (x)
      t[x] += v, x /= 2;
    return;
  };
  auto query = [&](int l, int r) {
    ll ans = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        ans += t[l++];
      }
      if (r & 1) {
        ans += t[--r];
      }
    }
    return ans;
  };

  for (int l = n - 1; l >= 0; l--) {
    int x = a[l];
    add[x] = 1;
    for (int v = x; v <= n; v += x) {
      upd(pos[v], add[v]);
      for (int u = v + v; u <= n; u += v) {
        if (pos[v] < pos[u]) {
          add[u] += add[v];
        }
      }
      add[v] = 0;
    }
    for (auto [r, id] : at[l]) {
      ans[id] = query(0, r);
    }
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
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