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

inline void push_up(const int &i)
{
    tr[i].lef = tr[i<<1].lef;
    tr[i].rig = tr[i<<1|1].rig;
    tr[i].mxl = max(tr[i<<1].mxl, tr[i<<1|1].mxl);
    if (a[tr[i<<1].r] < a[tr[i<<1|1].l]) {
        tr[i].mxl = max(tr[i].mxl, tr[i<<1].rig+tr[i<<1|1].lef);
        if (tr[i<<1].lef == tr[i<<1].size()) tr[i].lef += tr[i<<1|1].lef;
        if (tr[i<<1|1].rig == tr[i<<1|1].size()) tr[i].rig += tr[i<<1].rig;
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
    push_up(i);
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
    push_up(i);
}

int query(const int &l, const int &r, const int &i = 1)
{
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].mxl;
    int mid = (tr[i].l+tr[i].r)>>1, res = 0;
    if (l <= mid) res = max(res, query(l, r, i<<1));
    if (r >  mid) res = max(res, query(l, r, i<<1|1));
    if (a[tr[i<<1].r] < a[tr[i<<1|1].l])
        res = max(res, min(mid-l+1, tr[i<<1].rig)+min(r-mid, tr[i<<1|1].lef));
    return res;
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
