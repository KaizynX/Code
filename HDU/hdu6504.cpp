/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 17:36:14
 * @LastEditTime: 2020-04-30 19:52:15
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
int w[N], res[N], sum[N], cnt[N], son[N], num[N];
vector<int> e[N];

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
    cnt[w[u]] += dif;
    if (dif == 1) {
        if (cnt[w[u]] == 1) ++res[rt];
        if (cnt[w[u]] == sum[w[u]]) --res[rt];
    }
    for (const int &v : e[u]) dfs1(v, dif, rt);
}

void dfs(const int &u, const int &keep) {
    for (const int &v : e[u]) if (v != son[u]) dfs(v, 0);
    if (son[u]) dfs(son[u], 1), res[u] = res[son[u]];
    else res[u] = 0;
    for (const int &v : e[u]) if (v != son[u]) dfs1(v, 1, u);
    ++cnt[w[u]];
    if (cnt[w[u]] == 1) ++res[u];
    if (cnt[w[u]] == sum[w[u]]) --res[u];
    if (!keep) dfs1(u, -1, u);
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
    int ans = 0, base = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        if (++sum[w[i]] == 1) ++base;
    }
    get_son(1);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, res[i]+base);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        --sum[w[i]];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n) solve();
    return 0;
}