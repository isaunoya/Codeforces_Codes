#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2005;
const int MOD = 1000000007;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
char s[N][N];
bool check(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int tx = x + dir[i][0], ty = y + dir[i][1];
    if (tx < 1 || tx > n || ty < 1 || ty > m)
      continue;
    if (s[tx][ty] != s[x][y])
      return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%s", s[i] + 1);
  int c = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (check(i, j))
        c++;
  int ans = 1;
  for (int i = 1; i <= c; i++)
    ans = (ans + ans) % MOD;
  printf("%d", ans);
  return 0;
}