#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int u, v, flag;
int vis[Maxn];
vector<int> e[Maxn];

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
    for(int i : e[cur])
        if(i != last) dfs(i, cur);
}

int main()
{
    while(cin >> u >> v && u != -1 && v != -1)
    {
        for(int i = 1; i < Maxn; ++i) e[i].clear();
        memset(vis, 0, sizeof vis);
        flag = 0;
        int tmp = u;

        e[u].push_back(v); e[v].push_back(u);
        while(cin >> u >> v && u && v)
            e[u].push_back(v), e[v].push_back(u);
        dfs(tmp, 0);
        cout << (flag ? "No" : "Yes") << endl;
    }
    return 0;
}