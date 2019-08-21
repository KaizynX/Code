#include <bits/stdc++.h>

using namespace std;

const int kN = 2e5+7;
const int kM = 4e6+7;

int n, m, dn, tr_id;
int root[kN], dis[kN];

struct Node
{
    int id, v;
} a[kN];

struct Tree
{
    int sum = 0, ls = 0, rs = 0;
} tr[kM];

inline void push_up(int i)
{
    tr[i].sum = tr[tr[i].ls].sum + tr[tr[i].rs].sum;
}

void build_tree(int li, int ri, int l, int r, int v)
{
    if (l == v && r == v) {
        ++tr[ri].sum;
        return;
    }
    int mid = (l+r)>>1;
    if (v <= mid) {
        tr[ri].rs = tr[li].rs;
        build_tree(tr[li].ls, (tr[ri].ls = ++tr_id), l, mid, v);
    } else {
        tr[ri].ls = tr[li].ls;
        build_tree(tr[li].rs, (tr[ri].rs = ++tr_id), mid+1, r, v);
    }
    push_up(ri);
}

int query_tree(int li, int ri, int l, int r, int k)
{
    if (l == r) return l;
    int now = tr[tr[ri].ls].sum-tr[tr[li].ls].sum,
        mid = (l+r)>>1;
    if (k <= now) {
        return query_tree(tr[li].ls, tr[ri].ls, l, mid, k);
    } else {
        return query_tree(tr[li].rs, tr[ri].rs, mid+1, r, k-now);
    }
}

inline bool cmpv(const Node &x, const Node &y) { return x.v < y.v; }
inline bool cmpi(const Node &x, const Node &y) { return x.id < y.id; }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].v);
        a[i].id = i;
        dis[i] = a[i].v;
    }
    /* discrete */
    sort(a+1, a+n+1, cmpv);
    sort(dis+1, dis+n+1);
    dn = unique(dis+1, dis+n+1)-dis-1;
    for (int i = 1, p = 1; i <= n; ++i) {
        while (/*p <= dn && */dis[p] < a[i].v) ++p;
        a[i].v = p;
    }
    sort(a+1, a+n+1, cmpi);
    /* build_tree */
    for (int i = 1; i <= n; ++i) {
        build_tree(root[i-1], (root[i] = ++tr_id), 1, dn, a[i].v);
    }
    /* query_tree */
    for (int i = 1, l, r, k; i <= m; ++i) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", dis[query_tree(root[l-1], root[r], 1, dn, k)]);
    }
    return 0;
}
