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
  int N; cin >> N;
  vi A(N); rep(N) cin >> A[i];
  // int N = 5; vi A(N); rep(N) A[i] = rand() % 7 + 1;
  ll cur = 0;
  ll ANS = 0;
  for (int i = N - 1; i >= 0; i--) {
    cmax(ANS, cur + A[i] + i);
    if (i > 0 && A[i - 1] <= A[i]) {
      cur += A[i] - A[i - 1] + 1;
    } else {
      cur = 0;
    }
  }
  cout << ANS << "\n";

  // debug(A);
  // {
  //   int l = 0;
  //   while (true) {
  //     bool ok = true;
  //     rep(N) if (A[i]) ok = false;
  //     if (ok) break;
  //     rep(N) if (i + 1 == N || A[i] > A[i + 1]) A[i] = max(A[i] - 1, 0);
  //     l += 1;
  //   }
  //   debug(ANS, l);
  // }
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