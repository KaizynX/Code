#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

struct Point
{
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
    double length() { return sqrt(x*x+y*y); }
    friend double dis(const Point &p1, const Point &p2) { return (p2-p1).length(); }
    double dis(const Point &p) { return (p-*this).length(); }
    friend T dot(const Point &p1, const Point &p2) { return p1.x*p2.x+p1.y*p2.y; }
    T dot(const Point &p) { return x*p.x+y*p.y; }
    friend Point rotate_90_c(const Point &p) { return Point(p.y, -p.x, p.id); }
    Point rotate_90_c() { return Point(y, -x, id); }
    friend double atan(const Point &p) { return atan2(p.y, p.x); }
};

int n;
int vis[N], stk[N], tp;
Point p[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        while (tp >= 2 && (p[stk[tp]]-p[stk[tp-1]])*(p[i]-p[stk[tp-1]]) <= 0) --tp;
        if (tp) vis[stk[tp]] = 1;
        stk[++tp] = i;
    }
    int res = 0;
    for (int i = 2; i <= n; ++i) res += vis[i];
    cout << res << endl;
    return 0;
}
