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
  int n;
  cin >> n;
  vl l(n), r(n);
  rep(i, n) { cin >> l[i] >> r[i]; }

  int ori_n = n;
  rep(rot, 2) {
    map<ll, vl> mp;
    rep(i, n) mp[l[i]].pb(r[i]);
    vl new_l, new_r;
    auto it = mp.begin();
    multiset<ll> s;
    ll T = -LNF;
    while (true) {
      if (s.empty()) {
        if (it == mp.end()) {
          break;
        }
        T = it->first;
      }
      while (it != mp.end() && T == it->fi) {
        s.insert(it->se.begin(), it->se.end());
        it++;
      }
      assert(!s.empty());
      new_l.pb(T);
      new_r.pb(*s.begin());
      s.erase(s.begin());
      T += 1;
      while (!s.empty() && *s.begin() < T) {
        s.erase(s.begin());
      }
    }
    l.swap(new_l);
    r.swap(new_r);
    n = l.size();
    rep(i, n) {
      l[i] = -l[i];
      r[i] = -r[i];
      swap(l[i], r[i]);
    }
  }
  sort(all(l));
  sort(all(r));
  vl ans(ori_n + 1);
  ll lx = -LNF, rx = -LNF;
  int pl = 0;
  int pr = 0;
  int k = 0;
  while (true) {
    if (pl == n && pr == n) {
      break;
    }
    ll wl = pl < n ? l[pl] - lx : LNF;
    ll wr = pr < n ? r[pr] - rx : LNF;
    ll wait = min(wl, wr);
    ans[k] += wait;
    lx += wait;
    rx += wait;
    while (pl < n && l[pl] == lx) {
      k++;
      lx++;
      pl++;
    }
    while (pr < n && r[pr] == rx) {
      ans[k] += 1;
      k--;
      rx++;
      pr++;
    }
  }

  for (int i = n; i >= 1; i--) {
    ans[i - 1] += ans[i];
  }
  for (int i = 1; i <= ori_n; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}