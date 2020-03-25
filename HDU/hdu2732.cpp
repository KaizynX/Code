/*
 * @Author: Kaizyn
 * @Date: 2020-03-21 15:30:55
 * @LastEditTime: 2020-03-21 16:26:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int M = 2e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dir[] = {0, -1, 0, 1, 0};

template <typename T>
struct ISAP
{
    struct EDGE
    {
        int v, nex;
        T w;
    } e[M<<1];
    int tot, n, s, t;
    T maxflow;
    int fir[N], gap[N], dep[N];
    T work(const int &_s, const int &_t) {
        s = _s; t = _t;
        maxflow = 0;
        bfs();
        while (dep[s] < n) dfs(s, INF);
        return maxflow;
    }
    void init(const int &sz) {
        n = sz;
        tot = 0;
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w) {
        e[tot] = {v, fir[u], w}; fir[u] = tot++;
        e[tot] = {u, fir[v], 0}; fir[v] = tot++;
    }
    void bfs() {
        queue<int> q;
        memset(dep, -1, sizeof(int)*(n+3));
        memset(gap, 0, sizeof(int)*(n+3));
        dep[t] = 0;
        gap[0] = 1;
        q.push(t);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u], v; i != -1; i = e[i].nex) {
                v = e[i].v;
                if (dep[v] != -1) continue;
                q.push(v);
                dep[v] = dep[u]+1;
                ++gap[dep[v]];
            }
        }
    }
    T dfs(const int &u, const T &flow) {
        if (u == t) {
            maxflow += flow;
            return flow;
        }
        T used = 0;
        for (int i = fir[u], v; i != -1; i = e[i].nex) {
            v = e[i].v;
            if (!e[i].w || dep[v]+1 != dep[u]) continue;
            T minf = dfs(v, min(e[i].w, flow-used));
            if (minf) {
                e[i].w -= minf;
                e[i^1].w += minf;
                used += minf;
            }
            if (used == flow) return used;
        }
        if (--gap[dep[u]] == 0) dep[s] = n+1;
        ++gap[++dep[u]];
        return used;
    }
};


int n, m, d, s, t;
char a[25][25], b[25][25];
ISAP<int> isap;

inline int mp(const int &x, const int &y) { return (x*m+y)<<1; }

inline void walk(const int &x, const int &y)
{
    int flag = 0;
    for (int i = -d, nx, ny; i <= d; ++i) {
        for (int j = abs(i)-d; j <= d-abs(i); ++j) {
            if (i == 0 && j == 0) continue;
            nx = x+i; ny = y+j;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                if (!flag) isap.add_edge(mp(x, y)^1, t, INF), flag = 1;
                continue;
            }
            if (a[nx][ny] == '0') continue;
            isap.add_edge(mp(x, y)^1, mp(nx, ny), INF);
        }
    }
}

inline int solve()
{
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%s", a[i]);
    for (int i = 0; i < n; ++i) scanf("%s", b[i]);

    int num = 0;
    m = strlen(a[0]);
    s = 2*n*m; t= 2*n*m+1;
    isap.init(2*n*m+2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '0') isap.add_edge(mp(i, j), mp(i, j)^1, a[i][j]-'0');
            if (b[i][j] == 'L') isap.add_edge(s, mp(i, j), 1), ++num;
            walk(i, j);
            /*
            for (int k = 0, nx, ny; k < 4; ++k) {
                for (int l = 1; l <= d; ++l) {
                    nx = i+l*dir[k];
                    ny = j+l*dir[k+1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        isap.add_edge(mp(i, j)^1, t, INF);
                        break;
                    }
                    if (a[nx][ny] == '0') continue;
                    isap.add_edge(mp(i, j)^1, mp(nx, ny), INF);
                }
            }
            */
        }
    }
    return num-isap.work(s, t);
}

signed main()
{
    int testcase = 1;
    scanf("%d", &testcase);
    for (int i = 1; i <= testcase; ++i) {
        int res = solve();
        printf("Case #%d: ", i);
        if (res == 0) puts("no lizard was left behind.");
        else if (res == 1) puts("1 lizard was left behind.");
        else printf("%d lizards were left behind.\n", res);
    }
    return 0;
}