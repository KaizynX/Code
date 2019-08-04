#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n, q;
int a[Maxn];

struct Tree
{
    int l, r, x, v;
    Tree(){ x = 0; v = 0; }
} tr[Maxn<<2];

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }

inline void push_down(int i)
{
    if(!tr[i].x) return;
    tr[ls(i)].x = max(tr[ls(i)].x, tr[i].x);
    tr[rs(i)].x = max(tr[rs(i)].x, tr[i].x);
    tr[ls(i)].v = max(tr[ls(i)].x, tr[ls(i)].v);
    tr[rs(i)].v = max(tr[rs(i)].x, tr[rs(i)].v);
    tr[i].x = 0;
}

inline void build_tree(int i, int l, int r)
{
    tr[i].l = l; tr[i].r = r;
    if(l == r) { tr[i].v = a[l]; return; }
    int mid = (l+r)>>1;
    build_tree(ls(i), l, mid);
    build_tree(rs(i), mid+1, r);
}

inline void update_tree(int i, int p, int k)
{
    if(tr[i].l == p && tr[i].r == p)
    {
        tr[i].x = 0;
        tr[i].v = k;
        return;
    }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if(p <= mid) update_tree(ls(i), p, k);
    if(p > mid)  update_tree(rs(i), p, k);
}

inline int query_tree(int i, int p)
{
    if(tr[i].l == p && tr[i].r == p)
        return max(tr[i].x, tr[i].v);
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if(p <= mid) return query_tree(ls(i), p);
    if(p > mid)  return query_tree(rs(i), p);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build_tree(1, 1, n);
    cin >> q;
    int op, p, x;
    while(q--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> p >> x;
            update_tree(1, p, x);
        }
        else
        {
            cin >> x;
            tr[1].x = max(tr[1].x, x);
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << query_tree(1, i) << " ";
    cout << endl;
    return 0;
}
