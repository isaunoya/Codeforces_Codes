#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
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
  vector<pair<int, int>> a(n);

  for (auto &[x, y] : a)
    cin >> x >> y;
  sort(a.begin(), a.end());

  vector<int> t;
  for (int i = 0; i < n; i++)
    t.push_back(a[i].first), t.push_back(a[i].second);
  sort(t.begin(), t.end());
  t.resize(unique(t.begin(), t.end()) - t.begin());

  for (auto &[x, y] : a) {
    x = lower_bound(t.begin(), t.end(), x) - t.begin();
    y = lower_bound(t.begin(), t.end(), y) - t.begin();
  }

  vector<int> w(t.size(), -1);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (a[i].second >= a[j].first) {
        int p = max(a[i].second, a[j].second);
        w[p] = max(w[p], a[i].first);
      }
    }

  int l = (int)t.size();
  int las = -1;
  int c = 0;
  for (int i = 0; i < l; i++) {
    if (w[i] > las) {
      c++;
      las = i;
    }
  }
  cout << n - 2 * c << "\n";
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