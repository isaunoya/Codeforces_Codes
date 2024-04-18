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

const int B = 2500;
void solve() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  rep(k, B) {
    rep(i, n) {
      int x = a[i], y = a[(i + 1) % n];
      y = max(0, y - x);
      a[(i + 1) % n] = y;
    }
  }
  // debug(a);
  int zero = -1;
  rep(i, n) if (a[i] == 0) zero = i;
  rep(i, zero) {
    int x = a[i], y = a[(i + 1) % n];
    y = max(0, y - x);
    a[(i + 1) % n] = y;
  }
  assert(zero != -1);
  int shift = zero;
  vi b(n);
  rep(i, n) b[i] = a[(i + shift) % n];
  for (int i = 0, j = 0; i < n; i = j) {
    if (b[i] == 0) {
      j = i + 1;
      continue;
    }
    while (j < n && b[j]) {
      j++;
    }
    if (j - i == 1) {
      continue;
    }
    if (j - i == 2) {
      b[i + 1] = 0;
      continue;
    }
    if (j - i == 3) {
      int t = b[i + 1] / b[i];
      int rem = b[i + 1] % b[i];
      int L = rem;
      int R = rem + (t - 1) * b[i];
      ll sum = 1ll * (L + R) * t / 2;
      if (sum >= b[i + 2]) {
        b[i + 2] = 0;
      }
      b[i + 1] = 0;
      continue;
    }
  }
  vi ans;
  rep(i, n) if (b[i]) ans.pb((i + shift) % n);
  sort(all(ans));
  cout << sz(ans) << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
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