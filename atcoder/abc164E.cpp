/*
 * @Author: Kaizyn
 * @Date: 2020-04-28 10:26:14
 * @LastEditTime: 2020-04-28 11:22:56
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 57;
const int T = 5e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct Edge {
    int v, a, b;
};

struct Node {
    int u, s;
    long long t;
    Node (const int &_u, const int &_s, const long long &_t) : u(_u), s(_s), t(_t) {}
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.t > rhs.t;
    }
};

int n, m, s, sums;
int c[N], d[N];
long long t[N][T];
vector<Edge> e[N];
priority_queue<Node> q;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> s;
    for (int i = 1, u, v, a, b; i <= m; ++i) {
        cin >> u >> v >> a >> b;
        // e[u].emplace_back(v, a, b);
        e[u].push_back({v, a, b});
        e[v].push_back({u, a, b});
        sums += a;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
    }
    memset(t, 0x3f, sizeof t);
    s = min(s, sums);
    for (int i = 0; i <= s; ++i) t[1][i] = 0;
    q.push(Node(1, s, 0));
    while (q.size()) {
        Node cur = q.top();
        q.pop();
        if (cur.t > t[cur.u][cur.s]) continue;
        #ifdef DEBUG
        cout << cur.u << " " << cur.s << " " << cur.t << endl;
        #endif
        for (auto &edge : e[cur.u]) {
            if (edge.a > cur.s) continue;
            if (t[edge.v][cur.s-edge.a] <= edge.b+cur.t) continue;
            t[edge.v][cur.s-edge.a] = edge.b+cur.t;
            q.push(Node(edge.v, cur.s-edge.a, edge.b+cur.t));
        }
        for (int i = 1, nexts; ; ++i) {
            nexts = min(sums, cur.s+i*c[cur.u]);
            if (t[cur.u][nexts] <= cur.t+1ll*i*d[cur.u]) break;
            t[cur.u][nexts] = cur.t+1ll*i*d[cur.u];
            q.push(Node(cur.u, nexts, t[cur.u][nexts]));
            if (nexts == sums) break;
        }
    }
    for (int i = 2; i <= n; ++i) {
        long long res = t[i][0];
        for (int j = 1; j <= sums; ++j) res = min(res, t[i][j]);
        cout << res << endl;
    }
    return 0;
}