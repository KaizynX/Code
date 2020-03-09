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
int f[N], vis[N], die[N], inq[N];

inline int query(const int &u, const int &v)
{
    int res;
    cout << "? " << u << " " << v << endl;
    cout.flush();
    cin >> res;
    return res;
}

inline void write(const int &res)
{
    cout << "! " << res << endl;
    cout.flush();
    exit(0);
}

void del(const int &u, const int &w)
{
    if (u == w) return;
    memset(vis, 0, sizeof(int)*(n+3));
    queue<int> q;
    q.push(w);
    vis[w] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (cur == u) break;
        for (int v : e[cur]) if (!vis[v]) {
            f[v] = cur;
            vis[v] = 1;
            q.push(v);
        }
    }
    int last;
    for (int i = u; i != w; last = i, i = f[i]) die[i] = 1;
    for (auto i = e[w].begin(); i != e[w].end(); ++i) if (*i == last) {e[w].erase(i); break; }
}

inline int getq(queue<int> &q)
{
    int res = -1;
    while (q.size()) {
        res = q.front();
        inq[res] = 0;
        q.pop();
        if (die[res]) res = -1;
        else break;
    }
    return res;
}

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (e[i].size() == 1) {
        q.push(i);
        inq[i] = 1;
    }
    while (q.size()) {
        int x = getq(q), y = getq(q);
        if (y == -1) write(x);
        int w = query(x, y);
        if (e[w].size() == 1) write(w);
        del(x, w); del(y, w);
        if (!inq[w]) q.push(w);
    }
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
