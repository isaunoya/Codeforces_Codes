#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include </algo/debug.h>
#else
#define debug(...) 42
#endif
#define tr(x, v) for (auto &x : v)
#define rp(i, v) for (int i = 0; i < sz(v); i++)
#define rep(i, x, y) for (int i = x; i < y; i++)
#define pr(i, v) for (int i = sz(v) - 1; i >= 0; i--)
#define per(i, x, y) for (int i = x; i > y; i--)
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  if (x > y)
    x = y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  if (x < y)
    x = y;
}
using ll = long long;
using E = vector<vector<int>>;
using EW = vector<vector<array<int, 2>>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define ed(x) end(x)
#define all(x) bg(x), ed(x)
#define lb lower_bound
#define ub upper_bound
#define sort(x) sort(all(x))
#define unique(x) (x).erase(unique(all(x)), x.end())
#define reverse(x) reverse(all(x))
void out(bool t) { cout << (t ? "YES" : "NO") << "\n"; }
template <class T> T max(const vector<T> &v) { return *max_element(all(v)); }
template <class T> T min(const vector<T> &v) { return *min_element(all(v)); }
template <class T> istream &operator>>(istream &is, vector<T> &v) {
  tr(x, v) cin >> x;
  return is;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  if (v.empty()) {
    os << "\n";
  } else {
    rp(i, v) os << v[i] << " \n"[i + 1 == (int)v.size()];
  }
  return os;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> b(n);
  cin >> b;
  int m = 1;
  while ((1 << m) < n)
    m++;
  b.resize(1 << m, 0);
  rep(j, 0, m) rep(i, 0, n) if (i >> j & 1) b[i] ^= b[i ^ 1 << j];
  rep(j, 0, m) rep(i, 0, n) if (~i >> j & 1) b[i] ^= b[i ^ 1 << j];
  b.resize(n), reverse(b);
  cout << b;
  return 0;
}