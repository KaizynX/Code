#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

int n, m, k, flag;
int d1[N], dn[N], spj[N], cnt[N], ton[N];
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
    flag = 0;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        // 如果俩个特点本来就有边
        if (spj[u] && spj[v]) flag = 1;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    bfs(n, dn);
    bfs(1, d1);
    // 如果同一深度或者差值1的俩个特点连边
    // 如果在 >= d1[n]-1 的点之间连边也不构成影响
    int big = 0, sma = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 1 || (cnt[i] && cnt[i+1]))
            flag = 1;
        if (i >= d1[n]-1) big += cnt[i];
        if (i <= d1[n]) ++sma;
    }
    if (big > 1 || sma < 2) flag = 1;
    if (flag) { cout << d1[n]-1 << endl; return 0; }
    // ton[i] 1为起点深度为i的特点 到n的最大距离
    memset(ton, -1, sizeof ton);
    for (int i = 1; i <= n; ++i) {
        if (!spj[i]) continue;
        ton[d1[i]] = max(ton[d1[i]], dn[i]-1);
    }
    int res = -1;
    // 寻找连边减小的最小距离，如果没有则不构成影响
    for (int i = 1, last = 0; i <= d1[n]; ++i) {
        if (cnt[i]) {
            if (last && ton[i] != -1)
                res = max(res, last+ton[i]);
            last = i;
        }
    }
    if (res == -1 || res > d1[n]-1) cout << d1[n]-1 << endl;
    else cout << res << endl;
    return 0;
}

