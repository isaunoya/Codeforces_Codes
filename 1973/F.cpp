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
  int n, q;
  cin >> n >> q;
  vc<pii> a(n);
  for (auto &ai : a) {
    cin >> ai.first;
  }
  for (auto &ai : a) {
    cin >> ai.second;
  }

  vi c(n);
  for (auto &ci : c) {
    cin >> ci;
  }

  ll all = 0;
  for (auto &ci : c) {
    all += ci;
  }

  auto division = [&](int x) {
    vi d;
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        d.pb(i);
        if (x / i != i) {
          d.pb(x / i);
        }
      }
    }
    return d;
  };

  vi p(n);
  iota(all(p), 0);
  shuffle(all(p), rng);

  vi d1 = division(a[0].fi);
  vi d2 = division(a[0].se);
  map<int, ll> cost;

  auto solve = [&](int X, int Y) {
    ll s = 0;
    vi re;
    int ok = 1;
    for (int i : p) {
      if (a[i].fi % X == 0 && a[i].se % Y == 0) {
        continue;
      }
      s += c[i];
      swap(a[i].fi, a[i].se);
      re.pb(i);
      if (a[i].fi % X != 0 || a[i].se % Y != 0) {
        ok = 0;
        break;
      }
    }

    for (int i : re) {
      swap(a[i].fi, a[i].se);
    }

    if (ok) {
      return min(s, all - s);
    } else {
      return LNF;
    }
  };
  for (int i : d1) {
    for (int j : d2) {
      ll cur = solve(i, j);
      if (cur == LNF) {
        continue;
      }
      if (cost.count(i + j)) {
        cmin(cost[i + j], cur);
      } else {
        cost[i + j] = cur;
      }
    }
  }
  for (int i : d1) {
    for (int j : d2) {
      ll cur = solve(j, i);
      if (cur == LNF) {
        continue;
      }
      if (cost.count(i + j)) {
        cmin(cost[i + j], cur);
      } else {
        cost[i + j] = cur;
      }
    }
  }
  // debug(cost);
  vc<pll> w(all(cost));
  reverse(all(w));
  vc<pll> W;
  for (auto [x, y] : w) {
    if (W.empty()) {
      W.pb(y, x);
    } else {
      if (y > (ll)W.back().fi) {
        continue;
      } else {
        W.pb(y, x);
      }
    }
  }
  reverse(all(W));
  // debug(W);
  while (q--) {
    ll d;
    cin >> d;
    int P = --upper_bound(all(W), make_pair(d, LNF)) - begin(W);
    cout << W[P].se << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}