#include <bits/stdc++.h>

using namespace std;

const int base = 233;
const int N = 1e6 + 5;
unsigned long long pw[N], hsh[N], hsh2[N];
int len[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  pw[0] = 1;
  for (int i = 0; i < n; i++) {
    pw[i + 1] = pw[i] * base;
  }
  for (int i = 0; i < n; i++) {
    hsh[i + 1] = hsh[i] * base + s[i] - 'a';
  }
  for (int i = n - 1; i >= 0; i--) {
    hsh2[i] = hsh2[i + 1] * base + s[i] - 'a';
  }

  for (int i = n - 1; i >= 0; i--) {
    if (i + 3 < n && s[i] == s[i + 2] && s[i + 1] == s[i + 3]) {
      len[i] = len[i + 2] + 2;
    } else {
      len[i] = min(n - i, 2);
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    // cout << (hsh[r] - hsh[l] * pw[r - l]) << " " << (hsh2[l] - hsh2[r] * pw[r
    // - l]) << "\n";
    bool is_pal =
        ((hsh[r] - hsh[l] * pw[r - l]) == (hsh2[l] - hsh2[r] * pw[r - l]));
    if (is_pal) {
      cout << "Budada\n";
      continue;
    }
    int L = r - l;
    // if (len[l] >= L && L % 2 == 1) {
    //   cout << "Putata\n";
    //   continue;
    // }
    if (L % 2 == 0) {
      cout << "Budada\n";
    } else {
      cout << "Putata\n";
    }
  }
}