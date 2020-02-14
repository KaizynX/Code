#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;

int n, m, k, ds;
int dis[N];
typedef pair<int, int> pii;
vector<pii> e[N];

inline int read()
{
    static char buf[30];
    static int res;
    scanf("%s", buf);
    if (buf[0] == 'G') {
        sscanf(buf+1, "%d", &res);
        res += n;
    } else {
        sscanf(buf, "%d", &res);
    }
    return res;
}

inline void dijskra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(dis, -1, sizeof dis);
    dis[s] = 0;
    q.push({0, s});
    while (q.size()) {
        pii u = q.top();
        q.pop();
        if (u.first > dis[u.second]) continue;
        for (pii v : e[u.second]) {
            if (dis[v.second] != -1 && dis[v.second] <= u.first+v.first) continue;
            dis[v.second] = u.first+v.first;
            q.push({dis[v.second], v.second});
        }
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    for (int i = 1, u, v, w; i <= k; ++i) {
        u = read();
        v = read();
        scanf("%d", &w);
        e[u].emplace_back(w, v);
        e[v].emplace_back(w, u);
    }
    int resi = -1, resmin, resave;
    for (int i = 1, flag, mind, aved; i <= m; ++i) {
        dijskra(n+i);
#ifdef DEBUG
        cout << "G" << i << ":";
        for (int j = 1; j <= n; ++j)
            cout << dis[j] << " \n"[j==n];
#endif
        flag = 1;
        mind = 2e9;
        aved = 0;
        for (int j = 1; j <= n; ++j) {
            if (dis[j] > ds) { flag = 0; break; }
            mind = min(mind, dis[j]);
            aved += dis[j];
        }
        if (!flag) continue;
        if (resi == -1 || resmin > mind) {
            resi = i;
            resmin = mind;
            resave = aved;
        }
    }
    if (resi == -1) puts("No Solution");
    else printf("G%d\n%.1f %.1f\n", resi, 1.0*resmin, 1.0*resave/n);
    return 0;
}
