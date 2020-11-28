/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 13:19:43
 * @LastEditTime: 2020-10-25 13:35:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 6e3+7;

struct Point {
  typedef int T;
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

struct Line {
  Point p1, p2;
  Line(){}
  Line(const Point &_p1, const Point &_p2) : p1(_p1), p2(_p2) {}
  friend bool cross(const Line &l1, const Line &l2) {
    #define SJ1(x) max(l1.p1.x, l1.p2.x) < min(l2.p1.x, l2.p2.x) || \
             max(l2.p1.x, l2.p2.x) < min(l1.p1.x, l1.p2.x)
    if (SJ1(x) || SJ1(y)) return false;
    #undef SJ1
    #define SJ2(a, b, c, d) ((a-b)*(a-c))*((a-b)*(a-d)) <= 0
    return SJ2(l1.p1, l1.p2, l2.p1, l2.p2) &&
         SJ2(l2.p1, l2.p2, l1.p1, l1.p2);
    #undef SJ2
  }
  friend bool on_line(const Line &l, const Point &p) {
    return abs((l.p1-l.p2)*(l.p1-p)) < eps;
  }
  friend Point cross_point(const Line &l1, const Line &l2) {
    Point v1 = l1.p2-l1.p1, v2 = l2.p2-l2.p1;
    if (abs(v1*v2) < eps) return Point(0, 0); // no cross_point
    double t = (l2.p1-l1.p1)*v2/(v1*v2);
    return l1.p1+v1*t;
  }
};

int n, m, k;
double a[N][N];
double d[N];
Point p[N];

/*
void dijkstra(int s, int t) {
  fill(d+1, d+2*n+3, INF);
  dis[s] = 0;
  priority_queue<pair<double, int>> q;
  q.push({0, s});
  while (q.size()) {
    int u = q.top().second;
  }
}
*/

void floyd() {
  for (int l = 1; l <= 2*n+2; ++l)
  for (int i = 1; i <= 2*n+2; ++i) if (i != l)
  for (int j = 1; j <= 2*n+2; ++j) if (j != i && j != l)
    a[i][j] = min(a[i][j], a[i][l]+a[l][j]);
}

inline void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> p[i] >> p[i+n];
  }
  cin >> p[2*n+1] >> p[2*n+2];
  for (int i = 1; i <= n*2+2; ++i) {
    a[i][i] = INF;
    for (int j = i+1; j <= n*2+2; ++j) {
      a[i][j] = a[j][i] = INF;
      int flag = 0;
      Line line = Line(p[i], p[j]);
      for (int l = 1; l <= k; ++l) {
        if (cross(line, Line(p[l], p[l+n]))) {
          flag = 1;
          break;
        }
      }
      if (j <= 2*n && i+n == j) flag = 0;
      if (flag) continue;
      a[i][j] = a[j][i] = dis(p[i], p[j]);
    }
  }
  floyd();
  // printf("%.4f\n", dis[2*n+2]);
  printf("%.4f\n", a[2*n+1][2*n+2]);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}