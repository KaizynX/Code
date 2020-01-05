#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;

int n;
int a[N], p[N];
long long res[N];

struct SegmentTree
{
    struct TreeNode
    {
        int l, r, mv, cnt, add;
        long long sum;
    } tr[N<<2];
    void push_up(int i) {
        tr[i].cnt = tr[i<<1].cnt+tr[i<<1|1].cnt;
        tr[i].mv = max(tr[i<<1].mv, tr[i<<1|1].mv);
        tr[i].sum = tr[i<<1].sum+tr[i<<1|1].sum;
    }
    void push_down(int i) {
        if (!tr[i].add) return;
        tr[i<<1].sum += 1ll*tr[i<<1].cnt*tr[i].add;
        tr[i<<1|1].sum += 1ll*tr[i<<1|1].cnt*tr[i].add;
        tr[i<<1].add += tr[i].add;
        tr[i<<1|1].add += tr[i].add;
        tr[i].add = 0;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].sum = tr[i].mv = tr[i].cnt = tr[i].add = 0;
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int l, int r, int k) {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].add += k;
            tr[i].sum += 1ll*tr[i].cnt*k;
            tr[i].mv += k;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r, k);
        if (r >  mid) update(i<<1|1, l, r, k);
        push_up(i);
    }
    int query_mv(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].mv;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        int res = 0;
        if (l <= mid) res = max(res, query_mv(i<<1, l, r));
        if (r >  mid) res = max(res, query_mv(i<<1|1, l, r));
        return res;
    }
    long long query_sum(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        long long res = 0;
        if (l <= mid) res += query_sum(i<<1, l, r);
        if (r >  mid) res += query_sum(i<<1|1, l, r);
        return res;
    }
    void insert(int i, int x, int k) {
        if (tr[i].l == x && tr[i].r == x) {
            tr[i].cnt = 1;
            tr[i].mv = k;
            tr[i].sum = k;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) insert(i<<1, x, k);
        else insert(i<<1|1, x, k);
        push_up(i);
    }
    void erase(int i, int x) {
        if (tr[i].l == x && tr[i].r == x) {
            tr[i].cnt = 0;
            tr[i].mv = 0;
            tr[i].sum = 0;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) erase(i<<1, x);
        else erase(i<<1|1, x);
        push_up(i);
    }
} lmove, rmove;

struct BinaryIndexedTree
{
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} st;

#ifdef DEBUG
inline pair<int, int> check(int l, int r) {
    int resi, resj;
    long long res = 1e18;
    for (int i = l; i < r; ++i) {
        long long tmp = lmove.query_sum(1, l, i)+rmove.query_sum(1, i+1, r);
        // printf("(%d %lld) ", i, tmp);
        if (tmp < res) {
            res = tmp;
            resi = i;
        } else if (tmp == res) {
            resj = i;
        }
    }
    return make_pair(resi, resj);
}
#endif

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    lmove.build(1, 1, n);
    rmove.build(1, 1, n);
    st.update(p[1], 1);
    long long add = 0;
    for (int i = 2, l = p[1], r = p[1]; i <= n; ++i) {
        for (int j = p[i]+1; j < l; ++j) {
            lmove.insert(1, j, 1);
            rmove.insert(1, j, i-1);
        }
        for (int j = r+1; j < p[i]; ++j) {
            lmove.insert(1, j, i-1);
            rmove.insert(1, j, 1);
        }
        lmove.erase(1, p[i]);
        rmove.erase(1, p[i]);
        lmove.update(1, max(p[i], l), r, 1);
        rmove.update(1, l, min(p[i], r), 1);
        l = min(l, p[i]);
        r = max(r, p[i]);
        add += st.query(p[i], n);
        st.update(p[i], 1);
        int ll = l, rr = r;
        while (ll < rr) {
            int mid = (ll+rr+1)>>1;
            if (lmove.query_mv(1, l, mid) <= rmove.query_mv(1, mid+1, r)) ll = mid;
            else rr = mid-1;
        }
        res[i] = add+lmove.query_sum(1, l, ll)+rmove.query_sum(1, ll+1, r);
#ifdef DEBUG
        printf("%d %d %d %d ", i, ll, lmove.query_mv(1, l, ll), rmove.query_mv(1, ll+1, r));
        pair<int, int> ppp = check(l, r);
        res[i] = add+lmove.query_sum(1, l, ppp.first)+rmove.query_sum(1, ppp.first+1, r);
        printf("[%d, %d] [%d %d] [%d %d]\n", ppp.first, ppp.second,
                lmove.query_mv(1, l, ppp.first), rmove.query_mv(1, ppp.first+1, r),
                lmove.query_mv(1, l, ppp.second), rmove.query_mv(1, ppp.second+1, r));
#endif
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " \n"[i==n];
    return 0;
}
