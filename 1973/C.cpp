
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
  vi a(n);
  rep(i, n) cin >> a[i];
  {
    vc<pii> p;
    vc<pii> q;
    q.pb(a[0], 0);
    q.pb(a[n - 1], n - 1);
    rep(i, 1, n - 1) if (i % 2 == 1) p.pb(a[i], i); else q.pb(a[i], i);
    sort(all(p));
    int c = n;
    vi b(n);
    for (auto [v, i] : p) {
      b[i] = c;
      c--;
    }
    sort(all(q));
    for (auto [v, i] : q) {
      b[i] = c;
      c--;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      int l = a[i - 1] + b[i - 1];
      int x = a[i] + b[i];
      int r = a[i + 1] + b[i + 1];
      if (l < x && r < x) {
        ans += 1;
      }
    }
    if (ans + 1 == n / 2) {
      for (int i : b) {
        cout << i << " ";
      }
      cout << "\n";
      return;
    }
  }
  {
    vc<pii> p;
    vc<pii> q;
    q.pb(a[0], 0);
    q.pb(a[n - 1], n - 1);
    rep(i, 1, n - 1) if (i % 2 == 0) p.pb(a[i], i); else q.pb(a[i], i);
    sort(all(p));
    int c = n;
    vi b(n);
    for (auto [v, i] : p) {
      b[i] = c;
      c--;
    }
    sort(all(q));
    for (auto [v, i] : q) {
      b[i] = c;
      c--;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      int l = a[i - 1] + b[i - 1];
      int x = a[i] + b[i];
      int r = a[i + 1] + b[i + 1];
      if (l < x && r < x) {
        ans += 1;
      }
    }
    if (ans + 1 == n / 2) {
      for (int i : b) {
        cout << i << " ";
      }
      cout << "\n";
      return;
    }
  }

  assert(0);

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