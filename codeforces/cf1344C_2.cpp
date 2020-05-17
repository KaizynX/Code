/*
 * @Author: Kaizyn
 * @Date: 2020-05-06 22:33:23
 * @LastEditTime: 2020-05-07 15:44:53
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

int n, m;
int a[N], tot;
int dp[N];
int ind[N], otd[N], vis[N], rvis[N];
vector<int> e[N], re[N];

inline void bfs(const int &s, const vector<int> *e, int *vis) {
    static queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (const int &v : e[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }
}

signed main()
{
    static queue<int> q;
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        re[v].emplace_back(u);
        ++ind[v];
        ++otd[u];
    }
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        a[++tot] = u;
        for (const int &v : e[u]) {
            if (--ind[v] == 0) q.push(v);
        }
    }
    if (tot < n) return cout << -1 << endl, 0;

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && !rvis[i]) {
            ++res;
            dp[i] = 1;
        }
        bfs(i, e, vis);
        bfs(i, re, rvis);
    }
    cout << res << endl;
    for (int i = 1; i <= n; ++i) cout << (dp[i] ? "A" : "E");
    cout << endl;
    /*
    for (int i = n, u; i; --i) {
        u = a[i];
        for (const int &v : e[u]) {
            dp[u] = min(dp[u], dp[v]);
        }
    }
    for (int i = 1, u; i <= n; ++i) {
        u = a[i];
        for (const int &v : re[u]) {
            dp[u] = min(dp[u], dp[v]);
        }
    }
    for (int i = 1; i <= n; ++i) res += dp[i] == i;
    cout << res << endl;
    for (int i = 1; i <= n; ++i) {
        cout << (dp[i] == i ? "A" : "E");
    }
    cout << endl;
    */
    return 0;
}