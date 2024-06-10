#include <bits/stdc++.h>
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

const int P = 998244353;
const int inv2 = (P + 1) / 2;

const int MN = 2e5 + 5;
ll dp[MN][2];

void solve() {
  int N;
  cin >> N;
  rep(i, N + 1) dp[i][0] = dp[i][1] = 0;
  ll mn = 0, mx = 0;
  dp[0][0] = dp[0][1] = 1;
  rep(i, N) {
    int x;
    cin >> x;
    ll mn2 = mn + x;
    ll mx2 = abs(mn + x);
    cmax(mx2, mx + x);

    for (int j = 0; j < 2; j++) {
      {
        ll v = mn + x;
        if (j)
          v = abs(v);
        if (v == mn2)
          dp[i + 1][0] += dp[i][0];
        if (v == mx2)
          dp[i + 1][1] += dp[i][0];
      }
      if (mx != mn) {
        ll v = mx + x;
        if (j)
          v = abs(v);
        if (v == mn2)
          dp[i + 1][0] += dp[i][1];
        if (v == mx2)
          dp[i + 1][1] += dp[i][1];
      }
    }
    dp[i + 1][0] %= P;
    dp[i + 1][1] %= P;
    swap(mn, mn2);
    swap(mx, mx2);
  }
  cout << dp[N][1] << "\n";
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