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
  int N;
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A[i];

  if (*max_element(all(A)) == -1) {
    for (int i = 0; i < N; i++) {
      if (i & 1) {
        cout << 1 << " ";
      } else {
        cout << 2 << " ";
      }
    }
    cout << "\n";
    return;
  }
  int l = 0;
  int r = N - 1;
  while (l < N && A[l] == -1) {
    l++;
  }
  while (r >= 0 && A[r] == -1) {
    r--;
  }
  vi p;
  for (int i = l; i <= r; i++) {
    if (A[i] != -1) {
      p.pb(i);
    }
  }
  vi B = A;
  {
    int q = 0;
    for (int i = l - 1; i >= 0; i--) {
      if (q) {
        B[i] = B[i + 1] / 2;
      } else {
        B[i] = B[i + 1] * 2;
      }
      q ^= 1;
    }
    q = 0;
    for (int i = r + 1; i < N; i++) {
      if (q) {
        B[i] = B[i - 1] / 2;
      } else {
        B[i] = B[i - 1] * 2;
      }
      q ^= 1;
    }
  }

  for (int i = 0; i + 1 < (int)p.size(); i++) {
    int x = p[i];
    int y = p[i + 1];
    int X = A[x];
    int Y = A[y];
    if (X > Y) {
      while (__lg(X) != __lg(Y)) {
        x++;
        if (x >= N) {
          cout << "-1\n";
          return;
        }
        B[x] = X >> 1;
        X >>= 1;
      }
    } else {
      while (__lg(X) != __lg(Y)) {
        y--;
        if (y < 0) {
          cout << "-1\n";
          return;
        }
        B[y] = Y >> 1;
        Y >>= 1;
      }
    }
    if (x == y && X == Y) {
      continue;
    }
    if (x >= y) {
      cout << "-1\n";
      return;
    }

    int len = y - x - 1;
    if (len % 2 == 0) {
      cout << "-1\n";
      return;
    }

    int p = x;
    int k = y;
    if (X != Y) {
      int need = 0;
      for (int j = 30; j >= 0; j--) {
        if ((X >> j & 1) ^ (Y >> j & 1)) {
          need = j;
          break;
        }
      }
      if (len < need * 2 + 1) {
        cout << "-1\n";
        return;
      }
      // debug(B, need);
      for (int j = 1; j <= need; j++) {
        p++;
        if (p >= N) {
          cout << "-1\n";
          return;
        }
        B[p] = X >> j & 1;
      }
      p++;
      if (p >= N) {
        cout << "-1\n";
        return;
      }
      B[p] = X >> (need + 1);
      for (int j = 1; j <= need; j++) {
        k--;
        if (k < 0) {
          cout << "-1\n";
          return;
        }
        B[k] = Y >> j & 1;
      }
    }
    int q = 0;
    while (p + 1 < k) {
      p++;
      if (q)
        B[p] = B[p - 1] / 2;
      else
        B[p] = B[p - 1] * 2;
      q ^= 1;
    }
  }

  int ok = 1;
  for (int i = 0; i + 1 < N; i++) {
    if ((B[i] / 2) != B[i + 1] && (B[i + 1] / 2) != B[i]) {
      ok = 0;
      break;
    }
  }

  if (!ok) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < N; i++) {
    cout << B[i] << " \n"[i + 1 == N];
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