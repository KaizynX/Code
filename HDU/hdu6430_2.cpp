/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 20:33:08
 * @LastEditTime: 2020-05-01 09:49:25
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
map<int, int> mp[N];

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

void dfs(const int &u) {
    for (const int &v : e[u]) if (v != son[u]) dfs(v);
    if (son[u]) dfs(son[u]), swap(mp[u], mp[son[u]]);
    res[u] = -1;
    for (const int &v : e[u]) if (v != son[u]) {
        for (const pii &p : mp[v]) {
            if (mp[u].count(p.first)) res[u] = max(res[u], p.first);
            mp[u][p.first] += p.second;
        }
    }
    for (const int &x : a[u]) {
        if (mp[u].count(x)) res[u] = max(res[u], x);
        ++mp[u][x];
    }
}

inline void solve()
{
    for (int i = 1; i <= n; ++i) {
        vector<int>().swap(a[i]);
        vector<int>().swap(e[i]);
        map<int, int>().swap(mp[i]);
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
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", res[i]);
    }
}

signed main()
{
    while (scanf("%d", &n) == 1) solve();
    return 0;
}