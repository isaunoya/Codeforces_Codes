#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
int n, q, k, p[N], l[N], r[N], a[N], b[N], f[N], w[N][2];
long long op[N];
struct query {
  int x, y, id, c;
} S[N];
void add(int u, int c) {
  while (u <= n)
    f[u] += c, u += (u & (-u));
}
int getans(int u) {
  int sum = 0;
  while (u > 0)
    sum += f[u], u -= (u & (-u));
  return sum;
}
bool cmp(query A, query B) { return A.x < B.x; }
signed main() {
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++)
    scanf("%lld", &p[i]), a[i] = getans(p[i]), b[i] = p[i] - 1 - a[i],
                          add(p[i], 1), sum += min(a[i], b[i]);
  // for(int i=1;i<=n;i++) cout<<a[i]<<","<<b[i]<<endl;
  memset(f, 0, sizeof(f));
  cin >> q;
  for (int i = 1; i <= q; i++) {
    scanf("%lld%lld", &l[i], &r[i]), op[i] = sum;
    if (l[i] > r[i])
      swap(l[i], r[i]);
    if (l[i] == r[i])
      continue;
    if (p[l[i]] < p[r[i]]) {
      k++, S[k].x = l[i], S[k].y = p[l[i]], S[k].id = i, S[k].c = 1;
      k++, S[k].x = r[i] - 1, S[k].y = p[l[i]], S[k].id = i, S[k].c = -1;
      k++, S[k].x = r[i] - 1, S[k].y = p[r[i]], S[k].id = i, S[k].c = 1;
      k++, S[k].x = l[i], S[k].y = p[r[i]], S[k].id = i, S[k].c = -1;
    }
  }
  sort(S + 1, S + k + 1, cmp);
  memset(f, 0, sizeof(f));
  int j = 1;
  for (int i = 1; i <= n; i++) {
    add(p[i], min(a[i] - 1, b[i] + 1) - min(a[i], b[i]));
    while (S[j].x == i && j <= k) {
      op[S[j].id] += S[j].c * getans(S[j].y), j++;
    }
  }
  k = 0;
  for (int i = 1; i <= q; i++) {
    if (l[i] > r[i])
      swap(l[i], r[i]);
    if (l[i] == r[i])
      continue;
    if (p[l[i]] > p[r[i]]) {
      k++, S[k].x = l[i], S[k].y = p[r[i]], S[k].id = i, S[k].c = 1;
      k++, S[k].x = r[i] - 1, S[k].y = p[r[i]], S[k].id = i, S[k].c = -1;
      k++, S[k].x = r[i] - 1, S[k].y = p[l[i]], S[k].id = i, S[k].c = 1;
      k++, S[k].x = l[i], S[k].y = p[l[i]], S[k].id = i, S[k].c = -1;
    }
  }
  sort(S + 1, S + k + 1, cmp);
  memset(f, 0, sizeof(f));
  j = 1;
  for (int i = 1; i <= n; i++) {
    // cout<<min(a[i]+1,b[i]-1)-min(a[i],b[i])<<","<<p[i]<<"add"<<endl;
    add(p[i], min(a[i] + 1, b[i] - 1) - min(a[i], b[i]));
    while (S[j].x == i && j <= k) {
      // cout<<i<<","<<S[j].y<<","<<S[j].c<<","<<getans(S[j].y)<<endl;
      op[S[j].id] += S[j].c * getans(S[j].y), j++;
    }
  }
  // cout<<op[1]<<"wwwww"<<endl;
  k = 0;
  for (int i = 1; i <= q; i++) {
    if (l[i] > r[i])
      swap(l[i], r[i]);
    if (l[i] == r[i])
      continue;
    // if(p[l[i]]>p[r[i]]){
    k++, S[k].x = r[i], S[k].y = p[l[i]] - 1, S[k].id = i, S[k].c = 1;
    k++, S[k].x = l[i], S[k].y = p[r[i]] - 1, S[k].id = i, S[k].c = 0;
    // }
    op[i] -= min(a[l[i]], b[l[i]]);
    op[i] -= min(a[r[i]], b[r[i]]);
  }
  memset(f, 0, sizeof(f));
  sort(S + 1, S + k + 1, cmp), j = 1;
  for (int i = 1; i <= n; i++) {
    add(p[i], 1);
    while (S[j].x == i && j <= k) {
      // cout<<i<<","<<S[j].c<<","<<S[j].y<<","<<S[j].id<<endl;
      w[S[j].id][S[j].c] = getans(S[j].y), j++;
    }
  }
  // cout<<op[1]<<"www"<<","<<w[1][1]<<endl;
  for (int i = 1; i <= q; i++) {
    if (l[i] == r[i])
      continue;
    int x = w[i][0], y = p[r[i]] - 1 - x;
    if (p[l[i]] < p[r[i]])
      x--, y++;
    op[i] += min(x, y);
    x = w[i][1], y = p[l[i]] - 1 - x;
    op[i] += min(x, y);
  }
  for (int i = 1; i <= q; i++)
    printf("%lld\n", op[i]);
  return 0;
}
// 5
// 5 3 1 2 4
// 1
// 3 1