#include <bits/stdc++.h>
using namespace std;
char s[2000][2000];
int n, m;
int main() {
  cin >> n >> m;
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++)
    scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#' && s[i + 1][j] == '#' && s[i + 2][j] == '#' &&
          s[i + 3][j] == '#')
        if (s[i][j + 1] == '#' && s[i + 1][j + 1] == '.' &&
            s[i + 2][j + 1] == '.' && s[i + 3][j + 1] == '#')
          if (s[i][j + 2] == '.' && s[i + 1][j + 2] == '.' &&
              s[i + 2][j + 2] == '.' && s[i + 3][j + 2] == '.')
            if (s[i][j + 3] == '.' && s[i + 1][j + 3] == '.' &&
                s[i + 2][j + 3] == '.' && s[i + 3][j + 3] == '.')
              if (s[i][j + 4] == '#' && s[i + 1][j + 4] == '.' &&
                  s[i + 2][j + 4] == '.' && s[i + 3][j + 4] == '#')
                if (s[i][j + 5] == '#' && s[i + 1][j + 5] == '#' &&
                    s[i + 2][j + 5] == '#' && s[i + 3][j + 5] == '#')
                  x++;

      if (s[i][j] == '#')
        y++;
    }
  }
  // cout<<x<<" "<<y<<endl;
  for (int a = 0; a <= 1000000; a++) {
    int A = x - 2 * a;
    if (146 * a + 100 * A == y) {
      cout << a << " " << A << endl;
    }
  }
  // cout<<x<<" "<<y<<endl;
}
// 2 170
// 1 154