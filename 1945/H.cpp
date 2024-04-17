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

const int all = (1 << 30) - 1;
void solve() {
  int n, X;
  cin >> n >> X;
  int m = 0;
  vi a(n);
  for (auto &ai : a) {
    cin >> ai, cmax(m, ai);
  }
  int t = 1, l = 0;
  while (t <= m) {
    t *= 2, l++;
  }
  vi c(t);
  for (auto ai : a)
    c[ai]++;
  auto cnt = c;
  rep(j, l) {
    rep(i, t) {
      if (~i >> j & 1)
        c[i] += c[i ^ 1 << j];
    }
  }
  // debug(c);
  int must = 0;
  rep(i, t) {
    if (c[i] == n) {
      must = i;
    }
  }
  // debug(must);
  vi where[2];
  rep(i, must, t) {
    if (c[i] != n && c[i] >= n - 2)
      where[n - 1 - c[i]].pb(i);
  }
  reverse(all(where[0]));
  reverse(all(where[1]));
  // debug(where[0], where[1]);
  sort(all(a));
  vi pre(n + 1);
  vi suf(n + 1);
  pre[0] = suf[n] = all;
  rep(i, n) { pre[i + 1] = pre[i] & a[i]; }
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] & a[i];
  }
  rep(i, n - 1) {
    if (a[i] == a[i + 1]) {
      int and_sum = pre[i] & suf[i + 2];
      if (a[i] > and_sum + X) {
        cout << "YES\n";
        cout << 2 << " " << a[i] << " " << a[i + 1] << "\n";
        cout << n - 2 << " ";
        rep(j, n) if (j != i && j != i + 1) cout << a[j] << " ";
        cout << "\n";
        return;
      }
    }
  }
  vi ad(t * 2);
  rep(i, t) {
    if (cnt[i])
      ad[i + t] = i;
    else
      ad[i + t] = all;
  }
  for (int i = t - 1; i >= 1; i--) {
    ad[i] = ad[i * 2] & ad[i * 2 + 1];
  }
  auto upd = [&](int x, int v) {
    x += t;
    ad[x] = v;
    x /= 2;
    while (x) {
      ad[x] = ad[x * 2] & ad[x * 2 + 1];
      x /= 2;
    }
  };
  auto print = [&](int x, int y) {
    int ban_x = 1, ban_y = 1;
    cout << "YES\n";
    cout << 2 << " " << x << " " << y << "\n";
    cout << n - 2 << " ";
    for (int ai : a) {
      if (ai == x && ban_x) {
        ban_x = 0;
        continue;
      } else if (ai == y && ban_y) {
        ban_y = 0;
        continue;
      }
      cout << ai << " ";
    }
    cout << "\n";
  };
  int j[2];
  j[0] = j[1] = 0;
  for (int d = X + must + 1; d <= m; d++) {
    while (j[0] < (int)where[0].size() && where[0][j[0]] >= d - X) {
      j[0]++;
    }
    while (j[1] < (int)where[1].size() && where[1][j[1]] >= d - X) {
      j[1]++;
    }
    // debug(d, j[0], j[1]);
    vi may;
    for (int i = d; i <= m && may.size() < 22; i += d)
      if (cnt[i]) 
        may.pb(i);
    // debug(d, may);
    for (int i : may) {
      if (cnt[i] == 1) {
        upd(i, all);
      }
      for (int j : may) {
        if (i == j) {
          continue;
        }
        if (cnt[j] == 1) {
          upd(j, all);
        }
        if (d > ad[1] + X) {
          print(i, j);
          return;
        }
        if (cnt[j] == 1) {
          upd(j, j);
        }
      }
      if (cnt[i] == 1) {
        upd(i, i);
      }
    }
  }
  cout << "NO\n";
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