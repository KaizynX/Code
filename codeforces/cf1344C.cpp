/*
 * @Author: Kaizyn
 * @Date: 2020-05-06 22:33:23
 * @LastEditTime: 2020-05-07 14:44:47
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
int ind[N], otd[N], vis[N];
vector<int> e[N];

inline bool bfs(const int &s) {
    static queue<int> q;
    vis[s] = s;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (const int &v : e[u]) {
            if (vis[v] == s) return true;
            if (vis[v]) continue;
            vis[v] = s;
            q.push(v);
        }
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        ++ind[v];
        ++otd[u];
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (bfs(i)) return cout << -1 << endl, 0;
    }
    int cnti = 0, cnto = 0;
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) ++cnti;
        if (!otd[i]) ++cnto;
    }
    int *arr = ind;
    if (cnti < cnto) swap(cnti, cnto), arr = otd;
    cout << cnti << endl;
    for (int i = 1; i <= n; ++i) {
        cout << (arr[i] ? "E" : "A");
    }
    cout << endl;
    return 0;
}