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


#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T &t) { payload.push_back(t); }
  T &front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};

} // namespace internal

} // namespace atcoder


namespace atcoder {

template <class Cap> struct mf_graph {
public:
  mf_graph() : _n(0) {}
  mf_graph(int n) : _n(n), g(n) {}

  int add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from == to)
      to_id++;
    g[from].push_back(_edge{to, to_id, cap});
    g[to].push_back(_edge{from, from_id, 0});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
  }
  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result;
    for (int i = 0; i < m; i++) {
      result.push_back(get_edge(i));
    }
    return result;
  }
  void change_edge(int i, Cap new_cap, Cap new_flow) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    assert(0 <= new_flow && new_flow <= new_cap);
    auto &_e = g[pos[i].first][pos[i].second];
    auto &_re = g[_e.to][_e.rev];
    _e.cap = new_cap - new_flow;
    _re.cap = new_flow;
  }

  Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    std::vector<int> level(_n), iter(_n);
    internal::simple_queue<int> que;

    auto bfs = [&]() {
      std::fill(level.begin(), level.end(), -1);
      level[s] = 0;
      que.clear();
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : g[v]) {
          if (e.cap == 0 || level[e.to] >= 0)
            continue;
          level[e.to] = level[v] + 1;
          if (e.to == t)
            return;
          que.push(e.to);
        }
      }
    };
    auto dfs = [&](auto self, int v, Cap up) {
      if (v == s)
        return up;
      Cap res = 0;
      int level_v = level[v];
      for (int &i = iter[v]; i < int(g[v].size()); i++) {
        _edge &e = g[v][i];
        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0)
          continue;
        Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
        if (d <= 0)
          continue;
        g[v][i].cap += d;
        g[e.to][e.rev].cap -= d;
        res += d;
        if (res == up)
          break;
      }
      return res;
    };

    Cap flow = 0;
    while (flow < flow_limit) {
      bfs();
      if (level[t] == -1)
        break;
      std::fill(iter.begin(), iter.end(), 0);
      while (flow < flow_limit) {
        Cap f = dfs(dfs, t, flow_limit - flow);
        if (!f)
          break;
        flow += f;
      }
    }
    return flow;
  }

  std::vector<bool> min_cut(int s) {
    std::vector<bool> visited(_n);
    internal::simple_queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      visited[p] = true;
      for (auto e : g[p]) {
        if (e.cap && !visited[e.to]) {
          visited[e.to] = true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }

private:
  int _n;
  struct _edge {
    int to, rev;
    Cap cap;
  };
  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

} // namespace atcoder


void solve() {
  int n, m;
  cin >> n >> m;
  atcoder::mf_graph<int> f(n * 2 + 2);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    f.add_edge(a, b + n, 1);
  }
  int s = 2 * n;
  int t = 2 * n + 1;
  rep(i, n) {
    f.add_edge(s, i, 1);
    f.add_edge(i + n, t, 1);
  }
  int fl = f.flow(s, t);
  if (fl == n) {
    cout << 0 << "\n";
    return;
  }

  vc<vi> g(n * 2 + 2), rg(n * 2 + 2);
  for (auto e : f.edges()) {
    if (e.flow == 0) {
      int u = e.from, v = e.to;
      g[u].pb(v);
      rg[v].pb(u);
    } else {
      int u = e.to, v = e.from;
      g[u].pb(v);
      rg[v].pb(u);
    }
  }

  vi from_s(n * 2 + 2);
  vi from_t(n * 2 + 2);
  {
    vi que{s};
    from_s[s] = 1;
    rep(i, sz(que)) {
      int u = que[i];
      for (auto v : g[u])
        if (!from_s[v])
          from_s[v] = 1, que.pb(v);
    }
  }
  {
    vi que{t};
    from_t[t] = 1;
    rep(i, sz(que)) {
      int u = que[i];
      for (auto v : rg[u])
        if (!from_t[v])
          from_t[v] = 1, que.pb(v);
    }
  }
  int S = 0, T = 0;
  rep(i, n) if (from_s[i])++ S;
  rep(i, n) if (from_t[i + n])++ T;
  cout << 1ll * S * T << "\n";
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