#include <bits/stdc++.h>
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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (count(all(s), '0') != count(all(s), '1')) {
    cout << "-1\n";
    return;
  }
  vi ans;
  for (int l = 0, r = n - 1; l < r; l++, r--) {
    if (s[l] != s[r])
      continue;
    if (s[l] == '0') {
      ans.pb(r + 1);
      s.insert(s.begin() + r + 1, '1');
      s.insert(s.begin() + r + 1, '0');
      r += 2;
    } else {
      ans.pb(l);
      s.insert(s.begin() + l, '1');
      s.insert(s.begin() + l, '0');
      r += 2;
    }
  }
  int sz = sz(ans);
  cout << sz << "\n";
  rep(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
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