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
  rep(i, n) {
    cin >> a[i];
  }
  
  vi S(n+1); rep(i, n) S[i+1] = S[i]^a[i];
  vc<array<int, 30>> s(n + 2);
  rep(i, n + 1) {
    rep(j, 30) {
      s[i + 1][j] = s[i][j] + (S[i] >> j & 1);
    }
  }
  // rep(i,n){
  //   int c=0;
  //   rep(j,i+1){
  //     rep(k,i+1,n+1){
  //       if((S[j]^S[k]^a[i]) > (S[j]^S[k])){
  //         c++;
  //         // debug(i,j,k-1);
  //       }
  //     }
  //   }
  //   debug(i,c);
  // }
  // debug(S);
  ll ans = 0;
  rep(i, n) {
    int hi = 0;
    rep(j, 30) if (a[i] >> j & 1) hi = j;
    ll l1 = s[i + 1][hi];
    ll r1 = s[n + 1][hi] - s[i + 1][hi];
    ll l0 = (i + 1) - l1;
    ll r0 = (n - i) - r1;
    ans += l0 * r0 + l1 * r1;
    // debug(l0, r1, l1, r0);
    // debug(i, l0 * r0 + l1 * r1);
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