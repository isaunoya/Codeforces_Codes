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
  int N, K;
  cin >> N >> K;
  vi A(N);
  rep(i, N) cin >> A[i], --A[i];
  bitset<1000> S;
  int p = 2;
  while (p <= N) {
    S.flip(A[p - 2]);
    S.flip(A[p - 1]);
    if ((int)S.count() == K) {
      break;
    }
    p += 2;
  }
  if (p > N) {
    int all = N / 2;
    int rem = (int)S.count() / 2;
    // all even
    cout << all - rem << "\n";
    return;
  }

  vc<vi> layer(N, vi(N, -1));
  vi dp(N + 1, INF);
  dp[p] = 1;

  int ans = 0;
  for (int i = p; i <= N; i++) {
    if (dp[i] < INF) {
      S.reset();
      int cnt = 0;
      for (int j = i + 2; j <= N; j += 2) {
        S.flip(A[j - 2]);
        S.flip(A[j - 1]);
        if ((int)S.count() == 2) {
          int u = S._Find_first();
          int v = S._Find_next(u);
          if (layer[u][v] < i) {
            layer[u][v] = i;
            cmin(dp[j], dp[i] + 1);
            cnt++;
          }
        }
      }
      array<bool, 3> C{};
      rep(u, K) {
        int fu = S.test(u);
        rep(v, u + 1, K) if (layer[u][v] < i) {
          int fv = S.test(v);
          C[fu + fv] = 1;
        }
      }
      int pc = S.count();
      rep(c, 3) if (C[c]) {
        cmax(ans, N / 2 - dp[i] - (K - (pc + 2 - 2 * c)) / 2);
      }
    }
  }

  cout << ans << "\n";
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