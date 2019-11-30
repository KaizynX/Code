#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m;
int aa[N], res[N];

struct BinaryIndexedTree
{
    // set your type
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

struct Node
{
    int v, id;
    friend bool operator < (const Node &x, const Node &y) {
        return x.v == y.v ? x.id < y.id : x.v > y.v;
    }
} a[N];

struct Query
{
    int k, p, id;
    friend bool operator < (const Query &x, const Query &y) {
        return x.k < y.k;
    }
} q[N];

inline bool cmp(const Node &x, const Node &y) {
    return x.id < y.id;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> aa[i];
        a[i].v = aa[i];
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].k >> q[i].p;
        q[i].id = i;
    }
    sort(q+1, q+m+1);

    for (int i = 1, now = 0; i <= m; ++i) {
        while (now < q[i].k) BIT.update(a[++now].id, 1);
        int l = 1, r = n;
        while (l < r) {
            int mid = (l+r)>>1;
            if (BIT.query(mid) >= q[i].p) r = mid;
            else l = mid+1;
        }
        res[q[i].id] = aa[l];
    }
    for (int i = 1; i <= m; ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
