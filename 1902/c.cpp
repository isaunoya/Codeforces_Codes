#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
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
#define fi first
#define se second

void solve() {
  int n;
  cin >> n;
  vc<ll> a(n);
  rep(i, n) cin >> a[i];
  if (n == 1) {
    cout << "1\n";
    return;
  }
  ll g = 0;
  rep(i, n - 1) g = gcd(g, abs(a[i] - a[i + 1]));
  // debug(g);
  map<ll, bool> mp;
  rep(i, n) mp[a[i]] = 1;
  auto solve = [&](ll x) {
    // debug(x);
    vc<ll> b = a;
    b.pb(x);
    return (1ll * b.size() * (*max_element(all(b))) - accumulate(all(b), 0LL)) / g;
  };
  ll p = *max_element(all(a));
  // debug(p, g);
  while (mp[p]) {
    p -= g;
  }
  ll ans1 = solve(p);
  // debug(p, ans1);
  p = *max_element(all(a));
  while (mp[p]) {
    p += g;
  }
  ll ans2 = solve(p);
  cout << min(ans1, ans2) << "\n";
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