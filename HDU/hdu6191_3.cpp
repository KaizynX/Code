/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 15:31:54
 * @LastEditTime: 2020-04-30 17:41:32
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

struct TireTree
{
    static const int NN = 3e6+7;
    int nex[NN][2], num[NN], cnt;
    void clear() {
        memset(nex, 0, sizeof(nex[0])*(cnt+1));
        memset(num, 0, sizeof(int)*(cnt+1));
        cnt = 0;
    }
    void update(const int &x, const int &k) {
        for (int i = 30, c, p = 0; i >= 0; --i) {
            c = (x>>i)&1;
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
            num[p] += k;
        }
    }
    int query(const int &x) {
        int res = 0;
        for (int i = 30, c, p = 0; i >= 0; --i) {
            c = (x>>i)&1;
            if (num[nex[p][c^1]]) {
                p = nex[p][c^1];
                res |= 1<<i;
            } else {
                p = nex[p][c];
            }
        }
        return res;
    }
};

int n, m;
int val[N], son[N], num[N], res[N];
vector<int> e[N];
vector<pii> q[N];
TireTree TT;

void get_son(const int &u) {
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) {
        get_son(v);
        num[u] += num[v];
        if (num[v] > num[son[u]]) son[u] = v;
    }
}

void dfs1(const int &u, const int &dif) {
    TT.update(val[u], dif);
    for (const int &v : e[u]) dfs1(v, dif);
}

void dfs(const int &u, const int &keep) {
    for (const int &v : e[u]) if (v != son[u]) dfs(v, 0);
    if (son[u]) dfs(son[u], 1);
    for (const int &v : e[u]) if (v != son[u]) dfs1(v, 1);
    TT.update(val[u], 1);
    for (const pii &p : q[u]) res[p.second] = TT.query(p.first);
    if (!keep) dfs1(u, -1);
}

inline void solve()
{
    TT.clear();
    for (int i = 1; i <= n; ++i) {
        vector<int>().swap(e[i]);
        vector<pii>().swap(q[i]);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", val+i);
    for (int i = 2, f; i <= n; ++i) {
        scanf("%d", &f);
        e[f].emplace_back(i);
    }
    for (int i = 1, u, x; i <= m; ++i) {
        scanf("%d %d", &u, &x);
        q[u].emplace_back(x, i);
    }
    get_son(1);
    dfs(1, 0);
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", res[i]);
    }
}

signed main()
{
    while (scanf("%d %d", &n, &m) == 2) solve();
    return 0;
}