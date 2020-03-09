#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e2+7;
const int M = 2e2+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

template <typename T>
struct EK
{
    struct Edge
    {
        int v, nex;
        T w;
    } e[M<<1];
    int tot = 0, n;
    int fir[N], vis[N], pre[N];
    T incf[N];
    T work(const int &s, const int &t) {
        T res = 0;
        while (bfs(s, t)) {
            int u = t, id;
            while (u != s) {
                id = pre[u];
                e[id].w -= incf[t];
                e[id^1].w -= incf[t];
                u = e[id^1].v;
            }
            res += incf[t];
        }
        return res;
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
    bool bfs(const int &s, const int &t) {
        queue<int> q;
        memset(vis, 0, sizeof(int)*(n+3));
        q.push(s);
        vis[s] = 1;
        incf[s] = INF;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u], v; i != -1; i = e[i].nex) {
                v = e[i].v;
                if (vis[v] || !e[i].w) continue;
                incf[v] = min(incf[u], e[i].w);
                pre[v] = i;
                if (v == t) return true;
                q.push(v);
                vis[v] = 1;
            }
        }
        return false;
    }
};

int n, m;
EK<int> ek;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> m >> n) {
        ek.init(n);
        for (int i = 1, u, v, w; i <= m; ++i) {
            cin >> u >> v >> w;
            ek.add_edge(u, v, w);
        }
        cout << ek.work(1, n) << endl;
    }
    return 0;
}