#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b)
      puts("0");
    else if (a < b && a % 2 != b % 2)
      puts("1");
    else if (a > b && a % 2 == b % 2)
      puts("1");
    else if (a < b && ((b - a) / 2) % 2 == 0)
      puts("3");
    else
      puts("2");
  }
}