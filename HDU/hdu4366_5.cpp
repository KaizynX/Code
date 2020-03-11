/*
 * @Author: Kaizyn
 * @Date: 2020-03-10 21:16:43
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-10 21:55:37
 * @FilePath: \Code\HDU\hdu4366_5.cpp
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;

struct Node
{
    int id, abi, loy, l, r, dfn;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.abi == n2.abi ? n1.id < n2.id : n1.abi > n2.abi;
    }
};

int n, m, tot;
int res[N], tr[N<<2];
Node a[N];
vector<int> e[N];
map<int, int> mp;

inline void init()
{
    tot = 0;
    mp.clear();
    memset(tr, -1, sizeof tr);
    memset(res, -1, sizeof res);
    for (int i = 0; i <= n; ++i) vector<int>().swap(e[i]);
}

inline void push_up(const int &i) 
{
    tr[i] = max(tr[i<<1], tr[i<<1|1]);
}

void update(const int &x, const int &k, const int &i, const int &trl, const int &trr)
{
    if (trl == trr) { tr[i] = k; return; }
    int mid = (trl+trr)/2;
    if (x <= mid) update(x, k, i<<1, trl, mid);
    else update(x, k, i<<1|1, mid+1, trr);
    push_up(i);
}

int query(const int &l, const int &r, const int &i, const int &trl, const int &trr)
{
    if (l > r) return -1;
    if (l <= trl && trr <= r) return tr[i];
    int mid = (trl+trr)/2, res = -1;
    if (l <= mid) res = max(res, query(l, r, i<<1, trl, mid));
    if (r >  mid) res = max(res, query(l, r, i<<1|1, mid+1, r));
    return res;
}

void dfs(const int &u)
{
    a[u].dfn = tot++;
    for (int v : e[u]) dfs(v);
    a[u].l = a[u].dfn+1;
    a[u].r = tot-1;
}

inline void solve()
{
    scanf("%d %d", &n, &m);
    init();
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
        res[a[i].id] = mp[query(a[i].l, a[i].r, 1, 0, n-1)];
    }
    for (int i = 1, x; i <= m; ++i) {
        scanf("%d", &x);
        printf("%d\n", res[x]);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}