#include <vector>
#include <iostream>
#include <algorithm>
#define DEBUG

using namespace std;

const int MAXN = 1e5+7;

int n, num_x, num_y;
long long res;
int disx[MAXN<<1], disy[MAXN<<1];
vector<int> add[MAXN<<1], del[MAXN<<1];

struct Rec
{
    int x1, x2, y1, y2;
} a[MAXN];

struct SegmentTree
{
    struct Node
    {
        int l, r, dep = 0, wid = 0;
    } tr[MAXN<<3];

    inline void push_up(int i)
    {
        tr[i].wid = (tr[i].dep ? disy[tr[i].r+1]-disy[tr[i].l] : tr[i<<1].wid+tr[i<<1|1].wid);
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
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        disx[i*2-1] = a[i].x1;
        disx[i*2] = a[i].x2;
        disy[i*2-1] = a[i].y1;
        disy[i*2] = a[i].y2;
    }
    // discrete
    sort(disx+1, disx+n*2+1);
    sort(disy+1, disy+n*2+1);
    num_x = unique(disx+1, disx+n*2+1)-disx-1;
    num_y = unique(disy+1, disy+n*2+1)-disy-1;
    for (int i = 1; i <= n; ++i) {
        a[i].x1 = lower_bound(disx+1, disx+num_x+1, a[i].x1)-disx;
        a[i].x2 = lower_bound(disx+1, disx+num_x+1, a[i].x2)-disx;
        a[i].y1 = lower_bound(disy+1, disy+num_y+1, a[i].y1)-disy;
        a[i].y2 = lower_bound(disy+1, disy+num_y+1, a[i].y2)-disy;
        add[a[i].x1].push_back(i);
        del[a[i].x2].push_back(i);
    }

    ST.build(1, 1, num_y-1);
    for (int i = 1; i <= num_x; ++i) {
        res += 1ll*ST.tr[1].wid*(disx[i]-disx[i-1]);
#ifdef DEBUG
        printf("%d %d\n", ST.tr[1].wid, (disx[i]-disx[i-1]));
#endif
        for (auto p : add[i]) {
            ST.update(1, a[p].y1, a[p].y2-1, 1);
        }
        for (auto p : del[i]) {
            ST.update(1, a[p].y1, a[p].y2-1, -1);
        }
    }
    printf("%lld\n", res);
    return 0;
}
