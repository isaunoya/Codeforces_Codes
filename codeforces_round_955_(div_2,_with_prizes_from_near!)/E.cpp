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

#include <atcoder/modint>
using mint = atcoder::modint1000000007;
using info = array<mint, 4>;

info ans[64][64]{};
// cnt, l, r, len

info merge(const info &a, const info &b) {
  info c;
  c[0] = a[0] + b[0] + a[2] * b[1];
  c[1] = a[1] + (a[1] == a[3] ? b[1] : 0);
  c[2] = b[2] + (b[2] == b[3] ? a[2] : 0);
  c[3] = a[3] + b[3];
  return c;
}

void solve() {
  ll N, K;
  cin >> N >> K;
  info ANS = {0, 0, 0, 0};
  for (int i = 62; i >= 0; i--) {
    ll cur = 1ll << i;
    if (N >= cur) {
      ANS = merge(ANS, ans[i][K]);
      N -= cur;
      K -= 1;
      if (K < 0) {
        break;
      }
    }
  }

  cout << ANS[0].val() << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  rep(i, 64) {
    ans[0][i] = info{1, 1, 1, 1};
  }

  rep(i, 1, 64) {
    rep(j, 0, 64) {
      info a = ans[i - 1][j];
      info b = (j == 0 ? info{0, 0, 0, 1LL << (i - 1)} : ans[i - 1][j - 1]);
      ans[i][j] = merge(a, b);
    }
  }

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}