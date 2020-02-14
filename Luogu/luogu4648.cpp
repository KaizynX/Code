#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef pair<int, int> pii;

int B, n, d, m;
int sum[80][155][155], pt[80][155][155]; 

struct BinaryIndexedTree
{
    static const int NN = 150000;
    typedef int T;
    T tr[NN];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= 2*m; x += x&-x) tr[x] += v; }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

struct Point
{
    int z, x, y;
};

inline int sum_of_rec(int z, int lx, int rx, int ly, int ry)
{
    lx = max(1, lx);
    ly = max(1, ly);
    rx = min(2*m, rx);
    ry = min(2*m, ry);
    return sum[z][rx][ry]-sum[z][rx][ly-1]-sum[z][lx-1][ry]+sum[z][lx-1][ly-1];
}

int main()
{
    scanf("%d%d%d%d", &B, &n, &d, &m);
    long long res = 0;
    if (B == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        for (int i = 0, l = 0, r = 0; i < n; ++i) {
            while (r < n && a[r]-a[i] <= d) ++r;
            while (a[i]-a[l] > d) ++l;
            res += r-l;
        }
    } else if (B == 2) {
        // first y, second x
        vector<pii> a(n);
        for (int i = 0, x, y; i < n; ++i) {
            scanf("%d %d", &x, &y);
            a[i] = {x-y, x+y};
        }
        sort(a.begin(), a.end());
        for (int i = 0, l = 0, r = 0; i < n; ++i) {
            while (r < n && a[r].first-a[i].first <= d)
                BIT.update(a[r++].second, 1);
            while (a[i].first-a[l].first > d)
                BIT.update(a[l++].second, -1);
            res += BIT.query(max(1, a[i].second-d), min(2*m, a[i].second+d));
        }
    } else {
        vector<Point> a(n);
        for (int i = 0, z, x, y; i < n; ++i) {
            scanf("%d %d %d", &z, &x, &y);
            ++pt[z][x+y][x-y+m];
            a[i] = {z, x+y, x-y+m};
        }
        for (int z = 1; z <= m; ++z)
        for (int x = 1; x <= 2*m; ++x)
        for (int y = 1; y <= 2*m; ++y)
            sum[z][x][y] = sum[z][x-1][y]+sum[z][x][y-1]-sum[z][x-1][y-1]+pt[z][x][y];
        for (Point p : a)
            for (int z = max(1, p.z-d), tmp; z <= min(m, p.z+d); ++z) {
                tmp = d-abs(p.z-z);
                res += sum_of_rec(z, p.x-tmp, p.x+tmp, p.y-tmp, p.y+tmp);
            }
    }
    printf("%lld\n", (res-n)/2);
    return 0;
}
