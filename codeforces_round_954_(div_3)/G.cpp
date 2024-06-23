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

vi divisor[500001];

void solve() {
  int N;
  cin >> N;
  vc<vi> atX(N + 1), atY(N + 1);
  ll ans = 0;
  rep(i, 1, N + 1) {
    int pi;
    cin >> pi;
    // if (i == 1) pi = n;
    // else pi = i - 1;
    int a = pi / gcd(i, pi);
    int b = i / gcd(i, pi);

    if (a % b == 0) {
      ans--;
    }
    atX[a].pb(b);
    atY[b].pb(a);
  }

  vi vals(N + 1);
  rep(Y, 1, N + 1) {
    for (int i = Y; i <= N; i += Y) {
      for (auto X : atX[i]) {
        vals[X]++;
      }
    }                             // vals[x] = count of pair(KY/x)
    for (auto X : atY[Y]) {       // (X/Y)
      for (auto x : divisor[X]) { // x is divisor of X
        ans += vals[x];           // (X/Y)*(KY/x)=(X/x)*K is a integer.
      }
    }
    for (int i = Y; i <= N; i += Y) {
      for (auto X : atX[i]) {
        vals[X]--;
      }
    }
  }
  cout << ans / 2 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 1; i < 500001; i++) {
    for (int j = i; j < 500001; j += i) {
      divisor[j].pb(i);
    }
  }

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}