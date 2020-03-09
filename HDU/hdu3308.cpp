#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;
int a[N];

struct TreeNode
{
    int l, r;
    int lef, rig, mxl;
    int size() const { return r-l+1; }
} tr[N<<2];

inline void push_up(TreeNode &rt, const TreeNode &ls, const TreeNode &rs)
{
    rt.l = ls.l; rt.r = rs.r;
    rt.lef = ls.lef; rt.rig = rs.rig;
    rt.mxl = max(ls.mxl, rs.mxl);
    if (a[ls.r] < a[rs.l]) {
        rt.mxl = max(rt.mxl, ls.rig+rs.lef);
        if (ls.lef == ls.size()) rt.lef += rs.lef;
        if (rs.rig == rs.size()) rt.rig += ls.rig;
    }
}

void build(const int &l, const int &r, const int &i = 1)
{
    tr[i].l = l; tr[i].r = r;
    if (l == r) {
        tr[i].lef = tr[i].rig = tr[i].mxl = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
    // push_up(i);
    push_up(tr[i], tr[i<<1], tr[i<<1|1]);
}

void update(const int &x, const int &k, const int &i = 1)
{
    if (tr[i].l == x && tr[i].r == x) {
        a[x] = k;
        return;
    }
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) update(x, k, i<<1);
    else update(x, k, i<<1|1);
    // push_up(i);
    push_up(tr[i], tr[i<<1], tr[i<<1|1]);
}

TreeNode _query(const int &l, const int &r, const int &i = 1)
{
    if (tr[i].l >= l && tr[i].r <= r) return tr[i];
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return _query(l, r, i<<1);
    if (l >  mid) return _query(l, r, i<<1|1);
    TreeNode res;
    push_up(res, _query(l, r, i<<1), _query(l, r, 1<<1|1));
    return res;
}

inline int query(const int &l, const int &r)
{
    return _query(l, r).mxl;
}

inline void solve()
{
    char op;
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, n);
    while (m--) {
        cin >> op >> x >> y;
        if (op == 'U') update(x+1, y);
        else cout << query(x+1, y+1) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
