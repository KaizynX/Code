#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
int vis[Maxn];
vector<int> e[Maxn];
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    q.push(1);
    vis[1] = 1;
    while(q.size())
    {
        int cur = q.top();
        q.pop();
        cout << cur << " ";
        for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
            if(!vis[*it]) q.push(*it), vis[*it] = 1;
    }
    return 0;
}
