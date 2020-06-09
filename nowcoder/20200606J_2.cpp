/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 14:43:36
 * @LastEditTime: 2020-06-06 15:31:27
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

template <typename T = double>
struct Vec {
  T x, y, z;
  Vec(const T &_x = 0, const T &_y = 0, const T &_z = 0) : x(_x), y(_y), z(_z) {}
  double len() { return sqrt(1.0*x*x+1.0*y*y+1.0*z*z); }
  friend Vec operator +(const Vec &v1, const Vec &v2) { return Vec(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z); }
  friend Vec operator -(const Vec &v1, const Vec &v2) { return Vec(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z); }
  friend Vec operator *(const T &k, const Vec &v) { return Vec(k*v.x, k*v.y, k*v.z); }
  friend Vec operator *(const Vec &v, const T &k) { return k*v; }
  friend Vec operator *(const Vec &v1, const Vec &v2) {
    return Vec(
        v1.y*v2.z-v1.z*v2.y,
        v1.z*v2.x-v1.x*v2.z,
        v1.x*v2.y-v1.y*v2.x
    );
  }
  friend T dot(const Vec &v1, const Vec &v2) { return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z; }
  T dot(const Vec &v) { return dot(*this, v); }
  Vec& operator +=(const Vec &v) { return *this = *this+v; }
  Vec& operator -=(const Vec &v) { return *this = *this-v; }
  Vec& operator *=(const T &k) { return *this = *this*k; }
  Vec& operator *=(const Vec &v) { return *this = *this*v; }
  friend istream& operator >>(istream &is, Vec &v) { return is >> v.x >> v.y >> v.z; }
};

int L;
Vec<double> m, p1, p2, p3;

inline void solve() {
  cin >> L >> m >> p1 >> p2 >> p3;
  p1 = (p1-p3)*(p2-p3);
  double r = abs(dot(m-p3, p1))/p1.len()/2;
  double t = 4*PI*r*r*r/3/L;
  printf("%.10lf\n", t);
}

signed main() {
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}