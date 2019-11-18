#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e5+7;

int T, n, m, tot;
int a[N], c[N<<1], d[N<<1];

struct Hero
{
    int p, s;
    Hero(){}
    Hero(int _p, int _s = 0) : p(_p), s(_s) {}
    friend bool operator < (const Hero &x, const Hero &y) {
        return x.p < y.p;
    }
} b[N];

struct SegmentTree
{
    struct TreeNode
    {
        int mv, l, r;
    } tr[N<<3];
    void push_up(int i) { tr[i].mv = max(tr[i<<1].mv, tr[i<<1|1].mv); }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].mv = c[l];
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    int query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].mv;
        int mid = (tr[i].l+tr[i].r)>>1, res = 0;
        if (l <= mid) res = max(res, query(i<<1, l, r));
        if (r >  mid) res = max(res, query(i<<1|1, l, r));
        return res;
    }
} ST;


int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int mxa = 0, mxp = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            d[i] = a[i];
            mxa = max(mxa, a[i]);
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &b[i].p, &b[i].s);
            d[n+i] = b[i].p;
            mxp = max(mxp, b[i].p);
        }
        if (mxa > mxp) {
            cout << -1 << endl;
            continue;
        }

        sort(d+1, d+n+m+1);
        tot = unique(d+1, d+n+m+1)-d-1;
        for (int i = 1; i <= n; ++i) a[i] = lower_bound(d+1, d+tot+1, a[i])-d;
        for (int i = 1; i <= m; ++i) b[i].p = lower_bound(d+1, d+tot+1, b[i].p)-d;
        for (int i = 1; i <= tot; ++i) c[i] = 0;
        for (int i = 1; i <= m; ++i) c[b[i].p] = max(c[b[i].p], b[i].s);

        ST.build(1, 1, tot);
        mxa = 0;
        int res = 0;
        for (int i = 1, cnt = 0; i <= n; ++i) {
            mxa = max(mxa, a[i]);
#ifdef DEBUG
            printf("%d %d\n", mxa, ST.query(1, mxa, tot));
#endif
            if (cnt+1 > ST.query(1, mxa, tot)) {
                mxa = a[i];
                cnt = 1;
                ++res;
            } else {
                ++cnt;
            }
        }
        cout << res+1 << endl;
    }
    return 0;
}
