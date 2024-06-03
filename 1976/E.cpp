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

using i64 = long long;
template <class T> constexpr T power(T a, i64 b) {
  T res{1};
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
  i64 res = a * b - i64(1.L * a * b / p) * p;
  res %= p;
  if (res < 0) {
    res += p;
  }
  return res;
}

template <i64 P> struct MInt {
  i64 x;
  constexpr MInt() : x{0} {}
  constexpr MInt(i64 x) : x{norm(x % getMod())} {}

  static i64 Mod;
  constexpr static i64 getMod() {
    if (P > 0) {
      return P;
    } else {
      return Mod;
    }
  }
  constexpr static void setMod(i64 Mod_) { Mod = Mod_; }
  constexpr i64 norm(i64 x) const {
    if (x < 0) {
      x += getMod();
    }
    if (x >= getMod()) {
      x -= getMod();
    }
    return x;
  }
  constexpr i64 val() const { return x; }
  constexpr MInt operator-() const {
    MInt res;
    res.x = norm(getMod() - x);
    return res;
  }
  constexpr MInt inv() const { return power(*this, getMod() - 2); }
  constexpr MInt &operator*=(MInt rhs) & {
    if (getMod() < (1ULL << 31)) {
      x = x * rhs.x % int(getMod());
    } else {
      x = mul(x, rhs.x, getMod());
    }
    return *this;
  }
  constexpr MInt &operator+=(MInt rhs) & {
    x = norm(x + rhs.x);
    return *this;
  }
  constexpr MInt &operator-=(MInt rhs) & {
    x = norm(x - rhs.x);
    return *this;
  }
  constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
  friend constexpr MInt operator*(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res *= rhs;
    return res;
  }
  friend constexpr MInt operator+(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res += rhs;
    return res;
  }
  friend constexpr MInt operator-(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res -= rhs;
    return res;
  }
  friend constexpr MInt operator/(MInt lhs, MInt rhs) {
    MInt res = lhs;
    res /= rhs;
    return res;
  }
  friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
    i64 v;
    is >> v;
    a = MInt(v);
    return is;
  }
  friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
    return os << a.val();
  }
  friend constexpr bool operator==(MInt lhs, MInt rhs) {
    return lhs.val() == rhs.val();
  }
  friend constexpr bool operator!=(MInt lhs, MInt rhs) {
    return lhs.val() != rhs.val();
  }
  friend constexpr bool operator<(MInt lhs, MInt rhs) {
    return lhs.val() < rhs.val();
  }
};

template <> i64 MInt<0>::Mod = 998244353;

constexpr int P = 998244353;
using Z = MInt<P>;

void solve() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> l(q), r(q);
  for (int i = 0; i < q; i++) {
    std::cin >> l[i];
  }
  for (int i = 0; i < q; i++) {
    std::cin >> r[i];
  }

  std::vector<int> L(n + 2), R(n + 2);
  R[0] = n;
  L[n] = 0;
  R[n] = n + 1;
  L[n + 1] = n;

  for (int i = 0; i < q; i++) {
    int a = l[i], b = r[i];
    if (a > b) {
      R[b] = R[a];
      L[R[b]] = b;
      R[a] = b;
      L[b] = a;
    } else {
      L[a] = L[b];
      R[L[a]] = a;
      L[b] = a;
      R[a] = b;
    }
  }

  std::vector<int> a;
  for (int i = R[0]; i != n + 1; i = R[i]) {
    a.push_back(i);
  }

  std::vector<int> cnt(n + 1), v(n + 1);
  for (auto x : a) {
    v[x] = 1;
  }
  cnt[a[0]]++;
  for (int i = 1; i < a.size(); i++) {
    cnt[std::max(a[i - 1], a[i])]++;
  }
  cnt[a.back()]++;

  Z ans = 1;
  Z cur = 0;
  for (int i = n; i >= 1; i--) {
    if (!v[i]) {
      ans *= cur;
      cur += 1;
    }
    cur += cnt[i];
  }
  std::cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}