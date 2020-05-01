/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 20:33:08
 * @LastEditTime: 2020-05-01 09:43:04
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

int n;
int v[N], num[N], son[N], cnt[N], res[N];
vector<int> e[N], a[N];

inline void factor(const int &i) {
    for (int x = 1; x*x <= v[i]; ++x) {
        if (v[i]%x) continue;
        a[i].emplace_back(x);
        if (v[i]/x != x) a[i].emplace_back(v[i]/x);
    }
}

void get_son(const int &u) {
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) {
        get_son(v);
        num[u] += num[v];
        if (num[v] > num[son[u]]) son[u] = v;
    }
}

void dfs1(const int &u, const int &dif, const int &rt) {
    for (const int &x : a[u]) {
        cnt[x] += dif;
        if (dif == 1 && cnt[x] == 2) res[rt] = max(res[rt], x);
    }
    for (const int &v : e[u]) dfs1(v, dif, rt);
}

void dfs(const int &u, const int &keep) {
    for (const int &v : e[u]) if (v != son[u]) dfs(v, 0);
    if (son[u]) dfs(son[u], 1);
    res[u] = -1;
    for (const int &v : e[u]) if (v != son[u]) dfs1(v, 1, u);
    for (const int &x : a[u]) {
        if (++cnt[x] == 2) res[u] = max(res[u], x);
    }
    if (!keep) dfs1(u, -1, u);
}

inline void solve()
{
    for (int i = 1; i <= n; ++i) {
        vector<int>().swap(a[i]);
        vector<int>().swap(e[i]);
    }
    for (int i = 2, x; i <= n; ++i) {
        scanf("%d", &x);
        e[x].emplace_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", v+i);
        factor(i);
    }
    get_son(1);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", res[i]);
    }
}

signed main()
{
    while (scanf("%d", &n) == 1) solve();
    return 0;
}