#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;

int n, m, tot;
int dp[N], mv[N];

struct Node
{
    int l, r;
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.l >> node.r;
    }
} a[N];

struct SegmenTree
{
    typedef int T;
    static const T INF = 1e9;
    struct TreeNode
    {
        int l, r;
        T lazy, mv;
    } tr[N<<2];
    void push_up(int i) { tr[i].mv = min(tr[i<<1].mv, tr[i<<1|1].mv); }
    void push_down(int i) {
        tr[i<<1].mv = min(tr[i<<1].mv, tr[i].lazy);
        tr[i<<1|1].mv = min(tr[i<<1|1].mv, tr[i].lazy);
        tr[i<<1].lazy = min(tr[i<<1].lazy, tr[i].lazy);
        tr[i<<1|1].lazy = min(tr[i<<1|1].lazy, tr[i].lazy);
        tr[i].lazy = INF;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        tr[i].lazy = INF;
        if (l == r) {
            tr[i].mv = l;
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int x, T k) {
        if (tr[i].l == x && tr[i].r == x) {
            tr[i].mv = min(tr[i].mv, k);
            tr[i].lazy = min(tr[i].lazy, k);
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) update(i<<1, x, k);
        else update(i<<1|1, x, k);
        push_up(i);
    }
    void update(int i, int l, int r, T k) {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].mv = min(tr[i].mv, k);
            tr[i].lazy = min(tr[i].lazy, k);
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r, k);
        if (r >  mid) update(i<<1|1, l, r, k);
        push_up(i);
    }
    T query(int i, int x) {
        if (tr[i].l == x && tr[i].r == x) return tr[i].mv;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) return query(i<<1, x);
        else return query(i<<1|1, x);
    }
    T query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].mv;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        T res = 0;
        if (l <= mid) res = min(res, query(i<<1, l, r));
        if (r >  mid) res = min(res, query(i<<1|1, l, r));
        return res;
    }
} ST;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    ST.build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        ST.update(1, a[i].l, a[i].r, a[i].l);
    }
    for (int i = 1; i <= n; ++i) {
#ifdef DEBUG
        cout << ST.query(1, i) << ", ";
#endif
        dp[i] = mv[ST.query(1, i)-1]+1;
        mv[i] = max(mv[i-1], dp[i]);
    }
    cout << mv[n] << endl;
    return 0;
}
