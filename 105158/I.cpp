#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define debug(...) 42
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
template <typename T> using vc = vector<T>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

#include <atcoder/string>
template <typename T> class SparseTable {
public:
  SparseTable(std::vector<T> a) {
    table.push_back(a);
    for (int j = 1; j <= (int)std::__lg(a.size()); ++j) {
      table.emplace_back(a.size() - (1 << j) + 1);
      for (int i = 0; i < (int)table.back().size(); ++i) {
        table[j][i] =
            std::min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T queryMin(int l, int r) {
    assert(l <= r);
    int t = std::__lg(r - l + 1);
    return std::min(table[t][l], table[t][r - (1 << t) + 1]);
  }

private:
  std::vector<std::vector<T>> table;
};
void solve() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  using namespace atcoder;
  vi sa = suffix_array(S);
  vi rnk(N);
  for (int i = 0; i < N; i++)
    rnk[sa[i]] = i;
  vi lcp = lcp_array(S, sa);
  SparseTable<int> st(lcp);
  auto getlcp = [&](int i, int j) {
    if (i == j) {
      return N - i;
    }
    int x = rnk[i];
    int y = rnk[j];
    if (x > y) {
      swap(x, y);
    }
    return st.queryMin(x, y - 1);
  };
  for (int len = N / 4 + 1; len <= N / 2; len++) {
    int a = 0, b = len, c = len * 2, d = len * 3, rem = K;
    while (d < N) {
      int l = getlcp(a, b);
      int l2 = getlcp(a, c);
      int l3 = getlcp(a, d);
      l = min(l, l2);
      l = min(l, l3);
      a += l, b += l, c += l, d += l;
      if (d >= N)
        break;
      int v_a = (S[b] != S[a]) + (S[c] != S[a]) + (S[d] != S[a]);
      int v_b = (S[a] != S[b]) + (S[c] != S[b]) + (S[d] != S[b]);
      int v_c = (S[a] != S[c]) + (S[b] != S[c]) + (S[d] != S[c]);
      int v_d = (S[a] != S[d]) + (S[b] != S[d]) + (S[c] != S[d]);
      int v = min({v_a, v_b, v_c, v_d});
      rem -= v;
      if (rem < 0) {
        break;
      }
      a++;
      b++;
      c++;
      d++;
    }
    while (c < min(N, len * 3)) {
      int l = getlcp(a, b);
      int l2 = getlcp(a, c);
      l = min(l, l2);
      a += l, b += l, c += l;
      if (c >= min(N, len * 3))
        break;
      int v_a = (S[b] != S[a]) + (S[c] != S[a]);
      int v_b = (S[a] != S[b]) + (S[c] != S[b]);
      int v_c = (S[a] != S[c]) + (S[b] != S[c]);
      int v = min({v_a, v_b, v_c});
      rem -= v;
      if (rem < 0) {
        break;
      }
      a++;
      b++;
      c++;
    }
    while (b < min(N, len * 2)) {
      int l = getlcp(a, b);
      a += l, b += l;
      if (b >= min(N, len * 2))
        break;
      if (S[a] != S[b]) {
        rem--;
        if (rem < 0) {
          break;
        }
      }
      a++;
      b++;
    }
    if (rem >= 0) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}