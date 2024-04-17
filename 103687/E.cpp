#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
// tree_order_statistics_node_update>;
int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, h, s;

  cin >> n >> h >> s;

  vector<ld> p(n);

  for (auto &x : p) {
    cin >> x;
    x /= 100.;
  }

  int k_totem;
  cin >> k_totem;

  vector<bool> totem(n);

  for (int i = 0; i < k_totem; i++) {
    int x;
    cin >> x;
    totem[--x] = 1;
  }

  ld t1, t2;

  cin >> t1 >> t2;

  if (t1 >= t2 || s == 0) { // mana is useless
    vector<ld> dp(h + 1, 0), ndp(h + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
      ndp[2] = (1 + p[i] * dp[2] + (1 - p[i]) * t2) / p[i];
      for (int j = 3; j <= h; j++)
        ndp[j] = 1 + p[i] * dp[j] + (1 - p[i]) * ndp[j - 1];
      for (int j = 0; j <= h; j++) {
        dp[j] = ndp[j];
        ndp[j] = 0;
      }
    }
    cout << fixed << setprecision(10) << dp[h];
  } else { // mana is optimal
    vector<vector<ld>> dp(h + 1, vector<ld>(s + 1, 0)),
        ndp(h + 1, vector<ld>(s + 1, 1e18));
    for (int i = n - 1; i >= 0; i--) {
      if (totem[i]) {
        for (int j = 2; j <= h; j++) {
          ndp[j][s] =
              min(ndp[j][s], (1 + p[i] * dp[j][s] + (1 - p[i]) * t1) / p[i]);
          ndp[j][s] =
              min(ndp[j][s], 1 + p[i] * dp[j][s] + (1 - p[i]) * ndp[j - 1][s]);
        }
        for (int j = h - 1; j >= 2; j--)
          ndp[j][s] = min(ndp[j][s], ndp[j + 1][s] + t1);
        for (int j = 2; j <= h; j++)
          for (int k = 0; k < s; k++)
            ndp[j][k] = ndp[j][s];
      } else {
        for (int j = 2; j <= h; j++) {
          for (int k = 0; k <= s; k++) {
            if (j == 2) {
              if (k == 0) {
                ndp[j][k] = (1 + p[i] * dp[j][k] + (1 - p[i]) * t2) / p[i];
              } else {
                ndp[j][k] =
                    1 + p[i] * dp[j][k] + (1 - p[i]) * (ndp[j][k - 1] + t1);
              }
            } else {
              ndp[j][k] = 1 + p[i] * dp[j][k] + (1 - p[i]) * ndp[j - 1][k];
            }
          }
        }
      }
      for (int j = 2; j <= h; j++) {
        for (int k = 0; k <= s; k++) {
          dp[j][k] = ndp[j][k];
          ndp[j][k] = 1e18;
        }
      }
    }
    cout << fixed << setprecision(10) << dp[h][s] << '\n';
  }

  return 0;
}