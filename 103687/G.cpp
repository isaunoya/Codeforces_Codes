#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<long long, long long>> p(n);
  for (auto &pi : p) {
    cin >> pi.first >> pi.second;
  }

  pair<long long, long long> S, T;
  cin >> S.first >> S.second >> T.first >> T.second;

  auto dist = [&](pair<long long, long long> a, pair<long long, long long> b) {
    auto [x0, y0] = a;
    auto [x1, y1] = b;
    return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
  };

  long long v0, v1;
  cin >> v0 >> v1;

  double ans = 1. * sqrt(dist(S, T)) / v0;
  vector<bool> vis(n);
  vector<double> dis(n);
  for (int i = 0; i < n; i++) {
    dis[i] = 1ll * sqrt(dist(S, p[i])) / v0;
  }
  while (true) {
    int k = -1;
    for (int i = 0; i < n; i++) {
      if (vis[i]) {
        continue;
      }
      if (k == -1) {
        k = i;
      } else if (dis[i] < dis[k]) {
        k = i;
      }
    }
    if (k == -1) {
      break;
    }
    vis[k] = 1;
    for (int i = 0; i < n; i++) {
      if (vis[i]) {
        continue;
      }
      double len = sqrt(dist(p[k], p[i]));
      double cost = 0.;
      if (len < 3 * v1) {
        cost = len / v1;
      } else {
        cost = 3 + 1. * (len - 3 * v1) / v0;
      }
      dis[i] = min(dis[i], dis[k] + cost);
    }
  }
  for (int i = 0; i < n; i++) {
    double len = sqrt(dist(p[i], T));
    double cost = 0.;
    if (len < 3 * v1) {
      cost = len / v1;
    } else {
      cost = 3 + 1. * (len - 3 * v1) / v0;
    }
    ans = min(ans, dis[i] + cost);
  }

  cout << setprecision(7) << ans << "\n";
}