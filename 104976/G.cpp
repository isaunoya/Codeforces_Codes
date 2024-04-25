#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  auto get_id = [&](int x, int y) { return x * m + y; };
  auto get = [&](int id) { return make_pair(id / m, id % m); };
  vector<int> to_tail(n * m);
  vector<pair<int, int>> snake(k);
  vector<int> sid;
  sid.reserve(k);
  for (auto &si : snake) {
    cin >> si.first >> si.second;
    --si.first;
    --si.second;
    sid.emplace_back(get_id(si.first, si.second));
    to_tail[get_id(si.first, si.second)] = k - sid.size();
  }
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  vector<bool> vis(n * m);
  vector<vector<int>> pot(2 * n * m);
  vis[sid[0]] = 1;
  pot[0].emplace_back(sid[0]);
  for (int d = 0; d < 2 * n * m; d++) {
    for (auto u : pot[d]) {
      auto [x, y] = get(u);
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx * dx + dy * dy == 1) {
            int nx = x + dx;
            int ny = y + dy;
            int v = get_id(nx, ny);
            if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) {
              continue;
            }
            if (grid[nx][ny] == '#') {
              continue;
            }
            if (vis[v]) {
              continue;
            }
            vis[v] = 1;
            if (to_tail[v] == -1) {
              pot[d + 1].emplace_back(v);
            } else {
              pot[max(d, to_tail[v]) + 1].emplace_back(v);
            }
          }
        }
      }
    }
  }

  unsigned long long ans = 0;
  for (int i = 0; i < 2 * n * m; i++) {
    ans += (unsigned long long)pot[i].size() * i * i;
  }
  cout << ans << "\n";
}