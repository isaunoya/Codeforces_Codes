#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (i + 3 <= n && s.substr(i, 3) == "cjb") {
      ans += "cjb,";
      i += 2;
    } else {
      ans += s[i];
    }
  }
  cout << ans << "\n";
}