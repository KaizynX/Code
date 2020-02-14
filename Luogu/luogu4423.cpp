#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const double INF = 1e18;

struct Point
{
    int x, y, id;
    friend Point operator - (const Point &p1, const Point &p2) {
        Point res;
        res.x = p1.x-p2.x;
        res.y = p1.y-p2.y;
        return res;
    }
    friend Point operator - (const Point &p) {
        Point res;
        res.x = -p.x;
        res.y = -p.y;
        return res;
    }
    friend bool operator < (const Point &p1, const Point &p2) {
        return make_pair(p1.x, p1.y) < make_pair(p2.x, p2.y);
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
    double length() { return sqrt(1.0*x*x+1.0*y*y); }
    friend double dis(const Point &p1, const Point &p2) { return (p2-p1).length(); }
} a[N];

int n, ansa, ansb, ansc;
double mindist;

inline bool cmp_y(const Point &p1, const Point &p2) { return p1.y < p2.y; }


void upd_ans(const Point &p1, const Point &p2, const Point &p3)
{
    double dist = dis(p1, p2)+dis(p2, p3)+dis(p1, p3);
    if (dist < mindist) mindist = dist, ansa = p1.id, ansb = p2.id, ansc = p3.id;
}

void rec(int l, int r)
{
    if (r-l <= 3) {
        for (int i = l; i < r; ++i)
            for (int j = i+1; j < r; ++j)
                for (int k = j+1; k <= r; ++k)
                    upd_ans(a[i], a[j], a[k]);
        sort(a+l, a+r+1, cmp_y);
        return;
    }

    static Point t[N];
    int m = (l+r)>>1, midx = a[m].x;
    rec(l, m); rec(m+1, r);
    merge(a+l, a+m+1, a+m+1, a+r+1, t, cmp_y);
    copy(t, t+r-l+1, a+l);

    int tsz = 0;
    for (int i = l; i <= r; ++i)
        if (abs(a[i].x-midx) <= mindist/2) {
            for (int j = tsz; j && a[i].y-t[j].y < mindist/2; --j)
                for (int k = j-1; k && a[i].y-t[k].y < mindist/2; --k)
                    upd_ans(a[i], t[j], t[k]);
            t[++tsz] = a[i];
        }
}

inline void mindist_pair()
{
    sort(a+1, a+n+1);
    mindist = INF;
    rec(1, n);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i].id = i;
    mindist_pair();
    printf("%.6f\n", mindist+5e-7);
    return 0;
}
