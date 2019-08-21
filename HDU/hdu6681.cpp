#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int MAXN = 1e5+7;

int T, n, m, k;
long long res;

struct Point
{
    int x, xx, y, yy, d;
} a[MAXN];

inline bool cmpy(const Point &p1, const Point &p2) { return p1.y < p2.y; }
inline bool cmpx(const Point &p1, const Point &p2) {
    return p1.x == p2.x ? p1.d < p2.d : p1.x < p2.x;
}

struct Tree
{
    int tr[MAXN];
    void clear() { memset(tr, 0, sizeof(int)*(k+3)); }
    void update(int x, int v) { for ( ; x <= k; x += x&-x) tr[x] += v; }
    int query(int x) { int res = 0; for (; x; x -= x&-x) res += tr[x]; return res; }
    int query(int x, int y) { return query(y)-query(x-1); }
} tree;

int main()
{
    scanf("%d", &T);
    while (T--) {
        char c;
        scanf("%d%d%d", &n, &m, &k);
        res = 0;
        tree.clear();
        for (int i = 1; i <= k; ++i) {
            scanf("%d%d %c", &a[i].x, &a[i].y, &c);
            if (c == 'R') a[i].d = 0;
            if (c == 'U') a[i].d = 1;
            if (c == 'D') a[i].d = 2;
            if (c == 'L') a[i].d = 3;
        }
        
        sort(a+1, a+k+1, cmpy);
        a[1].yy = 2;
        for (int i = 2; i <= k; ++i) {
            a[i].yy = (a[i].y == a[i-1].y ? a[i].yy : a[i-1].yy+1);
            if (a[i].d == 3) {
                tree.update(a[i].yy, 1);
            }
        }
        m = a[k].yy+1;
        sort(a+1, a+k+1, cmpx);
        /*
        for (int i = 2; i <= k; ++i) {
            a[i].xx = (a[i].x == a[i-1].x ? a[i].xx : a[i-1].xx+1);
            if (a[i].d == 0) tree.update(a[i].yy, 1);
        }
        n = a[k].xx+1;
        */
        for (int i = 1; i <= k; ++i) {
            if (a[i].d == 3) {
                tree.update(a[i].yy, -1);
            } else if (a[i].d == 0) {
                tree.update(a[i].yy, 1);
            } else if (a[i].d == 1) {
                res += tree.query(1, a[i].yy);
#ifdef DEBUG
                printf("1 %lld\n", res);
#endif
            } else if (a[i].d == 2) {
                res += tree.query(a[i].yy, m);
#ifdef DEBUG
                printf("2 %lld\n", res);
#endif
            }
        }
        printf("%lld\n", res+1);
    }
    return 0;
}
