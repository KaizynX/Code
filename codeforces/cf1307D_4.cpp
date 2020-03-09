#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

int n, m, k;
int d1[N], dn[N], spj[N], cnt[N], vis[N], mv[N];
vector<int> e[N];

inline void bfs(const int &s, int d[])
{
    memset(cnt, 0, sizeof cnt);
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        // pt[d1[u]].emplace_back(u);
        cnt[d[u]] += spj[u];
        for (int v : e[u]) {
            if (d[v]) continue;
            d[v] = d[u]+1;
            q.push(v);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1, a; i <= k; ++i) {
        cin >> a;
        spj[a] = 1;
    }
    int res = -1;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        // 如果俩个特点本来就有边
        if (spj[u] && spj[v]) res = n;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    bfs(n, dn);
    bfs(1, d1);
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 1 || (cnt[i] && cnt[i+1]))
            res = n;
    }
    if (res >= d1[n]-1) { cout << d1[n]-1 << endl; return 0; }
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        if (!spj[i]) continue;
        if (d1[i]+dn[i] == d1[n]+1) vis[i] = 1, ++num;
        mv[d1[i]] = max(mv[d1[i]], dn[i]);
    }
    if (num < k) { cout << d1[n]-1 << endl; return 0; }
    for (int i = 1, last = 0; i <= d1[n]; ++i) {
        if (!spj[i]) continue;
        if (last) res = max(res, last+mv[i]-1);
        last = i;
    }
    if (res == -1) res = n;
    cout << min(res, d1[n]-1) << endl;
    return 0;
}

