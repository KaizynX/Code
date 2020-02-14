#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

struct Point
{
    static const int V = 2;
    typedef double T;
    vector<T> v;
    Point(){ vector<T>(V, 0).swap(v); }
    friend Point operator + (const Point &p1, const Point &p2) {
        Point res;
        for (int i = 0; i < V; ++i) res.v[i] = p1.v[i]+p2.v[i];
        return res;
    }
    friend Point operator - (const Point &p1, const Point &p2) {
        Point res;
        for (int i = 0; i < V; ++i) res.v[i] = p1.v[i]-p2.v[i];
        return res;
    }
    friend Point operator - (const Point &p) {
        Point res;
        for (int i = 0; i < V; ++i)
            res.v[i] = -p.v[i];
        return res;
    }
    friend bool operator < (const Point &p1, const Point &p2) { return p1.v < p2.v; }
    friend bool operator == (const Point &p1, const Point &p2) { return p1.v == p2.v; }
    friend bool operator != (const Point &p1, const Point &p2) { return p1.v != p2.v; }
    friend T operator * (const Point &p1, const Point &p2) {
        return p1.v[0]*p2.v[1]-p1.v[1]*p2.v[0];
    } 
    T dot(const Point &p) {
        T res = 0;
        for (int i = 0; i < V; ++i)
            res += v[i]*p.v[i];
        return res;
    }
    double length() {
        double res= 0;
        for (int i = 0; i < V; ++i)
            res += v[i]*v[i];
        return sqrt(res);
    }
    friend istream& operator >> (istream &is, Point &p) {
        for (int i = 0; i < V; ++i) is >> p.v[i];
        return is;
    }
    friend ostream& operator << (ostream &os, Point &p) {
        for (int i = 0; i < V; ++i) os << p.v[i] << " \n"[i+1==V];
        return os;
    }
} p[N], b[N];

int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    if (n&1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        b[i] = p[(i+1)%n]-p[i];
    }
    for (int i = 0; i < n/2; ++i) {
        if (b[i] != -b[i+n/2]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
