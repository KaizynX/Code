/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 20:25:18
 * @LastEditTime: 2020-03-27 13:58:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 8e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct TWO_SAT
{
    int n, cnt;
    int res[N], mem[N<<1], col[N<<1];
    vector<int> e[N<<1];
    void init(const int &_n) {
        n = _n;
        memset(col, -1, sizeof(int)*(n*2+3));
        for (int i = 0; i <= n*2+3; ++i) vector<int>().swap(e[i]);
    }
    // if u then v
    void add_edge(const int &u, const int &v) {
        e[u].emplace_back(v);
    }
    // pt i ==> i<<1 && i<<1|1 ==> 0 && 1
    void add_edge(const int &u, const int &uv, const int &v, const int &vv) {
        e[u<<1|uv].emplace_back(v<<1|vv);
    }
    // tag 0 any 1 smallest
    bool work() {
        for (int i = 2; i <= (n<<1|1); ++i) if (col[i] == -1) {
            cnt = 0;
            if (!dfs(i)) {
                for (int j = 1; j <= cnt; ++j) col[mem[j]] = col[mem[j]^1] = -1;
                if (!dfs(i^1)) return false;
            }
        }
        for (int i = 2; i <= (n<<1|1); ++i) if (!col[i]) res[i>>1] = i&1;
        return true;
    }
    bool dfs(const int &u) {
        col[u] = 0;
        col[u^1] = 1;
        mem[++cnt] = u;
        for (int v : e[u]) {
            if (col[v] == 0) continue;
            if (col[v] == 1 || !dfs(v)) return false;
        }
        return true;
    }
};

int n, m;
TWO_SAT sat;

inline void solve()
{
    sat.init(n);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        ++u; ++v;
        sat.add_edge(u^1, v);
        sat.add_edge(v^1, u);
    }
    sat.work();
    for (int i = 1; i <= n; ++i)
        cout << (i<<1|sat.res[i])-1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m) solve();
    return 0;
}