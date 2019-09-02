#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int MAXN = 2e5+7;
const long long INF = 1e18;

int n;
int p[MAXN];
long long s[MAXN];

struct SegmentTree
{
    // set your type
    typedef long long T;
    struct Node
    {
        int l, r;
        T mv, lazy;
    } tr[MAXN<<2];

    inline void push_up(int i)
    {
        tr[i].mv = min(tr[i<<1].mv, tr[i<<1|1].mv);
    }

    inline void push_down(int i)
    {
        if (!tr[i].lazy) return;
        tr[i<<1].mv += tr[i].lazy;
        tr[i<<1|1].mv += tr[i].lazy;
        tr[i<<1].lazy += tr[i].lazy;
        tr[i<<1|1].lazy += tr[i].lazy;
        tr[i].lazy = 0;
    }

    void build(int i, int l, int r)
    {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].mv = s[l];
            return;
        }
        int mid  = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }

    void update(int i, int l, int r, T v)
    {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].lazy += v;
            tr[i].mv += v;
            return;
        }
        push_down(i);
        int mid  = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1  , l, r, v);
        if (r >  mid) update(i<<1|1, l, r, v);
        push_up(i);
    }

    int query(int i)
    {
        if (tr[i].l == tr[i].r) return tr[i].l;
        push_down(i);
        if (tr[i<<1|1].mv == 0) return query(i<<1|1);
        else return query(i<<1);
    }

} ST;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    ST.build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        int pos = ST.query(1);
#ifdef DEBUG
        cout << i << " " << pos << endl;
#endif
        p[pos] = i;
        ST.update(1, pos, pos, INF);
        if (pos < n) ST.update(1, pos+1, n, -i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
