#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

template <typename T>
struct SegmentTree
{
    T tr[N<<2], lazy[N<<2];
    SegmentTree(){}
    void push_up(const int &i) { tr[i] = tr[i<<1]+tr[i<<1|1]; }
    void push_down(const int &i, const int &len) {
        if (!lazy[i]) return;
        tr[i<<1] += lazy[i]*(len-len/2);
        tr[i<<1|1] += lazy[i]*(len/2);
        lazy[i<<1] += lazy[i];
        lazy[i<<1|1] += lazy[i];
        lazy[i] = 0;
    }
    void build(const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = 0; return; }
        int mid = (l+r)>>1;
        build(l, mid, i<<1);
        build(mid+1, r, i<<1|1);
        push_up(i);
    }
    template <typename TT>
    void build(const TT a[], const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = a[l]; return; }
        int mid = (l+r)>>1;
        build(a, l, mid, i<<1);
        build(a, mid+1, r, i<<1|1);
        push_up(i);
    }
    void modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            lazy[i] = 0;
            return;
        }
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (x <= mid) update(x, k, trl, mid, i<<1);
        else update(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    void add(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) {
            tr[i] += k*(trr-trl+1);
            lazy[i] += k;
            return;
        }
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (l <= mid) add(l, r, k, trl, mid, i<<1);
        if (r >  mid) add(l, r, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        T res = 0;
        if (l <= mid) res += query(l, r, trl, mid, i<<1);
        if (r >  mid) res += query(l, r, mid+1, trr, i<<1|1);
        return res;
    }
};

int n, m;
int a[N];
SegmentTree<long long> ST;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    ST.build(a, 1, n);
    for (int i = 1, op, x, y; i <= m; ++i) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            long long k;
            scanf("%lld", &k);
            ST.add(x, y, k, 1, n);
        } else {
            printf("%lld\n", ST.query(x, y, 1, n));
        }
    }
    return 0;
}
