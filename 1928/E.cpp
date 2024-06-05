#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h" // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) 42
#define debug_assert(...) 42
#endif

const int INF = 1e9;

void solve() {
  long long n, x, y, s;
  cin >> n >> x >> y >> s;

  long long at_least = x + (x % y) * (n - 1);
  if (s < at_least) {
    cout << "NO\n";
    return;
  }
  // s >= at_least

  long long rem = s - at_least;
  if (rem % y) {
    cout << "NO\n";
    return;
  }

  long long sum = rem / y;

  long long t = 1;
  while (1ll * t * (t + 1) / 2 < sum) {
    t++;
  }

  vector<long long> dis(sum + 1, INF);
  vector<long long> pre(sum + 1, -1);
  vector<long long> wt(sum + 1, -1);

  dis[0] = 0;
  for (int i = t; i >= 0; i--) {
    long long weight = i * (i + 1) / 2;
    int sz = i + 1;
    for (int i = weight; i <= sum; i++) {
      if (dis[i] > dis[i - weight] + sz) {
        dis[i] = dis[i - weight] + sz;
        pre[i] = sz;
        wt[i] = weight;
      }
    }
  }

  int per = x % y;
  long long cur = at_least;
  long long now = x;
  for (int i = 1; i <= n; i++) {
    long long S = s - cur;
    if (S < 0) {
      break;
    }
    S /= y;
    if (dis[S] <= n - i) {
      cout << "YES\n";
      long long X = S;
      vector<long long> res;
      while (X) {
        res.push_back(pre[X]);
        X -= wt[X];
      }
      long long t = n - i - dis[S];
      while (t--) {
        res.push_back(1);
      }
      vector<long long> ans;
      for (int j = 1; j <= i; j++) {
        ans.push_back(x + (j - 1) * y);
      }
      long long tmp = x;
      for (int j : res) {
        tmp %= y;
        ans.push_back(tmp);
        for (int k = 0; k < j - 1; k++) {
          tmp += y;
          ans.push_back(tmp);
        }
      }
      for (int j : ans) {
        cout << j << " ";
      }
      cout << "\n";
      return;
    }
    now += y;
    cur += now - per;
  }

  cout << "NO\n";
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