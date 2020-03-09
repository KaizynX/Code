#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

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

inline bool polar_angle1(const Point &p1, const Point &p2)
{
    double d1 = atan(p1), d2 = atan(p2); 
    return d1 == d2 ? p1 < p2 : d1 < d2;
}

inline bool polar_angle2(const Point &p1, const Point &p2)
{
    auto tmp = p1*p2;
    return tmp == 0 ? p1 < p2 : tmp > 0;
}

inline long long S(const Point &p1, const Point &p2, const Point &p3)
{
    return abs(p1.x*p2.y+p1.y*p3.x+p2.x*p3.y-p1.x*p3.y-p1.y*p2.x-p2.y*p3.x);
}

int main()
{
    return 0;
}
