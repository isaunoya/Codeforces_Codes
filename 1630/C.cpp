#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }

  vector<int> fst(n, -1);
  vector<int> lst(n);
  for (int i = 0; i < n; i++) {
    if (fst[a[i]] == -1) {
      fst[a[i]] = i;
    }
    lst[a[i]] = i;
  }
  vector<int> pref(n + 1);
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i + 1] = max(pref[i], lst[a[i]]);
  }
  int giveup = 0;
  for (int l = 0, nx; l < n; l = nx) {
    giveup += 1;
    if (pref[l + 1] == l) {
      nx = l + 1;
    } else {
      nx = pref[l + 1];
    }
  }
  cout << n - giveup << "\n";
}