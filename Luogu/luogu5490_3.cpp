#include <vector>
#include <iostream>
#include <algorithm>
#define DEBUG

using namespace std;

const int MAXN = 1e5+7;

int n, num;
long long res;
int dis[MAXN<<1];

struct Rec
{
    int x, y1, y2, v;
    bool operator < (const Rec &nex) const {
        //return x == nex.x ? v > nex.v : x < nex.x;
        return x < nex.x;
    }
} a[MAXN<<1];

struct SegmentTree
{
    struct Node
    {
        int l, r, dep = 0, wid = 0;
    } tr[MAXN<<3];

    inline void push_up(int i)
    {
        tr[i].wid = (tr[i].dep ? dis[tr[i].r+1]-dis[tr[i].l] : tr[i<<1].wid+tr[i<<1|1].wid);
    }

    void build(int i, int l, int r)
    {
        tr[i].l = l; tr[i].r = r;
        if (l == r) return;
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
    }

    void update(int i, int l, int r, int v)
    {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].dep += v;
            push_up(i);
            return;
        }
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r, v);
        if (r >  mid) update(i<<1|1, l, r, v);
        push_up(i);
    }
} ST;

int main()
{
    scanf("%d", &n);
    for (int i = 1, x1, x2, y1, y2; i <= n; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        a[i*2-1].x = x1; a[i*2].x = x2;
        a[i*2-1].v = 1; a[i*2].v = -1;
        a[i*2-1].y1 = a[i*2].y1 = y1;
        a[i*2-1].y2 = a[i*2].y2 = y2;
        dis[i*2-1] = y1;
        dis[i*2] = y2;
    }
    // discrete
    sort(dis+1, dis+n*2+1);
    num = unique(dis+1, dis+n*2+1)-dis-1;
    for (int i = 1; i <= n*2; ++i) {
        a[i].y1 = lower_bound(dis+1, dis+num+1, a[i].y1)-dis;
        a[i].y2 = lower_bound(dis+1, dis+num+1, a[i].y2)-dis;
    }

    sort(a+1, a+n*2+1);
    ST.build(1, 1, num-1);
    for (int i = 1; i <= n*2; ++i) {
        res += 1ll*ST.tr[1].wid*(a[i].x-a[i-1].x);
#ifdef DEBUG
        printf("%d %d\n", ST.tr[1].wid, a[i].x-a[i-1].x);
#endif
        ST.update(1, a[i].y1, a[i].y2-1, a[i].v);
        /*
        res += 1ll*ST.tr[1].wid*(a[i+1].x-a[i].x);
#ifdef DEBUG
        printf("%d %d\n", ST.tr[1].wid, a[i+1].x-a[i].x);
#endif
        */
    }
    printf("%lld\n", res);
    return 0;
}
