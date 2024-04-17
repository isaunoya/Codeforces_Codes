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

int dp[205][205][205];
int dfs(int a,int b,int c){
  if(a<0||b<0||c<0){
    return 0;
  }
  if(dp[a][b][c]!=-1){
    return dp[a][b][c];
  }
  int x=0;
  if(a%2)x^=1;
  if(b%2)x^=2;
  if(c%2)x^=3;
  int v=(x==0);
  dp[a][b][c]=max({dfs(a,b,c-1),dfs(a,b-1,c),dfs(a-1,b,c)})+v;
  return dp[a][b][c];
}

void solve() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(d%2)d--;
  int ans=0;
  ans+=d/2;
  cout<<ans+dfs(a,b,c)<<"\n";
}

int main() {
  memset(dp,-1,sizeof dp);
  dp[0][0][0]=0;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}