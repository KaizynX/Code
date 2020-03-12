/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 14:45:50
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 16:21:14
 * @FilePath: \Code\atcoder\abc157F_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 65;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-7;
typedef pair<int, int> pii;

int n, k;
int x[N], y[N], c[N];
double d[N][N], r[N];

struct Point
{
    typedef double T;
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

inline int count(const Point &p)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (dis(p, Point(x[i], y[i])) < r[i]+eps) ++cnt;
    return cnt;
}

inline double get_cos(const int &i, const int &j)
{
    return (r[i]*r[i]+d[i][j]*d[i][j]-r[j]*r[j])/2/r[i]/d[i][j];
}

inline bool check(const double &mid)
{
    for (int i = 1; i <= n; ++i) r[i] = mid/c[i];
    for (int i = 1; i <= n; ++i) {
        if (count(Point(x[i], y[i])) >= k) return true;
        for (int j = i+1; j <= n; ++j) {
            // calc the cross point
            /*
            if (r[i]+r[j] < d[i][j]) continue;
            double cos_theta = get_cos(i, j), sin_theta = sqrt(1-cos_theta*cos_theta);
            double cos_len = cos_theta*r[i], sin_len = sin_theta*r[i];
            Point p(x[i], y[i]), vec(x[j]-x[i], y[j]-y[i]);
            vec /= vec.x*vec.x+vec.y*vec.y;
            p += vec*cos_len;
            vec = vec.rotate_90_c();
            vec *= sin_len;
            */
            double D = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if (D == 0) continue;
            double ad = (r[i]*r[i]+D-r[j]*r[j])/2;
            double h = D*r[i]*r[i]-ad*ad;
            if (h < 0) continue;
            h = sqrt(h);
            Point p(x[i], x[j]), vec(x[j]-x[i], y[j]-y[i]);
            vec /= D;
            p += vec*ad;
            vec = vec.rotate_90_c()*h;

            if (count(p+vec) >= k) return true;
            if (count(p-vec) >= k) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", x+i, y+i, c+i);
        for (int j = 1; j < i; ++j) {
            d[i][j] = d[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    double l = .0, r = 2e5, mid;
    while (r-l > eps) {
        mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.7f\n", l);
    return 0;
}
/*
#include <stdio.h>
#include <math.h>
#define maxn 65
#define eps 1e-8
double x[maxn],y[maxn],c[maxn],X[65*65*2],Y[65*65*2],r[maxn];
int tot,N,K;
double dis(double x,double y,double c,double X,double Y){
	return c*sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
}
void cal(double x1,double y1,double r1,double x2,double y2,double r2){//计算两圆交点坐标
	double D;//A=a*a,H=h*h,D=d*d;
	double ad,h;//ad=a*d;
	D=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	if(D==0)return;
	ad=(r1*r1+D-r2*r2)/2;//2*a*d=r1*r1+D-r2*r2
	h=D*r1*r1-ad*ad;
	if(h<0)return;//漏了此句的判定
	h=sqrt(h);
	tot++,X[tot]=x1+ad*(x2-x1)/D-(y2-y1)*h/D,Y[tot]=y1+ad*(y2-y1)/D+(x2-x1)*h/D;
	tot++,X[tot]=x1+ad*(x2-x1)/D+(y2-y1)*h/D,Y[tot]=y1+ad*(y2-y1)/D-(x2-x1)*h/D;
}
int judge(double t){
	int i,j,cnt;
	for(i=1;i<=N;i++)r[i]=t/c[i];
	tot=0;
	for(i=1;i<=N;i++){//计算出不同圆之间的交点坐标
		tot++,X[tot]=x[i],Y[tot]=y[i];//别忘了将圆心坐标放入交点坐标//此处错写成tot++,X[i]=x[i],Y[i]=y[i];
		for(j=i+1;j<=N;j++)
			cal(x[i],y[i],r[i],x[j],y[j],r[j]);
	}
	for(i=1;i<=tot;i++){
		cnt=0;
		for(j=1;j<=N;j++)
			if(dis(x[j],y[j],c[j],X[i],Y[i])<t+eps)cnt++;//浮点比大小无等于的情况，这是由浮点误差决定的。
		if(cnt>=K)return 1;
	}
	return 0;
}
int main(){
	double l,r,mid;
	int i;
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++)scanf("%lf%lf%lf",&x[i],&y[i],&c[i]);
	l=0,r=1000010;
	while(l+eps<r){
		mid=(l+r)/2;
		if(judge(mid))r=mid;
		else l=mid;
	}
	printf("%.6lf\n",r);
	return 0;
}
*/