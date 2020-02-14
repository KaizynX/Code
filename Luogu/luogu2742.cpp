#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e4+7;

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
    friend bool operator < (const Point &p1, const Point &p2) {
        return p1.v < p2.v;
    }
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
} p[N];

int n;
int stk[N], used[N], tp;

inline void Andrew()
{
    sort(p+1, p+n+1);
    tp = 0;
    stk[++tp] = 1;
    for (int i = 2; i <= n; ++i) {
        while (tp >= 2 && (p[stk[tp]]-p[stk[tp-1]])*(p[i]-p[stk[tp]]) <= 0)
            used[stk[tp--]] = 0;
        used[i] = 1;
        stk[++tp] = i;
    }
    int tmp = tp;
    for (int i = n-1; i; --i) {
        if (used[i]) continue;
        while (tp >= tmp && (p[stk[tp]]-p[stk[tp-1]])*(p[i]-p[stk[tp]]) <= 0)
            used[stk[tp--]] = 0;
        used[i] = 1;
        stk[++tp] = i;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    Andrew();
    double res = 0;
    for (int i = 1; i < tp; ++i) {
        res += (p[stk[i+1]]-p[stk[i]]).length();
    }
#ifdef DEBUG
    cout << endl;
    for (int i = 1; i < tp; ++i)
        cout << p[stk[i]];
    cout << endl;
#endif
    printf("%.2f\n", res);
    return 0;
}
