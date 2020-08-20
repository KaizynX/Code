/*
 * @Author: Kaizyn
 * @Date: 2020-08-13 11:58:13
 * @LastEditTime: 2020-08-13 12:13:45
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

struct Point {
  typedef long long T;
  T x, y;
  int id;
  Point(){}
  Point(const T &_x, const T &_y, const int &_i = 0) : x(_x), y(_y), id(_i) {}
  friend Point operator + (const Point &p1, const Point &p2) {
    return Point(p1.x+p2.x, p1.y+p2.y, p1.id);
  }
  friend Point operator - (const Point &p1, const Point &p2) {
    return Point(p1.x-p2.x, p1.y-p2.y, p1.id);
  }
  friend Point operator - (const Point &p) {
    return Point(-p.x, -p.y, p.id);
  }
  // a*b b在a的顺负逆正
  friend T operator * (const Point &p1, const Point &p2) {
    return p1.x*p2.y-p1.y*p2.x;
  }
  template <typename TT>
  friend Point operator / (const Point &p, const TT &k) {
    return Point(p.x/k, p.y/k, p.id);
  }
  template <typename TT>
  friend Point operator * (const Point &p, const TT &k) {
    return Point(p.x*k, p.y*k, p.id);
  }
  Point operator += (const Point &p) { return *this = *this+p; }
  Point operator -= (const Point &p) { return *this = *this+p; }
  template <typename TT>
  Point operator *= (const TT &k) { return *this = *this*k; }
  template <typename TT>
  Point operator /= (const TT &k) { return *this = *this/k; }
  friend bool operator < (const Point &p1, const Point &p2) {
    return make_pair(p1.x, p1.y) < make_pair(p2.x, p2.y);
  }
  friend bool operator > (const Point &p1, const Point &p2) {
    return make_pair(p1.x, p1.y) > make_pair(p2.x, p2.y);
  }
  friend bool operator == (const Point &p1, const Point &p2) {
    return p1.x == p2.x && p1.y == p2.y;
  }
  friend bool operator != (const Point &p1, const Point &p2) {
    return p1.x != p2.x || p1.y != p2.y;
  }
  friend istream& operator >> (istream &is, Point &p) {
    return is >> p.x >> p.y;
  }
  friend ostream& operator << (ostream &os, Point &p) {
    return os << p.x << " " << p.y << " " << p.id << endl;
  }
  double length() { return sqrt(1.0*x*x+1.0*y*y); }
  friend double dis(const Point &p1, const Point &p2) { return (p2-p1).length(); }
  double dis(const Point &p) { return (p-*this).length(); }
  friend T dot(const Point &p1, const Point &p2) { return p1.x*p2.x+p1.y*p2.y; }
  T dot(const Point &p) { return x*p.x+y*p.y; }
  friend Point rotate_90_c(const Point &p) { return Point(p.y, -p.x, p.id); }
  Point rotate_90_c() { return Point(y, -x, id); }
  friend double atan(const Point &p) { return atan2(p.y, p.x); }
};

Point a, b, c, p1, p2, p3;

inline void solve() {
  cin >> a >> b >> c;
  p1 = b-a;
  p2 = c-b;
  p3 = a-c;
  if (p1*p2 <= 0 && p2*p3 <= 0) cout << "Clockwise" << endl;
  else cout << "Counterclockwise" << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}