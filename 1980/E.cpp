#include <random>
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
mt19937_64 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

void solve() {
  map<int, unsigned long long> mp;
  int n, m;
  cin >> n >> m;
  vc<vi> a(n, vi(m));
  rep(i, n) rep(j, m) cin >> a[i][j];
  vc<vi> b(n, vi(m));
  rep(i, n) rep(j, m) cin >> b[i][j];
  rep(i, n) rep(j, m) {
    if (!mp.count(a[i][j])) {
      mp[a[i][j]] = rng();
    }
    if (!mp.count(b[i][j])) {
      mp[b[i][j]] = rng();
    }
  }

  {
    vc<unsigned long long> A, B;
    rep(i, n) {
      unsigned long long X = 0;
      rep(j, m) { X ^= mp[a[i][j]]; }
      A.push_back(X);
      X = 0;
      rep(j, m) { X ^= mp[b[i][j]]; }
      B.push_back(X);
    }
    sort(all(A));
    sort(all(B));
    if (A != B) {
      cout << "NO\n";
      return;
    }
  }
  {
    vc<unsigned long long> A, B;
    rep(j, m) {
      unsigned long long X = 0;
      rep(i, n) { X ^= mp[a[i][j]]; }
      A.push_back(X);
      X = 0;
      rep(i, n) { X ^= mp[b[i][j]]; }
      B.push_back(X);
    }
    sort(all(A));
    sort(all(B));
    if (A != B) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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