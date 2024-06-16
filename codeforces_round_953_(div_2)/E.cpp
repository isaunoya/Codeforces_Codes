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
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;

  vi a(N);
  rep(i, N) a[i] = s[i] - '0';
  vi b(N);
  rep(i, N) b[i] = t[i] - '0';
  vi d = b;
  rep(i, N - 2) d[i + 1] = b[i + 1] | ((a[i] ^ 1) & (a[i + 2] ^ 1));
  vi c = a;
  rep(i, N - 2) c[i + 1] = a[i + 1] | (d[i] & d[i + 2]);

  // debug(c);
  vi SUM(N + 1);
  rep(i, N) SUM[i + 1] = SUM[i] + c[i];
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l;
    int cur = SUM[r] - SUM[l];
    vector<int> p;
    for (int i = l - 3; i <= l + 3; i++)
      p.push_back(i);
    for (int i = r - 4; i <= r + 2; i++)
      p.push_back(i);
    for (int i : p) {
      if (0 <= i && i + 2 < N) {
        int p1 = 1;
        if (l <= i && i < r) {
          p1 = a[i];
        }
        int p2 = 1;
        if (l <= i + 2 && i + 2 < r) {
          p2 = a[i + 2];
        }
        d[i + 1] = b[i + 1] | ((p1 ^ 1) & (p2 ^ 1));
      }
    }
    for (int i : p) {
      if (0 <= i && i + 2 < N) {
        if (l <= i + 1 && i + 1 < r)
          cur -= c[i + 1];
        int p1 = 0;
        int p2 = 0;
        if (l <= i && i < r) {
          p1 = d[i];
        }
        if (l <= i + 2 && i + 2 < r) {
          p2 = d[i + 2];
        }
        c[i + 1] = a[i + 1] | (p1 & p2);
        if (l <= i + 1 && i + 1 < r)
          cur += c[i + 1];
      }
    }
    cout << cur << "\n";
    for (int i : p) {
      if (0 <= i && i + 2 < N) {
        d[i + 1] = b[i + 1] | ((a[i] ^ 1) & (a[i + 2] ^ 1));
      }
    }
    for (int i : p) {
      if (0 <= i && i + 2 < N) {
        c[i + 1] = a[i + 1] | (d[i] & d[i + 2]);
      }
    }
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