/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 17:36:14
 * @LastEditTime: 2020-04-30 20:29:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, dfn;
int w[N], a[N<<1], st[N], ed[N];
vector<int> e[N];

struct SegmentTree {
    struct TreeNode {
        map<int, int> v;
        int l, r;
    } tr[N<<2];
    void merge(map<int, int> &lhs, const map<int, int> &rhs) {
        for (const auto &p : rhs) lhs[p.first] += p.second;
    }
    void build(const int &l, const int &r, const int &i = 1) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].v.clear();
            tr[i].v[a[l]] = 1;
            return;
        }
        int mid = (l+r)>>1;
        build(l, mid, i<<1);
        build(mid+1, r, i<<1|1);
        // push_up(i);
        tr[i].v = tr[i<<1].v;
        merge(tr[i].v, tr[i<<1|1].v);
    }
    map<int, int> query(const int &l, const int &r, const int &i = 1) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
        int mid = (tr[i].l+tr[i].r)>>1;
        map<int, int> res;
        if (l <= mid) res = query(l, r, i<<1);
        if (r >  mid) merge(res, query(l, r, i<<1|1));
        return res;
    }
} ST;

void dfs(const int &u) {
    st[u] = ++dfn;
    for (const int &v : e[u]) dfs(v);
    ed[u] = dfn;
}

inline void solve()
{
    for (int i = 1; i <= n; ++i) {
        vector<int>().swap(e[i]);
    }
    for (int i = 2, p; i <= n; ++i) {
        cin >> p;
        e[p].emplace_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    dfn = 0;
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        a[st[i]+n] = a[st[i]] = w[i];
    }
    ST.build(1, 2*n);
    int res = 0;
    for (int i = 2, tmp; i <= n; ++i) {
        tmp = ST.query(st[i], ed[i]).size() + ST.query(ed[i]+1, st[i]+n-1).size();
        res = max(res, tmp);
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n) solve();
    return 0;
}