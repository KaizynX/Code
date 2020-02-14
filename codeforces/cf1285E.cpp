#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;

int n, m, T;
int l[N], r[N];

struct SegmenTree
{
    struct TreeNode
    {
        int l, r, add;
        int cnt[2];
    } tr[N<<2];
    void push_up(int i) {
        tr[i].cnt[0] = tr[i<<1].cnt[0]+tr[i<<1|1].cnt[0];
        tr[i].cnt[1] = tr[i<<1].cnt[1]+tr[i<<1|1].cnt[1];
    }
    void push_down(int i) {
        if (!tr[i].add) return;
        tr[i<<1].add += tr[i].add;
        tr[i<<1|1].add += tr[i].add;
        if (tr[i].add == 1) {
            tr[i<<1].cnt[1] = tr[i<<1].cnt[0];
            tr[i<<1|1].cnt[1] = tr[i<<1|1].cnt[0];
            tr[i<<1].cnt[0] = 0;
            tr[i<<1|1].cnt[0] = 0;
        } else {
            tr[i<<1].cnt[0] = 0;
            tr[i<<1|1].cnt[0] = 0;
            tr[i<<1].cnt[1] = 0;
            tr[i<<1|1].cnt[1] = 0;
        }
        tr[i].add = 0;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].add = 0;
            tr[i].cnt[0] = 1;
            tr[i].cnt[1] = 0;
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) {
            ++tr[i].add;
            tr[i].cnt[1] = tr[i].cnt[0];
            tr[i].cnt[0] = 0;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r);
        if (r >  mid) update(i<<1|1, l, r);
        push_up(i);
    }
    int query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].cnt[1];
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1, res = 0;
        if (l <= mid) res += query(i<<1, l, r);
        if (r >  mid) res += query(i<<1|1, l, r);
        return res;
    }
} ST;

void descrete()
{
    static vector<int> d;
    d.resize(n*2, 0);
    for (int i = 1; i <= n; ++i) {
        d[i*2-2] = l[i];
        d[i*2-1] = r[i];
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    m = d.size()*2-1;
    for (int i = 1; i <= n; ++i) {
        l[i] = lower_bound(d.begin(), d.end(), l[i])-d.begin()+1;
        r[i] = lower_bound(d.begin(), d.end(), r[i])-d.begin()+1;
        l[i] = l[i]*2-1;
        r[i] = r[i]*2-1;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", l+i, r+i);
        }
        descrete();
        ST.build(1, 1, m);
        for (int i = 1; i <= n; ++i) {
            ST.update(1, l[i], r[i]);
        }
        int base = ST.tr[1].cnt[0]+1, res = 0;
#ifdef DEBUG
        for (int i = 1; i <= n; ++i)
            printf("(%d, %d)\n", l[i], r[i]);
        printf("m = %d, res = %d\n", m, res);
#endif
        for (int i = 1; i <= n; ++i) {
            res = max(res, base+ST.query(1, l[i], r[i]));
#ifdef DEBUG
            printf("(%d, %d)\n", i, base+ST.query(1, l[i], r[i]));
#endif
        }
        printf("%d\n", res);
    }
    return 0;
}
