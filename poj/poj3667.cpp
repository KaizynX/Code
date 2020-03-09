#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cctype>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e4+7;

template <typename T>
struct SegmentTree
{
    struct TreeNode
    {
        int l, r, tag, lef, rig, mxl;
        T lazy, lv, rv;
        TreeNode operator = (const T &v) {
            lazy = tag = 0;
            lv = rv = lef = rig = mxl = v;
            return *this;
        }
        int size() const { return r-l+1; }
    } tr[N<<2];
    void push_up(const int &i) {
        tr[i].lv = tr[i<<1].lv;
        tr[i].rv = tr[i<<1|1].rv;
        tr[i].lef = tr[i<<1].lef;
        tr[i].rig = tr[i<<1|1].rig;
        tr[i].mxl = max(tr[i<<1].rig+tr[i<<1|1].lef, max(tr[i<<1].mxl, tr[i<<1|1].mxl));
        if (tr[i<<1].lef == tr[i<<1].size()) tr[i].lef += tr[i<<1|1].lef;
        if (tr[i<<1|1].rig == tr[i<<1|1].size()) tr[i].rig += tr[i<<1].rig;
    }
    void push_down(const int &i) {
        if (!tr[i].tag) return;
        tr[i<<1].lv = tr[i<<1].rv = tr[i<<1|1].lv = tr[i<<1|1].rv = tr[i].lazy;
        tr[i<<1].lef = tr[i<<1].rig = tr[i<<1].mxl = tr[i].lazy ? tr[i<<1].size() : 0;
        tr[i<<1|1].lef = tr[i<<1|1].rig = tr[i<<1|1].mxl = tr[i].lazy ? tr[i<<1|1].size() : 0;
        tr[i<<1].lazy = tr[i<<1|1].lazy = tr[i].lazy;
        tr[i<<1].tag = tr[i<<1|1].tag = 1;
        tr[i].tag = 0;
    }
    void build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) { tr[i] = k; return; }
        int mid = (l+r)>>1;
        build(l, mid, k, i<<1);
        build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    void update(const int &l, const int &r, const T &k, const int &i = 1) {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].lef = tr[i].rig = tr[i].mxl = k ? tr[i].size() : 0;
            tr[i].lv = tr[i].rv = k;
            tr[i].lazy = k;
            tr[i].tag = 1;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(l, r, k, i<<1);
        if (r >  mid) update(l, r, k, i<<1|1);
        push_up(i);
    }
    T query(const int &x, const int &i = 1) {
        if (tr[i].l == tr[i].r) return tr[i].l;
        push_down(i);
        if (tr[i<<1].mxl >= x) return query(x, i<<1);
        if (tr[i<<1].rig+tr[i<<1|1].lef >= x) return tr[i<<1].r-tr[i<<1].rig+1;
        return query(x, i<<1|1);
    }
};

SegmentTree<int> ST;

inline void solve()
{
    int n, m, op, x, d;
    scanf("%d %d", &n, &m);
    ST.build(1, n, 1);
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &d);
            int p = ST.query(d);
            if (p) ST.update(p, p+d-1, 0);
            printf("%d\n", p);
        } else {
            scanf("%d %d", &x, &d);
            ST.update(x, x+d-1, 1);
        }
    }
}

int main()
{
    int T = 1;
    while (T--) solve();
    return 0;
}
