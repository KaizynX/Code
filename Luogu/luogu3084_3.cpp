#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;

int n, m;
int dp[N];
vector<int> a[N];

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
        if (l > r) return 0;
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
    scanf("%d %d", &n, &m);
    for (int i = 1, l, r; i <= m; ++i) {
        scanf("%d %d", &l, &r);
        a[r].emplace_back(l);
    }
    int last = n+1;
    for (int i = n; i; --i) {
        if (a[i].empty()) continue;
        for (int j = i+1; j < last; ++j)
            a[j].emplace_back(j);
        for (int j : a[i])
            last = min(last, j);
    }
    for (int i = 1; i < last; ++i)
        a[i].emplace_back(i);

    ST.build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        for (int j : a[i]) {
            int pre = ST.query(1, 1, j-1),
                bac = ST.query(1, j, i-1);
            if (pre+1 < bac) return puts("-1")&0;
            // pre+1 >= bac
            dp[i] = max(dp[i], pre+1);
        }
        // dp[i] = max(dp[i], dp[i-1]);
        ST.update(1, i, dp[i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}
