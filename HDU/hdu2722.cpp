#include <bits/stdc++.h>

using namespace std;

const int N = 25;
const int M = 1007;
const int S = 2520;
const int INF = 1e9;

int T, n, m, tot;
int to[M<<1], fir[M], nex[M<<1], w[M<<1], dis[M];

inline int id(int x, int y) { return (x-1)*(m+1)+y; }

inline void add_edge(int u, int v, int d)
{
    ++tot;
    to[tot] = v;
    w[tot] = d;
    nex[tot] = fir[u];
    fir[u] = tot;
}

inline void init()
{
    tot = 0;
    for (int i = 1; i <= (n+1)*(m+1); ++i) {
        fir[i] = 0;
        dis[i] = INF;
    }
}

inline int dijskra(int s, int t)
{
    typedef pair<int, int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    dis[s] = 0;
    while (q.size()) {
        pii u = q.top();
        q.pop();
        if (u.first > dis[u.second]) continue;
        if (u.second == t) return u.first;
        for (int i = fir[u.second], v; i; i = nex[i]) {
            v = to[i];
            int d = w[i]+u.first;
            if (d >= dis[v]) continue;
            dis[v] = d;
            q.push({d, v});
        }
    }
    return -1;
}

int main()
{
    while (cin >> n >> m && n|m) {
        init();
        for (int i = 1; i <= n*2+1; ++i) {
            int v; char d;
            if (i&1) {
                for (int j = 1; j <= m; ++j) {
                    cin >> v >> d;
                    if (!v) continue;
                    v = S/v;
                    if (d == '*') {
                        add_edge(id((i+1)/2, j), id((i+1)/2, j+1), v);
                        add_edge(id((i+1)/2, j+1), id((i+1)/2, j), v);
                    } else if (d == '>') {
                        add_edge(id((i+1)/2, j), id((i+1)/2, j+1), v);
                    } else if (d == '<') {
                        add_edge(id((i+1)/2, j+1), id((i+1)/2, j), v);
                    }
                }
            } else {
                for (int j = 1; j <= m+1; ++j) {
                    cin >> v >> d;
                    if (!v) continue;
                    v = S/v;
                    if (d == '*') {
                        add_edge(id(i/2, j), id(i/2+1, j), v);
                        add_edge(id(i/2+1, j), id(i/2, j), v);
                    } else if (d == 'v') {
                        add_edge(id(i/2, j), id(i/2+1, j), v);
                    } else if (d == '^') {
                        add_edge(id(i/2+1, j), id(i/2, j), v);
                    }
                }
            }
        }
        int res = dijskra(1, (n+1)*(m+1));
        if (res == -1) cout << "Holiday\n";
        else cout << res << " blips\n";
    }
    return 0;
}
