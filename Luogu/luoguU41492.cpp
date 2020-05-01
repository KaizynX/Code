/*
 * @Author: Kaizyn
 * @Date: 2020-04-29 20:04:12
 * @LastEditTime: 2020-04-29 20:15:02
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

int n, m;
int col[N], cnt[N], num[N], son[N], res[N];
vector<int> e[N];

void get_son(const int &u, const int &fa) {
    num[u] = 1;
    son[u] = 0;
    for (int &v : e[u]) if (v != fa) {
        get_son(v, u);
        num[u] += num[v];
        if (num[v] > num[son[u]]) son[u] = v;
    }
}

void dfs1(const int &u, const int &fa, const int &dif, const int &rt) {
    cnt[col[u]] += dif;
    if (dif == 1 && cnt[col[u]] == 1) ++res[rt];
    for (int &v : e[u]) if (v != fa) dfs1(v, u, dif, rt);
}

void dfs(const int &u, const int &fa, const int &keep) {
    for (int &v : e[u]) if (v != fa && v != son[u]) dfs(v, u, 0);
    if (son[u]) dfs(son[u], u, 1), res[u] = res[son[u]];
    else res[u] = 0;
    for (int &v : e[u]) if (v != fa && v != son[u]) dfs1(v, u, 1, u);
    if (++cnt[col[u]] == 1) ++res[u];
    if (!keep) {
        --cnt[col[u]];
        for (int &v : e[u]) if (v != fa) dfs1(v, u, -1, u);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> col[i];
    cin >> m;
    get_son(1, 0);
    dfs(1, 0, 0);
    for (int i = 1, x; i <= m; ++i) {
        cin >> x;
        cout << res[x] << endl;
    }
    return 0;
}