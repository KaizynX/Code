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
        int l, r, cnt, add;
        long long sum;
    } tr[N<<2];
    void push_up(int i) {
        tr[i].cnt = tr[i<<1].cnt+tr[i<<1|1].cnt;
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
            tr[i].sum = tr[i].cnt = tr[i].add = 0;
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int l, int r, int k) {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].sum += 1ll*k*tr[i].cnt;
            tr[i].add += k;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r, k);
        if (r >  mid) update(i<<1|1, l, r, k);
        push_up(i);
    }
    void insert(int i, int x, int k) {
        if (tr[i].l == x && tr[i].r == x) {
            tr[i].cnt = 1;
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
            tr[i].sum = 0;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) erase(i<<1, x);
        else erase(i<<1|1, x);
        push_up(i);
    }
    long long query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        long long res = 0;
        if (l <= mid) res += query(i<<1, l, r);
        if (r >  mid) res += query(i<<1|1, l, r);
        return res;
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
} BIT;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    lmove.build(1, 1, n);
    rmove.build(1, 1, n);
    BIT.update(p[1], 1);
    long long sum = 0;
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
        lmove.update(1, max(l, p[i]), r, 1);
        rmove.update(1, l, min(r, p[i]), 1);
        l = min(l, p[i]);
        r = max(r, p[i]);
        sum += BIT.query(p[i], n);
        BIT.update(p[i], 1);
        int ll = l, rr = r;
        while (ll < rr) {
            int mid = (ll+rr+1)>>1;
            if (BIT.query(l, mid) <= i/2) ll = mid;
            else rr = mid-1;
        }
        res[i] = sum+lmove.query(1, l, ll)+rmove.query(1, ll+1, r);
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " \n"[i==n];
    return 0;
}
