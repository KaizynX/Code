#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int u, v;
int dep[Maxn];
map<pair<int, int>, int> mmp;
vector<int> e[Maxn];

bool bfs(int S)
{
    memset(dep, -1, sizeof dep);
    mmp.clear();
    dep[S] = 0;
    queue<int> q;
    q.push(S);
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(int i : e[cur])
        {
            if(dep[i] != -1) return 1;
            if(mmp.find(make_pair(min(cur, i), max(cur, i))) != mmp.end()) continue;
            mmp[make_pair(min(cur, i), max(cur, i))] = 1;
            dep[i] = dep[cur]+1;
            q.push(i);
        }
    }
    return 0;
}

int main()
{
    while(cin >> u >> v && u != -1 && v != -1)
    {
        for(int i = 1; i < Maxn; ++i) e[i].clear();
        int tmp = u;

        e[u].push_back(v); e[v].push_back(u);
        while(cin >> u >> v && u && v)
            e[u].push_back(v), e[v].push_back(u);
        cout << (bfs(tmp) ? "No" : "Yes") << endl;
    }
    return 0;
}