/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 17:07:51
 * @LastEditTime: 2021-06-13 17:15:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

const double eps=1e-10;
const double PI=acos(-1);
inline int sgn(double x){return fabs(x)<eps?0:(x<0?-1:1);}
struct point{
	double x,y;
	point(double a=0,double b=0):x(a),y(b){}
	point operator +(const point &A)const{
		return point(x+A.x,y+A.y);
	}
	point operator -(const point &A)const{
		return point(x-A.x,y-A.y);
	}
	point operator *(const double v)const{
		return point(x*v,y*v);
	}
	point operator /(const double v)const{
		return point(x/v,y/v);
	}
	bool operator ==(const point &A)const{
		return sgn(x-A.x)==0&&sgn(y-A.y)==0;
	}
	double norm(){
		return sqrt(x*x+y*y);
	}
};
double dot(point a,point b){
	return a.x*b.x+a.y*b.y;
}
double det(point a,point b){
	return a.x*b.y-a.y*b.x;
}
double dist(point a,point b){
	return (a-b).norm();
}
double angle(point p){
	return atan2(p.y,p.x);
}
struct line{
	point a,b;
	line(){}
	line(point x,point y):a(x),b(y){}
};
point point_proj_line(point p,point s,point t){
	double r=dot(t-s,p-s)/dot(t-s,t-s);
	return s+(t-s)*r;
}
point duichen(point p,point s,point t){
  point pp = point_proj_line(p, s, t);
  return point(pp.x*2-p.x, pp.y*2-p.y);
}

double f(point l1, point l2, point p1, point p2) {
  if (det(l1, p1) > 0) p1 = duichen(p1, point(0, 0), l1);
  if (det(l2, p2) < 0) p2 = duichen(p2, point(0, 0), l2);
  return dist(p1, p2);
}

inline void solve() {
  int a, b, c, d, x0, y0, x1, y1;
  cin >> a >> b >> c >> d >> x0 >> y0 >> x1 >> y1;
  point l1 = point(a, b), l2 = point(c, d), p1 = point(x0, y0), p2 = point(x1, y1);
  if (angle(l1) > angle(l2)) swap(l1, l2);
  printf("%.3f\n", min(f(l1, l2, p1, p2), f(l1, l2, p2, p1)));
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}