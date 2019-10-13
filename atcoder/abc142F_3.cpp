#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int M = 2e3+7;

int n, m, k;
int u[M], v[M], fir[N], nex[M], last[N], res[N], dis[N], vis[N];

inline void dijiskra(int s, int t, int del)
{
    priority_queue<pair<int, int>> q;
    memset(dis, 0x3f, sizeof(int)*(n+3));
    dis[s] = 0;
    vis[s] = 1;
    last[s] = 0;
    q.push({0, s});
    while (q.size()) {
        auto cur = q.top(); q.pop();
        int w = -cur.first, uu = cur.second;
        --vis[uu];
        if (dis[uu] < w) continue;
        for (int i = fir[uu], vv; i; i = nex[i]) {
            if (i == del) continue;
            vv = v[i];
            if (w+1 < dis[vv]) {
                ++vis[vv];
                dis[vv] = w+1;
                last[vv] = uu;
                q.push({-dis[vv], vv});
            }
        }
    }
#ifdef DEBUG
    cout << s << " " << t << endl;
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;
#endif
    if (dis[t]+1 < k) {
        k = dis[t]+1;
        for (int i = t, id = 1; i; i = last[i], ++id) {
            res[id] = i;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
        nex[i] = fir[u[i]];
        fir[u[i]] = i;
    }
    k = n+1;
    for (int i = 1; i <= m; ++i) {
        dijiskra(v[i], u[i], i);
    }
    if (k == n+1) {
        cout << -1 << endl;
        return 0;
    }
    cout << k << endl;
    for (int i = 1; i <= k; ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
