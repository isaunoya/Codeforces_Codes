#include <bits/stdc++.h>

using namespace std;

int main() {
  vector a{1, 1, 1, 1};
  int r = 0;
  while (a.back() <= 2e5) {
    r++;
    a[3] += a[2];
    a[2] += a[1];
    a[1] += a[0];
  }
  cout << r << "\n";
}