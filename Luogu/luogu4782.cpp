/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 17:23:27
 * @LastEditTime: 2020-03-26 17:51:33
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct TWO_SAT
{
    int top, _dfn, _col;
    int dfn[N<<1], low[N<<1], vis[N<<1], sta[N<<1], col[N<<1], res[N];
    vector<int> e[N<<1];
    void init(const int &n) {
        top = 0;
        memset(dfn, 0, sizeof(int)*(n*2+3));
        memset(low, 0, sizeof(int)*(n*2+3));
        memset(vis, 0, sizeof(int)*(n*2+3));
        for (int i = 0; i <= n*2; ++i) vector<int>().swap(e[i]);
    }
    // if u then v
    void add_edge(const int &u, const int &v) {
        e[u].emplace_back(v);
    }
    // pt i ==> i*2-1 && i*2 ==> 1 && 0
    inline bool work(const int &n) {
        for (int i = 1; i <= n*2; ++i)
            if (!dfn[i]) tarjan(i);
        for (int i = 1; i <= n; ++i) {
            if (col[i*2-1] == col[i*2]) return false;
            res[i] = col[i*2-1] < col[i*2];
        }
        return true;
    }
    void tarjan(const int &u) {
        dfn[u] = low[u] = ++_dfn;
        vis[u] = 1;
        sta[++top] = u;
        for (int &v : e[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (vis[v]) {
                low[u] = min(low[u], low[v]);
            }
        }
        if (dfn[u] == low[u]) {
            ++_col;
            do {
                col[sta[top]] = _col;
                vis[sta[top]] = 0;
            } while (sta[top--] != u);
        }
    }
};

int n, m;
TWO_SAT sat;

inline void solve()
{
    cin >> n >> m;
    sat.init(n);
    for (int k = 1, i, j, a, b; k <= m; ++k) {
        cin >> i >> a >> j >> b;
        sat.add_edge(i*2-(a==0), j*2-(b==1));
        sat.add_edge(j*2-(b==0), i*2-(a==1));
    }
    if (!sat.work(n)) return (void)(cout << "IMPOSSIBLE\n");
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; ++i) cout << sat.res[i] << " \n"[i==n];
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}