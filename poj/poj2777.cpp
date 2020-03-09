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

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int K = 31;

template <typename T>
struct SegmentTree
{
    int sz;
    int tag[N<<2];
    T tr[N<<2], lazy[N<<2];
    SegmentTree(){}
    void build(const int &n, const T &k = 0) { sz = n; _build(1, n, k); }
    template <typename TT>
    void build(const TT a[], const int &n) { sz = n; _build(a, 1, n); }
    void update(const int &x, const T &k) { _update(x, x, k, 1, sz); }
    void update(int l, int r, const T &k) { if (l > r) swap(l, r); _update(l, r, k, 1, sz); }
    // __builtin_popcount(x)
    T query(const int &x) { return __builtin_popcount(_query(x, x, 1, sz)); }
    T query(int l, int r) { if (l > r) swap(l, r); return __builtin_popcount(_query(l, r, 1, sz)); }
private :
    void push_up(const int &i) { tr[i] = tr[i<<1]|tr[i<<1|1]; }
    void push_down(const int &i) {
        if (!tag[i]) return;
        tr[i<<1] = 1<<lazy[i];
        tr[i<<1|1] = 1<<lazy[i];
        lazy[i<<1] = lazy[i<<1|1] = lazy[i];
        tag[i<<1] = tag[i<<1|1] = 1;
        tag[i] = 0;
    }
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        lazy[i] = tag[i] = 0;
        if (l == r) { tr[i] = 1<<k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    template <typename TT>
    void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
        lazy[i] = tag[i] = 0;
        if (l == r) { tr[i] = 1<<a[l]; return; }
        int mid = (l+r)>>1;
        _build(a, l, mid, i<<1);
        _build(a, mid+1, r, i<<1|1);
        push_up(i);
    }
    void _update(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) {
            tr[i] = 1<<k;
            lazy[i] = k;
            tag[i] = 1;
            return;
        }
        push_down(i);
        int mid = (trl+trr)>>1;
        if (l <= mid) _update(l, r, k, trl, mid, i<<1);
        if (r >  mid) _update(l, r, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        push_down(i);
        int mid = (trl+trr)>>1;
        T res = 0;
        if (l <= mid) res |= _query(l, r, trl, mid, i<<1);
        if (r >  mid) res |= _query(l, r, mid+1, trr, i<<1|1);
        return res;
    }
};

SegmentTree<int> ST;

inline void solve()
{
    char op;
    int n, k, q, a, b, c;
    scanf("%d %d %d", &n, &k, &q);
    ST.build(n);
    while (q--) {
        // getchar(); scanf("%c", &op);
        scanf("%*[ \n]%c", &op);
        if (op == 'C') {
            scanf("%d %d %d", &a, &b, &c);
            ST.update(a, b, c-1);
        } else if (op == 'P') {
            scanf("%d %d", &a, &b);
            printf("%d\n", ST.query(a, b));
        }
    }
}

int main()
{
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
