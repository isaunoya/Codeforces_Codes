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
template <class Info, class Tag> struct LazySegmentTree {
  int n;
  std::vector<Info> info;
  std::vector<Tag> tag;
  LazySegmentTree() : n(0) {}
  LazySegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
  template <class T> LazySegmentTree(std::vector<T> init_) { init(init_); }
  void init(int n_, Info v_ = Info()) { init(std::vector(n_, v_)); }
  template <class T> void init(std::vector<T> init_) {
    n = init_.size();
    info.assign(4 << std::__lg(n), Info());
    tag.assign(4 << std::__lg(n), Tag());
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        info[p] = init_[l];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m, r);
      pull(p);
    };
    build(1, 0, n);
  }
  void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
  void apply(int p, const Tag &v) {
    info[p].apply(v);
    tag[p].apply(v);
  }
  void push(int p) {
    apply(2 * p, tag[p]);
    apply(2 * p + 1, tag[p]);
    tag[p] = Tag();
  }
  void modify(int p, int l, int r, int x, const Info &v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    push(p);
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    pull(p);
  }
  void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return Info();
    }
    if (l >= x && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    push(p);
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }
  Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
  void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
    if (l >= y || r <= x) {
      return;
    }
    if (l >= x && r <= y) {
      apply(p, v);
      return;
    }
    int m = (l + r) / 2;
    push(p);
    rangeApply(2 * p, l, m, x, y, v);
    rangeApply(2 * p + 1, m, r, x, y, v);
    pull(p);
  }
  void rangeApply(int l, int r, const Tag &v) {
    return rangeApply(1, 0, n, l, r, v);
  }
  template <class F> int findFirst(int p, int l, int r, int x, int y, F pred) {
    if (l >= y || r <= x || !pred(info[p])) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findFirst(2 * p, l, m, x, y, pred);
    if (res == -1) {
      res = findFirst(2 * p + 1, m, r, x, y, pred);
    }
    return res;
  }
  template <class F> int findFirst(int l, int r, F pred) {
    return findFirst(1, 0, n, l, r, pred);
  }
  template <class F> int findLast(int p, int l, int r, int x, int y, F pred) {
    if (l >= y || r <= x || !pred(info[p])) {
      return -1;
    }
    if (r - l == 1) {
      return l;
    }
    int m = (l + r) / 2;
    push(p);
    int res = findLast(2 * p + 1, m, r, x, y, pred);
    if (res == -1) {
      res = findLast(2 * p, l, m, x, y, pred);
    }
    return res;
  }
  template <class F> int findLast(int l, int r, F pred) {
    return findLast(1, 0, n, l, r, pred);
  }
};

struct Tag {
  int x = 0;
  void apply(Tag t) { x += t.x; }
};

struct Info {
  int x = 0;
  void apply(Tag t) { x += t.x; }
};
Info operator+(Info a, Info b) { return {std::min(a.x, b.x)}; }

void solve() {
  int n;
  cin >> n;
  vi a(n);
  vc<vi> t(n);

  rep(i, n) { t[i].pb(-1); }
  rep(i, n) {
    cin >> a[i];
    --a[i];
    t[a[i]].pb(i);
  }

  rep(i, n) { t[i].pb(n); }

  LazySegmentTree<Info, Tag> st(n);
  vc<vc<array<int, 3>>> add(n + 1);
  rep(i, n) {
    for (int j = 1; j + 1 < sz(t[i]); j++) {
      int pre = t[i][j - 1];
      int cur = t[i][j];
      int nxt = t[i][j + 1];
      add[pre + 1].push_back({cur, nxt - 1, 1});
      add[cur + 1].push_back({cur, nxt - 1, -1});
    }
  }

  vi f(n);
  rep(i, n) {
    for (auto [x, y, v] : add[i]) {
      st.rangeApply(1, 0, n, x, y + 1, {v});
    }
    int cur = st.findFirst(i, n, [&](const Info &info) { return info.x == 0; });
    if (cur == -1) {
      f[i] = n;
    } else {
      f[i] = cur;
    }
  }
  // debug(f);

  for (int i = n - 2; i >= 0; i--)
    cmin(f[i], f[i + 1]);

  int p = 0;
  int w = 0;
  while (p < n) {
    if (f[p] == n) {
      break;
    }
    w++;
    p = f[p] + 1;
  }

  cout << w << "\n";
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