/*
 * temp.cc
 * written by retired_user
 * 2022-08-04 22:36:25
*/
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
template<typename T> void cmin(T &x, const T &y) { if (x > y) x = y; }
template<typename T> void cmax(T &x, const T &y) { if (x < y) x = y; }
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
#define rev(x) reverse(all(x))

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 2 << "\n";
    } else if (n == 2) {
      cout << 1 << "\n";
    } else if (n == 4) {
      cout << 2 << "\n";
    } else if (n % 3 == 0) {
      cout << n / 3 << "\n";
    } else if (n % 3 == 1) {
      cout << n / 3 + 1 << "\n";
    } else if (n % 3 == 2) {
      cout << n / 3 + 1 << "\n";
    }
  }
  return 0; 
}