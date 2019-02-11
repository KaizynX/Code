#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int u, v;
int vis[Maxn];
vector<int> e[Maxn];
map<int, int> mmp;

int bfs(int S)
{
    int cnt = 0;
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(S);
    vis[S] = 1;
    cnt = 1;
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(int i : e[cur])
        {
            if(!vis[i])
            {
                vis[i] = 1;
                cnt++;
                q.push(i);
            }
        }
    }
    return cnt;
}

int main()
{
    while(cin >> u >> v && u != -1 && v != -1)
    {
        for(int i = 1; i < Maxn; ++i) e[i].clear();
        mmp.clear();
        mmp[u] = mmp[v] = 1;
        int tmp = u, ecnt = 1;
        e[u].push_back(v); e[v].push_back(u);
        while(cin >> u >> v && u && v)
        {
            e[u].push_back(v);
            e[v].push_back(u);
            ecnt++;
            mmp[u] = mmp[v] = 1;
        }
        int pcnt = bfs(tmp);
        if(ecnt == mmp.size()-1 && pcnt == mmp.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}