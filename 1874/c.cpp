#include <bits/stdc++.h>
#include <iomanip>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep1(a) for (int i = 0; i < a; i++)
#define rep2(i, a) for (int i = 0; i < a; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
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
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int N = 5005;
double prob[N][N];
void solve() {
  int n, m;
  cin >> n >> m;
  vc<vi> e(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    e[x].pb(y);
  }
  vc<double> f(n);
  f[n - 1] = 1;
  for (int i = n - 1; i >= 0; i--) {
    vc<double> p;
    for (auto j : e[i]) {
      p.pb(f[j]);
    }
    sort(all(p), greater<double>());
    for (int j = 0; j < sz(p); j++) {
      f[i] += p[j] * prob[sz(p)][j + 1];
    }
  }
  cout << fixed << setprecision(20) << f[0] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < N; i += 2) {
    for (int j = 1; j <= i; j++) {
      prob[i][j] = 1. / i;
    }
  }
  prob[2][1] = .5;
  for (int i = 4; i < N; i++) {
    prob[i][1] = 1. / i;
    for (int j = 2; j < i; j++) {
      prob[i][j] = (1. * (j - 2) * prob[i - 2][j - 2] +
                    1. * (i - j) * prob[i - 2][j - 1]) /
                   i;
    }
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}