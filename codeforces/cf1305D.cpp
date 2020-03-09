#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
list<int> e[N];
int f[N], d[N], du[N], tag[N], vis[N];

inline int query(const int &u, const int &v)
{
    int res;
    cout << "? " << u << " " << v << endl;
    cout.flush();
    cin >> res;
    return res;
}

void del(const int &u, const int &w)
{
    memset(vis, 0, sizeof(int)*(n+3));
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (cur == w) break;
        for (int v : e[cur]) if (!vis[v]) {
            f[v] = cur;
            vis[v] = 1;
            q.push(v);
        }
    }
    for (int i = w; i != u; i = f[i]) tag[i] = 0;
    tag[u] = 0; tag[w] = 1;
}

inline int count()
{
    int res = 0;
    for (int i = 1; i <= n; ++i) res += tag[i];
    return res;
}

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++du[u]; ++du[v];
    }
    for (int i = 1; i <= n; ++i) {
        tag[i] = du[i] == 1;
    }
    while (count() > 1) {
        vector<int> pt;
        for (int i = 1; i <= n; ++i) {
            if (tag[i]) pt.emplace_back(i);
            if (pt.size() >= 2) break;
        }
        int w = query(pt[0], pt[1]);
        del(pt[0], w);
        del(pt[1], w);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (tag[i]) res = i;
    }
    cout << "! " << res << endl;
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}
