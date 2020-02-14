#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const double err = 1e-12;

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
};

struct Line
{
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
        return abs((l.p1-l.p2)*(l.p1-p)) < err;
    }
    friend Point cross_point(const Line &l1, const Line &l2) {
        Point v1 = l1.p2-l1.p1, v2 = l2.p2-l2.p1;
        if (abs(v1*v2) < err) return Point(0, 0); // no cross_point
        double t = (l2.p1-l1.p1)*v2/(v1*v2);
        return l1.p1+v1*t;
    }
};

struct Circular
{
    Point o;
    double r;
    Circular(){}
    Circular(const Point &_o, const double &_r) : o(_o), r(_r) {}
    template <typename T>
    Circular(const T &_x, const T &_y, const double &_r) : o(Point(_x, _y)), r(_r) {}
    friend bool in_cir(const Circular &c, const Point &p) { return dis(c.o, p) <= c.r; }
    bool in_cir(const Point &p) { return dis(o, p) <= r; }
};

inline Circular get_cir(const Point &p1, const Point &p2, const Point &p3)
{
    Circular res;
    res.o = cross_point(Line((p1+p2)/2, (p1+p2)/2+(p2-p1).rotate_90_c()),
                        Line((p1+p3)/2, (p1+p3)/2+(p3-p1).rotate_90_c()));
    res.r = dis(res.o, p1);
    return res;
}

int n;
Point a[N];

inline Circular RIA()
{
    Circular cir;
    random_shuffle(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        if (cir.in_cir(a[i])) continue;
        cir = Circular(a[i], 0);
        for (int j = 1; j < i; ++j) {
            if (cir.in_cir(a[j])) continue;
            cir = Circular((a[i]+a[j])/2, dis(a[i], a[j])/2);
            for (int k = 1; k < j; ++k) {
                if (cir.in_cir(a[k])) continue;
                cir = get_cir(a[i], a[j], a[k]);
            }
        }
    }
    return cir;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Circular cir = RIA();
    printf("%.10f\n%.10f %.10f\n", cir.r, cir.o.x, cir.o.y);
    return 0;
}
