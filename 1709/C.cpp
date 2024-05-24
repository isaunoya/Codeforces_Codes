/*
 * c.cc
 * 2022-07-22 10:43:38
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    assert(n % 2 == 0);
    int cnt[2] = {0};
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        ++cnt[0];
      } else if (s[i] == ')') {
        ++cnt[1];
      } else {
        pos.push_back(i);
      }
    }
    if (cnt[0] == n / 2 || cnt[1] == n / 2) {
      cout << "YES\n";
      continue;
    }
    for (int i = 0; i < n / 2 - cnt[0]; i++) {
      s[pos[i]] = '(';
    }
    for (int i = n / 2 - cnt[0]; i < (int) pos.size(); i++) {
      s[pos[i]] = ')';
    }
    swap(s[pos[n / 2 - cnt[0] - 1]], s[pos[n / 2 - cnt[0]]]);
    bool ok = true;
    int S = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') ++S;
      else --S;
      if (S < 0) {
        ok = false;
      }
    }
    if (ok) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}