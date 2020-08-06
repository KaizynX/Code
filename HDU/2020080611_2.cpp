/*
 * @Author: Kaizyn
 * @Date: 2020-08-06 15:31:49
 * @LastEditTime: 2020-08-06 16:47:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 31607;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

template <int _MOD> struct Mint {
  int v = 0;
  Mint() {}
  Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
  Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
  Mint operator = (const int &_v) { return *this = Mint(_v); }
  Mint operator = (const long long &_v) { return *this = Mint(_v); }
  bool operator ! () const { return !this->v; }
  bool operator < (const Mint &b) const { return v < b.v; }
  bool operator > (const Mint &b) const { return v > b.v; }
  bool operator == (const Mint &b) const { return v == b.v; }
  bool operator != (const Mint &b) const { return v != b.v; }
  bool operator <= (const Mint &b) const { return v < b.v || v == b.v; }
  bool operator >= (const Mint &b) const { return v > b.v || v == b.v; }
  Mint operator + (const Mint &b) const { return Mint(v+b.v); }
  Mint operator - (const Mint &b) const { return Mint(v-b.v); }
  Mint operator * (const Mint &b) const { return Mint(1ll*v*b.v); }
  Mint operator / (const Mint &b) const { return Mint(b.inv()*v); }
  Mint& operator += (const Mint &b) { return *this = *this+b; }
  Mint& operator -= (const Mint &b) { return *this = *this-b; }
  Mint& operator *= (const Mint &b) { return *this = *this*b; }
  Mint& operator /= (const Mint &b) { return *this = *this/b; }
  Mint operator - () const { return Mint(-v); }
  Mint& operator ++ () { return *this += 1; }
  Mint& operator -- () { return *this -= 1; }
  Mint operator ++ (int) { Mint tmp = *this; *this += 1; return tmp; }
  Mint operator -- (int) { Mint tmp = *this; *this -= 1; return tmp; }
  Mint pow(int p) const {
    Mint res(1), x(*this);
    while (p) {
      if (p&1) res = res*x;
      x *= x;
      p >>= 1;
    }
    return res;
  }
  Mint inv() const { return pow(_MOD-2); }
  friend istream& operator >> (istream &is, Mint &mt) { return is >> mt.v; }
  friend ostream& operator << (ostream &os, const Mint &mt) { return os << mt.v; }
};
using mint = Mint<MOD>;

struct Point {
  typedef int T;
  T x, y;
  mint p;
  Point(){}
  Point(const T &_x, const T &_y, const mint &_p = 0) : x(_x), y(_y), p(_p) {}
  friend Point operator + (const Point &p1, const Point &p2) {
    return Point(p1.x+p2.x, p1.y+p2.y, p1.p);
  }
  friend Point operator - (const Point &p1, const Point &p2) {
    return Point(p1.x-p2.x, p1.y-p2.y, p1.p);
  }
  // a*b b在a的顺负逆正
  friend T operator * (const Point &p1, const Point &p2) {
    return p1.x*p2.y-p1.y*p2.x;
  }
  friend bool operator < (const Point &p1, const Point &p2) {
    return make_pair(p1.x, p1.y) < make_pair(p2.x, p2.y);
  }
  friend istream& operator >> (istream &is, Point &p) {
    return is >> p.x >> p.y;
  }
  friend ostream& operator << (ostream &os, Point &p) {
    return os << p.x << " " << p.y << " " << p.p << endl;
  }
  double length() { return sqrt(1.0*x*x+1.0*y*y); }
  friend double dis(const Point &p1, const Point &p2) { return (p2-p1).length(); }
  double dis(const Point &p) { return (p-*this).length(); }
  friend T dot(const Point &p1, const Point &p2) { return p1.x*p2.x+p1.y*p2.y; }
  T dot(const Point &p) { return x*p.x+y*p.y; }
  friend double atan(const Point &p) { return atan2(p.y, p.x); }
};

int n;
int rk[N];
Point a[N];

inline bool polar_angle1(const Point &p1, const Point &p2) {
  double d1 = atan(p1), d2 = atan(p2); 
  return d1 == d2 ? p1 < p2 : d1 < d2;
}

inline bool polar_angle2(const Point &p1, const Point &p2) {
  auto tmp = p1*p2;
  return tmp == 0 ? p1 < p2 : tmp > 0;
}

inline void solve() {
  cin >> n;
  for (int i = 0, v; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].p >> v;
    a[i].p /= v;
  }
  mint res = 0;
  for (int i = 0; i < n; ++i) {
    int m = n-1;
    for (int j = 0; j < n; ++j) {
      if (j < i) rk[j] = j;
      if (j > i) rk[j-1] = j;
    }
    sort(rk, rk+m, [&](const int &x, const int &y) {
      return polar_angle1(a[x]-a[i], a[y]-a[i]);
    });
    int l = 0;
    mint mul = 1;
    for (int j = m-1; j > 0; --j) {
      if ((a[rk[j]]-a[i])*(a[rk[0]]-a[i]) <= 0) {
        mul *= -a[rk[j]].p+1;
        l = j;
      } else {
        break;
      }
    }
    res += a[i].p*a[rk[0]].p*mul*(a[i]*a[rk[0]]);
    for (int j = 1; j < m; ++j) {
      mul *= -a[rk[j-1]].p+1;
      while (l != j && (a[rk[l]]-a[i])*(a[rk[j]]-a[i]) > 0) {
        mul /= -a[rk[l]].p+1;
        l = (l+1)%m;
      }
      res += a[i].p*a[rk[j]].p*mul*(a[i]*a[rk[j]]);
    }
  }
  cout << res/2 << endl; // abs???
  cout << -res/2 << endl; // abs???
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