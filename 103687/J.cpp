#include <bits/stdc++.h>

typedef long double db;

const db eps = 1e-9L, pi = std::acos(-1.0L);

struct point {
  db x, y;
  point() : x(), y() {}
  point(db _x, db _y) : x(_x), y(_y) {}
  friend point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend point operator*(const point &a, db b) {
    return point(a.x * b, a.y * b);
  }
  db mod() const { return std::sqrt(x * x + y * y); }
  point unit() const { return point(x / mod(), y / mod()); }
  point norm() const { return point(y, -x); }
};

int ds, dt;

point Gen(int th) {
  return point(cos(th / 180.0L * pi), sin(th / 180.0L * pi));
}

point Mid(point a, point b) {
  point c = (a + b) * 0.5L;
  point v = (b - a).unit().norm();
  db d = (b - a).mod() * 0.5L;
  return c + v * std::sqrt(1.0L - d * d);
}

std::vector<point> Solve2(int ds, int dt) {
  point s = Gen(ds), t = Gen(dt);
  return {s, Mid(s, t), t};
}

std::vector<point> Solve3(int ds, int dt) {
  point s = Gen(ds), t = Gen(dt);
  point m = s - s.norm();
  return {s, m, Mid(m, t), t};
}

std::vector<point> Solve4(int ds, int dt) {
  point s = Gen(ds), t = Gen(dt);
  point m = Gen((ds + 90) % 360);
  return {s, s - s.norm(), m, Mid(m, t), t};
}

std::vector<point> Solve(int ds, int dt) {
  if (ds == dt)
    return {Gen(ds)};
  int dd = (dt - ds + 360) % 360;
  if (dd <= 90)
    return Solve2(ds, dt);
  if (dd <= 131)
    return Solve3(ds, dt);
  return Solve4(ds, dt);
}

void work() {
  // printf("%.10LF\n",90+2.0L*std::asin(std::sqrt(2.0L)/4)/pi*180.0L);
  // 209 91
  scanf("%d%d", &ds, &dt);
  std::vector<point> ans;
  // std::cerr<<(dt-ds+360)%360<<'\n';
  if ((dt - ds + 360) % 360 <= 180)
    ans = Solve(ds, dt);
  else {
    ans = Solve(dt, ds);
    std::reverse(ans.begin(), ans.end());
  }
  printf("%llu\n", (unsigned long long)ans.size() - 1);
  for (auto [x, y] : ans)
    printf("%.10Lf %.10Lf\n", x, y);
}

int main() {
  // std::ios::sync_with_stdio(0);
  int T = 1;
  // std::cin>>T;
  scanf("%d", &T);
  for (; T--;)
    work();
  return 0;
}