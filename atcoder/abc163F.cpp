/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 19:55:17
 * @LastEditTime: 2020-04-26 22:33:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int c[N], num[N], son[N], col[N];
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

void dfs(const int &u, const int &fa, const int &k) {
    col[c[u]] += k;
    for (int &v : e[u]) if (v != fa) {
        dfs(v, u, k);
    }
}

void treedp(const int &u, const int &fa, const int &op) {
    for (int &v : e[u]) if (v != fa && v != son[u]) {
        treedp(v, u, 1);
    }
    if (son[u]) treedp(v, u, 0);
    for (int &v : e[u]) if (v != fa && v != son[u]) {
        dfs(v, u, 1);
    }
    ++col[c[u]];
    if (col[c[u]] == 1) {
        ;
    }
    if (op) {
        --col[c[u]];
        for (int &v : e[u]) if (v != fa && v != son[u]) {
            dfs(v, u, -1);
        }
    }
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    get_son(1, 0);
    treedp(1, 0, 0);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}