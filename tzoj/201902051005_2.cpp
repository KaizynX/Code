#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int u, v, flag;
int vis[Maxn];
int tot, fir[Maxn], ver[Maxn*2], nex[Maxn*2];

inline void add_edge(int x, int y)
{
    ver[++tot] = y; nex[tot] = fir[x]; fir[x] = tot;
}

void dfs(int cur, int last)
{
    cout << last << " " << cur << endl;
    if(flag) return;
    if(vis[cur])
    {
        flag = 1;
        return;
    }
    vis[cur] = 1;
    for(int i = fir[cur]; i; i = nex[i])
        if(ver[i] != last) dfs(ver[i], cur);
}

int main()
{
    while(cin >> u >> v && u != -1 && v != -1)
    {
        memset(vis, 0, sizeof vis);
        memset(fir, 0, sizeof fir);
        tot = 0;
        flag = 0;
        int tmp = u;
        add_edge(u, v);
        add_edge(v, u);
        while(cin >> u >> v && u && v)
            add_edge(u, v), add_edge(v, u);
        dfs(tmp, 0);
        cout << (flag ? "No" : "Yes") << endl;
    }
    return 0;
}