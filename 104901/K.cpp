#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
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

template <typename T> struct Fenwick {
  int n;
  std::vector<T> a;

  Fenwick(int n = 0) { init(n); }

  void init(int n) {
    this->n = n;
    a.assign(n, T());
  }

  void add(int x, T v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
    }
  }

  T sum(int x) {
    auto ans = T();
    for (int i = x; i > 0; i -= i & -i) {
      ans += a[i - 1];
    }
    return ans;
  }

  T rangeSum(int l, int r) { return sum(r) - sum(l); }

  int kth(T k) {
    int x = 0;
    for (int i = 1 << std::__lg(n); i; i /= 2) {
      if (x + i <= n && k >= a[x + i - 1]) {
        x += i;
        k -= a[x - 1];
      }
    }
    return x;
  }
};

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  vl a(n), d;
  rep(i, n) {
    cin >> a[i];
    a[i] -= i;
    d.pb(a[i]);
  }
  sort(all(d));
  d.resize(unique(all(d)) - begin(d));
  // debug(a, d);
  vl b = a;
  for (auto &bi : b) {
    bi = lower_bound(all(d), bi) - begin(d);
  }
  int m = sz(d);
  Fenwick<ll> sum(m), cnt(m);
  int r = 0;
  auto add = [&](int pos) {
    sum.add(pos, d[pos]);
    cnt.add(pos, 1);
  };
  auto pop = [&](int pos) {
    sum.add(pos, -d[pos]);
    cnt.add(pos, -1);
  };

  int ans = 1;
  rep(l, n) {
    auto get = [&]() -> ll {
      int sz = r - l;
      if (sz < 1) {
        return 0;
      }
      int w = cnt.kth(sz / 2);
      // debug(l, r, d[w]);
      ll v = d[w];
      ll cost = 0;
      cost += sum.rangeSum(w, m) - v * cnt.rangeSum(w, m);
      cost -= sum.rangeSum(0, w) - v * cnt.rangeSum(0, w);
      return cost;
    };
    while (r < n) {
      add(b[r]);
      if (get() <= k) {
        r++;
      } else {
        pop(b[r]);
        break;
      }
    }
    // debug(l, r, get());
    cmax(ans, r - l);
    pop(b[l]);
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