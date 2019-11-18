#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

const int N = 2e5+7;

int n;
int k[3], a[3][N], pre[N], bac[N];

struct SegmentTree
{
    struct TreeNode
    {
        int mv, l, r;
    } tr[N<<2];
    void push_up(int i) { tr[i].mv = min(tr[i<<1].mv, tr[i<<1|1].mv); }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].mv = bac[l];
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    int query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].mv;
        int mid = (tr[i].l+tr[i].r)>>1, res = N;
        if (l <= mid) res = min(res, query(i<<1, l, r));
        if (r >  mid) res = min(res, query(i<<1|1, l, r));
        return res;
    }
} ST;

int main()
{
    for (int i = 0; i < 3; ++i) cin >> k[i], n += k[i];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < k[i]; ++j) cin >> a[i][j];
        sort(a[i], a[i]+k[i]);
    }
    for (int i = 0; i <= n+1; ++i) {
        // <= i
        pre[i] = a[0]+k[0]-upper_bound(a[0], a[0]+k[0], i)
                +upper_bound(a[1], a[1]+k[1], i)-a[1];
        // >= i
        bac[i] = lower_bound(a[2], a[2]+k[2], i)-a[2]
                +a[1]+k[1]-lower_bound(a[1], a[1]+k[1], i);
#ifdef DEBUG
        printf("%d pre:%d bac:%d\n", i, pre[i], bac[i]);
#endif
    }
    ST.build(1, 0, n+1);
    int res = n;
    for (int i = 0; i <= n; ++i) {
        res = min(res, pre[i]+ST.query(1, i+1, n+1));
    }
    cout << res << endl;
    return 0;
}
