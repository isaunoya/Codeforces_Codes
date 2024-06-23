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

vi divisor[500001];

void solve() {
  int n = 500000;
//   cin >> n;
  vc<map<int, int>> v(n + 1), f(n + 1);
  vi occ(n + 1), A(n + 1), B(n + 1);
  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    int pi;
    // cin >> pi;
    if (i == 1) pi = n;
    else pi = i - 1;
    int a = pi / gcd(i, pi);
    int b = i / gcd(i, pi);
    v[a][b] += 1;
    occ[b] = 1;
    if (a % b == 0) {
      ans--;
    }
    A[i] = a;
    B[i] = b;
  }

  for (int i = 1; i <= n; i++) {
    int a = A[i];
    int b = B[i];
    for (int c : divisor[a])
      if (occ[c])
        f[b][c] += 1;
  }

  for (int a = 1; a <= n; a++) {
    for (int c : divisor[a]) {
      for (auto [b, c1] : v[a]) {
        if (f[c].count(b)) {
          ans += 1ll * c1 * f[c][b];
        }
      }
    }
  }

  // {
  //   int tot = 0; rep(n + 1) tot += sizeof(f[i]) + sizeof(v[i]);
  //   debug(tot / 1048576.);
  // }

  cout << ans / 2 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < 500001; i++) {
    for (int j = i; j < 500001; j += i) {
      divisor[j].pb(i);
    }
  }

  int t = 1;
//   cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
