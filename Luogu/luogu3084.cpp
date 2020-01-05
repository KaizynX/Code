#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m, tot;
int dp[N], mv[N];

struct Node
{
    int l, r;
    Node(){}
    Node(int _l, int _r) : l(_l), r(_r) {}
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
        T mv;
    } tr[N<<2];
    void push_up(int i) { tr[i].mv = max(tr[i<<1].mv, tr[i<<1|1].mv); }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) return;
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
    }
    void update(int i, int x, T k) {
        if (tr[i].l == x && tr[i].r == x) {
            tr[i].mv = max(tr[i].mv, k);
            return;
        }
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) update(i<<1, x, k);
        else update(i<<1|1, x, k);
        push_up(i);
    }
    T query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r)
            return tr[i].mv;
        int mid = (tr[i].l+tr[i].r)>>1;
        T res = 0;
        if (l <= mid) res = max(res, query(i<<1, l, r));
        if (r >  mid) res = max(res, query(i<<1|1, l, r));
        return res;
    }
} ST;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+m+1);
    tot = m;
    int last = 0;
    for (int i = 1; i <= m; ++i) {
        if (last < a[i].l) {
            for (int j = last+1; j < a[i].l; ++j) {
                a[++tot] = Node(j, j);
            }
        }
        last = max(last, a[i].r);
    }
    if (last < n) {
        for (int i = last+1; i <= n; ++i)
            a[++tot] = Node(i, i);
    }
    sort(a+1, a+tot+1);
    ST.build(1, 1, n+1);
    for (int i = 1; i <= tot; ++i) {
        dp[a[i].r] = max(dp[a[i].r], ST.query(1, 1, a[i].l)+1);
        ST.update(1, a[i].r+1, dp[a[i].r]);
    }
    for (int i = 1; i <= tot; ++i) {
        if (dp[a[i].r] < ST.query(1, a[i].l+1, a[i].r+1)) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ST.query(1, 1, n+1) << endl;
    return 0;
}
