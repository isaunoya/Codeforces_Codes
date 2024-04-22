#include <ratio>
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
mt19937_64 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).siz())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

/*https://www.luogu.com.cn/record/23840086*/
const int N = 1e5 + 10;
const int M = N << 6;
const int m = 1e5 + 1;
int n, q;
unsigned long long sum[M];
int L[M], R[M];
unsigned long long hsh[N];
int a[N], rt[N];

struct node {
  int v;
  int nxt;
};
node e[N << 1];
int head[N];
int fa[N], siz[N], d[N], son[N], top[N];
int cnt = 0;
inline void Add(int u, int v) {
  e[++cnt].v = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
  return;
}
int tot = 0;
inline void Update(int last, int &now, int l, int r, int x) {
  sum[now = ++tot] = sum[last] + hsh[x];
  if (l == r)
    return;
  int mid = l + r >> 1;
  if (x <= mid)
    R[now] = R[last], Update(L[last], L[now], l, mid, x);
  else
    L[now] = L[last], Update(R[last], R[now], mid + 1, r, x);
  return;
}

inline void Dfs(int u) {
  siz[u] = 1;
  Update(rt[fa[u]], rt[u], 1, m, a[u]);
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa[u])
      continue;
    fa[v] = u;
    d[v] = d[u] + 1;
    Dfs(v);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]])
      son[u] = v;
  }
}
inline void Dfs2(int u, int t) {
  top[u] = t;
  if (!son[u])
    return;
  Dfs2(son[u], t);
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v ^ fa[u] && v ^ son[u])
      Dfs2(v, v);
  }
}
inline int Lca(int x, int y) {
  int fx = top[x];
  int fy = top[y];
  while (fx ^ fy) {
    if (d[fx] < d[fy])
      swap(x, y), swap(fx, fy);
    x = fa[fx];
    fx = top[x];
  }
  if (d[x] > d[y])
    swap(x, y);
  return x;
}

vector<int> ans;
int K;
inline void Query(int a, int b, int lca, int lca_fa, int a2, int b2, int lca2,
                  int lca_fa2, int l, int r) {
  if (!K) {
    return;
  }
  if (l == r) {
    ans.emplace_back(l);
    K--;
    return;
  }
  unsigned long long x = sum[L[a]] + sum[L[b]] - sum[L[lca]] - sum[L[lca_fa]];
  unsigned long long y =
      sum[L[a2]] + sum[L[b2]] - sum[L[lca2]] - sum[L[lca_fa2]];
  int mid = l + r >> 1;
  if (x != y)
    Query(L[a], L[b], L[lca], L[lca_fa], L[a2], L[b2], L[lca2], L[lca_fa2], l,
          mid);
  x = sum[R[a]] + sum[R[b]] - sum[R[lca]] - sum[R[lca_fa]];
  y = sum[R[a2]] + sum[R[b2]] - sum[R[lca2]] - sum[R[lca_fa2]];
  if (x != y)
    Query(R[a], R[b], R[lca], R[lca_fa], R[a2], R[b2], R[lca2], R[lca_fa2],
          mid + 1, r);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    head[i] = 0;
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    // debug(a[i], hsh[a[i]]);
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    Add(x, y);
    Add(y, x);
  }
  Dfs(1);
  Dfs2(1, 1);
  cin >> q;
  while (q--) {
    int u1, v1, u2, v2;
    cin >> u1 >> v1 >> u2 >> v2 >> K;
    int lca1 = Lca(u1, v1);
    int fa_lca1 = fa[lca1];
    int lca2 = Lca(u2, v2);
    int fa_lca2 = fa[lca2];
    ans.clear();
    Query(rt[u1], rt[v1], rt[lca1], rt[fa_lca1], rt[u2], rt[v2], rt[lca2],
          rt[fa_lca2], 1, m);
    cout << ans.size() << " ";
    for (int x : ans)
      cout << x << " ";
    cout << "\n";
  }
}

int main() {
  for (int i = 1; i < N; i++) {
    hsh[i] = rng();
  }
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}