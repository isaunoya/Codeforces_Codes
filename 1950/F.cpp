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
  int a, b, c;
  cin >> a >> b >> c;
  if (a + 1 == c) {
    vector<int> d(a + b + c, -1);
    auto get = [&](int x) {
      if (x < a) {
        return 2;
      } else if (x < a + b) {
        return 1;
      } else {
        return 0;
      }
    };
    d[0] = 0;
    vector<int> que{0};
    int p = 1;
    rep(i, que.size()) {
      int u = que[i];
      int son = get(u);
      if (son == 2) {
        d[p] = d[u] + 1;
        que.emplace_back(p);
        p += 1;
        d[p] = d[u] + 1;
        que.emplace_back(p);
        p += 1;
      } else if (son == 1) {
        d[p] = d[u] + 1;
        que.emplace_back(p);
        p += 1;
      }
    }
    cout << *max_element(all(d)) << "\n";
  } else {
    cout << -1 << "\n";
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