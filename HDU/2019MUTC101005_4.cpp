#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int T, n, num;
int vis[MAXN<<1];
long long dis[MAXN<<1];

struct Tree
{
    int tr[MAXN<<1];
    void clear() { for (int i = 1; i <= num; ++i) tr[i] = 0; }
    void update(int x, int v) { for ( ; x <= num; x += x&-x) tr[x] += v; }
    int query(int x) { int res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    int query(int x, int y) { return query(y)-query(x-1); }
} tree;

struct Node
{
    long long x, y;
    Node () {}
    Node (long long _x, long long _y) : x(_x), y(_y) {}
} a[MAXN];

inline bool cmpx(const Node &p1, const Node &p2) { return p1.x < p2.x; }
inline bool cmpy(const Node &p1, const Node &p2) { return p1.y < p2.y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &a[i].x, &a[i].y);
            dis[i*2-1] = a[i].x;
            dis[i*2] = a[i].y;
        }
        sort(dis+1, dis+n*2+1);
        num = unique(dis+1, dis+2*n+1)-dis-1;
        tree.clear();
        for (int i = 1; i <= num; ++i) vis[i] = 0;
        long long res = dis[num]-dis[1], maxb = 0;
        int id = 1;
        sort(a+1, a+n+1, cmpy);
        for (int i = 1; i <= n; ++i) {
            while (dis[id] < a[i].y) ++id;
            a[i].y = id;
            tree.update(a[i].y, 1);
            ++vis[a[i].y];
        }
        id = 1;
        sort(a+1, a+n+1, cmpx);
        for (int i = 1; i <= n; ++i) {
            while (dis[id] < a[i].x) ++id;
            a[i].x = id;
        }
        reverse(a+1, a+n+1);
        for (int i = 1; i <= n; ++i) {
            tree.update(a[i].y, -1);
            --vis[a[i].y];

            if (vis[a[i].x]) {
                if (maxb <= dis[a[i].x]) {
                    res = 0;
                    break;
                } else {
                    res = min(res, abs(dis[a[i].x]-maxb));
                    continue;
                }
            }
            int cur = tree.query(a[i].x), l = 1, r = num;
            if (cur > 0) {
                while (l < r) {
                    int mid = (l+r)>>1;
                    if (tree.query(mid) < cur) l = mid+1;
                    else r = mid;
                }
                res = min(res, abs(max(maxb, dis[l])-dis[a[i].x]));
            }
            r = num;
            if (cur < n-i) {
                while (l < r) {
                    int mid = (l+r)>>1;
                    if (tree.query(mid) >= cur+1) r = mid;
                    else l = mid+1;
                }
                res = min(res, abs(max(maxb, dis[l])-dis[a[i].x]));
            }
            if(i!=1)res = min(res, abs(dis[a[i].x]-maxb));
            maxb = max(maxb, dis[a[i].y]);
        }
        printf("%lld\n", res);
    }
    return 0;
}
