/*
 * b.cpp 2023-10-18
 * Copyright (C) 2023 Woshiluo Luo <woshiluo.luo@outlook.com>
 *
 * 「Two roads diverged in a wood,and I—
 * I took the one less traveled by,
 * And that has made all the difference.」
 *
 * Distributed under terms of the GNU GNU AGPLv3+ license.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <vector>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
typedef const int cint;
typedef long long ll;
typedef unsigned long long ull;

inline bool isdigit(const char cur) { return cur >= '0' && cur <= '9'; } /*{{{*/
template <class T> T Max(T a, T b) { return a > b ? a : b; }
template <class T> T Min(T a, T b) { return a < b ? a : b; }
template <class T> void chk_Max(T &a, T b) {
  if (b > a)
    a = b;
}
template <class T> void chk_Min(T &a, T b) {
  if (b < a)
    a = b;
}
template <typename T> T read() {
  T sum = 0, fl = 1;
  char ch = getchar();
  for (; isdigit(ch) == 0; ch = getchar())
    if (ch == '-')
      fl = -1;
  for (; isdigit(ch); ch = getchar())
    sum = sum * 10 + ch - '0';
  return sum * fl;
}
template <class T> T pow(T a, int p) {
  T res = 1;
  while (p) {
    if (p & 1)
      res = res * a;
    a = a * a;
    p >>= 1;
  }
  return res;
} /*}}}*/

const int N = 1e6 + 1e5;
const int mod = 998244353;

struct ModInt { /*{{{*/
  int cur;
  ModInt(ll _cur = 0) { cur = (((_cur % mod) + mod) % mod); }

  inline ModInt operator+(const ModInt &b) const { return (cur + b.cur) % mod; }
  inline ModInt operator-(const ModInt &b) const {
    return (((cur - b.cur) % mod) + mod) % mod;
  }
  inline ModInt operator*(const ModInt &b) const {
    return (1LL * cur * b.cur) % mod;
  }
  inline ModInt operator/(const ModInt &b) const {
    return (1LL * cur * pow(b, mod - 2).cur) % mod;
  }

  inline void operator+=(const ModInt &b) { (*this) = (*this) + b; }
  inline void operator-=(const ModInt &b) { (*this) = (*this) - b; }
  inline void operator*=(const ModInt &b) { (*this) = (*this) * b; }
  inline void operator/=(const ModInt &b) { (*this) = (*this) / b; }

  inline void output(const char end = '\n') { printf("%d%c", cur, end); }
}; /*}}}*/

ModInt fact[N], ifac[N];

ModInt choose(cint n, cint m) {
  if (n < m)
    std::exit(-1);
  return fact[n] * ifac[m] * ifac[n - m];
}

int main() {
#ifdef woshiluo
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int T = read<int>();
  fact[0] = 1;
  for (int i = 1; i < N; i++)
    fact[i] = fact[i - 1] * i;
  ifac[N - 1] = (ModInt)1 / fact[N - 1];
  for (int i = N - 2; i >= 0; i--)
    ifac[i] = ifac[i + 1] * (i + 1);
  while (T--) {
    cint n = read<int>();
    cint k = read<int>();
    ModInt res = 0;
    cint size = std::__gcd(n, k);
    ModInt p = pow((ModInt)2, n / std::__gcd(n, k)) - 2;
    res += (ModInt)(size + 2) * pow(p + 1, size);
    res -= (ModInt)pow(p + 1, size) + (ModInt)p * size * pow(p + 1, size - 1);
    // for( int i = 0; i <= size; i ++ ) {
    //   res -= choose( size, i ) * pow( p, i ) * (i+1);
    // }

    res.output();
  }
}
