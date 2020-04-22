/*
 * @Author: Kaizyn
 * @Date: 2020-04-21 21:08:40
 * @LastEditTime: 2020-04-22 09:47:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int K = 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    U cmp = U();
    int n;
    T tr[N<<2], lazy[N<<2], init_val = cmp(0, 1) ? INF : -INF;
    SegmentTree(){}
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
    T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
    void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
    void push_down(const int &i) {
        if (!lazy[i]) return;
        tr[i<<1] += lazy[i];
        tr[i<<1|1] += lazy[i];
        lazy[i<<1] += lazy[i];
        lazy[i<<1|1] += lazy[i];
        lazy[i] = 0;
    }
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            return;
        }
        push_down(i);
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        push_down(i);
        int mid = (trl+trr)>>1;
        T res = init_val;
        if (l <= mid) res = mv(res, _query(l, r, trl, mid, i<<1));
        if (r >  mid) res = mv(res, _query(l, r, mid+1, trr, i<<1|1));
        return res;
    }
};

int n, k, q;
int a[N][K];
int va[N][1<<K];
int lg2[1<<K];
SegmentTree<int> ST[1<<K];

inline void calc(const int &x) {
    va[x][0] = 0;
    for (int i = 0; i < k; ++i) {
        va[x][0] -= a[x][i];
    }
    for (int i = 1, j; i < 1<<k; ++i) {
        j = i&-i;
        va[x][i] = va[x][i^j]+2*a[x][lg2[j]];
    }
}

inline void update(const int &x) {
    for (int i = 0; i < 1<<k; ++i) {
        ST[i].modify(x, va[x][i]);
    }
}

signed main()
{
    for (int i = 1; i < K; ++i) lg2[1<<i] = i;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 1<<k; ++i) ST[i].build(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[i][j]);
        }
        calc(i);
        update(i);
    }
    scanf("%d", &q);
    int op, x, l, r, res;
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            for (int i = 0; i < k; ++i) {
                scanf("%d", &a[x][i]);
            }
            calc(x);
            update(x);
        } else {
            scanf("%d %d", &l, &r);
            res = -INF;
            for (int i = 0, j, base = (1<<k)-1; i <= base; ++i) {
                j = base^i;
                res = max(res, ST[i].query(l, r)+ST[j].query(l, r));
            }
            printf("%d\n", res);
        }
    }
    return 0;
}