#include <bits/stdc++.h>
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define pb emplace_back
using namespace std;
#define int long long
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

template <class T> std::vector<int> z_algorithm(const std::vector<T> &s) {
  int n = (int)(s.size());
  if (n == 0)
    return {};
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    int &k = z[i];
    k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
    while (i + k < n && s[k] == s[i + k])
      k++;
    if (j + z[j] < i + z[i])
      j = i;
  }
  z[0] = n;
  return z;
}
std::vector<int> z_algorithm(const std::string &s) {
  int n = s.length();
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return z_algorithm(s2);
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int pos = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'a') {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    cout << n - 1 << '\n';
    return;
  }
  int sum0 = pos;
  reverse(s.begin(), s.end());
  int tot = sum0;
  while (tot--)
    s.pop_back();
  reverse(s.begin(), s.end());
  n = s.length();
  vector<int> p;
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'a')
      p.emplace_back(i);
  }
  tot = p.size();

  auto z = z_algorithm(s);
  // cout<<s<<endl;
  long long ans = 0;
  for (int len = 1; len <= n; ++len) {
    bool ok = 1;
    long long sum = sum0;
    int r = len - 1;
    while (1) {
      int it = upper_bound(p.begin(), p.end(), r) - p.begin();
      if (it >= tot) {
        ans += sum + 1;
        break;
      }
      it = p[it];
      if (it + len - 1 >= n)
        break;

      sum = min(sum, it - r - 1);
      if (z[it] < len)
        break;

      r = it + len - 1;
    }
  }
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}