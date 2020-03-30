/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 20:25:18
 * @LastEditTime: 2020-03-27 14:17:15
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
    int res[N], mem[N<<1], mark[N<<1];
    vector<int> e[N<<1];
    void init(const int &_n) {
        n = _n;
        memset(mark, 0, sizeof(int)*n*2);
        for (int i = 0; i < n<<1; ++i) vector<int>().swap(e[i]);
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
        for (int i = 0; i < n; ++i) {
            if (mark[i<<1] || mark[i<<1|1]) continue;
            cnt = 0;
            if (!dfs(i<<1)) {
                while (cnt) mark[mem[cnt--]] = 0;
                if (!dfs(i<<1|1)) return false;
            }
        }
        for (int i = 0; i < n<<1; ++i) if (mark[i]) res[i>>1] = i&1;
        return true;
    }
    bool dfs(const int &u) {
        if (mark[u^1]) return false;
        if (mark[u]) return true;
        mark[mem[++cnt] = u] = 1;
        for (int v : e[u]) if (!dfs(v)) return false;
        return true;
    }
};

int n, m;
TWO_SAT sat;

inline void solve()
{
    sat.init(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        --u; --v;
        sat.add_edge(u, v^1);
        sat.add_edge(v, u^1);
    }
    if (!sat.work()) return (void)(cout << "NIE" << endl);
    for (int i = 0; i < n; ++i) cout << (i<<1|sat.res[i])+1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m) solve();
    return 0;
}