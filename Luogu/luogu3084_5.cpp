#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int M = 1e5+7;

int n, m;
int dp[N], lef[N], tag[N];

struct Node
{
    int l, r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.l < n2.l;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.l >> node.r;
    }
} a[N];

struct SegmenTree
{
    typedef int T;
    struct TreeNode
    {
        int l, r;
        T lazy, mv;
    } tr[N<<2];
    T cmp(const T &x, const T &y) { return max(x, y); }
    void push_up(int i) { tr[i].mv = cmp(tr[i<<1].mv, tr[i<<1|1].mv); }
    void push_down(int i) {
        tr[i<<1].mv = cmp(tr[i<<1].mv, tr[i].lazy);
        tr[i<<1|1].mv = cmp(tr[i<<1|1].mv, tr[i].lazy);
        tr[i<<1].lazy = cmp(tr[i<<1].lazy, tr[i].lazy);
        tr[i<<1|1].lazy = cmp(tr[i<<1|1].lazy, tr[i].lazy);
        tr[i].lazy = 0;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        tr[i].lazy = 0;
        if (l == r) {
            tr[i].mv = 0;
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int x, T k) {
        if (tr[i].l == x && tr[i].r == x) {
            tr[i].mv = cmp(tr[i].mv, k);
            tr[i].lazy = cmp(tr[i].lazy, k);
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
            tr[i].mv = cmp(tr[i].mv, k);
            tr[i].lazy = cmp(tr[i].lazy, k);
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
        if (l > r) return -1;
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].mv;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        T res = 0;
        if (l <= mid) res = cmp(res, query(i<<1, l, r));
        if (r >  mid) res = cmp(res, query(i<<1|1, l, r));
        return res;
    }
} ST;

int main()
{
    cin >> n >> m;
    ST.build(1, 1, n+1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        tag[a[i].r+1] = max(tag[a[i].r+1], a[i].l);
    }
    sort(a+1, a+m+1);
    for (int i = 1; i <= n; ++i) {
        lef[i] = i;
        tag[i] = max(tag[i], tag[i-1]);
    }
    for (int i = 1, lastl = 0, lastr = 0; i <= m; ++i) {
        if (a[i].l > lastr) {
            for (int j = lastl; j <= lastr; ++j)
                lef[j] = lastl;
            lastl = a[i].l;
        }
        lastr = max(lastr, a[i].r);
        if (i == m) {
            for (int j = lastl; j <= lastr; ++j)
                lef[j] = lastl;
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = ST.query(1, tag[i]+1, lef[i])+1;
        ST.update(1, i+1, dp[i]);
#ifdef DEBUG
        printf("%d %d %d %d\n", i ,tag[i], lef[i], dp[i]);
#endif
    }
    cout << ST.query(1, 1, n+1);
    return 0;
}
