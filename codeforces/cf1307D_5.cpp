#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
const int INF = 1e9;
typedef pair<int, int> pii;

int n, m, k;
int d1[N], dn[N], spj[N];
vector<int> e[N];
vector<pii> vec;

inline void bfs(const int &s, int d[])
{
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
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
        if (!spj[i]) continue;
        vec.emplace_back(d1[i]-dn[i], i);
    }
    sort(vec.begin(), vec.end());
    for (int i = 1, mv = d1[vec[0].second]; i < (int)vec.size(); ++i) {
        res = max(res, mv+dn[vec[i].second]-1);
        mv = max(mv, d1[vec[i].second]);
    }
    cout << min(res, d1[n]-1) << endl;
    return 0;
}

