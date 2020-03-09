#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

int n, m, k;
int dep[N], spj[N], cnt[N];
vector<int> e[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1, a; i <= k; ++i) {
        cin >> a;
        spj[a] = 1;
    }
    int flag = 0;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        // 如果俩个特点本来就有边
        if (spj[u] && spj[v]) flag = 1;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    // bfs
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        // pt[dep[u]].emplace_back(u);
        cnt[dep[u]] += spj[u];
        for (int v : e[u]) {
            if (dep[v]) continue;
            dep[v] = dep[u]+1;
            q.push(v);
        }
    }
    // 如果同一深度或者差值1的俩个特点连边
    // 如果在 >= dep[n]-1 的点之间连边也不构成影响
    int biger_than_n = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 1 || (cnt[i] && cnt[i+1]))
            flag = 1;
        if (i >= dep[n]-1) biger_than_n += cnt[i];
    }
    if (biger_than_n > 1) flag = 1;
    if (flag) { cout << dep[n]-1 << endl; return 0; }
    int res = INF;
    // 寻找连边减小的最小距离，如果没有则不构成影响
    for (int i = 1, last = 0; i <= dep[n]; ++i) {
        if (cnt[i]) {
            if (last) res = min(res, i-last);
            last = i;
        }
    }
    if (res == INF) cout << dep[n]-1 << endl;
    else cout << dep[n]-res << endl;
    return 0;
}

