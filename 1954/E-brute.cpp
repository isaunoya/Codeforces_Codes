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
  vi A(n);
  rep(i, n) cin >> A[i];
  int mx = 0;
  rep(i, n) cmax(mx, A[i]);
  for (int k = 1; k <= mx; k++) {
    vi a = A;
    int ans = 0;
    while (true) {
      int p = -1;
      rep(i, n) {
        if (a[i] <= 0)
          continue;
        if (p == -1 || a[i] < a[p]) {
          p = i;
        }
      }
      if (p == -1) {
        break;
      }
      ans++;
      int i = p - 1;
      while (i >= 0) {
        if (a[i] <= 0) {
          break;
        }
        a[i] -= k;
        i--;
      }
      int j = p + 1;
      while (j < n) {
        if (a[j] <= 0) {
          break;
        }
        a[j] -= k;
        j++;
      }
      a[p] -= k;
    }
    cout << ans << " \n"[k == mx];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}