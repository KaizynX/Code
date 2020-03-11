/*
 * @Author: Kaizyn
 * @Date: 2020-03-10 21:36:49
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-10 22:00:33
 * @FilePath: \Code\hdu4366_6.cpp
 */
#include<bits/stdc++.h>

using namespace std;

const int N = 5e4+7;

struct Node
{
    int id ,abi, loy, dfn, l, r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.abi == n2.abi ? n1.id < n2.id : n1.abi > n2.abi;
    }
};

vector<int> e[N];
map<int,int> mp;
int tr[N<<2];
Node a[N];
int tot, ans[N];

void init(int n)
{
    for (int i = 0; i <= n; ++i)
        vector<int>().swap(e[i]);
    memset(tr, -1, sizeof tr);
    memset(ans, -1, sizeof ans);
    mp.clear();
    tot = 0;
}

void push_up(const int &i)
{
    tr[i] = max(tr[i<<1], tr[i<<1|1]);
}

void update(int q, int v, int i, int l, int r)
{
    if(l == r) { tr[i] = v; return; }
    int m = (l+r)/2;
    if (q <= m) update(q, v, i<<1, l, m);
    else update(q, v, i<<1|1, m+1, r);
    push_up(i);
}

int query(int ql, int qr, int i, int l, int r)
{
    if(ql > qr) return -1;
    if(ql <= l && r <= qr) return tr[i];
    int m = (l+r)/2, res = -1;
    if (ql <= m) res = max(res, query(ql, qr, i<<1, l, m));
    if (qr >  m) res = max(res, query(ql, qr, i<<1|1, m+1, r));
    return res;
}
void dfs(int id)
{
    a[id].dfn = tot++;
    for (int v : e[id]) dfs(v);
    a[id].l = a[id].dfn+1;
    a[id].r = tot-1;
}

int main()
{
    int T, n, q;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        init(n);
        for (int i = 1, fa; i < n; ++i) {
            scanf("%d %d %d", &fa, &a[i].loy, &a[i].abi);
            a[i].id = i;
            e[fa].emplace_back(i);
            mp[a[i].loy] = i;
        }
        dfs(0);
        sort(a+1, a+n);
        mp[-1] = -1;
        for (int i = 1; i < n; ++i) {
            update(a[i].dfn, a[i].loy, 1, 0, n-1);
            ans[a[i].id] = mp[query(a[i].l, a[i].r, 1, 0, n-1)];
        }
        for (int i = 1, x; i <= q; ++i) {
            scanf("%d", &x);
            printf("%d\n", ans[x]);
        }
    }
    return 0;
}