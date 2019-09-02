#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int T, n, m;
int a[MAXN], b[MAXN];

struct SegmentTree
{
    struct Node
    {
        int l, r, id = 0;
    } tr[MAXN<<2];

    inline void push_up(int i)
    {
        tr[i].id = max(tr[i<<1].id, tr[i<<1|1].id);
    }

    void build(int i, int l, int r)
    {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].id = b[l];
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }

    void del(int i, int x)
    {
        if (tr[i].l == tr[i].r) {
            tr[i].id = n+1;
            return;
        }
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) del(i<<1, x);
        else del(i<<1|1, x);
        push_up(i);
    }

    int query(int i, int r, int k)
    {
        if (tr[i].l == tr[i].r) return tr[i].l;
        int mid = (tr[i].l+tr[i].r)>>1, res = n+1;
        if (k <= mid && tr[i<<1].id > r) {
            res = query(i<<1, r, k);
        }
        if (res != n+1) return res;
        if (tr[i<<1|1].id > r) {
            res = query(i<<1|1, r, k);
        }
        return res;
    }
} ST;

int main()
{
    scanf("%d", &T);
    while (T--) {
        int last_ans = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            b[a[i]] = i;
        }
        ST.build(1, 1, n);
        for (int i = 1, op, t1, t2, pos, r, k; i <= m; ++i) {
            scanf("%d %d", &op, &t1);
            if (op == 1) {
                pos = t1^last_ans;
                ST.del(1, a[pos]);
            } else {
                scanf("%d", &t2);
                r = t1^last_ans;
                k = t2^last_ans;
                last_ans = ST.query(1, r, k);
                printf("%d\n", last_ans);
            }
        }
    }
    return 0;
}
