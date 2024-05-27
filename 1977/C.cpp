#include <algorithm>
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
  vl a(n);
  rep(n) cin >> a[i];
  sort(all(a));
  ll L = 1;
  rep(n) {
    L = lcm(L, a[i]);
    if (L > a.back())
      break;
  }
  if (L > a.back()) {
    cout << n << "\n";
    return;
  }
  ll M=a.back();
  vi d;
  for(int i=1;1ll*i*i<=M;i++){
    if(M%i==0){
      d.pb(i);
      d.pb(M/i);
    }
  }
  auto get=[&](int d){
    if(binary_search(all(a),d))return 0;
    ll cur=1;
    int cnt=0;
    for(auto ai:a){
      if(d%ai==0){
        cur=lcm(cur,ai);
        cnt+=1;
      }
    }
    if(cur==d){
      return cnt;
    }else {
      return 0;
    }
  };
  int ans=0;
  for(auto i:d){
    cmax(ans,get(i));
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