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
  ll N, C;
  cin >> N >> C;
  vl A(N);
  rep(i, N) cin >> A[i];
  vl pre(N + 1); pre[0] = 0;
  rep(i, N) pre[i + 1] = max(pre[i], A[i]);
  vl suf(N + 1); suf[N] = 0;
  for (int i = N - 1; i >= 0; i--) suf[i] = max(suf[i + 1], A[i]);

  vl sum(N + 1); rep(i, N) sum[i + 1] = sum[i] + A[i];
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      if (A[i] + C >= suf[i + 1]) {
        cout << 0;
      } else {
        cout << 1;
      }
    } else {
      if (A[i] > A[0] + C && pre[i] < A[i] && A[i] >= suf[i + 1]) {
        cout << 0;
      } else {
        ll S = sum[i] + A[i] + C;
        if (S >= suf[i + 1]) {
          cout << i;
        } else {
          cout << i + 1;
        }
      }
    }
    cout << " \n"[i + 1 == N];
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