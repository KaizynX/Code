/*
 * @Author: Kaizyn
 * @Date: 2020-04-21 22:33:40
 * @LastEditTime: 2020-04-22 00:01:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const long long INF = 1e18;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m, a, b, c;
int p[N];
int disa[N], disb[N], disc[N];
long long sum[N];
vector<int> e[N];

void bfs1(const int &s, int *dis) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int &v : e[u]) if (dis[v] == -1) {
            dis[v] = dis[u]+1;
            q.push(v);
        }
    }
}

long long bfs2(const int &s, int *dis) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    long long res = INF;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (disa[u]+disc[u]+dis[u] <= m)
            res = min(res, sum[dis[u]]+sum[disa[u]+disc[u]+dis[u]]);
        for (int &v : e[u]) if (dis[v] == -1) {
            dis[v] = dis[u]+1;
            q.push(v);
        }
    }
    return res;
}

inline void solve()
{
    cin >> n >> m >> a >> b >> c;
    for (int i = 1; i <= n; ++i) {
        disa[i] = disb[i] = disc[i] = -1;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> p[i];
    }
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    sort(p+1, p+m+1);
    for (int i = 1; i <= m; ++i) {
        sum[i] = sum[i-1]+p[i];
    }
    bfs1(a, disa);
    bfs1(c, disc);
    cout << bfs2(b, disb) << endl;
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) cout << disa[i] << " \n"[i==n];
    for (int i = 1; i <= n; ++i) cout << disc[i] << " \n"[i==n];
    for (int i = 1; i <= n; ++i) cout << disb[i] << " \n"[i==n];
    #endif
    for (int i = 1; i <= n; ++i) {
        vector<int>().swap(e[i]);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    while (testcase--) solve();
    return 0;
}