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
  int n, m;
  cin >> n >> m;
  int k = n + m + 1;
  vi a(k);
  rep(i, k) cin >> a[i];
  vi b(k);
  rep(i, k) cin >> b[i];

  vl A(k + 1);
  vl B(k + 1);
  A[k] = B[k] = 0;
  for (int i = k - 1; i >= 0; i--)
    A[i] = A[i + 1] + a[i];
  for (int i = k - 1; i >= 0; i--)
    B[i] = B[i + 1] + b[i];

  vi ca(k + 1);
  vi cb(k + 1);
  ca[0] = cb[0] = 0;
  for (int i = 0; i < k; i++) {
    ca[i + 1] = ca[i] + (a[i] > b[i]);
    cb[i + 1] = cb[i] + (a[i] < b[i]);
  }
  vl cur(k + 1);
  for (int i = 0; i < k; i++) {
    cur[i + 1] = cur[i] + max(a[i], b[i]);
  }

  for (int i = 0; i < k; i++) {
    int L = 0, R = k + 1;
    int da = (a[i] > b[i]);
    int db = (a[i] < b[i]);
    auto getca = [&](int M) {
      if (i < M) {
        return ca[M] - da;
      } else {
        return ca[M];
      }
    };
    auto getcb = [&](int M) {
      if (i < M) {
        return cb[M] - db;
      } else {
        return cb[M];
      }
    };
    while (R - L > 1) {
      int M = (L + R) / 2;
      if (getca(M) <= n && getcb(M) <= m) {
        L = M;
      } else {
        R = M;
      }
    }
    // debug(i, L, a, b);
    // debug(getca(L), getcb(L));
    ll ans = cur[L];
    if (i < L) {
      ans -= max(a[i], b[i]);
    }
    if (getca(L) == n) {
      ans += B[L];
      if (i >= L) {
        ans -= b[i];
      }
    } else {
      ans += A[L];
      if (i >= L) {
        ans -= a[i];
      }
    }
    cout << ans << " \n"[i + 1 == k];
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