#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 42
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define rp(i, n) rep(i, 0, n)
#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

void solve() {
  int n, a, q;
  cin >> n >> a >> q;
  int b=a,mx=a;
  rp(i,q){
    char c;
    cin>>c;
    if(c=='-')a--;
    if(c=='+')a++,b++;
    cmax(mx,a);
  }
  if(mx==n){
    cout<<"YES\n";
  }else if(b>=n){
    cout<<"MAYBE\n";
  }else{
    cout<<"NO\n";
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