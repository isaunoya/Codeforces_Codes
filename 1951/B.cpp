#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
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
  int n, k;
  cin >> n >> k;
  k -= 1;
  vi a(n);
  rep(i, n) { cin >> a[i]; }
  int v = a[k];

  auto run = [&](vi &A, int val) {
    int cnt = 0;
    int cur = A[0];
    rep(i, 1, n) {
      cmax(cur, A[i]);
      if (cur == val) {
        cnt += 1;
      }
    }
    return cnt;
  };

  int ans = run(a, v);
  swap(a[0], a[k]), cmax(ans, run(a, v)), swap(a[0], a[k]);
  swap(a[1], a[k]), cmax(ans, run(a, v)), swap(a[1], a[k]);
  int fir = -1;
  rep(i, n) {
    if (a[i] > v) {
      fir = i;
      break;
    }
  }
  if (fir != -1) {
    swap(a[fir], a[k]), cmax(ans, run(a, v)), swap(a[fir], a[k]);
  }
  cout << ans << "\n";
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