#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

int n, m, k;
int d1[N], dn[N], spj[N], cnt[N];
vector<int> e[N];
vector<pii> ton, to1;

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
    if (res >= d1[n]-1) { cout << d1[n]-1 << endl; return 0; }
    // ton[i] 1为起点深度为i的特点 到n的最大距离
    for (int i = 1; i <= n; ++i) {
        if (!spj[i]) continue;
        ton.emplace_back(dn[i], i);
        to1.emplace_back(d1[i], i);
    }
    sort(ton.begin(), ton.end());
    reverse(ton.begin(), ton.end());
    sort(to1.begin(), to1.end());
    reverse(to1.begin(), to1.end());
    // 寻找连边减小的最小距离，如果没有则不构成影响
    for (int i = 1; i <= n; ++i) {
        if (!spj[i]) continue;
        for (int j = 0; j < (int)ton.size() && d1[i]+ton[j].second-1 > res; ++j) {
            if (i == ton[j].second) continue;
            if (d1[i]+ton[j].first <= dn[i]+d1[ton[j].second]) {
                res = max(res, d1[i]+ton[j].first-1);
                break;
            }
        }
        if (res >= d1[n]-1) { cout << d1[n]-1 << endl; return 0; }
        for (int j = 0; j < (int)to1.size() && dn[i]+to1[j].second-1 > res; ++j) {
            if (i == to1[j].second) continue;
            if (dn[i]+to1[j].first <= d1[i]+dn[to1[j].second]) {
                res = max(res, dn[i]+to1[j].first-1);
                break;
            }
        }
        if (res >= d1[n]-1) { cout << d1[n]-1 << endl; return 0; }
    }
    cout << min(res, d1[n]-1) << endl;
    return 0;
}

