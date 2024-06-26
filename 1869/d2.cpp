#include <bits/stdc++.h>
#include <unordered_map>
#ifndef LOCAL
#define debug(...)
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

template <class... T> void read() {}
template <class T> void read(T &x) { cin >> x; }
template <class T, class S> void read(pair<T, S> &v) {
  read(v.first, v.second);
}
template <class T> void read(vector<T> &v) {
  for (T &x : v)
    read(x);
}
template <class T, class... Ts> void read(T &a, Ts &...b) {
  read(a), read(b...);
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll s = 0;
  for (int i = 0; i < n; i++) {
    s += a[i];
  }

  if (s % n) {
    cout << "No\n";
    return;
  }
  // debug(s / n);
  ll avg = s / n;
  bool yes = true;
  map<ll, pii> mp;
  rep(i, 31) rep(j, 31) mp[(1ll << i) - (1ll << j)] = pii(i, j);
  vi out(32), up(31), down(31);
  rep(i, n) {
    if (a[i] == avg) { 
      continue;
    }
    if (!mp.count(a[i] - avg)) {
      cout << "No\n";
      return;
    }
    auto [x, y] = mp[a[i] - avg];
    if(abs(x - y) == 1) {
      if (x > y) {
        out[y]++;
        up[y] += 2;
      } else {
        swap(x, y);
        // x>y
        out[y]--;
        down[y] -= 2;
      }
    } else {
      out[x]++;
      out[y]--; 
    }
  }
  rep(i, 31) {
    if (out[i] == 0) {
      continue;
    }
    if (down[i] <= out[i] && out[i] <= up[i]) {
      out[i + 1] += out[i] / 2;
      out[i] = 0;
    }
  }
  rep(i, 31) yes &= out[i] == 0;
  if (yes) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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