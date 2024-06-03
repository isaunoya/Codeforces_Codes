#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) 
    cin >> A[i];

  array<int, 2> f{INF, -INF};
  // f[0], down
  // f[1], up

  for (int i = 1; i < N; i++) {
    int x;
    cin >> x;
    array<int, 2> g{-INF, INF};
    if (A[i - 1] < A[i]) {
      g[0] = f[0];
    }
    if (A[i - 1] > A[i]) {
      g[1] = f[1];
    }
    if (f[1] < A[i]) {
      g[1] = max(g[1], A[i - 1]);
    }
    if (f[0] > A[i]) {
      g[0] = min(g[0], A[i - 1]);
    }
    if (g == array<int, 2>{-INF, INF}) {

    }
    swap(f, g);
  }
}